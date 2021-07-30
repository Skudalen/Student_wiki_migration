<div class="note">

<div class="title">

Naučíte sa

</div>

  - Pracovať so zložitejšími dátami a ukladať ich do polí v
    štruktúrovanej podobe.

  - Triediť zoznam položiek podľa zvoleného atribútu.

</div>

Program v jazyku C vieme využiť aj na prácu so zložitejšími dátami ako
sú celé a desatinné čísla. V tejto časti sa naučíme vytvoriť program na
načítanie databázy a jej zotriedenie podľa zvolenej položky.

Prevtelíme sa do úlohy zamestnanca firmy pracujúcej v oblasti
poľnohospodárstva. V našej biofarme sa profesionálne venujeme
pestovaniu rôznych zdravých produktov na rozľahlých poliach. Od šéfa sme
práve dostali zadanie vytvoriť databázu poľnohospodárskych strojov v
našej biofarme. Každý stoj má svoj opis a počet najazdených kilometrov.

# Štruktúry

Využijeme svoju znalosť jazyka C a informácie o strojoch v garáži si
uložíme do premenných. Prvou časťou návrhu je rozmýšľanie o tom, aké
dátové typy budeme potrebovať. Pre každý stroj v našej garáži musíme
evidovať jeho meno a počet najazdených kilometrov. Pre meno stroja sa
javí najvýhodnejší dátový typ reťazec maximálne 19 znakov (`char[10]`).
Pre stav tachometra by mohla stačiť celočíslená premenná (`int`).

Vložme si všetky dostupné informácie o poľnohospodárskych strojoch do
krátkeho programu. Premenné si môžeme ľahko vypisovať na obrazovku,
kedykoľvek si spustíme náš výtvor:

``` c
#include <stdio.h>
int main(){
    char meno1[10]="Traktor";
    int tachometer1 = 20000;

    char meno2[10]="Retro Traktor";
    int tachometer2 = 200000;

    char meno3[10]="Kombajn";
    int tachometer3 = 123456;

    printf("V garazi mame:\n");
    printf("%s, najazdenych %d km\n",meno1,tachometer1);
    printf("%s, najazdenych %d km\n",meno2,tachometer2);
    printf("%s, najazdenych %d km\n",meno3,tachometer3);

    return 0;
}
```

Program je veľmi pekný a funguje výborne. Takmer sme od šéfa za neho
dostali pochvalu. Nanešťastie si spomenul, že by bolo fajn, keby sme
zistili, ktorý stroj má toho najazdené najviac. Samozrejme, dalo by sa
to vyriešiť metódou pozriem - vidím, ale to nie je hodné pracovníka IT
oddelenia farmy "Zdravý život". A je už vybavené, že naša farma dostane
eurodotáciu, a dokúpime ďalších 70 strojov.

Informácie o jednom stroji by bolo dobré mať v jednej premennej, aby sme
vedeli spojiť informácie o mene a počte najazdených kilometrov. Poznáme
typ `int` vhodný na uloženie celých čísel a typ pole znakov `char[]`,
ktoré je vhodné na uloženie mena. Nepoznáme ale typ `traktor` do ktorý
by bol vhodný na uloženie informácií o traktoroch.

Našťastie si môžeme definovať vlastný dátový typ: Nový dátový typ je
niečo návod na usporiadanie miesta v pamäti.

``` c
struct traktor {
    char meno[10];
    int tachometer;
};
```

Týmto zápisom sme si definovali vlastný dátový typ, ktorý sa bude volať
`struct traktor`. Pomocou štruktúry sme prekladaču vysvetlili, že pod
pojmom "struct traktor" rozumieme dvojicu atribútov `meno` a
`tachometer`. Tieto dva atribúty sa budú vyskytovať a spracovávať spolu.

V novom dátovom type definujeme druh "priehradiek", z ktorých sa bude
skladať. Jednu priehradku nazývame "člen" štruktúry alebo "atribút".
Člen štruktúry môže byť ľubovoľný existujúci dátový typ, dokonca aj iná
štruktúra.

<div class="tip">

Vymyslite štruktúru vhodnú na uloženie informácií o kuchynských
mixéroch.

</div>

# Statická inicializácia

Pomocou štruktúry `struct traktor` sme vysvetli, ako vyzerá traktor vo
všeobecnosti. Traktor v našom programe má zatiaľ iba tachometer a
ceduľu s menovkou, ale nebude problém uvažovať aj nádrž, objem motora
alebo počet kolies. Stále sa ale pohybujeme v rovine úvah o tom, aký
druh strojov chceme mať v garáži.

Ak chceme predstavy premeniť na skutočnosť, musíme pristúpiť k ich
realizácii - akvizícii strojovej techniky. V reálnom svete by to
znamenalo transfer finančných prostriedkov smerom k predajcovi a
transfer traktora smerom k nám. V počítačovom programe zase musíme
vyhradiť pamäťové miesto, kde si uložíme informácie o novom stroji.

