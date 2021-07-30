# Štruktúrované údajové typy

# Programovanie je modelovanie reálneho sveta

  - Porozumieť problému znamená byť schopný to vysvetliť aj mojej babke

  - Porozumieť problému znamená byť schopný ho naprogramovať

# Čo znamená auto?

![old beetle](oldbeetle.jpg)

# Čo znamená auto?

... v jazyku C

# Atribúty

Množina premenných pomocou ktorých opíšeme objekt.

| Atribút             | Typ             |
| ------------------- | --------------- |
| meno                | max. 128 znakov |
| množstvo benzínu    | reálne číslo    |
| dátum platnosti stk | dátum a čas     |

# Ako by vyzeralo auto v jazyku C

``` c
char meno[128] = "Chrobáčik";
float nadrz = 1.1;
```

# Ako by vyzeralo natankovanie auta?

1.  Zoberiem auto a benzínovú hadicu.

2.  Zvýšim množstvo benzínu v nádrži a odložím hadicu.

3.  Môžem zobrať auto a ísť preč.

# Toto nebude fungovať

# Ako by vyzeralo natankovanie auta?

... v jazyku C

# Toto nebude fungovať

``` c
void natankuj10(const char* meno,float nadrz){
    nadrz += 10;
}
```

# Toto je lepšie

``` c
void natankuj10(float* nadrz){
    *nadrz += 10;
}
```

... ale nefunguje to na celé auto

# Šrotovisko

![scrapyard By Paul brown from england - scrapyard challenge vw beetle
Uploaded by oxyman](Scrapyard_challenge_vw_beetle.jpg)

[source](https://commons.wikimedia.org/w/index.php?curid=11608494)

# Šrotovisko v jazyku C

``` c
char meno[128]]2] = {"Chrobáčik","Mucinko"};
float nadrz[2] = {0.0, 0.0};
```

# Ako by sme spracovali viac áut?

# Ako by sme spracovali viac áut?

    void recykluj(const char** meno[2], float* nadrz[2]){
        printf("Oh....\n");
    }

# Súvisiace atribúty by mali byť spolu

# Nový dátový typ - Štruktúra

``` c
struct auto {
    char meno[128];
    float nadrz;
}
```

# Čo je štruktúra

  - vyjadruje určitý pojem.

  - nový, nami definovaný dátový typ.

  - slúži ako "šablóna" pre opísanie skupiny podobných objektov.

# Nové štruktúrované auto

  - deklarácia (štruktúry)

  - definícia (konkrétneho auta)

# Deklarácia auta

(môže ísť do "auto.h")

``` c
struct car {
    char meno[128];
    float nadrz;
};
```

# Definícia auta

``` c
#include "auto.h"

int main(){
    struct car ke123ab = {
        .nadrz = 2.3,
        .meno = "Chrobáčik"
    };
}
```

# Inicializácia štruktúry po častiach

``` c
#include "auto.h"
#include <string.h>

int main(){
    struct car ke123ab;
    ke123ab.nadrz = 2.3;
    strcpy(ke123ab.name,"Chrobáčik");
}
```

# Operátor bodka

Slúži na modifikáciu členov štruktúry

# Nový dátový typ vieme používať viac krát

``` c
#include "auto.h"
#include <string.h>

int main(){
    struct car zle_auto;
    struct car prazdne_auto;
    memset(&prazdne_auto,0,sizeof(struct car));
}
```

# Odovzdávanie štruktúry kópiou

``` c
void kukni_auto(struct car dake_auto){
    printf("Páči sa mi %s\n",dake_auto.name);
    printf("V nádrži má až %f l benzínu.\n",dake_auto.nadrz);
}
```

# Odovzdávanie štruktúry adresou

``` c
void natankuj10(struct car* dake_auto){
    (*dake_auto).nadrz += 10;
}
```

Operátor `*` slúži na získanie hodnoty z adresy

# Operátor →

``` c
void natankuj10(struct car* dake_auto){
    dake_auto->nadrz += 10;
}
```

# Pole štruktúr

``` c
struct car viacaut[2];
```

# Inicializácia poľa štruktúr

``` c
struct car viacaut[2];
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

# Inicializácia poľa štruktúr

``` c
struct car viacaut[2];
memset(&viacaut,0,sizeof(s) * 2);
```

# Odovzdanie poľa štruktúr

``` c
void natankuj_auta(struct car* prve_auto, int pocet_aut){
    for (int i = 0; i < pocet_aut; i++){
        prve_auto[i].nadrz += 10;
    }
}
```

# Názov poľa je adresa prvého prvku

Ľubovoľná adresa môže byť začiatkom poľa

# Príklad - Reprezentácia času

# Reprezentácia času

  - Pomocou celého čísla `time_t`

  - Pomocou štruktúry `struct tm`

# Reprezentácia času pomocou celého čísla

  - Celé číslo `time_t`

  - Počet milisekúnd sekúnd od 1.1.1970

<http://currentmillis.com/>

# Výhody času pomocou celého čísla

Vieme ľahko robiť aritmetické operácie (pripočítavať a odpočítavať
časové intervaly)

    Dnes je:    1519650881023
    Nový Rok bol: 1514761200000

    Rozdiel:         4 889 681 023

Koľko je to hodín?

# Nevýhoda

  - Integer overflow;
    
      - Problém roku 2000, roku 2038

  - Ťažká zrozumiteľnosť pre človeka.

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

# Śtruktúrovaný čas

  - deň

  - mesiac

  - rok

  - hodina

  - sekunda

  - deň v týždni

# Śtruktúrovaný čas: struct tm

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

# Operácie s časom

  - void time(time\_t\*)  
    aktuálny čas `time_t`.

  - struct tm\* localtime(time\_t\*)  
    konverzia `time_t` na `struct tm`.

  - const char\* asctime(struct tm\*)  
    konverzia `struct tm` na reťazec.

<http://www.cplusplus.com/reference/ctime/>

# Aktuálny čas

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

# Bonus: Enumerátory

Dátový typ pre obmedzený počet hodnôt.

``` c
enum days {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

enum months {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};
```

# Zhrnutie

  - Štruktúrovaným typom opisujeme skupinu podobných objektov.

  - Štruktúra sa skladá z atribútov.

  - Každý atribút má svoj dátový typ, môže to byť aj iná štruktúra.

  - Na prístup k atribútom používame operátor `.` alebo `→`.

  - Aj štruktúru treba inicializovať.

# Štruktúra je Váš dátový typ

# Koniec
