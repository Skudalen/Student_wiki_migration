---
title: Vlak do neba
published: true
---
# Spojkový zoznam

Naša nová pracovná pozícia je na železnici. Vďaka významným úspechom dosiahnutých
na predošlých postoch sme boli nominovaní na pozíciu krízového manažéra s cieľom zachrániť
hospodárske výsledky národného vlakového prepravcu.

V stanici Košice často dochádza ku chaosu v radení vlakov. Vozne, ktoré sú určené na prepravu do Prešova
niekedy končia v Čiernej nad Tisou a cestujúci do Popradu končia v Levoči.
A to už je vážne, lebo do Levoče vlaky jazdia iba raz za rok.

Výsledkom dnešnej práce bude pamäťová štruktúra spojkový zoznam, vhodná na uloženie informácii o radení vlaku.
O každom vozni vo vlaku budeme evidovať jeho cieľovú stanicu.
Budeme potrebovať funkcie na pridanie nového záznamu, zrušenie zoznamu a výpis prvkov zoznamu. Hlavnou funkciou programu bude
vymazanie informácií o určenej cieľovej stanici.

## Ciele

Oboznámite sa s týmito funkciami spojkového zoznamu:

- Pridanie na koniec spojkového zoznamu.
- Výpis spojkového zoznamu.
- Zrušenie spojkového zoznamu.
- Zrušenie ľubovoľného prvku spojkového zoznamu.

## Spojkový zoznam

Dátová štruktúra, ktorá najviac pripomína vlak sa nazýva spojkový zoznam. Do spojkového zoznamu si vieme uložiť údaje
podobne ako do vozňa a vozeň pripojiť k vlaku, ktorý obsahuje ďalšie položky.
Najväčšou výhodou spojkového zoznamu je, že sa dá veľmi ľahko modifikovať . Nové údaje môžeme ľahko pridať na ľubovoľné miesto
spojkového zoznamu. Staré údaje môžeme vymazať aj z prostriedku a vlak spojiť.


Dátová štruktúra pre jeden prvok spojkového zoznamu je tvorená:

- Hodnotou, ktorá sa má uložiť.
- Smerníkom na ďalší prvok. Tento smerník je nulový v prípade, že je prvok posledný v zozname.

Dátová štruktúra by mala vyzerať nejako takto:

```c
struct car {
    char value[SIZE]; // Cieľová stanica
    struct car* next; // Ďaľší záznam, môže byť NULL
}
```

Najdôležitejšou časťou je smerník na ďalší prvok spojkového zoznamu.
Nulový odkaz na ďalší prvok zároveň slúži ako indikátor konca spojkového zoznamu. V prípade, že má smerník hodnotu `NULL`
tak vieme, že prvok je posledný.


Spojkový zoznam je dynamicky alokovaná štruktúra, to znamená že pri jeho návrhu musíme využiť
funkcie pre vyhradenie a zrušenie pamäte  `calloc` a `free`.

