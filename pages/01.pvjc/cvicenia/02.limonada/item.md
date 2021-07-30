---
title: Limonádový pohár
published: true
---

! Zopakujete si:
!
!  - Formátovaný vstup celého čísla.
!  - Algoritmus hľadania maximálneho čísla v poli.
!  - Cykly, podmienky a premenné.
!  - Čo je to konštanta.
!  - Na čo je hlavičkový súbor.

## Kto vypil najviac limonády?

Na Technickej univerzite sa koná súťaž v druhom najobľúbenejšom
slovenskom športe - pijatike citrónovej limonády zvanej aj citronáda.
Súťažiaci dostali štartovacie čísla od jednotky až po počet
súťažiacich. Počas troch minút majú za úlohu vypiť čo najviac
dvojdecových pohárov kvalitnej citronády z produkcie študentského bufetu
"Libresso" v budove Univerzitnej knižnice.

Ako člen technickej poroty budete mať na starosti spracovanie výsledkov.
Na štandardný vstup nového informačného systému sa bude postupne
zapisovať počet počet vypitých pohárov pre každého súťažiaceho podľa
jeho štartovacieho čísla. Prvý súťažiaci má štartovacie číslo 0.

Koniec zápisu výsledkov sa vyznačí vložením
neplatného čísla (inej ako kladnej celej hodnoty) alebo koncom vstupu
(`CTRL+D`).

Vašou úlohou bude vytvoriť program, ktorý načíta do poľa počty vypitých
pohárov a vypíše čísla všetkých súťažiacich, ktorí vypili maximálny
počet pohárov.

![Lemonade from Wikipedia](Fentimans_Range.png)

## Návod

