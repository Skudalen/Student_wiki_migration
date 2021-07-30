# 4. Dynamická alokáca pamäte


## 4. Dynamická alokáca pamäte

## Organizačné pokyny

Opravný termín zápočtovky bude v piatom týždni.

## Operácia priradenia

Hodnota 4 sa skopíruje do premennej a. Vznikne nová hodnota.

	int a = 4;
    
## Funkcia, ktorá realizuje operáciu priradenia

```c
#include <stdio.h>

void zapis_do_premennej(int a){
    a = 2;
}
int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    zapis_do_premennej(a);
    printf("V premennej a je po zapise %d\n",a);
}
```

[NOTE.speaker] 
====
Zistili sme, že program nefunguje podľa očakávania. 
Dôvodom je to, že v jazyku C sa argumenty odovzdávajú vždy kópiou.
====

## Adresa premennej - operátor &

```c
#include <stdio.h>
void zapis_do_premennej(int a){
    a = 2;
    printf("V zapis_do_premennej():\n");
    printf("V premennej a vo funkcii je %d\n",a);
    printf("Premenna a je vo funkcii na adrese %p\n",&a);
    printf("koniec funkcie zapis_do_premennej():\n"); 
}
int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    printf("Premenna a je  na adrese %p\n",&a);
    zapis_do_premennej(a);
    printf("V premennej a je po zapise %d\n",a);
    printf("Premennej a je  na adrese %p\n",&a);
    return 0;
}
```

NOTE: %p je formátovací znak pre adresu


## Smerník

Adresa premmennej samostatný dátový typ, ktorý zapisujeme pomocou *.

```c
int premenna_typu_int = 2;
int* adresa_premennej_typu_int = &premenna_typu_int;
```

Adresu premennej nazývame aj *smerník*.

## Ako vyzerá smerník v pamäti

    názov premennej:   premenna_typu_int 
    typ premennej:		int
                       +--------------+
    hodnota:           |     2        | 
                       +--------------+            
    adresa:             #10         #14
                       =====
                                                   
                                                   
    názov premennej:   adresa_premennej_typu_int   
    typ premennej:      int*                       
                       +--------------+            
    hodnota:           |     10       |
                       +--------------+
    adresa:             #40         #48    


### Zmeníme hodnotu adresy


```c
#include <stdio.h>

void zapis_do_premennej(int* a){
    a = 2;
    printf("V premennej a vo funkcii je %d\n",a);
    printf("Premenna a je vo funkcii na adrese %p\n",&a);
}

int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    printf("Premenna a je  na adrese %p\n",&a);
    zapis_do_premennej(&a);
    printf("V premennej a je po zapise %d\n",a);
    printf("Premennej a je  na adrese %p\n",&a);
    return 0;
}
```

[NOTE.speaker]
====
Tento program nie je správny!!! 

- Vo funkcii pracujeme s hodnotou adresy v pamäti
- adresa 2 nie je vyhradená nášmu programu.
- Namiesto kópie hodnoty sa odovzdáva kópia adresy
====

## Operátor dereferencie `*`

Pre prácu so smerníkovými typmi.

1. Zober adresu
2. Pozri sa kam adresa smeruje
3. Vráť hodnotu


## Operátor dereferencie `*`

Vráti *hodnotu* ktorá je na adrese.

```c
int premenna_typu_int = 2;
// Smerníkový typ
int* adresa_premennej_typu_int = &premenna_typu_int;
// Operátor dereferencie
printf("Tak kde ukazuje smernik je hodnota %d\n",*adresa_premennej_typu_int);
```
## Dereferencia * na ľavej strane výrazu

Pomocou dereferencie je možné meniť hodnotu, na ktorú ukazuje adresa

```c
int premenna_typu_int = 2;
// Smerníkový typ
int* adresa_premennej_typu_int = &premenna_typu_int;
// Operátor dereferencie na lavej stane
*adresa_premennej_typu_int = 3;
```
WARNING: * má dva významy - na druhom riadku je súčasťou označenia smerníkového typu, 
v treťom riadku označuje dereferenciu.


## Funkcia na zápis do premennej


