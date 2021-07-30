---
title: Štruktúrované údajové typy
published: true
visible: true
---
# Štruktúrované údajové typy

---
### Obsah

- Štruktúry;
- Polia štruktúr;
- Čas a dátum;
- Enumerátory.

---
### Programovanie je modelovanie reálneho sveta

---
## Nájdem skupinu premenných ktoré opisujú stav objektu

- dá sa to využiť v databáze,
- "auto" sa prenesie do virtuálneho sveta.

---
### Staré auto

![beetle](./oldbeetle.jpg)

---
# Atribúty

---

| Atribút             | Typ             |
| ------------------- | --------------- |
| množstvo benzínu    | reálne číslo    |
| vek                 | reálne číslo    |
| stav tachometra     | celé číslo      |
| dátum platnosti stk | dátum a čas     |

---
# Má Vaše auto meno?

---
# Ako by vyzeralo auto v jazyku C

``` c
char meno[`128] = "Chrobáčik";
float nadrz = 1.1;
```

---
# Ako by vyzeralo natankovanie auta?

1.  Zoberiem auto a benzínovú hadicu.
2.  Zvýšim množstvo benzínu v nádrži a odložím hadicu.
3.  Môžem zobrať auto a ísť preč.

---

[Toto nerobte...](https://youtu.be/2xjINRdfezE?t=60)

---
# Ako by vyzeralo natankovanie auta?

... funkcia v jazyku C modifikuje atribút

---

Musíme použiť smerníkovú premennú aby sa zmena nezabudla...

``` c
void natankuj_nadrz(float* nadrz,float benzin){
    *nadrz += benzin;
}
```

---
# A ako spracujeme viac áut?

---
### Šrotovisko

![scrapyard By Paul brown from england - scrapyard challenge vw beetle
Uploaded by oxyman](Scrapyard_challenge_vw_beetle.jpg)

[source](https://commons.wikimedia.org/w/index.php?curid=11608494)

---

[Spravovanie viacerých áut naraz](https://youtu.be/_rZaLlP7kTU)

---
# Spracovanie viacerých áut naraz

``` c
char meno[`128]]`2] = {"Chrobáčik","Mucinko"};
float nadrz[`2] = {0.0, 0.0};
```

---
# Ako by sme spracovali viac áut?

```c
void recykluj(const char* mno[`128], float* nadrz,int pocet_aut){
    printf("Oh....\n");
}
```

---
### Ako triediť viac záznamov?

---
# Súvisiace atribúty by mali byť spolu

---
# Vlastný dátový typ - Štruktúra auto

``` c
struct auto {
    char meno[`128];
    float nadrz;
};
```

---
# Čo je štruktúra

- vyjadruje určitý pojem.
- nový, nami definovaný dátový typ.
- slúži ako "šablóna" pre opísanie skupiny podobných objektov.

---
# Nové štruktúrované auto

- deklarácia (štruktúry) - vysvetlíme pojem "auto".
- definícia (konkrétneho auta) - opíšeme konkrétne auto.

---
### Deklarácia auta

(môže ísť do "auto.h")

``` c
#ifndef _AUTO_H
#define _AUTO_H

struct car {
    char meno[`128];
    float nadrz;
    int tachometer;
};
#endif
```

---
### Nová premenná

``` c
#include "auto.h"

int main(){
    struct car ke123ab;
    // Hhodnota premennej nie je definovaná
    return 0;
}
```

---
### Premennú treba vždy inicializovať

``` c
#include "auto.h"
#include <string.h>

int main(){
    struct car prazdne_auto;
    memset(&prazdne_auto,0,sizeof(struct car));
}
```

---
### Operátor bodka

Slúži na modifikáciu členov štruktúry

---
### Inicializácia štruktúry po častiach

``` c
#include "auto.h"
#include <string.h>

