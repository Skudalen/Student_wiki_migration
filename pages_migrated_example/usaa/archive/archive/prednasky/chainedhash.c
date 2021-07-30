#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Jedna polozka v databaze
 */
struct item {
    char key[20];
    int value;
    struct item* next;
};

/**
 * Cela tabulka
 */
struct table {
    // Pole smernikov na polozky
    // Ak je hodnota NULL, tak je slot prazdny
    struct item** slots;
    int slot_count;
};

// Alokuje pamat pre dynamicke pole smernikov.
struct table* create_table(){
    struct table* tab = malloc(sizeof(struct table));
    tab->slot_count = 40;
    tab->slots = calloc(tab->slot_count,sizeof(struct item *));
    return tab;
}

// Uvolni pamat
void destroy_table(struct table* tab){
    for (int i = 0; i < tab->slot_count; i++){
        /// Jedna polozka je spojkovy zoznam, uvolni cely spojkovy zoznam
        struct item* list = tab->slots[i];
        while (list != NULL){
            struct item* del = list;
            list = del->next;
            free(del);
        }
    }
    free(tab->slots);
    free(tab);
}

// Hash funkcia, spocita kontrolny sucet pre kluc
unsigned int hash_string(const char* word){
    unsigned int hash = 0;
    for (int counter = 0; word[counter]!='\0'; counter++){
        hash = word[counter] + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

int insert(struct table* tab,const char* key,int value){
    int hash = hash_string(key); 
    // Vyberie polozku v poli s ktorou pracujeme
    int slot_index = hash % tab->slot_count;

    // Ak sa da, tak, ju vyhladame
    struct item* slot = tab->slots[slot_index];
    while (slot != NULL){
    // Ak existuje, modifikujeme ju
        if (strcmp(slot->key,key) == 0) {
            slot->value = value;
            return 1;
        }
        slot = slot->next;
    }
    // Ak neexistuje, pridame ju na zaciatok spojkoveho zoznamu
    struct item* new = malloc(sizeof(struct item));
    strcpy(new->key,key);
    new->value = value;
    new->next = slot;
    tab->slots[slot_index] = new;
    if (new->next){
        return 1;
    }
    return 0;
}

// Vyhlada polozku. Ak exituje, vrati smernik na hodnotu v databaze
// Ak neexituje, vrati NULL
int* find(struct table* tab,const char* key){
    int hash = hash_string(key); 
    int slot_index = hash % tab->slot_count;

    struct item* slot = tab->slots[slot_index];
    while (slot != NULL){
        if (strcmp(slot->key,key) == 0) {
            return &(slot->value);
        }
        slot = slot->next;
    }
    return NULL;
}

// Vymaze polozku z databazy
void delete(struct table* tab,const char* key){
    int hash = hash_string(key); 
    int slot_index = hash % tab->slot_count;

    struct item* slot = tab->slots[slot_index];

    if(slot != NULL){
        struct item* this = slot;
	if (this->next == NULL){
            if (strcmp(this->key,key) == 0) {
		    free(this);
		    tab->slots[slot_index] = NULL;
		    return;
            }
	}
	// Algoritmus vymazania zo spojkoveho zoznamu
	// prev je vzdy predosly prvok
	// Sme si isti, ze prev nie je kandidat na odstranenie
	// kontrolujeme this
	struct item* prev = this;
	this = this->next;
        while (this != NULL){
            if (strcmp(this->key,key) == 0) {
		    // Opravime novy spojkovy zoznam
		    prev->next = this->next;
		    free(this);
		    return;
            }
	    prev = this;
            this = this->next;
        }
    }
    return;
}

int main(){
    struct table* tab = create_table();
    insert(tab,"ahoj",2);
    insert(tab,"svet",4);

    int* val = NULL;
    val = find(tab,"kluc");

    destroy_table(tab);
    return 0;
}
