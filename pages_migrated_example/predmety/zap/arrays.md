---
title: Polia
published: true
---
# Polia


Základy algoritmizácie a programovania

Ing. Daniel Hládek PhD.

---
# Obsah prednášky

- úvod, indexovanie prvkov, 
- zmena obsahu poľa, 
- prechod poľom, vyhľadávanie v poli
- cyklus for, 
- vyhľadávanie
- triedenie

---
# Premenná

Niekoľko bajtov v na určitom mieste v pamäti s dohodnutým spôsobom práce.

---
# Premenná v pamäti

```c
int premenná = 1;
```

```
               4 bajty 
             +-------------+
    hodnota: | 00 00 00 01 |
             +-------------+

    adresa:  \#10          \#14 
```

---
# Pole

Viac premenných rovnakého typu za sebou


```c
float merania[] = {1,2,3,4};
```


---
# Pole v pamäti

```
	int pole[[4]] = {4,3,2,1};
    
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22 
```

---
Pole má fixnú veľkosť, ktorá sa v čase nemôže meniť.
Ak potrebujeme pole zväčšiť, musíme si vyhradiť nové pole.
    
---
# Index  prvku

Na prístup k prvkom poľa môžeme použiť operátor \[\]:

```c
float merania[\4] = {0.0,0.0,0.0,0.0};

merania[\0] = 1.1;
float m1 = merania[\0];
```

---
# Index v pamäti

```       
    index:      0      1      2        3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22 
```



---
# Index začína nulou!

Pole nám slúži ako viac premenných

---
# Inicializácia

```c
int hodnoty[\4];
printf("Akú mám hodnotu? %d\n",hodnoty[\0]);
```

---
# Inicializácia poľa pomocou cyklu

```c
float merania[\50];
for (int i = 0; i < 50; i++){
   merania[\i] = 0.0;
}
```

---
# Načítanie do poľa

<!--
Chyba v zdrojáku hranaté zátvorky
-->

```
float merania [\50];
for (int i = 0; i < 50; i++){
    float v = 0;
    int r = scanf("%f",&v);
    if (r == 1){
        merania[\i] = v;
    }
    else {
        merania[\i] = 0;
    }
}
```

---
# Načítanie je vždy neisté

Koľko hodnôt som načítal?

---

# Načítanie neznámeho počtu hodnôť

---

```c
#include <stdio.h>
#define SIZE 50

int main(){
    int pocet = 0;
    float merania[\SIZE];
    for (pocet = 0; pocet < SIZE; pocet +=1){
        int r = scanf("%f",&merania[\pocet]);
	if (r != 1){
	    break;
	}
    }
    printf("Nacital som %d hodnot\n",pocet);
    // Zvyšok poľa nie je inicializovaný
    return 0;
}
```
---
# Pole nemusí byť inicializované

ak nenačítame všetky hodnoty

---
```c
#include <stdio.h>
#define SIZE 50

int main(){
    int pocet = 0;
    float merania [\SIZE];
    for (pocet = 0; pocet < SIZE; pocet +=1){
        if (scanf("%f",&merania[\pocet])!= 1){
	    break;
	}
    }
    for (int i = 0; i < SIZE; i +=1){
       printf("Aká je tu hodnota? %d\n",merania[\i]);
    }
    return 0;
}
```
---

# Hranica poľa

```c
int pole[\4] = {1,2,3,4};
printf("Aká je tu hodnota? %d\n",pole[\4]);
```

---
# Chyby pri práci s pamäťou

- ak môj program padá `segmentation fault`
- ak na inom počítači ide program inak

---
# Ako sa vyhnúť pamäťovej chybe

- dávajte pozor pri prechádzaní a indexovaní poľa
- vždy si inicializujte premenné aj polia
- pri preklade používajte parameter `-Wall -g` a sledujte varovania

---
# Chybové hlásenia sú cenné

pri spustení používajte program `valgrind` a sledujte varovania

---
# Adresa poľa

Pomocu adresy poľa vieme vo funkcii spracovať zadaný počet prvkov.


---
# Zen jazyka C

---
# Názov poľa je adresa jeho začiatku

---
# Smerníková premenná

Adresu ľubovoľnej premennej si vieme poznačiť do smerníkovej premennej.

---
Adresa sa dá uložiť do smerníkovej premennej

```c
int pole[]={1,2,3,4};
int* adresa_pola = pole;
printf("Pole ma adresu #%p\n",adresa_pola);
```

---
Smerníkovú premennú vieme používať rovnako ako pole na ktoré ukazuje


```c
int pole[]={1,2,3,4};
int* adresa_pola = pole;
printf("Pole ma adresu #%p\n",adresa_pola);
printf("Na prvom nieste je %d\n",adresa_pola[0]);
```

---
# Funkcia pre prácu s poľom

Voláme ju s adresou začiatku a s počtom prvkov.

---
# Vyhľadanie v poli

```c
int linear_search(int* heap,int heap_size,int needle){
    for(int i =0; i < size; i++){
        if(heap[i] == needle){
           return i;
        }
    }
    return -1;
}
```
---

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 20
int linear_search(int* heap,int sz,int needle);
int main(){
    srand(time(NULL));
    int pole[SIZE];
    for (int i = 0; i<SIZE; i++){
       pole[i] = rand() % 100;      
    }
    int hladam = 2;
    int nasielsom =  linear_search(pole,SIZE,hladam);
    if (nasielsom >= 0){
       printf("Nasiel som %d na %d\n",hladam,nasielsom);
    }
    else {
       printf("%d v poli nie je\n",hladam);
    }
    return 0;
}
```

