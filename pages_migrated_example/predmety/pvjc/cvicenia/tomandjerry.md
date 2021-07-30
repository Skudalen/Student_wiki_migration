# 8\. Tomáš a Juraj

Zopakujete si:

  - Pracovať so smerníkom na štruktúru.
  - Používať externú knižnicu a modulárny program.
  - Pracovať s pseudo grafickým terminálom.
  - Generovať celé náhodné číslo.

Na Technickej Univerzite budú natáčať ďalší diel obľúbenej kreslenej grotesky Tomáš a Juraj. Diváci chcú vidieť nové príbehy mačky Tomáša a myšky Juraja čím skôr a tak požiadali o pomoc našu produkčnú firmu BN Computer Networks 32th Fox.

Animovať sa bude inovatívnou metódou ASCII Art animation. Do úlohy mačky Tomáša sa prihlásilo písmeno `c`, do úlohy myšky Juraja písmenko `m`.

Vašou prvou úlohou bude rozbehať animáciu mačky a myši na obrazovke a pomocou šípiek na klávesnici navigovať mačku tak aby chytila myš.

Ak sa Vám to podarí, v druhom dieli angažujte ďalších myších hercov a natočte diel v ktorom mačka Tomáš chytá až päť myšiek naraz. Počet aktuálne chytených myšiek nech zobrazí počítadlo. Ak Tomáš myšku chytí (ocitne sa na rovnakom mieste) tak odstráňte myšku z hracej plochy a zvýšte počítadlo o jedna. Ak Tomáš chytí všetky myšky, vypíšte vtipnú správu na obrazovku a skončite.

![By Unknown photographer - This image was released by the National
Cancer Institute](640px-Scid_mouse.jpg)

## Naštudujte si

Pomocou knižnice Svet viete vytvoriť jednoduchú akčnú hru s textovo-grafickým rozhraním bez toho, aby ste museli poznať detaily programovania terminálov.

