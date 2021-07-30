---
title: Zemiaky v poli
---

! Naučíte sa:
!
! - statická alokácia poľa
! - odovzdávanie pola ako argument hodnotu a smerníkom
! - základy práce s poľom - prechádzanie poľa,
! - rozdiel medzi poľom a reťazcom
! - naučiť sa základy smerníkovej aritmetiky

</div>

# Polia a smerníky

Pole je súvislá oblasť v pamäti do ktorej si môžeme uložiť viac hodnôt
vedľa seba. Pole je vždy odvodené od iného dátového typu podľa toho, čo
si chceme do neho uložiť. Môžeme ho použiť na uloženie skupiny hodnôt
rovnakého typu ktoré patria z nejakého dôvodu k sebe, napr. si môžeme
poznačiť, koľko kilometrov sme najazdili na našej novej motorke počas
dovolenky:

``` c
int kilometre[5] = {1,2,2,1,4};
```

Vytvorením tohto poľa sme zároveň vytvorili odvodený dátový typ - pätica
celočíselných hodnôt. Tento dátový typ môžeme použiť pri návrhu funkcie,
ktorá by pracovala s takýmto poľom:

``` c
void vypis_kilometre(int kilometre[5]){
    for (int i = 0; i < 5; i++ ){
        printf("%d ",kilometre[i]);
    }
}
```

<div class="tip">

<div class="title">

Zamyslite sa

</div>

Čo sa stane, ak funkciu zavolám s poľom inej veľkosti - 4 alebo 6 ? Môže
existovať pole s nulovou veľkosťou?

</div>

# Adresa začiatku poľa

Pri takto navrhnutej funkcii dochádza ku kopírovaniu všetkých hodnôt v
poli, čo je nepraktické v prípade, že pole obsahuje veľa hodnôt.
Spracovanie celého 200 megabajtového videa by zabralo viac času a
minimálne dva krát viac pamäte. Keby sme v tejto funkcii pole
modifikovali, zmena sa zabudne keď funkcia skončí. Ďalšou nevýhodou
bude, že táto funkcia pracuje iba s poľom fixnej veľkosti 5.

Na to aby sme obišli tieto obmedzenia, využijeme zlaté pravidlo jazyka
C:

    Názov poľa je adresa jeho začiatku.

Adresa začiatku poľa celočíselných hodnôt má typ `int*`. Môžeme teda
napísať:

``` c
int* zaciatok_pola = kilometre;
```

Navrhneme funkciu, ktorá pole odovzdá pomocou adresy jeho začiatku. Z
adresy začiatku poľa nie je možné určiť jeho veľkosť, tú si musíme
pamätať osobitne:

``` c
void vypis_kilometre(int* kilometre, int velkost){
    for (int i = 0; i < velkost; i++ ){
        printf("%d ",kilometre[i]);
    }
}
```

Takúto funkciu zavoláme:

``` c
int kilometre[5] = {1,2,2,1,4};
vypis_kilometre(kilometre,5);
```

# Reťazec

Dátový typ pole môžeme použiť aj na uloženie nejakej správy, stačí ho
odvodiť od dátového typu `char`. Pole znakov môžeme vypisovať pomocou
formátovacej značky `%s`. Veľkosť poľa za nás odvodí prekladač.

Druhý argument funkcie `printf` je smerník na začiatok poľa so znakmi. V
klasickom poli znakov nie je možné povedať, kde sa pole znakov končí.
Existuje ale dohoda, že posledná hodnota v reťazci nula. Pole znakov s
nulou na konci nazývame reťazec.

Vďaka tomu môžme odovzdať reťazec ako argument bez toho aby sme
odovzdali aj jeho veľkosť. Tá sa dá ľahko zistiť podľa poslednej nuly.
Pozor, ak na nulu na konci reťazca zabudneme tak sa program bude správať
nepredvídateľne.

``` c
char meno_motorky[] = {'J','a','w','a',' ','3','5','0', 0};
printf("%s",meno_motorky);
```

INFO: Je rozdiel medzi nulovou hodnotou 0 a hodnotou znaku '0' v ASCII
tabuľke.

Našťastie, reťazec sa dá zapísať aj jednoduchšie. Reťazcový zápis vyzerá
o veľa krajšie a nemusíme písať toľko čiarok a apostrofov. O veľkosť
poľa a o nulu na konci sa postará prekladač.

To isté aj s nulou na konci poľa zapíšeme pomocou úvodzoviek takto:

``` c
char meno_motorky[] = "Jawa 350";
```

Keďže vieme určiť, kde je koniec reťazca, vieme si napísať aj vlastnú
verziu funkcie `printf()`, ktorá vypisuje reťazce. Reťazec odovzdáme
adresou jeho začiatku a budeme schopní vypísať ľubovoľne veľký reťazec.
Koniec reťazca zistíme podľa nuly na konci a preto nemusíme odovzdávať
veľkosť reťazca ako argument.

``` c
void vypis_meno(const char* meno){
    for (int i = 0; meno[i] != 0; i++){
        putchar(meno[i]);
    }
}
```

