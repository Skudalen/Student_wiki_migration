---
title: Smerníky
---
# Smerníky

Daniel Hládek

---
# Motivácia

Tajomstvo smerníkov je tajomstvo programovania

---
# Pamäť RAM

- vieme si ju predstaviť ako niekoľko "nádob", kam si môžme niečo
uložiť.
- každá "nádoba" má meno a číslo.
- čísla nádob idú podľa poradia.

---
# Pamäť RAM

Vytvoríme niekoľko premenných:

``` c
char znak = 'a';
char pole[``5`] = "ahoj";
```

Operačný systém určí, kde  RAM sa budú nachádzať.

---
# Pamäť RAM

    adresa:   \#10            \#15                        \#19
            +----------------------------------------------+
    obsah:  | 'a' | 4 | 5 | 'a' | 'h' | 'o' | 'j' | 0  | 5 |
            +----------------------------------------------+

    rozsah: |<--->|       |<-------------------------->| 

    typ:    char          char[`5]
    názov:  znak          pole

---
# Smerník

Adresu premennej nazývame aj **smerník**.

---
# Pamäť RAM

- Mená a typy premenných určuje programátor.
- Adresy premenných určuje operačný systém.
  - ale je možné ich zistiť a pracovať s nimi.

---
# Smerník == Adresa

- Adresa je celé číslo.
- Celé číslo si vieme uložiť do premennej.

---
# Smerníková premenná

Premenná, do ktorej si uložíme smerník.

``` c
int premenna_typu_int = 2;
int* adresa_premennej_typu_int = &premenna_typu_int;
```

---
# operátor & vráti adresu premennej

adresu si môžme poznačiť do smerníkovej premennej

---
## Smerníková premenná

    adresa:   \#10              \#15              \#19
            +--------------------------------------------+
    obsah:  | 0 | 0 | 0 | 2 | 0 | 0 | 0 | 0 | 10 | 0 | 0 |
            +--------------------------------------------+
                                           
    rozsah: |<------------->|   |<-------------->| 

    typ:    int                 int*
    názov:  premenna_typu_int   adresa_premennej_typu_int

---
#### Smerníková premenná vždy ukazuje na miesto určitého typu.

  - int\*  adresa premennej typu `int`.
  - char\* adresa premennej typu `char`.
  - void\*  ľubovoľná adresa.

---
#### Typ smerníkovej premennej môžeme ľubovoľne meniť

```c
int a = 2;
void* pa = &a;
int* ppa = (int*)pa;
```

Za behu je možné meniť dátové typy.

---
# Operátor dereferencie `*`

Vráti **hodnotu** ktorá je na adrese.


---
### Smerníkovú premennú vieme používať ako obyčajnú premennú

Ale musíme použiť operátor dereferencie

---
### Smerníkovú premennú vieme používať ako obyčajnú premennú

``` c
int premenna_typu_int = 2;
// Smerníkový typ
int* adresa_premennej_typu_int = &premenna_typu_int;
// Operátor dereferencie
printf("Tam kde ukazuje smernik je hodnota %d\n",*adresa_premennej_typu_int);
```
---
### Pomocou dereferencie je možné meniť hodnotu

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


---
# Polia a smerníky

Názov poľa je adresou jeho prvého prvku.

Ľubovoľná adresa môže byť začiatkom poľa.

---
# ZEN jazyka C

Názov poľa je adresou jeho prvého prvku.

Ľubovoľná adresa môže byť začiatkom poľa.

---
# Polia a smerníky

```c
int pole[`5] = {1,2,3,4,5};
int* zaciatok_pola = pole;
for(int i = 0; i < 5; i++){
    if (pole[`i] == zaciatok_pola[`i]){
        printf("Sicko v poriadku\n");
    }
    else {
        printf("Ta...\n");
    }
}
```
---
# Operácie so smerníkmi

  - Čo sa nachádza na vedľajšom mieste?
  - Čo sa nachádza na ľubovoľnej adrese?

---
### Smerníková aritmetika

```c
int pole[`5] = {1,2,3,4,5};
int* zaciatok_pola = pole;
int* druhe_miesto = pole + 1;
int* tretie_miesto = pole + 2;
int* piate_miesto = tretie_miesto + 2;
```

---
### Smerníková aritmetika je iný zápis [`] a &

```c
int pole[`5] = {1,2,3,4,5};
int* zaciatok_pola = &pole[`0];
int* druhe_miesto = &pole[`1];
int* tretie_miesto = &pole[`2];
int* piate_miesto = tretie_miesto[`2];
```
---
### Funkcia so smerníkovým argumentom

  - Vstupný argument funguje ako výstupný.
  - Menej kopírovania.

---
### Funkcia so smerníkovým argumentom

Môže spracovať aj reťazec:

```c
int strlen(char* str){
    int l = 0;
    while(*str != 0){
        l++;
    }
    return l;
}
```
Reťazec je pole znakov zakončené nulou.

---
### Funkcia so smerníkovým argumentom

```c
int maximum(int* pole, int sz){
    int max = -1000000;
    for (int i = 0 ; i < sz; i++){
        if (pole[`i] > max){
            max = pole[`i];
        }
    }
    return max;
}
```

---
### Funkcia so smerníkovým argumentom

Môže načítať a hlásiť výsledok načítania.

```c
int nacitaj_int(int* vysledok);
```
---
### Funkcia so smerníkovým argumentom

```c
// Vrati kladne cislo 
// ak sa nacitanie podarilo
// Ak nie vypise spravu a vrati nula
int nacitaj_int(int* vysledok){
 int r = scanf("%d",vysledok);
 if (r!=1){
     printf("Nepodarilo sa.\n");
     return 0;
 }
 return 1;
}
```
---
### Funkcia so smerníkovým argumentom

Umožňuje pracovať s ľubovoľnými dátami

```c
int compare(const void* p1,const void* p2){
    // Zmením typ smerníka
    int* pa = (int*)p1;
    int* pb = (int*)p2;
    // Skopírujem hodnoty
    int a = *pa;
    int b = *pb;
    return b - a;
}
```
---
#### Argument funkcie sa vždy kopíruje

```c
// Toto nefunguje
int nacitaj_int(int vysledok){
// Vysledok je lokalna premenna
 int r = scanf("%d",&vysledok);
 if (r!=1){
     printf("Nepodarilo sa.\n");
     return 0;
 }
 // Ked skoncim, vysledok sa zabudne
 return 1;
}
```
---
### Sme zodpovední za to, že pracujeme s vyhradenou pamäťou

```c
int pole[`5] = {1,2,3,4,5};
int* neplatne_miesto = pole + 10;
printf("Hodnota %d\ je nedefiovana, lebo adresa %p mi nepatri\n",*neplatne_miesto,neplatne_miesto);
```

---
## Sme zodpovední...

(Skoro) nikto Vás neupozorní, že pracujete s nedefinovanou hodnotou.

Len program sa správa nepredvídateľne.


---
# Sme zodpovední...

Používame Valgrind, upozorní nás na problémy s pamäťou.

---
# Valgrind je Váš priateľ

Aj keď sa veľa sťažuje....

---
# Vďaka smerníkom vieme

  - menej kopírovať.
  - používať vstupný argument na uložene výsledku.
  - vytvárať funkcie pre modifikovanie obsahu premennej.
  - vytvárať funkcie pre prácu s poľom.


