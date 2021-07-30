# 4. Úvod do jazyka C

## História jazyka C


## Charakteristika jazyka C

- Jazyk C je silno typovaný
	- Argumenty funkcií a premenné majú presne definovaný formát uloženia v pamäti
    - Tvorba dokumentácie je jednoduchšia
    	- Každá funkcia má jasne definovaný vzťah medzi vstupom a výstupom
- Nizko úrovňový jazyk
	- Jazyk C má blízko k Assembleru, napriek tomu je 1ahko čitateľný
	- spustiteľný program je rovnako efektívny ako keby sme ho napísali priamo v strojovom kóde
- Prekladaný jazyk
	- Zdrojové texty musia prejsť procesom prekladu do strojového kódu
    - Časť chýb sa dá objaviť pred tým ako sa program spustí
    - Výsledný program je veľmi efektívny
- Ľahko prenositeľný
	- Časti závislé na architektúre sú implementované v základnej knižnici.
	

## Jazyk C je základ

Skoro všetky operačné systémy (Windows aj Linux) sú napísané v jazyku C.
Dôležité časti vyšších programovacích jazykov sú napísané v C (Python, Java).

Mikrokontroléry sa programujú v C.

Viaceré programovacie jazyky používajú syntax podobnú jazyku C:
- C++
- Java
- C sharp
- Javascript


## Ahoj Svet

```clike
#include <stdio.h>

int main(){
    printf("Hello World!\n");
}
``` 
## Proces prekladu programu a spustenia

```shell
gcc hello.c -o hello
./hello
```

## Proces prekladu 2

1. Preprocesor (direktívy include)
1. Kompilátor
1. Linker


```shell
# Preklad
gcc -c hello.c -o hello.o
# Linkovanie
gcc hello.o -o hello

# Spustenie
./hello
```
## Funkcia v jazylu C

- Jednotka kódu, ktorá je algoritmus:
	- Má jasne definovaný vstup, výstup a konečnú postupnosť krokov.
- Funkcia sa skladá z:
	- Predpis funkcie:
		- Typ návratovej hodnoty
    	- Názov
    	- Argumenty funkcie (vstup)
    - Telo funkcie (postupnosť krokov)
    	- Návratová hodnota pomocou return (výstup algoritmu)
        

## Prečo je dôležitá abstrakcia

Program je:

- kratší
- lepšie čitateľný
- lepšie sa upravuje
- je možné ho rozdeliť na moduly

Funkciu je možné:

- osobitne testovať a ladiť
- jendoducho nahradiť za inú


## Princíp DRY

Don't repeat yourself.

Funkcia je abstrakcia určitej opakujúcej sa časti.

Princíp DRY hovorí, že abstrakcia sa má použiť vždy keď je to možné.

Pozor, nie vždy to je aj rozumné, niekedy je jednoduchšie kód skopírovať a upraviť.

Nová funkcia znamená nové slovo do slovníka programu.

## Nevýhody prílišnej abstrakcie

Nová funkcia by mala predstatvovať zjednodušenie programu, nie je jeho zozložitnie.

Funkcia by mala mať vhodné meno, zlé meno funkcie kazí čitateľnosť kódu.

Nová funkcia pridáva réžiu:

- Potrebujeme pracovať s novou pamäťou.

Niekedy je vhodné kód skopírovať.



## Robot Karel v jazyku C

- Knižnica, ktorú pripojíme k prograu
- Využívame funkcie, ktoré sú definované v knižnici


```clike
// File karel.c
#include <karel.h>
  
int main(){
    turnOn("world.kw");
    turnLeft();
    pickBeeper();
    turnOff();
}
```

## Preklad programu s Robotom Karel

```shell
# Preklad - pripojí predpisy funkcií
gcc -c karel.c -o karel.o
# Linkovanie - pripojí skompilované telá funkcií
gcc karel.o libkarel32-lin.a -lcurses  -o hello

# Spustenie
./hello
```

## Systém make

Návod na zostavenie programu:

Premenné, pravidlá

Pravidlo:
	- predpoklad
    - dôsledok
    - transformácia

```makefile
# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=libkarel32-lin.a -lcurses
OUTPUT=$@.run

# if not running, try to use libkarel64-lin.a

# targets
%:
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $(OUTPUT)
```



