int main(){
    // Nové nedefinované auto
    struct car ke123ab;
    ke123ab.nadrz = 2.3;
    strcpy(ke123ab.name,"Chrobáčik");
    ke123ab.tachometer = 123;
}
```

---
### Štruktúra auto je obyčajný dátový typ

``` c
// Pri volani sa vytvára kópia
void kukni_auto(struct car dake_auto){
    printf("Páči sa mi %s\n",dake_auto.name);
    printf("V nádrži má až %f l benzínu.\n",dake_auto.nadrz);
}
```

---
### Funkcia pre modifikáciu člena štruktúry

``` c
void natankuj10(struct car* dake_auto){
    (*dake_auto).nadrz += 10;
}
```

Operátor `*` slúži na získanie hodnoty z adresy

---
### Operátor `->`

Získa hodnotu atribútu zo smerníkovej premennej

``` c
void natankuj10(struct car* dake_auto){
    dake_auto->nadrz += 10;
}
```

---
### Pole štruktúr

``` c
struct car viacaut[`2];
```

---
### Inicializácia poľa štruktúr

``` c
struct car viacaut[`2];
viacaut = { {
        .meno = "Chrobáčik",
        .nadrz = 12.3
    },
    {
        .meno = "Mucinko",
        .nadrz = 9.2
    }
};
```
---
### Inicializácia poľa štruktúr

``` c
struct car viacaut[`2];
memset(&viacaut,0,sizeof(s) * 2);
```

---
### Spracovanie poľa štruktúr

``` c
void natankuj_auta(struct car* prve_auto, int pocet_aut){
    for (int i = 0; i < pocet_aut; i++){
        prve_auto[`i].nadrz += 10;
    }
}
```

---
### Názov poľa je adresa prvého prvku

Ľubovoľná adresa môže byť začiatkom poľa

---
### Triedenie poľa štruktúr

``` c
int porovnaj_tachometer(const void* a1,const void* a2){
    // Premeníme vsšobecný smerník na smerník na štruktúru
    struct auto* aa1 = (struct auto*)a1;
    struct auto* aa2 = (struct auto*)a2;
    return aa1->tachometer - aa2->tachometer;
}
void zotried_auta(struct car* prve_auto, int pocet_aut){
    qsort(prve_auto,pocet_aut,sizeof(struct auto),porovnaj_tachometer);
}
```
---
# Ako by ste naprogramovali "čas"?



---
### Reprezentácia času

- Pomocou celého čísla `time_t`;
- Pomocou štruktúry `struct tm`;
- pomocou reťazca 'const char[SIZE]'.

---
### Reprezentácia času pomocou celého čísla

- Celé číslo `time_t`;
- Počet milisekúnd sekúnd od 1.1.1970.

<http://currentmillis.com/>

---
### Typedef

```c
typedef  unsigned long int time_t;
```

- Vytvoríme alias pre existujúci dátový typ.
- Názov aliasu hovorí niečo o tom ako máme rozumieť obsahu premennej.

---
### Výhody času pomocou celého čísla

Vieme ľahko robiť aritmetické operácie (pripočítavať a odpočítavať
časové intervaly)

    Dnes je:    1519650881023
    Nový Rok bol: 1514761200000

    Rozdiel:         4 889 681 023

Koľko je to hodín?

---
### Nevýhoda

  - Integer overflow;
      - Problém roku 2000, roku 2038
  - Ťažká zrozumiteľnosť pre človeka.

---
## Integer overflow

``` c
int main(){

    char c = 0;
    for (int i = 0; i < 1000; i++){
        c = c + 1;
    }
    printf("Hodnota v premennej c je %d",c);
    return 0;
}
```

---
## Štruktúrovaný čas

  - deň
  - mesiac
  - rok
  - hodina
  - sekunda
  - deň v týždni

---
### Štruktúrovaný čas

`time.h`:

``` c
struct tm {
   int itm_sec      // seconds after the minute 0-60*
   int tm_min       // minutes after the hour   0-59
   int tm_hour      // hours since midnight 0-23
   int tm_mday      // day of the month 1-31
   int tm_mon       // months since January 0-11
   int tm_year      // years since 1900
   int tm_wday      // days since Sunday    0-6
   int tm_yday      // days since January 1 0-365
   int tm_isdst     // Daylight Saving Time flag
};
```

---
# Operácie s časom

- `void time(time_t*)` aktuálny čas `time_t`.
- `struct tm* localtime(time_t*)`  konverzia `time_t` na `struct tm`.
- `const char* asctime(struct tm*)` konverzia `struct tm` na reťazec.

<http://www.cplusplus.com/reference/ctime/>

---
### Aktuálny čas

<http://www.cplusplus.com/reference/ctime/localtime/>

``` c
#include <stdio.h>
#include <time.h>

int main () {
  time_t rawtime;
  struct tm *timeinfo;
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  printf ("Current local time and date: %s", asctime(timeinfo));
  return 0;
}
```
---
### Bonus: Enumerátory

Dátový typ pre obmedzený počet hodnôt.

``` c
enum days {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

enum months {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};
```

---
# Zhrnutie

  - Štruktúrovaným typom opisujeme skupinu podobných objektov.
  - Štruktúra sa skladá z atribútov.
  - Každý atribút má svoj dátový typ, môže to byť aj iná štruktúra.
  - Na prístup k atribútom používame operátor `.` alebo `->`.
  - Aj štruktúru treba inicializovať.

