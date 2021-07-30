---
title: Triedenie
published: true
---

# Triedenie

## Odovzdanie


- názov `usaa19cv3`
- heslo `usaa19cv3`
- odovzdanie cez [GIT](https://git.kemt.fei.tuke.sk)
- za 4 body do 25.10.2019
- hodnotenie systémom [Traktor](https://traktor.kemt.fei.tuke.sk).

## Ciele

Navrhnúť a využiť algoritmus triedenia v poli štruktúr podľa zvoleného kritéria.

## Úvod 

Naša kariéra v pizzérii sa sľubne vyvíja a šéf našej startupovej pizzérie "U hladného hipstera" bol nadšený.
Keďže usilovnosť bude odmenená, boli sme odmenení ďalším pracovným zadaním.

## Úloha

Pri určovaní marketingovej stratégie je veľmi dôležité zistiť,. ktorá pizza je najlacnejšia. Dalo by sa to síce zistiť jednoduchým prečítaním jedálneho lístka, ale vieme to robiť aj inak - strojovým spracovaním. Nová verzia jedálneho listka by mala byť zoradená podľa ceny tak, aby najlacnejšia pizza bola na prvom mieste. V prípade, že je cena rovnaká, zoraďte položky podľa abecedy. Špeciálne znaky s diakritikou nemusíte brať do úvahy.

Jedálny lístok je vo formáte:

    Názov 1
    Cena 1
    Názov 2
    Cena 2
    atd.

Názov je ľubovoľný neprázdny reťazec neprázdnych znakov. Názov nie je dlhší ako 100 znakov.
Cena je číslo s desatinnou čiarkou zadané na dva miesta.
Jedálny lístok je ukončený neplatnou položkou (nesprávne zadaný názov alebo cena) alebo koncom vstupu.

Práca s programom môže vyzerať napríklad takto:

Vstup:

    Salamovo Fazulova pizza
    7.96
    Sunkova pizza
    5.77
    Bryndzova pizza
    8.67
    Zelerova pizza
    8.86
    Slaninovo Sunkova pizza
    7.55
    Slaninova pizza
    5.16

Výstup:

    Slaninova pizza
    5.160000
    Sunkova pizza
    5.770000
    Slaninovo Sunkova pizza
    7.550000
    Salamovo Fazulova pizza
    7.960000
    Bryndzova pizza
    8.670000
    Zelerova pizza
    8.860000


# Ako na to

Porozmýšľajte, ako by ste program urobili Vy a skúste to samostatne. Začnite s čo najjednoduchším funkčným programom ktorý viete urobiť. Postupne pridávajte ďalšie vlastnosti tak, aby ste sa čo najviac priblížili k splneniu zadania. Ťažké časti si nechajte na koniec. 

Ak potrebujete inšpiráciu, pokračujte v čítaní návodu.

## Budete potrebovať

Na začiatok je dobré sa zamyslieť nad potrebnými "stavebnými blokmi". Určite sa zíde:

- Funkcia na načítanie jednej položky jedálneho lístka: zíde sa predošlé cvičenie.
- Definíciu štruktúry s jednou položkou jedálneho lístka (názov a cena).
- Pole štruktúr na uloženie celého jedálneho lístka.
- Porovnávaciu funkciu.

## Zopakujte si

- Triedenie s pomocou funkcie [qsort](http://www.cplusplus.com/reference/cstdlib/qsort/).
- Typovú konverziu pre smerníky pomocou zátvoriek `(struct novy_typ *)`
- prístup k členom štrukútry pomocou smerníka pomocou `->`.

## Vytvorte si program na načítanie celého jedálneho lístka

Stačí, aby prvá verzia iba načítala a zobrazila všetky položky jedálneho lístka.

Môžte skopírovať časti kódu z predošlého cvičenia. Nechajte ale iba tie časti, ktoré sa Vám zdajú relevantné k riešeniu dnešnej úlohy.

## Uložte všetky položky poľa do pamäte

Triedenie prebieha tak, že podľa určitého poriadku postupne vymieňame položky v pamäti.
Na to aby sme mohli zoznam triediť, je potrebné aby sme mali k dispozícii celý zoznam.
A nielen to, potrebujeme aby súvisiace údaje, napr. názov a cena jedla boli v pamäti blízko seba - aby sa nestalo, že pizza na inom mieste jedálneho lístka bude mať zrazu inú cenu.

### Vytvorte si vhodný údajový typ

Ak sme to doteraz neurobili, vytvoríme si nový dátový typ `struct pizza` ktorý bude vyjadrovať jednu položku jedálneho lístka. Vytvorenie štruktúry zabezpečí, aby spolu s názvom jedla sme vedeli presunúť aj jeho cenu.

```c
struct pizza{
   char name[LINE_SIZE];
   float prize;
};
```

Na uloženie jedného záznamu nám stačí obyčajná premenná typu `struct pizza`:
 
 ```c
struct pizza vcerajsia = {.name:"Vajcova pizza",.prize:0.2};
```

Ak je k dispozícii iba smerník na štruktúru, použijeme operátor `->` na prístup k členu štruktúry:

```c
struct pizza* pizza_pointer=&item;
printf("%.2f",pizza_pointer->prize);
```
### Vytvorte si pole a uložte do neho jedálny lístok

Na uloženie viacerých záznamov môžme použiť pole. Pole treba samozrejme inicializovať:
napr. pomocou funkcie [memset](http://www.cplusplus.com/reference/cstring/memset/).

```c
struct pizza list[LIST_SIZE];
memset(list,0,LIST_SIZE*sizeof(struct pizza));
```

Do tohto poľa načítavame postupne záznamy až pokiaľ sa nevyčerpá miesto.

Načítanie do poľa si môžme naprogramovať do osobitnej funkcie, ktorá vráti počet úspešne načítaných položiek. 

! Pozor, v tomto prípade je v premennej `list` uložený smerník na prvú položku poľa. Maximálna veľkosť poľa môže byť uložená v konštante `LIST_SIZE`;

```c
int read_pizza_list(struct pizza* list);
```

Načítajte celý jedálny lístok do poľa a vypíšte jeho obsah aby ste si skontolovali či to naozaj funguje.

Načítanie jedálneho lístka by určite malo obsahovať cyklus, ktorý prejde všetky voľné miesta v poli.
Cyklus sa preruší v prípade, že sme našli posledný (neplatný) záznam.

Môže postupovať napr. tako:

```c
// Prechadzajte vsetky miesta jedalneho listka
int counter = 0;
for (int i=0; i< LIST_SIZE; i++){
    struct pizza item;
    memset(&item,0,sizeof(struct pizza));
    // Nacitajte polozku do pomocnej premennej
    // Na nacitanie pouzite vlastny kod
    int r = read_item(&item);
    if (r){
        // Ak sa nacitanie podarilo, skopirujte polozku do pola
        memcpy(&listok[i],&item,sizeof(struct pizza));
	// Spocitame uspesne nacitane polozky
	counter += 1;
    }
    else{
        // Ak sa nacitanie nepodarilo, nasli sme poslednu polozku
	// Prerusim nacitanie
        break;
    }
}
// Na konci budemem mat nacitany jedalny listok
// V premennej counter je pocet uspesne nacitanych poloziek
```


Na konci si vypíšte obsah poľa s jedálnym lístkom. Počet položiek v poli máte uložený v počítadle
(`counter`).

## Zotrieďte pole s jedálnym lístkom


Keď máte pole načítane v pamäti, môžeme na ňom vykonať operáciu triedenia.  Triedenie funguje tak,
že sa v určitom poradí vymieňajú položky poľa medzi sebou podľa toho ktorá je väčšia alebo menšia.

Na zotriedenie múžete naprogramovať vlastnú funkciu, ktorá bude porovnávať a vymieňať položky poľa,
Môžete využiť napr. algoritmus  bubblesort. Na zotriedenie musíte použiť dva vnorené cykly.

V prvok kroku navrnite cyklus, ktorý "prebuble" najväčší prvok na koniec.
Získame to, že na konci bude najväčší prvok, ktorý už nmusíme  brať do úvahy a pole na zotriedenie je o jedno políčko menšie. Potom nám stačí ten istý postup aplikovať na zvyšok poľa, až pokiaľ máme čo triediť.

NOTE: Môžete sa pokúsiť navrhnúť aj nejaký iný algoritmus triedenia z prednášky.

Druhou možnosťou je využiť funkciu zo štandardnej knižnice `qsort`.
Pri volaní funkcie [http://www.cplusplus.com/reference/cstdlib/qsort/](qsort) zadáme ako argument pole ktoré chceme zotriediť, jeho veľkosť a
smerník na funkciu pre porovnanie.

Volanie `qsort` môže vyzerať takto:

```c
qsort (list, size, sizeof(struct pizza), compare_pizza);
```

### Definujte funkciu na porovnávanie

Zopakujte si

!! - `*` v predpise funkcie znamená smerníkový typ. `void*` znamená smerník na ľubovoľnú pamäť.
!! - Význam `*` v tele funkcie je iný. Povie nám hodnotu, na ktorú ukazuje smerník.
!! - Smerník typu `void` môžete pretypovať na ľubovoľný iný typ pomocou dynamického pretypovania - pred hodnotu uvediete `(NovyTyp)`.
!! - Hodnotu člena štruktúry, na ktorú ukazuje smerník, zistíte pomocou operátora `->`.


V každom prípade budete musieť porovnať dva prvky na určemie ich poradia.

Porovnávacia má dva argumenty - smerníky na objekty ktoré sa majú porovnať. Návrátová hodnota definuje vzťah medzi týmito dvoma prvkami.

Nulové návratová hodnota znamená, že oba prvky sú rovnaké. Kladná hodnota znamená, že prvý prvok je väčší,
záporná znamená opak.

Porovnávacia funkcia pre porovnanie celých čísel by mala podľa dokumentácie funkcie [qsort](http://www.cplusplus.com/reference/cstdlib/qsort) spĺňať predpis:

```c
int compare (const void * a, const void * b);
```

Kľúčové slovíčko `const` si nemusíte všímať, vyjadruje iba že by sme nemali meniť hodnoty s ktorými pracujeme.

Toto je všeobecná funkcia pre porovnanie dvoch hodnôt ľubovoľného typu. 

Na správne fungovanie musíme využiť niekoľko fígľov na premenu
ľubovoľného  smerníka typu `void*` na smerník typu `struct pizza` a pristúpiť k hodnote člena štruktúry.
Jazyk C ale nepozná pojem "ľubovoľný typ". Namiesto neho je potrebné použiť
pojem "ľubovoľný smerník" (`void*`). Funkcia dostane dva smerníky a je na programátorovi čo s tým urobí. Smerník je celé číslo, pamätáte sa?

Z adresy musíme "extrahovať" hodnotu, na ktorú odkazuje. Najprv si premeníme "všeobecný smerník" `void*` na smerník na typ s ktorým pracujeme.

```c
struct pizza* pizza_a = a;
```

Je fajn, že pri tejto operácii priradenia  a pretypovania sa nekopíruje celá hodnota so záznamom o pizzi, iba hodnota adresy na záznam.

Zo smerníkovej  premennej typu `struct pizza*` už vieme ľahko "vytiahnuť" hodnotu pomocou operátora `->`:

```c
float prize = pizza_a->prize;
char* name = pizza_a->name;
```

Takto máme k dispozícii hodnoty z adresy typu (void*). Musíme si ale byť istí, že tam naozaj takáto hodnota je, inak budeme pracovať 
s ľubovoľnými hodnotami uloženými niekde v pamäti.

Dátový typ smerníka sa zmení pri priradení do novej premennej. Novú premennú ani nemusíme využívať, 
typ je možné zmeniť dynamicky s použitím výrazu:

```c
(struct pizza*)a
```

Na rozlíšenie podľa ceny stačí zistiť, či je rozdiel medzi cenami nulový, kladný alebo záporný.

Na rozlišenie dvoch hodnôt podľa abecedného poradia použite funkciu [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/).

