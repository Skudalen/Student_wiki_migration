# Matikár

Naučíte sa:

<div class="note">

  - Spracovávať reťazce.

  - Zistiť adresu vedľajšej pamäťovej bunky.

  - Zistiť, či adresa leží v zadanom poli.

  - Premeniť reťazce na reálne čísla.

</div>

# Matikár

Opäť sa na nás obrátili kolegovia so žiadosťou o pomoc - teraz z katedry matematiky. Sú zavalení prácou s množstvom písomiek z aritmetiky, ktoré musia opraviť a oznámkovať.

Jeden príklad sa nachádza na jednom riadku vo formáte:

    ČÍSLO OPERÁCIA ČÍSLO = VÝSLEDOK

Medzi čislami a operátormi sa môže nachádzať ľubovoľný počet medzier (aj nula).

Číslo je zadané na max. 2 desatinné miesta. Operácie sú sčítanie (`+`), odčítanie (`-`), súčin (`*`) a podiel (`/`).

Vytvorte program na kontrolu správnosti zapísaného výsledku. Výsledok je správny v prípade, že sa nelíši viac ako +/- 0.001 od skutočného výsledku.

  - V prípade, že je príklad správny, vypíšte `OK`.

  - V prípade, že príklad nie je správny, vypíšte `ZLE`.

  - V prípade, že je príklad zle zapísaný alebo delíme nulou, vypíšte
    `CHYBA`.

  - V prípade, že nájdete prázdny riadok, ukončite program a napíšte
    `KONIEC`.

