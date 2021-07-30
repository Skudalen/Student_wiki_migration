# Dynamická alokácia


---
## Ako spracovať ľubovoľné množstvo dát?

---
### Ako počas behu programu ovládať množstvo dostupnej pamäte?

- Statická alokácia: Ak presne vieme koľko pamäte budeme potrebovať.
- Dynamická alokácia: Ak chceme množstvo meniť počas behu programu.

---
## K dispozícii máme dva druhy pamäte

- kopa (heap)
- zásobník (stack)


---
## Zásobník

Pre lokálne premenné

---
## O zásobník sa stará kompilátor

- Zásobník sa vytvorí, keď začneme kontext.
- Nový kontext má k dispozícii pôvodný kontext.
- Lokálne premenné využijú zásobník.
- Uvoľní sa, keď skončí kontext.

---
### Obsah statickej pamäte sa odovzdáva kopírovaním

``` c
void funkcia(int a) {
     a = 2;
}
int main(){
    int a = 1;
    funkcia(a);
}
```

---
### Dynamická alokácia pamäte (na kope)

Keď dopredu nevieme koľko pamäte budeme potrebovať.

Napr. potrebujeme prečítať súbor po riadkoch

Pri statickej alokácii budeme vždy obmedzení max. veľkosťou riadku,
alebo budeme veľmi plytvať.

---
## O kopu sa stará porgramátor

Existuje jedna "kopa" počas celého behu programu.

Na konci ju (možno) zruší operačný systém.


---
## Využitie kopy

- Alokuje sa na požiadanie pomocou `malloc()` alebo `calloc()`.
- Uvoľňuje sa na požiadanie pomocou `free()`.
- Je dostupná pomocou smerníka.

---
## Malloc

Vyhradili sme si 100 bajtov pamäte a ich adresu sme uložili do premennej
`mojapamat`.

``` c
void* mojapamat = malloc(100);
```

Smerník typu `void*` je všeobecný smerník, ktorý nehovorí na aký typ
pamäte ukazuje.

---
# Free

``` c
free(mojapamat);
```

Každú vyhradenú pamäť musíme explicitne uvoľniť pomocou `free`.

---
## Pretypovanie

```
int* intpamat = (int*)mojapamat;
```

---
# Zen jazyka C

- Názov poľa je adresa jeho začiatku.
- Ľubovoľná adresa môže byť začiatkom poľa.

---
## Mám dosť pamäte?


```
intpamat[`10] = 1;
```

---
## Mám dosť pamäte?


```
// Mam k dispozicii 20 miest typu int
int* intpamat = malloc(sizeof(int)* 20);
intpamat[`10] = 1;
free(intpamat);
```

---
### Dynamicky alokovaná pamäť je dostupná iba pomocou smerníkovej premennej

---

Prvé miesto:

```
int prvahodnota = *intpamat;
```

Tretie miesto:


```
int tretiahodnota = intpamat[2];
```

---
### Ako to vyzerá v pamäti?

---

``` 
                   +-------------------+
Pamäť na kope      | | | | | | | | | | |
                   +-------------------+
adresa:          \#10 1              \#20
                   ^
                   |
                   +---------------------------+
                                               |
Pamäť na stacku                                |
                                               |
názov premennej:   poleznakov                  |
typ premennej:      char*                      |
                   +--------------+            |
hodnota:           |     10       | -----------+
                   +--------------+
adresa:             \#100        \#108
```

---
### Alokácia a inicializácia dynamickej pamäte

``` c
char* poleznakov = (char*)calloc(1,100);
poleznakov[0] = 'a';
free(poleznakov);
```

---
### Zmena veľkosti alokovanej pamäte: `realloc`

``` c
char* poleznakov = (char*)calloc(1,100);
poleznakov[0] = 'a';
poleznakov = realloc(poleznakov,200);
poleznakov[150] = 'b';
free(poleznakov);
```

---
# Statické pole

![Diego Delso CC](field.jpg)

---
# Zhrnutie

  - Dynamickú pamäť vyhradzujeme a uvoľňujeme pomocou `malloc` a `free`.
  - Vieme si určiť, akého bude typu.

