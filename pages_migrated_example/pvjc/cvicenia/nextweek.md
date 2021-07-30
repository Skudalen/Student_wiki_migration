---
title: O týždeň
published: true
---

! Naučíte sa:
!
! - načítanie jedného riadka;
! - pracovať s časom a dátumom;
! - pracovať so smerníkmi.

Pri pracovných a školských úlohách je častý termín vypracovania o týždeň.
Vytvorte program, ktorý Vám pomôže odhadnúť dátum odovzdania Vášho
zadania.

Program načíta ľubovoľný dátum a k nemu vypočíta dátum o týždeň.

## Preštudujte si

Pri riešení môžte využiť [časť štandardnej knižnice](http://www.cplusplus.com/reference/ctime/) pre prácu s časom
a dátumom. Budete potrebovať tieto dva dátové typy:

- [Štruktúra pre reprezentáciu času](http://www.cplusplus.com/reference/ctime/tm/) `struct tm`.
     Aké členy má táto štruktúra? Ako si vytvorím novú premennú typu `struct tm`?
- [Typ pre celočíselnú reprezentáciu](http://www.cplusplus.com/reference/ctime/time_t/)
    času `time_t`. Aký je rozdiel medzi celočíselnou a štruktúrovanou reprezentáciou?

Je možné zmeniť celé číslo na štruktúru alebo na reťazec? Pomôžu Vám tieto funkcie:

- [mktime()](http://www.cplusplus.com/reference/ctime/mktime) konverzia štruktúrovanej reprezentácie na celočíselnú;
- [localtime()](http://www.cplusplus.com/reference/ctime/localtime) konverzia celočíselnej reprezentácie času na štruktúrovanú:
- [strftime()](http://www.cplusplus.com/reference/ctime/strftime) konverzia štruktúrovanej reprezentácie času do reťazca.

Pri štúdiu technickej dokumentácie sa sústreďte na:

- Predpis funkcie vám prezradí aké argumenty funkcia očakáva a aký je typ návratovej hodnoty.
- Stručný opis činnosti hovorí čo funkcia robí.
- Spôsob ako funkcia hlási chybu (väčšinou pomocou špeciálnej návratovej hodnoty). Konverzia alebo načítanie sa nemusí podariť a musíte definovať čo sa má robiť v tom prípade.

Budete potrebovať aj tieto funkcie na načítanie riadka:

- [fgets()](http://www.cplusplus.com/reference/cstdio/fgets/) na načítanie reťazca;
- [puts()](http://www.cplusplus.com/reference/cstdio/puts/) na výpis reťazca:
- [memset()](http://www.cplusplus.com/reference/cstring/memset/) na inicializáciu pamäte;


## Smerníková premenná

Pri štúdiu týchto funkcií a dátových typov môžte vidieť, že sa často
pracuje s adresou premennej namiesto jej hodnoty. Na uloženie adresy je
dobré používať tzv. smerníkovú premennú, ktorú vyznačíte pomocou `*` pri
vyhradení pamäte.

```c
struct tm* adresa_tm;
```

je premenná pre uloženie smerníka na premennú kde je uložená hodnota typu `struct tm`.

Adresu premennej zistíte pomocou operátora `*`.

Takto si pomocou operátora `&` poznačíte adresu premennej typu `int`:

``` c
int moja_premenna = 1;
int* adresa_mojej_premennej_int = &moja_premenna;
```

So smerníkovou premennou (s adresou hodnoty) vieme pracovať podobne ako s klasickou premennou (kde je uložená hodnota).
Ak vieme adresu s hodnotou, tak sa vieme ľahko dostať aj k hodnote.

Obsah pamäte s danou adresou zistíte pomocou operátora `*`.

``` c
int moja_premenna = 1;
int* adresa_mojej_premennej_int = &moja_premenna;
int hodnota_mojej_premennej = *adresa_mojej_premennej_int;
```

Druhá možnosť ako získať hodnotu zo smerníkovej premennej je využitie "zenovej" pravdy jazyka C: adresa premennej je začiatok poľa:

```
int hodnota = adresa_mojej_premennej_int[0];
```

!! Adresa premennej je zároveň začiatok poľa.
 
Ak je štruktúra uložená v klasickej premennej, k jednotlivým členom štruktúry pristupujete pomocou operátora `.`.
Ak smerníková premenná obsahuje adresu štruktúry tak môžeme použiť skrátený zápis `->` na prístup k hodnotám jej atribútov.


## Návrh riešenia

Riešenie je možné vyjadriť pomocou postupu:

1.  Najprv načítajte jeden riadok ľubovoľného textu.
2.  Skúste text premeniť do štruktúrovanej reprezentácie.
3.  Ak sa konverzia nepodarila, vypíšte chybové hlásenie.
4.  Ak bola konverzia úspešná, skúste čas premeniť do celočíselnej
    reprezentácie.
5.  V celočíselnej reprezentácii vypočítajte čas o týždeň.
6.  Celočíselnú reprezentáciu premeňte do štruktúrovanej a vypíšte
    výsledok.

## Odovzdanie

Domácu úlohu odovzdajte na GIT do adresára `du3` do súboru `program.c` pomocou [systému Traktor](https://traktor.kemt.fei.tuke.sk/#submit/147) za 8 bodov.


