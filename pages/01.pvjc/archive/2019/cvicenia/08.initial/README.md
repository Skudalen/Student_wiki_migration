# 8\. Tomáš a Juraj

<div class="tip">

<div class="title">

Zopakujete si

</div>

  - Pracovať so smerníkom na štruktúru.

  - Používať externú knižnicu a modulárny program.

  - Pracovať s pseudo grafickým terminálom.

  - Generovať celé náhodné číslo.

</div>

Na Technickej Univerzite budú natáčať ďalší dieľ obľúbenej kreslenej
grotesky Tomáš a Juraj. Diváci chcú vidieť nové príbehy mačky Tomáša a
myšky Juraja čím skôr a tak požiadali o pomoc našu produkčnú firmu BN
Computer Networks 32th Fox.

Animovať sa bude inovatívnou metódou ASCII Art animation. Do úlohy mačky
Tomáša sa prihlásilo písmeno `c`, do úlohy myšky Juraja písmenko `m`.

Vašou prvou úlohou bude rozbehať animáciu mačky a myši na obrazovke a
pomocou šípiek na klávesnici navigovať mačku tak aby chytila myš.

Ak sa Vám to podarí, v druhom dieli angažujte ďalších myších hercov a
natočte diel v ktorom mačka Tomáš chytá až päť myšiek naraz. Počet
aktuálne chytených myšiek nech zobrazí počítadlo. Ak Tomáš myšku chytí
(ocitne sa na rovnakom mieste) tak odstráňte myšku z hracej plochy a
zvýšte počítadlo o jedna. Ak Tomáš chytí všetky myšky, vypíšte vtipnú
správu na obrazovku a skončite.

![By Unknown photographer - This image was released by the National
Cancer Institute](640px-Scid_mouse.jpg)

# Naštudujte si

Najprv sa oboznámte s knižnicou [Svet](https://github.com/hladek/world).

# Návrh riešenia

Prvým krokom bude získanie zdrojových kódov a ich zostavenie.

Na to aby ste hru "Tomáš a Juraj" preložili a spustili musíte mať najprv
nainštalovanú knižnicu Termbox.

Pozrite si aktuálnu implementáciu hry v súbore `game.c`, kde mačka chytá
myš. Na začiatku sa vyhradí a inicializuje pamäť pre uloženie stavu hry.
Stav hry je množina premenných nevyhnutných a postačujúcich pre hru.

V našom prípade na túto hru stačí poznať pozíciu mačky a myši. To si
vieme vyjadriť ako štruktúru:

``` c
struct state {
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

K premenným stavu vieme pristupovať pomocou operátora `→`, napr.
`state→mousey` je vyjadruje `y` pozíciu myšky ak je smerník na stav
(`struct state*`) uloženy v premennej `state`.

Smerník na stav získame z premennej `world`

``` c
struct state* state = world->state;
```

Vašou úlohou bude modifikovať zdrojové kódy tak, aby mohlo byť na
obrazovke viac myší naraz. Maximálny počet myšiek si vieme zadefinovať
ako konštantu:

``` c
#define MOUSE_COUNT 5
```

To znamená, že potrebujeme rozšíriť pamäť na uchovanie pozície myšky v
štrukture `struct state`, napr.

``` c
int mousex[MOUSE_COUNT];
int mousey[MOUSE_COUNT];
```

Takéto polia nám umožnia uchovať pozíciu až piatich myší. Pri návrhu
potrebných dátových typov sa samozrejme fantázii medze nekladú. Na
uchovanie pozície 5 myši môžete využiť aj dvojrozmerné pole:

``` c
int mouse[MOUSE_COUNT][2];
```

Každá myška v hracom poli môže byť už zjedená. Môžme si povedať, že
zjedená myška je taká, ktorej súradnice sú záporné. Kontrola či je myška
zjedená môže vyzerať napr. takto:

``` c
for (int i = 0; i < MOUSE_COUNT;i++){
    // Ak myška žije
    if (st->mousex[i] >= 0){
        // Ak mačka chytila myš
        if (st->mousex[i] == st->catx && st->mousey[i] == st->caty){
            // Myška domyšila
            st->mousex[i] = -1;
            st->mousey[i] = -1;
        }
    }
}
```

Pri generovaní náhodného pohybu myšky sa môžete inšpirovať vzorovým
kódom:

``` c
int m = rand() % 4;
if (m == 0){
    st->mousey -= 1;
}
else if (m == 1){
    st->mousey += 1;
}
else if (m == 2){
    st->mousex -= 1;
}
else if (m == 3){
    st->mousex += 1;
}
```

Funkcia `rand()` vygeneruje náhodné celé číslo. Operátor `%` vracia
zvyšok po celočíselnopm delení. Celý výraz vráti náhodné číslo v
intervale 0 až 3.

Pohyb mačky je riešený podobne, ale nezávisí od náhodnej hodnoty ale od
aktuálne stlačenej klávesy.

Výsledný algoritmus môže vyzerať takto:

1.  Na začiatku náhodne inicializujte pozíciu mačky a myšiek na
    obrazovke.

2.  Podľa stlačenej klávesy zmeňte pozíciu mačky.

3.  Pre každú živú myšku skontrolujte, či nemá rovnakú pozíciu ako
    mačka.

4.  Ak má, nastavte jej pozíciu na negatívne hodnoty.

5.  Náhodne pohnite všetkými živými myškami.

6.  Ak je počet živých myšiek nula, vypíšte správu a skončite hru.

7.  Inak vypíšte počet živých myšiek a vykreslite mačku a každú živú
    myšku.

## Doplnkové úlohy

  - Obkoleste hraciu plochu stenou a zabráňte myškám a mačke opustiť
    hraciu plohu.

  - Vymyslite veselšie farby.

  - Skúste navrnúť ukladanie a nahrávanie hry.

# Odovzdanie

Úlohu odovzdajte do repozitára `pvjc19cv8`. Ak sa Vám úlohu podarí
dokončiť na cvičení, získavate 2 body za aktivitu.

Kostru zadania môžte získať ako [zip
súbor](https://github.com/hladek/world/archive/master.zip). Nezabudnite
adresár po rozbalení vhodne premenovať:

    wget https://github.com/hladek/world/archive/master.zip
    unzip master.zip
    mv world-master pvjc19cv8

V prípade problémov so spustením:

    ./game: error while loading shared libraries: libtermbox.so.1: cannot open shared object file: No such file or directory

Vykonajte príkaz:

    export LD_LIBRARY_PATH=/usr/local/lib

aby dynamický linker vedel nájsť cestu k dynamickej knižnici potrebnej
pre spustenie Vášho programu.
