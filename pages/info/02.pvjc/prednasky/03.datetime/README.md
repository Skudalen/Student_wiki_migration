# 3. Reprezentácia času  a modulárne programovanie

## Organizačné pokyny

- Zadanie č. 1
- Máte 2 týždne na vypracovanie
- Začnite hneď - pripravte si otázky na cvičenie
- Korekcie po termíne nebudú akceptované.

## Modulárne programovanie


## Modulárne programovanie

Náš program s telefónnym zoznamom sa nám rozrástol.
Pomohlo by, keď si ho rozdelíme na menšie časti.

## Prečo programovať modulárne?

- *Čitateľnosť*: Súbor so zdrojovým kódom môže mať veľa riadkov a je ťažké sa v ňom orientovať
- *Návrh*: - každý modul môžeme navrhnúť osobitne.
- *Testovanie*: Moduly môžu byť testované osobitne.

## Prečo programovať modulárne?

- *Znovupoužiteľnosť*: Niektoré moduly môžeme použiť v iných projektoch
- *Zapuzdrenie*: Oddelenie rozhrania a implementácie: pre "používateľa" je viditeľné iba 
   rozhranie (deklarácie funkcií), ale nevidí ich definíciu.
  
## Modulárne programovanie v praxi

image::ISS_configuration_2017-06_en.svg[Author: NASA and various Wikimedia editors including Colds7ream, Fritzbox and Johndrinkwater.derivative work: Trex2001 (talk) – ISS Configuration as of August 2016.svg, Voľné dielo, https://commons.wikimedia.org/w/index.php?curid=61056806]

## Ako programovať modulárne

- Funkcia môže slúžiť ako "najmenšia funkčná jednotka"
- Množina funkcií môže slúžiť ako modul.
- Využijeme, že je možné oddeliť deklaráciu a definíciu funkcie.

## Deklarácia a definícia

Deklarácia a definícia funkcie sú dve rozdielne veci.

[%header]
|===
| Deklarácia 	| Definícia	
| *TUKE* 		| Technická univerzita v  Košiciach
|===

## Deklarácia a definícia funkcie


[%header,cols=2*]
|===
| Deklarácia 	  
| Definícia	

| `void pozdrav();` 
| 
void pozdrav() {
	printf("Ahoj svet\n");
}
|===

## Deklarácia funkcie

Predpis fukcie:

- Meno funkcie
- Návratová hodnota
- Zoznam argumentov a ich typov.

```c
float pow(float arg);
```

## Definícia funkcie

- Musí vyhovovať deklarácii
- Definuje telo funkcie


Funkcia môže mať nejaké vedľajšie efekty, napr. výstup na obrazovku alebo čítanie zo súboru.

```c
float pow(float arg){
	return arg * arg;
}
```


## Proces zostavenia programu

1. Preprocesor - vyhodnotí direktívy preprocesora
1. Kompilátor - skompiluje zdrojové kódy
1. Linker - poskladá skompilované zdrojové kódy a knižnice a vytvorí spustiteľný súbor.

## Proces zostavenia programu

image::build.svg[build]



## Tvorba modulu

Pomocou preprocesora oddelíme deklaráciu a definíciu do osobitného súboru.

matik.h

```c
float pow(float arg);
float plus(float a,float b);
```
matik.c
```c
#include "matik.h"

float pow(float arg){
	return arg * arg;
}
float plus(float a,float b);
	return a + b;
}
```
## Zabránenie viacnásobnému pripojeniu

Hlavičkový súbor by mal byť preprocesorom pripojený práve raz

Definícia sa pripojí iba vtedy ak nie je definované nejaké makro.

```c
#ifndef _MATIK_H
#define _MATIK_H

float pow(float arg);
float plus(float a,float b);

#endif
```

## Preprocesor pripojí hlavičkové súbory pred prekladom

	gcc -E matik.c -o matik-pre.c

```c
float pow(float arg);
float plus(float a,float b);

float pow(float arg){
	return arg * arg;
}
float plus(float a,float b);
	return a + b;
}
``` 
## Vyhľadávanie hlavičkových súborov

Vyhľadáva v systémových priečinkoch

```c
#include <stdio.h>
```

Vyhľadáva v aktuálnom adresári

```c
#include "matik.h"
```

## Využitie modulu

1. Pripojíme hlavičkový súbor
2. Prilinkujeme objektový súbor

```c
#include "matik.h"
int main() {
	float vysledok = plus(2.0,3.0);
	printf("%f\n",vysledok);
	return 0;
}
```

## Zostavenie pomocou gcc


1. Pre každý zdrojový súbor: *Preprocesor a kompilátor*

		gcc -c matik.c -o matik.o
    	gcc -c main.c -o main.o
        
   Pripojí všetky hlavičkové súbory a vytvorí `.o` súbor. Vytvorenie `.o` súboru aktivujeme prepínačom `-c`.

1. Pre všetky objektové súbory: *Linker*
		
        gcc main.o matik.o -o matik

   Zoberie všetky `.o` súbory a vytvorí spustiteľný súbor.
      

## Zostavenie pomocou make

Pre každý .c súbor definujeme pravidlo pre vytvorenie objektového súboru.

Definujeme pravidlo pre spojenie všetkých objektových súborov.

## Pravidlo makefile

	vysledok: predpoklady
		ako z predpokladov spravím výsledok

```Makefile
all: matik

matik.o: matik.c
	gcc -c matik.c -o matik.o

main.o: main.c
	gcc -c main.c -o main.o

matik: main.o matik.o
    gcc main.o matik.o -o matik
```

## Reprezentácia času

## Reprezentácia času

- Pomocou celého čísla
- Pomocou štruktúry

## Reprezentácia času pomocou celého čísla

Počet milisekúnd sekúnd od 1.1.1970

Koľko milisekúnd od vtedy ubehlo?

http://currentmillis.com/


## Výhody času pomocou celého čísla

Vieme ľahko robiť aritmetické operácie (pripočítavať a odpočítavať časové intervaly)
	
    Dnes je: 	  1519650881023
    Nový Rok bol: 1514761200000

    Rozdiel:		   4 889 681 023

Koľko je to hodín?


## Nevýhoda

- Integer overflow
-- Problém roku 2000, roku 2038
- Ťažká zrozumiteľnosť pre človeka

## Integer overflow

```c
int main(){

    char c = 0;

    for (int i = 0; i < 1000; i++){
        c = c + 1;
    }

    printf("Hodnota v premennej c je %d",c);
	
    return 0;
}
```

## Reprezentácia času pomocou štruktúry

Pomocou štruktúry vieme reprezentovať dátum a čas podobným spôsobom
ako to robí človek.

- deň
- mesiac
- rok
- hodina
- sekunda
- deň v týždni


## Reprezentácia času pomocou štruktúry v time.h

```c
struct tm {
   int itm_sec		// seconds after the minute	0-60*
   int  tm_min		// minutes after the hour	0-59
   int tm_hour		// hours since midnight	0-23
   int tm_mday		// day of the month	1-31
   int  tm_mon		// months since January	0-11
   int tm_year		// years since 1900	
   int tm_wday		// days since Sunday	0-6
   int tm_yday		// days since January 1	0-365
   int tm_isdst     // Daylight Saving Time flag
};
```

## Enumerátory

Reprezentácia mesiacov a dní v týždni.

Dátový typ pre obmedzený počet hodnôt.

    enum days {
        MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
    };

    enum months {
        JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
    };


## Operácie s časom

- Času na reťazec 
- konverzia reťazca na čas.
- Unix time na štruktúru tm
- śtruktúra na unix time

http://www.cplusplus.com/reference/ctime/


## Aktuálny čas

http://www.cplusplus.com/reference/ctime/localtime/

```c
#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);
  printf ("Current local time and date: %s", asctime(timeinfo));

  return 0;
}
```


## Koniec


