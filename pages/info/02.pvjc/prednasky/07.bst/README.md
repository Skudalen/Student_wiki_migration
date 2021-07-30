# 7. Binárny vyhľadávací strom

## 7. Binárny vyhľadávací strom


## Rodostrom

[.stretch]
image::Waldburg_Ahnentafel.jpg[]


## Čo je to BST

Pamäťová štruktúra

- Logaritmická zložitosť všetkých operácií
- Údaje sú v pamäti vždy zotriedené 



## Pravidlá BST

- Každá hodnota sa tam nachádza maximálne raz (nemôžu sa opakovať)
- Je definovaná operácia čiastočného usporiadania (hodnoty môžeme zoradiť a porovnať).
- Všetky hodnoty na ľavej strane sú menšie, všetky hodnoty na pravej strane sú väčšie.

https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

## Demo BST

https://www.cs.usfca.edu/~galles/visualization/BST.html


### Aká je zložitosť dynamického poľa

- lineárna pre vyhľadanie a vloženie
- konštantná pre náhodný prístup

### Aká je zložitosť spojkového zoznamu

- konštantná pre vloženie
- lineárna pre všetko ostatné


## Ako vyzerá BST

```c
struct BSTNode {
    struct BSTNode* left;
    struct BSTNode* right;
    int value;
}
```
    
## Príklad BST

[.stretch]
image::Binary_search_tree.svg[]


## Operácie s BST

- prechádzanie
- vloženie
- vyhľadanie
- vymazanie

## Prechádzanie BST

- Vyhľadávanie prvku s hodnotou
- Vyhľadávanie miesta, kde sa má vložiť nový prvok

- Inorder
- Preorder
- Postorder

## Inorder

Naľavo, hodnota, napravo

	2 + 3

## Preorder

hodnota, naľavo, napravo

	+ 2 3

## Postorder

naľavo, napravo, hodnota

	2 3 +

## Vyváženosť stromu

Vkladanie prvkov v určitom poradí môže spôsobiť, 
že na jednej strane môže byť podstatne viac prkov ako na druhej.

Binárny strom sa môže degradovať na obojsmerný spojkový zoznam.

- operácia vyhľadávania bude mať lineárnu a nie logaritimickú zložitosť.

## Nevyvážený strom

[.stretch]
image::Full_binary.svg[]

## Obojsmerný spojkový zoznam


image::Doubly-linked-list.svg[]



## Vyvážené binárne stromy

- AVL Tree
- Red-Black Tree 

## N-árne stromy

Jeden uzol môže mať viac hodnôt a viac podstromov.

- 2-3 tree
- B-tree



## Bibliografia

https://en.wikipedia.org/wiki/Binary_search_tree

https://gist.github.com/ArnonEilat/4611213

http://www.zentut.com/c-tutorial/c-binary-search-tree/
