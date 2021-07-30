# /prednasky/07.linkedlist/priklad

/************************************\*\*

Welcome to GDB Online. GDB online is an online compiler and debugger
tool for C, C++, Python, PHP, Ruby, C\#, VB, Perl, Swift, Prolog,
Javascript, Pascal, HTML, CSS, JS Code, Compile, Run and Debug online
from anywhere in world.

************************************\*\*\*/ \#include \<stdio.h\>

struct node { int value; struct node \* next; };

Viacprvkový spojkový zoznam

``` 
   +-------------+      +-------------+      +------------+
   | 'a' | #aa01 | -->  | 'a' | #aabb | -->  | 'a' | NULL |
   +-------------+      +-------------+      +------------+
#0a01                #aa01                #aabb
```

Pridanie prvku do spojkového zoznamu

    Vytvoríme nový prvok

    Zapíšeme jeho adresu do predošlého prvku

struct node\* linked\_list = create\_node(1); struct node\* next\_node =
create\_node(2); linked\_list→next = next\_node;

free(next\_node); free(linked\_list)

Pridanie nového prvku na začiatok

struct node\* add(struct node\* list,int value) { struct node\* item =
create\_node(value); item→next = list; return item; }

struct node\* create\_node(int value){ struct node\* linked\_list =
malloc(sizeof(struct node)); linked\_list→value = 1; linked\_list→next =
NULL; return linked\_list; }

struct node\* add\_end(struct node\* list, int value){ struct node\* new
= craete(value); if (list == NULL){ return new; } struct node\* first =
list; while(list→next \!= NULL){ list = list→next; } list→next = new;
return first; }

int main() { struct node\* list = NULL; list = add(list,1); list =
add(list,2);

``` 
    for(struct node* this = list;this != NULL;this = this->next){
        if (this->value == 1){
            printf("Nasiel som 1");
        }
    }
}
```

``` 
    return 0;
}
```
