# Nápady na zadania
:toc:

Možno podľa http://prog.dcs.fmph.uniba.sk/

https://www.w3resource.com/c-programming-exercises/linked_list/index.php

https://github.com/exercism/c
 
## Triviálne príklady

- Funkcia na delenie
- Vyber hodnotu z poľa
- Načítaj do štruktúry
- Hádaj číslo na ktoré myslím
- Automatická kocka (generovanie a zobrazovanie náhodných čísel - ako na kocke)
- Riešenie kvadratických rovníc
- Riešenie objemu gule
- Obsah trojuholníka
- Počet samohlások v texte
- Vyhoď čísla z textu



## Dátové štruktúry

### Unigramová pravdepodobnosť

Slov z štandardného vstupu


### Telefónny zoznam

Na vstupe: zoznam osôb

Na výstupe: zoznam osôb zotriedený podľa priezviska


Spojkový zoznam https://www.w3resource.com/c-programming-exercises/linked_list/index.php

### O Týždeň

Vstup: Zoznam dátumov

Výstup: Zoznam dátumov posunutý o týždeň

### Krasokorčuliarska porota:

Vstup: Zoznam čísel (hodnotení)

Výstup: Zoznam čísel bez maxima a minima.

Maximum a mimimum. Maxím a mimím môže byť viac za sebou.

### Slovník slov

Vstup zoznam slov

Výstup zoznam slov zotriedený podľa abecedy


## Algoritmické úlohy

### Cézarova šifra

Implementujte program na lámanie Cézarovej šifry (pomocou frekvenčnej analýzy). 

### Matikár

Problém A:

https://icpc.baylor.edu/download/worldfinals/problems/2010-icpc-dress-rehearsal.pdf

Napíšte program na kontrolu vypracovaných úloh z matematiky.

Úloha je zadaná na jednom riadku, vo formáte:

CISLO OPERACIA CISLO = VYSLEDOK

Napíšte program, ktorý skontroluje výsledok matematickej operácie
a napíše:

- OK, ak je výsledok správny
- ZLE, ak je výsledok nesprávny
- CHYBA ZAPISU, ak bol príklad zadaný neprávne.

Počítajte s operáciami + - * /
a číslami zadanámi na max. 5 desatinných miest.


### ASCII Art

Napíšte vaše iniciály pomocou ASCII Artu. Veľkosť písmen nech je najmenej 7 znakov.

BONUS: Nech je veľkosť písmen meniteľná od 7 do 17 na základe argumentu príkazového riadka

BONUS: Využite cykly a funkcie


### Mená stupníc

Problém A
podľa https://icpc.baylor.edu/download/worldfinals/problems/2012-icpc-dress-rehearsal.pdf

Mená stupníc

Napíšte alternatívne meno hudobne stupnice ak existuje.

Napr:

C# (cis) dur je to isté ako Db (des) dur.

E# mol neexistuje



### Antik telka

Problem F

Na zadanej štvorcovej virtuálnej klávesnici pohybujeme kurzorom pomocou 4 šípok.
Na začiatku sa kurzor nachádza v ľavom hornom rohu.

Vstup:

Rozmer klávesnice
Riadky Klávesnice
text

Výstup

počet stlačení kurzorových kláves potrebných na napísanie slova

### Benchmark

Otestujte rýchlosť Vášho triediaceho algoritmu na náhodne generovanom poli celých číslel
veľkosti n.

## Matematické úlohy:

Vyžadujú mierne znalosti z matematiky

### Bitcoin Burza

Podľa:

https://icpc.baylor.edu/worldfinals/problems/icpc2015.pdf
Problem A

Model je daný parametrami p, a, b, c, d: 

Nezávislá premenná je k

	price(k) = p * (sin (a * k + b ) + cos (c * k + d) + 2 )

Aký je maximálny pokles ceny v zadanom čase?


### Mliekárenský Startup

Podľa:

https://icpc.baylor.edu/worldfinals/problems/icpc2015.pdf

Problem D


Narežte kockový kus deravého syra na časti, ktoré vážia rovnako.

Vstup:

Počet dier a počet kusov
Pozícia a rozmer guľovej diery

Výstup:

Pozície rezov


### Prvočísla - faktoriál, fibonacci..

Implementujte čo najefektívnejší program na hľadanie všetkých prvočísel menších 
ako zadané číslo.


### Gaussova eliminačná metóda

### Horolezecký algoritmus - aké je maximum zadanej n-rozmernej funkcie?

## Textová hra: 

### Chamurapi

Implementujte Chamurapi

### Piškôrky

Immplementujte hru piškôrky a automatického protihráča:

- Ak protihráč hrá náhodne
- Ak Protihráč začína
- Ak protiháč hrá druhý
- Na väčšom poli ako je 3 x 3

### Lode

Implementujte hru lode

Hráč A na dvojrozmernom poli náhodne rozmiestni svoje lode tak aby sa nedotýkali.

Hráč B háda, kde sa lode nachádzajú.

### Mastermind (Logik)

Textová hra logik




## Zadania na CURSES:

### Rubíkova kocka

Niečo ako

https://github.com/calebabutler/nrubik

### Night Driver

Jednoduchá závodná hra.

Vykresli okraje cesty a auto
 
šoféruj tak, aby auto nenarazilo do kraja cesty.

### Game of Life

Implementujte Game of Life

### Zadanie 3 Snake Master

Úloha:

