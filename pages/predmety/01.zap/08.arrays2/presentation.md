# Triedenie a vyhľadávanie


Ing. Daniel Hládek PhD.

---
# Opakovanie

Polia

[note]


- Meno poľa je adresa jeho prvého prvku
- Všetky prvky poľa majú ten istý dátový typ
- V pamäti sú prvky poľa uložené za sebou
- Pole má fixnú veľkosť
- Je ľahké čítať a zapisovať mimo hraníc poľa - program sa dostane do nedefinovanéo stavu.


V jazyku C sa argumenty odovzdávajú vždy kópiou.

Ak by sme chceli pole odovzdať ako argument, 
musíme ho celé kopírovať a musíme používať vždy tú istú veľkosť.

Aby sme obišli tento problém, pole odovzdávame ako adresu jeho prvého prvku a jeho veľkosť.
[/note]

---
# Vyhľadávanie bisekciou

- Predpokladáme, že pole je zotriedené
- Pozrieme sa do prostriedku a postupne zmenšujeme prehľadávanú oblasť

---
# Porovnávanie celých čísel

- Ak je rozdiel nulový, čísla sú rovnaké
- Ak je rozdiel kladný, prvé číslo je väčšie

---
```c
int bisec(int * array,int size,int needle){
        int from = 0;
        int to = size;
        int mid = size / 2;
        while (to > from){
                int r = array[\mid] - needle;
                if (r == 0){
                        return mid;
                }
                else if (r > 0){
                        to = mid;
                }
                else {
                        from = mid + 1;
                }
                mid = (to - from) / 2 + from;
                //printf("%d %d %d\n",from,mid,to);
        }
        return -1;
}

int main(){
        int a1[] = {1,2,2,3,3,4};
        int r = bisec(a1,6,4);
        printf("%d\n",r);
        return 0;
}
```

---
# Bublinkové triedenie

Binárne vyhľadávanie v zotriedenom poli je oveľa rýchlejšie ako lineárne.

---

1. Zober 2 susedné prvky
1. Vymeň ich tak aby napravo bol väčší prvok
1. Opakuj pre celé pole. V celom poli je napravo najväčší prvok.
1. Opakuj pre celé pole okrem už zotriedených prvkov.
1. Ak už nie je čo triediť, skonči.

---
# Iteratívne bublinkové triedenie

---

```c
void bsort(int* data, int size){
	// Prejdeme všetky členy
    for(int j = 0; j < size - 1; j++){
    	// Prejdeme všetky členy 
        // okrem tých na konci ktoré sú už zotriedené
        for(int i = 0; i < size - 1 - j; i++){
        	// Vymeníme susedov tak aby napravo bol ten väčší
            if(data[i+1] < data[\i]){
                // swap
                int tmp = data[i+1];
                data[i+1] = data[\i];
                data[\i] = tmp;
            }
        }
    }
}
```

---

# Tanec bublinkového triedenia

https://www.youtube.com/watch?v=lyZQPjUT5B4

---

# Rekurzívny algoritmus bublikového triedenia

---


```c
void recursive_bsort(int* data, int size){
	// Ukončovacia podmienka, pole veľkosti 1 nie je potrebné triediť
    if (size < 2)
        return;
    // Na konci cyklu bude napravo najväčší prvok
    for(int i = 0; i < size - 1; i++){
        if(data[i+1] < data[i]){
            // swap
            int tmp = data[i+1];
            data[i+1] = data[\i];
            data[\i] = tmp;
        }
    }
    // Zotriedime zvyšok poľa
    recursive_bsort(data,size - 1);
}
```
---
Rekurzívna implementácia je možná aj vďaka tomu, že pole odovzdávame adresou, nie hodnotou.

---

# Z čoho sa skladá rekurzia:


1. Ukončovacia podmienka
2. Telo
3. Volanie rekurzie

---

# Zložitosť algoritmu bublinkového triedenia

Tento algoritmus si vyžaduje 2 vnorené cykly.

- Kvadratická zložitosť

---

Donald Knuth, in The Art of Computer Programming, concluded that:

"the bubble sort seems to have nothing to recommend it, except a catchy 
name and the fact that it leads to some interesting theoretical problems",

---
# Selection sort

Vyberieme najväčší prvok.

Vymeníme ho s posledným prvkom.

---

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

void selection(int* array, int size){
        while (size > 0){
                int b = -1;
                int bv = -1;
                for (int i = 0; i < size; i++){
                        if (array[\i] >= bv){
                                bv = array[\i];
                                b = i;
                        }
                }
                bv = array[size - 1];
                array[size -1] = array[\b];
                array[\b] = bv;
                size -= 1;
        }
}

int main(){
        srand(time(NULL));
        int array[\SIZE];
        for (int i = 0; i < SIZE; i++){
                array[\i] = rand() % 100;
        }
        selection(array,SIZE);
        for (int i = 0; i < SIZE; i++){
            printf("%d ",array[\i]);
        }
        printf("\n");
        return 0;
}

```

---
# Tanec insertion sort

https://www.youtube.com/watch?v=ROalU379l3U

---
# Quicksort

Používa sa niektorá všeobecná implementácia, napr. zo štandardnej knižnice.

---
# Príklad na qsort

http://www.cplusplus.com/reference/cstdlib/qsort/

```c
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

// Správanie triedenia je ovplyvňované porovnávacou funkciou
int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main () {
	int values[] = { 40, 10, 100, 90, 20, 25 };
  	qsort (values, 6, sizeof(int), compare);
  	for (int n=0; n<6; n++)
     	printf ("%d ",values[n]);
  	return 0;
}
```

---

# Tanec Quicksort

https://www.youtube.com/watch?v=ywWBy6J5gz8
