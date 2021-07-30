---
title: Title
---
# Vyvážené vyhľadávacie stromy

---
## Vlastnosti vyhľadávacieho stromu

- Hĺbka stromu:: maximálny počet predkov listového uzla. (koľko "poschodí má strom")
- Vyváženosť stromu:: rozdiel medzi počtom potomkov na ľavej a pravej strane.

---
## Vyváženosť stromu

Vkladanie prvkov v určitom poradí môže spôsobiť,
že na jednej strane môže byť podstatne viac prkov ako na druhej.

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

- Ľavá a pravá rotácia

---
## Čo je to rotácia

Operácia ktorá zmené štruktúru stromu, ale nezmení poradie prvkov pri prechádzaní INORDER:

https://en.wikipedia.org/wiki/Tree_rotation


---
# Ľavá rotácia stromu

- Zväčšujeme ľavú výšku a zmenšujeme pravú výšku
- Ak je ľavá výška menšia ako pravá

---
## Ľavá rotácia


       ROOT        ľavá rotácia       PIVOT
       /   \            =>            /   \
      A    PIVOT                    ROOT   C
           /   \                    /   \
         B      C                  A     B


---
## Rotácia naľavo

```c
struct node* rotate_left(struct node* parent){
    struct node* pivot = parent->right;
    assert(pivot != NULL);
    parent->right = pivot->left;
    pivot->left = parent;
    return pivot;
}
```

---
# Prravá  rotácia stromu

- Zväčšujeme pravú  výšku a zmenšujeme ľavú výšku
- Ak je pravá výška menšia ako ľavá

---
## Rotácia


           ROOT    pravá rotácia     PIVOT
          /   \         =>           /   \
       PIVOT   C                    A    ROOT   
       /   \                            /   \
      A     B                          B     C



---
## Rotácia napravo

```c
struct node* rotate_right(struct node* parent){
    struct node* pivot = parent->left;
    assert(pivot != NULL);
    parent->left = pivot->right;
    pivot->right = parent;
    return pivot;
}
```

---
## Rotácie pre vyváženie stromu

image::Tree_rotation_animation_250x250.gif[Tree Rotation Animation]

https://en.wikipedia.org/wiki/Tree_rotation

## Rotácie pre vyváženie stromu

- Ľavá rotácia zvýší výšku stromu na ľavej strane
- Pravá rotácia zvýší výšku stromu na pravej strane

## Vyvážené vyhľadávacie stromy

Pri vkladaní a vyberaní prvkov sa strom vyvažuje pomocou rotácií.

- Avelson-Veltski-Landis tree
- Red-Black tree
- 2-3 tree
- B-tree

## AVL strom

Koeficient vyváženia:: rozdiel medzi výškou pravého a ľavého syna.

Každý uzol AVL stromu má koefiient vyváženia -1, 0 alebo 1

## Vkladanie do AVL stromu

- Vložíme uzol.
- Rotujeme všetky uzlu, ktoré sa stali nevyvážené.

## Mazanie z AVL stromu

- Rotujeme uzol
- Vymažeme uzol

## Zhrnutie

- Pomocou vyhľadávacieho stromu vieme pripraviť asociatívne pole.
- Všetky dôležité operácie majú zložitosť `log(n)`.
- Nevyvážený strom sa degraduje na spojkový zoznam.
- Stromy sa vyvažujú pomocou rotácií.

## Koniec
