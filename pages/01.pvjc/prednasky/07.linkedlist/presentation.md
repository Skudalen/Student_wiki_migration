---
title: Spojkový zoznam
published: true
---
# 7. Spojkový zoznam

---
### Ako uložiť dáta?

  - Papierik
  - Notes
  - Kalendár
  - Tabuľka v Exceli
  - Databáza
  - Textový súbor

---
### Ktorá metóda je najlepšia ?

Záleži od požiadaviek, každá má svoje výhody a nevýhody

INFO: Použi počítač...

---
### Ktorá metóda uloženia je najlepšia ?

- čo najjednoduchšia práca?
- čo najrýchlejšie vyhľadanie?
- čo najmenej potrebnej pamäte?
- čo najrýchlejšia modifikácia? (vymazanie a pridanie)

---
###  Zabudované typy

- premenné na jeden záznam
- polia na viac záznamov
- polia štruktúr na viac zložitejších záznamov

---
# Polia

- jednoduché
- pozná ich prekladač
- konštatný čas výberu n-tého prvku

---
### Typická práca s poľom

``` c
int pole[10] = {1,2,3,4,5,6,7,8,9,10};
int stvrty = pole[3];
for (int i = 0; i < 10; i++){
    printf("%d\n",pole[`i]);
}
```

---
# Typická práca s dynamickým poľom

``` c
int* pole = malloc(sizeof(int) * 10);
for (int i = 0; i < 10; i++){
    pole[i] = i;
}
int stvrty = pole[3];
free(pole);
```

---
### Nevýhody polí

  - Lineárny čas vloženia nového prvku
  - Lineárny čas vyhľadania hodnoty

Lineárna zložitosť je dosť zlá

---
### Algoritmus vloženia nového prvku

  - Musím posunúť všetky prvky napravo
  - Nemusím mať dosť miesta
      - pole je potrebné alokovať nanovo

---
### Algoritmus vloženia nového prvku

``` c
for (c = n - 1; c >= position - 1; c--)
  array[c+1] = array[c];

array[position-1] = value;
```

<https://www.programmingsimplified.com/c/source-code/c-program-insert-element-in-array>

---
# Údajové štruktúry

- spojkové zoznamy
- binárne vyhľadávacie stromy
- N-árne vyhľadávacie stromy
- hashovacie tabuľky

---
## Viac v predmete "Údajové štruktúry a algoritmy"

---
# Spojkový zoznam

---
### Spojkový zoznam

- umožňuje pridanie alebo zmazanie prvku kdekoľvek bez toho aby sme museli posúvať prvky.
- Pamätáme si pozíciu začiatku.
- Ostatné prvky si musíme vyhľadať.

---
Jazyk C, ani štandardná knižnica nepoznajú spojkový zoznam.

      - Musíme si ho naprogramovať
---
### Ako vyzerá spojkový zoznam

- Každý prvok obsahuje obsahuje odkaz na ďalší prvok.
- Každý prvok je dynamicky alokovaný.

![sll](Singly-linked-list.svg)

---
### Ako vyzerá spojkový zoznam

<https://www.slovakrail.sk/fileadmin/Obrazky2/fotogaleria_nova/radenie_vlakov/2019/1_zmena/Kosice1_.jpg>

---
### Jeden prvok spojkového zoznamu

``` c
struct node {
    // Ľubovoľné premenné
    int value;
    // Odkaz na ďalší prvok
    struct node* next;
};
```
---
### Vytvorenie prvku spojkového zoznamu

``` c
struct node* create_node(int value){
    struct node* linked_list = calloc(1,sizeof(struct node));
    linked_list->value = 1;
    linked_list->next = NULL;
    return linked_list;
}
```

---
### Dynamická alokácia pamäte

``` c
(struct node*)malloc(sizeof(struct node));
```

  - Operátor `sizeof`
  - Operátor pretypovania `(struct node*)`

---
### Jeden prvok spojkového zoznamu

``` 
  +------------+
  | 'a' | NULL |
  +------------+
#aabb
```
---
### Viacprvkový spojkový zoznam

``` 
   +-------------+      +-------------+      +------------+
   | 'a' | #aa01 | -->  | 'a' | #aabb | -->  | 'a' | NULL |
   +-------------+      +-------------+      +------------+
#0a01                #aa01                #aabb
```

---
### Pridanie prvku do spojkového zoznamu

1.  Vytvoríme nový prvok
2.  Zapíšeme jeho adresu do predošlého prvku

---
### Pridanie nového prvku na začiatok

``` c
// Vytvoríme zoznam a poznačíme si začiatok
struct node* old_node = create_node(1);
struct node* zaciatok = old_node;

// Pridáme nový prvok
struct node* new_node = create_node(2);
// Zaradíme za neho starý prvok
new_node->next = old_node;
// Zmeníme začiatok
zaciatok = new_node;

// Uvoľníme pamäť
free(next_node);
free(linked_list)
```

---
### Pridanie nového prvku na začiatok (funkcia)

Prvý argument je vždy starý začiatok spojkového zoznamu.
Funkcia vždy vráti nový začiatok spojkového zoznamu.

``` c
struct node* add(struct node* start,int value) {
    struct node* item = create_node(value);
    item->next = start;
    return item;
}
```

---
### Pridanie nového prvku na začiatok (funkcia)

Použitie

``` c
// Zoznam je prázdny
struct node* zaciatok = NULL;
zaciatok = add(zaciatok,1);
zaciatok = add(zaciatok,2);
zaciatok = add(zaciatok,3);
// 3->2->1

```
---
### Pridanie nového prvku na koniec

``` c
struct node* add_end(struct node* list,int value) {
    struct node* item = create_node(value);
    if (list == NULL){
        return item;
    }
    struct node* first = list;
    while (list->next != NULL){
        list = list->next;
    }
    list->next = item;
    return first;
}
```

---
### Prechádzanie spojkového zoznamu

1.  Zoberiem prvý prvok
2.  Ak je prvok nulový, skončím
3.  Zoberiem ďalší prvok a pokračujem bodom 2.

---
### Prechádzanie spojkového zoznamu

``` c
for(struct node* this = linked_list;this != NULL;this = this->next){
    if (this->value == 'a'){
        printf("Nasiel som a");
    }
}
```

---
### Rekurzívne zrušenie celého spojkového zoznamu


``` c
void delete(struct node* list){
    if (list!=NULL){
        delete(list->next);
        free(list);
    }
}
```

---
### Fragmentácia pamäte

- Pamäť je organizovaná do blokov a je podobná papierovej páske.
- O pridelenie pamäte sa stará operačný systém.
- Vyhradenie malého množstva pamäte často zaberie celý blok
- Spojkový zoznam je neefektívny vzhľadom na spotrebu pamäte.

<https://stackoverflow.com/questions/3770457/what-is-memory-fragmentation>

---
### Spojkový zoznam spôsobuje fragmentáciu pamäte

---
Spojkový zoznam nie je dobrý ak:

- potrebujeme sa rýchlo pozrieť do prostriedku alebo na koniec 
- potrebujeme uložiť veľmi veľa záznamov

Spojkový zoznam je dobrý ak:

- potrebujeme rýchlo vložiť niečo na začiatok alebo do prostriedku
- neviem koľko miesta budeme potrebovať
