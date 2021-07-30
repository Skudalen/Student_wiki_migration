---
title: Úvod do algoritmizácie a programovania
presentation:
  theme: sky
  order:
    by: date
    dir: desc

published: true
---
# Základy algoritmizácie a programovania

Ing. Daniel Hládek PhD.

Katedra elektroniky a multimediálnych telekomunikácií

---
# Vitajte na Technickej univerzite

Technické informácie

---
# Obsah prednášky

- Prvý program
- Preklad a spustenie programu

---
# Zápočet je podmienkou na vykonanie skúšky

Zápočet získate počas semestra, potom sa môžete prihlásiť na skúšku počas semestra.

Predmet sa končí vykonaním skúšky.

---
# Ako získate zápočet

- Budete chodiť na cvičenia
- Získate min. 11 bodov z 20
- Budete samostatne pracovať na zadaniach a cvičeniach

---
# Ako nezískate zápočet

- Nebudete dodržiavať etický kódex
- Budete čakať, kým Vás niekto nenaučí programovať

---
# Odporúčania

--- 
#  Pravidelná práca počas semestra je veľmi dôležitá.

---
# Nebojte sa opýtať

- Googla
- Knihy
- Cvičiaceho alebo prednášajúceho

Pomôžeme Vám

---
# Nebojte sa do toho pustiť

- Je v poriadku, keď niečo neviete.
- Nie je v poriadku, keď nič nespravíte.

---
# Dá sa to

Nebojte sa!

---
# Programovanie je dôležté

- algoritmizácia problému
- znalosť syntaxe programovacieho jazyka
- znalosť prostriedkov, ktoré máme k dispozícii

---
# Byť programátor? Ale aj tak...

- Budem pracovať s aplikáciami
- Budem používať technickú dokumentáciu
- Budem konfigurovať aplikácie alebo zariadenia
- Budem pracovať s programovateľnými zariadeniami

---
#  Budem vytvárať a vykonávať algoritmy

- Na návrh a správu počítačovej siete
- Pre podporu IT procesov
- alebo pre veľkokapacitné stravovanie...

---
#  Budem čítať a písať technickú dokumentáciu

- K novému routru
- alebo robtickému vysávaču
- Liebesbrief cez sociálnu sieť

---
# Alebo predsa len budem programátor

a zarobím viac ako prednášajúci :-)

---

# O čom je predmet

V predmete sa naučíme algoritmicky myslieť a pracovať.

[note]
- napísať, preloži a spustiť štruktúrovaný program
- používať knižnice
- pracovať so štandardným vstupom a súbormi
[/note]

---
# Algoritmus je príbeh so šťastným koncom

Postupnosť krokov, ktorá v konečnom čase viedie k dosiahnutiu výsledku.

---
# Vytvárať algoritmus znamená písať list

List obsahuje príbeh napísaný jazykom ktorému adresát rozumie.

Adresát si ho prečíta a vykoná to, o čo sme ho požiadali.

