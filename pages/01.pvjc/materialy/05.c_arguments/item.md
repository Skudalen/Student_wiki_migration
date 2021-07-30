---
title: Argumenty príkazového riadka
published: false
---

# Práca s argumentami príkazového riadka

Argumenty príkazového riadka nájdete v poli reťazcov `argv`, počet argumentov je v premennej `argc`:

``` c
#include <stdio.h>

int main(int argc, char** argv){
    if (argc < 2){
        printf("Nemám dosť argumentov\n");
        return 0;
    }
    printf("Ja som prvý argument %s\n",argv[0]);
    printf("Ja som druhý argument %s\n",argv[1]);
    return 0;
}
```

Tento program je trochu zložitejší. To ale nebude problém, lebo sa bude skladať z viacerých jednoduchších častí. Každá časť bude riešiť čiastkový problém. Vďaka tomu sa "veľký" problém zmení na množinu
"malých" a jednoduchšie riešiteľných problémov. Časť návrhu máte vytvorenú dopredu vo forme hlavičkového súboru s dátovými typmi a predpismi funkcií ktoré implementujete.

Aplikácia je rozdelená do dvoch modulov - jeden bude riešiť prácu s dátami a druhý sa bude starať o komunikáciu s používateľom.

V prvom module `anketa.c` sa budeme sústrediť na "logiku" nášej
aplikácie. Každá funkcia sa bude riešiť a testovať osobitne.

V module sú najprv definované dátové typy a konštanty s ktorými budeme pracovať. Potom si definujeme funkcie ktoré budú pracovať s navrhnutými dátovými typmi:

  - spočítanie platných položiek.
  - vyhľadanie konkrétnej položky.
  - porovnanie dvoch položiek podľa početnosti.
  - zotriedenie celej databázy podľa početnosti.
  - načítanie databázy zo súboru.
  - výpis výsledku na obrazovku.

Množina týchto funkcií tvorí takmer kompletný program, pre ktorý stačí vytvoriť jednoduché textové používateľské rozhranie. Na rozhranie sa môžte sústrediť v module `main.c`. Vo vhodnom poradí volajte funkcie z prvého modulu a vypisujte správy na obrazovku tak aby práca s programom
bola ľahko pochopiteľná pre človeka ktorý sa s ním stretol po prvý raz.

Používateľské rozhranie by malo byť založené na argumentoch príkazového riadka. Na začiatku načítajte súbor (názov zadajte ako prvý argument), spracujte ho a podľa ostatných argumentov vykonajte niektorú akciu.

Program by mal akceptovať nasledovné argumenty:

  - `-h` vypíše návod na ovládanie.
  - `-s` vyhľadá zadané meno.
  - `-p` vypíše výslednú databázu mien.
  - `-o` zotriedi výslednú databázu podľa početnosti.
  - `-c` vypíše počet všetkých odovzdaných hlasov.
  - `-i` vypíše počet študentov, ktorí dostali aspoň jeden hlas.

Príklad práce s programom:

    ./anketa hlasy.list -s Hrozný
    Ivan Hrozný
    23
