# O týždeň

Naučíte sa:

<div class="note">

  - načítanie jedného riadka;

  - pracovať s časom a dátumom;

  - pracovať so smerníkmi.

</div>

Pri pracovných a školských úlohách je častý termín odovzdania o týždeň.
Vytvorte program, ktorý Vám pomôže odhadnúť dátum odovzdania Vášho
zadania.

Program načíta ľubovoľný dátum a k nemu vypočíta dátum o týždeň.

Pred tým ako začnete, uistite sa, že máte vytvorený repozitár
`pvjc19cv4` na našom git servri podľa [stručného
návodu](https://student.kemt.fei.tuke.sk/pvjc/materialy/git).

# Preštudujte si

Pri riešení môžte využiť [časť štandardnej
knižnice](http://www.cplusplus.com/reference/ctime/) pre prácu s časom
a dátumom. Budete potrebovať tieto dva dátové typy:

  - [Štruktúra pre reprezentáciu
    času](http://www.cplusplus.com/reference/ctime/tm/) `struct tm`.
    Aké členy má táto štruktúra? Ako si vytvorím novú premennú typu
    `struct tm`?

  - [Typ pre celočíslenú
    reprezentáciu](http://www.cplusplus.com/reference/ctime/time_t/)
    času `time_t`. Aký je rozdiel medzi celočíselnou a štruktúrovanou
    reoprezentáciou?

Je možné jeden typ zmeniť na druhý a ako? Pomôžu Vám tieto funkcie:

  - [strptime()](http://man7.org/linux/man-pages/man3/strptime.3.html)
    konverzia reťazca na štruktúrovanú reprezentáciu času (táto funkcia
    je neštandardná, ale je najjednoduchšia);

  - [mktime()](http://www.cplusplus.com/reference/ctime/mktime)
    konverzia štruktúrovanej reprezentácie na celočíslenú;

  - [localtime()](http://www.cplusplus.com/reference/ctime/localtime)
    konverzia celočíselnej repreezntácie času na štruktúrovanú:

  - [strftime()](http://www.cplusplus.com/reference/ctime/strftime)
    konverzia štruktúrovanej reporezentácie času do reťazca.

Pri štúdiu technickej dokumentácie sa sústreďte na:

  - Predpis funkcie vám prezradí aké argumenty funkcia očakáva a aký je
    typ návratovej hodnoty.

  - Stručný opis činnosti hovorí čo funkcia robí.

  - Spôsob ako funkcia hlási chybu (väčšinou pomocou špeciálnej
    návratovej hodnoty). Konverzia alebo načítanie sa nemusí podariť a
    musíte definovať čo sa má robiť v tom prípade.

# Zopakujte si

Pri štúdiu týchto funkcií a dátových typov môžte vidieť, že sa často
pracuje s adresou premennej namiesto jej hodnoty. Na uloženie adresy je
dobré používať tzv. smerníkovú premennú, ktorú vyznačíte pomocou `*` pri
vyhradení pamäte.

``` c
struct tm* adresa_tm;
```

je premenná pre uloženie smerníka na premennú kde je uložená hodnota
typu `struct tm`.

Adresu premennej zistíte pomocou operátora `*`.

Takto si pomocou operátora `&` poznačíte adresu premennej typu `int`:

``` c
int moja_premenna = 1;
int* adresa_mojej_premennej_int = &moja_premenna;
```

Obsah pamäte s danou adresou zistíte pomocou operátora `*`.

``` c
int moja_premenna = 1;
int* adresa_mojej_premennej_int = &moja_premenna;
int hodnota_mojej_premennej = *adresa_mojej_premennej_int;
```

K jednotlivým členom štruktúry pristupujete pomocou operátora `.` alebo
`→` v prípade smerníkovej premennej.

Budete potrebovať aj tieto funkcie:

  - [fgets()](http://www.cplusplus.com/reference/cstdio/fgets/) na
    načítanie reťazca;

  - [puts()](http://www.cplusplus.com/reference/cstdio/puts/) na výpis
    reťazca:

  - [memset()](http://www.cplusplus.com/reference/cstring/memset/) na
    inicializáciu pamäte;

Príkaz na načítanie jedného riadka do 100 znakov môže vyzerať takto:

``` c
char riadok[100];
memset(riadok,0,100);
int r = fgets(riadok,100,stdin);
if (r){
    puts("Nacitanie sa podarilo");
}
```

# Návrh riešenia

Riešenie je možné vyjadriť pomocou postupu:

1.  Najprv načítajte jeden riadok ľubovoľného textu.

2.  Skúste text premeniť do štruktúrovanej reprezentácie.

3.  Ak sa konverzia nepodarila, vypíšte chybové hlásenie.

4.  Ak bola konverzia úspešná, skúste čas premeniť do celočíslelnej
    reprezentácie.

5.  V celočíslelnej reprezentácii vypočítajte čas o týždeň.

6.  Celočíselnú reprezentáciu premeňte do štruktúrovanej a vypíšte
    výsledok.

# Domáca úloha

  - heslo na vyhodnotenie úlohy je `otyzden`.

  - odovzdávanie pomocou GITu do súboru s názvom `program.c` do
    repozitára s názvom `pvjc19cv4`

  - Dokončite cvičenie (3b)
