---
title: Vyhľadaj ma
---
# Vyhľadaj ma

! Poriadne si prečítajte celý [všeobecný návod na prácu](../).

## Odovzdanie

- názov `usaa19cv1`
- heslo `usaa19cv1`
- cez [GIT](https://git.kemt.fei.tuke.sk)
- za 4 body do 11.10.2019  
- hodnotenie systémom [Traktor](https://traktor.kemt.fei.tuke.sk).

## Ciele

- Algoritmus naivného vyhľadávania reťazcov.
- Vhodne navrhnúť a použiť funkcie
- Zopakovať si reťazce, štruktúry a prácu s pamäťou
- Naučiť sa, že práca so súbormi aj terminálom je veľmi podobná.

## Úvod

Leto je vhodný čas na letnú brigádu.
Viacerý z Vás popri kúpaní a iných aktivitách využila čas na získanie zárobku v stravovacom biznise, napríklad v pizzérii.
Práca v pizzérii je ale veľmi namáhavá a preto sa tešíte, že si počas semestra trochu oddýchnete.

Do našej pizzérie začali chodiť davy ľudí s najrôznejšími požiadavkami na zloženie stravy..
Zvlášť hipsterská komunita na ktorú sa zameriavame je charakteristická najrôznejšími požiadavkami na diétu.
Frutariáni uprednostňujú ovocné pizze a nápoje, paleo a raw skupina by najradšej namiesto pizze chrúmala iba obilie s vodou a surovou paradajkou.
Brethariáni fungujú na pránickej strave, ale logicky ich v našej pizzérii nevidno lebo postupne ubúdajú a presúvajú sa do vyšších sfér.

Vďaka dosiahnutým úspechom s jedálnym lístkom sa naša pizzéria dostala do prestížneho gurmánskeho zoznamu časopisu "Zjem aj vlek".
V rámci akcie "Hladoš" pripravíme špeciálne sezónne menu, ktoré obsahuje iba položky, ktoré v názve obsahujú určitú surovimu (reťazec).

## Úloha

Vypracujte aplikáciu, ktorá z jedálneho lístka odfiltruje jedlá, ktorých názov neobsahuje zadaný reťazec.

Aplikácia najprv načíta reťazec, ktorý sa bude vyhľadávať v názvoch jedla.
Potom aplikácia načíta jedálny lístok. Položka v jedálnom lístku sa skladá z názvu a ceny uvedených na samostatnom riadku. 
Ak sa načítanie položky nepodarí, prerušte načítanie.
Ak názov jedla obsahuje zadaný reťazec, zobrazte celú položku aj s cenou.
Názov jedla ale môže byť mierne skreslený.  Na konci zobrazte počet všetkých úspešne načítaných položiek.

Mierna komplikácia je, že na zápis názvu  alebo vyhľadávanej suroviny sa používa neštandardný "Hack3r scr1pt", ktorý získava čoraz väčšiu popularitu na sociálnych sieťach. Hacker 5cript sa riadi nasledovným pravidlom - je možné ľubovoľne nahradiť veľké písmená za malé a niektoré písmená za čísla:

	0 <=> o
	1 <=> i
	2 <=> z
	3 <=> e
	4 <=> a
	5 <=> s
	6 <=> b
	7 <=> t
	8 <=> b
	9 <=> q

Oštiepkovú pizzu teda môžme zapísať ako:

	Ostiepkova pizza
	05t13pkova pizza
	05t13pkova p1zz4


## Príklad použitia programu

Vstup:


	bryndz
	8rynd20va P1zza
	7.50
	Ja8lkov4 Pizza
	6.50
	5penatov3 kal2on3
	8.20

Výstup:

	Zadaj hladanu surovinu:
	Zadaj jedalny listok:
	8rynd20va P1zza
	7.50
	Nacitanych 3 poloziek.


Vstup si môžte poznačiť aj do textového súboru vstup.txt aby ste to pri ručnom ladení nemuseli stále vypisovať.

	./program < vstup.txt

# Ako na to

Budete potrebovať:

- vytvoriť štruktúru na uloženie jednej položky jedálneho lístka.
- načítať reťazec pomocou `fgets`
- premeniť reťazec na číslo s desatinnou čiarkou pomocou `strtof` alebo `sscanf`.
- overiť úspešnosť načítania alebo premeny pomocou overovania návratovej hodnoty.
- implementovať algoritmus "naivného vyhľadávania" v reťazci 
- vytvoriť funkciu na transformáciu znaku do normalizovanej podoby.

## Zopakujte si

- správu vypisujeme pomocou funkcie `printf()`
- ak chceme použiť funkciu pre prácu s terminálom, musíme priložiť hlavičkový súbor `<stdio.h>`.
- Ako prvá sa v programe automaticky vyvolá funkcia `main()`.
- program vieme preložiť pomocou prekladača `gcc program.c -o program`,
- proces prekladu si vieme zjednodušiť pomocou Makefile a príkazu `make`
- Koniec riadka je vyznačený znakom `\n`.
- Reťazec je pole znakov zakončené nulou.
- Názov poľa je smerník na jeho začiatok.


## Načítajte vyhľadávaný reťazec 

Najprv si pripravte jednoduchý program, ktorý načíta vyhľadávaný reťazec vypíše ho  a skončí.

Vo funkcii `main` si vytvorte pole, do ktorého uložíte načítaný riadok. Nezabudnite si pole inicializovať na nulu pomocou [memset](http://www.cplusplus.com/reference/cstring/memset/).

```c
char line[LINE_SIZE];
memset(line,0,LINE_SIZE);
```

Výraz `LINE_SIZE` si definujte ako konštantu na začiatku súboru: 

```c
#define LINE_SIZE 100
```

Na načítanie reťazca použite funkciu [fgets](http://www.cplusplus.com/reference/cstdio/fgets/) zo štandardnej knižnice.
Na načítanie  čísel s desatinnou bodkou môžete použiť funkciu [strtof](http://www.cplusplus.com/reference/cstdlib/strtof/).

```c
char* r = fgets(line,LINE_SIZE,stdin);
```

Hodnota `stdin` je smerník na štandardný vstup, dostupný ako globálna premená o ktorú sa stará prekldač.

Úspešnosť načítania si overte pomocou návratovej hodnoty. Ak je hodnota smerníka `r` nulová, načítanie sa nepodarilo.

Pozor, funkcia `fgets` načítava všetko, vrátanie konca riadku `\n`. Ak používateľ vloží prázdny riadok, načítanie bude úspešné a načíta sa znak pre koniec riadku. S týmto musíme rátať pri vyhľadávaní a výpisoch. Preto si treba overiť aj poče načítaných znakov.

Počet načítaných znakov si môžte určiť pomocou cyklu podľa prvej nájdenej nuly alebo pomocou funkcie [strlen](http://www.cplusplus.com/reference/cstring/strlen/). Alebo sa jednoduch pozrite, či sa na druhom mieste načítaného poľa nenachádza nula.

Ak ste si istí, že sa riadok načítal správne, vypíšte ho pomocou funkcie [printf](http://www.cplusplus.com/reference/cstring/strlen/):

```c
if(r != NULL && line[1] != 0){
   printf("%s",line);
}
```

Program si môžte upraviť tak, aby načítaval všetky riadky až pokiaľ načítanie nezlyha. Na to si vytvorte cyklus ktorý sa preruší ak sa načítanie riadka nepodarilo:
správne stanoviť hranice cyklu pri prechádzaní reťazca.

```c
while (1){
    memset(line,0,LINE_SIZE);
    char* r = fgets(line,LINE_SIZE,stdin);
    if(r != NULL && line[1] != 0){
        printf("%s",line);
    }
}
```

## Vytvorte funkciu na načítanie jednej položky jedálneho lístka 

Informácia o jednej pizzi v jedálnom lístku sa bude skladať z názvu a (reťazec) a ceny (desatinné číslo).
Na to musíme navrhnúť vhodný dátový typ  (štruktúru).

```c
#define LINESIZE 100
struct pizza {
    float prize;
    char name[LINESIZE];
};
```

NOTE: Definícia štruktúry je podobná ako definícia funkcie. Neznamená to že sme si vyhradili nejakú pamäť, iba sme povedali ako by mala vyzerať.


Funkcia sa vám zíde v ďalšom cvičení.

Funkcia bude spĺňať tento predpis:

```c
int read_pizza(struct pizza* item);
```

Prvý argument  argument je miesto v pamäti, kde sa má načítať záznam. 
Pomocou návratovej hodnoty bude signalizovať či sa načítanie podarilo alebo nepodarilo.
Funkcia vráti nulu, ak je záznam o pizzi neplatný a ukončuje jedálny lístok.

Najpr načítajte riadok s názvom do pomocného poľa. Ak sa načítanie podarí, načítajte ďalší riadok do nového poľa, kotrý obsahuje zápis čísla s desatinnou čiarkou. Ak sa načítanie riadku podarí, skúste znaky premeniť na číslo s desatinnou čiarkou pomocou funkcie [strtof](http://www.cplusplus.com/reference/cstdlib/strtof/):

```c
float value = strtof(line2);
if (value == 0.0F){
   return 0;
}
```

Ak sa konverzia nepodarí, funkcia vráti nulu.

Ak sa podarilo načítanie názvu aj ceny, skopírujte načítané hodnoty a signalizujte úspech.

```
item->prize = value;
strcpy(item->name, line);
return 1;
```

## Overte si výsledok

Upravte program tak, aby načítal prvý riadok do poľa a potom v cykle postupne načítavajte záznamy o pizzi až pokiaľ nenatrafíte na neplatný záznam. Ak je záznam platný, vypíšte ho:

```c
struct pizza item;
int counter = 1;
while(read_pizza(stdin,&item)){
    counter += 1;
    printf("%s",item->name);
    printf("%.2f",item->prize);
}
```

Pár krát vyskúšajte Váš program aby ste sa uistili, že funguje správne. Použite aj poocníka `valgrind` aby ste overili prácu s pamäťou.

## Implementujte vyhľadávanie

V ďalšom kroku vyradíme záznamy z jedálneho lístka, ktoré neobsahujú zadaný reťazec.

Na to potrebujeme funkciu, ktorá bude vyhľadávať reťazec (označíme ho `needle`)  v zadanom reťazci (`heap`).

```c
int search_string(const char* heap, const char* needle);
```
Funkcia bude využívať dve slučky. Jedna z nich bude prechádzať reťazec `heap` a druhá `needle`.
V prápade, že reťazec `needle` sa nachádza v reťazci `heap`, funkcia vráti index jeho začiatku.
V prípade, že reťazec nenašla, vráti -1.

Viac informácií o tomto algoritme nájdete pod heslom ["naive string search"](https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/)

Pri práci s indexami a poliami dávajte pozor, aby ste nepracovali s pamäťou mimo vyhradeného rozsahu.
Dávajte pozor ak sa v tele slučky nachádza odčítanie alebo pripočítanie k indexu. Takýto program bude určite nesprávny:

```c
int pole[5]="abcd";
for (int i = 0; i < 5; i++){
  printf("%c",pole[i+1]);
}
```

## Zlepšite vyhľadávanie tak, aby bralo do úvahy skreslenie

Upravte vyhľadávanie tak, aby bralo do úvahy možné podoby znakov. Na to nám stači funkcia, ktorá transformuje znaky.
Funkcia by mala ľubovoľný znak premeniť do normalizovanej podoby ktorá berie do úvahy vlastnosti Hacker Scriptu.

Môže vyzerať napr. takto:

```c
char hacker_script(char c);
```
 Vo vnútri funkcie  definujte pravidlá na prepis znaku do Hacker scriptu:
 
 - Ak je znak veľký, prepíšte ho na malý
 - Ak je znak v zozname "špeciálnych znakov", tak ho prepíšte do pôvodnej podoby
 
Aby ste vo funkcii nemali prílič veľa podmienok, uložte si špeciálne znaky do poľa a pouťite cyklus na vyhľadávanie v poli:

```c
char numbers[] = "0123456789";
char letters[] = "oizeasbtbq";
for (int i = 0; i < 10; i++){
	if (c == numbers[i]){
	    return letters[i];
	}
}
```

K tomuto kódu pridajte premenu všetkých veľkých znakov na malé.
Túto funkciu Vám stačí aplikovať na každý znak vo vyhľadávacom algoritme.

