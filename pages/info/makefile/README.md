# Zostav si svoj program

Naučíte sa:

  - Zostaviť program zložený z knižníc a modulov.
  - Napísať pravidlá systému `make`.
  - Používať funkcie z externých knižníc.


## Zostavenie programu

Zostaviť program ktorý sa skladá z jedného súboru v jazyku C je
jednoduché. Prekladač sa postará o všetko dôležité - predspracovanie, preklad aj linkovanie.

Príkaz

    gcc program.c -o program

vykoná všetky dôležité kroky a ak je zdrojový kód správne napísaný
vytvorí spustiteľný súbor.

Situácie je o niečo zložitejšia v prípade, keď program je dlhší a skladá sa z viacerých modulov. Vtedy musíme preložiť každý modul samostatne a potom ich spojiť do jedného spustiteľného súboru.

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
vykoná pravidlo. Ak je cieľový súbor mladší, nevykoná sa nič.

Pravidlá zapisujeme v tvare:

    cieľový objekt: zoznam zdrojových objektov
        pravidlo ako zo zdrojových objektov vytvoriť cieľový objekt

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

NOTE:    Pred príkazom sa nachádza znak TAB (`\t`). Obyčajné medzery nebudú
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

Ak používate knižnicu `curses` je potrebné ju pripojiť pomocou prepínača `-lcurses`.
