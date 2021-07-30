# /inner

Osobná obhajoba zadania:

Pokyny pre hodnotenie

  - 1.5 B Včasnosť

  - 1.5 B znalosť kódu (odpoveď na otázku)

  - 2 B spracovanie argumentov príkazového riadka

Hodnotené aktivity:

Nápady na zadania

<http://codeforces.com/blog/entry/14021>

<https://github.com/SnapDragon64/ACMFinalsSolutions>

Otoč spojkový zoznam

<https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1>

Zisti, či sú dva polia rovnaké - obsahujú rovnaké čísla?

<https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not/0>

Spočítaj písmená. Zisti frekvenčnú tabuľku zo zadaného textu.

Spájanie povrazov (queue).

<https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0>

Slová naopak:

<https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0>

Nájdi postupnosť s maximálnym súčtom.

<https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0>

Burza - nájdi dni, keď sa oplatí nakúpiť a predať.

<https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0>

Množina

Vyraď čísla z postupnosti, ktoré sa viac krát opakujú.

Wordcounter

spočítaj čísla

# Nekonečný riadok

Mali by ste vedieť:

  - pracovať so statickým poľom

  - odovzdať pole ako argument na spracovanie

  - názov poľa je adresa jeho prvého prvku.

Načítanie zo štandardného vstupu po znakoch.

Naučíte sa:

<div class="tip">

<div class="title">

Zopakujete si

</div>

  - Pracovať s dynamickým poľom.

  - Precvičíte si inicializáciu, alokáciu a uvoľnenie pamäte

  - malloc, calloc, realloc, free

</div>

Dynamické pole

Pole môže mať akýkoľvek typ, ktorý si určíte.

# Načítanie po znakoch

1.  Alokujeme buffer na počiatočnú veľkosť.

2.  Načítame jeden znak

3.  Overíme, či nenastal koniec súboru.

4.  Overíme, či máme dosť miesta v buffri. Ak nemáme dosť miesta,
    realokujeme buffer na novú veľkosť.

5.  Zapíšeme znak do buffru. Ak je znak koniec riadka, vypíšeme ho a
    zapisujeme od začiatku.

# Realloc

Zmena veľkosti už alokovanej pamäte

1.  Zoberie existujúcu pamäť.

2.  Ak je to potrebné, tak alokuje novú pamäť.

3.  Ak nie je možné alokovať novú pamäť, vráti NULL.

4.  Inak vráti smerník na novú alebo starú pamäť

# Nekonečný riadok celých čísel
