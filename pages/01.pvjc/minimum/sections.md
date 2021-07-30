---
title: Programátorské minimum
published: true
visible: true
hide_page_title: true
show_sidebar: true
sections_nav_align: left
content:
    items: '@self.children'
    order:
        by: folder
        dir: asc
    limit: 0    
    taxonomy:
        filter: [view1,view2]
---


Ing. Daniel Hládek PhD.

Prípravná verzia študijnej literatúry pre predmet Programovanie

Uvítam Vaše pripomienky.


Celá kniha ako [PDF](minimum.pdf)

## Obsah

Časť 1:

1. [Ahoj Svet](helloworld) - Prvý program
2. [Premeň ma](premenna) - Premenné
3. [Funguj](funguj) - Funkcie
4. [Hoď to do stroja](hodtodostroja) - Načítanie z klávesnice
5. [Bicyklová reťaz](bicykel) - Cykly a reťazce

Časť 2: (v príprave)

6. [Na správnej adrese](adresa) - Smerníková premenná a funkcia na načítanie vstupu
7. [Zemiaky na poli](pole) - Polia a smerníková aritmetika
8. [Štruktúra bublinkovej fólie](struct) - Štruktúry
9. [Dynamo pamätlivé](dynamic) - Dynamická alokácia pamäte
10. [Folklórny súbor](serial) - Práca so súbormi

Jazyk C pre jednoducho uvažujúcich.

Začínajúcich programátorov často odradí veľké množstvo pojmov ktoré je
nutné sa naučiť a technologických problémov, ktoré je potrebné prekonať.
Naučiť sa programovať znamená prekonanie týchto počiatočných prekážok.
Cieľom tejto príručky je priblížiť jazyk C ľuďom bez predchádzajúcej
skúsenosti s programovaním a uľahčiť prekonanie počiatočných prekážok.

Naučiť sa programovať sa nedá inak ako vyskúšaním "na vlastnej koži". V
sérii niekoľkých tutoriálov Vás príručka naučí základné programátorské
postupy. Nestačí "iba" čítať, dokonalý zážitok dosiahnete len tak že
príklady v tutoriáloch si prepíšete a preložíte sám.

Predpokladáme, že máte počítač s nainštalovaným prekladačom, textovým
editorom a viete spustiť príkazový riadok. Odporúčame si nainštalovať
operačný systém Linux - obsahuje všetko potrebné pre vytváranie
programov v jazyku C.

<div class="note">

<div class="title">

Naučíte sa za 4 hodiny

</div>

Programátorské minimum:

1.  Napísať a preložiť triviálny program.

2.  Vypísať správu.

3.  Vytvoriť a inicializovať premennú.

4.  Načítať číslo zo štandardného vstupu.

5.  Navrhnúť funkciu s jedným parametrom, ktorá vracia jednu hodnotu.

6.  Zavolať vlastnú funkciu s jedným parametrom a uložiť návratovú
    hodnotu.

7.  Vypísať správu s parametrom.

</div>

**Príklad.**

```clike
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
