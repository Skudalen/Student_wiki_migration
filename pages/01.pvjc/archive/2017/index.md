# Archive 2017

Katedra elektroniky a multimediálnych komunikácií

Letný semester 2017

Cvičiaci:

Kancelária BN32 L610

- Ing. Daniel Hládek PhD. (odporúčaný čas konzultácií pondelok 12:30)
- Ing. Martin Lojka PhD.


# Oznamy

- 11.5.2017: Zápočty do Maisu sa budú zapisovať v piatok. V prípade nejasností prosím kontaktujte cvičiaceho.
- 11.5.2017: Posledný termín na odovzdávanie zadaní je budúci utorok. V pondelok nebudeme prítomní. 
- 10.5.2017: Odovzdávanie zadania 3 a 4 sa deje v univerzitnej knižnici vo štvrtok od 9 00 do 10 40. Potom v kancelárii na BN32. Prosím odovzdajte aj dokumentáciu podľa pokynov.
- 27.4.2017: Na cvičenie v 12. týždni prosím doneste Vaše Arduino.
- 27.2.2017: Prihláste sa na <https://www.codewars.com/> a vysúšajte si niektoré cvičenia (Kata) pre jazyk C.
- 24.2.2017: Zápočet udeľuje cvičiaci u ktorého ste zapísaný na cvičení.
- 20.2.2017: Zápočty ani skúšky z minulých ročníkov sa neuznávajú
- 17.2.2017: Kolegovia ktorým nefunguje prístup na omega.tuke.sk, prosím napíšte e-mail cvičiacemu, kde uvediete Váš login do MAISu a meno.

# Obsah

[[TOC]]

# Hodnotenie A

4 zadania po max 5 bodov zápočet

** skúška programovanie max 80 bodov **

min. 2 nepovinné zadania sa pripočítajú k skúške
    
```c
int zapocetA(int zadania[4]){
    int vysledok = 0;
    for (int i=0; i < 4; i++){
        vysledok += zadanie[i];
    }
    return vysledok;
}
```

Ak študent získa aspoň 80% hodnotenie zo všetkých riadnych zadaní a 80% hodnotenie z doplnkových zadaní, môže skúšku získať ich dodatočnou obhajobou v na to určenom termíne.

# Hodnotenie  B

1. zadanie max 10 bodov

Ľubovoľné ďalšie zadanie z povinných zadaní max 10 bodov.

** skúška test max 60 bodov **

```c
int zapocetB(int zadania[4]){
    int vysledok = zadanie[0];
    int m = 0;
    for (int i = 1 ; i < 4; i++){
        if (zadanie[i] > m)
            m = zadanie[i];
    }
    return 2 * (vysledok + m);
}
```
    


# Podmienky na zápočet

Môžete si zvoliť hodnotenie A alebo B

Max. 3 ospravedlnené neúčasti

Urobené prvé zadanie

Minimálne 11 bodov z 20


# Študijné materiály

