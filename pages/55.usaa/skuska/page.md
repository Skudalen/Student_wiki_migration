---
title: Skúška
published: true
visible: true
---

## Skúška

Prednášajúci Vám pridelí 1 úlohu.  V prípade, že Vám úloha nevyhovuje, máte možnosť 1 x požiadať o pridelenie inej úlohy.

Na vypracovanie máte čas do jedného týždňa pred termínom skúšky. Prednášajúci do termínu skúšky  navrhne hodnotenie.  Navrhnuté hodnotenie obhájite v krátkej prezentácii kde predstavíte program a zodpoviete otázky. V prípade, že Vaše riešenie neobhájite, v opravnom termíne musíte vypracovať inú úlohu.

### Odovzdanie

- Riešenie odovzdávate na Git cez systém Traktor do príslušného adresára. 
- Odovzdanie sa uzatvára týždeň pred Vašim termínom skúšky. 
- Riešenie musí obsahovať `Makefile` pre preklad pomocou príkazu `make`. Príkaz `make` musí skompilovať program.
- Riešenie musí obsahovať `README.md` s dokumentáciou. Dokumentácia musí obsahovať zadanie, stručný opis funkčnosti, stručný opis riešenia a podmienky za ktorých funguje.

### Podmienky pre odovzdanie

Nesplnenie niektorej podmienky na odovzdanie je dôvodom na nulové hodnotenie. 

- Riešenie nesme využívať inú ako štandardnú knižnicu. 
- Riešenie sa môže inšpirovať voľne dostupným cudzím riešením za predpokladu že uvediete zdroj, ste podrobne oboznámený so zdrojovým kódom a viete odpovedať na otázky týkajúce sa kódu.
- Vaše riešenie nemôže kopírovať cudzie riešenie.

### Hodnotenie riešenia

Za 60 bodov.

- Funkčnosť. 40b
  - Funguje program správne ? Má správny výsledok ?
  - Obsahuje chyby ?
  - Správa sa program podľa očakávania ?
  - Je program univezálne použiteľný ? Funguje aj v zložitejších situáciách?
- Používateľská prívetivosť a dokumentácia. 20b
  - Je spustenie a používanie jednoduché ?
  - Obsahuje vstavanú nápovedu ? Program by mal mať zdokumentované používateľské rozhranie.
  - Sú kódy ľahko čitateľné  a zdokumentované ?
  - Je napísané v akých podmienkach program funguje správne ?
  - V prípade , že máte nárok na bonus zo zápočtu tak dokumentácia kódov nie je povinná.
- Originalita
  - Koľko cudzieho kódu ste využili pri riešení? Nízka originalita znamená nízke hodnotenie.

### Prezentácia

- Na maximálne 3 min, max 5 slajdov. Ako podklad využite dokumentáciu k Vášmu programu.
- Vysvetlite zadanie úlohy a čo Váš program robí.
- Vysvetlite aké údajové štruktúry a algoritmy ste použili na riešenie. 
- Uveďte zdroje ktoré Vám pomohli pri riešení.
- Predstavte ovládanie a funkčnosť Vášho programu.
- Buďte pripravený na cca 2-3 otázky (cca 5 min.) týkajúce sa Vášho riešenia.
- V prípade, že máte nárok na bonus zo zápočtu, nie je potrebná prezentácia, stačí stručne vysvetliť čo robí program.

### Hodnotenie prezentácie

Prezentácia a odpovede môžu ovplyvniť výsledné hodnotenie. 
- Viete stručne predstaviť Vaše riešenie?
- Zodpovedáte za odovzdané riešenie?
- Viete rýchlo predviesť funkčnosť Vášho programu?
- Viete pohotovo a plynulo odpovedať na otázky týkajúce sa zdrojového kódu?

## Príklady:

### 1. Kompressor