Definícia štruktúry sa podobá na definíciu funkcie. Ak definujeme
funkciu, neznamená to, že sme ju vykonali - iba sme vysvetlili ako sa má
vykonať. Na vykonanie je potrebný špeciálny príkaz na vykonanie funkcie.
Podobne aj pri štruktúrach potrebujeme špeciálny príkaz na vytvorenie
pamäťového miesta s dátovým typom štruktúra:

``` c
struct traktor zetor;
```

Tento príkaz vytvorí nové miesto pre uloženie informácií o traktore
`zetor`.

Celý program kde definujeme štruktúru `struct traktor` a vytvoríme jedno
pamäťové miesto na uloženie informácií o jednom konkrétnom traktore bude
vyzerať takto:

``` c
// Definícia nového dátového typu
struct traktor {
    char meno[10];
    int tachometer;
};

int main() {
    // Použitie nového dátového typu v novej premennej
    struct traktor zetor;
    return 0;
}
```

<div class="warning">

<div class="title">

Pozor

</div>

Informácie o nových dátových typoch píšeme na rovnakú úroveň ako funkciu
`main()`, nikdy nie do vnútra funkcie.

``` c
int main() {
    // Definícia nového dátového typu platí iba pre túto funkciu
    struct traktor {
        char meno[10];
        int tachometer;
    };

    // Použitie nového dátového typu v novej premennej
    struct traktor zetor;
    return 0;
}
```

</div>

Bolo by fajn, keby sme do novej premennej nového dátového typu vedeli
uložiť nejaké informácie. Klasický postup s operátorom = asi fungovať
nebude. Na rozlíšenie toho, ktorý atribút premennej chceme využívať
použijeme operátor `.` .

``` c
zetor.tachmoter = 123;
```

Menší problém nastane pri pokuse o určenie mena nového traktora. Príkaz
na priradenie reťazca nefunguje podľa očakávania:

``` c
zetor.meno = "Zetor 1000";
```

<div class="tip">

Zistite, aká hodnota najazdených kilometrov sa nachádza tesne po
vytvorení premennej.

</div>

<div class="informalexample">

Namiesto toho môžme vykonať kopírovanie reťazce ručne. Využijeme fakt,
že reťazec je vždy zakončený nulou.

``` c
int i = 0;
char meno[10] = "Zetor 1000";
while(meno[i] != 0){
    zetor.meno[i] = meno[i];
    i += 1;
}
zetor.meno[i] = 0;
```

</div>

môžME využiť funkciu zo štandardnej knižnice `strcpy` na skpírovanie
reťazca, ktorá kopíruje reťazce. Musíme dbať na to, aby v mieste kde
kopírujeme bolo dosť miesta. Pre použitie funkcie `strcpy` musíme
priložiť hlavičkový súbor `<string.h>`.

``` c
strcpy(zetor.meno,"Zetor 1000");
```

# Statická inicializácia štruktúry

Druhou možnosťou je alokácia a inicializácia v jednom kroku. O
kopírovanie sa postará kompilátor. Na tento účel existuje špeciálny
zápis, ktorý sa podobá na inicializáciu poľa. Musíme len špecifikovať
mená členov, ktoré inicializujeme:

``` c
struct traktor zetor = {.meno:"Zetor 1000",.tachometer:123};
```

<div class="warning">

tento zápis môžme použiť iba pri inicializácii premennej, nie v ďalšom
programe.

</div>

Celý program bude vyzerať trochu inak. Hlavným rozdielom je to, že
informácie o jednom poľnohospodárskom stroji sú uložené v jednej
premennej.

``` c
#include <stdio.h>
struct traktor {
    char meno[10];
    int tachometer;
}
int main(){
    struct traktor stroj1 = {.meno:"Traktor",.tachometer:123};
    struct traktor stroj2 = {.meno:"Retro Traktor",.tachometer:10000};
    struct traktor stroj3 = {.meno:"Kombajn",.tachometer:3454};

    printf("V garazi mame:\n");
    printf("%s, najazdenych %d km\n",stroj1.meno,stroj1.tachometer);
    printf("%s, najazdenych %d km\n",stroj2.meno,stroj2.tachometer);
    printf("%s, najazdenych %d km\n",stroj3.meno,stroj3.tachometer);
    return 0;
}
```

# Polia štruktúr

Počet riadov programu ktorý využíva štruktúry sa takmer nezmenil a
získali sme to, že informácie o jednom stroji sú v jednej premennej.
Keďže sme firma, ktorá sa profesionálne venuje poliam, databázu
traktorov bude uložená v poli.

``` c
struct traktor stroje[3] = {
     {.meno:"Traktor",.tachometer:123},
     {.meno:"Retro Traktor",.tachometer:10000},
     {.meno:"Kombajn",.tachometer:3454}
};
```

Na prechádzanie poľa je špeciálne vhodný cyklus `for`. Výpis všetkých
strojov v databáze je potom geniálne stručný:

``` c
for (int i = 0; i < 3; i++) {
    printf("%s, najazdenych %d km\n",stroje[i].meno,stroje[i].tachometer);
}
```

