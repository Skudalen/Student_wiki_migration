---
title: Hešovacia tabuľka
---
# 6. Hešovacia tabuľka

## Hešovacia tabuľka

## Ciele

Oboznámiť sa s fungovaním hešovacej tabuľky so zreťazením.

Je potrebné poznať ako funguje spojkový zoznam.

## Stanica Peklo

Ďalšou pracovnou úlohou na pozícii riaditeľa vlakovej stanice bude spočítať koľko cestujúcich cestuje do každej stanice. Úloha to nie je jednoduchá, lebo databáza musí byť pekelne rýchla.  Lineárne vyhľadávanie musíme obmedziť na minimum. V oddelení vývoja vymysleli geniálny zlepšovák - vyhľadávanie pri ktorom je jedno v akej veľkej stanici vyhľadávane, vždy bude trvať rovnaký čas. Vzniklo nové perpettum mobile? 


## Hešovacia tabuľka so zreťazením

Na  účel vyhľadávania si vytvoríme asociatívne pole, ktoré stanici priradí počet cestujúcich ktorí do nej cestujú. Asociatívne pole viete používať podobne ako klasické pole, ale ako kľúč môžete využiť ľubovoľný objekt, napr. reťazec.  Pri vonkajšom pohľade, asociatívne pole vyzerá takto:


        Kľúč         Hodnota
    
    Prešov       20
    Košice       3
    Bratislava   11



Asociatívne pole ale nie je súčasťou jazyka C a tak si ho budeme musieť vytvoriť. Klasický spojkový zoznam na vytvorenie asociatívneho poľa nebude stačiť, lebo operácia vyhľadania je neefektívna - silno (lineárne) závisí od počtu prvkov. Možným riešením je použiť hešovaciu tabuľku so zreťazením. Namiesto jedného spojkového zoznamu použijeme viacero spojkových zoznamov,
ktoré uložíme do poľa.  

Jeden spojkový zoznam si môžeme predstaviť ako vlak, hešovaciu tabuľku si vieme predstaviť ako celú stanicu,
kde sa naraz nachádza viac vlakov, každý na svojej koľaji. Do jednej stanice je smerovaný práve jeden vozeň (cieľové stanice sa nemôžu opakovať).
Podobne ako na stanici, musíme povedať, na ktorej trati sa vlak bude nachádzať. To nám povie hešovacia funkcia, ktorá názvu cieľovej stanice
priradí nejaké celé číslo. Dôležíté je, aby výsledné číslo bolo čo najviac "nepredvídateľné", ale stále rovnaké pre rovnaký reťazec. 
Množstvo všetkých možných reťazcov je väčšie ako množstvo celých čísel typu `int` a tak je možné, že viac rôznych reťazcov bude mať priradenú rovnakú hodnotu - nastane "kolízia". V prípade kolízie nám pomôže spojkový zoznam, ktorý umožní na jednu "koľaj" uchovať viac hodnôt.

Príklad stanice s viacerými vlakmi:

                    hash 0: Prešov -> Košice -> Liptovský Mikuláš -> NULL
        stanica     hash 1: Spišská Nová Ves -> Margecany -> NULL
                    hash 2: NULL
                    hash 3: Kysak-> Dobšiná -> Levoča -> NULL
                    hash 4: NULL

Hešovacia funkcia nám hovorí na ktorej koľaji nájdeme vozeň do niektorej cieľovej stanice.
Prehľadanie jedného zoznamu bude trvať podstatne kratší čas, lebo vo väčšine prípadov sa záznam bude nachádzať hneď na prvom mieste.

## Úloha

Vytvorte databázu  na uloženie informácií o počte cestujúcich do rôznych staníc.  Databázu vytvorte pomocou hešovacej tabuľky so zreťazením.
V databáze môže byť o každej stanici maximálne jeden záznam o počte cestujúcich ktorí do nej cestujú.

Podľa dokumentácie v hlavičkovom súbore implementujte všetky funkcie.

## Budete potrebovať

Ak ste to ešte neurobili, podrobne si zopakujte spojkové zoznamy a dynamické polia, budete ich potrebovať.

Inak riešenie tejto úlohy si nevyžaduje žiadne špeciálne knižnice, iba obyčajné:

- `stdlib.h` na dynamickú alokáciu a uvoľnenie pamäte
- `string.h` na kopírovanie a porovnávanie reťazcov
- `stdio.h` na výpisy a načítanie z terminálu

Veľa Vám prezradí aj šablóna zadania.

