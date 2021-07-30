# Anketa Študent roka

<div class="tip">

<div class="title">

Naučíte sa

</div>

  - Pracovať poľom štruktúr.

  - Pracovať s operátorom `→`.

  - Dynamicky pretypovať hodnotu: pracovať s operátorom `()`.

  - Vytvoriť porovnávaciu funkciu.

  - Triediť pomocou funkcie `qsort`.

</div>

Časopis Emmma vypísal každoročnú anketu v ktorej čitatelia určia "Emmma
Študent roka 2018". Do súťaže sa môže prihlásiť ktokoľvek\! Našou
úlohou bude pomôcť pri sčítavaní hlasov.

Navrhneme jednoduchú databázu mien, v ktorej budeme ku každému menu
evidovať počet hlasov, ktoré študent dostal od čitateľov časopisu Emmma.
Databáza bude tvorená poľom štruktúr konštantnej veľkosti, ktoré si
vyhradíme na začiatku. Prázdna položka databázy bude mať nulovú alebo
zápornú početnosť alebo meno bude prázdny reťazec. Na začiatku bude
databáza naplnená iba prázdnymi položkami.

Zo sčítacích komisiíí budú na štandardný vstup postupne chodiť výsledky
vo formáte meno a počet hlasov, napr:

    Ivan Hrozný
    200
    Peter Veľký
    11
    Ivan Hrozný
    17

Postupne načítavame mená a početnosti zo štandardného vstupu. Načítanie
ukončíme načítaním neplatnej položky.

Ak sa meno človeka v databáze nenachádza, vložíme ho do prvého voľného
miesta v databáze. Ak sa meno človeka v databáze nachádza, zväčšíme jeho
počet hlasov. V prípade, že v databáze nie je dosť miesta tak vypíšte
chybové hlásenie a ukončite načítanie. Po konci načítania zotrieďte
databázu podľa počtu získaných hlasov a zobrazte jej obsah.

Pre celý program vytvorte používateľské rozhranie tak, aby bolo príjemné
aj pre iných členov poroty ktorí nie sú až takí zruční v programovaní
ako Vy.

# Naštudujte si

