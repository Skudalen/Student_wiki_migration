Naučíte sa:

  - Vytvoriť novú premennú alebo pole, aj keď dopredu neviete jej typ.

  - Vytvoriť pole ktorého veľkosť zistíte až po spustení programu.

# Dynamicky alokovaná pamäť

Do teraz sa o vyhradenie a uvoľňovanie pamäte staral kompilátor. Stačilo
do programu napísať o akú pamäť v akom množstve máme záujem a prekladač
sa postaral o ostatné. Automaticky alokovanú pamäť nazývame statická.
Nevýhodou je, že veľkosť a typ pamäte musí byť známy už počas doby
prekladu.

INFO: Statická pamäť je alokované na tzv. zásobníku (stack), časť
pamäte, ktorá je pridelená konkrétnemu volaniu funkcie.

Dynamickú pamäť veľkosti 100 bajtov si alokujeme príkazom `malloc`. Hneď
ako pamäť nebudeme potrebovať, uvoľníme ju príkazom `free`.

``` c
void* pole = malloc(100);
free(pole);
```

V smerníku `pole` je uložená adresa prvého prvku súvislej oblasti. Tento
smerník zatiaľ nie je spojený so žiadnym pamäťovým typom - je to smerník
na typ `void`. Na to, aby sme pamäť nejako využili, je potrebné jej
nejaký typ priradiť. Pri zmene dátového typu nie sme ničím obmedzený -
môžeme použiť ľubovoľný existujúci typ, ktorý sa zmestí do vyhradeného
miesta. Túto pamäť môžeme využiť na uloženie reťazca:

``` c
void* pole = malloc(100);
char* retazec = pole;
strcpy(retazec,"Ahoj svet!");
printf("%s\n",retazec);
free(pole);
```

Príkaz `malloc()` má podobnú funkciu, ako príkaz na statické vyhradenie
pamäte:

``` c
char pole[100];
```

Rozdiel je, že dynamicky vyhradená pamäť sa automaticky neuvoľní, ale
zostane prístupná až do vtedy, pokiaľ ju explicitne neuvoľníme pomocou
`free`. Vo vyhradenej pamäti sa nachádzajú nedefinované hodnoty, preto
je pole musíme inicializovať na nejakú počiatočnú hodnotu. Príkazom
`strcpy` sme do vyhradeného miesta nakopírovali zadaný reťazec. Klasický
operátor priradenia (`char* retazec="Ahoj Svet\n";`) nebude fungovať
podľa očakávania - do smerníka sa priradí adresa staticky alokovanému
reťazcu.

# Pretypovanie smerníka

Podobným spôsobom si z rovnakej pamäte môžeme vytvoriť aj pole celých
čísel.

``` c
void* pole = malloc(100);
int* cele_cisla = pole;
cele_cisla[0] = 1;
cele_cisla[1] = 2;
printf("%d %d\n",cele_cisla[0],cele_cisla[1]);
free(pole);
```

Došlo ale k plytvaniu pamäťou - hoci potrebujeme miesto iba pre dve
celočíselné hodnoty, vyhradili sme si miesto až 100 bajtov. Na to aby
sme boli o niečo efektívnejší, potrebujeme pri alokácii poznať poznať
veľkosť jedného pamäťového miesta a koľko miest potrebujeme. a po
použijeme operátor `sizeof`. Pre skrátenie zápisu vykonáme operáciu
pretypovania smerníka typu `void*` na typ `int*` hneď.

``` c
int* cele_cisla  = (int*)malloc(sizeof(int)* 2);
```

Takto sme zadali požiadavku operačnému systému pre vyhradenie miesta na
dve premenné typu `int` hneď vedľa seba.

# Štruktúry

Príkazom `malloc` si vieme vyhradiť pamäť pre akýkoľvek dátový typ.
Môžeme si dynamicky vyhradiť miesto pre jednu premennú typu `int`:

``` c
int* cele_cislo = malloc(sizeof(int));
```

V skutočnosti sme si vyhradili miesto až pre dve premenné. Niekde na
pamäti (na kope) sa nachádza miesto, kde si uložíme číselnú hodnotu. K
tejto hodnote ale nemôžeme pristupovať priamo, ale musíme využiť
smerníkovú premennú `int* cele_cislo` ktoré je alokované staticky a
operátor `*`.

