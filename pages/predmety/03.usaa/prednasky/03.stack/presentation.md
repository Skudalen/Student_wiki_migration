---
title: Title
---
# Údajové štruktúry, Zásobník

---
# Prečo používať údajové štruktúry?

---
## Výhody polí

- jednoduché
- pozná ich prekladač
- konštatný čas výberu n-tého prvku
- lineárna pamäťová náročnosť

---
# Keď základné typy nestačia...

---
## Nevýhody polí

- Lineárny čas vloženia nového prvku
- Lineárny čas vyhľadania hodnoty

---

```c
// Algoritmus vloženia nového prvku do poľa
// Pole array musi byt alokovane aspon na velkost size + 1
void insert(int array*, int size, int value, int index){
    // Aká je zložitosť?
    for (int i = size ; i > index; i--){
        array[i] = array[i-1];
    }
    assert(index <= size);
    array[index] = value;
}
```

---
## Zložitosť vloženia

- V najlepšom prípade? O(1)
- V najhoršom  O(n)
- a priemernom prípade? O(n/2)

---
## Potrebujeme niečo lepšie ako je pole

- logaritmický alebo konštantný čas vloženia
- logaritmický čas vyhľadania

---
## Čo je to údajová štruktúra

[quote, Introduction to Algorithms]

> A data structure is a way to store
> and organize data in order to facilitate access and modifications.

---
## Aplikácie údajových štruktúr

Všade, kde sa pracuje s údajmi...

---
- Databázové systémy;
- Smerovače (routre);
- Analýza paketov;
- Spracovanie textu a multimediálnych dát;
- Kompresné algoritmy a kodeky;
- Šifrovanie, autentifikácia a iné bezpečnostné aplikácie;

---
## Príklady údajových štruktúr

* spojkové zoznamy
* binárne vyhľadávacie stromy
* N-árne vyhľadávacie stromy
* hashovacie tabuľky

---
## Abstraktné operácie

- Dopytové operácie
- Modifikujúce operácie

---
## Dopyt na množinu

SEARCH(S,x):: Vráti smerník na prvok x alebo NULL ak sa prvok nenachádza v množine S

---
## Dopyt na usporiadanú množinu

- MINIMUM(S):: Vráti smerník na najmenši prvok alebo NULL ak je množina S prázdna.
- MAXIMUM(S):: Vráti smerník na najväčší prvok alebo NULL ak je množina S prázdna.

---
## Dopyt na usporiadanú množinu

- SUCCESSOR(S,x):: Smerník ďalší väčší prvok od x alebo NULL ak x je najväčší v množine S.
- PREDECESSOR(S,x)::  Smerník ďalší menší prvok od x alebo NULL ak x je najmenší v množine S.

---
## Modifikácie

- INSERT(S,x)::  Pridá prvok x do množiny S.
- DELETE(S,x)::  Odoberie prvok x z množiny S,


---
## Buffer

---
## Buffer

Miesto pre dočasné uloženie viacerých údajov.

---
## Spôsob práce s buffrom

FIFO:: First in, first out

LIFO:: Last in, first out.

---
## Fronta (Queue)

typ FIFO

---
Operácie so zložitosťou O(1):

- Operácia INSERT pridá prvok na koniec (enqueue)
- Operácie DELETE odoberie prvok zo začiatku. (dequeue)

---
## Fronta (Queue)

video::HwoMDBM4Mq4[youtube]

---
## Zásobník (Stack),

typ LIFO

Operácie so zložitosťou O(1):

- Operácia INSERT pridá prvok na začiatok (push)
- Operácie DELETE odoberie prvok zo začiatku. (pop)
- Vyhľadá prvok na začiatku (peek)

---
## Zásobník

video::umNoxIN45hY[youtube]

---
## Ako vyzerá zásobník v jazyku C

- Dátový typ (štruktúra)
- Množina funkcií pre:
** inicializáciu a uvoľnenie,
** pridanie a odobranie prvku

---
## Štruktúra pre zásobník

- Smerník na začiatok poľa
- Veľkosť poľa (kapacita)
- Počet prvkov v stacku

---
## Štruktúra pre zásobník

```c
struct stack {
 int size;
 int capacity;
 char* array;
}
```

---
## Inicializácia

1. Ako parameter prijme počiatočné hodnoty.
1. Dynamicky alokuje štruktúru
1. Inicializuje jej obsah
    1. Na začiatku vyhradíme pole na počiatočnú veľkosť.
    1. Počet prvkov nastavíme na nulu
1. Vráti smerník na štruktúru.

---
## Inicializácia príklad

```c
struct pole* create_char_array(int size){
    struct pole* res = malloc(sizeof(struct char_array));
    res->size = size;
    res->array = malloc(size * sizeof(char));
    return res;
}
```

---
## Uuvoľnenie štruktúry

1. Ako parameter prijme smerník na štruktúru
1. Uvoľní všetky jej časti.
1. Uvoľní štruktúru.


---
## Uvoľnenie príklad

```c
void destroy_stack(struct stack* stack){
    free(stack->array);
    free(stack);
}
```

---
## Pridanie prvku

Využijeme fakt, že pridanie prvnku na koniec poľa je jednoduché

1. Najprv skontrolujeme či máme dosť miesta.
1. Ak je miesta málo, musíme pole prealokovať na novú veľkosť.
1. Potom môžme vložiť nový prvok.

---
## Pridanie prvku

```c
void push_stack(struct stack* stack, char value){
    if(size == stack->capacity - 1 ){
        stack->capacity = stack->capacity * 2;
        stack->array = realloc(stack->array,stack->capacity);
    }
    stack->array[size] = value;
    stack->size += 1;
}
```

---
## Odobranie prvku

Musíme skontrolovať či je dosť miesta.

Ak chceme, môžeme alokovať pole na menšie aby sa ušetrilo miesto.

Niekedy to nemá zmysel.

---
## Odobranie prvku

```c
int  pop_stack(struct stack* stack){
   if (stack->size == 0){
        return -1;
   }
   char val = stack->array[stack->size];
   stack->size = stack->size - 1;
   return val;
}
```

---
## Zhrnutie

- Údajová štruktúra je abstrakcia práce s pamäťou.
- Buffer je miesto pre dočasné uloženie viacerých údajov.
- Buffer môže byť typu LIFO alebo FIFO.
- LIFO buffer sa nazýva aj zásobník.
