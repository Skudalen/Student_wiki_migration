---
title: Ahoj svet
---
Cieľom tohto tutoriálu je naučiť vás vytvoriť triviálny program v jazyku
C.


! Naučíte sa
!  - Zdrojový kód je zápis algoritmu v programovacom jazyku.
!  - Programovací jazyk je súbor pravidiel pre zápis algoritmov.
!  - Spustiteľný kód získame spracovaním (prekladom) zdrojového kódu
!  - Spustiteľný kód je plnohodnotný program


# Vytvorenie zdrojového textu

V textovom editore si otvorme súbor, ktorý môžeme nazvať `hello.c` a do
neho napíšeme:

``` c
#include <stdio.h>

int main(){
    printf("Ahoj svet\n");
    return 0;
}
```

Textový súbor uložíme a prvý krôčik máme za sebou. Práve sme vytvorili
svoj prvý program.

# Preklad

Náš program, je síce správny, ale počítač bude mať ťažkosti s jeho
vykonaním, pretože rozumie iba číslam. Zdrojový text v jazyku C je pre
človeka čitateľný. nie je priamo vykonateľný. Našou ďalšou úlohou bude
preklad zdrojového textu do tvaru, ktorý sa dá spustiť. Zo zdrojového
textu sa vytvorí binárny súbor, ktorý je tvorený číslami inštrukcií.
Binárny súbor už je vykonateľný. Prekladač funguje podobne ako stroj na
spracovanie textu. Vstupom do prekladača je zdrojový text programu,
ktorý sa spracuje a premení do vykonateľnej podoby. Požitie kompilátora
na zdrojový text, ktorý sme vytvorili je jednoduché:

``` bash
gcc hello.c -o hello
```

Ak sme pri prepise neurobili žiadnu chybu, tak by preklad mal prebehnúť
bez problémov a vznikne spustiteľný súbor `hello`.

# Chybové hlásenia

Ak sme predsa len nejakú chybu urobili, prekladač napíše chybovú hlášku
a preklad neprebehne. Pozorne si hlásenie prečítajte a skúste opraviť
chybu. Chybové hlásenie (skoro) vždy obsahuje číslo riadku a znak, kde
sa chyba nachádza a podľa toho sa ku chybe vieme vrátiť. Ak je chybových
hlásení viac, ignorujeme všetky okrem prvého. Opravíme prvú chybu,
preložíme program a sledujeme, či oprava pomohla. Ak nie, postup
opakujeme dovtedy, pokiaľ nie je preklad úspešný.

# Spustenie programu

Ak preklad prebehol správne, môžeme vyskúšať výsledok. Najprv overíme
situáciu, či sa tam spustiteľný súbor naozaj nachádza:

``` bash
ls
hello.c hello
```

<div class="note">

`ls` je príkazom interpretera BASH, ktorý sa stará o vykonanie príkazov
v príkazovom riadku. Jeho ekvivalent v systéme Widows je príkaz `dir`.

</div>

Príkaz `ls` by mal zobraziť zdrojový súbor aj spustiteľný súbor.
Spustiteľný súbor môžeme spustiť:

``` bash
./hello
Ahoj svet
```

# Vývojový cyklus

Tento proces budeme opakovať stále dookola. V prvom kroku sme vytvorili
alebo upravili existujúce zdrojové kódy. V druhom kroku sme sa pokúsili
ich preložiť. Ak sa vyskytla chyba, tak sme sa museli vrátiť, znova
upraviť zdrojové kódy a znova program preložiť. Posledným krokom
vývojového cyklu je spustenie programu. Ak sme s výsledkom spokojní,
nemusíme pokračovať a výsledný program môžeme odovzdať do používania. Ak
nie, musíme začať znova.

**Postup prác pri programovaní.**

``` 
             +--------+         +---------+        +--------+
             | Edituj |  ---->  | Prelož  | ---->  | Spusť  | ---+
             +--------+         +---------+        +--------+    |
                 ^                                               |
                 |                                               |
                 +-----------------------------------------------+
```

# Úprava programu

Ak spustenie prebehlo úspešne, môžem Vám gratulovať - práve ste sa stali
(začínajúcim) programátorom. Náš prvý program je hotový.

Základy sú síce vybudované, ale výsledná stavba je malá. Zatiaľ vieme
slušne pozdraviť, ale to je všetko. Skúsime využiť vedomosti ktoré máme
aby sme výsledok trochu vylepšili. Okrem sveta skúsme pozdraviť aj
niekoho iného.

Nájdime riadok v programe, ktorý pravdepodobne spôsobuje výpis správy na
obrazovku a pozrime sa na neho bližšie:

``` c
 
 printf("Ahoj svet\n")
   ;
```

Okrem správy "Ahoj svet" si všimneme niekoľko vecí, ktoré nám veľa
povedia o jazyku C.

  - Okrem správy, ktorá sa má vypísať tam vidíme `printf` a úvodzovky.
    Takýto zápis so zátvorkami nazývame **volanie funkcie**, Časť pred
    zátvorkou je **názov funkcie** a časť v zátvorke sú **argumenty
    funkcie** .

  - Správa `"Ahoj svet"` je ohraničená úvodzovkami a zakončená znakom
    `'\n'`. Znaky ohraničené úvodzovkami nazývame **reťazec**. `'\n'`
    znamená nový riadok (line feed).

  - Riadok je zakončený bodkočiarkou. Takýto riadok nazývame **príkaz**.

Program v jazyku C sa skladá z definícií funkcií a ich volaní. Každú
funkciu v jazyku C musíme pred volaním definovať, lebo jazyk C ako taký
nepozná žiadne funkcie, iba spôsob ako ich definovať a volať.

V prípade funkcie `printf` je situácia jednoduchá, lebo funkciu už
definoval niekto za nás. Nám už iba stačí “naučiť” kompilátor, čo
znamená `printf` tým, že oznámime, kde definíciu funkcie nájde.

Na overenie týchto tvrdení použijeme tzv. *kreatívnu chirurgiu* a mierne
zmrzačíme náš program. Upravíme niektorý riadok programu a zopakujeme
proces prekladu. S vedeckým odstupom sledujeme čo sa stane:

``` c
#include <stdio.h> 

int main(){
    printf("Ahoj svet\n");  
    return 0;
}
```

  - Zmeňte `"svet\n"` na `"TUKE"` Zistili sme, že `"\n"` je zápis pre
    koniec riadku.

  - Zmeňte `printf` na `print` Zistili sme, že takú funkciu systém
    nepozná. Opravte chybu a pokračujeme.

  - Vymažte riadok s `#include`. Zistili sme, že napriek očakávaniam
    kompilátor hlási chybu na riadku s `printf`.

Zoznam funkcií, ktoré môžeme pri práci použiť sa nazýva "Štandardná
knižnica jazyka C".

# Úlohy na precvičenie

Modifikujte program tak, aby do prvého riadka vypísal Vaše meno a do
druhého riadka Vašu obľúbenú farbu napr.:

    Moje meno je Chuck Norris
       a moja obľúbená farba je krvavo čierna.

Pozrite si dokumentáciu štandardnej knižnice a skúste využiť ľubovoľnú
ďalšiu funkciu, napr. `sleep()`. Nezabudnite, že pred použitím musíte
funkciu "naučiť" pomocou `#include`.
