---
title: Sieť a zväzky v Docker kontajneroch
published: true
---

# Zväzky a virtuálna sieť v Docker kontajneroch

Naučíte sa:

- Uchovať stav aplikácie pomocou zväzkov
- vytvárať virtuálne siete
- Mapovať porty
- Používať databázu cez systém Docker

## Spustenie databázy

Uistite sa, že Docker Machine beží v poriadku.

    docker-machine ls

Zistite akú IP adresu má Docker machine.

Pozrite si dokumentáciu k [Docker obrazu servra PostgreSQL](https://hub.docker.com/_/postgres).

Štúdiom dokumentácie zistíte že:

- databáza beží na porte 5432
- používateľské meno je `postgres`
- heslo si nastavíte premennou prostredia napr. `-e POSTGRES_PASSWORD=mysecretpassword`


Spusťte si databázu Postgresql.


```
docker run --name postgres -e POSTGRES_PASSWORD=mysecretpassword -d postgres:10.4-alpine
```

Prepínač  `-d` znamená, že aplikácia bude bežať na pozadí. 
Že naozaj beží na pozadí si overíme pomocou:

```
docker ps
```

Prepínač `-e` nastaví premennú prostredia s názvom `POSTGRES_PASSWORD`. Aplikácia ju vie prečítať a podľa nej nastaviť heslo na prístup k databáze.
Pomocou premenných prostredia vieme meniť aj iné vlastnosti aplikácie.


- Mapovanie portov `-p` lokálny port, kontajnerový port


## Pripojenie sa na databázu

K databáze sa môžete pripojiť pomocou riadkového klienta `psql`


Spusťte riadkového klienta psql v kontajneri:

```
docker exec -it postgres psql -U postgres
```

Pre zábavu vyskúšajte nejaké jednoduché SQL príkazy:

```sql
CREATE TABLE zabava (id INTEGER PRIMARY KEY,vtip TEXT);
INSERT INTO zabava values(1,'klop klop');
SELECT * FROM zabava;
```
Klienta ukončíte stlačením `Ctrl+D`.

SQL príkazy si môžte poznačiť do súboru a do databázy ich odoslať pomocou štandardného vstupu:

```
cat schema.sql | docker exec -i postgres psql -U postgres
```

## Vytvorenie sieťového spojenia

Komunikácia s aplikáciou pomocou príkazového riadka je síce jednoduchá, 
ale má určité obmedzenia.
Nie každému vyhovuje rozhranie príkazového riadku. 
To síce určite nie je náš problém, ale používatelia našej aplikácie určite ocenia luxusné grafické rozhranie `pgadmin`.

Na Docker Hube sa nachádza viacero obrazov `pgamin`.
Naštudujeme ten najpoužívanejší [dpage/pgadmin4](https://hub.docker.com/r/dpage/pgadmin4).

S Dockerom je jeho spustenie a inštalácia príjemne jednoduchá:

```
docker pull dpage/pgadmin4
docker run -p 8080:80 \
    --name pgadmin \
    -e 'PGADMIN_DEFAULT_EMAIL=user@domain.com' \
    -e 'PGADMIN_DEFAULT_PASSWORD=SuperSecret' \
    -d dpage/pgadmin4
```

Premennými prostredia `PGADMIN_DEFAULT_EMAIL` a `PGADMIN_DEFAULT_PASSWORD`
nastavíme prihlasovacie meno a heslo pre prístup do webovej aplikácie.

Aplikácia v kontajneri za bežných podmienok nie je viditeľná pre vonkajší svet. Port, pomocou ktorého komunikuje musíme explicitne mapovať na reálny port na stroji, kde beží Docker (virtuálny stroj Docker Machine).

Prepínačom `-p` sme povedali, že aplikácia využívajúca port 80 bude prístupná na porte 8080 našej Docker Machine. Pri určovaní portov treba dávať pozor aby nevznikla kolízia - aby na jednom porte bežala maximálne jedna služba.


    Zistite IP adresu Docker Machine (napr. `docker-machine ls`) a zobrazte webové rozhranie klienta pomocou webového prehliadača.

V luxusnom grafickom prostredí bude asi hračka pripojiť sa na databázový server `postgres` na port 5432 bežiaci na "Docker Machine".

Na úvodnej obrazovke kliknite na "Add New Server". Vyplňte ľubovoľne meno spojenia ("Name"). V záložke "Connection" skúste vyplniť položku "Host Name/Address" - DNS meno alebo IP adresa databázového servra.   

Funguje to?

Asi bude potrebné začať odznova. Vypnite databázu aj klienta `pgadmin`.


```
# Bezi
docker ps
docker stop postgres
docker rm postgres
docker stop pgadmin
docker rm pgadmin
# Uz nebezi
docker ps
```

## Virtuálna sieť

Pomocou mapovania portov je síce možné sa z vonkajšieho prostredia pripojiť na bežiaci kontajner, ale nie je to možné medzi kontajnermi navzájom. 

A nebolo by to ani bezpečné. Kontajnery by mali byť od seba maximálne oddelené, aby nebolo možné ľahko pristupovať k cudzím procesom.

Musíme explicitne povedať, ktoré kontajnery budú vidieť ktoré.

Na určenie skupín kontajnerov ktoré budú sieťoví kamaráti (budú navzájom viditeľné a budú vedieť spolu komunikovať) slúži virtuálna sieť.

Virtuálnu sieť `pgnet` pre databázu a rozhranie vytvoríme podobným spôsobom ako kontajner:

```
docker network create pgnet
```

Overíme si zoznam sietí:

```
docker network ls
```


Pri spustení kontajnera zadáme meno virtuálnej siete do ktorej bude kontajner patriť.

Všetky kontajnery v rámci jednej virtuálnej siete budú navzájom dostupné pomocou svojho menia. Docker sa postará o to, aby v každom bežiacom 
kontajneri vznikol príslušný DNS záznam aby sme sa nemuseli starať o konkrétne virtuálne IP adresy.

Pri novom spustení kontajnerov pridáme parameter `--network`.

```
docker run  \
    -p 8080:80 \
    --name pgadmin \
    --network pgnet \
    -e 'PGADMIN_DEFAULT_EMAIL=user@domain.com' \
    -e 'PGADMIN_DEFAULT_PASSWORD=SuperSecret' \
    -d dpage/pgadmin4
docker run  \
    --name postgres \
    --network pgnet \
    -e POSTGRES_PASSWORD=mysecretpassword \
    -d postgres:10.4-alpine
```

V grafickom klientovi `pgadmin` bude databázový server prístupný pod
DNS menom `postgres` na porte 5432.

Vo vituálnej sieti bude kontajner prístupný pod DNS menom rovnakým ako je meno kontajnera (prepínač `--name`).
V prípade, že je kontajner pripojený na viac virtuálnych sietí,
medzi DNS menami sa rozlišuje pomocou prípony s menom siete, napr.
`postgres.pgnet`.

Poznámka:

Špeciálna sieť  `--network host` vypína virtualizáciu siete a sieť v aplikácii sa bude správať rovnako ako sieť hostiteľského operačného systému. Odporúča sa používať iba v špeciálnych prípadoch.


Keď nás sieť omrzí, vymažeme ju príkazom:

```
docker network rm pgnet
```

## Pridajte pomenovaný zväzok

Pomocou grafického klienta `pgadmin4` si pozrite obsah databázy `postgres`.

Na to aby ste zachovali obsah databázy aj po ukončení kontajnera je potrebné vytvoriť nový zväzok.

Zväzok môže byť:

- ľubovoľný lokálny súborový systém 
- ľubovoľný lokálny adresár
- vzdialený súborový systém alebo adresár, pripojený pomocou sieťového protokolu ktorý podporuje operačný systém.

Pri štarte kontajnera viem vytvoriť mapovanie medzi adresármi v kontajnermi a zväzkami. Dáta sa tak nebudú zapisovať do súborového systému
kontajnera ale do zväzku. Tým obídeme to, že dáta neprežijú reštart kontajnera, lebo zostanú vo zväzku.

Aby sme sa nemuseli zamýšľať nad tým, ako sú usporiadané adresáre na servri, kde beží Docker, môžme si vytvoriť pomenovaný zväzok.

Pomenovaný zväzok je špeciálny adresár a ktorého vytvorenie a zmazanie sa stará Docker. Inak to je obyčajný adresár.

Nový pomenovaný zväzok  `pgdata` si vytvoríte príkazom:

```
docker volume create pgdata
```
 
 Na lokálnom  disku (v Docker Machine) vznikne nový zväzok (`/var/lib/docker/volumes/`) kde sa budú ukladať údaje z databázy.


```
docker run  \
    --name postgres \
    --network pgnet \
    -v pgdata:/var/lib/postgresql/data \
    -e POSTGRES_PASSWORD=mysecretpassword \
    -d postgres:10.4-alpine
```

Mapovanie zväzkov robíme pomocou prepínača `-v`.
Uvedieme špeciálny reťazec s mapovaním. Časť pred dvojbodkou je meno pomenovaného zväzku alebo lokálneho adresára, časť za dvojbodkou je meno adresára v kontajneri.

Zoznam zväzkov si môžeme pozrieť pomocou:

```
docker volume ls
```

 Ak nás pomenovaný zväzok omrzí, môžeme ho vymazať:

 ```
 docker volume rm pgdata
 ```

Ak beží kontajner, ktorý využíva zväzok, tak ho nebude možné vymazať aby sa zabránilo strate dát.

Ak sme zabudli, ktorý kontajner využíva zväzok, použime príkaz

```
docker inspect pgdata
```

## Vytvorte si pomocné skripty

Do skriptu si poznačte všetky príkazy potrebné na prípravu, štart a koniec aplikácie.

- prepare-app.sh
- start-app.sh
- stop-app.sh

Skript sa môže začínať príkazmi:

```
#!/bin/bash
set -e
```

## Dodatočné zdroje:

- Katacoda: [What is a Container?](https://www.katacoda.com/courses/container-runtimes/what-is-a-container)
- Katacoda: [What is a Container Image](https://www.katacoda.com/courses/container-runtimes/what-is-a-container-image)
- [Docker networking](https://docs.docker.com/network/)
- [docker network create](https://docs.docker.com/engine/reference/commandline/network_create/)
- [Docker Volumes](https://docs.docker.com/storage/volumes/)
- [docker volume create](https://docs.docker.com/engine/reference/commandline/volume_create/)
