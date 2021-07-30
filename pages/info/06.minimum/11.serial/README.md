Mali by ste vedieť:

  - Základy štruktúrovaného programovania

  - Cyklus

  - Funkcia

  - Polia

  - štruktúry

  - Vypísať a načítať hodnotu

<div class="note">

<div class="title">

Naučíte sa

</div>

  - Otvorenie a zatvorenie súboru.

  - Práca so súborom je podobná práci s terminálom.

  - čítanie súboru po riadkoch.

  - binárne čítanie a zápis.

</div>

# Otvorenie a zatvorenie súboru

V jazyku C so súborom pracujeme pomocou špeciálneho smerníka `FILE*`.

Tento smern9k reprezentuje aktuálnu pozíciu hlavičky pevného disku,
pomocou ktorej vykonávame čítanie alebo zápis. Sperník `FILE*` je
definovaný v hlavičkovom súbore `<stdio.h>`.

Pred tým ako otvoríme súbor musíme povedať v akom móde chceme súbor
používať. Niektoré módy sú: - `r` : čítanie zo začiatku - `w` : zápis
na začiatok. Súbor je skrátený na nulu. - `a` : zápis na koniec súboru

<div class="warning">

<div class="title">

Pozor

</div>

Ak otvoríte súbor na zápis s príznakom `w`, prídete o dáta v súbore.

</div>

Súbor otvoríme príkazom `fopen`, kde prvý argument je meno súboru a
druhý argument je mód v ktorom chceme otvoriť súbor. Hneď ako skončíme
prácu so súborom je dobré smerník na otvorený súobor zrušiť a zavrieť
súbor pomocou príkazu `fclose`.

``` c
FILE* f = fopen("subor.txt","w");
fclose(f);
```

# Čítanie a zápis do súboru

Zápis textu do súboru vykonáme príkazom `fprintf`:

``` c
fprintf(f,"Ahoj subor\n");
```

Prvý argument je smerník na otvorený súbor, druhý argument je
formátovací reťazec. Ďalšie argumenty sú hodnoty, kotré sa majú
doplniť do formátovacieho reťazca.

Načítanie hodnoty z textového súboru prebieha podobne, ako načítanie z
terminálu. Môžeme použiť príkaz `fscanf`.

``` c
int hodnota = 0;
fscanf(f,"%d",&hodnota);
```

<div class="warning">

<div class="title">

Pozor

</div>

Načítanie nemusí prebehnúť úspešne.V prípade, že sa v súbore nachádza
niečo iné ako očakávaná hodnota nie je správanie programu definované.

</div>

# Smerník stdin a stdout

Ku konzole vieme pristupovať rovnako ako k súboru pomocou špeciálnych
smerníkov stdin, ktorý reprezentuje vstuv z klávesnice a stdou, kotrý
prepreentuje výstup na textový terminál. Tieto smerníky sa správanú ako
globálne premenné, kotré vytvára a ruší kompilátor pri štarte a konci
porgramu.

# Načítanie zo súboru do zložitejšej štruktúry

Ak potrebujeme na
