// 
// Priklad na spojkovy zoznam.
//
// Demonstruje pridavanie na koniec 
// a vyhladavanie v spojkovom zozname.
//
// (c) 2018 Daniel Hladek @ Technicka univerzita v Kosiciach
//
// Pre vyukove ucely
//
// v 1.0
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * Jeden prvok spojkoveho zoznamu
 */
struct node {
    // Hodnota v spojkovom zozname
    int value;
    // Adresa dalsieho prvku
    struct node* next;
};

/**
 * Pridanie prvku na koniec zoznamu.
 *
 * Funkcia vytvori novy prvok a inicializuje ho. 
 *
 * @arg list Zoznam kde sa ma pridat prvok. Moze by NULL ak je zoznam prazdny.
 * @arg value Hodnota, kotra sa ma pridat.
 * @return Adresa noveho zaciatku zoznamu.
 */
struct node* add(struct node* list,int value) {
    // Vytvorenie noveho prvku
    struct node* item = (struct node*)malloc(sizeof(struct node));
    assert(item != NULL);
    item->value = value;
    item->next = NULL;
    // Ak je zoznam prazdny, novy prvok je na prvom mieste.
    if (list == NULL){
        list = item;
    }
    else {
        // Ak zoznam nie je prazdny
        struct node* this=list;
        // Vyhladame koniez zoznamu
        while(this->next != NULL){
            this = this->next;
        }
        // This je teraz posledny prvok.
        // Posledny prvok je taky, ktoreho next je rovny NULL
        assert(this->next == NULL);
        this->next = item;
    }
    return list;
}

/**
 * Vyhladanie hodnoty v zozname
 *
 * Funkcia prejde vsetky prvky v zozname a vrati prvy, ktory ma zadanu hodnotu.
 *
 * @arg list Zaciatok zoznamu ke sa ma vyhladavat.
 * @arg value Hodnota, kotra sa ma vyhladat
 * @return Adresa prvku, kotry ma zadanu hodnotu. NULL, ak sa prvok v zoznme nenachadza
 */
struct node* search(struct node* list,int val) {
    if (list != NULL){
        for (; list != NULL; list = list->next){
            if (list->value == val){
                break;
            }
        }
    }
    return list;
}


/**
 * Vyhladanie i-teho prvku v zozname
 *
 *
 * @arg list Zaciatok zoznamu ke sa ma vyhladavat. Moze byt aj prazdny zoznam (NULL)
 * @arg index kotry sa ma vyhladat
 * @return Adresa i-teho prvku, alebo NULL ak je zoznam kratsi.
 */
struct node* get(struct node* list,int index) {
    for (int i = 0; i < index; i++ ){
        if (list == NULL){
            break;
        }
        list = list->next;
    }
    return list;
}

/**
 * Zrusenie spojkoveho zoznamu a uvolnennie pamate.
 *
 * Funkcia je pre nazornost implekentovana rekurzivne,
 * sposobuje chyby STACK_OVERFLOW pri prilis velkom zozname.
 *
 */
void delete(struct node* list){
    if (list!=NULL){
        delete(list->next);
        free(list);
    }
}

int main(){
    struct node* linked_list = NULL;
    for (int i = 0; i < 10; i++){
        linked_list = add(linked_list,i);
    }
    struct node* fifth = get(linked_list,4);
    printf("Na piatom mieste je %d\n",fifth->value);

    struct node* stvorka = search(linked_list,4);
    if (stvorka != NULL){
        printf("Nasli sme prvok s hodnotou 4");
    }
    else {
        perror("Chyba funkcie search\n");
        abort();
    }

    struct node* stovka = search(linked_list,100);
    if (stovka == NULL){
        printf("Prvok s hodnotou 100 sa nenachedza v zozname");
    }
    else{
        perror("Chyba funkcie search\n");
        abort();
    }
    delete(linked_list);

    return 0;
}