Výsledný program bude takýto:

``` c
#include <stdio.h>
struct traktor {
    char meno[10];
    int tachometer;
};
int main(){
    struct traktor stroje[3] = {
        {.meno:"Traktor",.tachometer:123},
        {.meno:"Retro Traktor",.tachometer:10000},
        {.meno:"Kombajn",.tachometer:3454}
    };
    printf("V garazi mame:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s, najazdenych %d km\n",stroje[i].meno,stroje[i].tachometer);
    }
    return 0;
}
```

# Typedef

Program môžeme "vylepšiť" ešte viac. Nemusíme stále vypisovať `struct
traktor`. Pomocou zápisu `typedef` si môžeme definovať alias `traktor`
pre názov typu `struct traktor`:

``` c
typedef struct traktor {
    char meno[10];
    int tachometer;
} traktor;
```

Takto sme si vytvorili nový typ `traktor`. Zlepšená verzia môže vyzerať
takto:

``` c
#include <stdio.h>
#define POCET_STROJOV

typedef struct traktor {
    char meno[10];
    int tachometer;
} traktor;

int main(){
    traktor stroje[POCET_STROJOV] = {
        {.meno:"Traktor",.tachometer:123},
        {.meno:"Retro Traktor",.tachometer:10000},
        {.meno:"Kombajn",.tachometer:3454}
    };
    printf("V garazi mame:\n");
    for (int i = 0; i < POCET_STROJOV; i++) {
        printf("%s, najazdenych %d km\n",stroje[i].meno,stroje[i].tachometer);
    }
    return 0;
}
```

# Bublinkové triedenie

Prvý krok sme zvládli - traktory sú úspešne na poli. Stačí iba ich
presvedčiť nech sa zoradia podľa počtu najazdených kilometrov.

Milujeme bublinky. Každý má rád bublinky a tak na zotriedenie poľa
použijeme "bublinkové triedenie".

<div class="note">

Bublinky vo forme bublinkového plastového obalu môžeme použiť aj na
ukľudnenie nepokojnej nálady ich postupným praskaním.

</div>

Podstatou bublinkového triedenie je, že prvky poľa necháme "prebublávať"
na koniec až pokiaľ sme si istý, že sú zoradené od najmenšieho po
najväčší. Výsledkom prvého kola "prebublávania" bude to, že na konci
určite bude najväčší prvok. V ďalšom kole už nemusíme "prebublávať"
všetky prvky, ale môžeme vynechať ten na konci. Pokračujeme až
spracujeme celé pole. "Prebublávanie" je realizované výmenou dvoch
susediacich prvkov tak, aby ten väčší bol na pravo.

Jedno kolo prebublávania vyzerá takto:

``` c
for (int i=1; i < POCET_STROJOV; i++){
    // Ak je ma prvy stroj viac kilometrov
    if (stroje[i-1].tachometer > stroje[i].tachometer){
        // Vymenime ich tak, aby druhy stroj mal viac kilometrov
        traktor pomocny = stroje[i];
        stroje[i] = stroje[i-1];
        stroje[i-1] = pomocny;
    }
}
```

Na konci cyklu sme si istý, že na konci je stroj s najväčším počtom
kilometrov. Aby sme zotriedili celé pole, stačí postup opakovať, ale na
menšej oblasti poľa. Použijeme na to pomocnú premennú `j`, ktorá sa bude
postupne zväčšovať.

``` c
for (int j=0; j < POCET_STROJOV -1; j++){
    for (int i=1; i < POCET_STROJOV -j ; i++){
        // Ak je ma prvy stroj viac kilometrov
        // Vymenime ich tak, aby druhy stroj mal viac kilometrov
    }
}
```

Finálny produkt bude:

``` c
#include <stdio.h>
#define POCET_STROJOV

typedef struct traktor {
    char meno[10];
    int tachometer;
} traktor;

int main(){
    traktor stroje[POCET_STROJOV] = {
        {.meno:"Traktor",.tachometer:123},
        {.meno:"Retro Traktor",.tachometer:10000},
        {.meno:"Kombajn",.tachometer:3454}
    };
    for (int j=0; j < POCET_STROJOV -1; j++){
        for (int i=1; i < POCET_STROJOV -j ; i++){
            // Ak je ma prvy stroj viac kilometrov
            if (stroje[i-1].tachometer > stroje[i].tachometer){
                // Vymenime ich tak, aby druhy stroj mal viac kilometrov
                traktor pomocny = stroje[i];
                stroje[i] = stroje[i-1];
                stroje[i-1] = pomocny;
            }
        }
    }
    printf("V garazi mame:\n");
    for (int i = 0; i < POCET_STROJOV; i++) {
        printf("%s, najazdenych %d km\n",stroje[i].meno,stroje[i].tachometer);
    }
    return 0;
}
```

## Úloha na precvičenie

Vyskúšajte si program pre väčšie množstvo traktorov, ktorých parametre
si vymyslite.

Modifikujte program pre triedenie iného druhu tovaru na sklade.