INFO: kľúčové slovíčko `const` v tomto prípade naznačuje, že funkcia
pracuje s reťazcom a nie s poľom znakov.

## Adresa v pamäti je celé číslo

Hodnoty adresy v pamäti môžeme vypisovať. Overme si, že pole je naozaj
množina hodnôt, ktoré sa nachádzajú vedľa seba:

    int kilometre[5] = {5,6,7,8,9};
    for (int i = 0; i < 5; i++){
        printf("%p ",&kilometre[i])
    }

Pomocou formátovacej značky `%p` vypisujeme hodnotu adresy v
hexadecimálnom tvare. Zistili sme, že jednotlivé bunky poľa sú v pamäti
od seba vzdialené v pravidelných intervaloch. Veľkosť jednej bunky je
rovná veľkosti dátového typu `int`. Veľkosť dátového typu si vieme
overiť pomocou operátora `sizeof`.

``` c
int kilometre[5] = {5,6,7,8,9};
int* zaciatok_pola = kilometre;
int velkost_int = sizeof(int);
```

Aká je veľkosť premennej typu `int*`?. Koľko rôznych hodnôt pomocou nej
môžeme reprezentovať ? Odpoveď na túto otázky hovorí o tom, s koľkými
pamäťovými bunkami môžeme počítať v našom programe.

Operátor `*` (dereferencia, zistenie hodnoty) je to isté ako operátor
`[0]` (hodnota prvého prvku v poli).

``` c
int pole = {1,2,3,4};
if (pole[0] == *pole){
    puts("Je to to isté\n");
}
```

V slučke typu `for` sme si v prvom kroku vytvorili pomocnú premennú
`miesto_v_poli`, ktorá najprv ukazuje na začiatok poľa. Postupne ju
zvyšujeme o jedna tak, aby ukazovala na jednotlivé bunky poľa až
dovtedy, pokiaľ neukazuje za vyhradenú oblasť.

# Smerníková aritmetika

Pomocou smerníkovej premennej si vieme poznačiť konkrétne miesto v
pamäti. S hodnotou smerníkovej premennej vieme robiť podobné operácie
ako s klasickou hodnotou - kopírovať, odovzdávať ako argument a dokonca
aj pripočítať nejakú hodnotu.

Aritmetické operácie so smerníkmi nám umožňujú sa pozrieť na vedľajšie
pamäťové miesta v poli. Fungujú podobne ako operátor `[]`. Inak
povedané, výraz `*(pole + 2)` je to isté ako `pole[2]` alebo `pole + 3`
je to isté ako `&pole[3]`. Adresa v pamäti je celé číslo. S celým číslom
je možné vykonávať operácie - sčítavanie, odčítavanie alebo
porovnávanie.

Vďaka tomu ľahko vieme vypočítať adresu vedľajšieho miesta v pamäti.

Napríklad:

``` c
int pole = {1,2,3,4};
int* druhy_prvok = pole + 1;
printf("Druhy prvok je %d\n",*druhy_prvok);
printf("Treti prvok je %d\n",*(druhy_prvok + 1));
printf("Stvrty prvok je %d\n",druhy_prvok[2]);
```

Smerníková aritmetika nám umožňuje sa pozrieť do vedľajších pamäťových
buniek. Kompilátor nám uľahčuje prácu tým, že automaticky berie do úvahy
veľkosť dátového typu. Skúsme sa pozrieť do pamäťovej bunky, ktorá leží
dva políčka napravo od začiatku poľa kilometre.

``` c
int kilometre[5] = {5,6,7,8,9};
int* zaciatok_pola = kilometre;
int* adresa_dve_bunky_od_zaciatku = zaciatok_pola + 2;
printf("Na druhom mieste v poli sa nachadza hodnta %d",*adresa_dve_bunky_od_zaciatku);
printf("Hodnota zaciatku je %p a hodnota tretej bunky je %p",zaciatok_pola,adresa_dve_bunky_od_zaciatku);
```

Mágia nastala pri výsledku operácie `zaciatok_pola + 2`. Výsledná adresa
nie je oproti očakávaniu o 2 bajty väčšia, ale až o 8. Nedá sa to ale
overiť klasickým spôsobom:

``` c
int rozdiel = adresa_dve_bunky_od_zaciatku - zaciatok_pola;
printf("Rozdiel medzi smerníkmi je %d",rozdiel);
```

Rozdiel medzi bunkami bude vypočítaný v počte buniek poľa a nie v
bajtoch.

Operácia sčítavania a odčítavania smerníkovej premennej berie do úvahy
veľkosť typu, na ktorý daná premenná odkazuje. Pripočítanie jednotky
nastaví smerník na vedľajšie miesto v poli.

``` c
int pole = {1,2,3,4};
int* zaciatok = pole;
int* adresa_druheho_prvku = zaciatok + 1;
int hodnota_druheho_prvku = *adresa_druheho_prvku;
int hodnota_stvrteho_prvku = adresa_druheho_prvku[2];
```

