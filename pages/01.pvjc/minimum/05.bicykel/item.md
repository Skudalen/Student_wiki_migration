---
title: Bicyklová reťaz
---

! Naučíte sa:
!
! - Vytvoriť cyklický kód, ktorý sa opakuje dovtedy kým platí určitá
    podmienka.
! - Načítať reťazec a celé číslo s ošetrením.
! - Používať funkciu `fgets` na načítanie reťazc a `sscanf` na konverziu  reťazca na číslo.


Pomocou našich zázračných programátorských schopností sme boli schopní
vo veľmi krátkom čase navrhnúť a implementovať kalkulačku vhodnú aj pre
netechnické typy. Stále tam však zostávajú viaceré nedostatky. V
prípade, že zadáme nesprávny vstup, musíme celý proces začať od znova
lebo program sa pokazí.

# Cyklus while

V tejto kapitole upravíme kalkulačku tak, aby sa nevzdávala pri prvom
neúspechu, ale vytrvalo prosila o správny vstup až kým sa to nepodarí.
Na to využijeme cyklus typu **while**, ktorý bude prebiehať dovtedy,
pokiaľ je splnená podmienka:

``` c
while(1){
    printf("Ja neprestanem\n");
}
```

Podmienka `1` je splnená ak je vyhodnotená na nenulovú hodnotu. Číslo 1
bude v našich podmienkach nenulové vždy, takže takýto cyklus bude s
prebiehať do nekonečna (alebo až kým nevypnú elektrický prúd). Na koniec
ktorý nenastane nemusíme čakať, ale program vypneme pomocou klávesovej
skratky Ctrl+C.

Ak si to rozmeníme na drobné, program sa najprv spýta či je podmienka v
okrúhlej zátvorke splnená. Ak je, tak sa vykoná časť v zložených
zátvorkách a pokračuje novým cyklom, ktorý opäť zisťuje, či má
pokračovať.

Zápis cyklu typu **while** je veľmi podobný podmienke **if**, hlavný
rozdiel je v tom, že telo cyklu **while** môže byť vykonané viac krát
(pokiaľ platí podmienka).

# Načítanie hodnoty s ošetrením

Ak vieme napísať cyklus, môžme skúsiť vytvoriť taký kód, ktorý bude
žiadať o vstup dovtedy pokým nebude správny. Inými slovami, ak bude
vstup nesprávny tak sa bude požiadavka opakovať.

Na zastavenie cyklu vo vhodnom momente využijeme fakt, že môžme zmeniť
hodnotu premennej.

Aby nám cyklus prebehol aspoň raz, nastavíme počiatočnú hodnotu
premennej `pocet_hodnot` na nulovú hodnotu. Ak v priebehu vykonávania
tela cyklu zmeníme hodnotu premennej vhodným spôsobom, podmienka cyklu
nebude splnená a cyklus viac nebude prebiehať.

Zatiaľ na účel načítania poznáme funkciu `scanf`.

``` c
int pocet_hodnot = 0;
int a = 0;
while (pocet_hodnot != 1){
    printf("Prosím zadajte prvý argument\n");
    // Pri druhom volaní sa funkcia scanf nechova podla ocakavania
    pocet_hodnot = scanf("%d",&a);
}
printf("Načítal som hodnotu %d\n",a);
```

Vyskúšajte si tento kód. Čo sa stane, ak namiesto vstupu napíšete
písmeno? Ćo sa stane, ak súčasťou vstupu bude špeciálny znak pre koniec
vstupu (`EOF` - `Ctrl+D`). Skúste zistiť, prečo sa program v prípade
nesprávneho vstupu správa nečakane. Modifikujte tento program tak, aby v
prípade nesprávneho vstupu o tom vypísal správu a skončil porgram.

Zistili sme, že takto napísaný program síce funguje skvele, ale iba v
prípade že sa nevyskytnú “neočakávané” okolnosti (nesprávny vstup od
používateľa). Dôvodom je to, že funkcia `scanf` nie je veľmi užitočná.
Obsahuje vnútorný buffer (pomocné pole znakov), ktorý sa vyprázdni iba v
prípade, že vstup z klávesnice bol správny. V prípade, že bol vstup
nesprávny tak tam nesprávna hodnota ostane, až pokiaľ nebude spracovaná.
Ďalšie volania funkcie `scanf` potom namiesto vstupu od používateľa
stále pracujú s pôvodným, nesprávnym vstupom.

Vyplýva z toho, že funkcia `scanf` je použiteľná iba na veľmi jednoduché
príklady, ale nie je vhodná na reálne použitie. Našťastie, riešenie je
pomerne jednoduché - naprogramovať si vlastný “buffer” (miesto pre
dočasné uloženie údajov), do ktorého budeme ukladať vstup od
používateľa. Premenu vstupu z klávesnice na číslo budeme vykonávať
osobitne na vlastnom buffri.

# Pole a reťazec

