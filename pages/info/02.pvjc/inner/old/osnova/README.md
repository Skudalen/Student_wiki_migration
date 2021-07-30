# Osnova

Podľa http://it4kt.cnl.sk/c/pvjc/2017/lecture.02.html

[[TOC]]

# Týždeň 1

štruktúrované údajové typy, používateľom definované údajové typy, zoznamy údajov, vyhľadávanie a triedenie nad zoznamom údajov

- struct
- typedef
- statická inicializácia
- čítanie a zápis do štruktúry
- pole štruktúr
- lineárne vyhľadávanie v poli štruktúr

## Cvičenie

Frekvenčná tabuľka, prekladová tabuľka, triedenie qsort, binary search

# Týždeň 2

knižnica stdlib.h, funkcie qsort(), bsort(), binárne súbory, načítavanie a ukladanie štruktúrovaných údajov, serializácia, deserializácia

- lineárne vs. binárne vyhľadávanie
- bsearch
- qsort
- Binárne vs. textové súbory
- fread, fwrite
- Uloženie štruktúry na disk
- uloženie poľa štruktúr na disk v binárnom móde
- dôležitosť fclose
- serializácia a deserializácia

## Cvičenie

prekladová tabuľka, štruktúry

# Týždeň 03

reprezentácia času v počítači, pretečenie, enumeračné typy, modulárne programovanie, exit status

- repreentácia času (struct dt)
- dni v týždni ako enumerátor
- Unix time
- funkcia time()
- koľko je možných sekúnd? : typ time_t je long
- strftime
- pretečenie integer: Tento problém sa dá jednoducho ilustrovať pomocou tachometra v aute (slide) - keď dosiahne max hodnotu 99999, po prejdení +dalšieho kilometra sa vynuluje.
- Modulárne programovanie:
	- hlavičkový súbor
    - zdrojový súbor
    - Makefile
- Návratová hodnota funkcie main

## Cvičenie

Codewars, IP validation

# PS1 Hra K

# Week 04

dynamická správa pamäte, alokácia pamäte, uvoľnenie pamäte, memory leak, valgrind

- funkcia pre výmenu dvoch hodnôt premenných
- odovzdávanie parametrov funkcií kópiou (analýza pomocou deguggera)
- odovzdávanie parametrov pomocou adresy
- porovnávanie
- kopírovanie reťazcov
- memory leak a valgrind

## Cvičenie

Modulárne programovanie, Makefile

# Week 05

pravouhlé pole, zubaté pole, pole smerníkov, štandardné kanály/prúdy

- pole reťazcov
	- do dvojrozmerného poľa
- pole smerníkov
- smerník na smerník (smerník na pole smerníkov)
- načítanie zoznamu slov do pamäte

## Cvičenie

Ladenie, Valgrind

# Week 6

PS2?

úvod do dynamických údajových typov, spojkový zoznam, CRUD

Základné operácie s údajmi:
- create
- read
- update
- delete

Navrhnime takú údajovú štruktúru, ktorá by podporovala tieto operácie.

Ako by to vyzeralo s poľom? (Pole nie je výhodné pre niektoré operácie)

- Uloženie údajov do súvislých blokov (v pamäti a na disku)

Spojkový zoznam
- prechádzanie spojkového zoznamu
- vkladanie do spojkového zoznamu
- vyhľadávanie v spojkovom zozname
- mazanie zo spojkového zoznamu

Iné dátové typy
- stromy, mapy

## Cvičenie

Unit testy s assert h

# Week 7

Singly Linked Lists, Doubly Linked Lists, Trees, Binary Trees

Obojsmerný spojkový zoznam

Binárny vyhľadávací strom

Vytvorenie uzlu vuhľadávacieho stromu

Prechádzanie vyhľadávacieho stromu

## Cvičenie

Spojkový zoznam, malloc, crud, struct


# Week 8

Regular Expressions

Validácia reťazcov

Regex v C


## Cvičenie

Curses, hra bomber 1


# Week 9

Uniony, Bit Masking

Unix file system

Prístupové práva pomocou bitovej masky

Udalosti vstupno-výstupmých zariadení

Zoznam IO udalostí - uniony (každý prvok môže maž iný typ)

Polymorfický union:

V štruktúre je prvý člen štruktúry typ a druhý člen je union možných typov

## Cvičenie

Curses, hra bomber 2, klávesnica


# Week 10

mikrokontrolér Arduino, senzor, aktuátor, Arduino IDE


Deliberatívna architektúra
- sense
- think
- act

Z čoho sa skladá \Arduino UNO

Arduino IDE

Z čoho sa skladá aurduino program

Program pre blikanie diódy

## Cvičenie

Regex

# Week 11

meranie teploty, sériová komunikácia, analógové vstupy, potenciometer

Čítanie analógovej hodnoty z teplotného čidla (AD prevodník)

Rýchlosť sériovej linky

Čitanie a zápis do sériovej linky


## Cvičenie

wc - príkazový riadok, tokenizácia



# Week 12

Pulse-Width Modulation

Stmievanie LED diódy

## Cvičenie

Arduino Semafor


# Week 13

sériová linka, SPI a I2C

Problém synchronizácie a prenosovej rýchlosti medzi zariadeniami


Zbernica SPI

Až 4 vodiče pre každé zariadenie

Zbernica I2C

2 vodiče pre každé zariadenie

Knižnica Wire.h

## Cvičenie

Arduino Semafor II, stavový diagram


