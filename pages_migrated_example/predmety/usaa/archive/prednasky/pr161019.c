// Stack a dynamický stack
// Príklad z prednášky USAA 16.10.2019 Daniel Hládek
//
#include <assert.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

// Stack
struct stack {
	// ulozenie hondot
    float pole[STACK_SIZE];
    // pocet hodnot v poli
    int sz;
};

// Pridanie do stacku
void push(struct stack* st,float v){
   // Overenie si, ci nepridavam mimo
       assert(st->sz < STACK_SIZE);
       st->pole[st->sz] = v;
       st->sz += 1;
}

// Dynamicky stack
struct dynamic_stack {
	// Dynamicke pole
    int* pole;
    // Velkost dynamickeho pola
    int capacity;
    // Pocet prvkov v poli
    int sz;
};


// Vytvorenie dynamickeho stacku
void init_dynamic(struct dynamic_stack *st){
    memset(st,0, sizeof(struct dynamic_stack));
    st->capacity = 16;
    st->pole = calloc(st->capacity,sizeof(int) );
}


// Pridanie 
void push_dynamic(struct dynamic_stack* st,int v){
	// Ak nestaci kapacita, zvysime velkost pola
       if (st->capacity <= st->sz){
           st->capacity *= 2;
           st->pole = realloc(st->pole,st->capacity * sizeof(int));
       }
       st->pole[st->sz] = v;
       st->sz += 1;
}

// Uvolnnie pamate
void destroy(struct dynamic_stack *st){
    free(st->pole);
}

int main() {
    struct stack mystack;
    memset(&mystack,0, sizeof(struct stack));
    for (int i = 0;i < 100000; i++){
        push(&mystack,1.1);
    }
    return 0;
}

