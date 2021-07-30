---
title: Hešovacia tabuľka
---
# Hešovacia tabuľka

---
## Klasické pole

Každá hodnota má svoj index.

Mapovanie Index => Hodnota

---
## Klasické pole

    int pole[4] = {4,3,2,1};

    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22

---
## Asociatívne pole

Zovšeobecnenie klasického poľa

Mapovanie Kľúč => hodnota.

NOTE: Kľúč je väčšinou reťazec.

---
## Príklad na asociatívne pole

- "ahoj" => 2
- "pekný" => 4
- "svet" => 11

---
## Príklad na asociatívne pole

    index:    prvy   druhy  treti   stvrty
               |       |      |        |
               v       v      v        v
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+

---

## Časté operácie s asociatívnym poľom

- Vloženie ľubovoľného prvku na ľubovoľné miesto (INSERT).
- Vymazanie ľubovoľného prvku  (DELETE).
- Vyhľadanie ľubovoľného prvku

---
## Použitie asociatívneho poľa

Množina údajov, kde sa kľúč nemôže opakovať.

- Počítadlo slov;
- Pravidlové systémy;
- Systémová konfigurácia;
- Databázové systémy;
- Slovníky;
- atď.

---
## Implementácia asociatívneho poľa

Kľúč a hodnota by mali byť blízko pri sebe.

Súčasťou informácie o hodnote by mal byť aj kľúč.

---
## Naivná implementácia asociatívneho poľa

```c
struct asoc {
 char key[20];
 int value;
};

struct asoc array[10];
```

Má všetky nevýhody klasického poľa
(lineárna zložitosť skoro všetkých operácií).

---
## Naivná implementácia asociatívneho poľa

     +-------------+---------------+
     | prvy    3   | druhy     1   |
     +-------------+---------------+

---
## Ako implementovať asociatívne pole

- Naivný spôsob.
- Binárny vyhľadávací strom.
- Hešovacia tabuľka.

---
## Hešovacia tabuľka

- Založené na myšlienke, že hešovanie za dá urobiť za (skoro) konštantný čas.
- Kľúču sa priradí celé číslo (hash), podľa ktorého vieme vyhľadať hodnotu v údajovej štruktúre.

NOTE: Vo všeobecnosti je HT lepšia ako BVS.

---
## Hešovacia tabuľka


    index:    prvy   druhy  treti   stvrty
               ||      ||     ||      ||
               \/      \/     \/      \/
    hash:       0       1      2       3
               ||      ||     ||      ||
               \/      \/     \/      \/
             +------+------+-------+-------+
    slot     |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+

---
### Slot

Slot je miesto pre jednu hodnotu v HT

---

## Load factor

- Nie všetky miesta v HT musia byť obsadené
- Load factor: priemerný počet hodnôt na slot

---
## Load Factor

n / m - očakávaný počet hodnôt v jednom slote.

n:: počet hodnôt

m:: - počet slotov (možných hodnôt hash funkcie).

---
## load factor 0.5

    index:    prvy         treti
               ||            ||
               \/            \/
    hash:       0             2
               ||            ||
               \/            \/
             +------+------+-------+-------+
    slot     |  4   |      |  2    |       |
             +------+------+-------+-------+

---
### Čo je to HT

[quote, Mastering Algorithms]
The primary idea behind a hash table is to establish a mapping
>between the set of all possible keys and positions in the array using a hash function.

---

[quote, Introduction ot Algorithms]
Many applications require a dynamic set that supports only the dictionary
>operations INSERT , SEARCH , and DELETE.

---

[quote, Introduction ot Algorithms]
A hash table is an effective data structure for implementing dictionaries.
>Although searching for an element in a hash table can take as long as searching for an element in a
>linked list—‚.n/ time in the worst case—in practice, hashing performs extremely
>well. Under reasonable assumptions, the average time to search for an element in
>a hash table is O.1/. A hash table generalizes the simpler notion of an ordinary array.

---
## Hešovacia funkcia

Funkcia, ktorá ľubovoľne veľkej hodnote priradí hodnotu fixnej veľkosti.

WARNING: Je možné, že dva rôzne vstupy majú rovnakú hodnotu hešovacej funkcie.

---
### Perfektná hešovacia funkcia je injektívna

Funkcia, ktorá hodnote `a` priradí hodnotu `b`, tak že pre ľubovoľné `b` existuje maximálne jedno `a`.

Nepozná kolízie.

---

## Príklad na hešovaciu funkciu

```c
int hash_string(const char* word){
    for (int counter = 0; word[counter]!='\0'; counter++){
        hash = word[counter] + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}
```

https://stackoverflow.com/questions/14409466/simple-hash-functions

---

## Vyhľadávanie v hešovacej tabuľke

VSTUP:: kľúč, hešovacia tabuľka

VÝSTUP:: hľadaná hodnota alebo NULL.

---
## Vyhľadávanie v HT

1. Vypočítame hash z kľúča.
1. Pozrieme si príslušný slot.
1. Ak je slot prázdny, hodnota sa v tabuľke nenachádza a vrátime NULL.
1. Ak kľúč sedí, našli sme hodnotu. Inak nastala kolízia.
1. Ak nastala kolízia, vyhľadáme ďalší slot.

---
### Hešovacia funkcia

Mala by by priradiť indexy uniformnou pravdepodobnosťou.

- ak jednému existujú dva kľúče, ktoré majú rovnaký hash, vzniká kolízia

---

[quote, Mastering Algorithms]

> A hash function h is a function we define to map a key k to some position x
> in a hash table. x is called the hash coding of k. Formally stated:
> h ( k ) = x

---
### Tvorba hash funkcie

- Metóda delenia:: celočíslený zvyšok po delení
- Metóda násobenia::

[quote]
> An alternative to the division method is to multiply the integer key k by a
> constant A in the range 0 < A < 1; extract the fractional part; multiply this value by the
> number of positions in the table, m; and take the floor of the result.

---
## Riešenie kolízíí

Je potrebné, aby kľúč bol uložený v hešovacej tabuľke spolu s hodnotou.

- Zreťazenie:: jeden slot sa podobná na spojkový zoznam.
- Otvorené mapovanie:: ak je slot obsadený, využijeme iný.

---
## Zreťazenie

- Jeden slot je množina hodnôt s rovnakým hash kódom.
- Jeden slot je spojkový zoznam.

Chceme, aby všetky sloty mali približne rovnakú veľkosť.

---
## Otvorené mapovanie

- Hodnoty sú uložené priamo v slotoch
- Ak je slot obsadený, vyberieme nový voľný slot pomocou pomocnej hešovacej funkcie
   - vedľa o n miest
   - aplikujeme hash funkciu ešte raz
   - použijeme inú hash funkciu

---
## References

- Introduction to Algorithms Book by Charles E. Leiserson, Clifford Stein, Ronald Rivest, and Thomas H. Cormen
- Mastering algorithms with C by Kyle Loudon O'Reilly, 1999 - Computers - 540 pages

---
# Zhrnutie

- Hešovacia tabuľka umožnuje "konštantnú" zložitosť pri vyhľadaní prvku.
- Hešovacia funkcia vypočíta miesto v poli s ktorým pracujeme.
- Kolízie riešime pomocou spojkového zoznamu alebo pomocou hľadania voľného miesta v poli.
