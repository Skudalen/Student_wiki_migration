# Triedenie

Ako by ste usporiadali skupinu objektov?

  - podľa čoho?

  - ako by ste postupovali

# Triedenie jedno prvkovej množiny

Netreba triediť

# Triedenia dvojprvkovej množiny

  - Porovnajme oba prvky

  - Väčší dajme na druhé miesto

# Triedenie trojprvkovej množiny

  - Zotriedime prvú dvojicu.

  - Zotriedime druhú dvojicu.

  - Sme si istý, že na konci bude najväčší prvok

  - Zotriedime ešte raz prvú dvojicu.

# Triedenie n-prvkovej množiny

  - Zotriedime všetky dvojice, čo idú za sebou

  - Na konci bude určite najväčší prvok.

  - Zotriedime zvyšok bez najväčšieho prvku ako n-1 prvkovú množinu.

# Iteratívne bublinkové triedenie

``` c
int pole[10] = {4,10,2,5,6,7,8,2,4,8};
// Pole velkosti 1 nemá zmysel triedit
for (int i = 0; i < 10;i++){
    for (int j = 1; j < 10 - i;j++){
        if (pole[j-1] >= pole[j]){
            int k = pole[j];
            pole[j] = pole[j-1];
            pole[j-1] = k
        }
    }
}
```

# Rekurzívne bublinkové triedenie

``` c
void bubble_sort(int* pole, int size){
    if (size < 2){
        return;
    }
    for (int i = 1; i < size;i++){
        if (pole[i-1] >= pole[i]){
            int k = pole[i];
            pole[i] = pole[i-1];
            pole[i-1] = k;
        }
    }
    bubble_sort(pole,size-1);
}
```

# Triediť je možné viacerými spôsobmi

  - insertion sort

  - merge sort

  - heap sort

  - quick sort

# Matematika triedenia

  - množina hodnôt

  - operácia čiastočného usporiadania

# Operácia čiastočného usporiadania

  - Funkcia dvoch argumentov

  - Je menší

  - Je väčší alebo rovný

# Triedenie pomocou štandardnej knižnice

  - Môžeme triediť ľubovoľné pole hodnôt
    
      - počet hodnôt
    
      - veľkosť jednej hodnoty
    
      - porovnanie 2 hodnôt

# Predpis funkcie qsort

``` c
void qsort (
    void* base, // Začiatok poľa
    size_t num, // Počet prvkov
    size_t size, // Veľkosť prvku
    int (*compar)(const void*,const void*) // Operácia porovnania
);
```

# Ako volať funkciu qsort

  - Využiť dynamické pretypovanie

  - definovať funkciu s parametrami `void*` a `void*`, ktorá porovná dva
    prvky

# Ale ja neviem čo to…​

  - `size_t`

  - `void*`

  - `int (compar)(const void,const void*)`

# Čo je to dátový typ v jazyku C

  - koľko bajtov máme k dispozícii na jednu hodnotu.
    
      - koľko rôznych hodnôt môžme uložiť.

  - akým spôsobom budeme s hodnotou nakladať
    
      - čo bude výsledkom operácií (napr. `+ - * / ++ == % --`)

# Jazyk C je "silno typovaný"

  - Každá premenná má pevne definovaný typ, ktorý sa nemôže meniť.

  - Typ hodnoty sa ale môže meniť takmer ľubovoľne.

# Dynamické pretypovanie

``` c
int cele_cislo = 3.4;
float realne_cislo = 4;
```

# Výsledok operácií

``` c
int a = 5;
int b = 2;

float c = a / b;
```

# Výsledok operácií

    float / float = float
    int / int = int

# Operátor dynamického pretypovania (typ)

``` c
int a = 5;
int b = 2;

float c = (float)a / (float)b;
```

# Operátor dynamického pretypovania (typ)

Vytvori "dočasnú premennú" s daným typom a pôvodnou hodnotou.

# Ako by sme urobili abstrakciu (znovu použiteľnú funkciu triedenia)

  - Operácia porovnania

# Triedenie je závislé od TYPU

# Smerník na funkciu

Rob čo Ti poviem

Callback

    int (*compar)(const void*,const void*)

# Triedenie poľa celých čísel

``` c
// http://www.cplusplus.com/reference/cstdlib/qsort/
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main (){
  int values[] = { 40, 10, 100, 90, 20, 25 };
  qsort (values, 6, sizeof(int), compare);
  for (int n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}
```

# Zhrnutie

  - Typ staticky alokovanej premenej nie je možné meniť.

  - Typ hodnôt dynamicky alokovanej premennej je možné ľubovoľne meniť

  - Typ hodnoty je možné (takmer) ľubovoľne meniť.
