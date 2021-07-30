
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

Preštudujte si [hlavičkový ;súbor](https://github.com/nsf/termbox/blob/master/src/termbox.h)
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


## Domáca úloha

Dokončite cvičenie.
