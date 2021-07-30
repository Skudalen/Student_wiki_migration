---
title: Tomáš a Juraj
published: true
---

! Naučíte sa:
!
! - Používať externú knižnicu a modulárny program.
! - Pracovať s pseudo-grafickým terminálom.
! - Reaktívne programovať.

Na Technickej Univerzite budú natáčať ďalší diel obľúbenej kreslenej grotesky Tomáš a Juraj. Diváci chcú vidieť nové príbehy mačky Tomáša a myšky Juraja čím skôr a tak požiadali o pomoc našu produkčnú firmu BN Computer Networks 32th Fox.

Animovať sa bude inovatívnou metódou ASCII Art animation. Do úlohy mačky Tomáša sa prihlásilo písmeno `c`, do úlohy myšky Juraja písmenko `m`.

Vašou prvou úlohou bude rozbehať animáciu mačky a myši na obrazovke a pomocou šípiek na klávesnici navigovať mačku tak aby chytila myš.

Ak sa Vám to podarí, v druhom dieli angažujte ďalších myších hercov a natočte diel v ktorom mačka Tomáš chytá až päť myšiek naraz. Počet aktuálne chytených myšiek nech zobrazí počítadlo. Ak Tomáš myšku chytí (ocitne sa na rovnakom mieste) tak odstráňte myšku z hracej plochy a zvýšte počítadlo o jedna. Ak Tomáš chytí všetky myšky, vypíšte vtipnú správu na obrazovku a skončite.

![By Unknown photographer - This image was released by the National
Cancer Institute](640px-Scid_mouse.jpg)

## Naštudujte si

Pomocou knižnice Svet viete vytvoriť jednoduchú akčnú hru s textovo-grafickým rozhraním bez toho, aby ste museli poznať detaily programovania terminálov.

