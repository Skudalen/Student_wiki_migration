
! Naučíte sa:
! 
! - Používať funkciu `scanf` na načítanie do celočíselnej premennej.
! - Vytvárať časti kódu, ktoré sa vykonajú iba v prípade ak je splnená podmienka.
! - Overiť si výsledok načítania.
! - Zistíte, že niektoré výrazy sú pravdivé alebo nie podľa okolností.


V predošlom tutoráli sme sa naučili vytvoriť funkciu na spočítanie dvoch
čísel a na výpis výsledku. V tomto bloku sa naučíme, ako vytvoriť
interaktívny program, ktorý bude schopný požiadať používateľa o vstup,
načítať zadanú hodnotu do premennej a vypísať výsledok. Naučíme sa aj
bojovať s nezodpovednými používateľmi, ktorí testujú našu pozornosť a
trpezlivosť a zadávajú niečo iné ako očakávame. Výsledkom bude
kalkulačka, vhodná aj pre malé deti.

# Načítanie z klávesnice

Doteraz vytvorený program už je použiteľný ako jednoduchá kalkulačka,
ale iba pre nás programátorov. Tento postup naozaj nie je vhodný pre
každého. Bolo by fajn, keby s našou kalkulačkou vedela pracovať aj moja
babka.

Do teraz sme počiatočné hodnoty premenných určovali priamo v programe.
Na to aby sme zmenili čísla na spočítanie, musíme zmeniť náš program na
správnom mieste a zopakovať proces prekladu a spustenia. Slovo premenná
je od slova *meniť* a preto skúsime zmeniť náš program tak, aby sa
premenná vedela meniť počas behu. Požiadame používateľa o vstup krátkou
správou, v ktorej mu vysvetlíme, čo od neho chceme:

**Žiadosť o vstup.**

``` c
#include <stdio.h>

int main(){i
    printf("Súčtová kalkulačka\n");
    printf("Prosím zadajte prvý argument\n");
    return 0;
}
```

Vstup od používateľa sa v jazyku C dá získať rôznymi spôsobmi.
Najjednoduchším (a zároveň najhorším \[1\]) spôsobom je využitie funkcie
`scanf`. Zhodou okolností (ale nie náhodou) je použitie funkcie `scanf`
veľmi podobné použitiu funkcie `printf`. Ako prvý argument šablónu
reťazca ktorý očakávame a druhý argument je **adresa premennej**, kde
sa má uložiť výsledok. Adresu premennej získame pomocou operátora `&`
(ampersand).

**Vstup celočíselnej premennej.**

``` c
int vstup = 0;
scanf("%d",&vstup);
```

  - Druhý argument funkcie `scanf` očakáva adresu, preto musíme použiť
    operátor `&` na získanie adresy premennej