Využijete tieto časti štandardnej knižnice:

  - [fgets()](http://www.cplusplus.com/reference/cstdio/fgets/) -
    Načítanie jedného riadka

  - [qsort()](http://www.cplusplus.com/reference/cstdlib/qsort/) -
    triedenie

  - [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/) -
    lexikografické porovnanie dvoch reťazcov

  - [memcpy()](http://www.cplusplus.com/reference/cstring/memcpy/) -
    kopírovanie ľubovoľného poľa alebo reťazca

Argumenty príkazového riadka nájdete v poli reťazcov `argv`, počet
argumentov je v premennej `argc`:

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

# Analýza riešenia

Tento program je trochu zložitejší. To ale nebude problém, lebo sa bude
skladať z viacerých jednoduchších častí. Každá časť bude riešiť
čiastkový problém. Vďaka tomu sa "veľký" problém zmení na množinu
"malých" a jednoduchšie riešiteľných problémov. Časť návrhu máte
vytvorenú dopredu vo forme hlavičkového súboru s dátovými typmi a
predpismi funkcií ktoré implementujete.

Aplikácia je rozdelená do dvoch modulov - jeden bude riešiť prácu s
dátami a druhý sa bude starať o komunikáciu s používateľom.

V prvom module `anketa.c` sa budeme sústrediť na "logiku" nášej
aplikácie. Každá funkcia sa bude riešiť a testovať osobitne.

V module sú najprv definované dátové typy a konštanty s ktorými budeme
pracovať. Potom si definujeme funkcie ktoré budú pracovať s navrhnutými
dátovými typmi:

  - spočítanie platných položiek.

  - vyhľadanie konkrétnej položky.

  - porovnanie dvoch položiek podľa početnosti.

  - zotriedenie celej databázy podľa početnosti.

  - načítanie databázy zo súboru.

  - výpis výsledku na obrazovku.

Množina týchto funkcií tvorí takmer kompletný program, pre ktorý stačí
vytvoriť jednoduché textové používateľské rozhranie. Na rozhranie sa
môžte sústrediť v module `main.c`. Vo vhodnom poradí volajte funkcie z
prvého modulu a vypisujte správy na obrazovku tak aby práca s programom
bola ľahko pochopiteľná pre človeka ktorý sa s ním stretol po prvý raz.

Používateľské rozhranie by malo byť založené na argumentoch príkazového
riadka. Na začiatku načítajte súbor (názov zadajte ako prvý argument),
spracujte ho a podľa ostatných argumentov vykonajte niektorú akciu.
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

## Platné a neplatné položky v databáze

Databáza záznamov bude ukončená prvou neplatnou položkou. Určovanie
počtu položiek je preto ekvivalentné zisťovaniu polohy prvej neplatnej
položky. Pri overovaní neplatnosti overte:

  - či je počet odovzdaných hlasov väčší ako nula

  - či je meno prázdny reťazec.

Pri zisťovaní, či je reťazec prázdny, môžte využiť funkciu `strlen`
alebo `strcmp`. Najjednoduchšie bude zistiť, či je prvý znak v poli
nulový (ak je nulový, tak je reťazec prázdny), lebo posledmný znak v
reťazci je nula

    students[i].name[0] == 0

Overovanie platnosti využijete na viacerých miestach - pri počítaní aj
pri vyhľadávaní. Je výhodné si ho dať do osobitnej funkcie, napr.

    int is_valid(struct strudent* item){
        return 0;
    }

## Triedenie

Na zotriedenie databázy použite štandardnú funkciu qsort. Na správne
zotriedenie je potrebné definovať funkciu na porovnanie dvoch hodnôt,
ktoré dostanete adresu. Názov tejto funkcie uveďte ako posledný argument
do funkcie `qsort`.

``` c
int commpare(const void* s1, const void* s2){
    return 0;
}
```

Pre správne porovnanie dvoch záznamov v databáze najprv zmeňte typ
(`const void*`| na (`struct student*`). Potom s pomocou operátora `→`
získate počet hlasov, ktorý môžte porovnať.

# Odovzdanie

Skúste program vytvoriť tak, aby sa dal použiť pre prácu v naozajstnej
porote\!

Časť s používateľským rozhraním (`main.c`) nebude striktne testovaná ale
buďte pripravení na to že Vaše zadanie niekto (Váš cvičiaci alebo
prednášajúci) skontroluje osobne.

  - dokončite cvičenie tak aby prešli automatické testy (5b).

  - buďte pripravení predviesť Váš program a zodpovedať zvedavé otázky
    pri osobnej obhajobe (5b), termín bude oznámený.

Tento druh automatických testov bude overovať funkcie v súbore
`anketa.c`. Automat bude generovať rôzne polia a ich adresu pošle na
vstup Vašej funkcie. Funkcia má podľa dokumentácie vykonať niečo s
pamäťou (porovnať, spočítať alebo modifikovať). Automat potom overí
výsledok. Práca so súbormi a štandardným vstupom sa bude hodnotiť
neskôr.

Pri práci so smerníkmi je veľmi ľahké pracovať s pamäťou, ktorá nie je
správne inicializovaná alebo je mimo vyhradenej oblasti. Pri ladení
určite využite program `valgrind` ktorý Vás upozorní na prípadné chyby.

Zadanie odovzdávate pomocou systému GIT do repozitára `pvjc19cv5`.
Automaticky sa budú hodnotiť funkcie, ktoré máte v súbore `anketa.c`.
Hodnotenie je pomocou systému Traktor, heslo je `anketa`.

Najprv si stiahnite a rozbaľte [šablónu zadania](pvjc19cv5.zip):

    curl -O https://student.kemt.fei.tuke.sk/pvjc/cvicenia/05.vysledky/pvjc19cv5.zip
    unzip pvjc19cv5.zip

Vytvorte si vzdialený GIT repozitár s názvom `pvjc19cv5`.

Rozbalením Vám vznikne adresár s počiatočnými súbormi zadania. Prepnite
sa do adresára a prepojte ho s Vašim vzdialeným GIT repozitárom podľa
inštrukcií.
