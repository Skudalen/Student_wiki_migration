---
title: Vyhľadávací strom
published: true
---
# Vyhľadávací strom

---
## Vyhľadávací strom

Zovšeobecnenie spojkového zoznamu, kde jeden prvok má viac smerníkov.

  - Každý uzol má nula alebo viac podradených uzlov (synov).
  - Uzol, ktorý nemá nadradený uzol sa nazýva koreň stromu.
  - Uzol, ktorý nemá podradené uzly sa nazýva list.
  - Každý uzol je zároveň koreňom podradeného stromu.

---
# Reprezentácia hierarchických štruktúr

  - asociatívne pole
  - matematické výrazy
  - DOM (Document Object Model)
      - html stránka
      - office dokument
  - AST (Abstract Syntax Tree)
      - preklad jazyka C do strojového kódu

---
# Prvok vyhľadávacieho stromu

  - kľúč
  - hodnota
  - smerníky na ďalšie prvky
      - ľavý syn
      - pravý syn
      - rodič

---
# Ako to vyzerá v pamäti?

``` 
        left     +------+   right
            +--- |  5   | ----+
            |    +------+     |
            v                 V
    left +------+          +------+
    +----|  3   |          |  10  |
    |    +------+          +------+
    |
    V
+------+
|  1   |
+------+
```

---
# Demo BST

<https://www.cs.usfca.edu/~galles/visualization/BST.html>

---
# Na čo je to dobré?

    Matematický výraz:  3 * (5 + 6)

``` 
        left     +------+   right
            +--- |  *   | ----+
            |    +------+     |
            v                 V
    left +------+          +------+
    +----| +    |---+      |   3  |
    |    +------+   |      +------+
    V               V
+------+         +------+
|  5   |         |  6   |
+------+         +------+
```

---
# Prechádzanie BST

Akým spôsobom vieme strom zapísať do jedného riadka?

  - Inorder
  - Preorder
  - Postorder

---
# Inorder

Naľavo, hodnota, napravo

    3 * 5 + 6

Pozor na zátvorky \!\!\!


---
# Preorder

hodnota, naľavo, napravo

  - \+ 5 6 3


---
# Postorder

naľavo, napravo, hodnota

    5 6 + 3 *


---
# Načítanie do stromu

Ak máme zadaný zápis v jednom riadku, akým spôsobom ho môžeme uložiť do
stromu?

  - infixná notácia
  - prefixná notácia
  - postfixná notácia (reverzná poľská notácia)


---
# Príklad na (binárny) vyhľadávací strom

``` c
struct binary_tree {
    int data;
    struct binary_tree* left;
    struct binary_tree* right;
};
```


---
# Vyhľadávanie vo vyhľadávacom strome

(pre-order)

1.  Pozrieme sa na koreň stromu.
2.  Ak sa hodnoty zhodujú, našli sme výsledok.
3.  Ak sa nezhodujú, a hodnota je menšia, hľadáme vľavo.
4.  Ak je hodnota väčšia, hľadáme vpravo.


---
# Vymazanie z BST

Vyhľadáme prvok so zadanou hodnotou.

  - Ak má nula potomkov
      - Vymažeme
  - Ak má jedného potomka:
      - Nahradíme za potomka a vymažeme
  - Ak má dvoch potomkov:
      - Nájdeme k nemu "ďalší prvok".
      - Vymeníme hodnoty.
      - Z väčšieho podstromu vymažeme "ďalší prvok".


---
# Triedenie s pomocou BST

  - Vložíme prvky do BST
  - Vypíšeme prvky INORDER


---
# Bibliografia

- [Wikipedia](https://en.wikipedia.org/wiki/Binary_search_tree)
- [Gist](https://gist.github.com/ArnonEilat/4611213)
- [Zentut](http://www.zentut.com/c-tutorial/c-binary-search-tree/)