---
![Letter](https://cdn.pixabay.com/photo/2013/07/13/12/20/heart-159637_960_720.png)

---
# Garbage IN => Garbage OUT

Odmietne poslušnosť v iba prípade, že nerozumie čo od neho chceme.

Teechnické zariadenie nemá vlastný rozum, robí iba to čo mu povieme.

---

[data-background-iframe="https://www.youtube.com/embed/ouf3uLeLioE"]

---
# Ak je recept dobrý

![Choco](https://cdn.pixabay.com/photo/2017/09/19/08/49/chocolate-2764581_960_720.jpg)

---
# Nemecný romantický film

- Vstup: On, Ona a Zloduch
- Potrebujeme: nečakané okolnosti
- Výstup: svadba a deti

---
# Recept na párky

- Vstup: voda, párky
- Potrebujeme: rýchlovarná konvica
- Výstup: teplé párky

---
# Recept na teplé párky

1. Nalej vodu do kanvice
1. Pridaj párky
1. Var pokiaľ nie sú párky teplé

---
# Vlastnosti algoritmu

- jednoznačnosť: - má definovaný vstup a výstup
- konečnosť: výsledok príde v konečnom čase
- rezultatívnosť: výsledok je garantovaný
- univerzálnosť: dá sa aplikovať na ľubovoľný vstup

---
# Program
je zápisom algoritmu jazykom ktorý je zrozumiteľný počítaču.

---
# Programovať sa dá naučiť iba programovaním

Tancovať sa dá naučiť iba tancovaním.

---
# Robot Karel

- Pomôže Vám s učením
- je síce mentálne jednoduchý, ale zato veľmi poslušný. 
- žije v miestnosti so žetónmi.
- vie sa prechádzať po miestnosti a premiestňovať žetóny.

---
# Miestnosť robota Karla
---

```
 CORNER  FACING  BEEP-BAG  BEEP-CORNER
  (3, 2)   EAST       0         1
 ST.+-----------------------------------+
  9 | .   .   .   .   .   .   .   .   . |
    |                                   |
  8 | .   .   .   .   .   .   .   .   . |
    |                                   |
  7 | .   .   .   .   .   .   .   .   . |
    |                                   |
  6 | .   .   .   .   .   .   .   .   . |
    |                       +---+       |
  5 | .   .   .   .   .   . | . | .   . |
    |                   +---+   |       |
  4 | .   .   .   .   2 | .   . | .   . |
    |               +---+       |       |
  3 | .   .   .   . | .   .   . | .   . |
    |           +---+           |       |
  2 | .   .   > | .   .   .   . | .   . |
    |       +---+               |       |
  1 | .   . | .   .   .   .   . | .   . |
    +-----------------------------------+
      1   2   3   4   5   6   7   8   9   AVE.
```

---
# Jazyk robota Karla

Robotov jazyk sa skladá zo slov a viet.

Základné slovesá, ktorým robot rozumie:

---
# Tieto slovesá hovoria príbeh

```c
turn_on("world.kw");
step();
turn_left();
pick_beeper();
put_beeper();
turn_off();
```

---
# Preklad do slovenčiny

```c
turn_on("world.kw");  // Zapni sa
step();             // Pohni sa dopredu
turn_left();          // Zatoč do ľava
pick_beeper();        // Zober žetón
put_beeper();         // Polož žetón
turn_off();           // Vypni sa
```

---
# List musí spĺňať formálne náležitosti

- Musíme povedať, ktorý slovník používame.
- Musíme povedať je začiatok a kde je koniec príbehu.

---

```c
#include <karel.h>
int main(){
    turn_on("world.kw");
    turn_left();
    pick_beeper();
    turn_off();
    return 0;
}
```
---
# Práve sme napísali prvý program v jazyku C

Ani to nebolelo. Každý ďalší program sa Vám bude písať ľahšie.

---
# Ale ako robot vykoná naše príkazy?

Napísali sme program - text v špeciálnom jazyku. 

Ako ho doručíme robotovi Karlovi?

---
# Proces zostavenia programu

(build)

---
Preklad prebieha v dvoch fázach:

1. Príprava (preprocessing): priložia sa všetky slovníky (hlavičkové súbory) 
1. Preklad zdrojových kódov (kompilácia): všetky slová (deklarácie) sa zoradia za sebou a preložia sa do strojového kódu.
2. Spájanie (linkovanie): vyhľadájú a priradia sa významy (definicie) všetkých slov.

[note]
<div class="mermaid">
graph LR
	H(hlavičkové <br /> súbory .h) --> C
    P(zdrojový <br />kód .c) --> C(prekladač)
	C --> O(objektový <br /> súbor .o)
	O --> L(linker)
	K(knižnice .a) --> L
    L --> S(spustiteľný <br /> subor)	
</div>
[/note]

---

# Niečo nie je v poriadku

Ak sme pri zápise urobili chybu, preklad neprebehne úspešne.

Kompilátor nám hlási chybu. 

Chybové hlásenie je potrebné si pozorne prečítať.

---
# Kompilátor

Musíme využiť "poštový úrad" - kompilátor. 

Kompilátor sa pozrie na náš list a ak spĺňa formálne požiadavky, tak ho tlmočí do Karlovho jazyka.

[mermaid]
graph LR
   P(zdrojový kód) --> kompilátor
   kompilátor --> B(spustiteľný súbor)
[/mermaid]

---
# Proces prekladu programu

Preklad programu je algoritmus
(postupnosť krokov, ktorá vedia ke výsledku vkonečnom čase)

---

- Vstup: Zdrojový kód
- Potrebujeme: Prekladač, knižnice 
- Výstup: Spustiteľný kód

---
*Zdrojový kód* : je zápis algoritmu v špeciálnom jazyku (C) v textovej podobe zrozumiteľnej človeku.

*Spustiteľný kód* : prepis algoritmu do podoby čitateľnej procesorom. Spustiteľný kód sa skladá iba z čísel a nie je človenkom čitateľný (skúste to).

---
# Kompilácia programu pomocou gcc

- Prvé slovo je názov príkazu.
- Ostatné slová sú argumenty

---
	kompilátor   ďalšie argumenty  knižnica1       knižnica2 vstup      výstup

	gcc          -std=c11          libkarel32-lin.a -lcurses karel.c -o karel


![Mlynček](https://cdn.pixabay.com/photo/2015/05/25/16/19/mincer-783559_960_720.jpg)

---
# Spustenie programu

Náš nový program vieme spustiť rovnako ako každý iný,

	./karel
    
Bodka je potrebná kvôli bezpečnostnej politike systému UNIX.

---
# Koniec prvej časti

Ďakujem za pozornosť.

Odpoviem na Vaše otázky

daniel.hladek@tuke.sk
