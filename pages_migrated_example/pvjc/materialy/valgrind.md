---
title: Ladenie programov v jazyku C
published: true
---

! Naučíte sa:
!
! - Vyhnúť sa častým chybám pri práci s pamäťou
! - Analyzovať prístupy do pamäte a odhaliť chyby

Prekladač jazyka C sa sám od seba nestará, či je pamäť ktorú Váš program využíva alokovaná a inicializovaná správne.

V prípade, že využívate pamäť ktorá nebola alokovaná alebo pamäť ktorá nebola inicializovaná, tak väčšinou vyzerá všetko v poriadku. Program funguje a sám od seba nehlási žiadne chyby. 

To, že niečo nie je v poriadku sa môže prejaviť až vtedy keď Váš program spustíte na inom počítači, napríklad na systéme pre automatické hodnotenie.

V niektorých premenných sa nachádzajú ľubovoľné hodnoty čo spôsobí to, že výsledky niekedy budú ľubovoľné a iné ako tie čo očakávame.

Ak sa program pri automatickom hodnotení správa inak ako predpokladáte, signalizuje to 
chybu pri práci s pamäťou. Tento druh chyby sa prejavuje iba za určitých okolností.
Program sa môže predčasne ukončiť so zápornou návratovou hodnotou.

Úlohou ladenie je identifikovať problémové miesta a zabrániť programu aby sa dostal do neurčitého stavu, aj za cenu pádu programu.

Aby ste sa chybe vyhli:

- vždy si inicializujte alokovanú pamäť napr. pomocou [memset()](https://www.cplusplus.com/reference/cstring/memset/).
- vždy si overte úspešnosť načítania reťazca alebo jeho konverzie.
- pri prechádzaní poľa si overte, či nepoužívate hodnoty mimo poľa.
- preložte Váš program s prepínačom `-Wall` a vyriešte všetky varovania.

## Ladenie pomocou analýzy prístupov do pamäte počas behu programu

Počas behu programu vieme spustiť proces, ktorý aktívne kontroluje, či je práca s pamäťou správna. 

V prípade, že nie, Valgrind vypíše chybovú správu a číslo riadku na ktorom sa vyskytol. 

Preložte Váš program s debugovacími informáciami (prepínač `-g`) a
spustite ho s pomocou programu Valgrind.

    gcc -g -std=c99 program.c -o program
    valgrind ./program

Valgrind Vás upozorní, ktorý riadok spôsobuje chybu prístupu do pamäte.

## Analýza výpisu pamäte

Pamäť vieme analyzovať aj po skončení behu programu.

Pomocou tohto postupu viete zistiť prečo Váš program spadol.
Požiadame operačný systém, aby obsah pamäte programu v okamihu pádu  zapísal do špeciálneho súboru `core`.

```
ulimit -c unlimited
```

Ak program spadne, vytvorí sa špeciálny súbor, ktorý vieme analyzovať pomocou debugera `gdb`:

Celé ladenie môže vyzerať takto:

```bash
# Prezime spolu s debug. 
$ gcc -g -Wall ./program.c -o program
# povolime vypis pamate
$ ulimit -c unlimited
# spustime program
$ ./program
Segmentation fault
# Ak spadne, vznikne nam subor core
$ ls
program program.c core.1234
# Pri ladeni sa ocitneme v okamihu ked program spadol
$ gdb ./program ./core.1234
# vieme zistit, na ktorom riadku spadol
bt
```