Najprv sa oboznámte s knižnicou [Svet](https://github.com/hladek/world).

- Dokumentáciu nájdete v súbore [world.h](https://github.com/hladek/world/blob/master/world.h)
- Príklad použitia API nájdete v súbore [game.c](https://github.com/hladek/world/blob/master/game.c)

## Herné udalosti

Hra je založená na reakcii na udalosti, ktoré modifikujú stav.
Udalosť môže byť čokoľvek čo je dôležité pre hru, ako je:

- stlačenie klávesy,
- pohyb myšou,
- zmena rozlíšenia obrazovky
- uplynutie časového intervalu 


```
+------+                    +---------+
| Stav |   <--modifikuje--  | handler |  <-- Udalosti
+------+                    +---------+
```

Knižnica `world` je schopná zachytiť udalosť a informovať o tom programátora.
Ak nastane nejaká udalosť, vyvolá funkciu (handler) ktorá spracuje udalosť a podľa toho modifikuje stav hry.

Udalosti zaujímavé pre hru sú zachytené v hlavnej slučke (v súbore `world.c`).

Slučka pre zachytenie udalosti pracuje takto:

1. Inicializuj knižnicu.
1. Priprav potrebné premenné.
1. Čakaj na udalosť.
1. Keď udalosť príde, urči typ udalosti a zavolaj handler. 
1. Ak handler vráti nenulovú hodnotu, ukončí slučku.
1. Inak čakaj na novú udalosť.

Túto hlavnú slučku nemusíte vymyšľať nanovo. Ak chcete naprogramovať vlastnú hru, stačí naprogramovať vlastný handler ktorý zachytí udalosť a modifikuje stav hry.

### Stav hry

Na začiatku sa vyhradí a inicializuje pamäť pre uloženie stavu hry.
Stav hry je množina premenných nevyhnutných a postačujúcich pre hru.

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

Alokáciu pamäte pre stav hry si zaobalíme do funkcie `init_game()`. Smern9k na túto funkciu odovzdáme pri štarte knižnice `world` ktorá sa postará jej zavolanie v správnom momente.

Vo funkcii `init_game()` Alokujeme pamäť pre novú hru, nastavíme počiatočné hodnoty
a vrátime adresu pamäte kde sa nachádza nová hra:

```c
// Návratová hodnota je adresa s novou hrou
void* init_game(){
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

Na zmenu stavu sveta a vykreslenie používame handler funkciu `world_event()`. Všetky argumenty Vám pošle knižnica `world`.


```
int world_event(struct event* event,void* g){
    struct game* game = (struct game*)g;
    // Tu píšeme pravidlá hry
    // Načítame event podľa toho
    // zmeníme a vykreslíme game

    return 0;
}
```

Prvý argument `event` je informácia o aktuálnej udalosti. Informácie o udalosti pre nás pripraví knižnica.  Typ udalosti sa nachádza v premennej `event->type`.
V prípade, že udalosť sa týka klávesnice, kód stlačenej klávesy sa nachádza v premennej `event->key`.
Dostupné kódy kláves sa nachádzajú dokumentácii.

Druhý argument je smerník na hru `game`, ktorú sme si vytvorili vo  funkcii `init_game()`. Smerník na stav hry  `game` si musíme pretypovať z všeobecného smerníka `void*` aby sa nám s ním pracovalo ľahšie:
K premenným stavu hry `game` vieme pristupovať pomocou operátora `->`, napr. `game->mousey` je vyjadruje `y` pozíciu myšky. 


Algoritmus pre hru môže vyzerať takto:

1. Ak sa mačka a myš nachádza na tom istom mieste, tak vypíšte správu.
1. alebo ak sa vyskytlo stlačenie klávesy, tak upravte polohu mačky
1. alebo ak sa nevyskytlo stlačenie klávesy, tak pohnite myškou po ploche.
1. Vykreslite polohu mačky, myšky a správu ak je nejaká.

## Vykreslenie hry

Na vykreslenie sveta nám stačí nám použiť jedinú funkciu - povedať aký znak chceme vykresliť a na ktoré miesto.

Použijeme na to funkciu `set_cell()`.
Prvý argument `event` je smerník na aktuálny stav sveta obrazovky a klávesnice. Druhý argument je znak na vykreslenie. Tretí a štvrtý argument sú súradnice `x` a `y` kde na obrazovke sa má znak vykresliť.

Bod `0,0` je podľa dohody v ľavom hornom rohu obrazovky.

Ak napíšeme tieto príkazy:


```
set_cell('c',3,2);
set_cell('m',3,4);
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

## Preloženie a spustenie

Skúste si preložiť a spustiť vzorovú hru kde mačka chytá myš.
Na to aby ste hru "Tomáš a Juraj" preložili a spustili musíte mať najprv nainštalovanú knižnicu `curses`. Je nainštalovaná na servri Omega alebo na Vašom virtuálnom stroji s Linuxom.

Ak používate systém typu Debian, knižnicu nainštalujete príkazom:

```bash
sudo apt-get install libncurses5-dev
```

Prvým krokom bude získanie zdrojových kódov a ich zostavenie.
Stiahnite a rozbaľte kostru zadania do adresára `a4`.

```
wget https://github.com/hladek/world/archive/master.zip
unzip master.zip
mv world-master a4
cd a4
make
```

Celý program zostavíte príkazom `make`. Inštrukcie pre zostavenie sa nachádzajú v súbore `Makefile`.

### Modifikácia hry pre viacero myšiek


Najprv modifikujte súbor `game.h`.
Vašou úlohou bude modifikovať zdrojové kódy tak, aby mohlo byť na obrazovke viac myší naraz. 
Pozícia myšiek a informácia o tom či sú zjedené alebo nie je súčasťou aktuálneho stavu hry. To potrebujeme vyjadriť v štruktúre so stavom hry `sruct game`.

Maximálny počet myšiek si vieme zadefinovať
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

### Modifikácia stavu hry

Pozrite si aktuálnu implementáciu hry v súbore `game.c`, kde mačka chytá myš. 
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

1.  Vo funkcii `create_world` náhodne inicializujte pozíciu mačky a myšiek na obrazovke.
2.  Ak je počet živých myšiek nula, vypíšte správu a skončite hru.
2.  Podľa stlačenej klávesy zmeňte pozíciu mačky.
3.  Pre každú živú myšku skontrolujte, či nemá rovnakú pozíciu ako  mačka. Ak má, označte ju ako zjedenú.
4.  Náhodne pohnite všetkými živými myškami.
5.  Inak vypíšte počet živých myšiek a vykreslite mačku a každú živú myšku.

## Odovzdanie

Za vypracovanie máte možnosť získať body 7 bodov ako Aktivita4.

Vypracovaný príklad odovzdajte cez [Traktor](https://traktor.kemt.fei.tuke.sk/#submit/157) do súboru game.c v adresári `a4`.
Automatické hodnotenie v tomto prípade nepočíta, úlohu Vám osobne ohodnotí Váš cvičiaci, najneskôr do 13. týždňa.

Na zisk 90 percent bodov Váše riešenie musí:

- byť kompletné a preložiteľné.
- obsahovať hru s 5 myškami.
- kontrolovať a zabrániť opusteniu hernej plohy myškami alebo mačkou.

Na zisk 100 percent:

- Obkoleste hraciu plochu stenou a zabráňte myškám a mačke opustiť hraciu plochu.
- Použite veselšie farby.

Doplnkové úlohy:

- Skúste navrhnúť ukladanie a nahrávanie hry.
- Umiestnite na plochy prekážky.

## Doplnkové materiály

- [Programovanie založené na udalostiach](https://en.wikipedia.org/wiki/Event-driven_programming)
- [Ncurses Programming](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
- [Kódy kláves, udalostí a farieb](https://pubs.opengroup.org/onlinepubs/007908799/xcurses/curses.h.html)
