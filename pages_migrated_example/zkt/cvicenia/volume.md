---
title: Týždeň 3: Sieť a zväzky v Docker kontajneroch
published: true
---

! Naučíte sa:
!
! - Konfigurovať aplikáciu pomocou premenných prostredia.
! - Uchovať stav aplikácie pomocou zväzkov.
! - Vytvárať virtuálne siete.
! - Mapovať porty.

## Databáza v systéme Docker

V tomto návode si ukážeme ako je možné využiť systém Docker pre spúšťanie databázového systému. Cieľom návodu je naučiť sa ako funguje súborový systém a sieťové spojenie v aplikačnom kontajneri. Na konci by ste mali byť schopní pracovať s databázou cez webové rozhranie bežiace v inom kontajneri.

!!! V prostredí verejného klaudu spravidla nie je nutné vytvárať vlastnú inštaláciu databázy. Pripojenie k databáze je dostupné ako jedna zo služieb klaudového poskytovateľa.

### Dokumentácia obrazu kontajenera

Najprv sa oboznámte s obrazom kontajnera na Docker Hube. Pozrite si dokumentáciu k [Docker obrazu servra PostgreSQL](https://hub.docker.com/_/postgres).

Obraz kontajnera obsahuje nainštalovanú databázu spolu so všetkými závislosťami vrátanie operačného systému. V dokumentácii by mali byť uvedené základné informácie o tom ako obraz používať - ako ho nakonfigurovať, kde sa nachádzajú dôležité súbory a na akom porte je dostupná služba. Niekedy sa stane, že na to aby ste pochopili aj detaily tak si budete musieť pozrieť aj `Dockerfile` a základnú dokumentáciu k softvéru ktorý sa nachádza v aplikačnom kontajneri.

Štúdiom dokumentácie zistíte že:

- databáza beží na porte 5432
- používateľské meno je `postgres`
- heslo si nastavíte premennou prostredia napr. `-e POSTGRES_PASSWORD=mysecretpassword`

### Spustenie kontajnera s databázou

Spusťte si databázu PostgreSql.

```
docker run --name postgres -e POSTGRES_PASSWORD=mysecretpassword -d postgres:10.4-alpine
```

Prepínač  `-d` znamená, že aplikácia bude bežať na pozadí. 
Prepínač `--name` pridelí kontajneru symbolické meno aby sme vždy nemuseli hľadať jeho identifikačný reťazec.


Prepínač `-e` nastaví premennú prostredia s názvom `POSTGRES_PASSWORD`. Aplikácia ju vie prečítať a podľa nej nastaviť heslo na prístup k databáze.
Pomocou premenných prostredia vieme meniť aj iné vlastnosti aplikácie.
Zoznam premenných na konfiguráciu je uvedený v dokumentácii obrazu.

Že naozaj beží na pozadí si overíme pomocou:

```
docker ps
```

## Pripojenie sa na databázu

K databáze sa môžete pripojiť pomocou riadkového klienta `psql`

Spusťte riadkového klienta `psql` v kontajneri:

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

## Stav kontajnera je dočasný

v prostredí klaudu sa ľahko môže stať, že kontajner havaruje a bude reštartovaný. Reštart kontajnera môže spôsobiť to, že pôvodný stav (súbory s databázou) nebude k dispozícii.

Skúste vypnúť kontajner a zistiť, či sa tam aj po reštarte nachádza vytvorený záznam:

```
docker stop postgres
docker ps
docker run --name postgres -e POSTGRES_PASSWORD=mysecretpassword -d postgres:10.4-alpine
docker exec -it postgres psql -U postgres
psql> SELECT * FROM zabava;
```

## Zväzky v aplikačnom kontajneri 

Na to aby ste zachovali obsah databázy aj po ukončení kontajnera je potrebné vytvoriť nový zväzok.

Zväzok môže byť:

- ľubovoľný lokálny súborový systém 
- ľubovoľný lokálny adresár
- vzdialený súborový systém alebo adresár, pripojený pomocou sieťového protokolu ktorý podporuje operačný systém.

Pri štarte kontajnera viem vytvoriť mapovanie medzi adresármi v kontajnermi a zväzkami. Dáta sa tak nebudú zapisovať do súborového systému
kontajnera ale do zväzku. Tým obídeme to, že dáta neprežijú reštart kontajnera, lebo zostanú vo zväzku.

!!! V prostredí verejného klaudu zväzok spravidla nie je lokálny adresár, ale môže to byť virtuálne blokové zariadenie alebo adresár v distribuovanom súborovom systéme. Každý poskytovateľ má svoje vlastné riešenie, ale z hľadiska kontajnera sa pripojené zväzky používajú rovnako.

Aby sme sa nemuseli zamýšľať nad tým, ako sú usporiadané adresáre na servri, kde beží Docker, môžme si vytvoriť pomenovaný zväzok.

Pomenovaný zväzok je špeciálny adresár a ktorého vytvorenie a zmazanie sa stará Docker. Inak to je obyčajný adresár.

Nový pomenovaný zväzok  `pgdata` si vytvoríte príkazom:

```
docker volume create pgdata
```
 
Na lokálnom  disku (v Docker Machine) vznikne nový zväzok ( zvyčajne sa nachádza v `/var/lib/docker/volumes/`) kde si môžeme uložiť to čo chceme aby prežilo reštart kontajnera.

Zoznam zväzkov si môžeme pozrieť pomocou:

```
docker volume ls
```

 Ak nás pomenovaný zväzok omrzí, môžeme ho vymazať:

```
docker volume rm pgdata
```


## Mapovanie zväzkov

Na to aby sme v kontajneri mohli zväzok používať, musíme vytvoriť mapovanie.
Mapovaním určíme, ktorý adresár v súborovom systéme kontajnera bude zodpovedať zväzku.

Mapovanie zväzkov robíme pomocou prepínača `-v`.
Uvedieme špeciálny reťazec s mapovaním. Časť pred dvojbodkou je meno pomenovaného zväzku alebo lokálneho adresára, časť za dvojbodkou je meno adresára v kontajneri.


Ak beží kontajner, ktorý využíva zväzok, tak ho nebude možné vymazať aby sa zabránilo strate dát.

Ak sme zabudli, ktorý kontajner využíva zväzok, použime príkaz

```
docker inspect pgdata
```

Spustime si nový kontajner, ktorý už bude obsahovať aj mapovanie na trvalý zväzok. 

```
docker run  \
    --name postgres \
    -v pgdata:/var/lib/postgresql/data \
    -e POSTGRES_PASSWORD=mysecretpassword \
    -d postgres:10.4-alpine
```

Z vnútra bude kontajner vyzerať úplne rovnako, ale po reštarte bude obsah databázy zachovaný.

! Niektorá konfigurácia kontajnera, napríklad heslo sa zapíše do pomenovaného zväzku pri jeho vytvorení, napr. heslo pre prístup do databázy. Ak chcete neskôr zmeniť heslonastavené pomocou premennej prostredia, musíte vymazať pomenovaný zväzok alebo použiť nástroje postgres na zmenu hesla.

## Vytvorenie sieťového spojenia

Komunikácia s aplikáciou pomocou príkazového riadka je síce jednoduchá, 
ale má určité obmedzenia.
Na to aby sme kontajner vedeli plnohodnotne využívať musíme vedieť ho pripojiť na našu sieť.

Nie každému vyhovuje rozhranie príkazového riadku. 
To síce určite nie je náš problém, ale používatelia našej aplikácie určite ocenia luxusné grafické rozhranie `pgadmin`. Vyskúšajme si pre demonštráciu webovú aplikáciu pre správu relačnej databázy Postgres `pgadmin`.

Na Docker Hube sa nachádza viacero obrazov `pgadmin`.
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
Tieto údaje slúžia iba na spustenie rozhrania a nemajú nič spoločné s databázami ktoré vieme pomocou webovej aplikácie spravovať.

Aplikácia v kontajneri za bežných podmienok nie je viditeľná pre vonkajší svet. Port, pomocou ktorého komunikuje musíme explicitne mapovať na reálny port na stroji, kde beží Docker (virtuálny stroj Docker Machine).

Prepínačom `-p` sme povedali, že aplikácia využívajúca port 80 bude prístupná na porte 8080 našej Docker Machine. Pri určovaní portov treba dávať pozor aby nevznikla kolízia - aby na jednom porte bežala maximálne jedna služba.

### Pripojenie sa na bežiaci kontajner

Najprv musíme zistiť, na akej IP adrese beží webová aplikácia.

- Ak používate Docker Machine:  Zistite IP adresu Docker Machine (napr. `docker-machine ls`) 
- Ak používate Docker Desktop: Ak sa chcete pripojiť na kontajner pomocu webového prehliadača tak musíte použiť IP vášho stroja (`localhost`). Ak sa chcete pripojiť pomocou iného stroja WSL, použite symbolické meno `host.docker.internal`. Ak neviete, webový prehliadač si otvoríte aj pomocu Dashboardu Docker Desktop.

V luxusnom grafickom prostredí bude asi hračka pripojiť sa na databázový server `postgres` na port 5432. 

Na úvodnej obrazovke kliknite na "Add New Server". Vyplňte ľubovoľne meno spojenia ("Name"). V záložke "Connection" skúste vyplniť položku "Host Name/Address" - DNS meno alebo IP adresa databázového servra.   

Ale aké IP mám vyplniť?

### Virtuálne siete

Pomocou mapovania portov je síce možné sa z vonkajšieho prostredia pripojiť na bežiaci kontajner, ale nie je to možné medzi kontajnermi navzájom. 
A nebolo by to ani bezpečné. Kontajnery by mali byť od seba maximálne oddelené, aby nebolo možné ľahko pristupovať k cudzím procesom.
Musíme explicitne povedať, ktoré kontajnery budú vidieť ktoré.

!! Pozor: Virtuálna sieť Docker je odlišná od virtuálnej siete ktorú využíva virtuálny stroj WSL2 alebo VirtualBox. Aplikačné kontajnery majú svoje vlastné virtuálne siete.

Na určenie skupín kontajnerov ktoré budú sieťoví kamaráti (budú navzájom viditeľné a budú vedieť spolu komunikovať) slúži virtuálna sieť.

Virtuálnu sieť `pgnet` pre databázu a rozhranie vytvoríme podobným spôsobom ako kontajner:

```
docker network create pgnet
```

Pri spustení kontajnera zadáme meno virtuálnej siete do ktorej bude kontajner patriť.

Všetky kontajnery v rámci jednej virtuálnej siete budú navzájom dostupné pomocou svojho mena. Docker sa postará o to, aby v každom bežiacom 
kontajneri vznikol príslušný DNS záznam aby sme sa nemuseli starať o konkrétne virtuálne IP adresy.

### Pridanie kontajnerov do virtuálnej siete

Kontajner pridáme do virtuálnej siete pri spustení. Asi bude potrebné začať odznova. 

Vypnite databázu `postgres` aj klienta `pgadmin`.

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

Overíme si zoznam sietí:

```
docker network ls
```

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
    -v pgdata:/var/lib/postgresql/data \ 
    -d postgres:10.4-alpine
```

!!! Špeciálna sieť  `--network host` vypína virtualizáciu siete a sieť v aplikácii sa bude správať rovnako ako sieť hostiteľského operačného systému. Odporúča sa používať iba v špeciálnych prípadoch.

Na virtuálnej sieti to bude vyzerať takto:

    +-----------+                 +----------+
    | postgres  | <-5432 pgnet -> | pgadmin  | 80 <--> localhost 8080
    +-----------+                 +----------+

### Spojenie medzi kontajnermi

Vo virtuálnej sieti bude kontajner prístupný pod DNS menom rovnakým ako je meno kontajnera (prepínač `--name`).
V prípade, že je kontajner pripojený na viac virtuálnych sietí,
medzi DNS menami sa rozlišuje pomocou prípony s menom siete, napr.
`postgres.pgnet`.

Nakonfigurujte `pgadmin` tak, aby sa napojil na databázu v kontajneri `postgres`. 

Na úvodnej obrazovke kliknite na "Add New Server". Vyplňte ľubovoľne meno spojenia ("Name"). V záložke "Connection" skúste vyplniť položku "Host Name/Address" - DNS meno alebo IP adresa databázového servra.   

* General - Name: Meno spojenia
* Connection - Host: Url na ktorom beží databázový server. V tomto prípade to bude meno kontajnera (`postgres`) alebo meno siete a meno kontajnera `pgnet.postgres`.
* Connection - Port: Vnútorný port na virtuálnej sieti na ktorom beží databáza.
* Connection - Username: používateľské meno na prístup k databáze. 
* Connection - Password: heslo na prístup k databáze. 

!!! Ak sa pripájate ku vlastnej inštalácii Postgresql, musíte povoliť prístup pomocou hesla v súbore pg_hba.conf. Docker verzia je už nakonfigurovaná.


Pomocou grafického klienta `pgadmin4` si pozrite obsah databázy `postgres`.


### Zrušenie virtuálnej siete

Keď nás sieť omrzí, vymažeme ju príkazom:

```
docker network rm pgnet
```

Sieť sa nedá vymazať, pokiaľ existujú kontajnery ktoré ju využívajú.


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

