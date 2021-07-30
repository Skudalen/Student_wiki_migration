Tutoriál č. 3

V treťom bloku sa naučíme vytvárať a využívať vlastné funkcie.

Potrebné znalosti z predošlého tutoriálu.

Naučíte sa:

  - volanie funkcie bez parametrov

  - parametre funkcie

  - volanie funkcie odovzdávanie parametrov kópiou

  - návratová hodnota funkcie a jej využitie

# Definícia funkcie

S vytváraním a využívaním funkcií v jazyku C sme sa už stretli, možno aj
bez toho aby ste to vedeli. V našom hračkovom programe sme si už
definovali vlastnú funkciu, ktorej sme dali meno main.

``` c
#include <stdio.h>

int main(){
    printf("Ahoj svet\n");
    return 0;
}
```

Definícia funkcie sa skladá z nasledovných častí: - návratový typ (v
tomto prípade int) - názov funkcie (v tomto prípade main) - argumenty
funkcie (uvedené v okrúhlych zátvorkách, v tomto prípade žiadne) - telo
funkcie (časť v zložených zátvorkách)

Ak určíme nejaký návratový typ, tak sľubujeme prekladaču, že pomocou
príkazu return vrátime hodnotu daného typu. Príkaz return spôsobí
okamžité prerušenie vykonávania funkcie a funkcia vráti danú hodnotu,
ktorú je možné ďalej spracovávať. Posledný príkaz

    return 0;

ukončí vykonávanie hlavnej funkcie a operačnému systému odovzdá hodnotu
0. Ak ako návratový typ určíme void, neočakávame žiadnu návratovú
hodnotu a príkaz return nemusíme uviesť. Tieto znalosti môžeme využiť a
definovať si vlastnú funkciu pre výpis správy.

``` c
#include <stdio.h>

void pozdrav(){
    printf("Dobry den\n");
}

int main(){
    printf("Ahoj svet\n");
    return 0;
}
```

Čo sa stane? Preklad programu prebehne úspešne, to znamená, že program
je syntakticky správny. Napriek očakávaniu ale zdvorilý pozdrav nebude
vypísaný.

\#=== Ǔlohy na precvičenie:

Ćo sa stane, keď vynecháme príkaz return z hlavnej funkcie? Čo sa stane,
keď hlavnej funkcii určíme návratový typ void?

# Volanie funkcie

Definícia funkcie je určitým spôsobom ekvivalentná k definícii slova v
slovníku. Ak poznáme slovo, to ešte neznamená, že sme ho použili. Ak
chceme definovanú funkciu aj použiť, musíme ju **zavolať**. Volanie
funkcie bez parametrov vykonáme zapísaním mena funnkcie a prázdnych
okrúhlych zátvoriek. Každý príkaz musíme ukončiť bodkočiarkou.

``` c
#include <stdio.h>

void pozdrav(){
    printf("Dobry den\n");
}

int main(){
    pozdrav();
    printf("Ahoj svet\n");
    return 0;
}
```

Zistili sme, že volanie vlastnej funkcie sa neodlišuje od volania
funkcie zo štandardnej knižnice. Náš jednoduchý program neobsahuje
príkaz na vykonanie funkcie main. Podľa dohody sa o niečo také stará
operačný systém pri spustení programu. Operačný systém pri spustení
programu vyhľadá definíciu funkcie main a tej odovzdá riadenie. Až potom
sa vykonávajú funkcie, ktoré určil programátor.

# Návratová hodnota a argumenty funkcie

``` c
void pozdrav(){
    printf("Dobry den\n");
}
```

Takto definovaná funkcia nemá definovanú návratový hodnotu. Výpis
správy, ktorý funkcia vykoná je možné brať ako **vedľajší efekt**,
ktorý nemá priamy súvis so vstupom funkcie.

