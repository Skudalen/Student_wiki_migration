# Znakový vstup a výstup - CAPS Lock

<div class="tip">

<div class="title">

Zopakujete si

</div>

  - Načítanie po znakoch.

  - Koniec vstupu sa vyznačuje ako EOF.

  - Zopakujte si formátovaný výstup.

  - Písmeno je zakódované ako ASCII kód.

  - Zopakujete si prácu s premennými.

  - Zopakujete si prácu s cyklami a podmienkami.

</div>

Po krátkom zimmom oddychu tu je zase práca. Na študijnom oddelení majú
technické problémy so zápisom výsledkov minulého semestra. Na všetkých
klávesniciach sa pokazila klávesa CAPS LOCK čo značne komplikuje písanie
pracovných výkazov a iných dôležitých dokumentov. Verejné obstarávanie
na nové klávesnice je už vypísane, ale bude ukončené najskôr v septembri
roku 2021. Ako dočasné riešenie navrhlo vedenie univerzity využiť
šikovných študentov odboru Počítačové siete.

Mali by sme navrhnúť softvérové riešenie, ktoré by čo najlepšie
simulovalo klávesu CAPS LOCK. Zo štandardného vstupu budeme postupne
načítať znaky pomocou funkcie getchar(). V prípade že načítame veľké
písmeno, premeníme ho na malé a vypíšeme. V prípade, že načítame malé
písmeno, premeníme ho na veľké a vypíšeme. Všetky ostatné znaky necháme
bez zmeny. Koniec pracovnej doby budú používatelia nášho programu
signalizovať klávesou CTRL+D. Ak to zistíme, tak ukončíme program a
vypíšeme správu o počte spracovaných riadkov.

``` c
printf("\nPočet riadkov: %d\n",counter);
```

# Návrh riešenia

<div class="tip">

<div class="title">

Vedeli ste?

</div>

  - Nedostatky klávesy CAPS LOCK sa dajú riešiť aj úpravou hardvéru.

</div>

![caps-lock-flickr-cc](caps-lock-flickr-cc-dipurinku-sm-2.jpg)

Budeme potrebovať tieto premenné:

  - Práve načítaný znak (typ `int`).

  - Znak, ktorý sa vypíše (`char`)

  - Počet riadkov (`int`).

a tieto funkcie:

  - [getchar()](http://www.cplusplus.com/reference/cstdio/getchar/) na
    načítanie znaku.

  - [putchar()](http://www.cplusplus.com/reference/cstdio/putchar/) na
    výpis znaku.

  - [printf()](http://www.cplusplus.com/reference/cstdio/printf/) na
    výpis obsahu premennej.

Pri riešení môžme využiť fakt, že znak je zakódovaný ako číslo z [ASCII
tabuľky](https://en.wikipedia.org/wiki/ASCII) . Na obrazovke sa
zobrazuje ako znak, ale v pamäti má celočíselnú hodnotu, ktorá je iná
ako tá, ktorá je zobrazená. Napr. znak `0` má hodnotu 48. So znakmi je
možné robiť rovnaké operácie ako s číslami - porovnávať aj sčítavať.
Vhodnou operáciou odčítania alebo sčítania je možné zmeniť veľký znak na
malý a naopak.

Pri vstupe sa môže vyskytnúť aj "neočakávaná" situácia - koniec. Ten je
zakódovaný ako špeciálna konštanta `EOF` a má zväčša hodnotu -1, preto
na uloženie načítaného znaku potrebujeme premennú typu `int`. Pokus o
vypísanie načítaného `EOF` môže spôsobiť neočakávané chovanie.

## Algoritmus

Pri riešení môžete využiť tento postup:

1.  Vytvorte slučku, v ktorej budete do premennej typu `int` načítavať
    znak.

2.  V prípade, že je načítaný znak EOF ukončite slučku.

3.  Navrhnite pravidlá, ktoré zmenia načítavaný znak podľa potreby
    (veľké písmeno na malé a naopak). Použite na to ASCII tabuľku.

4.  Pridajte pravidlo, ktoré inkrementuje počítadlo v prípade, že
    načítaný znak je koniec riadku.

5.  Ak bude ukončená hlavná slučka vypíšte obsah počítadla.

# Spätná väzba

Vaše riešenie budete odovzdávať pomocou systému
[Traktor](https://nlp.web.tuke.sk/traktor), ktorý Vám poskytne okamžitú
spätnú väzbu. Vypracujte program tak, aby vyhovel čo najväčšiemu počtu
automatických testov.

Spätná väzba bude časovo obmedzená, sledujte prosím časový termín
posledného hodnotenia.

Heslo na prístup do predmetu "Programovanie" je `pvjc19`. Po prihlásení
do predmetu prosím vyberte Vašu skupinu. Heslo na prístup do cvičenia
`pvjc19cv1`.

# Domáca úloha

Za 3 body.

  - Dokončite dnešné cvičenie

  - Vyskúšajte si prístup na Omegu

  - [Aktivujte si prístup na
    GIT](https://student.kemt.fei.tuke.sk/pvjc/materialy/git/).
