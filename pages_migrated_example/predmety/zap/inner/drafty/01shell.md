# Prvé kroky s Linuxom a programovaním

##  Ciele:

Nacvičiť si základný pracovný postup pre programátorskú prácu v príkazovom riadku:

- Vytváranie adresárov a súborov,
- Pohyb po adresároch,
- Mazanie adresárov a súborov,
- Používanie textového editora,
- Používanie Makefile.

## Prihlásenie sa

Podľa Vášho operačného systému sa prihláste na server omega.tuke.sk.
Vaše prihlasovacie meno a heslo je rovnaké ako do systému MAIS.

- Ak používate Windows, nájdite program Putty
- Ak používate Linux, príkaz na prihlásenie je vo formáte:

        ssh ab123cd@omega.tuke.sk

Po prihlásení sa môžte porozhliadať po systéme príkazmi:

    ls
    cd
    pwd

Ako argumenty príkazov využite názvy špeciálnych adresárov, ako napr:

    ls ~ # Prepne Vás do domovského adresára
    cd / # Prepne Vás do koreňového adresára

### Úloha

1. Pomocou príkazu man zistite, čo presne robia jednotlivé príkazy a akým argumentom rozumejú.
1. Zistite ako sa volá Váš domovský adresár.

## Vytvorenie adresára s programami

Je výhodné, ak je Vaša práca na cvičení uložená v jednom adresári. Pomocou príkazu

    mkdir prog

si vytvorte adresár, kde budete ukladať Vašu prácu na cvičeniach. 
Ak ste sa pomýlili, môžete existujúci adresár premenovať príkazom mv.
Prepnite sa do nového adresára s využitím magického doplňovania:

    cd ./p<TAB>

Bodka je špeciálny názov pre aktuálny adresár. Po napísaní prvého písmena vie klávesa TAB inteligentne doplniť názov súboru.
K posledne napísaným príkazom sa viete vrátiť pomocou šípok. 

Žiaden príkaz nemusíte písať viac krát.

## Vytvorenie adresára s projektom

Vytvorte v adresári prog nový podadresár s názvom cv1.
Prepnite sa o adresár vyššie:

    cd ..

Názov .. je špeciálny názov pre adresár o úroveň vyššie.

###  Úloha 

Overenie si dosiahnutého výsledku:

Zistite, v akom adresári sa nachádzate a aký je jeho obsah. Prepnite sa späť do adresára cv1.

## Získanie kostry projektu a rozbalenie

Z adresy http://zzzz získajte kostru Vášho prvého projektu. Premiestnite ju do adresára cvičenie cv1.

    wget http://zzzz
    pwd
    ls # Overíme si aktuálny adresár a jeho obsah
    mv ./zzz.zip ~/prog/cv1 # Ak je to potrebné, premiestnime súbor a prepneme sa do správneho adresára.
    cd ~/prog/cv1

Rozbaľte ju príkazom unzip:

    unzip zzz.zip
    ls -l # Pozrieme čo sa rozbalilo

## Preklad programu

Pozrite si zdrojové kódy ktoré ste získali príkazom cat:

    cat hello.c

Preklad programu urobíme pomocou príkazu gcc:

    gcc hello.c

Ak je zdrojový kód v poriadku, objaví sa spustiteľný súbor s názvom a.out. Program môžeme preložiť a pomenovať v jednom kroku:

    gcc hello.c -o hello

Spustiteľný súbor sa bude podľa našich inštrukcií volať hello.

Môžeme sa podrobne pozrieť na stav nášho projektu:

    ls -l

Všimnite si príznaky súborov, ktoré hovoria o prístupových právach. Ako sa líši spustiteľný súbor hello od ostatných?

## Spustenie programu

Hotový prgram vieme spustiť príkazom:

    ./hello

Beh programu predčasne prerušíme klávesovou skratkou Ctrl+C alebo Ctrl+D. Pozor - Ctrl+D  (Koniec vstupu) Vás vie odhlásiť z terminálu.

## Vytvorenie súboru Makefile

V prostredí príkazového riadku vieme vytvárať nové textové súbory, ktoré budú obsahovať inštrukcie pre prekladač. Pomocou textového súboru si zjednodušíme proces prekladu. Na vytvorenie nového textového súboru použijeme textový editor:

    vim Makefile

Otvorí sa nám textový editor v normálnom móde. Stlačenia kláves sa nesprávajú podľa predpokladu, ale každá z nich má špeciálny význam. Stlačením klávesy i sa prepnite do vkladacieho módu a môžete písať. Keď ukončíte písanie, prepnite sa do normálneho módu klávesou ESC.

Napíšte:

    hello: hello.c
        gcc hello.c -o hello

Pozor: medzery v druhom riadku sú tvorené jedným tabulátorom. V prípade, že ste tam vložili štyri medzery sa systém nebude právať podľa očakávania.

Keď ste skončili prácu s editorom, napíšte v normálnom móde :wq.
Uloženie bez skončenia je :w, skončenie bez uloženia je :q!


## Preklad programu v prostredí ViM

Ak budete mať hotový súbor Makefile, preklad programu je hračkou a môžeme ho vykonávať priamo z prostredia textového editora.

Prepnite sa do Vášho programu príkazom e:

    :e ./hello.c

Podobne ako pri klasickom príkazovom riadku aj tu môžeme vyžívať históriu príkazov (začínajúcich sa dvojbodkou) pomocou šípok.

Keď napíšem:

    :

viem sa ľahko vrátiť k posledne zadaným príkazom. Klávesa TAB vie tiež dopĺňať názvy súborov.

V normálnom móde napíšte:

    :make

Mal by prebehnúť proces prekladu. Výsledok si môžete overiť volaním príkazov príkazového riadka priamo z prostredia editora:

    :!ls

A priamo z editora si môžeme program aj spustiť:

    :!./hello

## Vytvorenie si zálohy

### Úloha:

Vytvorte si adresár, do ktorého si budete dávať zálohy s názvom bak. Skopírujte do neho dnešný projekt,

Ak používate Windows, naučte ss používať program WinSCP pre vzdialený prístup k Vašim súborom na omege.

Skúste si Váš projektu uložiť do archívu a stiahnuť na lokálny stroj.