Zmena nášho programu bude taká, že namiesto celého čísla, ktoré je možné
zapísať nesprávne budeme očakávať všeobecnejší typ **reťazec**. Do
reťazca si poznačíme všetko, čo používateľ zadal (ktoré klávesy
stlačil) a premenu na celé číslo vykonáme neskôr.

*Reťazec je sada znakov ukončená nulou*. Každý znak je v pamäti
reprezentovaný jedným kódom (číslom v rozsahu 0 až 255). Posledným
znakom je vždy nula ktorá vyznačuje koniec reťazca. Hodnoty znakov sú
zakódované do číselnej podoby pomocou ASCII tabuľky. Na uloženie reťazca
(viacerých nakov naraz) budeme potrebovať si zapamätať viac čísel naraz.

Klasické celočíselné premenné v jazyku C umožňujú uloženie iba jednej
hodnoty. Aby sme si mohli do premennej uložiť viac hodnôt, musíme o tom
prekladaču povedať. Napríklad ak chceme “rozšíriť” celočíselnú premennú
na viacero miest, môžeme napísať:

``` c
int pole[4];
```

Vyhradeniu viacerých pamäťových miest rovnakého typu vedľa seba vravíme
**pole**. Celé si to vieme predstaviť ako rebrík:

**Pole v pamäti.**

``` 
    int pole[4] = {4,3,2,1};


    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22
```

Rozdiel od klasického zápisu deklarácie premennej (príkazu na vyhradenie
pamäťového miesta) je použitie hranatých zátvoriek. Pomocou hranatých
zátvoriek v deklarácii premennej vravíme prekladaču, aby vyhradil viac
miest naraz. Pole si môžeme zostaviť z ľubovoľného dátového typu, napr.
`float`.

Na uloženie znaku je v jazyku C najvhodnejší typ `char` (znakový typ).
Jeden znak je v pamäti uložený vo forme ASCII kódu, teda celého čísla.
Typ `char` nie je veľmi odlišný od typu `int`, je ale menší. Do jednej
premennej typu `char` sa zmestí 256 rôznych hodnôt. Na uloženie znaku to
stačí a šetrí to pamäť.

Reťazec je pole znakov zakončené nulou, pamäť pre uchovanie desať
znakového reťazca si vyhradíme takto:

``` c
char retazec[11];
```

Posledné políčko poľa musíme vyhradiť pre zápis nuly na konci.

<div class="warning">

Vždy musíme počítať s tým, že do poľa sa musí zmestiť aj nula na konci.
Na uloženie `n` ASCII znakov nám treba minimálne `n+1` bajtov. Situácia
je ešte zložitejšia ak chceme do pamäte uložiť aj znaky s dĺžnom alebo
mäkčeňom. Jeden takýto znak môže zabrať dva alebo viac bajtov. Ak
nevieme, aké znaky v pamäti budú, je celkom ťažké presne povedať, koľko
pamäte budeme potrebovať. Nemalo by to byť viack ako trojnásobok
zamýšľaného počtu znakov.

</div>

Ak si chceme zapamätať ľubovoľný vstup od používateľa (menší ako *100*
ASCII znakov) a uložiť ho do poľa, môžeme zapísať:

``` c
char retazec[100];
printf("Zadajte hocijaký vstup:");
fgets(retazec,100,stdin);
printf("Napísali ste: %s\n");
```

Tento program počká na vstup z klávesnice a ak používateľ stlačí enter,
vypíše ho.

Prvým argumentom funkcie `fgets()` je názov poľa, kam sa má uložiť
výsledok. Druhým argumentom je veľkosť poľa, ktoré máme k dispozícii.
Tretím argumentom je súbor z ktorého sa má načítavať, v tomto prípade
načítavame z klávesnice ako keby to bol otvorený súbor.

<div class="note">

Premenná `stdin` je globálna premenná ktorá reprezentuje klávesnicu.
Funkciu `fgets` je možné použiť aj na načítanie zo súboru.

</div>

**Reťazec v pamäti. Posledná hodnota s indexom *3* môže byť
ľubovoľná..**

``` 
    char reazec[4] = "14";

    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  '1' |  '4' |   0   |   x   |
             +------+------+-------+-------+
    adresa:  \#10   \#11   \#12    \#13
```

Operácia načítania má neistý výsledok. Ak sa načítanie nepodarí (napr. v
súbore sa už nenachádza žiadny reťazec) tak program na túto skutočnosť
neupozorní a pokračuje ďalej, hoci je v cielovom poli `retazec` nejaká
predošlá hodnota. Vždy je potrebné si overiť návratovú hodnotu fukcie
pre načítanie aby sme vedeli čo robiť v prípade, že načítanie zlyhá.

Funkcia `fgets()` nás vie s pomocou špeciálnej návratovej hodnoty `NULL`
(nula) informovať o tom, že sa jej nepodarilo načítať nič. Ak je jej
návratová hodnota nulová tak sa načítanie reťazca nepodarilo.

