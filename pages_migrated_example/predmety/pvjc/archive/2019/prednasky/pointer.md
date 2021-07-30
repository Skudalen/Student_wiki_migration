# 2\. Smerník

# Motivácia

Tajomstvo smerníkov je tajomstvo programovania

# Pamäť RAM

  - vieme si ju predstaviť ako niekoľko "nádob", kam si môžme niečo
    uložiť.

  - každá "nádoba" má meno a číslo.

  - čísla nádob idú podľa poradia.

# Pamäť RAM = Mankala

# Pamäť RAM

``` c
char znak = 'a';
char pole[5] = "ahoj";
```

# Pamäť RAM

    +----------------------------------------------+
    | 'a' | 4 | 5 | 'a' | 'h' | 'o' | 'j' | 0  | 5 |
    +----------------------------------------------+
    meno premennej:
    znak            pole
    typ premennej:
    char            char[5]
    adresa:
    \#10            \#15                        \#19

# Smerník

Adresu premennej nazývame aj **smerník**.

# Pamäť RAM

  - Mená a typy premenných určuje programátor.

  - Adresy premenných určuje operačný systém.
    
      - ale je možné ich zistiť a pracovať s nimi.

# Operácie so smerníkmi

  - Aká je adresa premennej?

  - Čo sa nachádza na vedľajšom mieste?

  - Čo sa nachádza na ľubovoľnej adrese?

# Adresa premennej - operátor &

``` c
int premenna_typu_int = 2;
int* adresa_premennej_typu_int = &premenna_typu_int;
```

# Smerník je premenná

Smerník vždy ukazuje na určitý typ.

  - int\*  
    adresa premennej typu `int`.

  - char\*  
    adresa premennej typu `char`.

  - void\*  
    ľubovoľná adresa.

## Smerník je premenná

    názov premennej:   premenna_typu_int
    typ premennej:      int
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

# Operátor dereferencie `*`

Vráti **hodnotu** ktorá je na adrese.

``` c
int premenna_typu_int = 2;
// Smerníkový typ
int* adresa_premennej_typu_int = &premenna_typu_int;
// Operátor dereferencie
printf("Tam kde ukazuje smernik je hodnota %d\n",*adresa_premennej_typu_int);
```

# Dereferencia \* na ľavej strane výrazu

Pomocou dereferencie je možné meniť hodnotu, na ktorú ukazuje adresa

``` c
int premenna_typu_int = 2;
// Smerníkový typ
int* adresa_premennej_typu_int = &premenna_typu_int;
// Operátor dereferencie na lavej stane
*adresa_premennej_typu_int = 3;
```

<div class="warning">

`*` má dva významy - na druhom riadku je súčasťou označenia smerníkového
typu, v treťom riadku označuje dereferenciu.

</div>

# Funkcia so smerníkovým argumentom

  - Vstupný argument funguje ako výstupný.

  - Menej kopírovania.

# Funkcia so smerníkovým argumentom

``` c
int c = 0;
scanf("%d",&c);
```

Funkcia pre načítanie hodnoty z klávesnice zapisuje do zadanej
premennej.

# Argument funkcie sa vždy kopíruje

Priradenie vytvára novú kópiu hodnoty.

``` c
void zapis_do_premennej(int a){
    a = 2;
}
```

# Polia a smerníky

Názov poľa je adresou jeho prvého prvku.

Ľubovoľná adresa môže byť začiatkom poľa.

# Zhrnutie

Pamäť si vieme predstaviť ako množinu nádob.

  - nádoba má veľkosť 1 bajt

  - nádoba má svoje meno

  - nádoba má svoje číslo (adresu)

# Vďaka smerníkom vieme

  - menej kopírovať.

  - používať vstupný argument na uložene výsledku.

  - vytvárať funkcie pre modifikovanie obsahu premennej.

# Koniec

# Príklad

## Adresa premennej

<div class="note">

%p je formátovací znak pre adresu

</div>

``` c
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

## Argument funkcie sa vždy kopíruje

``` c
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

<div class="note">

Zistili sme, že program nefunguje podľa očakávania. Dôvodom je to, že v
jazyku C sa argumenty odovzdávajú vždy kópiou.

</div>

## Funkcia na zápis do premennej

``` c
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

<div class="note">

Vidíme, že program funguje podstatne lepšie a podarilo sa nám
implementovať funkciu, ktorá bude manipulovať s hodnotou premennej.

</div>

## Funkcia na prácu s poľom

``` c
#include <stdio.h>

void male_a_na_velke_A(char* retazec){
   while (*retazec != 0){
        if (*retazec == 'a'){
            *retazec = 'A';
        }
        retazec += 1;
   }
}
int main(){
    char retazec[] = "ahoj";
    puts(retazec);
    putc('\n');
    male_a_na_velke_A(retazec);
    puts(retazec);
    putc('\n');
    return 0;
}
```