# Naštudujte si

  - Načítanie riadku zo štandardného vstupu alebo zo súboru:
    [fgets](http://www.cplusplus.com/reference/cstdio/fgets/)

  - Premena reťazca na reálne číslo
    [strtof](http://www.cplusplus.com/reference/cstdlib/strtof/)

Pri štúdiu dokumentácie hľadajte odpovede na tieto otázky:

  - Čo robí táto funkcia?

  - Akého typu sú argumenty funkcie a čo znamenajú?

  - Akého typu je návratová hodnota a aký má význam?

  - Ako funkcia signalizuje, že neprebehla úspešne?

## Smerníková aritmetika

<div class="note">

  - Smerník je začiatok poľa.

  - Reťazec je pole znakov.

  - Reťazec je zakončený nulou.

  - Každé pamäťové miesto v poli má svoju adresu a leží blízko iného
    miesta v poli.

</div>

Adresa v pamäti je celé číslo. S celým číslom je možné vykonávať
operácie - sčítavanie, odčítavanie alebo porovnávanie.

Vďaka tomu ľahko vieme vypočítať adresu vedľajšieho miesta v pamäti.

Operácia sčítavania a odčítavania smerníkovej premennej berie do úvahy
veľkosť typu, na ktorý daná premenná odkazuje. Pripočítanie jednotky
nastaví smerník na vedľajšie miesto v poli.

``` c
int pole = {1,2,3,4};
int* zaciatok = pole;
int* adresa_druheho_prvku = zaciatok + 1;
int hodnota_druheho_prvku = *adresa_druheho_prvku;
int hodnota_stvrteho_prvku = adresa_druheho_prvku[2];

if (pole[0] == *pole){
    puts("Je to to isté\n");
}
```

## Operátor \[\] a \*

Operátor `*` (dereferencia, zistenie hodnoty) je to isté ako operátor
`[0]` (hodnota prvého prvku v poli).

``` c
int pole = {1,2,3,4};
if (pole[0] == *pole){
    puts("Je to to isté\n");
}
```

Aritmetické operácie so smerníkmi nám umožňujú sa pozrieť na vedľajšie
pamäťové miesta v poli. Fungujú podobne ako operátor `[]`.

Napríklad:

``` c
int pole = {1,2,3,4};
int* druhy_prvok = pole + 1;
printf("Druhy prvok je %d\n",*druhy_prvok);
printf("Treti prvok je %d\n",*(druhy_prvok + 1));
printf("Stvrty prvok je %d\n",druhy_prvok[2]);
```

## Smerník na smerník

Pomocou smerníkových premenných sme schopní uložiť výsledok do zadanej
vstupnej premennej. Pomocou funkcie s argumentom typu `int*` vieme
výsledok zapísať priamo do premennej typu `int`:

``` c
void zapis_do_premennej_int(int* vysledok){
    *vysledok = 2;
}
```

Takúto funkciu potom môžme volať, adresu zistíme pomocou operátora `&`:

    int premenna = 1;
    zapis_do_premennej(&premenna);

Výsledkom bude to, že v premennej typu int sa nachádza hodnota 2.

Podobným spôsobom môžme zapísať aj funkciu, ktorej výsledok nebude
priamo celé číslo, ale *adresa* celého čísla. Použijeme typ ktorý vieme
opísať ako "adresa smerníkovej premennej".

``` c
void posun_o_dva(int* zaciatok, int** druhy_prvok){
    *druhy_prvok = zaciatok + 2;
}
```

Táto funkcia zvýši hodnotu smerníka o dva. Voláme ju podobne:

``` c
int pole = {1,2,3};
int* zaciatok = pole;
int* treti_prvok= 0;
posun_o_dva(zaciatok,&treti_prvok);
```

To je to isté, ako keby sme zapísali:

``` c
int pole = {1,2,3};
int* zaciatok = pole;
int* treti_prvok = pole + 2;
```

Podobne voláme aj funkciu `strtof`. Pri každom volaní vieme okrem
konverzie reťazca na reálne číslo aj zistiť, kde sa číslo končí.

Funkcia `strtof(char* zaciatok, char** koniec)` má dva argumenty. Prvý
argument je začiatok reťazca z ktorého sa má vykonať konverzia. Do
druhého argumentu sa uloží adresa prvého znaku po rozpoznanom čísle
(adresu prvého znaku, čo nepatrí do čísla).

``` c
float value = 0;
char znaky[10] = "1.1";
char* koniec_znakov = 0;
value = strtof(znaky,&koniec_znakov);
if (value != 0){
// Konverzia sa nepodarila
}
```

To vieme využiť ak chceme premeniť viacero čísel oddelených medzerou.

``` c
float value = 0;
char znaky[13] = "1.1 2.2 3.3";
char* koniec_pola = znaky + strlen(znaky);
char* koniec_cisla = NULL;
char* zaciatok_cisla = znaky;
while (zaciatok_cisla < koniec_pola){
    value = strtof(zaciatok_cisla,&koniec_cisla);
    if (value == 0){
        break;
    }
    printf("Nasiel som cislo %f",value);
    zaciatok_cisla = koniec_cisla + 1;
}
```

## Porovnávanie dvoch reálnych čísel

Nie je reálne číslo ako reálne číslo. Vďaka spôsobu, akým sú
reprezentované reálne čísla sa výsledok nejakej operácie nemusí zhodovať
s tým čo očakávame: Ak napíšem:

    float a = 10;
    float b = 3;
    float c = a / b;

Je jasné, že výsledok sa určite nebude rovnať `3.333`. A rovnosť nemusí
platiť ani v prípade čísel s ukončeným desiatkovým zápisom, napr. `6.0
/ 2.0` nemusí byť úplne presne `3.0000000`.

Ak chceme overiť výsledok, musíme absolútnu hodnotu rozdielu
predpokladanej a skutočnej hodnoty porovnať s nejakou malou konštantou:

    float vysledok = 10.0 / 3.0;
    vysledok -= 3.3333333;
    if (vysledok < 0.000001 && vysledok > -0.000001){
        printf("Je to spravne\n");
    }

# Analýza riešenia

Najprv si vyskúšajte príklady uvedené vyššie.

Skúste riešenie rozdeliť na viaceré čiastkové úlohy.

Najprv sa sústreďte na načítanie všetkých riadkov zo štandardného
vstupu.

Keď sa Vám to podarí, skúste každý riadok spracovať, a povedať či
obsahuje správny matematický príklad alebo nie.

Na to, aby ste si to vedeli overiť, musíte sa postupne pokúsiť rozpoznať
všetky významové jednotky z reťazca - čísla a operátory. Pri správnom
zápise sa na riadku nachádzajú práve tri čísla oddelené medzerami a
operátormi.

Na to, aby ste vedeli rozpoznať číslo pomocou funkcie `strtof` musíte
vedieť adresu jeho začiatku. Ako vedľajší produkt sa pri úspešnom
rozpoznaní dozviete aj adresu konca zápisu reálneho čísla. Adresu konca
čísla môžete využiť pri hľadaní začiatku operátora a ďalšieho čísla ako
to je uvedené v príklade.

Aktuálne spracovávanú časť reťazca si môžete uložiť do smerníkovej
premennej a nastaviť ju najprv na začiatok.

    char* zaciatok = riadok;

Potom postupne aplikujte funkciu `strtof` na rozpoznanie reálneho čísla
a jeho konca. Ak si trúfate, môže vymyslieť aj vlastnú funkciu na
konverziu reťazca na reálne číslo.

Pri riešení možno využijete aj algoritmus, ktorý preskočí všetky medzery
a smerník nastaví na ďalší znak, ktorý nie je medzera:

    while(*zaciatok == ' '){
        zaciatok+= 1;
    }

Za číslom sa nachádza operátor, čo je jeden znak a overíme ho
jednoducho:

    if (*zaciatok == '+'){
    }

Smerník vieme nastaviť na ďalšiu pozíciu pomocou aritmetických operácií,
napr. pripočítanie jedna ho posunie na ďalší znak:

    zaciatok += 1;

## Používajte Valgrind

Pri operáciách s adresami pamäte je veľmi ľahké pracovať s pamäťou ktorá
nie je vyhradená alebo nie je inicializovaná. Váš program ani prekladač
Vás na tieto prípady neupozorní a môže sa správať nepredvídateľne.

Preložte Váš program s debugovacími informáciami (prepínač `-g`) a
spustite ho s pomocou programu Valgrind.

    gcc -g -std=c99 program.c -o program
    valgrind ./program

Valgrind Vás upozorní, ktorý riadok spôsobuje chybu prístupu do pamäte.

# Odovzdanie

Domácu úlohu odovzdávate pomocou systému GIT a Traktor, heslo pre úlohu
je `matikar`.

Riešenie píšte do repozitára `pvjc19cv6` do súboru `program.c`.