- [calloc()](http://www.cplusplus.com/reference/cstdlib/calloc/)
- [free()](http://www.cplusplus.com/reference/cstdlib/free/)

## Príprava

### Oboznámte sa so šablónou

Získajte [šablónu](cv5.zip) a skúste si ju preložiť.

```bash
# Prihláste sa na pracovný server a otvorte si pracovný repozitár:
cd ~/usaa20
# Získajte šablónu
curl https://student.kemt.fei.tuke.sk/predmety/usaa/cvicenia/linked/cv5.zip -o cv5.zip
# rozbaľte šablónu
unzip cv5.zip
# Archív už nie je potrebný
rm cv5.zip
# Zmente adresár
cd cv5
# Pozrite si predpisy funkcií ktoré máte vytvoriť
cat a_train.h
# Editujte súbor so zadaním
vim a_train.c
# Preložte program
make
```


Potrebné konštanty a dátové typy sú v súbore `a_train.h`. Nachádza sa tam aj dokumentácia a predpisy funkcií, ktoré máte navrhnúť.
Pravidlá pre preklad sú v súbore `Makefile`.

### Spôsob odovzdania


- odovzdanie cez [GIT](https://git.kemt.fei.tuke.sk)
- za 4 body
- hodnotenie systémom [Traktor](https://traktor.kemt.fei.tuke.sk).

V tomto zadaní budete hodnotení pomocou jednotkových testov funkcií ktoré máte vytvoriť.  Budete odovzdávať obsah súboru `a_train.c` podľa predpisov a dokumentácie v súbore `a_train.h`.

Používateľskú funkčnosť Vášho programu  a znalosť zdrojových kódov predstavíte v rámci osobnej obhajoby.

## Ako na to

Vašou úlohou bude implementovať funkcie v súbore `a_train.c` podľa dokumentácie  súbore `a_train.h`.

### Implementujte funkciu na pridanie prvku na koniec spojkového zoznamu

Pridanie do spojkového zoznamu by malo spĺňať predpis:

```c
struct car* add_car(struct car* first,const char* target);
```

Funkcia by mala dynamicky vyhradiť pamäť pre jednu položku typu `struct car`.
Do nej bude potrebné nakopírovať hodnoty, ktoré sa majú uložiť v jednom prvku spojkového zoznamu.
Určite budete potrebovať dynamicky alokovať  novú pamäť:

```
struct car* newcar = calloc(1,sizeof(struct car));
```

Funkcia `calloc` má príjemnú vlastnosť, že nastaví hodnotu všetkých bajtov na nulu. Nemusíme ju potom inicializovať osobitne.

Skopírujte názov stanice do nového vozňa:

! Musíte použiť funkciu na kopírovanie reťazcov, napr. `strcpy` .
Obyčajné nakpírovanie smerníka na začiatok reťazca nepomôže.

```
strcpy(newcar->value, target);
```

Vyhľadajte koniec spojkového zoznamu. Ak je smerník `first` nulový, potom je pôvodný zoznam prázdny. 
Ak je spojkový zoznam prázdny (prvý prvok je nulový), tak nový prvok bude na začiatku a vrátime na neho smerník.

Ak je zoznam neprázdny, v smerníku `first` sa bude nachádzať adresa prvého prvku. 

Posledný prvok nájdete tak, že sa pozriete na ďalší prvok `next` pokiaľ nebude nulový. Prvok, ktorého smerník `next` je nulový je posledný.
Na uloženie aktuálneho prvku v slučke si vytvorte pomocnú premennú `this`:

```
struct car* this = first;
```

Potom v cykle postupne prejdite všetky prvky, pokiaľ nenájdete posledný prvok.

```
this = this->next;
```

Nový prvok zaradte za posledný prvok:

```
this->next = newcar;
```

Na konci vráťte smerník na prvý prvok spojkového zoznamu.


### Implementujte funkciu na výpis spojkového zoznamu

Mala by spĺňať predpis:

```c
void print_train(struct car* first);
```

Funkcia prechádza spojkový zoznam a vypisuje aktuálne hodnoty.
Použite podobný cyklus ako pri pridávaní nakoniec.
Je možná aj rekurzívna implementácia.


### Implementujte funkciu na zrušenie spojkového zoznamu

Každé vyhradenie dynamickej pamäte by malo byť neskôr uvoľnené pomocou `free`.

Mala by spĺňať predpis:

```c
void cancel_train(struct car* first);
```

Funkcia na zrušenie spojkového zoznamu môže pracovať rekurzívne:
Ak je zoznam prázdny, potom rušenie končí.
Inak sa najprv uvoľní ďalší prvok `next` rekurzívnym volaním. Na konci sa uvoľní aktuálny prvok.

Nezabudnite, že ak pamäť uvoľníte pamäť, tak s ňou už nemôžete pracovať.

### Vyskúšajte funkčnosť

Vytvorené funkcie môžete zavolať v súbore `main.c`.

Pridajte niekoľko informácií o vozňoch a vypíšte obsah spojkového zoznamu. Nakoniec zoznam uvoľnite.

Overte si,  či nedochádza ku chybám pri práci s pamäťou.


## Navrhnite spôsob prečistenia spojkového zoznamu

Program by mal byť schopný zo spojkového zoznamu vyradiť položky, ktoré majú určitý názov.

Navrhnite funkciu s predpisom:

```c
struct car* clear_train(struct car* first,const char* name);
```

ktorá prejde spojkový zoznam a vyberie z neho prvky, ktorých názov je zhodný s parametrom `name`.

Funkcia vráti nový začiatok spojkového zoznamu, lebo je možné, že sa zruší aktuálny začiatok.

! Porovnanie dvoch reťazcov môžete vykonať s pomocou funkcie `strcmp`.

Na to aby ste vedeli vybrať prvok z prostriedku spojkového zoznamu je potrebné poznať až tri smerníky. Ak chcete odstrániť druhý prvok z troch,
musíte potom napojiť tretí prvok na druhý:

	first->second->third
	  ^              |
	  +--------------+


	first->third

Preto musíte osobitne riešiť prípad, keď je spojkový zoznam kratší ako dva  prvky. Ak je spojový zoznam prázdny, funkcia neurobí nič a vráti `NULL`.
Ak má spojkový zoznam práve jeden prvok (`first->next == NULL`), zistite, či sa názvy zhodujú. Ak áno, uvoľnite prvok a vráťte hodnotu `NULL`. Ak sa nezhodujú vráťte smerník na prvý prvok.

Ak má zoznam aspoň dva prvky, prechádzajte ho tak aby ste mali k dispozícii smerník na predchádzacúci prvok `prev`:

```
struct car* prev = first;
// Už sme si istí, že  prev a prev->next nie sú NULL
while (prev->next->next != NULL){
   prev = prev->next;
}
```

Ak zistíte, že `prev->next` treba vymazať, poznačte si smerník na tretí prvok, uvoľnite druhý prvok a zaraďte tretí prvok za druhý:

```
struct car* third = prev->next->next;
free(prev->next);
prev->next = third;
return first;
```

## Dokončite program do používateľsky príjemnej podoby.

Overte si funkčnosť spojkového zoznamu.

1. Zo štandardného vstupu načítajte zoznam vozňov a zaraďte ich do vlaku.
1. Vypíšte obsah spojkového zoznamu.
1. Modifikujte spojkový zoznam tak, aby neobsahoval žiadne vozne do Levoče.
1. Na konci uvoľnite pamäť.

Funkcia programu môže na koniec vyzerať takto:


    Zadajte zoznam cieľových staníc a počet cestujúcich.
    Zoznam zakončite prázdnym riadkom.
    Bratislava
    40
    Prešov
    50
    Levoča
    80

    Zadajte stanicu, ktorá sa má vyradiť:
    Levoča

    Výsledný vlak bez stanice Levoča bude:
    Bratislava
    Prešov


