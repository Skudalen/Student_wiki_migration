// Max binárna kopa
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Ľubovoľné (dynamické) pole môže byť binárna kopa
struct heap {
    int* array;
    int size;
    int capacity;
};

// Výpočet rodičovského uzla
int parent(int i){
    return (i -1) / 2;
}

// Výpočeť ľavého syna
int left_child(int i){
    return (2*i) + 1;
}

// Výpočet pravého syna
int right_child(int i){
    return (2*i) + 2;
}

// Výmena dvoch prvkov v poli
void swap(int* array,int a, int b){
    int c = array[a];
    array[a] = array[b];
    array[b] = c;
}

// Test kopovitosti
// Pozeráme, či je každý potomok menší ako jeho rodič
// Funkcia zlyhá, ak nájdeme aspoň jedného potomka, väčšieho alebo rovného ako je rodič
void check_heap_property(struct heap* h){
    for (int i = 0; i < h->size ; i++){
        int c = left_child(i);
        if (c >= h->size){
            break;
        }
        assert(h->array[c] >= h->array[i]);
        c = right_child(i);
        if (c >= h->size){
            break;
        }
        assert(h->array[c] >= h->array[i]);
    }
}
// 
// Vytvorenie prázdnej kopy
struct heap* create_heap(int capacity){
    struct heap* h = malloc(sizeof(struct heap));
    h->array = calloc(capacity,sizeof(int));
    h->capacity = capacity;
    h->size = 0;
    return h;
}

// Zmazanie ľubovoľnej kopy
void delete_heap(struct heap* h){
    assert(h);
    free(h->array);
    free(h);
}

// Recursive heapification
/**
 * Predpokladáme, že ľavý a pravý podstrom  prvku i sú kopy.
 *
 * Výsledkom je, že strom s vrcholom i je kopa.
 *
 * @param pole
 * @param velkost pola
 * @param Koren stromu, ktorý sa má upraviť
 */
void heapify2(int* array,int size,int i){
    // Zoberiem i-ty prvok
    int largest = i;
    int l = left_child(i);
    int r = right_child(i);
    // Pozrieme jeho hodnotu a hodnoty jeho potomkov
    // Zistíme kde v tejto trojici sa nachádza najväčšia hodnota
    if (l < size && array[largest] < array[l]){
        largest = l;
    }
    if (r < size && array[largest] < array[r]){
        largest = r;
    }
    // Ak je najväčšia hodnota v potomkovi
    if (largest != i){
	// Vymeníme ich hodnoty
        int v = array[i];
        array[i] = array[largest];
        array[largest] = v;
	// Obnovíme kopovitosť v potomkovi
        heapify2(array,size, largest);
    }
}

void heapify_array(int* array, int size){
    // Začíname od predposlednej úrovne
    // sme si istí, že všetky prvky na poslednej 
    // úrovni sú binárne kopy (lebo nemajú potomkov)
    // Postupne tak obnovíme kopovitosť celého poľa
    for (int i = size / 2; i > 0; i-- ){
        heapify2(array,size,i);
    }
}

int remove_max(struct heap* h){
    assert(h->size > 0);
    int i = 0;
    int res = h->array[i];
    // Vymeníme prvý a posledný prvok a skrátime pole
    h->array[i] = h->array[h->size -1];
    h->size -= 1;
    // Obnonovíme kopovitosť
    heapify2(h->array,h->size,0);
    return res;
}



// Pridanie do kopy
void add(struct heap* h,int value){
    // Pridáme prvok na koniec poľa
    int i = h->size - 1;
    h->size += 1;
    assert(h->size <= h->capacity);
    h->array[i] = value;
    // Pozrieme na jeho rodiča
    int p = parent(i);
    // Pokiaľ rodič existuje a jeho hodnota je menšia
    while(p >= 0 && h->array[p] < h->array[i]){
	// Vymeníme ich hodnoty
        int v = h->array[p];
        h->array[p] = h->array[i];
        h->array[i] = v;
	// Pokračujeme ďalším rodičom
        i = p;
        p = parent(p);
    }
}

/***
 * Z kopy vytvorí zotriedené pole
 */
void heap_sort(int* heap,int size){
    // Na začiatku je najväčší prvok
    for (int i = size -1; i >= 0; i -= 2){
        // Vymenime prvy a posledny prvok
        int v = heap[0];
        heap[0] = heap[i];
        heap[i] = v;
        // Na konci je najväčší prvok.
	// Uvažujeme, že kopa je o jedno menšia
	// Obnovíme kopovitosť
        heapify2(heap,i,0);
    }
}


