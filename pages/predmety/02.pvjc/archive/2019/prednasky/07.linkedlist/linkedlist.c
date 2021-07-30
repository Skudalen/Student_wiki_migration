#include <stdio.h>
#include <stdlib.h>

/**
 * Jeden prvok spojového zoznamu
 */
struct node {
    // Hodnota ktorú uchovávame
    int value;
    // Ďalší prvok skojkového zoznamu je spojkový zoznam
    struct node * next;
};

/**
 * Vytvorenie jedného prvku
 */
 
struct node* create_node(int value){
    struct node* linked_list = malloc(sizeof(struct node));
    linked_list->value = 1;
    linked_list->next = NULL;
    return linked_list;
}

/**
 * Pridanie na začiatok spojkového zoznamu
 * 
 * @return Nový začiatok sojkového zoznamu
 */
 
struct node* add(struct node* list,int value) {
    // Nový prvok je nový začiatok spojkového zoznamu
    struct node* item = create_node(value);
    item->next = list;
    return item;
}

/**
 * Pridanie na koniec spojkového zoznamu
 */
struct node* add_end(struct node* list, int value){
    struct node* new = create_node(value);
    if (list == NULL){
        return new;
    }
    struct node* first = list;
    // Prejdeme všetky prvky spojkového zoznamu
    // Posledný prvok je taký, ktorého next je nulový
    while(list->next != NULL){
        list = list->next;
    }
    list->next = new;
    return first;
}

/*
 * Rekurzívne zrušenie spojkového zoznamu.
 */
void free_list(struct node* list){
    // Ak je zoznam prázdny, neurobím nič
    if (list != NULL){
        // ďalší prvok je tiež spojkový zoznam
        free_list(list->next);
        free(list);
    }
}

int main(){
    struct node* list = NULL;
    list = add(list,1);
    list = add(list,2);
    
    for(struct node* this = list;this != NULL;this = this->next){
	    if (this->value == 1){
    	    printf("Nasiel som 1\n");
        }
    }

    free_list(list);
    
    return 0;
}
