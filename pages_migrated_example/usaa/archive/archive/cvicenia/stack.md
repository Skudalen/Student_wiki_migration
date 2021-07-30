---
title: Title
published: true
---
# Poľská zásobníková kalkulačka

## Odovzdanie


- názov `usaa19cv4`
- heslo `usaa19cv4`
- odovzdanie cez [GIT](https://git.kemt.fei.tuke.sk)
- za 4 body
- hodnotenie systémom [Traktor](https://traktor.kemt.fei.tuke.sk).

## Ciele

- Návrh a implementácia zásobníka
- Využívanie zásobníka v jednoduchom programe

## Zásobník

Nášmu biznisu sa prestalo dariť. Tržby z neznámeho dôvodu klesli a je potrebné zaviesť úsporné opatrenia.
Dodatočným vyšetrovaním sa zistilo, že chyba je na strane pokladníka Gejzu, ktorý do teraz všetky bločky počítal z hlavy
a výsledky z nejakého dôvodu zaokrúhľoval smerom nadol. Asi počítal v doméne ceých čísel a tak pizza za 3,99 EUR zrazu stála iba 3 EUR.
Zákazíkom sa to síce páčilo, ale vedeniu už menej. Gejza bol za trest preradený do mzdovej účtárne a my sme dostali za úlohu vyriešiť vzniknutú situáciu implementáciou kalkulačky.

Dodaný hardware ale nespĺňa všetky požiadavky - do verejného obstarávania zabudli uviesť požiadavku na klávesu `=` !
Kalkulačka, ktorú musíme použiť nemá klávesu na zobrazenie výsledku?
Našťastie poznáme tzv. postfixovú notáciu (reverzná poľská notácia) a zásobník
pomocou ktorých vieme takú kalkulačku navrhnúť.

Dostaneme tak jednoduchú kalkulačku. 

## Úloha

 Vytvorte  zásobníkovú kalkulačku. Zásobník bude mať veľkosť 10 miest na uloženie čísla s desatinnou čiarkou.

Jeden vstup do kalkulačky bude zadaný na jedmom riadku. Vstup do kalkulačky môže byť číslo s desatinnou čiarkou alebo jedna z operácií `+-*/`.
Ak je na vstupe platné číslo, pridajte ho na koniec zásobmíka.
Ak je vstup operácia, vyberte dva posledné čísla zo zásobníka, vykonajte operáciu a výsledok vložte do zásobníka.
Na konci každého úspešného vstupu alebo operácie zobrazte na nový riadok hodnoty v zásobníku oddelené medzerou.

V prípade, že sa nepodarilo načítať číslo alebo operáciu, vypíšte chybové hlásenie a ukončite program.
V prípade, že je zásobník plný alebo v ňom nie je dostatok hodnôt, vypíšte chybovú správu a ukončite program.


Ak chceme v reverznej notácii vypočítať výraz (1 + 2), bude to vyzerať takto:

```
1
> 1
2
> 1 2
+
> 3
```

Ak chceme vypočítať (2 * (4 + 5)), musíme trochu porozmýšľať. Zadáme:

```
2
> 2
4
> 2 4
5
> 2 4 5
+
> 2 9
*
> 18
```

[https://hackaday.com/2017/10/24/reverse-polish-notation-and-its-mildly-confusing-elegance/](Viac informácií o poľskej kalkulačke)

## Ako na to

Zásobník je dátová štruktúra, ktorá umožnuje ľahké  ( `O(1)`)  pridanie a odobratie prvku na konci zoznamu.

Najprv si navrhneme a vytvoríme zásobník.
V druhom kroku implementujeme načítanie desatinných čísel do zásobníka, Ak je zásobník plnyý, vypíšte chybové hlásenie a skončite program. Ak sa načítanie nepodarilo, tiež vypíšte chybovú správu a ukončite program.

Ak nám funguje načítanie, môžme doplniť vykonávanie operácií.

Na splnenie tejto úlohy sú potrebné nástroje z predošlých úloh, ako je načítanie desatnného čísla alebo pole.

Kalkulačka bude fungovať podľa týchto pravidiel:

1. Načítajte reťazec.
1. Zistite či je načítaná hodnota číslo alebo operácia
1. Ak je hodnota číslo, uložte ho do zásobníka.
1. Ak je hodnota operácia, vyberte operandy zo zásobníka, vykonajte operáciu a výsledok uložte do zásobníka.
1. Ak v zásobníku nie je dosť hodnôt pre vykonanie operácie, zobrazte chybové hlásenie a skončite program.
1. Zobrazte obsah zásobníka.
1. Pokračujte od začiatku.

## 1. Implementujte štruktúru pre zásobník pomocou statického poľa

Zásobník je tvorený:

- poľom fixnej veľkosti
- počítadlom hodnôť v zásobníku. Počítadla slúži zároveň ako ukazovateľ na prvé voľné miesto.

Musíme si zapamätať aj maximálnu veľkosť poľa a pamätať, že aktuálna veľkosť ju nesmie prekročiť.

WARNING: Ak budeme zapisovať mimo poľa, program sa bude správať nepredvídateľne.

Dátová štruktúra pre zásobník môže vyzerať napr. takto:

```c
struct stack {
   float values[STACK_SIZE];
   int size;
}
```

Nový zásobník si môžme vytvoriť staticky:

```c
struct stack mystack;
memset(&mystack,0,sizeof(struct stack));
```

Zápis do zásobníka (`push`) spočíva v uložení novej hodnoty na posledné miest v poli a inkrementácii (zvýšení hodnotu o jedna) počítadla. Pred zápisom sa musíte presvedčiť, že nezapisujete mimo vyhradenej časti poľa.

```c
assert(mystack.size < STACK_SIZE); // Program spadne, ak zapisuje mimo
mystack.values[mystack.size] = value;
mystack.size += 1;
```

Makro  `assert` spôsobí, že ak nie je splnená podmienka vo vnútri tak program spadne. Okamžite zabránime tomu aby sa dostal do neurčitého stavu a uľahčíme si tým hľadanie chyby.

Výber hodnoty zo zásobníka  (`pop`) je opačný proces. Prečítame hodnotu a znížime (dekrementujeme) počet hodnôt v poli.
Musíme sa presvedčiť, že počet neklesne pod nulu.

```c
assert(mystack.size > 0); // Program spadne, ak číta mimo
float value = mystack[mystack.size-1];
stack_size -= 1;
```
 Do zásobníka postupne zapisujte načítané hodnoty podľa už známeho postupu.

Výpis zásobníka môžte realizovať aj pomocou funkcie:

```c
void print_stack(struct stack* stack);
```

Pri funkciách, ktoré pracujú so štruktúrou je výhodné používať smerník aby sme zabránili zbytočnému 
a nechcenému kopírovaniu. Nezabudnite, že adresu statickej premennej získate pomocou operátora `&`
a k členom štruktúry prístupnej ako smerník pomocou operátora `->`.

Operácie zo zásobníkom si tiež môžte vyjadriť ako funkcie:


```c
void push_stack(struct stack* stack, float value);
float pop_stack(struct stack* stack);
int count_stack(struct stack* stack);
```

## 2. Implementujte operácie s kalkulačkou

Modifikujte program a doplňte možnosť operácií s kalkulačkou.



Ak je načítaný reťazec operácia (plus, mínus, krát, delené), tak operáciu aplikujeme na posledné dva prvky zásobníka a výsledok uložíme do zásobníka.
Ak je načítaný reťazec číslo, pridáme ho do zásobníka. Po načítaní a vykonaní zobrazíme obsah zásobníka.

Ak je vstup číslo, tak sa uloží do zásobníka.

Ak je vstup operátor, tak sa vyberie potrebný počet operandov zo zásobníka a výsledok sa opäť uloží do zásobníka.


