# 7\. Spojkový zoznam

# Ako uložiť dáta

  - Papierik

  - Notes

  - Kalendár

  - Tabuľka v Exceli

  - Databáza

  - Textový súbor

# Ktorá metóda je najlepšia ?

Záleži od požiadaviek, každá má svoje výhody a nevýhody

INFO: Použi počítač…​

# Spôsoby uloženia viacerých údajov v pamäti počítača

  - Dynamické a statické polia

  - Iné pamäťové štruktúry
    
      - spojkové zoznamy
    
      - binárne vyhľadávacie stromy
    
      - N-árne vyhľadávacie stromy
    
      - hashovacie tabuľky

# Viac v predmete "Údajové štruktúry a algoritmy"

# Polia

  - jednoduché

  - pozná ich prekladač

  - konštatný čas výberu n-tého prvku

# Typická práca s poľom

``` c
int pole[10] = {1,2,3,4,5,6,7,8,9,10};
int stvrty = pole[3];
for (int i = 0; i < 10; i++){
    printf("%d\n",pole[i]);
}
```

# Typická práca s dynamickým poľom

``` c
int* pole = malloc(sizeof(int) * 10);
for (int i = 0; i < 10; i++){
    pole[i] = i;
}
int stvrty = pole[3];
free(pole);
```

# Nevýhody polí

  - Lineárny čas vloženia nového prvku

  - Lineárny čas vyhľadania hodnoty

Lineárna zložitosť je dosť zlá

# Algoritmus vloženia nového prvku

  - Musím posunúť všetky prvky napravo

  - Nemusím mať dosť miesta
    
      - pole je potrebné alokovať nanovo

# Algoritmus vloženia nového prvku

``` c
for (c = n - 1; c >= position - 1; c--)
  array[c+1] = array[c];

array[position-1] = value;
```

<https://www.programmingsimplified.com/c/source-code/c-program-insert-element-in-array>

# Spojkový zoznam

# Spojkový zoznam

  - Umožňuje ľahké pridanie nového prvku

  - Umožňuje ľahké preusporiadanie

  - Jazyk C, ani štandardná knižnica nepoznajú spojkový zoznam.
    
      - Musíme si ho naprogramovať

# Ako vyzerá spojkový zoznam

  - Každá hodnota obsahuje odkaz na ďalšiu hodnotu

  - Každá hodnota je osobitne alokovaná

![sll](Singly-linked-list.svg)

# Ako vyzerá spojkový zoznam

<https://www.slovakrail.sk/fileadmin/Obrazky2/fotogaleria_nova/radenie_vlakov/2019/1_zmena/Kosice1_.jpg>

# Jeden prvok spojkového zoznamu

``` c
struct node {
    int value;
    struct node* next;
}
```

# Opakovanie: Statická alokácia štruktúry

``` c
struct node one_node;
one_node.value = 1;
one_node.next = NULL;
```

Operátor .

INFO: Statická alokácia sa nepoužíva pri spojkovom zozname

# Vytvorenie prvku spojkového zoznamu

``` c
struct node* create_node(int value){
    struct node* linked_list = malloc(sizeof(struct node));
    linked_list->value = 1;
    linked_list->next = NULL;
    return linked_list;
}
```

## Dynamická alokácia pamäte

``` c
(struct node*)malloc(sizeof(struct node));
```

  - Operátor sizeof

  - Operátor pretypovania

# Jeden prvok spojkového zoznamu

``` 
  +------------+
  | 'a' | NULL |
  +------------+
#aabb
```

# Viacprvkový spojkový zoznam

``` 
   +-------------+      +-------------+      +------------+
   | 'a' | #aa01 | -->  | 'a' | #aabb | -->  | 'a' | NULL |
   +-------------+      +-------------+      +------------+
#0a01                #aa01                #aabb
```

# Pridanie prvku do spojkového zoznamu

1.  Vytvoríme nový prvok

2.  Zapíšeme jeho adresu do predošlého prvku

<!-- end list -->

``` c
struct node* linked_list = create_node(1);
struct node* next_node = create_node(2);
linked_list->next = next_node;

free(next_node);
free(linked_list)
```

# Pridanie nového prvku na začiatok

``` c
struct node* add(struct node* list,int value) {
    struct node* item = create_node(value);
    item->next = list;
    return item;
}
```

# Pridanie nového prvku na koniec

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

# Prechádzanie spojkového zoznamu

1.  Zoberiem prvý prvok

2.  Ak je prvok nulový, skončím

3.  Zoberiem ďalší prvok a pokračujem bodom 2.

# Prechádzanie spojkového zoznamu (pomocou for)

``` c
for(struct node* this = linked_list;this != NULL;this = this->next){
    if (this->value == 'a'){
        printf("Nasiel som a");
    }
}
```

# Rekurzívne zrušenie celého spojkového zoznamu

``` c
void delete(struct node* list){
    if (list!=NULL){
        delete(list->next);
        free(list);
    }
}
```

# Fragmentácia pamäte

Pamäť je organizovaná do blokov a je podobná papierovej páske.

O pridelenie pamäte sa stará operačný systém.

Vyhradenie malého množstva pamäte často zaberie celý blok

Spojkový zoznam je neefektívny vzhľadom na spotrebu pamäte.

<https://stackoverflow.com/questions/3770457/what-is-memory-fragmentation>

# Koniec