Na riešenie budeme potrebovať funkcie na formátovaný vstup a výstup.
Naštudujte si technickú dokumentáciu funkcií štandardnej knižnice,
ktoré sú v tomto prípade najjednoduchšie použiteľné:

  - [printf()](http://www.cplusplus.com/reference/cstdio/printf/)
  - [scanf()](http://www.cplusplus.com/reference/cstdio/scanf/)

Pri štúdiu technickej dokumentácie sa zamerajte na zistenie:

- aký dátový typ majú argumenty funkcie.
- aký je význam argumentov funkcie.
- aký je typ návratovej hodnoty.
- aký je význam návratovej hodnoty.

Pozor, nie všetko musí byť zrejmé na prvý pohľad.
Pri štúdiu funkcie [scanf()](http://www.cplusplus.com/reference/cstdio/scanf/) zistíme, že jej úloha je načítavať dáta na
určitú adresu v pamäti. Ale návratová hodnota znamená niečo iné. Čo je to?

!! Nezabudnite:
!!
!! Na to, aby ste vedeli použiť akúkoľvek funkciu, musíte s pomocou
!! direktívy preprocesora `#include` do zdrojového kódu zapísať v ktorom
!! hlavičkovom súbore sa nachádza jej definícia. Názov hlavičkového súboru
!! zistíte z dokumentácie.

### Načítanie premennej

Keď si vytvoríme novú premennú tak jej priraďme nulovú hodnotu.

Každá premenná má svoju adresu v pamäti a tú zistíte pomocou operátora `&`. Druhý argument funkcie `scanf()` je adresa na ktorú sa má zapísať výsledok.

```c
int value = 0;
int r = scanf("%d",&value);
```

Operácia načítania má vždy neistý výsledok. Funkcia na načítanie sa môže vykonať, ale načítanie mohlo zlyhať.  Používateľ mohol zadať niečo iné ako očakávate, napríklad písmená namiesto čísla. Vtedy sa môže stať, že budeme pracovať s nedefinovanou (ľubovoľnou) hodnotou. Tomu je potrebné zabrániť
a po načítaní si overiť, či prebehlo úspešne. 

Pri funkcii `scanf` sa to dá dvoma
spôsobmi:

1.  overením návratovej hodnoty funkcie. V prípade, že načítanie celého
    čísla nebolo úspešné, návratová hodnota funkcie bude mať špeciálnu
    hodnotu (zistíte ju z dokumentácie).
2.  kontrolou obsahu premennej, do ktorej sa načítavalo. Je dôležité,
    aby premenná, do ktorej sa bude načítavať bola správne
    inicializovaná.


!!! Funkcia `scanf` sa pri ďalšom použití chová nepredvídateľne, ak používateľ vloží inú ako očakávanú hodnotu.

Celé načítanie jednej hodnoty s overením môže vyzerať takto:

```c
int value = 0;
int r = scanf("%d",&value);
if (r == 1){
    printf("Úspešne som načítal hodnotu %d\n",value);
}
else {
    printf("Načítanie sa nepodarilo. V premennej value ostala pôvodná hodnota. \n");
}
```

### Pole fixnej veľkosti

Veľkosť poľa na načítanie si definujte ako konštantu. Konštanta je
príkaz pre preprocesor, ktorým definujete "alias" pre kúsok textu.
Tento "alias" sa nahradí počas prekladu. Niekde na začiatok súboru
zadajte:


```c
#define VELKOST_POLA 12
```

Tým si vytvoríte konštantu, ktorú môžete využívať v ďalšom zdrojovom
texte. Takto si vytvoríme nové statické pole konštantnej veľkosti:

```c
int pole[VELKOST_POLA];
```

!! Pozor:
!!
!! V poli sa tesne po vytvorení nachádzajú ľubovoľné hodnoty.


Po vytvorení je vhodné do poľa priradiť nejaké počiatočné hodnoty, napr.:

```c
int pole[VELKOST_POLA] = {0,0,0,0};
```

priradí hodnotu nula prvým štyrom prvkom poľa. Ostatné prvky zostanú neinicializované, teda **môžu mať ľubovoľnú hodnotu**.  To je dosť nepraktické pre väčšie polia. Pre inicializáciu poľa vieme použiť aj funkciu
[memset()](http://www.cplusplus.com/reference/cstring/memset/):

```c
memset(pole,0,VELKOST_POLA * sizeof(int));
```

Posledný argument tejto funkcie je veľkosť poľa v bajtoch.


### Načítanie do poľa

Na začiatku nie je známe koľko súťažiacich budeme spracovávať. Záleží to od toho, koľko čísel sa podarí načítať.

Budete potrebovať tieto dáta:

  - konštantu pre uloženie veľkosti poľa. napr. `#define VELKOST_POLA 52`
  - pole celých čísel fixnej veľkosti na uloženie výsledkov napr. `int vysledky[VELKOST_POLA]`.
  - premennú na uloženie najlepšieho výsledku (`int`).
  - premennú na uloženie počtu úspešne načítaných hodnôt (`int`).

Skúste v jazyku C zapísať tento postup:

1. Na začiatku si vytvorte a inicializujte všetky potrebné premenné.
2. Vytvorte si cyklus. V cykle načítavajte celé čísla do poľa.
3. Vo vnútri cyklu si overte, či bolo načítanie úspešné. Pri každom úspešnom načítaní zvýšte hodnotu počítadla o jedna. Ak načítanie nebolo úspešné
ukončite cyklus.
4. V prípade, že sa po ukončení cyklu nenačítala ani jedna hodnota, vypíšte chybové  hlásenie a ukončite program.

### Určenie a výpis maximálnej hodnoty

Pri každom úspešnom načítaní v cykle zistite, či načítané číslo je najväčšie.
Ak je, poznačte si ho:


```c
if (pole[i] > max_hodnota){
    max_hodnota = pole[i];
}
```

Na konci  v cykle vypíšte poradové číslo všetkých súťažiacich, ktorí dosiahli maximálnu hodnotu. Môže ich byť  aj viac.

## Odovzdanie

[Úlohu budete odovzdávať](https://traktor.kemt.fei.tuke.sk/#/submit/144) do súboru `program.c` v adresári `du2`  vo Vašom GIT repozitári.

