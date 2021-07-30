---
title: Spojkový zoznam
---
# Spojkový zoznam

---
## Čo je spojkový zoznam

- Údajová štruktúra, ktorá umožňuje ľahké pridanie alebo odobranie nového prvku.
- Jeden prvok obsahuje hodnotu a smerník na ďalší prvok.
- Prvky spojkového zoznamu sú pospájané pomocou smerníkov.

---
## Časté operácie so spojkovým zoznamom

- Vloženie hodnoty (INSERT)
- Odobratie hodnoty (DELETE)
- Vyhľadanie hodnoty (SEARCH)

---
## Jeden prvok spojkového zoznamu

    +------------+
    | 'a' | NULL |
    +------------+
     #aabb

---
## Viacprvkový spojkový zoznam

    +-------------+      +-------------+      +------------+
    | 'a' | #aa01 | -->  | 'b' | #aabb | -->  | 'c' | NULL |
    +-------------+      +-------------+      +------------+
    #0a01                #aa01                #aabb

---
## Spojkový zoznam si musíme naprogramovať

Jazyk C, ani štandardná knižnica nepoznajú spojkový zoznam.

---
## Jeden prvok spojkového zoznamu

```c
struct node {
    int value;
    struct node* next;
}
```
---
### Statická alokácia sa nedá použiť

```c
struct node one_node;
one_node.value = 1;
one_node.next = NULL;
```

---
## Dynamická alokácia 

```c
struct node* linked_list = malloc(sizeof(struct node));
linked_list->value = 1;
linked_list->next = NULL;
free(linked_list);
```

---
### Dynamická alokácia pamäte

```c
(struct node*)malloc(sizeof(struct node));
```

- Operátor `->`.
- Operátor `sizeof`.
- Operátor pretypovania `()`.

---
## Pridanie prvku do spojkového zoznamu

---

```c
struct node* linked_list = malloc(sizeof(struct node));
linked_list->value = 1;
linked_list->next = NULL;

struct node* next_node = malloc(sizeof(struct node));
next_node->value = 2;
next_node->next = NULL;

linked_list->next = next_node;

free(next_node);
free(linked_list)
```
---
## Pridanie prvku na začiatok

1. Vytvoríme nový prvok
1. Zapíšeme do neho adresu ďalšieho prvku

---
```c
struct node* add_node(struct node* first, int value){
   struct node* newnode = calloc(1,sizeof(struct node));
   newnode->value = value;
   newnode->next = first;
   return newnode;
}
```

---
## Pridanie prvku na koniec 

---
```c
struct node* add(struct node* list,int value) {
    // Vytvorenie nového prvku
    struct node* item = (struct node*)malloc(sizeof(struct node));
    item->value = value;
    item->next = NULL;
    if (list == NULL){
        list = item;
    }
    else {
       // Vyhladanie posledneho prvku
        struct node* this=list;
        while(this->next != NULL){
            this = this->next;
        }
        this->next = item;
    }
    return list;
}
```

---
## Rekurzívne zrušenie

```c
void delete(struct node* list){
    if (list!=NULL){
        delete(list->next);
        free(list);
    }
}
```

----

## Prechádzanie zoznamu

```c
struct node* this = first;
while(this != NULL){
   this = this->next;
}
```

---

## Prechádzanie  for

```c
for(struct node* this = linked_list;this != NULL;this = this->next){
    if (this->value == 'a'){
    	printf("Nasiel som a");
    }
}
```

---

## Vyhľadanie posledného prvku

```c
struct node* this = first;
while(this->next != NULL){
   this = this->next;
}
```

----

## Opakovanie

- Spojkový zoznam je údajová štruktúra.
- Modifikácie na začiatku alebo konci majú konštantnú zložitosť.
- Pridanie na koniec má lineárnu zložitosť.
- Skladá sa z hodnôt prepojených smerníkmi.
- Používame ho ako buffer (queue alebo stack).