Takto si definujeme celočíselnú premennú `vstup`, do ktorej si uložíme
počiatočnú hodnotu nula. V druhom príkaze voláme funkciu `scanf`, ktorá
spôsobí to, že program čaká na celočíselný vstup od používateľa z
klávesnice a ak je to možné, tak výsledok uloží na zadanú adresu
premennej. Celý program s kalkulačkou môže vyzerať takto:

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
    printf("Prosím zadajte prvý argument\n");
    int a = 0;
    scanf("%d",&a);
    printf("Prosím zadajte druhý argument\n");
    int b = 0;
    scanf("%d",&b);
    vypis_sucet(a,b);
    return 0;
}
```

## Úloha na precvičenie

Preložte program, spustite ho a dajte vyskúšať Vašej babke alebo
sedemročnému dieťaťu. Za akých podmienok program funguje správne a kedy
nastáva zlyhanie?

# Ošetrenie vstupu

Po preskúšaní programu sme zistili, že program síce funguje správne, ale
iba v prípadoch keď zadaný vstup vyhovuje formátovacej značke `%d`, teda
celé číslo. Ak používateľ zadá niečo iné, výsledky nie sú podľa
očakávania. Program môže vyzerať, že funguje v poriadku, ale pracuje s
nesprávnymi hodnotami bez toho aby nás na to upozornil.

Jedným z možných riešení je používateľa upozorniť na možmé problémy a
poprosiť, aby zadával iba správne hodnoty:

``` c
printf("Súčtová kalkulačka celých číslek\n");
printf("Prosím zadajte prvý argument (ak nezadáte celé číslo, tak sa kalkulačka pokazí)\n");
int a;
scanf("%d",&a);
```

Kalkulačka by sa mala správať tak, ako to používateľ očakáva, inak
vznikne nespokojnosť na strane spotrebiteľa, môjho šéfa a v konečnom
dôsledku aj moja nespokojnosť. Ani by som nebol veľmi šťastný, keby som
si takúto kalkulačku kúpil. Pripomína mi to prístup niektorých úradov k
oprave ciest. Namiesto vyasfaltovania dier pribudne značka s chrbátom
dvojhrbej ťavy alebo s obrázkom uja s lopatou.

**Ťava podľa <http://ascii.co.uk/art/camel>.**

``` 
                 ,,_
                 (=-'
            /\/\  ))
          ~/    \/ |
          | )___(  |
          |/     \||
   ejm98  |'      |'
```

Skúsme urobiť kalkulačku odolnejšiu voči neočakávanému vstupu a overiť,
či načítanie prebehlo úspešne. Aby sme to vedeli urobiť, musíme si
bližšie prečítať dokumentáciu funkcie `scanf`. Zistíme, že návratová
hodnota funkcie `scanf` nie je až taká nezaujímavá ako v prípade funkcie
`printf`.

<div class="note">

Technickú dokumentáciu funkcie `scanf`. zobrazíme príkazom `man scanf`
alebo na [internete](http://www.cplusplus.com/reference/cstdio/scanf/).

</div>

Funkcia `scanf` vráti počet úspešne načítaných hodnôt, čo je v našom
prípade 1. Túto skutočnosť môžeme využiť na to aby sme našu kalkulačku
urobili odolnejšou voči neočakávanému vstupu. Ak používateľ nezadal
správny reťazec, môžeme ho na túto skutočnosť upozorniť. Zapamätáme si
návratovú hodnotu a môžeme ju vypísať:

``` c
int a = 0;
int pocet_hodnot = scanf("%d",&a);
printf("Pocet uspesne nacitanych hodnot je %d\n",pocet_hodnot);
printf("Nacitana hodnota je %d\n",a);
```

Vieme síce zistiť, či nastal nesprávny vstup, ale nevieme s tým nič
robiť. Aby sme vedeli ošetriť nesprávny vstup od používateľa, musíme
napísať kód, ktorý sa vykoná iba v prípade, že používateľ zadal
nesprávny vstup. Na to použijeme podmienku **if**.

## Úloha na precvičenie

Čo sa stane ak namiesto celého čísla zadám reťazec alebo číslo s
desatinnou čiarkou?

# Podmienka if

Jazyk C nám umožňuje napísať taký kód, ktorý sa spustí iba v prípade, že
je splnená určitá podmienka. Používame na to kľúčové slovíčko **if** za
ktorým do okrúhlych zátvoriek napíšeme podmienku. Nasledujúci príkaz
alebo blok príkazov sa vykoná iba v prípade, že je podmienka pravdivá.
Podmienka v zátvorke je pravdivá práve vtedy keď je nenulová. Tento kód
ilustruje vytvorenie bloku kódu pomocou podmienky **if**, ktorý sa
vykoná vždy:

``` c
if (2) {
    printf("Vykonam sa vzdy\n");
}
```

Ak je výraz v zátvorke nulový, podmienka sa nevykoná. Nasledovný blok
kódu v podmienke **if** sa nevykoná nikdy:

``` c
if (0) {
    printf("Nevykonam sa nikdy\n");
}
```

Namiesto hodnoty môžeme do zátvorky napísať výraz, ktorý sa vyhodnotí na
nulovú alebo nenulovú hodnotu:

``` c
if (1 == 2) {
    printf("Nevykonam sa lebo 1 sa nerovna 2\n");
}
```

Podmienka **if** môže byť nasledovaná blokom **else**, ktorý sa vykoná
iba v prípade, že podmienka nie je splnená:

``` c
if (1 == 2) {
    printf("Nevykonam sa lebo 1 sa nerovna 2\n");
}
else {
    printf("Vzdy viem ze 1 sa nerovna 2\n");
}
```

Operátor `==` znamená operáciu porovnania, ktorá ak je pravdivá tak
vracia nenulovú hodnotu a ak je nepravdivá, tak vracia nulu. Operácia
`!=` (nerovná sa) sa správa opačne ako operácia `==`, vráti *1* v
prípade, že dve hodnoty nie sú rovnaké a nulu v iných prípadoch.

# Operátor porovnania a operátor priradenia

Je rozdiel medzi operáciou `=` a `==`. Operácia priradenia `=` spôsobí
vloženie hodnoty do premennej a vrátu pravdivú hodnotu. Operácia
porovnania `==` vráti pravdivú hodnotu iba vtedy, ak je hodnota na ľavej
strane rovnaká ako na pravej strane.

Je ľahké si zameníť tieto dve operácie. Použitie priradenia namiesto
porovnania spôsobí, že neočakávané správnaie programu a kompilátor nás
na to nemusí upozorniť.

Operácia priradenia vždy vracia nenulovú hodnotu a ako vedľajší efekt
spôsobí kopírovanie do premennej na ľavej strane. Nasledovný kód sa
teda nebude správať podľa očakávania:

``` c
int pocet_hodnot = 0;
if (pocet_hodnot = 1){ 
    printf("Pocet nacitanych hodnot je 1\n",a);
}
else {
    printf("Nenacitala sa ziadna hodnota\n",a);
}
```

  - Výraz `pocet_hodnot = 1` vráti nenulovú hodnotu a jeho vedľajší
    efekt je priradenie hodnoty do premennej.

<div class="warning">

Pozor, v jazyku C je operátor porovnania `==` rozdielny ako operátor
priradenia `=`.

</div>

Blok kódu v podmienke sa vykoná vždy a prepíše sa hodnota premennej.
Takto napísaný kód je nesprávny. Oveľa lepšie je vždy v podmienke `if`
využívať operáciu porovnania:

``` c
if (pocet_hodnot == 1){
    printf("Hodnota pocet_hodnot je 1\n",a);
}
```

<div class="note">

Operácia porovnania funguje správne iba na celočíselné hodnoty. Hodnoty
s desatinnou čiarkou nemusi byť vnútorne reprezentované rovnako aje keď
rovnako vyzerajú. Operácia porovnania nefunguje ani na polia, reťazce a
iné zložitejšie dátové typy.

</div>

## Úlohy na precvičenie:

Vykoná sa nasledovný blok kódu?

``` c
if (-1) {
    printf("Je -1 pravdivy vyraz?\n");
}
```

Čo vypíše takéto volanie funkcie `printf`?

``` c
printf("Hodnota pravdiveho vyrazu je %d",1==1);
```

# Vstup s ošetrením

Už vieme napísať kód, ktorý sa vykoná iba ak je vstup od používateľa
nesprávny. Ak bude zadaná nejaká nesprávna hodnota, tak vieme napísať
upozornenie a prerušiť program ak je to potrebné.

Operátor porovnania môže využívať aj premenné, takže môžeme napísať:

``` c
#include <stdio.h>

int main(){
    printf("Súčtová kalkulačka\n");
    printf("Prosím zadajte prvý argument\n");
    int a = 0;
    // Nacita hodnotu pod pouzivatela do premennej a
    // a vrati pocet nacitanych hodnot do pocet_hodnot
    int pocet_hodnot = scanf("%d",&a);
    printf("Pocet uspesne nacitanych hodnot je %d\n",pocet_hodnot);
    if (pocet_hodnot != 1){
        printf("")
    }
    printf("Nacitana hodnota je %d\n",a);
    return 0;
}
```

V tomto príklade vieme vykonať nejaký blok príkazov iba v prípade, že
bola zadaná nesprávna hodnota. Celý príklad s ošetrením vstupu bude
trochu zložitejší:

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
    printf("Prosím zadajte prvý argument\n");
    int a = 0;
    int pocet_hodnot = 0;
    pocet_hodnot = scanf("%d",&a);
    if (pocet_hodnot == 1){
        printf("Prosím zadajte druhý argument\n");
        int b = 0;
        int pocet_hodnot = 0;
        pocet_hodnot = scanf("%d",&b);
        if (pocet_hodnot == 1){
            vypis_sucet(a,b);
        }
        else {
            printf("Zle ste zadali druhy argument. Cakal som cele cislo.\n");
        }
    }
    else {
        printf("Zle ste zadali prvy argument. Cakal som cele cislo.\n");
    }
    return 0;
}
```

Tento program má o niečo lepšie vlastnosti. Pomocou vetvenia **if-else**
sme dosiahli, že funkcia na sčítanie sa bude volať iba v prípade, že
obidve hodnoty boli zadané správne. Zabráni sa “pokazeniu” kalkulačky -
vylúčili sme situáciu, keď bude program fungovať, ale nesprávne. Vďaka
tomu si môžeme byť istý, že ak dostaneme výsledok tak bude správny.

# Úlohy na precvičenie

Upravte kalkulačku tak, aby vedela pracovať aj s číslami s desatinnou
čiarkou.

1.  vysvetlíme neskôr