```c
#include <stdio.h>
void zapis_do_premennej(int* a){
    *a = 2;
    printf("V premennej a vo funkcii je %d\n",*a);
    printf("Premenna je vo funkcii na adrese %p\n",a);
}
int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    printf("Premenna a je  na adrese %p\n",&a);
    zapis_do_premennej(&a);
    printf("V premennej a je po zapise %d\n",a);
    printf("Premennej a je  na adrese %p\n",&a);
    return 0;
}
```
[NOTE.speaker]
====
Vidíme, že program funguje podstatne lepšie a podarilo sa nám implementovať funkciu, ktorá bude manipulovať
s hodnotou premennej.
====

## Funkciu na zápis do premennej už poznáme

```c
int c = 0;
scanf("%d",&c);
```

Funkcia pre načítanie hodnoty z klávesnice zapisuje do zadanej premennej.


## Alokácia pamäte

## Druhy alokácie pamäte

- *Zásobník* (Stack) - pamäť je platná iba v určitom kontexte
- *Kopa* (Heap) - pamäť je platná všade

## Statická alokácia pamäte (v zásobníku)

Pamäť je dostupná iba v rámci jednej funkcie. 
Do ďalších funkcií sa odovzdáva kópia a vyhradí sa nová 
pamäť v zásobníku.

```c
void funkcia(int a) {
	a = 2;
}
int main(){
	int a = 1;
    funkcia(a);
}
```

## Dynamická alokácia pamäte (na kope)

Keď dopredu nevieme koľko pamät budeme potrebovať.

Napr. potrebujeme prečítať súbor po riadkoch

Pri statickej alokácii budeme vždy obmedzení 
max. veľkosťou riadku, alebo budeme veľmi  plytvať 


## Malloc

Vyhradili sme si 100 bajtov pamäte a ich adresu sme uložili do premennej `mojapamat`.

```c
void* mojapamat = malloc(100);
```

Smerník typu void* je všeobecný smerník, kotrý nehovorí na aký typ pamäte ukazuje.

## Free

```c
free(mojapamat);
```

Každú vyhradenú pamäť musíme explicitne uvoľniť pomocou free.

## Využitie dynamicky alokovanej pamäte

Na to, aby sme vedeli využiť dynamicky alokovanú pamäť, musíme zmeniť jej typ:

```c
char* poleznakov = (char*)malloc(100);
poleznakov[0] = 'a';
poleznakov[1] = 0;
free(poleznakov);
```
Smerník char* môžeme použiť ako miesto pre uloženie reťazca s veľkosťou 100 bajtov.

Koľko znakov sa zmestí do takejto pamäte?

## Ako to vyzerá v pamäti?

                       +-------------------+
    Pamäť na kope      | | | | | | | | | | | 
                       +-------------------+
    adresa:          \#10 1              \#20 
                       ^
                       |
                       +---------------------------+
                                                   |
    Pamäť na stacku                                |
                                                   |                                                |
    názov premennej:   poleznakov                  |
    typ premennej:      char*                      |
                       +--------------+            |
    hodnota:           |     10       | -----------+
                       +--------------+
    adresa:             \#100        \#108    

## Dynamicky alokovaná pamäť je dostupná iba pomocou jej adresy

Hodnota v dynamickej pamäti je dostupná pomocou operátora dereferencie `*`.

Hodnota v dynamicky alokovanom poli je dostupná pomocou operátora `[]`

## Názov poľa je adresa jeho začiatku

A ľubovoľná adresa môže byť začiatkom poľa.

(ale nemusí)

## Dynamicky alokované pole

Ak nevieme, aký dlhý riadok budeme načítavať.

Klasický spôsob načítania riadku do pamäte je obmedzený fixnou veľkosťou buffra.
Takýto program spadne, ak sa v ňom dlho nevyskytuje koniec riadka.

## Načítanie po znakoch


1. Alokujeme buffer na počiatočnú veľkosť.
1. Načítame jeden znak
1. Overíme, či nenastal koniec súboru.
1. Overíme, či máme dosť miesta v buffri. Ak nemáme dosť miesta, realokujeme buffer na novú veľkosť.
1. Zapíšeme znak do buffru. Ak je znak koniec riadka, vypíšeme ho a zapisujeme od začiatku.


## Realloc

Zmena veľkosti už alokovanej pamäte

1. Zoberie existujúcu pamäť.
1. Ak je to potrebné, tak alokuje novú pamäť.
1. Ak nie je možné alokovať novú pamäť, vráti NULL.
1. Inak vráti smerník na novú alebo starú pamäť


## Koniec


