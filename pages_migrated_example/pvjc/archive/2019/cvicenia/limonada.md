# Limonádový pohár

<div class="tip">

<div class="title">

Zopakujete si

</div>

  - Formátovaný vstup celého čísla.

  - Algoritmus hľadania maximálneho čísla v poli.

  - Cykly, podmienky a premenné.

  - Čo je to konštanta.

  - Na čo je hlavičkový súbor.

</div>

# Kto vypil najviac limonády?

Na Technickej univerzite sa koná súťaž v druhom najobľúbenejšom
slovenskom športe - pijatike citrónovej limonády zvanej aj citronáda.
Súťažiaci dostali štartovacie čísla od jednotky až po počet
súťažiacich. Počas troch minút majú za úlohu vypiť čo najviac
dvojdecových pohárov kvalitnej citronády z produkcie študentského bufetu
"Libresso" v budove univerzitnej knižnice.

Ako člen technickej poroty budete mať na starosti spracovanie výsledkov.
Na štandardný vstup nového informačného systému sa bude postupne
zapisovať počet počet vypitých pohárov pre každého súťažiaceho podľa
jeho štartovacieho čísla. Koniec zápisu výsledkov sa vyznačí vložením
neplatného čísla (inej ako kladnej celej hodnoty) alebo koncom vstupu
(`CTRL+D`).

Vašou úlohou bude vytvoriť program, ktorý načíta do poľa počty vypitých
pohárov a vypíše čísla všetkých súťažiacich, ktorí vypili maximálny
počet pohárov.

![Lemonade from Wikipedia](Fentimans_Range.png)

# Príprava

Na riešenie budeme potrebovať fukcie na formátovaný vstup a výstup.
Naštudujte si technickú dokumentáciu funkcií štandardnej knižnice,
ktoré sú v tomto prípade najjednoduchšie použiteľné:

  - [scanf()](http://www.cplusplus.com/reference/cstdio/scanf/)

  - [printf()](http://www.cplusplus.com/reference/cstdio/printf/)

## Načítanie premennej

Pri štúdiu fukcie `scanf` zistíme, že jej úloha je načítavať dáta na
určitú adresu v pamäti. Každá premenná má svoju adresu v pamäti a tú
zistíte pomocou operátora `&`:

``` c
int value = 0;
scanf("%d",&value);
```

Ten istý operátor môžete použiť aj s poľom a načítavať priamo do poľa.
Značka `%d` znamená, že očakávame celé číslo.

``` c
int pole[]  = {1,2,3,4} ;
scanf("%d",&pole[0]);
```

<div class="note">

<div class="title">

Nezabudnite

</div>

Na to, aby ste vedeli použiť akúkoľvek funkciu, musíte s pomocou
direktívy preprocesora `#include` do zdrojového kódu zapísať v ktorom
hlavičkovom súbore sa nachádza jej definícia. Názov hlavičkového súboru
zistíte z dokumentácie.

</div>

Operácia načítania má vždy neistý výsledok. Po načítaní je potrebné si
overiť, či prebehlo úspešne. Pri funkcii `scanf` sa to dá dvoma
spôsobmi:

1.  overením návratovej hodnoty funkcie. V prípade, že načítanie celého
    čísla nebolo úspešné, návratová hodnota funkcie bude mať špeciálnu
    hodnotu (zistíte ju z dokumentácie).

2.  kontrolou obsahu premennej, do ktorej sa načítavalo. Je dôležité,
    aby premenná, do ktorej sa bude načítavať bola správne
    inicializovaná.

<div class="warning">

<div class="title">

Pozor

</div>

Funkcia scanf sa pri ďalšom použití chová nepredvídateľne, ak používateľ
vloží inú ako očakávanú hodnotu.

</div>

## Pole

Veľkosť poľa na načítanie si definujte ako konštantu. Konštanta je
príkaz pre preprocesor, ktorým definujete "alias" pre kúsok textu.
Tento "alias" sa nahradí počas prekladu. Niekde na začiatok súboru
zadajte:

``` c
#define VELKOST_POLA 12
```

Tým si vytvoríte konštantu, ktorú môžete využívať v ďalšom zdrojovom
texte, napr.

``` c
int pole[VELKOST_POLA];
```

Maximálnu hodnotu v poli zistíte pomocou cyklu:

``` c
int pole[4] = {4,8,8,2};
int max_hodnota = -1;
for (int i = 0; i < 4; i++){
    if (pole[i] > max_hodnota){
        max_hodnota = pole[i];
    }
}
printf("Maximálna hodnota je %d\n",maximalna_hodnota);
```

<div class="warning">

<div class="title">

Pozor

</div>

V poli sa tesne po vytvorení nachádzajú ľubovoľné hodnoty.

</div>

Po vytvorení je vhodné do poľa priradiť nejaké počiatočné hodnoty, napr.

``` c
int pole[VELKOST_POLA] = {0,0,0,0};
```

Pre inicializáciu poľa vieme použiť aj funkciu
[memset()](http://www.cplusplus.com/reference/cstring/memset/):

``` c
memset(pole,0,VELKOST_POLA * sizeof(int));
```

Posledný argument tejto funkcie je veľkosť poľa v bajtoch.

# Návrh riešenia

Budete potrebovať tieto dáta:

  - konštantu pre uloženie veľkosti poľa. napr. `#define
    VELKOST_POLA 52`

  - pole celých čísel fixnej veľkosti na uloženie výsledkov napr. `int
    vysledky[VELKOST_POLA]`.

  - premennú na uloženie najlepšieho výsledku (`int`).

  - premennú na uloženie počtu súťažiacich (`int`).

Riešenie problému si môžme vyjadriť pomocou tohto postupu:

1.  Na začiatku si vytvorte a inicializujte všetky potrebné premenné.

2.  V cykle načítavajte celé čísla do poľa.

3.  Overte si, či bolo načítanie úspešné. Pri každom úspešnom načítaní
    zvýšte hodnotu počítadla o jedna. Ak načítanie nebolo úspešné
    ukončite cyklus.

4.  V prípade, že sa nenačítala ani jedna hodnota, vypíšte chybové
    hlásenie a ukončite program.

5.  Spočítajte všetky úspešne načítané hodnoty.

6.  Zistite maximálnu hodnotu v poli.

7.  Na konci vypíšte všetky výsledky, ktoré sú maximálne. Môže ich byť
    aj viac.

# Vypracovanie

Úlohu budete odovzdávať pomocou webového formulára v systéme Traktor.
Heslo na úlohu je `cv2`.

# Domáca úloha

  - Dokončite cvičenie (3b).

  - Pripravte sa na zápočtovku ďalší týždeň (10b). So zadaním na
    zápočtovke sa oboznámite na prednáške.
