# Textovo grafické rozhranie

---
# Znaky vykresľujeme ako grafiku

---
# Grafické terminálové aplikácie

---
# Pozrite si bežiace procesy

- top

---
# Ovládnite Vaše súbory

Midnight Commander

- mc

---
# Web a e-mail v termináli

- mutt
- links

---
# Adventure of &

- nethack
- rogue

---
# Vytvorme si svoju hru

Veď terminál je 2D pole znakov

---
# Knižnica ncurses

- Stará ale jará
- Pracuje s textovým terminálom v "grafickom" móde

---
# Curses používa globálne premenné

Premenné, ktoré nevidno, ale ovplyvňujú stav.

---
```c
#include <curses.h>
int main(){
   // Vytvorí globálne premenné
   initscr();
   // Tu píšete program 
   // Vráti terminál do pôvodného stavu
   endwin();
}
```
---
# Terminál je dvojrozmerné pole

LINES - počet riadkov
COLS - počet stĺpcov

---
# Grafický terminál

      0,0              COLS-1, 0
          +---------------+
          |               |
          |               |
          |               |
          |               |
          +---------------+
    LINES-1,0        LINES-1,COLS-1

---
# Kreslenie znakov

Tak isto ako `printf`, ale zadávame aj pozíciu

```c
void mvprintw(int row,int col,const char* msg, printf format...);
```

---
# Obnova terminálu

Vypísané znaky je potrebné vykresliť:

```
void refresh();
```

---
# Vstup

```c
int getch();
```

Vráti kód stlačenej klávesy

---
# Nastavenie vstupu

```c
noecho(); // Nevypisuj vstup na obrazovku
cbreak(); // Zabudni starý vstup
nodelay(stdscr,TRUE); // Nečakaj na stlačenie
keypad(stdscr,TRUE); // Aktivuje šípky
curs_set(FALSE); // Neviditeľný kurzor
```

---
# Časovanie


```c
#include <unistd.h>

int usleep(useconds_t usec);
```

---
# Farby


Farby je potrebné inicializovať na začiatku

---
# Inicializácia farebnosti

```c
has_colors(); // Zistenie či terminál podporuje farby
start_color();
	```
---
# Inicializácia konkrétnej farby

```c
init_pair(1, COLOR_RED, COLOR_BLACK);
```

Zadáme číslo farby v programe, farbu písma, farbu pozadia.

---
# Použitie farby

```c
attron(COLOR_PAIR(1)); // Zapnem farbu
mvprintw(LINES/2,COLS/2,"Ahoj farba"); // Píšem farebne
attroff(COLOR_PAIR(1)); // Vypnem farbu
```

---
# Kompilovanie programu

K programu treba pripojiť dynamickú knižnicu curses 

```
gcc program.c -lcurses -o ./program
```

---
# Generovanie náhodných čísel

---

```c
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  srand(time(NULL));
  int a = 10;
  int b =  20;
  int r = a + rand() % (b-a);
  printf("Nahodne cislo z intervalu od %d do %d je %d",a,b,r);
  return 0;
}
```

---
# Zhrnutie

- Pomocou knižnice `curses` vieme pracovať s terminálom ako by to bol obrázok. 
- Terminál je dvojrozmerné pole znakov
- Klávesy a farby sú zakódované ako konštanty v [curses.h](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html)


