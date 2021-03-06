# 5. Testovanie a Cézarova šifra

## 5. Testovanie a Cézarova šifra

http://it4kt.cnl.sk/c/pvjc/2018/labs.05.html[Vypracujte tutoriál č. 5]

Postup:

1. Stiahnite si kostru zadania č. 2 a pripravte si ju do priečinka ps2 vo Vašom GIT repozitári
1. Skopírujte hlavičkové súbory bmp.h a playfair.h do prislúchajúcich c súborov
        
        cp bmp.h bmp.c
        cp playfair.h playfair.c

1. Upravte c súbory tak, aby obsahovali prázdne telá funkcie a pridajte direktívy pre vloženie hlavičiek.    
```c
#include "playfair.h"

char* playfair_decrypt(const char* key, const char* text){
    return NULL;
}
```
+
1. Vytvorte kostru súboru main.c.
```c
#include "bmp.h"
#include "playfair.h"

int main(){
    // Tu mozte písat program
    return 0;
}
```
+
1. Vytvorte Makefile pre zostavenie projektu.
```Makefile
CFLAGS=-std=c11 -Werror -Wall -lm

all: ps2

ps2: main.o playfair.o bmp.o
    gcc $(CFLAGS) main.o playfair.o bmp.o -o ps2

%.o: %.c
    gcc $(CFLAGS) -c $< -o $@
```
+
1. Do hlavičkového spboru bmp.h pridajte predpis funkcie pre Cézarovu šifru.

```c
char* caesar_encrypt(const char* text, int step);
```
+
1. Do bmp.c pridajte implementáciu Cézarovej šifry.
        
```c
char* caesar_encrypt(const char* text, int step){
    int sz = strlen(text);
    char* res = malloc(sz + 1);
    memcpy(res,text,sz +1);
    // Každý znam v res posunte o step, ale dávajte pozor aby ste nevybehli mimo abecedy
    // Vyuzite operator %
    return res;
}
```
+
1. Vytvorte c súbor s testom:
    
```c
#include "bmp.h"
#include <stdio.h>
#include <assert.h>

// Tu pisete funkcie s testami

int main(){
    printf("Tests started...\n");
    // Tu volate Vase testy
    printf("All tests passed\n");
    return 0;
}
```
+
1. Pridajte cieľ do Makefile pre zostavenie a spustenie testu
        
```Makefile
tests: tests_bmp.o bmp.o
    gcc $(CFLAGS) tests_bmp.o bmp.o -o tests
    ./tests
```
+
1. Implementujte testy. Využite funkciu assert, ktorá predčasne ukončí program v prípade, že nie je splnená podmienka



### Doplnkové informácie

- link:danotr.c/highlight[Zdrojový kód tr]
- https://sk.wikipedia.org/wiki/C%C3%A9zarova_%C5%A1ifra
- http://nlp.web.tuke.sk/zap/prednasky/09Tr/[Prednáška z minulého semestra] na tému Cézarova šifra
- https://cs.wikipedia.org/wiki/Vigen%C3%A8rova_%C5%A1ifra[Vigenerova šifra]
- https://cs.wikipedia.org/wiki/Playfairova_%C5%A1ifra[Playfairova šifra]

