# 6. Spojkový zoznam

## 6. Spojkový zoznam

## Ako uložiť dáta

- Papierik
- Notes
- Kalendár
- Tabuľka v Exceli
- Databáza
- textový súbor

## Ktorá metóda je najlepšia ?

Záleži od požiadaviek, každá má svoje výhody a nevýhody

INFO: Použi počítač...


## Spôsoby uloženia viacerých údajov v pamäti počítača

* Dynamické a statické polia
* Iné pamäťové štruktúry
** spojkové zoznamy
** binárne vyhľadávacie stromy
** N-árne vyhľadávacie stromy
** hashovacie tabuľky

## Výhody polí

- jednoduché
- pozná ich prekladač
- konštatný čas výberu n-tého prvku

### Typická práca s poľom

```c
int pole[10] = {1,2,3,4,5,6,7,8,9,10};
int stvrty = pole[3];
for (int i = 0; i < 10; i++){
	printf("%d\n",pole[i]);
}
```

### Typická práca s dynamickým poľom

```c
int* pole = malloc(sizeof(int) * 10);
for (int i = 0; i < 10; i++){
	pole[i] = i;
}
int stvrty = pole[3];
free(pole);
```

## Nevýhody polí

- Lineárny čas vloženia nového prvku
- Lineárny čas vyhľadania hodnoty

Lineárna zložitosť je dosť zlá

### Algoritmus vloženia nového prvku

```c
for (c = n - 1; c >= position - 1; c--)
  array[c+1] = array[c];

array[position-1] = value;
```

https://www.programmingsimplified.com/c/source-code/c-program-insert-element-in-array

### Problémy vloženia nového prvku

- Keď vkladáme nový prvok, musíme posunúť všetky ostatné
- Musíme overiť, či máme dosť miesta k dispozícii
- Ak nemáme dosť miesta, musíme alokovať novú pamäť, čo je časovo náročné


## Čo je spojkový zoznam

- Pamäťová štruktúra, ktorá umožňuje ľahké pridanie nového prvku
- Jazyk C, ani štandardná knižnica nepoznajú spojkový zoznam.
- Musíme si ho naprogramovať

## Časté operácie so spojkovým zoznamom

- Vloženie hodnoty
- Vyhľadanie hodnoty
- Zrušenie spojkového zoznamu

## Ako vyzerá spojkový zoznam

- Spojkový zoznam sa skladá z hodnôt
- Každá hodnota obsahuje odkaz na ďalšiu hodnotu
- Každá hodnota je osobitne alokovaná

image::Singly-linked-list.svg[sll]


## Jeden prvok spojkového zoznamu

```c
struct node {
    int value;
    struct node* next;
}
```

## Opakovanie: Statická alokácia štruktúry

```c
struct node one_node;
one_node.value = 1;
one_node.next = NULL;
```
Operátor .

INFO: Statická alokácia sa nepoužíva pri spojkovom zozname

## Dynamická alokácia štrukúry

```c
struct node* linked_list = malloc(sizeof(struct node));
linked_list->value = 1;
linked_list->next = NULL;
free(linked_list);
```
Operátor -> 


### Dynamická alokácia pamäte

```c
(struct node*)malloc(sizeof(struct node));
```

- Operátor sizeof
- Operátor pretypovania

## Jeden prvok spojkového zoznamu

    +------------+
    | 'a' | NULL |
    +------------+  
	 #aabb


## Viacprvkový spojkový zoznam

    +-------------+      +-------------+      +------------+
    | 'a' | #aa01 | -->  | 'a' | #aabb | -->  | 'a' | NULL |
    +-------------+      +-------------+      +------------+  
	#0a01                #aa01                #aabb


## Pridanie prvku do spojkového zoznamu

1. Vytvoríme nový prvok
1. Zapíšeme jeho adresu do predošlého prvku

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

## Funkcia na pridanie nového prvku

```c
struct node* add(struct node* list,int value) {
    struct node* item = (struct node*)malloc(sizeof(struct node));
    item->value = value;
    item->next = NULL;
    if (list == NULL){
        list = item;
    }
    else {
        struct node* this=list;
        while(this->next != NULL){
            this = this->next;
        }
        this->next = item;
    }
    return list;
}
```



## Prechádzanie spojkového zoznamu

1. Zoberiem prvý prvok
1. Ak je prvok nulový, skončím
1. Zoberiem ďalší prvok a pokračujem bodom 2.

```c
for(struct node* this = linked_list;this != NULL;this = this->next){
	if (this->value == 'a'){
    	printf("Nasiel som a");
    }
}
```

## Zrušenie celého spojkového zoznamu

```c
void delete(struct node* list){
    if (list!=NULL){
        delete(list->next);
        free(list);
    }
}
```


## Obojsmerný spojkový zoznam

Umožňuje prehľadávanie oboma smermi:

```c
struct node_double_linked {
	node_double_linked* next;
	node_double_linked* prev;
	int value;
}
```

## Fragmentácia pamäte

Pamäť je organizovaná do blokov a je podobná papierovej páske.

O pridelenie pamäte sa stará operačný systém.

Vyhradenie malého množstva pamäte často zaberie celý blok

Spojkový zoznam je neefektívny vzhľadom na spotrebu pamäte.

https://stackoverflow.com/questions/3770457/what-is-memory-fragmentation


## Koniec