Funkciu si môžeme predstaviť ako kuchynského robota, ktorý vie spracovať
určitý druh potravín. Vstupné argumenty sú suroviny, ktoré vkladáme do
kuchynského robota. Návratový typ je výsledok spracovania vstupných
surovín. Napríklad možným vstupom do mlynčeka na mäso je kus mäsa a
výstupom je mleté mäso. Automatický mlynček na mäso bude mať problémy s
niektorými surovinami. Napríklad orechy alebo hrozno na vstupe môžu
spôsobiť zničenie robota alebo výstup nebude mať očakávané vlastnosti.

Funkcia, ktorú sme definovali vyššie nemá definované vstupné argumenty
ani výstupný typ. Funkciu si môžeme definovať tak, že výstupná hodnota
závisí od vstupných argumentov. Vstupné argumenty sú definície
premenných do ktorých sa priradí hodnota počas volania funkcie. Vstupné
premenné uvedieme počas definície do okrúhlych zátvoriek a oddelíme ich
čiarkou.

``` c
int spocitaj(int a,int b){
    return a + b;
}
```

    Týmto kusom kódu sme definovali funkciu, ktorá vezme dva čísla, spočíta ich a vráti výsledok ako návratovú hodnotu.
    Takúto funkciu vieme použiť na ľubovoľné premenné alebo hodnoty, stačí ich zadať ako argumenty funkcie:

```` 
 ```c
#include <stdio.h>
````

int spocitaj(int a,int b){ return a + b; }

int main(){ spocitaj(2,3); return 0; }

    Ak si vyskúšame takýto program, zistíme, že nie je veľmi užitočný. Napriek tomu, že vykonáme operáciu spočítania, výsledok sa nedostaví.
    Je to z toho dôvodu, že sme na to nedali príkaz. Program poslušne vykoná to, o čo sme ho požiadali, ale nič viac.
    Na to aby sme zobrazili návratovú hodnotu funkcie musíme pripraviť špeciálny príkaz. Najlepšie bude, ak si návratovú hodnotu uložíme
    do premennej a obsah premennej vypíšeme. Dávajme ale pozor, aby formátovacia značka sedela s typom premennej:
    
     ```c
    #include <stdio.h>
    
    int spocitaj(int a,int b){
        return a + b;
    }
    
    int main(){
        int vysledok = spocitaj(2,3);
        printf("Vysledok spocitania 2 + 3 je %d\n",vysledok);
        return 0;
    }

Tento program je oveľa užitočnejší. Najprv si definujeme premennú
výsledok a do nej si uložíme návratovú hodnotu funkcie spocitaj.
Funkcia printf spôsobí výpis správy na obrazovku ako vedľajší efekt
vykonania. Meno premennej, ktorá obsahuje hodnotu ktorá sa má vypísať
uvedieme ako argument. Návratová hodnota funkcie printf nás nezaujíma,
preto ju ignorujeme. Návratová hodnota celého programu bude 0, čo je
signál operačnému systému, že je všetko v poriadku.

Keďže už vieme definovať vlastné funkcie s argumentami aj pracovať s
návratovými hodnotami, môžeme si definovať funkciu, ktorá spočíva
ľubovoľné dve čísla a výsledok výpíše na obrazovku. Využijeme kód,
ktorý už ovládame:

``` c
#include <stdio.h>

int spocitaj(int a,int b){
    return a + b;
}

void vypis_sucet(int a,int b){
    int vysledok = spocitaj(a,b);
    printf("Vysledok spocitania %d + %d je %d\n",a,b,vysledok);
}

int main(){
    vypis_sucet(4,5);
    return 0;
}
```

Nová funkcia vypis\_sucet nemá definovanú návratovú hodnotu, preto je
múžeme ignorovať. Vedľajší efekt spustenia bude vykonanmie operácie
sčítania a výpis správy s výsledkom. Argumenty funkcie vypis\_sucet sa
správajú ako bežné premenné a tak ich aj môžeme využívať.

# Úloha na precvičenie

Aký bude výsledok volania funkcie vypis\_sucet(4.5,4.5) ? Aká bude
návratová hodnota a čo sa vypíše na obrazovku?

# Deklarácia a definícia funkcie

Pri definícii funkcií môžeme oddeliť časť