Najprv sa oboznámte s knižnicou [Svet](https://github.com/hladek/world).


## Preloženie a spustenie

Na to aby ste hru "Tomáš a Juraj" preložili a spustili musíte mať najprv nainštalovanú knižnicu `curses`. Je nainštalovaná na servri Omega alebo na Vašom virtuálnom stroji s Linuxom.

Prvým krokom bude získanie zdrojových kódov a ich zostavenie.
Stiahnite a rozbaľte kostru zadania do adresára a2.

```
wget https://github.com/hladek/world/archive/master.zip
unzip master.zip
mv world-master a2
cd a2
make
```

Celý program zostavíte príkazom `make`. Inštrukcie pre zostavenie sa nachádzajú v súbore `Makefile`.

## Vytvorenie hry

Najprv si určíme, ako bude vyzerať hra na začiatku.

V prípade hry na mačku a myš nám stačí poznať pozíciu mačky a myši. To si vieme vyjadriť ako štruktúru:

``` c
struct game {
    // Pozícia mačky
    int catx;
    int caty;
    // Pozícia myši
    int mousex;
    int mousey;
    // Správa na vykreslenie na konci
    char message[100];
};
```

Fantázii sa medze nekladú a stav sveta môže vyzerať úplne inak. Ak by sme vymysleli hru kde lieta raketka pomedzi asteroidy tak si potrebujeme zapamätať pozíciu raketky a asteroidov.


Na začiatku sa vyhradí a inicializuje pamäť pre uloženie stavu hry.
Stav hry je množina premenných nevyhnutných a postačujúcich pre hru.

Alokujeme pamäť pre novú hru, nastavíme počiatočné hodnoty
a vrátime adresu pamäte kde sa nachádza nová hra:

```c
// Návratová hodnota je adresa s novou hrou
void* init_game(struct world* g){
    // Allocate memory for the state
    struct game* st = calloc(1,(sizeof(struct game)));
    // Počiatočná poloha myšky
    st->mousex = 11;
    st->mousey = 12;
    // počiatočná poloha mačky
    st->catx = 5;
    st->caty = 5;
    // Store pointer to the state to the world variable
    return st;
}
```

## Zmena stavu hry

Hra prebieha tak, že meníme jej stav ak sa vyskytne nejaká zaujímavá udalosť, napr.  nejaké inštrukcie z klávesnice.
Stav sa môže zmeniť aj v prípade, že žiadne inštrukcie z klávesnice neprichádzajú, ale uplynie nejaký časový interval. Tak môžeme robiť animácie.

Na zmenu stavu sveta a vykreslenie používame funkciu `world_event`. Všetky argumenty Vám pošle knižnica Svet.


```
int world_event(struct world* world,void* g){
    struct game* game = (struct game*)g;
    // Tu píšeme pravidlá hry
    // Načítame world podľa toho
    // zmeníme a vykreslíme game

    return 0;
}
```

Prvý argument `world` je stav obrazovky a klávesnice `struct world*`.
Parametre stavu hry sú aktuálne rozmery obrazovky a aktuálne stlačený kláves.

Kód stlačenej klávesy sa nachádza v premennej `world->key`.
Dostupné kódy kláves sa nachádzajú dokumentácii.

Ak je hodnota `world->key` rovná konštante `ERR`, potom nenastalo žiadne stlačenie klávesy.

Druhý argument je smerník na hru `game`, ktorú sme si vytvorili vo  funkcii `create_game()`. 
Smerník na hru `game` si musíme pretypovať z všeobecného smerníka `void*` aby sa nám s ním pracovalo ľahšie:

K premenným stavu hry `game` vieme pristupovať pomocou operátora `->`, napr. `game->mousey` je vyjadruje `y` pozíciu myšky. 


Algoritmus pre hru môže vyzerať takto:

1. Ak sa mačka a myš nachádza na tom istom mieste, tak vypíšte správu.
1. alebo ak sa vyskytlo stlačenie klávesy, tak upravte polohu mačky
1. alebo ak sa nevyskytlo stlačenie klávesy, tak pohnite myškou po ploche.
1. Vykreslite polohu mačky, myšky a správu ak je nejaká.


## Vykreslenie hry

Na vykreslenie sveta nám stačí nám použiť jedinú funkciu - povedať aký znak chceme vykresliť a na ktoré miesto.


Použijeme na to funkciu `set_cell()`.
Prvý argument `world` je smerník na aktuálny stav sveta obrazovky a klávesnice. Druhý argument je znak na vykreslenie. Tretí a štvrtý argument sú súradnice `x` a `y` kde na obrazovke sa má znak vykresliť.

Bod `0,0` je podľa dohody v ľavom hornom rohu obrazovky.

Ak napíšeme tieto príkazy:


```
set_cell(world,'c',3,2);
set_cell(world,'m',3,4);
```

Obrazovka bude vyzerať takto.

```
    origin
     [0,0]     width (x) ->
          +--------------------+
  height  |                    |
     (y)  |  c                 |
          |                    |
          |  m                 |
          |                    |
          |                    |
          +--------------------+
```

## Modifikácia hry pre viacero myšiek

Pozrite si aktuálnu implementáciu hry v súbore `game.c`, kde mačka chytá myš. 


Vašou úlohou bude modifikovať zdrojové kódy tak, aby mohlo byť na obrazovke viac myší naraz. Maximálny počet myšiek si vieme zadefinovať
ako konštantu:

``` c
#define MOUSE_COUNT 5
```

To znamená, že potrebujeme rozšíriť pamäť na uchovanie pozície myšky v štruktúre `struct game`, napr.

``` c
int mousex[MOUSE_COUNT];
int mousey[MOUSE_COUNT];
```

Takéto polia nám umožnia uchovať pozíciu až piatich myší. Pri návrhu potrebných dátových typov sa samozrejme fantázii medze nekladú.

Ak kocúr chytí myšku, jej stav sa zmení na "zjedená".
Každá myška v hracom poli môže byť už zjedená alebo ešte nie.

Stav každej myšky (či je zjedená alebo nie) si môžme poznačiť do osobitného poľa v štruktúre `struct game`.

```
int mouse_state[MOUSE_COUNT];
```

Alebo si môžeme  povedať, že zjedená myška je taká, ktorej súradnice sú záporné. 

Kontrola či je myška zjedená môže vyzerať napr. takto:

``` c
for (int i = 0; i < MOUSE_COUNT;i++){
    // Ak myška žije
    if (game->mousex[i] >= 0){
        // Ak mačka chytila myš
        if (game->mousex[i] == game->catx && game->mousey[i] == st->caty){
            // Myška domyšila
            // Nastavíme jej stav na "zjedená".
            game->mouse_state[i] = 1;
        }
    }
}
```

Pri generovaní náhodného pohybu myšky sa môžete inšpirovať vzorovým kódom:

``` c
int m = rand() % 4;
if (m == 0){
    game->mousey -= 1;
}
else if (m == 1){
    game->mousey += 1;
}
else if (m == 2){
    game->mousex -= 1;
}
else if (m == 3){
    game->mousex += 1;
}
```

Funkcia `rand()` vygeneruje náhodné celé číslo. Operátor `%` vracia
zvyšok po celočíselnom delení. Celý výraz vráti náhodné číslo v
intervale 0 až 3.

Pohyb mačky je riešený podobne, ale nezávisí od náhodnej hodnoty ale od aktuálne stlačenej klávesy.

Výsledný algoritmus môže vyzerať takto:

1.  Vo funkcii `crete_world` náhodne inicializujte pozíciu mačky a myšiek na obrazovke.
2.  Ak je počet živých myšiek nula, vypíšte správu a skončite hru.
2.  Podľa stlačenej klávesy zmeňte pozíciu mačky.
3.  Pre každú živú myšku skontrolujte, či nemá rovnakú pozíciu ako  mačka. Ak má, označte ju ako zjedenú.
4.  Náhodne pohnite všetkými živými myškami.
5.  Inak vypíšte počet živých myšiek a vykreslite mačku a každú živú myšku.

## Odovzdanie

Za vypracovanie máte možnosť získať body 7 bodov ako Aktivita2.

Vypracovaný príklad odovzdajte do súboru game.c v adresári `a2`.


## Doplnkové úlohy

  - Obkoleste hraciu plochu stenou a zabráňte myškám a mačke opustiť hraciu plochu.
  - Vymyslite veselšie farby.
  - Skúste navrhnúť ukladanie a nahrávanie hry.

## Doplnkové materiály

- [Programovanie založené na udalostiach](https://en.wikipedia.org/wiki/Event-driven_programming)
- [Ncurses Programming](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
-  [Kódy kláves, udalostí a farieb](https://pubs.opengroup.org/onlinepubs/007908799/xcurses/curses.h.html)
