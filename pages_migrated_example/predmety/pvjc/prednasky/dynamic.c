///Modul s dynamickým poľom typu `int`
// Toto je len príklad na predmet programovanie
// Daniel Hládek 2020

// Dynamické pole sa prisôsobuje požiadavkám
// Kontrolujeme pomocou funkcie assert, či k pamäti pristupujeme správne.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Dátový typ pre prácu s dynamickým poľom
struct darray {
    // Počet vyhradených pamäťových miest v poli
    int capacity;
    // Adresa prvého miesta
    int* start;
};

// Vyhradenie pamäte s požadovanou veľkosťou
//
// Do štruktúry array sa zapíše kapacita a adresa vyhradenej pamäte
//
void initialize(struct darray* array,int capacity){
    // zapíšeme kapacitu
    array->capacity = capacity;
    // Alokujeme dynamické pole a inicializujeme ho na nulu
    array->start = (int*)calloc(capacity,sizeof(int));
    // Ak je návratová hodnota NULL tak nie je dostatok pamäte
    // program spadne, ale vieme prečo
    assert(array->start != NULL);
}

// Uvoľnenie pamäte
//
// pole start je uvoľnené
void destroy(struct darray* addr){
    free(addr->start);
}

// Zápis na i-te miesto v poli.
//
// V prípade, že je v poli málo miesta,
// tak pole zväčšíme
//
void darray_set(struct darray* addr,int i,int value){
    if (i >= addr->capacity){
        int oldcap = addr->capacity;
        addr->capacity = addr->capacity * 2;
        if (i >= addr->capacity ){
            addr->capacity = i * 2;
        }
        // zväčšíme staré pole na novú veľkosť
        // Ak to je potrebné tak sa obsah skopíruje do nového poľa
        // a staré pole sa uvoľní.
        addr->start  = realloc(addr->start,addr->capacity * sizeof(int));
        // Ak je návratová hodnota NULL tak nie je dostatok pamäte
        assert(addr->start != NULL);
        // Inicializujeme novú časť
        for (int j = oldcap; j < addr->capacity; j++){
            addr->start[j] = 0;
        }
    }
    // Zapíšeme hodnotu
    // Je isté, že pamäť je vyhradená
    addr->start[i] = value;
}

int darray_get(struct darray* array, int i){
    assert(i >= 0 && i < array->capacity);
    // Sme si istí, že čítame z vyhradenej pamäte
    return array->start[i];
}

int main() {
    struct darray da;
    initialize(&da,100);
    darray_set(&da,0,1);
    darray_set(&da,2,7);
    destroy(&da);
    return 0;
}