- [Web stránka predmetu](http://it4kt.cnl.sk/c/pvjc/)
- [Kniha Kernighan a Ritchie: Programovací jazyk C](https://knihy.abz.cz/imgs/teaser_pdf/4449788025108970.pdf) (druhé vydanie, český jazyk)
- [kniha Podlubný: Úvod do programovanie v jazyku C](http://people.tuke.sk/igor.podlubny/C/index.htm)
- [kniha Belan: Kurz jazyka C](https://www.smnd.sk/anino/moje/C.pdf)
- Pavel Herout : Učebnice jazyka C (1. díl) (Vydavateľstvo: Kopp, 2009)

# Cvičenie 1

Vypracujte [tutoriál č. 1](http://it4kt.cnl.sk/c/pvjc/2017/labs.01.html)

Budete potrebovať:

- Konštantu s počtom písmen
    
        #define ASIZE 26
    
- Funkcia na prevod znaku na index
    - Ak je znak veľké alebo malé písmeno, vráti jeho poradie v abecede
    - Inak vráti konštantu
- Funkciu pre porovnanie dvoch smerníkov typu int
    
        int compareints (const void * a, const void * b){
          return ( *(int*)a - *(int*)b );
        }
    
- Funkciu pre zotriedenie poľa
    - [qsort](http://www.cplusplus.com/reference/cstdlib/qsort/)
- Funkciu pre vyhľadávanie v poli
    - [bsearch](http://www.cplusplus.com/reference/cstdlib/bsearch/)
- Funkciu pre načítanie znaku zo štandardného vstupu
    - Vráti EOF na konci vstupu
    - [getchar](http://www.cplusplus.com/reference/cstdio/getchar/)

Riešenie:

- Funkcia build_ftable
    - Vynulujeme frekvenčnú tabuľku (pole)
    - Načítavame znaky zo štandardného vstupu až do konca
    - Konvertujeme znak na index
    - Ak je index v poli, zväčšíme jeho hodnotu vo frekvenčnej tabuľke
- Funkcia build_ttable
    - Vytvoríme nové pole sortedt, do ktorého uložíme zotriedenú frekvenčnú tabuľku
    - Vyhľadáme každý prvok frekvenčnej tabuľky ftable  v zotriedenej frekvenčnej tabuľke sortedt a jeho index uložíme do prekladovej tabuľky ttable
             
            ttable[i] = bsearch(&ftable[i],sortedt,ASIZE,sizeof(int)) - sortedt;

# Cvičenie 2


Opakovanie:
    - Algoritmus lineárneho vyhľadávania

Nová látka:

- [Štruktúry](https://en.wikipedia.org/wiki/Struct_(C_programming_language))
- Zložené údajové typy
- Definícia štruktúry
- Deklarácia štruktúry
- Inicializácia štruktúry
- Pole štruktúr

Vypracujte [tutoriál č. 2](http://it4kt.cnl.sk/c/pvjc/2017/labs.02.html):

- skopírujte si súbor z minulého cvičenia
    
    cp cv1.c cv2.c

# Cvičenie 3

Opakovanie:

- Polia v jazyku C
- Reťazce v jazyku C
- Práca so štandardnou knižnicou (pr8ca s dokumentáciou a pripojenie hlavičkového súboru)
    strlen
    memcpy
- Štruktúry

Vypracujte tutoriál č. 3

Prihláste sa na https://www.codewars.com/

Skontrolujte, či je zadaný reťazec platná IPV4 adresa:

- reťazce v jazyku C sú ukončené nulou
- práve 4 čísla menšie ako 256 a väčšie ako 0
- číslo sa nesmie začínať na nulu
- číslo sa končí bokdou alebo 0 (na konci)
- všetky znaky sú číslice alebo bodky

Budete potrebovať:

- Funkciu pre konverziu reťazca na číslo
    atoi
    strtol (Pozor, funkcia mení zadaný reťazec!)
- Slučku ktorá prechádza všetky čísla
- Slučku ktorá prechádza všetky znaky


# Cvičenie 6

Vypracujte [tutoriál č. 6](http://it4kt.cnl.sk/c/pvjc/2017/labs.06.html):

Opakovanie

- Ladenie pomocou GDB
- Ladenie pomocou analýzy výpisu pamäte

Nová látka

Automatické testy


Postup:

1. Stiahnite si kostru zadania č. 2 a pripravte si ju do priečinka ps2 vo Vašom GIT repozitári
1. Skopírujte hlavičkové súbory bmp.h a playfair.h do prislúchajúcich c súborov
        
        cp bmp.h bmp.c
        cp playfair.h playfair.c

1. Upravte c súbory tak, aby obsahovali prázdne telá funkcie a pridajte direktívy pre vloženie hlavičiek. Napr:
        
    ```c
    #include "playfair.h"

    char* playfair_decrypt(const char* key, const char* text){
        return NULL;
    }
    ```

1. Vytvorte kostru súboru main.c. Napr.
    
    ```c
    #include "bmp.h"
    #include "playfair.h"

    int main(){
        // Tu mozte písat program
        return 0;
    }
    ```

1. Vytvorte Makefile pre zostavenie projektu. Napr.
    
    ```Makefile
    CFLAGS=-std=c11 -Werror -Wall -lm

    all: ps2

    ps2: main.o playfair.o bmp.o
        gcc $(CFLAGS) main.o playfair.o bmp.o -o ps2

    %.o: %.c
        gcc $(CFLAGS) -c $< -o $@
    ```

1. Do hlavičkového spboru bmp.h pridajte predpis funkcie pre Cézarovu šifru
    ```c
    char* caesar_encrypt(const char* text, int step);
    ```

1. Do bmp.c pridajte implementáciu Cézarovej šifry
        
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

1. Pridajte cieľ do Makefile pre zostavenie a spustenie testu
        
    ```Makefile
    tests: tests_bmp.o bmp.o
        gcc $(CFLAGS) tests_bmp.o bmp.o -o tests
        ./tests
    ```

1. Implementujte testy. Využite funkciu assert, ktorá predčasne ukončí program v prípade, že nie je splnená podmienka



# Cvičenie 7

Opakovanie:

Štruktúry, operátor ->

Nová látka:

Spojkový zoznam

1. Vytvorte [kostru projektu](http://it4kt.cnl.sk/c/pvjc/2017/download/forecast.zip) v novom adresári cv7
1. Skopírujte predpisy funkcií z forecast.h do forecast.c
1. Vytvorte prázdne implementácie v súbore forecast.c

    ```c
    #include "forecast.h"
    #include <stdlib.h>

    struct data* insert_data(struct data* first, long int dt, float temp, float pressure, int humidity, float speed, float deg){
        return NULL;
    }
    void print_forecast_data(struct data* first){
    }
    struct data* delete_all(struct data* first){
        return NULL;
    }
    ```


1. Implementujte funkciu insert_data() pre vytvorenie nového prvku na konci spojkového zoznamu . Ak je prvý prvok nulový, funkcia vráti nový prvok. Inak funkcia vždy vracia prvý prvok.  Ak existuje, posledný prvok spojkového zoznamu musí ukazovať na nový prvok. Nezabudnite správne inicializovať všetky prvky novej štruktúry.

    Nový prvok si vytvoríte pomocou volannia funkcie [malloc()](http://www.cplusplus.com/reference/cstdlib/malloc/):

    ```c
    struct data* new = malloc(sizeof(struct data));
    // vsetky prvky iniciazujte pomocou operatora ->
    new->next = NULL;
    ```

    Príklad volania novej funkcie:

    ```c
    struct data* first = NULL;

    while(fscanf(fp, "%ld %f %f %d %f %f", 
                &dt, &temp, &pressure, &humidity, &speed, &deg) != EOF){
        // Pri prvom volani je first NULL !!!
        first = insert_data(first,dt,temp,pressure,humidity,speed,deg);
    }
    ```

    Kód pre prechádzanie všetkých prvkov zoznamu:

    ```c
    struct data* this = first;
    assert(first  != NULL);
    while (this->next != NULL){
        // Mozem urobit nejaku operaciu so strukturou na ktoru ukazuje this
        this = this->next;
    }
    ```

    Kód funkcie insert_data:

    ```c
    struct data* insert_data(struct data* first, long int dt, float temp, float pressure, int humidity, float speed, float deg){
    // Alokacia noveho porvkuy spojkoveho zoznamu
        struct data* new_node = malloc(sizeof(struct data));
        // Inizializacia 
        new_node->deg = deg;
        new_node->dt = dt;
        new_node->temp = temp;
        new_node->pressure = pressure;
        new_node->humidity = humidity;
        new_node->speed = speed;
        // Posledny prvok spojkoveho zoznamu je nulovy
        new_node->next = NULL;

        // Ak ma zoznam nula prvkov, novy prvok je prvy
        if (first == NULL)
            return new_node;
        // Pomocny smernik pre prechadzanie zoznamu, najprv je prvy
        struct data* current_node = first;
        // Pokiak altualny prvok nie je posledny (nema dalsi prvok)
        while (current_node->next != NULL){
            // Prechadzaj - novy aktualny prvok
            current_node = current_node->next;
        }
        // Na konci je aktualny prvok posledny
        // Novy prvok pripojime za posledny
        current_node->next = new_node;

        // Vzdy vraciame prvy prvok
        return first;
    }
    ```

1. Zavolajte funkciu insert_data() vo funkcii load_data() v súbore main.c
1. Vyskúšajte správnosť programu pomocou Valgrindu
1. Implementujte funkciu print_forecast_data() pre výpis štruktúr v zozname.
    
    Čas vypíšte ako reťazec vo formáte DD.MM.YYYY HH:MM.  Pre výpis času v danom formáte si preštudujte formátovacie znaky pre funkciu strftime.

    - [strftime](http://www.cplusplus.com/reference/ctime/strftime/)
    - [localtime](http://www.cplusplus.com/reference/ctime/localtime/)
    - [printf](http://www.cplusplus.com/reference/cstdio/printf/)

    Príklad využitia funkcie strftime pre výpis aktuálneho času ([zdroj](http://www.cplusplus.com/reference/ctime/strftime/)):

```c
/* strftime example */
#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */

int main ()
{
  time_t rawtime; // Aktualny cas ako cele cislo
  struct tm * timeinfo; // Aktualny cas, rozdeleny na zlozky
  char buffer [80];

  time (&rawtime); // Ziskanie aktualneho casu
  timeinfo = localtime (&rawtime); // Konverzia celeho cisla na strukturu

  strftime (buffer,80,"Now it's %I:%M%p.",timeinfo); // Konverzia struktury na retazec
  puts (buffer); // Vypis retazca

  return 0;
}
```

1. Implementujte funkciu delete_all() pre vymazanie celého spojkového zoznamu.
1. Modifikujte súbor main.c tak aby volal funkciu print_forecast_data() a delete_all()
1. Vyskúšajte správnosť programu pomocou Valgrindu

# Cvičenie 8

Nová látka:

[Práca s knižnicou NCURSES](http://invisible-island.net/ncurses/ncurses-intro.html)

Dôležité funkcie

- initscr
- mvprintw
- refresh

Dôležité globálne premenné

- LINES
- COLS

Iné dôležité funkcie

- nanosleep
- rand
- srand
- getchar

# Cvičenie 10

Nová látka:

Regulárne výrazy a editor VIM

Dodatočný materiál 

- [Regex Tutoriál](http://www.regular-expressions.info/tutorial.html)
- [Regex Cheat Sheet](http://www.petefreitag.com/cheatsheets/regex/)

Regulárne sú nevyhnutnou pomockou pri práci s veľkým množstvom textu. Pomocou nich vieme vyhľadávať a nahrádzať niektoré vzory. Zápis regulárnych výrazov je závislý na konkrétnej implementácii, ale existujú niektoré všeobecné pravidlá.

Regulárne výrazy môžeme využiť v programoch:

- vim
- Váš iný obľúbený textový editor
- grep: vyhľadávanie súborov
- sed: neinteraktívne editovanie súborov z príkazového riadku.
- Váš vlastný program v jazyku C


1. Editor vi pracuje v rôznych módoch. V normálnom móde pohybujete kurzorom a
   manipulujete s blokmi textu.  Príkazy v normálom móde zadávame stlačením
   kláves. Príkazom i alebo A aktivujete vkladací mód v ktorom píšete text.
   Vkladací mód opustíme klávesou ESC.  Otvorte si editor vi a vložte do neho
   testovací text:
        
        vim test.txt
   
       Otvorí sa prázdny súbor a editor vim je v príkazovom móde. Skúste napísať "Ahoj svet". Editovanie ukončite klávesou ESC. Súbor uložíme  a skončíme editovanie príkazom ZZ. Overíme si výsledok editovanie pomocou programu cat.

            cat test.txt
        
1. Do súboru test.txt vložte nasledovný testovací text. Môžete použiť schránku.

        toto je mac adresa: 01:23:45:67:89:0a
        Nesprávne MAC adresy:
        xx:xx:xx:xx:xx:xx
        01:23:45-67-89-0a
        01:23:45:67:89:0a:
        :01:23:45:67:89:0a
        01:
        Správna mac adresa:
        a1:3d:56:99:01:ee

1. Príkazom / vyhľadávate.  Vyhľadajte všetky výskyty slova adresa. Príkazom n kurzor skočí na ďalší vyskyt, N skočí na predošlý výskyt hľadaného reťazca. Príkazom :set hlsearch zapnite zvýraznenie nájdených reťazcov. Príkazom :nohl zrušíte  aktuálne zvýraznenie  vyhľadávania. 

1. Na miesto vyhľadávaného reťazca môžete zadať aj regulárny výraz. Regulárny výraz je špeciálny reťazec, ktorým viete "zachytiť" a opísať viac reťazcov naraz. Napíšte regulárny výraz, ktorý zachytí slová "adresa" a "adresy". V reguárnom výraze použijete operátor [] pre zachytenie skupiny znakov:

        /adres[ay]

    Znaky [ a ] majú špeciálny význam. Ak ich chceme vyhľadať, musíme pred nich napísať spätné lomítko \.

1. V hranatých zátvorkách vieme uvádzať aj rozsahy znakov pomocou -. Vyhľadajte všetky dvojice desiatkových čísel. Pri vyhľadávaní môžeme využiť aj históriu hľadaní pomocou šípok hore a dole.

        /[0-9][0-9]

1. V regulárnych výrazoch vieme vytvoriť opakujúce sa skupiny. Skupinu ohraničíme znakmi ```\( a \)``` . Počet opakovaní zapíšeme skupiny zapíšeme pomocou ```\{m,n}```. (m je minimálny počet opakovaní, n je maximlány). Napíšte regulárny výraz pre zachytenie mac adresy tvorenej desiatkovými číslami alebo malými písmenami  a oddelenej dvojbodkami:

    
        \([0-9a-z][0-9a-z]:\)\{6} 

    Upravte výraz tak aby zachytával aj adresy oddelené pomlčkou. Všimnite si, že uvedený zápis nie je celkom správny, lebo si vyžaduje, aby na konci bola dvojbodka.

1. Napísaný regulárny výraz môžeme využiť pre operáciu typu "hľadaj na nahraď". Nahradte všetky MAC adresy v súbore reťazcom "MAC". Využite príkaz :%s/hladaj/nahrad/gc. Reťazec hladaj je regulárny výraz ktorý vyjadruje hľadané reťazce. nahrad je reťazec ktorým nahradzujeme. Znak % hovorí, že hľadáme v celom súbore. g hovorí, že nahradzujeme všetky výskyty na riadku, nie len prvý. Znak c hovorí, že si vyžadujemem osobitné potvrdenie každého nahradenia.

        :%s/\([0-9a-z][0-9a-z]:\)\{6}/MAC/gc

    Posledný regulárny výraz z vyhľadávania nemusíte vypisovať odznova, môžete využiť fintu ```<Ctrl-R>/``` ktorá vloží posledne hľadaný výraz. Ak sa Vám vykonané nahradenia nepáčia, zmeny môžte vratíť príkazom u (ako undo). Opakom undo je  ```<Ctrl-R>``` (redo). V príkazovom móde tiež môžete využívať históriu pomocou kláves hore a dole.

1. Regulárne výrazy môžeme napísať aj v jazyku C. Stianite si program [heslo.c](http://it4kt.cnl.sk/c/pvjc/2016/src/week.09/heslo.c), preložte a spusttite ho. Skúste využiť editor vim. Príkazy príkazového riadka môžete zadávať priamo z VIMu pomocou :!

        wget http://it4kt.cnl.sk/c/pvjc/2016/src/week.09/heslo.c
        vim heslo.c
        :!gcc -std=c99 heslo.c -o heslo
        :!./heslo

    Zistite, aké heslo program očakáva. Na pohyb kurzora v normálnom móde využite klávesy w b (ďalšie alebo predošlé slovo)  alebo h j k l (pohyb kurzorom z klávesnice). Ak máte pripravený Makefile, mlžete použiť príkaz :make

    Pomôcka špeciálne znaky REGEX:

        . Ľubovoľný znak
        ^ Začiatok reťazca
        $ Koniec reťazca
        [A-Z] skupina znakov s rozsahom
        () skupina pre opakovanie
        ? 0-1 opakovaní
        * 0-nekonečno opakovaní predošlého znaku alebo skupiny.
        + 1-nekonečno opakovaní
        | operátor alebo v skupine znakov

    Význam a zápis špeciálnych znakov je závislý od implementácie. (napr. vo VIM musíte pred niektoré špeciálne znaky písať \)

1. Upratovačka zdrojového kódu.

    Zoberte nejaký Váš program a skúste ho upratať pomocou VIM. Upratovanie označenej časti vykonáme klávesou =.
Príkazom gg skočíme na začiatok súboru, v aktivuje označovací mód. príkazom G skočíme na koniec súboru a tým je celý súbor označený.
    


# Zadanie 3 Snake Master

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

# Zadanie 4: Arduino

Úloha:

Vytvorte demonštračný program pre Arduino spolu s hardvérovou časťou.

Hardvérová časť:

- Ako riadiaci modul použite Arduino, odporúčame verziu UNO
- Systém by mal mať minimálne dva vstupy, napr. tlačítko, teplomer alebo sonar.
- Systém by mal mať minimálne dva výstupy, napr. LED svetlo, segmentový displej alebo motorček.
- Pre spojenie komponentov môžete použiť nepájivé kontaktné pole (breadboard)

Softvérová časť:

- Program musí byť napísaný v jazyku C
- Program musí využívať všetky hardvérové komponenty 
- Všetky funkcie, ich argumenty, návratové hodnoty, štruktúry musia byť podrobne dokumentované pomocou komentárov v zdrojovom kóde.

Dokumentácia:

Súčasťou zadania bude stručný manuál vo formáte PDF v ktorom opíšete:

- Účel Vášho zariadenia
- Fotografiu Vášho zariadenia
- Návod na oživenie, spustenie a použitie
- Slovný opis riešenia

Odovzdanie a povinná štruktúra zadania:

Zdrojový kód a dokumentáciu e-mailom v archíve typu ZIP.
Meno a obsah súboru bude vo formáte:

- priezvisko-zadanie4.zip
    - source.c
    - README.pdf

Hodnotenie:

- Zadanie obhajujte osobne na 13. cvičení
- Dokumentácia 2 body
- Zdrojové kódy 2 body.
- Funkčnosť: 1 bod


Poznámky k implementácii:

- Skrat spôsobí poškodenie Vášho Arduina.
- Najprv si rozvrhnite rozloženie všetkých súčiastok na breadboarde.
- Pre vývoj môžete použiť systém [Arduino IDE](https://www.arduino.cc/en/Main/Software).
- Pred použitím každého pinu musíte nastaviť či je vstupný alebo výstupný pomocou funkcie pinMode();
- I2C komunikáciu zapojte na porty A4 a A5.
- Pre ovládanie LCD displeja pomocou I2C modulu PCF8574 použite knižnicu [LiquidCrystal_I2C](http://www.mathertel.de/Arduino/LiquidCrystal_PCF8574.aspx), nain3talujete ju pomocou menu v Arduino IDE (Sketch/Include Libraries/Manage Libraries/LiquidCrystal_I2C)
- Pre zapojenie I2C modulu na breadboard bude možno potrebné poohýbať piny.
- K spínaču budete potrebovať min. 10k odpor.
- K LED dióde ide min. 220R odpor

# Doplnková úloha

pomôžte pri vedeckom výskume účasťou na ["Spelling Experimente"](/pages/spelling).
 
Úloha: Prepíšte aspoň 100 viet, ktoré Vám prečíta umelý hlas na Vašom mobilnom telefóne.

Odhadovaný čas: cca 20 min.

Postup:

1. Vyplňte krátky formulár, aby bolo možné identifikovať Vás a Vaše zariadenie.
1. Zapnite slúchadlá a nastavte si hlasitosť tak aby ste počuli testovaciu správu.
1. Požiadajte systém o novú vetu a prepíšte ju pomocou virtuálnej klávesnice. Opakujte 100 krát.

Hodnotenie:

1 bod k zápočtu


# Pomôcka pre editor Vim

- [Editor VIM prakticky](http://www.abclinuxu.cz/clanky/navody/editor-vim-prakticky-i)
- [Stránky Pavel Satrapa](http://www.nti.tul.cz/~satrapa/docs/vim/)
- [Mapa klávesnice VIM a tutoriál](http://www.viemu.com/a_vi_vim_graphical_cheat_sheet_tutorial.html)


- :tutorial - Spustí interaktívny tutoriál
- Esc - Normálny mód
- i - vkladací mód
- a - koniec riadka a vkladací mód
- v - vizuálny (označovací) mód
- V - riadkový vizuálny mód
- y -kopíruj (vo vizuálnom móde)
- x - vyber (vo vizuálnom móde)
- = - uprav odsadenie, uprac kód (vo vizuálnom móde)
- yy - kopíruj riadok
- dd - vymaž riadok
- dw - vymaž slovo
- das - vymaž aktuálnu vetu
- P - vlož
- ZZ - ulož a skonči
- / - vyhľadávanie
- \* - vyhľadávanie aktuálneho slova alebo mena
- gg choď na začiatok
- G choď na koniec súboru
- :2 choď na riadok číslo 2
- :w - ulož
- u - undo
- Crtl-R - redo
- :make stairs - prelož program stairs
- :!./stairs.run - spusti program stairs


# Návod na používanie siete eduroam

1. Prečítajte si [návod](https://nastavenia.tuke.sk/wifi/prirucka-pouzivatela)
1. Nastavte si [WiFi heslo](https://identity.tuke.sk) (View and Edit Profile)
1. Vaše meno je vo formáte ab123cd@tuke.sk