Pomocu smerníkovej aritmetiky vieme ľahko zistiť veľkosť reťazca pomocou
vyhľadávania nulového znaku. Na začiatku si poznačíme adresu začiatku do
premennej `retazec`. Výraz `*retazec` vráti hodnotu uloženú na danom
mieste v poli. Výraz `retazec++` posunie aktuálnu adresu o jedno
pamäťové miesto ďalej. Podmienka zastaví cyklus v prípade, že nájdeme
nulový znak. Na konci bude v premennej `retazec` adresa posledného prvku
poľa. Ak vieme adresu začiatku poľa (poremenná `zaciatok_retazca`) a
adresu konca poľa, tak veľkosť reťazca je ich rozdiel.

``` c
int dlzka_retazca(const char* zaciatok_retazca){
    char* retazec = zaciatok_retazca;
    while(*retazec != 0){
        retazec++;
    }
    return retazec - zaciatok_retazca;
}
```

## Smerník na smerník

Vieme si vytvoriť aj funkciu, ktorá bude vykonávať smerníkovú
aritmetiku.

Pomocou smerníkových premenných sme schopní uložiť výsledok do zadanej
vstupnej premennej. Pomocou funkcie s argumentom typu `int*` vieme
výsledok zapísať priamo do premennej typu `int`:

``` c
void zapis_do_premennej_int(int* vysledok){
    *vysledok = 2;
}
```

Takúto funkciu potom môžme volať, adresu zistíme pomocou operátora `&`:

``` c
int premenna = 1;
zapis_do_premennej(&premenna);
```

Výsledkom bude to, že v premennej typu int sa nachádza hodnota 2.

Podobným spôsobom môžme zapísať aj funkciu, ktorej výsledok nebude
priamo celé číslo, ale **adresa** celého čísla. Použijeme typ ktorý
vieme opísať ako "adresa smerníkovej premennej". Do predpisu funkcie
zapíšeme smerníkovú premenú typu smerníková premenná. Adresa
smerníkovej premennej typu `int*` má zápis `**int`.

Takáto funkcia vypočíta adresu o dve pamäťové miesta ďalej a výslednú
adresu zapíše do smerníkovej premennej.

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

## Cvičenie

Zistite, čo sa stane v prípade, ak pomocou smerníka prečítame alebo
zmeníme hodnotu, ktorá je mimo poľa s ktorým pracujeme?

O koľko bajtov sa posunie smerník v poli znakov ak ho inkrementujeme
(zvýšime mu hodnotu o jedna)?

# Premena reťazca na celé číslo

Ak vieme ako fungujú smerníky tak vieme aj navrhnúť vlastnú funkciu
ktorá sa pokúsi premeniť reťazec cifier na celé číslo.

Funkcia vezme reťazec, pokúsi sa ho premeniť na celé číslo a ak uspeje
vráti nulovú hodotu a zapíše výsledok do zadanej premennej.

Pri výpočte využijeme algoritmus zvaný Hornerova schéma.

``` c
int str_to_int(const char* cifry, int* vysledok,char** koniec){
    // Aktuálna hodnota výpočtu
    int sucet = 0;
    // Adresa aktuálneho znaku nastavíme na prvý znak
    char* znak = cifry;
    // Zistíme, či je ASCII hodnota znaku medzi ciframi
    while (*znak >= '0' && *znak <= '9'){
        // Hornerova schéma
        // Vypočíta celkovú hodnotu čísla
        // ako výpočet polynómu
        sucet = sucet * 10;
        sucet +=  znak - '0';
        // posunieme aktuálny znak o jedno miesti
        znak += 1;
    }
    // Ak sa podarilo načítať aspoň jednu cifru
    if ( znak > cifry){
        // Zapíšeme výsledok do smerníkových premenných
        *vysledok = sucet;
        // Zapíšeme aj adresu prvého znaku čo nie je číslo
        *koniec = znak;
        // Funkcia hlási úspech
        return 0;
    }
    // Inak funkcia hlási neúspech.
    return 1;
}
```

Túto funkciu na premenu reťazcov na celé čísla vieme využiť napríklad na
výpočet súčtu čísel oddelených čiarkou:

    char cisla[] = "5,6,7,8";

Funkcia nám vždy hlási úspech, výsledok aj adresu najbližšej čiarky.
Musíme len zabrániť opakovaniu v prípade, že namiesto čiarky nájdeme
koniec reťazca:

``` c
#include <stdio.h>
int main(int argc, char** argv){
    if (argc < 2){
        printf("zadaj argument\n");
        return 0;
    }
    char* retazec = argv[1];
    int sucet = 0;
    while (*retazec != 0){
        int r = str_to_int(retazec,&sucet,&retazec);
        if (r) {
            printf("Neplatny retazec\n");
            return 1;
        }
        if (*retazec == 0){
            break;
        }
        retazec += 1;
    }
    printf("Vysledok suctu je: %d\n",sucet);
    return 0;
}
```

Tomuto programu stačí zadať zoznam čísel oddelených čiarkou ako prvý
argument príkazového riadku.

    ./program 3,4,5,6
    Vysledok suctu je: 18