Naprogramuj nástroj na kompresiu a dekompresiu.
Na kompresiu použite jeden alebo viac kompresných algoritmov: Huffmanovo kódovanie, LZ77, LZ78, Run Length kódovanie alebo iný.

Meno vstupného a výstupného súboru načítajte ako argument príkazového riadka.
V zadaní by mali byť implementované tieto dve funkcie:

```c
/**
 * Skomprimuje súbor in a zapíše do súboru out. 
 * @arg in smerník na otvorený vstupný súbor (na čítanie)
 * @arg out smerník na otvorený výstupný súbor (na zápis)
 * @return počet bajtov skomprimovaného súboru
 */
int compress(FILE* in, FILE* out);
/**
 * Dekomprimuje súbor in a zapíše do súboru out. 
 * @arg in smerník na otvorený vstupný súbor (na čítanie)
 * @arg out smerník na otvorený výstupný súbor (na zápis)
 * @return počet bajtov dekomprimovaného  súboru
 */
void decompress(FILE* in, FILE* out);
```

Kompresor a dekompresor by mal byť schopný pracovať s ľubovoľným binárnym súborom do 10 MB. Súbor by mal byť po skomprimovaní menší minimálne o 10 percent a po dekomprimovaní by mal byť zhodný s pôvodným súborom.  Pri práci s binárnymi súbormi môžete využiť funkcie `fopen()`, `fread()` a `fwrite()`.