Vypracovanie tejto úlohy je citlivé na prácu s pamäťou - ak niečo nebude fungovať v poriadku tak sa program bude správať nevypočítateľne. Pri ladení používajte Valgrind, upozorní Vás na problému a vyhnete sa sklamaniu pri automatickom hodnotení.

## Ako na to

V úlohe budete implementovať sadu funkcií z hlavičkového súboru. Ak to urobíte správne, vznikne Vám asociatívne pole, do ktoré si ku ľubovoľnému kľúču budete vedieť priradiť nejakú hodnotu.


Bohato využijeme znalosti z predošlého cvičenia, prednášky aj minulého ročníka. Namiesto jedného spojkového zoznamu ich ale budeme mať viac. Odkaz na každý spojkový zoznam si uložíme do dynamicky alokovaného poľa smerníkov.

Na výpočet indexu kde do poľa uložíme spojkového zoznamu použijeme hešovaciu funkciu.

Databáza bude tvorená viacerými záznamami, ktoré vyzerajú podobne ako spojkový zoznam:

```c
struct car {
   int capacity;
   char value[SIZE];
   struct car* next;
};
```

Na dynamické pole smerníkov si vytvoríme ďalší typ. Adresy spojkových zoznamov
si poznačíme do poľa smerníkov `tracks`. Počet prvkov v poli smerníkov si uložíme do premennej `track_count`.

```c
struct station {
    // Dynamicke pole smernikov na zaznamy
    struct car** tracks;
    // Velkost pola tracks
    int track_count;
};
```
### 1. Oboznámte sa zo zadaním.

Najprv získajte [šablónu zadania](cv6.zip) a oboznámte sa s funkciami ktoré máte vytvoriť. Dokumentáciu nájdete v súbore `a_station.h`. Odovzdávať na GIT budete súbor `a_station.c`. V súbore `main.c` nájdete nejaké pomocné funkcie.


V šablóne nájdete funkciu na dynamické vytvorenie poľa smerníkov:

```c
struct station* create_station(){
   struct station* station = calloc(1,sizeof(struct station));
   station->tracks = calloc(STATION_SIZE, sizeof(struct car*));
   station->track_count = STATION_SIZE;
   return station;
}
```

Funkcia dynamicky alokuje celú štruktúru, do nej alokuje pole smerníkov a poznačí jeho veľkosť.
Na koniec vráti adresu na štruktúru `struct station`.
Pole smerníkov je na začiatku nulové.

Porozmýšľajte, ako uvoľniť takto alokovanú pamäť vo funkcii `destroy_station`. Každé volanie `calloc` alebo `malloc` musí mať svojho kamaráta `free` (inak sa program bude správať nepredvídateľne).

V práci Vám pomôže aj funkcia na výpis aktuálneho stavu vlakovej stanice, aby ste videli 
na ktorej trati je koľko vlakov.  Pozrite si ju a zistite, ako prechádzať všetky prvky v hešovacej tabuľke. V jednom cykle prejdite všetky spojkové zoznamy a v druhom prejdite všetky prvky spojkového zoznamu. Pomôže Vám pri ladení programu ak budete vedieť kam sa Vaše dáta ukladajú.

```c
void print_station(struct station* station){
        printf("station>>>\n");
        // Prejde vsetky trate
        for (int i = 0 ; i< station->track_count; i++){
                struct car* start = station->tracks[i];
                struct car* this = start;
                // Prejde vsetky vozne vo vlaku
                while(this != NULL){
                        printf("%s %d -> ",this->value,this->capacity);
                        this=this->next;
                }
                printf("NULL\n");
        }
        printf("<<<station\n");
}
```

## 2. Vytvorte si hešovaciu  funkciu

V hešovacej tabuľke je najdôležitejšia hešovacia funkcia - pomôže nám určiť, s ktorou časťou poľa práve pracujeme. 
Hešovacia funkcia zoberie kľúč, väčšinou reťazec, pod ktorým je uložený záznam. V našom prípade to je názov stanice.

Z tohto reťazca hešovacia fumkcia vypočíta kontrolný súčet - číslo získané špeciálnym súčtom hodnôt znakov v reťazci. Z toho kontrolného súčtu určíme index poľa s ktorým budeme pracovať. Hodnota kontrolného súčtu je použitá na určenie miesta v poli smerníkov `tracks` kam sa záznam uloží. 

