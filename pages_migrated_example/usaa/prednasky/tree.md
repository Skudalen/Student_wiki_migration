---
title: Vyhľadávací strom
---
# Vyhľadávací strom

---
## Vyhľadávací strom

Zovšeobecnenie spojkového zoznamu, kde jeden prvok má viac smerníkov.

---
- Každý uzol má nula alebo viac podradených uzlov (synov).
- Uzol, ktorý nemá nadradený uzol sa nazýva koreň stromu.
- Uzol, ktorý nemá podradené uzly sa nazýva list.
- Každý uzol je zároveň koreňom podradeného stromu.


---
## Prvok binárneho vyhľadávacieho stromu

- kľúč
- hodnota
- smerníky na ďalšie prvky
    - ľavý syn
    - pravý syn

---
## Príklad na (binárny) vyhľadávací strom

```c
struct binary_tree {
    int data;
    struct binary_tree* left;
    struct binary_tree* right;
};
```

---
## Ako to vyzerá v pamäti?


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

---
## Demo BST

https://www.cs.usfca.edu/~galles/visualization/BST.html


---
## Aritmetický výraz je strom


            Matematický výraz:  3 * (5 + 6)
    
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
---
## Inorder

Naľavo, hodnota, napravo

	3 * 5 + 6

Pozor na zátvorky !!!

---
## Preorder

hodnota, naľavo, napravo

    * + 5 6 3

---
## Postorder

naľavo, napravo, hodnota

	5 6 + 3 *

---
Reprezentácia hierarchických štruktúr

- matematické výrazy
- DOM (Document Object Model)
    - html stránka
    - office dokument
- AST (Abstract Syntax Tree)
    - preklad jazyka C do strojového kódu


---
## Asociatívne pole 

s pomocou binárneho vyhľadávacieho stromu

- Každá hodnota sa tam nachádza maximálne raz (nemôžu sa opakovať)
- Je definovaná operácia čiastočného usporiadania (hodnoty môžeme zoradiť a porovnať).
- Všetky hodnoty na ľavej strane sú menšie, všetky hodnoty na pravej strane sú väčšie.

https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
---

## Triedenie s pomocou BST

- Vložíme prvky do BST
- Vypíšeme prvky INORDER
- logaritmická zložitosť vyhľadávania

---
## Prechádzanie BST

Akým spôsobom vieme strom zapísať do jedného riadka?

- Inorder
- Preorder
- Postorder

---
## Načítanie do stromu

Ak máme zadaný zápis v jednom riadku, akým spôsobom ho môžeme uložiť do stromu?

- infixná notácia
- prefixná notácia
- postfixná notácia (reverzná poľská notácia)


---
## Vyhľadávanie vo vyhľadávacom strome

(pre-order)

1. Pozrieme sa na koreň stromu.
1. Ak sa hodnoty zhodujú, našli sme výsledok.
1. Ak sa nezhodujú, a hodnota je menšia, hľadáme vľavo.
1. Ak je hodnota väčšia, hľadáme vpravo.

---
## Vymazanie z BST

- Ak má nula potomkov:Vymažeme
- Ak má jedného potomka: Nahradíme za potomka a vymažeme
- Ak má dvoch potomkov:
	- Nájdeme k nemu "ďalší prvok".
	- Vymeníme hodnoty.
	- Z väčšieho podstromu vymažeme "ďalší prvok".

---
## Príklad: Počítadlo slov pomocou BST

- Pomocou BST si vieme vytvoriť asociatívne pole
- pole bude stále zoradené podľa abecedy
- bude mať možnosť vymazania niektorého slova.

---
# Vyvážené vyhľadávacie stromy

---
## Vlastnosti vyhľadávacieho stromu

- Výška stromu: maximálny počet predkov listového uzla. (koľko "poschodí má strom")
- Vyváženosť stromu:: rozdiel medzi ľavou a pravou výškou.

---
## Vyváženosť stromu

Vkladanie prvkov v určitom poradí môže spôsobiť,
že na jednej strane môže byť podstatne viac prvkov ako na druhej.

WARNING: Binárny strom sa môže degradovať na spojkový zoznam. operácia vyhľadávania bude mať lineárnu a nie logaritmickú zložitosť.

---
## Zle vyvážený strom.

Výška 3

                  left     +-----+
                      +--- |  1  |
                      |    +-----+
                      v
              left +------+
              +----|  2   |
              |    +------+
              V
          +------+
          |  3   |
          +------+

---
## Vyvážené vyhľadávacie stromy

- počas vkladania alebo vyberania prvku sa vyvažujú
- rotácia stromu: výmena koreňa stromu - vyváženie stromu

---
## Operácie pre vyváženie binárneho stromu



To be continued....

---