Na otestovanie kompresora a dekompresora použite súbory z [Cantebury corpus](https://en.wikipedia.org/wiki/Canterbury_corpus)


### 2. Psychiater

Vytvor konverzačný systém s ilúziou umelej inteligencie. Konverzačný systém by mal interaktívne komunikovať po slovensky.   Program by sa mal snažiť motivovať používateľa aby sa s ním zhováral o tom čo prežíva. 

- Vstup: Konverzácia od používateľa
- Výstup: Konverzácia od psychiatra
- Hodnotenie: inout



Pri reakcii musí vedieť "porozumieť" časti výpovede používateľa a porozumenie použiť pri odpovedi. Chatbot by mal mať databázu min. 40 rôznych viet ktorými vie reagovať. 

Chatbot musí minimálne 4 rôznymi spôsobmi reagovať na minimálne 60 rôznych kľúčových slov tak aby vytvoril ilúziu rozhovoru s psychoterapeutom. 
Inšpirujte sa: 

- https://www.masswerk.at/elizabot/
- https://www.cyberpsych.org/eliza/

V implementácii využite asociatívne pole pre vyhľadávanie kľúčových slovíčok.

### 3. Rigorózka

- Vstup: Text v slovenskom jazyku.
- Výstup: Iný text s podobnými štatistickými vlastnosťami.
- Hodnotenie: unit

Vymyslite program, ktorý bude vedieť generovať "zmysluplné" texty v slovenskom jazyku. Na "natrénovanie" generátora použite ľubovoľný dlhší text v slovenskom jazyku.

Najprv v texte identifikujte významové jednotky - slová a interpunkciu. Interpunkcia (bodka, čiarka, otáznik) sa počíta ako samostatné slovo. Inak povedané, interpunkcia by mala  byť obkolesená medzerami.

Z takto upraveného textu spočítajte početnosti n-tíci (min. dvojíc a jednoíc) za sebou nasledujúcich slov. 

Ak je vstupný text:

```
a b c, d c a b.
```

tak tokenizovaný text bude:

```
a b c , d c a b .
```

a slovník početností bude:

Jedno-ice:

```
a 2
b 2
c 2
d 1
. 1
, 1
```

Dvojice:

```
a b 2
b c 1
c , 1
, d 1
d c 1
c a 1
b . 1
```

Z početností n-tíc zostavte štatistický model slovenského jazyka. Model funguje tak, že si vie zapamätať početnosti jedno a dvojíc slov. Pravdepodobnosť slova `w2` na základe dvoch predošlých slov `w1` a `w2` vypočítate na základe početností výskytu trojíc a dvojíc..

Pravdepodobnosť nasledujúceho slova `w2` na základe predošlého slova `w1` `P(w2|w1)` vypočítate podľa vzťahu:

```
P(w2|w1) = 0.1 * C(w2)/N  + 0.9* (C(w1,w2) + 1) / (C(w1) + 1)
```

kde N je počet všetkých slov , C(w2) a C(w1) sú početnosti slov v texte a C(w1,w2) je početnosť dvojice w1 a w2 v texte.
Môžete použiť aj nejaký iný vzťah. Viac informácií sa dočítate v článku o [jazykovom modelovaní](https://en.wikipedia.org/wiki/Language_model) alebo v prezentácii ktorú napísal [Dan Jurafsky](https://web.stanford.edu/class/cs124/lec/languagemodeling.pdf).

Generovanie slov bude prebiehať tak, že najprv náhodne vyberiete jedno slovo zo slovníka. Pre všetky možné ďalšie slová vypočítate ich pravdepodobnosť.
Podľa zistenej pravdepodobnosti vyberiete ďalšie slovo.

Ak budete potrebovať ušetriť pamäť, pripravte si asociatívne pole v ktorom slovám priradíte celé čísla v intervale od 0 až po `n`.
Pre uloženie početností n-tíc slov vstupného textu použite asociatívne pole.
Naivné vyhľadávanie v slov v obyčajnom poli nebude fungovať, je potrebné použiť hešovaciu tabuľku alebo binárny vyhľadávací strom.

### 4. TUKAFUK

Virtuálny stroj programovacieho jazyka TUKAFUK sa skladá z dvoch pások.
Na jednej páske je napísaný program.  Po programovej páske beží programová hlava PH a číta inštrukcie zľava doprava. Stroj má k dispozícii aj  dátovú pásku s osobitnou hlavou DH.

Príklad počiatočného stavu virtuálneho stroja TUKAFUK:

```
          PH
          |
          v
        +-----+-----+-----+-----+
Program | TUK | INK | DEK | FUK |
        +-----+-----+-----+-----+

         DH
          |
          v
        +---+---+---+---+
Data    | 0 | 0 | 0 | 0 |
        +---+---+---+---+

```

Skladá sa z nasledujúcich symbolov:

```
TUK začiatok programu
INK  inkrementuj údaj na mieste kde ukazuje DH
DEK  dekrementuj údaj na mieste kde ukazuje DH
BREK  posuň hlavu DH do prava o jedno miesto
GLEK  posuň hlavu DH do ľava o jedno miesto
PUK  vypíš 1 byte z miesta kde ukazuje hlava DH
KUK  načítaj 1 byte na  miesto je ukazuje hlava DH
[  ak je hlava DH nula, posuň PH na zodpovedajúcu značku ]. Inak pokračj ďalej.
]  ak hlava nie je nula, pokračuj s PH na zodpovedajúvej značke [. Inak pokračuj ďalej.
FUK koniec programu
iný znak: odeľuje príkazy alebo slúži ako komentár.
```

Vytvorte interpret jazyka TUKAFUK. Program by mal implementovať funkciu:

```c
void run_tukafuk(const char* code);
```

Funkcia preloží vstupný program (zistí adresy skokov) a spustí ho. 
Preklad programu znamená identifikáciu inštrukcií a zistenie adries pre skok programovej hlavy PH. 
Pri implementácii zistenia adries PH v programe pre inštrukcie `[` a `]`.
Funkcie `getchar()` a `putchar()` použite pre implementáciu inštrukcií `PUK` a `KUK` .
Pre implementáciu dátovej pásky použite pole znakov, pre implementáciu programovej pásky použite pole spracovaných inštrukcií.

Vytvorte program v jazyku TUKAFUK na výpis celého Vášho mena. 

Testovacie programy budú zverejnené.

Testovací program 1:

```
TUK
INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK INK KUK
DEK DEK KUK
DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK KUK
KUK
DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK DEK KUK
FUK
```

Testovací program 2:

```
TUK
BREK BREK BREK INK BREK BREK BREK BREK BREK INK BREK BREK INK BREK BREK INK [ GLEK GLEK ] PUK 
[ DEK [ DEK [ DEK [ DEK [ DEK [ DEK [ DEK [ DEK [ GLEK INK BREK DEK [ 
BREK INK GLEK DEK [ BREK DEK GLEK DEK [ DEK [ DEK [ GLEK INK INK [ GLEK INK INK 
INK INK INK INK BREK DEK ] GLEK [ BREK BREK [ DEK GLEK ] GLEK [ BREK ] GLEK DEK ] BREK BREK [ GLEK INK BREK DEK 
[ GLEK DEK BREK [ DEK ] ] ] ] ] ] ] ] ] ] ] ] ] ] ] 
] GLEK [ DEK GLEK GLEK [ DEK ] INK BREK ] GLEK GLEK [ BREK BREK BREK BREK BREK BREK INK 
GLEK GLEK GLEK GLEK GLEK GLEK DEK ] BREK [ BREK ] BREK BREK BREK BREK BREK BREK BREK INK BREK 
[ GLEK INK [ BREK INK INK INK INK INK INK INK INK INK GLEK DEK [ BREK DEK GLEK DEK ] INK INK BREK 
[ GLEK INK INK INK INK INK INK INK BREK DEK [ GLEK DEK BREK DEK ] INK [ INK BREK 
BREK BREK BREK BREK BREK ] ] GLEK [ BREK INK GLEK DEK ] BREK [ BREK BREK BREK BREK BREK INK INK BREK [ DEK ] ] 
INK GLEK ] BREK [ DEK GLEK GLEK GLEK GLEK GLEK GLEK ] BREK BREK BREK BREK ] PUK ] INK GLEK INK INK BREK BREK BREK [ [ INK INK INK INK INK BREK BREK BREK BREK BREK BREK 
] GLEK INK BREK INK [ [ GLEK INK INK INK INK INK INK INK INK BREK DEK ] GLEK KUK 
GLEK GLEK GLEK GLEK GLEK ] BREK BREK BREK BREK BREK BREK BREK BREK ] [ PUK PUK KUK DEK DEK DEK DEK BREK KUK KUK KUK ] FUK
```

Pre inšpiráciu:

- https://stackoverflow.com/questions/2588163/implementing-brainfuck-loops-in-an-interpreter
- https://en.wikipedia.org/wiki/Brainfuck

### 5. Tajný agent

Nový hacker toolkit sa skladá z dvoch nástrojov - na šifrovanie a dešifrovanie textu. Hacker toolkit by mal  obsahovať minimálne dve funkcie a žiadne globálne premenné.


```c
// Vstup je anglický text a číslo n.
// Výstup je text, kde sú znaky v abecede posunuté o n miest.
void encode(const char* input,char* output, int key);

// Vstup je text z kódera.
// Výstup je rozkódovaný text.
void decode(const char* input,char* output);
```

Funkcia `encode` vykonáva šifrovanie textu pomocou zadaného kľúča. Kľúč je celé číslo.  Šifrovanie prebieha prebieha pomocou posunutia o niekoľko  miest v tabuľke písmen.


Funkcia `decode` dešifruje zadaný text bez toho aby bol známy tajný kľúč.  Pri dešifrovaní je možné použiť slovník najčastejších slov alebo frekvenčnú analýzu písmen. V zakódovanej správe zistite, s ako frekvenciou sa vyskytujú jednotlivé symboly. Zistenú frekvenciu všetkých symbolov porovnajte s frekvenciou symbolov bežného anglického textu. Pre presnejšie dekódovanie môžete použiť aj slovník najčastejších anglických  slov. 


