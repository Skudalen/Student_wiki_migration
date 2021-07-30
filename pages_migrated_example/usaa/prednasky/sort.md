---
title: Rekurzia a triedenie
published: true
---
# 2. Rekurzia a triedenie

---
## Čo je to rekurzia ?

Opakovanie samého seba.

![Had](440px-Serpiente_alquimica.jpg)

---
## Rekurzia v prírode ?

![Strom](RecursiveTree.JPG)

---
## Rekurzia v prírode !

![Mrak](1200px-Clouds_over_Africa.jpg)


---
## Aj slimáky sú rekurzívne

![Snail](Animals-Sicily-bjs-3.jpg)

---
## Rekurzia v informačných technológiách

Poznáme rekurzívne algoritmy, ale aj rekurzívne dátové typy

---
## Rekurzia v počítačových sieťach

Keď siete tvoria ďalšie siete

---
## Rekurzívne dátové typy

Dátový typ, ktorý obsahuje sám seba.

---
## Spojkový zoznam

```c
struct linked_list {
    int value;
    struct linked_list* next;
}
```
[note]
Členom štruktúry je smerník na rovnakú ďalšiu štruktúru.
[/note]

---
## Rekurzívne algoritmy

Postup, ktorý volá sám seba.

---
## N-tý člen Fibonacciho postupnosti

- Prvý člen je 0
- Druhý člen je 1
- Každý ďalší člen je súčtom dvoch predošlých

https://sk.wikipedia.org/wiki/Fibonacciho_postupnos%C5%A5

---
## Implementácia

```c
int fibonacci(int n){
  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  // A co dalej ???
  //
}
```

---
## Implementácia

```c
int fibonacci(int n){
  // Ukocovacia podmienka
  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  // Rekurzivne volanie
  return fibonacci(n-1) +  fibonacci(n-2);
}
```

---
## Rekurzívne algoritmy

- Ukončovacia podmienka
- Telo: Volanie samého seba

---
## Ukončovacia podmienka

- Určuje triviálny prípad.
- Ak ju určíme zle, dôjde k nekonečnému opakovaniu a pretečeniu zásobníka.
- Pri každom ďalšom volaní sa skopírujú lokálne premenné

[note]
- Zle definovaná ukončovacia podmienka: nekonečný beh
- Príliš hlboký strom volania: pretečenie stacku
[/note]

---
## Telo

- Určuje, ako problém rozložiť na menšie časti.
- Spája čiastkové výsledky.

---
## Rozdeľuj a panuj

Rozdeľ problém na menšie časti tak, aby každá bola menšou verziou pôvodného problému.
Ak je problém dostatočne malý, riešenie je triviálne. Pospájaj čiastkové riešenia.

---

[ntroduction to Algorithms]
> Divide the problem into a number of subproblems that are smaller instances of the
> same problem. Conquer the subproblems by solving them recursively. If the subproblem sizes are
> small enough, however, just solve the subproblems in a straightforward manner.
> Combine the solutions to the subproblems into the solution for the original problem.

---


## Triedenie


---
## Triedenie

Rekurzia sa často využíva pri triedení.

----

## Formálna definícia triedenia

- Vstup: zoznam hodnôt;
- Výstup: zotriedený zoznam hodnôt;
- Postup:  usporiadaj prvky tak aby na prvom mieste bol najmenší prvok a aby za väčším prvkom nikdy nešiel menší

----

## Rozdeľuj a panuj nad triedením

----

### Triedenie jednoprvkového zoznamu

Netreba robiť nič

----

### Triedenie dvojprvkového zoznamu

Vymeň dva prvky.

----

### Triedenie viacprvkového zoznamu

Daj na prvé miesto najmenší prvok.

Zotrieď zvyšný (menší) zoznam .

---
## Bubble sort

1. Zober a usporiadaj prvú dvojicu.
1. To isté urob s ďalšími dvojicami tak aby najväčší prvok bol na konci poľa.
1. Opakuj celý postup na zvyšok poľa okrem už zotriedených prvkov.



----

![Bubble](Bubble-sort-example-300px.gif)

----

### Insertion Sort

1. Zober ľubovoľný prvok.
1. Vlož ho do nového poľa tak, aby bol na správnom mieste.
1. Pokračuj, až kým všetky prvky nie sú zotriedené.

----

![Insertion sort](Insertion-sort-example-300px.gif)

---
## Heap Sort

Je založený na dátovej štruktúre "kopa".

Na budúce.

----

![Heap sort](Heapsort-example.gif)

----

### Iné triedenia

- Insertion sort
- merge sort
- quick sort

---
## Výpočtová zložitosť algoritmu triedenia

\( O(n^2) \)

---
## Výpočtová zložitosť algoritmu triedenia


!!! Zložitosť vloženia prvku do poľa môže byť veľká


---
## Priestorová zložitosť

Je potrebné nové pole na uloženie výsledku?

 \(O(1) \)  alebo   \(O(n) \) 

---
## Challenge

Vaša vlastná implementácia heapsort.

----

## References

- Introduction to Algorithms Book by Charles E. Leiserson, Clifford Stein, Ronald Rivest, and Thomas H. Cormen
-  https://en.wikipedia.org/wiki/Recursion_(computer_science)
- Pictures by [Wikipedia](https://Wikipedia.org)

---
## Zhrnutie

- Rekurzívny algoritmus sa skladá z ukončovacej podmienky a časti ktorá volá samu seba.
- Pri rekurzívnom algoritme sa snažíme problém rozdeliť na jednoduchšie časti a tie potom spojiť.