Obyčajný súčet znakov nestačí, vo výpočte hodnoty heš funkcie sa nachádzajú aj ďalšie operácie tak aby súčet spĺňal určité vlastnosti.
Heš funkcia má za úlohu zabezpečiť, aby sa jednotlivé záznamy v poli rozdelili rovnomerne.  Heš funkcia je navrhnutá tak, aby počet operácií na jej výpočet závisel iba od veľkosti kľúča. Ak by všetky záznamy boli smerované na jediné miesto, tak by sa hešovacia tabuľka degradovala na spojkový zoznam. Ak je v poli smerníkov dosť miesta, tak je zložitosť uloženia alebo výberu  závislá iba od veľkosti kľúča a nie od počtu uložených prvkov. 

Pri výpočte hodnoty hash je potrebné použiť bezznamienkovú reprezentáciu `unsigned long`. Na konci je potrebné hodnotu hešu upraviť pomocou operátora delenia modulo (`%`) tak aby patrilo do intervalu 0 až `station->track_count`.


Pri návrhu sa môžete inšpirovať niektorou z existujúcih hash funkcií:

- [Rozsiahly článok o HASH](https://www.partow.net/programming/hashfunctions/)
- [Niekoľko HASH funkcií](http://www.cse.yorku.ca/~oz/hash.html)
- [na Wikipédii](https://en.wikipedia.org/wiki/Hash_function)

Budete musieť využiť cyklus, ktorý prejde všetky znaky reťazca. Nezabudnite, že posledný znak je vždy nula. V každom kroku upravíme hodnotu hash funkcie podľa aktuálneho znaku.


##  3. Vytvorte funkciu na pridanie záznamu 



Algoritmus na pridanie nového záznamu do databázy bude vyzerať takto:

1. Pomocou funkcie `select_track` vyberte s ktorým spojkovým zoznamom budeme pracovať.
1. Ak je spojkový zoznam prázdny, vytvoríme nový prvok a zapíšeme ho na vybrané miesto.
1. Ak spojkový zoznam nie je prázdny, prechádzame všetky jeho prvky. Ak nájdeme "vozeň" s rovnakou cieľovou stanicou,  modifikujeme jeho kapacitu a skončíme.


Miesto v poli smerníkov vyberieme pomocou hešovacej funkcie:

```c
int track = select_track(station,target);
struct car* start = station->tracks[track];
```

Pri pridávaní musíte zabezpečiť, aby v databáze bol maximálne jeden záznam o danej cieľovej stanici.
Keď vieme v na ktorom mieste sa záznam nachádza, so záznamom robíme rovnako ako so spojkovým zoznamom.

## 4. Správne uvoľnite pamäť

Ubezpečte sa, že funkcia `destroy_station` uvoľní aj pamäť všetkých záznamov, ktoré ste vytvorili vo funkcii `add_target_capacity`

## 6. Vytvorte funkciu na vyhľadanie 

Ak na základe hash funkcie vieme do ktorého vlaku vlaku vozeň patrí, je jednoduché ho vyhľadať.

1. Vypočítajte heš hodnotu z reťazca názvu stanice pomocou funkcie `select_track`.
1. Určite číslo "koľaje", do ktorého ide záznam.  Funkcia `select_track` vráti ľubovoľne veľké celé číslo. Toto číslo konvertujeme do intervalu 0 až `station->size -1` pomocou operátora `%`.
1. Vyhľadajte "vozeň" s daným názvom v určenom vlaku. Prejdite všetky prvky spojkového zoznamu.

## 7. Vytvorte funkcie na spočítanie 

všetkých záznamov a dostupnej kapacity.

Ako príklad môžte použiť funkciu `print_station`.

## 8. Dokončite program do používateľsky príjemnej podoby

Do aplikácie doplňte tieto vlastnosti:


- Načítanie existujúcej databázy  z textového súboru.
- Pridanie nového záznamu a zvýšenie kapacity do danej destinácie
- Vyhľadávanie informácií podľa zadanej destinácie

## Odovzdanie

- odovzdanie cez [GIT](https://git.kemt.fei.tuke.sk)
- za 4 body
- hodnotenie systémom [Traktor](https://traktor.kemt.fei.tuke.sk).

V tomto zadaní budete hodnotení pomocou jednotkových testov funkcií ktoré máte vytvoriť. 
Budete odovzdávať obsah súboru `a_station.c` podľa predpisov a dokumentácie v súbore `a_station.h`.

Používateľskú funkčnosť Vášho programu  a znalosť zdrojových kódov predstavíte v rámci osobnej obhajoby.