``` c
*cele_cislo = 2;
```

Podobným spôsobom vieme dynamicky alokovať pamäť aj pre zložitejšie
dátové typy, napr. štruktúru. Statickým spôsobom by sme to urobili
takto:

``` c
#include <stdio.h>
struct datum {
    int den;
    int mesiac;
    int rok;
};

int main(){
    struct datum dnes;
    dnes.den = 1;
    dnes.mesiac = 1;
    dnes.rok = 2018;
    printf("Dnes je %d.%d.%d\n",dnes.den,dnes.mesiac,dnes.rok);
    return 0;
}
```

Dynamický spôsob by bol:

``` c
struct datum* dnes = malloc(sizeof(struct datum));
(*dnes).den = 1;
(*dnes).mesiac = 1;
(*dnes).rok = 2018;
printf("Dnes je %d.%d.%d\n",(*dnes).den,(*dnes).mesiac,(*dnes).rok);
free(dnes);
```

K prístupu k členom dynamicky alokovanej štruktúry musíme využiť
operátor `*` . Operátor `()` hovorí, že operácia dereferencie sa má
aplikovať iba na prvú časť výrazu `dnes.den` a nie na celý výraz.

Dynamicky alokované štruktúry sa v jazyku C vyskytujú pomerne často a
prístup k ich členom pomocou zátvoriek a hviezdičky je pomerne zložitý.
Preto z estetických dôvodov vieme nahradiť operátor `*` pre prístup k
členom štruktúry operátorom `→` . Predošlý príklad potom môžeme zapísať
takto:

``` c
struct datum* dnes = malloc(sizeof(struct datum));
dnes->den = 1;
dnes->mesiac= 1;
dnes->rok = 2018;
printf("Dnes je %d.%d.%d\n",dnes->den,dnes->mesiac, dnes->rok);
free(dnes);
```

Ak chceme všetky členy štruktúry inicializovať na nulu, môžeme to tak
urobiť naraz pomocou funkcie `memset`:

``` c
struct datum* dnes = malloc(sizeof(struct datum));
memset(dnes,0,sizeof(struct datum));
printf("Dnes je %d.%d.%d\n",dnes->den,dnes->mesiac, dnes->rok);
free(dnes);
```

Pre ešte lenivejších kolegov je možné alokáciu a inicializáciu vykonať v
jednom kroku pomocou funkcie `calloc`:

``` c
struct datum* dnes = calloc(sizeof(struct datum));
printf("Dnes je %d.%d.%d\n",dnes->den,dnes->mesiac, dnes->rok);
free(dnes);
```

Situácia je o niečo komplikovanejšia, ak je členom štruktúry pole alebo
reťazec. Musíme dávať pozor, či je reťazec alokovaný staticky alebo
dynamicky. Ak si vytvoríme štruktúru, ktorá má reprezentovať údaje o
študentovi, môžeme použiť staticky alokovaný reťazec:

``` c
struct student {
    char meno[100];
    int rocnik;
};

struct student* daniel = calloc(sizeof(struct student));
daniel->rocnik = 1;
strcpy(daniel->meno,"Daniel");
free(daniel);
```

Nevýhodou tohto prístupu je, že pamäť nie je využitá veľmi efektívne -
každý záznam v databáze študentov zaberie 104 bajtov.

Pamäť môžeme využiť o niečo efektívnejšie, ak využijeme dynamickú
alokáciu a meno študenta uložíme do dynamicky alokovaného poľa. Do
štruktúry pole si uložíme smerník na začiatok poľa s menom. Daňou za to
je o niečo zložitejšia manipulácia so záznamom. Dynamické pole musíme
alokovať a uvoľniť osobitne;

``` c
struct student {
    char* meno;
    int rocnik;
};

struct student* daniel = calloc(sizeof(struct student));
daniel->rocnik = 1;
malloc(daniel->meno, strlen("Daniel") + 1);
strcpy(daniel->meno,"Daniel");
free(daniel->meno);
free(daniel);
```