``` c
char retazec[100];
printf("Zadajte hocijaký vstup:");
if (fgets(retazec,100,stdin) != NULL) { 
    printf("Napísali ste: %s\n");
}
else {
    printf("Nenapísali ste nič.\n");
}
```

  - Funkcia `fgets()` vraciu nulu ak sa nič nepodarilo načítať. Kvôli
    dátovým typom sa nula v tomto prípade zapisuje ako `NULL`, inak to
    je obyčajná nula.

Načítanie prázdneho riadka sa nepovažuje za chybu - aj prázdny riadok je
riadok a `fgets()` ho poslušne načíta do poľa. Chyba, teda nemožnosť
ďalšieho vstupu môžeme simulovať stlačením `Ctrl+D`, čo je špeciálny
znak pre koniec vstupu.

# Konverzia reťazca na číslo

Zistili sme, že v jazyku C sú reťazec a číslo dve rozdielne veci.
Zjednodušene môžme povedať, že reťazec je viac hodnôt vedľa seba, číslo
je iba jediná hodnota. Na to aby sme so zadaným reťazcom vedeli
vykonávať matematické operácie, musíme si ho premeniť na číslo. Tento
krok do teraz robila za nás funkcia `scanf`, ktorá premieňala vstup z
klávesnice vo forme reťazca bez toho, aby sme o nejakých reťazcoch
tušili. Zistili sme ale, že má určité obmedzenia, ktoré je potrebné
obísť.

Riešenie je našťastie jednoduché - konverziu na číslo je možné vykonávať
nie len z klávesnice, ale aj z hodnôt, ktoré sme si poznačili pred tým
do poľa. Slúži na to funkcia `sscanf`, ktorá sa správa rovnako ako
funkcia `scanf`, ale namiesto klávesnice pracuje s reťazcom, ktorý jej
zadáme ako argument. Netrpí teda problémom so zasekávajúcim sa buffrom.

Konverziu reťazca na číslo pomocou funkcie `sscanf` vykonávame takto:

``` c
int cislo = 0;
int pocet_hodnot = 0;
char retazec[10] = "14";
pocet_hodnot = sscanf(retazec,"%d",&cislo);
printf("Vase cislo je %d",);
```

**Celé číslo v pamäti.**

    int cislo = 14;
    
                 +------+
        hodnota: | 14   |
                 +------+
        adresa:  \#10   \#14

Už vieme správne vykonať konverziu reťazca na číslo, ale jeho načítanie
z klávesnice je stále problém, lebo funkcia `scanf` sa zasekáva.
Namiesto nej radšej použime funkciu `fgets`, ktorá slúži na čítanie
znakov zo súboru a netrpí "zasekávaním". Prvý argument tejto funkcie je
pole, do ktorého budeme načítavať. Druhým argumentom je maximálny počet
znakov ktorý budeme načítavať. Počet načítavaných znakov nesmie byť
väčší ako pole, do ktorého načítavame. Tretím argumentom je súbor, z
ktorého budeme načítavať. Návratová hodnota je počet znakov, ktorý sa
nám podarilo načítať.

Moment - načítanie zo súboru? Načítavame predsa z klávesnice. Toto nie
je omyl - štandardná knižnica jazyka C nerobí rozdiel medzi súborom,
sieťovou kartou alebo klávesnicou. Princíp načítavanie je pri všetkých
zariadeniach rovnaký - sadu hodnôt ukladáme do poľa. Na tento účel slúži
globálna premenná `stdin` o ktorú sa stará prekladač a ktorú vieme
použiť na čítanie.

# Celý program

Celý program bude potom vyzerať takto:

``` c
#include <stdio.h>

int spocitaj(int a,int b){
    return a + b;
}

void vypis_sucet(int a,int b){
    int vysledok = spocitaj(a,b);
    printf("Vysledok spocitania %d + %d je %d\n",a,b,vysledok);
}

int main(){
    printf("Súčtová kalkulačka\n");
    int pocet_hodnot = 0;
    int a = 0;
    char buffer[100];
    char* mam_riadok = NULL;
    while (pocet_hodnot == 0){
        printf("Prosím zadajte prvý argument\n");
        mam_riadok = fgets(buffer,100,stdin);
        if (mam_riadok == 0){
                return 0;
        }
        pocet_hodnot = sscanf(buffer,"%d",&a);
    }
    int b = 0;
    pocet_hodnot = 0;
    mam_riadok = NULL;
    while (pocet_hodnot == 0){
        printf("Prosím zadajte druhý argument\n");
        mam_riadok = fgets(buffer,100,stdin);
        if (mam_riadok == 0){
            return 0;
        }
        pocet_hodnot = sscanf(buffer,"%d",&b);
    }
    vypis_sucet(a,b);
    return 0;
}
```

Cyklus pre načítanie sa zopakuje vždy, keď používateľ zadá neplatnú
hodnotu a nepodarí sa konverzia reťazca na číslo. Ak nastane koniec
vstupu, program sa skončí.

# Úloha na precvičenie

Modifikujte program tak, aby vypísal chybové hlásenie o tom, že sa nebol
zadaný platný vstup.

Modifikujte program, tak aby napísal chybové hlásenie v prípade že
výpočet nebol vôbec vykonaný.
