---
title: Znakový vstup a výstup
published: true
---

! Zopakujete si
!
! - Načítanie po znakoch.
! - Koniec vstupu sa vyznačuje ako EOF.
! - Zopakujte si formátovaný výstup.
! - Písmeno je zakódované ako ASCII kód.
! - Zopakujete si prácu s premennými.
! - Zopakujete si prácu s cyklami a podmienkami.

## Úvod

Po krátkom zimnom oddychu tu je zase práca. Na všetkých školských
klávesniciach sa pokazila klávesa CAPS LOCK čo značne komplikuje písanie
pracovných výkazov a iných dôležitých dokumentov. Pravdepodobne to bolo spôsobené zvýšeným záujmom o diskusie na sociálnych sieťach. Verejné obstarávanie
na nové klávesnice je už vypísané, ale bude ukončené najskôr v septembri
roku 2022.  Ako dočasné (rozumej trvalé) riešenie navrhlo vedenie univerzity využiť šikovných študentov odboru Počítačové siete a ich schopnosti pri programovaní štandardného vstupu.

! Vedeli ste?
!
! - Nedostatky klávesy CAPS LOCK sa dajú riešiť aj úpravou hardvéru.

![caps-lock-flickr-cc](caps-lock-flickr-cc-dipurinku-sm-2.jpg)


## Úloha

Navrhneme softvérové riešenie, ktoré by čo najlepšie
simulovalo klávesu CAPS LOCK. Zo štandardného vstupu budeme postupne
načítať znaky pomocou funkcie `getchar()`. V prípade že načítame veľké
písmeno, premeníme ho na malé a vypíšeme. V prípade, že načítame malé
písmeno, premeníme ho na veľké a vypíšeme. Všetky ostatné znaky necháme
bez zmeny. Koniec pracovnej doby budú používatelia nášho programu
signalizovať klávesou `CTRL+D`. Ak to zistíme, tak ukončíme program a
vypíšeme správu o počte spracovaných riadkov.

``` c
printf("\nPočet riadkov: %d\n",counter);
```

## Návrh riešenia

Budeme potrebovať tieto premenné:

  - Práve načítaný znak (typ `int`).
  - Znak, ktorý sa vypíše (`char`)
  - Počet riadkov (`int`).

a tieto funkcie:

  - [getchar()](http://www.cplusplus.com/reference/cstdio/getchar/) na
    načítanie znaku.

  - [putchar()](http://www.cplusplus.com/reference/cstdio/putchar/) na
    výpis znaku.

  - [printf()](http://www.cplusplus.com/reference/cstdio/printf/) na
    výpis obsahu premennej.

Pre zopakovanie, základná kostra programu v jazyku C vyzerá takto:

```c
// Definícia funkcií ktoré budete používať
#include <stdio.h>
// Tu môžte dopísať Vaše funkcie
int main(){
    // Tu píšete program
    return 0;
}
```

Pri riešení môžete využiť tento postup:

### 1. Vytvorte cyklus

V cykle budete načítavať znak pomocou funkcie [getchar()](http://www.cplusplus.com/reference/cstdio/getchar/), až do vtedy pokiaľ sa dá. Pred tým ako funkciu použijete sa oboznámte s jej technickou dokumentáciou.

Cyklus môže byť typu `while`, v ktorej budete do premennej typu `int` načítavať znak z klávesnice.

```c
int c= 0;
while(1){
    c = getchar();
    //
}
```

Vo väčšine prípadov nám na uloženie znaku stačí typ `char`, v tomto prípade potrebujeme typ `int` aby sme mohli rozlíšiť
aj špeciálny znak `EOF` (end of file), ktorý signalizuje koniec vstupu.

Pri vstupe sa môže vyskytnúť aj "neočakávaná" situácia - koniec. Ten je
zakódovaný ako špeciálna konštanta `EOF` a má zväčša hodnotu -1, preto
na uloženie načítaného znaku potrebujeme premennú typu `int`. Pokus o
vypísanie načítaného `EOF` môže spôsobiť neočakávané chovanie. Pred tým ako vypíšete znak si musíte byť istí, že to nie je `EOF`.
V prípade, že je načítaný znak `EOF` tak cyklus ukončite pred tým ako sa znak vypíše.

Nezabudnite na pravidlo na ukončenie "nekonečného" cyklu.

### 2. Pridajte pravidlá na zmenu znakov

Pravidlá zmenia načítaný znak podľa potreby (veľké písmeno na malé a naopak). Použite na to ASCII tabuľku.

Pridajte pravidlo, ktoré inkrementuje počítadlo v prípade, že
    načítaný znak je koniec riadku.

Ak bude ukončená hlavná slučka vypíšte obsah počítadla.

Pri riešení môžme využiť fakt, že znak je zakódovaný ako číslo z [ASCII
tabuľky](https://en.wikipedia.org/wiki/ASCII) . Na obrazovke sa
zobrazuje ako znak, ale v pamäti má celočíselnú hodnotu, ktorá je iná
ako tá, ktorá je zobrazená. Napr. znak `0` má hodnotu 48. 

So znakmi je
možné robiť rovnaké operácie ako s číslami - porovnávať aj sčítavať.
Nemusíme ich dokonca ani hľadať v ASCII tabuľke, znaková konštanta sa správa rovnako ako číslo.

Vhodnou operáciou odčítania alebo sčítania je možné zmeniť veľký znak na
malý a naopak.
Nasledovná operácia pre zistenie malého písmena je úplne v poriadku:

```c
if (c >= 'a' && c <= 'z'){
    // Našiel som malý znak
}
```

Znaky sa dajú aj odpočítavať a pripočítavať čo využijeme na zmenu malého znaku na veľký:

```
int velkyznak = malyznak - 'a' + 'A';
```

Podobnú operáciu použijete aj pri premene veľkého znaku na malý. Pozor, v prípade iných znakov, napr. čísel
táto operácia nemá zmysel. Pozorne si overte (pomocou podmienky `if`), s akým znakom pracujete.


### 3. Vyskúšajte program

Preklad programu vykonajte volaním kompilátora:

    gcc -g -Wall program.c -o program

Dajte pozor, aby ste nepracovali s premennými, ktoré nemajú priradenú žiadnu hodnotu. V prípade staršej verzie kompilátora (napr. na servri omega) pridajte prepínač `-std=c99`.

## Odovzdanie

1. aktivujte si git
2. [Odovzdajte](https://traktor.kemt.fei.tuke.sk/#/submit/143) vypracovanie do adresára `du1`, súbor `program.c`.
