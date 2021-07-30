---
title: 'Zase jazyk C'
published: true
process:
    markdown: true
    twig: true
twig_first: true
never_cache_twig: true
---

# 2. Načítaj ma, najväčší spoločný deliteľ


## Ciele

- obnoviť praktické schopnosti programovania v jazyku C;
- preklad a spustenie programu;
- vytvorenie a vyvolanie funkcie;
- základy smerníkov;
- načítanie z reťazcov z klávesnice a výpis na obrazovku.
- premena reťazca na celé číslo

## Úvod

Zostavte program na výpočet najväčiieho spoločného deliteľa dvoch celých čísel.

Na vstupe sa ale môže nachádzať hocičo!


## Ako na to

Vytvorte a preložte jednoduchý program, ktorý vypíše správu na obrazovku.

Program bude vyzerať podobne ako legendárny "Ahoj svet".
Bude sa skladať z jedinej funkcie main a bude obsahovať volanie funkcie pre výpis textu na obrazovku.

## 3. Vytvorte funkciu pre načítanie z klávesnice do zadaného poľa.

Vytvorte funkciu na načítanie reťazca z klávesnice do poľa *vrátane konca riadku*. Reťazec môže obsahovať aj
medzery a je ukončený koncom riadku alebo koncom súboru.

NOTE: Funkcia `scanf` načítava iba po prvú medzeru.

Funkcia by mala spĺňať tento predpis:

```c
int read_line(char* line,int size)
```

Funkcia postupne načítava znaky z klávesnice do poľa pomocou indexu `i`.
Načítanie sa môže prerušiť z troch rôznych dôvodov:

- Načítaný znak je EOF;
- Načítaný znak je '\n';
- Nie je dosť miesta v poli.

V každom prípade treba na koniec poľa pridať nulu aby bol reťazec znakov platný.

Funkcia vráti počet znakov, ak nenašla koniec súboru alebo `EOF` ak našla koniec súboru.

Pri návrhu algoritmu môžete postupovať podľa tohto postupu:

### 3.4 Správne ukončite reťazec

Nezabudnite, že v každom prípade reťazec musí byť ukončený nulou:

`line[i] = 0`;

Na konci načítania ešte musíte vo funkci vrátiť správnu hodnotu. Ak ste našli `EOF` vrátte `EOF`, inak vrátte počet načítaných znakov.


.Zopakujte si
[WARNING]
####
- Ak zabudnete doplniť nulu na konci reťazca, pokus o jeho vypísanie môže skončiť pádom programu.
- Pri odhalení nesprávnej práce s pamäťou nám pomôže program Valgrind, napr. `valgrind ./pizza1`
- Na to aby nám Valgrind prezradil aj číslo riadka na ktorom nastala chyba je potrebné program preložiť s parametrom `-g` pre pridanie debugovacích informácií,
napr. `gcc -g program.c -o program`
####

### 3.1 Vytvorte cyklus

Načítanie realizujte v cykle typu `for`.
Vytvorte si pomocnú premennú `int i`, ktorú zvýšte o 1 pri každom načítanom znaku. Maximálny počet načítaných znakov je `size - 1`.

### 3.2 Pridajte príkaz na načítanie jedného znaku do premennej

Výsledok načítania si uložte do premennej typu `int`.


### 3.3 Zistite, čo ste načítali

Načítaný znak ktorý je v poriadku uložte do poľa `line`.
Načítanie opakujte, až pokiaľ nie je načítaný znak `\n` alebo `EOF`. Ak zistíte, že ste našli koniec riadku, uložte
ho tiež do poľa a predčasne ukončite cyklus `for` pomocou `return`.


## 4. Vo funkcii main využite funkciu na načítanie reťazca

Načítajte viac reťazcov a uložte ich do pola reťazcov.

.Zopakujte si
[TIP]
####
- jeden prvok dvojrozmerného poľa je jednorozmerné pole, ktoré mlžeme použiť na uloženie jedného reťazca. Dvojrozmerné pole môžeme vnímať aj ako pole reťazcov.
- viac reťazcov si môžeme uložiť do dvojrozmerného poľa.
- prvky dvojrozmerného poľa sú jednorozmerné polia.
- mázov poľa je smerník na jeho začiatok.
####


## Odovzdanie

cez git, 4 body za aktivitu

