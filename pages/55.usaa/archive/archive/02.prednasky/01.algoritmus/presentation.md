---
title: Algoritmus
---

# 1. Algoritmus

----
## Údajové štruktúry a algoritmy

prednášky aj cvičenia: Ing. Daniel Hládek PhD.

----
# plynulo programovať v jazyku C

---
# Programovať sa dá naučiť iba programovaním

---
## Ciele predmetu

- pracovať s dynamicky meniacou sa množinou údajov
- efektívne používať a modifikovať údajové štruktúry
- efektívne používať a modifikovať základné algoritmy

---
## Získané zručnosti

- hashovanie
- indexovanie
- triedenie a vyhľadávanie:
    - v strome
    - v reťazci
    - v poli
    - v spojkovom zozname

---
## Údajové štruktúry a algoritmy sú potrebné pre prácu v IT

----
## Organizácia predmetu a hodnotenie

[na stránke](../info)


----
## Úvod do algoritmov

----
## Čo je to algoritmus?

Introduction to Algorithms:

> Informally, an algorithm is any well-defined computational procedure that takes
> some value, or set of values, as input and produces some value, or set of values, as
> output. An algorithm is thus a sequence of computational steps that transform the
> input into the output.

----
## Vlastnosti algoritmov

- Konečný
- Determinovaný
- Efektívny
- Má vstup a výstup

Ak postup nespĺňa všetky vlastnosti algoritmu, nazývame ho **heuristika**

----
## Zápis algoritmu

vstup => postup = výstup

- Pseudokód
- Kód
- Vývojový diagram

----
### Príklad na algoritmus:

- varenie
- triedenie
- vyhľadávanie

----
## Algoritmy sú dôležité pre počítačové siete

- algoritmické myslenie
- poznanie technických prostriedkov
- porozumenie princípom činnosti sieťových zariadení
- znalosť grafových algoritmov

----
## Dôležité algoritmy

- Dijkstrov algoritmus najkratšet cesty
- Kompresné algoritmy, stratové aj bezstratové
- CRC kontrolný súčet
- RSA šifrovanie
- ARQ algoritmus (Automatic repeat request)
- routing table - hash, tree

[note]
Podľa [https://www.quora.com/What-are-the-most-important-algorithms-used-in-computer-networking/](blogu)
[/note]

----
## Prečo sa zamýšať nad algoritmami?

> Suppose computers were infinitely fast and computer memory was free. Would
> you have any reason to study algorithms? The answer is yes, if for no other reason
> than that you would still like to demonstrate that your solution method terminates
> and does so with the correct answer.

---
# Algoritmy nie sú zadarmo

----
## Koľko bude stáť vyriešenie problému?

---
## Zložitosť algoritmu

- peňazí = koľko času a koľko prístrojov (pamäte) budeme potrebovať?
- Pamäťová náročnosť
- Časová náročnost (Výpočtová náročnosť)

----
## Benchmarking

Odmeráme spotrebovaný strojový čas a potrebnú pamäť na vzorovom probléme.

----
## Teoretická analýza algoritmu

Depredu presne nevieme, koľko dát budeme spracovávať.

---
## Vzťah medzi množstvom dát a množstvom potrebných prostriedkov

- najlepší prípad
- najhorší prípad
- priemerný prípad

----
## RAM Model

Určíme, ktorá inštrukcia má cenu 1.

---
# RAM Model

> Before we can analyze an algorithm, we must have a model of the implemen-
> tation technology that we will use, including a model for the resources of that
> technology and their costs. For most of this book, we shall assume a generic one-
> processor, random-access machine (RAM) model of computation as our imple-
> mentation technology and understand that our algorithms will be implemented as
> computer programs. In the RAM model, instructions are executed one after an-
> other, with no concurrent operations.

----
## Aká je cena vykonanie algoritmu lineárneho vyhľadávania?


- cena priradenia: \( O_{prir} \)
- cena porovnania: \( O_{por} \)
- cena inkremenácie: \( O_{inc} \)

----
## Iteratívne lineárne vyhľadávanie

```c
int vyhladaj(char* pole, int size, char znak){
	for (int i = 0; i < size; i++)}
    	if (pole[i] == znak){
        	return i;
        }
    }
    return -1;
}
```

---
V najhoršom prípade: 

\( O(n) = O_{prir} + n * (2 * O_{por} + O_{inc}) \)

---

V najlepšom prípade: 

\( O(n) = O_{prir} + (2 * O_{por} + O_{inc}) \)

---

V priemernom prípade: 

\( O(n) = O_{prir} + 0.5 * n * (2 * O_{por} + O_{inc}) \)

----
## Asymptotická zložitosť

Zanedbáme všetky konštanty.


\( C => O(1) \)


\(n C => O(n) \)


\( n^2 C => O(n^2) \)

---
# Asymptotická zložitosť lineárneho vyhľadávania


\(O(n) \)


---
# Vyhľadávanie bisekciou

Predpokladáme, že pole je zotriedené...

---
```c
int binary_search(int* array,int size,int search){
   int first = 0;
   int last = size - 1;
   int middle = (first+last)/2;
   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;    
      else if (array[middle] == search) {
         return middle;
      }
      else{
         last = middle - 1;
      }
      middle = (first + last)/2;
   }
   return -1; 
}
```


---
# Aká je zložitosť vyhľadávania bisekciou?

---
v najlepšom prípade


- 2 x porovnanie
- 1 delenie
- 1 spočítanie
- 1 priradenie

Asymptoticky \(0(1)\)

---
# Asymptotická zložitosť bisekcie


Zložitosť slučky v najhoršom prípade:



\( O (log_2 (n)) \)

---
# Ktorá zložitosť je lepšia

- konštantná  \( 0(1) \)
- Lineárna     \( O(n) \)
- Logaritmická \( O(log(n)) \)

---
# References


- [[[ia]]] Introduction to Algorithms Book by Charles E. Leiserson, Clifford Stein, Ronald Rivest, and Thomas H. Cormen
- [[[pw]]] Piotr Wroblewski: Algoritmy - Datové struktury a programovací techniky, Computer Press 2004

---
# Zhrnutie

- Cena vykonania algoritmu súvisí s jeho zložitosťou
- Cena návrhu počítačovej siete súvisí s jej zložitosťou

