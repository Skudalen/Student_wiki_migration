# Dynamická alokácia

# Druhy alokácie pamäte

  - Statická  
    Ak presne vieme koľko pamäte budeme potrebovať.

  - Dynamická  
    Ak chceme množstvo meniť počas behu programu.

# Statická pamäť

# O statickú pamäť sa stará kompilátor

  - Vyhradí sa, keď vytvoríme novú premennú.

  - Uvoľní sa, keď skončí kontext.

  - Nie je možné meniť jej veľkosť.

# Obsah statickej pamäte sa odovzdáva kopírovaním

``` c
void funkcia(int a) {
     a = 2;
}
int main(){
    int a = 1;
    funkcia(a);
}
```

# Dynamická pamäť

  - Stará sa o ňu programátor.

  - Alokuje a uvoľnuje sa na požiadanie.

  - Je dostupná pomocou smerníka.

# Malloc

Vyhradili sme si 100 bajtov pamäte a ich adresu sme uložili do premennej
`mojapamat`.

``` c
void* mojapamat = malloc(100);
```

Smerník typu `void*` je všeobecný smerník, ktorý nehovorí na aký typ
pamäte ukazuje.

# Free

``` c
free(mojapamat);
```

Každú vyhradenú pamäť musíme explicitne uvoľniť pomocou `free`.

# Zen jazyka C

  - Názov poľa je adresa jeho začiatku.

  - Ľubovoľná adresa môže byť začiatkom poľa.

# Všetky typy jazyka C je možné meniť

  - Aj typy smerníkových premenných.

# Využitie dynamicky alokovanej pamäte

Na to, aby sme vedeli využiť dynamicky alokovanú pamäť, musíme zmeniť
jej typ:

``` c
char* poleznakov = (char*)malloc(100);
poleznakov[0] = 'a';
poleznakov[1] = 0;
free(poleznakov);
```

Smerník `char*` môžeme použiť ako miesto pre uloženie reťazca s
veľkosťou 100 bajtov.

Koľko znakov sa zmestí do takejto pamäte?

# Dynamicky alokovaná pamäť je dostupná iba pomocou jej adresy

Hodnota v dynamickej pamäti je dostupná pomocou operátora dereferencie
`*`.

Hodnota v dynamicky alokovanom poli je dostupná pomocou operátora `[]`

# Ako to vyzerá v pamäti?

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

# Dynamická alokácia pamäte (na kope)

Keď dopredu nevieme koľko pamäte budeme potrebovať.

Napr. potrebujeme prečítať súbor po riadkoch

Pri statickej alokácii budeme vždy obmedzení max. veľkosťou riadku,
alebo budeme veľmi plytvať

# Alokácia a inicializácia dynamickej pamäte

``` c
char* poleznakov = (char*)calloc(1,100);
poleznakov[0] = 'a';
free(poleznakov);
```

# Zmena veľkosti alokovanej pamäte realloc

``` c
char* poleznakov = (char*)calloc(1,100);
poleznakov[0] = 'a';
poleznakov = realloc(poleznakov,200);
poleznakov[150] = 'b';
free(poleznakov);
```

# Statické pole

![Diego Delso CC](field.jpg)

# Dynamické pole

# Praktická ukážka

Modul s dynamickým poľom typu `int`

``` c
#include <stdio.h>
#include <stdlib.h>

struct darray {
    int capacity;
    int* start;
};

struct darray* create(int capacity){
    struct darray* res = malloc(sizeof(struct darray));
    res->capacity = capacity;
    res->start = (int*)malloc(res->capacity * sizeof(int));
    return res;
}

void destroy(struct darray* addr){
    free(addr->start);
    free(addr);
}

void darray_set(struct darray* addr,int i,int value){
    if (i >= addr->capacity){
        addr->capacity = addr->capacity * 2;
        if (i >= addr->capacity ){
            addr->capacity = i * 2;
        }
        addr->start  = realloc(addr->start,addr->capacity * sizeof(int));
    }
    addr->start[i] = value;

}

int main() {
    struct darray* da = create(100);
    darray_set(da,0,1);
    darray_set(da,2,7);
    destroy(da);
    return 0;
}
```

# Zhrnutie

  - Dynamickú pamäť vyhradzujeme a uvoľňujeme pomocou `malloc` a `free`.

  - Vieme si určiť, akého bude typu.

# Potom koniec
