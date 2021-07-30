# Programátorské minimum

Jazyk C pre jednoducho uvažujúcich. 

Naučíte sa za 4 hodiny:

1. Napísať a preložiť triviálny program.
1. Vypísať správu.
1. Vytvoriť a inicializovať premennú.
1. Načítať číslo zo štandardného vstupu.
1. Navrhnúť funkciu s jedným parametrom, ktorá vracia jednu hodnotu.
1. Zavolať vlastnú funkciu s jedným parametrom a uložiť návratovú hodnotu.
1. Vypísať správu s parametrom.

Predpokladáme, že máte počítač s nainštalovaným prekladačom, textovým editorom a viete spustiť príkazový riadok.


Pre ešete väčšie zjednodušenie je možné použiť C Online IDE - nie je potrebné pracovať

[[TOC]]

# Príklad

```c
#include <stdio.h>

float mocnina(float);

int main() {
	printf("Mocninová kalkulačka\n");
    float vysledok = 0;
    printf("Výsledok je zatiaľ %f\n",vysledok);
    char vstup[10];
    printf("Zadaj hodnotu na max. 10 miest:");
    fgets(vstup,10,stdin);
    printf("Zadali ste %s\n",vstup);
    float parameter = 0;
    sscanf(vstup,"%f",&parameter);
    printf("Hodnota parametra je %f\n",parameter);
    vysledok = mocnina(parameter);
    printf("Výsledok je %f\n",vysledok);
    return 0;
}

float mocnina(float arg){
	float parameter = arg * arg;
	return parameter;
}
```

## Tutoriál 0:

Pripravte si prostredie pre prácu

## Tutoriál 1:

Napísať a preložiť triviálny program, ktorý napíše správu.

Budete potrebovať:

- Textový editor alebo IDE
- Príkazový riadok
- Prekladač jazyka C (gcc)

1. Otvorte si textový editor.
1. Napíšte zdrojový text.
1. Preložte zdrojový text.
1. Spustite program.

Potrebné znalosti:

- Čo je to súbor a adresár.
- Aký je rozdiel medzi textovým a binárnym súborom
- Čo znamená vykonateľný súbor

Naučíte sa:

- Zdrojový kód je zápis algoritmu v programovacom jazyku.
- Programovací jazyk je súbor pravidiel pre zápis algoritmov.
- Spustiteľný kód získame spracovaním (prekladom) zdrojového kódu
- Spustiteľný kód je plnohodnotný program


## Tutoriál 2: Premeň ma -  Premenné a dátové typy

Potrebné znalosti z predošlého tutoriálu.

Naučíte sa:
- Je možné uložiť hodnotu a tú neskôr použiť
- Každá hodnota má dátový typ.
- Dátové typy je možné meniť, má to ale vedľajšie efekty.
- Výpis premennej v rôznom formáte
- Rovnaký typ je možné vypisovať rôznymi spôsobmi
	- aj číslo s desatinnou čiarkou vieme zapisovať rôznym spôsobom
- Čítať dokumentáciu funkcie printf


## Tutoriál 3: Funguj - Návrh a používanie vlastnej funkcie

Potrebné znalosti z predošlého tutoriálu.

Naučíte sa:

- volanie funkcie bez parametrov
- parametre funkcie
- volanie funkcie odovzdávanie parametrov kópiou
- návratová hodnota funkcie a jej využitie


## Tutoriál 4: Hoď to do stroja: Načítanie a využívanie hodnoty

Potrebné znalosti z predošlého tutoriálu.

Naučíte sa:

- dátový typ reťazec
- parametre funkcie printf a sscanf
- Výpis čísla vlastne znamená jeho premenu na reťazec.
- Používať funkciu fgets a sscanf.
- čítať dokumentáciu funkcie fgets a sscanf.











