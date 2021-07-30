# Zostav si svoj program

<div class="tip">

<div class="title">

Naučíte sa

</div>

  - Zostaviť program zložený z knižníc a modulov.

  - Napísať pravidlá systému make.

  - Používať funkcie z externých knižníc.

</div>

## Zostavenie programu

Zostaviť program ktorý sa skladá z jedného súboru v jazyku C je
jednoduché. Prekladač sa postará o všetko dôležité - preprocesing,
preklad aj linkovanie.

Príkaz

    gcc program.c -o program

vykoná všetky dôležité kroky a ak je zdrojový kód správne napísany
vytvorí spustiteľný súbor.

Situácie je o niečo zložitejšia v prípade, keď program je dlhší a skladá
sa z viacerých modulov. Vtedy musíme preložiť každý modul samostatne a
potom ich spojiť do jedného spustiteľného súboru.

Samostatný preklad vykonáme pomocou príkazu:

    gcc -c modul1.c -o modul1.o

Procesom prekladu vytvoríme jeden "objektový" súbor (`modul1.o`), ktorý
obsahuje skompilovaný zdrojový kód z modulu `modul1.c`. Neobsahuje ale
kód z iných modulov alebo knižníc. Kód z ostatných modulov alebo
knižníc musíme pripojiť osobitne v procese linkovania. Zoberieme
všetky moduly, spojíme ich a vytvoríme spustiteľný súbor:

    gcc modul1.o modul2.o -o program

Ak preklad niektorého súboru alebo linkovanie zlyhá, musíme opraviť
chybu a opakovať všetko odznova:

    gcc -c modul1.c -o modul1.o
    gcc -c modul2.c -o modul2.o
    gcc modul1.o modul2.o -o program

Ak sa program skladá z viacerých modulov je náročné spúšťať celý proces
prekladu ručne. Na uľahčenie procesu prekladu si poznačíme všetky
potrebné príkazy do súboru `Makefile`. Príkaz `make` si ho prečíta a
podľa potreby vykoná iba tie príkazy ktoré sú potrebné. Orientuje sa
podľa času poslednej modifikácie súboru.

## Pravidlá

Príkazy v súbore `Makefile` sú organizované do pravidiel, ktoré hovoria
ako zo zdrojového objektu vytvoriť cieľový:

    zdrojový objekt -> príkaz -> cieľový objekt

Systém `make` sa pozrie na čas poslednej modifikácie zdrojového súboru.
V prípade, že cieľový súbor chýba, alebo je starší ako zdrojový súbor sa
vykoná pravidlo. Ak je cieľový súbor mladši, nevykoná sa nič.

Pravidlá zapisujeme v tvare:

    cieľový objekt: zoznam zdrojových objektov
        pravidlo

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

  - NOTE  
    Pred príkazom sa nachádza znak TAB (`\t`). Obyčajné medzery nebudú
    fungovať.

Príkaz `make` načíta pravidlá z `Makefile` a podľa potreby vykoná všetky
príkazy potrebné na zostavenie programu. Ak po úspešnom zostavení
spustíme `make` ešte raz, nevykoná sa nič, lebo to nebude potrebné.

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

## Externé knižnice

Ak Váš program používa funkcie mimo štandardnej knižnice tak je potrebné
pripojiť ich počas linkovania pomocou prepínača `-l`. Ak v programe
využívame matematické funkcie (`math.h`), tak pri linkovaní použijeme
prepínač `-lm`.

## Zostavte si program s Termbox

V praktickom príklade si nakreslíme svoju iniciálu pomocou ASCII art
grafiky na obrazovku terminálu. pomocou knižnice Termbox.

Príklad mojej iniciály D:

    +--\
    |   |
    |   |
    +--/

Vaša bude samozrejme krajšia.

### Nainštalujte si knižnicu Termbox

Na váš stroj si ju nainštalujete podľa
[návodu](https://github.com/nsf/termbox). Na servri `omega.tuke.sk` je
knižnica už nainštalovaná.

V procese inštalácie sa zdrojové súbory skompilujú do formy knižnice.
Knižnica a príslušné hlavičkové súbory sa potom skopírujú so systémových
priečinkov, kde ich kompilátor vie nájsť.

Preštudujte si [hlavičkový
súbor](https://github.com/nsf/termbox/blob/master/src/termbox.h)
knižnice Termbox a dozviete sa, čo všetko knižnica dokáže.

### Vytvorte si priečinok s projektom

Vytvorte si priečinok s názvom `pvjc19cv3`, kde budete dávať súbory s
projektom. Projekt môže vyzerať takto:

    program.h (hlavičkový súbor)
    program.c (modul s programom)
    main.c (modul s funkciou main)
    Makefile (pravidlá pre zostavenie)

Obsah súboru `program.h`:

``` c
#ifndef _PROGRAM_H_
#define _PROGRAM_H_

void initial();

#endif
```

Obsah súboru `main.c`

``` c
#include "program.h"

int main() {
    initial();
    return 0;
}
```

### Vytvorte si súbor s programom

Obsah súboru `program.c`:

``` c
#include "program.h"
#include <termbox.h>

void initial() {
    tb_init(); // Inicializácia knižnice
    // Tu dajte svoj program
    tb_change_cell(1,1,'a',TB_WHITE,TB_BLACK); // Vykreslí jeden znak na danú pozíciu.
    tb_present(); // Vykreslenie na obrazovku
    tb_shutdown(); // Uvoľnenie knižnice
}
```

### Navrhnite Makefile pre zostavenie programu

Najprv preložte program ručne. Ak sa to podarí, mal by vypísať jedno
písmeno `a` na obrazovku. Pri linkovaní musíte použiť prepínač
`-ltermbox` na pripojenie knižnice k Vášmu programu:

    gcc -g -c -Wall -std=c99 program.c -o program.o
    gcc -g -c -Wall -std=c99 main.c -o main.o
    gcc main.o program.o -ltermbox -o initial

Pri návrhu využite aj premenné na zápis často opakujúcich sa argumentov
prekladača.

### Modifikujte program

tak, aby vykreslil ako ASCII art prvé písmenko Vášho mena.

### Uložte si program na Gite

Celý projekt si nahrajte na náš [Git
server](https://git.kemt.fei.tuke.sk).

Nezabudnite nahrať Váš SSH verejný kľúč podľa [stručného
návodu](https://student.kemt.fei.tuke.sk/pvjc/materialy/git).

## Domáca úloha

Dokončite cvičenie.
