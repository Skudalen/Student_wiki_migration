---
title: Preklad projektov v jazyku C
published: false
---

! Naučíte sa:
!
!  - Zostaviť program zložený z knižníc a modulov.
!  - Napísať pravidlá systému `make`.
!  - Používať funkcie z externých knižníc.


Zostaviť program ktorý sa skladá z jedného súboru v jazyku C je
jednoduché. Prekladač sa postará o všetko dôležité - predspracovanie, preklad aj linkovanie.

Príkaz

    gcc program.c -o program

vykoná všetky dôležité kroky a ak je zdrojový kód správne napísaný
vytvorí spustiteľný súbor.

Situácie je o niečo zložitejšia v prípade, keď program je dlhší a skladá sa z viacerých modulov. Vtedy musíme preložiť každý modul samostatne a potom ich spojiť do jedného spustiteľného súboru.
Ak chceme preložiť program, ktorý sa skladá z viacerých súborov, tak musíme kroky prekladu a linkovania vykonávať osobitne.

## Preklad z viacerých súborov

Procesom prekladu vytvoríme jeden "objektový" súbor (`modul1.o`), ktorý
obsahuje skompilovaný zdrojový kód z modulu `modul1.c`. Neobsahuje ale
kód z iných modulov alebo knižníc. 
Pomocou prepínača `-c` dáme príkaz prekladaču, aby vynechal krok linkovania a vykonal iba preklad zadaného súboru.

Samostatný preklad dvoch modulov (bez linkovania) vykonáme pomocou príkazu:

    gcc -c modul1.c -o modul1.o
    gcc -c modul2.c -o modul2.o

## Linkovanie

Kód z ostatných modulov alebo knižníc musíme pripojiť osobitne v procese linkovania. Zoberieme
všetky moduly, spojíme ich a vytvoríme spustiteľný súbor.
Nie je potrebné zadávať žiadny špeciálny prepínač, prekladač sám uhádne že ak je vstupom objektový súbor tak má vykonať iba linkovanie.

    gcc modul1.o modul2.o -o program

Špeciálne prepínače sú potrebné v prípade, že k prgramu potrebujeme pripojiť nejakú externú knižnicu.

Ak Váš program používa funkcie mimo štandardnej knižnice tak je potrebné
pripojiť ich počas linkovania pomocou prepínača `-l`. Ak v programe
využívame matematické funkcie (`math.h`), tak pri linkovaní použijeme
prepínač `-lm`. Alebo ak používate knižnicu `curses` je potrebné ju pripojiť pomocou prepínača `-lcurses`.


## Preklad projektu pomocou Makefile

Ak sa program skladá z viacerých modulov je náročné spúšťať celý proces
prekladu ručne. Ak preklad niektorého súboru alebo linkovanie zlyhá, musíme opraviť
chybu a opakovať všetko odznova:

    gcc -c modul1.c -o modul1.o
    gcc -c modul2.c -o modul2.o
    gcc modul1.o modul2.o -o program

Na uľahčenie procesu prekladu si poznačíme všetky
potrebné príkazy do súboru `Makefile`. Príkaz `make` si ho prečíta a
podľa potreby vykoná iba tie príkazy ktoré sú potrebné. Orientuje sa
podľa času poslednej modifikácie súboru.

### Pravidlá v Makefile

Pravidlo v Makefile sa skladá z troch častí - cieľ, predpoklad a transformácie. Cieľ je súbor alebo virtuálny objekt kotrý sa má pomocou pravidla vytvoriť. Predpoklad je zoznam potrebných súborov alebo cieľov, ktoré musia byť naplnené aby sme mohli vytvoriť cieľ. Transformácia je zoznam príkazov ktoré je potrebné vykonať, aby sme z predpokladov vytvorili cieľ.

Pravidlá zapisujeme v tvare:

    cieľ: predpoklady oddelené medzerou
        transformácia sa začína tabulátorm, obsahuje príkazy ako zo zdrojových objektov vytvoriť cieľový objekt

!!! Pred príkazom sa nachádza znak TAB (`\t`). Obyčajné medzery nebudú
    fungovať.

### Zápis pravidiel Makefile

Najjednoduchší Makefile s jedným pravidlom môže vyzerať takto:

`Makefile` pre projekt, ktorý sa skladá z dvoch modulov, by mohol
vyzerať takto:

``` Makefile
program: modul1.0 modul2.o
    gcc modul1.0 modul2.o -o program

modul1.o: modul1.c
    gcc -c modul1.c -o modul1.o

modul2.o: modul2.c
    gcc -c modul2.c -o modul2.o
```


### Vykonanie pravidiel

Príkaz `make` načíta pravidlá z `Makefile` a podľa potreby vykoná všetky
príkazy potrebné na zostavenie programu. Ak po úspešnom zostavení
spustíme `make` ešte raz, nevykoná sa nič, lebo to nebude potrebné.
Systém `make` prečíta všetky pravidlá a porovná ich s aktuálnym stavom v adresári v ktorom sa nachádzame.  Podľa toho vie určiť, ktoré transformácie sú potrebná na to aby sa dosiahol konečný cieľ (uvedený ako prvý).
V prípade, že cieľový súbor chýba, alebo je starší ako zdrojový súbor sa
vykoná pravidlo. Ak je cieľový súbor mladší, nevykoná sa nič.

## Premenné

Často používané prepínače si vieme uložiť do premenných.

``` Makefile
CFLAGS=-Wall -std=c99 -g

program: modul1.0 modul2.o
    gcc  modul1.0 modul2.o -o program

modul1.o: modul1.c
    gcc -c  $(CFLAGS) modul1.c -o modul1.o

modul2.o: modul2.c
    gcc -c $(CFLAGS) modul2.c -o modul2.o
```