Vytvorte implementáciu klasickej hry ["Snakes"](https://en.wikipedia.org/wiki/Snake_\(video_game\)), ktorú poznáte zo starých mobilných telefónov. Pre implementáciu použite knižnicu ncurses.

Počiatočný stav sveta:

Svet je viditeľná oblasť obrazovky. Po svete je náhodne rozhádzaných 20 odmien, vykreslených ako *. Svet nemá okraje ani žiadne prekážky. Telo hada je tvorené značkou x. Na začiatku je telo hada dlhé 5 x a je umiestnený v strede obrazovky.

Pohyb hada:

Had sa najprv pohybuje do prava. Pohyb hada sa riadi pomocou šípiek podľa nesledovných pravidiel:

1. Určí sa nová pozícia hlavy podľa posledne stlačenej smerovej klávesy.
1. Ak je nová pozícia hlavy na mieste hada, hra sa končí a vypíše sa hlásenie "Game over, you looser!".
1. Ak je nová pozícia hlavy mimo rozmerov sveta, had pokračuje v pohybe na opačnej strane.
1. Ak sa na novej pozícii hlavy nenachádza odmena, vymaže sa posledný článok hada.
1. Ak sa na novej pozícii hlavy nachádza odmena a iné odmeny sa nenachádzajú, hra sa končí a vypíše sa hlásenie "You won, snake master!"
1. Pridá sa nový článok hada na novú pozíciu hlavy.

Štruktúra zadania a odovzdávanie:

Zadanie sa odovzdáva e-mailom a obhajuje osobne v 13. týždni.
Všetky súbory zadania budete ukladať do adresára zadanie3.

- priezvisko-zadanie3.zip
    - zadanie3
        - snake.c : Súbor s implementáciu zadania sa bude volať snake.c.
        - snake.h : predpisy funkcií 
        - main.c : volanie funkcie game();
        - Makefile : Súbor Makefile bude obsahovať pravidlá pre kompiláciu.
        - README : Dokumentácia k zadaniu



Obsah súboru snake.h:

```c

struct snake {
    // Dvojrozmerne pole pre ulozenie pozicii odmien. Zjedenym odmenam priradte -1,-1.
    int world[2][20];
    // Dvojrozmerne pole pre ulozenie tela hada. Posledny prvok je vzdy hlava hada.
    int snake[2][25];
    // Velkost hada.
    int snakesz;
};

// Inicializuje poziciu odmien, poziciu a velkost hada
// @arg snake Alokovany Stav hada a odmien
void init_world(struct snake* snake);

// Funkcia pre logiku hada, podla zadanych pravidiel modifikuje strukturu snake.
// @arg snake Stav hada a odmien
// @arg snakedir Argument snakedir znaci novy smer hada
// V ramci funkcie nemozete volat funkcie kniznice ncurses pre zobrazenie.
//
// @return
// Vrati 0 ak je nova poloha v poriadku
// Vrati -1 ak had narazil
// Vrati +1 ak uz nie su odmeny
int move_snake(struct snake* snake,int snakedir);

// Vykresli aktualny stav sveta na obrazovku
// Vyuziva volania ncurses pre vykreslenie odmien a pozicii hada
// @arg snake Stav hada a odmien
void draw_world(struct snake* snake);

// Inicializuje ncurses
// Inicializuje svet pomocou funkcie init_world(), potom v cykle:
// Zisti a nastavi smer hada podla stlacenej klavesy 
// Vykona cakanie podla nastavenej rychlosti.
// Ak je treba, ukonci hru pomocou end();
// Pohne hada  pomocou funkcie move_snake()
// Vykresli svet pomocou funkcie draw_world()
void game();

// Vypise spravu o konci hry
// Skonci ncurses.
// Argumentom je navratova hodnota funkcie move_snake.
void end(int reason);

```

Obsah Makefile:

```Makefile

CFLAGS= -std=c99 -Wall
LDFLAGS= -lcurses -lm

all: snake

snake.o: snake.c
    gcc -c snake.c -o snake.o $(CFLAGS)

main.o: main.c
    gcc -c main.c -o main.o $(CFLAGS)

snake: main.o snake.o
    gcc main.o snake.o -o snake $(CFLAGS) $(LDFLAGS)

```


Podmienky na odovzdanie:

- Názvy súborov a archívu spĺňajú formálnu stránku (nevyhnutná podmienka pre udelenie ostatných bodov)
- Zadanie bolo odovzdané načas (nevyhnutná podmienka pre udelenie ostatných bodov)
- Dokumentácia je dostatočne rozsiahla a správna. Dokumentácia by mala tvoriť minimálne 25% zdrojových kódov.
    - do súboru README napíšte:
        - Vaše meno a skupinu
        - Stručný opis hry
        - podmienky za akých sa program skompiluje
        - návod na preloženie
        - Návod na spustenie
    - do súboru snake.c do blokových komentárov pre každú funkciu:
        - podrobný opis činnosti funkcie
        - podrobný opis vstupov jej vstupov a návratovú hodnotu.
    - do súboru snake.c do riadkových alebo blokových komentárov ku každej dôležitej časti zdrojových kódov:
        - slovné vysvetlenie čo kódy robia
- Program sa dá skompilovať a spustiť
- Program funguje správne.
- Zadanie odovzdajte e-mailom do posledného cvičenia

Hodnotenie:

Spolu 5 bodov:

- Zadanie obhajujte osobne na 13. cvičení
- Dokumentácia 2 body
- Správnosť zdrojových kódov 2 body
- Úprava zdrojových kódov 1 bod (dodržanie odsadenia, kvalitné komentovanie kódov)
