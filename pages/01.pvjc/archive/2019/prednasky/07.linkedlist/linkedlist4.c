#include <stdio.h>
#include <stdlib.h>

struct ll {
    int value;
    struct ll* next;
};

// Pridanie na zaciatok spojkového zoznamu
struct ll* add_start(struct ll* head, int value){
    struct ll* new = calloc(1,sizeof(struct ll));
    new->value = value;
    new->next = head;
    return new;
}

// Pridanie na koniec spojkového zoznamu
struct ll* add_end(struct ll* head, int value){
    struct ll* new = calloc(1,sizeof(struct ll));
    new->value = value;
    new->next = NULL;
    if (head == NULL){
        return new;
    }
    struct ll* this = head;
    while(this->next != NULL){
        this = this->next;
    }
    this->next = new;
    return head;
}

// Rekurzívne pridanie na koniec spojkovho zoznamu
struct ll* add_end_recursive(struct ll* head, int value){
    if (head == NULL){
        struct ll* new = calloc(1,sizeof(struct ll));
        new->value = value;
        new->next = NULL;
        return new;
    }
    head->next = add_end_recursive(head->next, value);
    return head;
}


// Odobratie zo začiatku spojkového zoznamu.
struct ll* remove_start(struct ll* head){
	if (head == NULL){
    	return NULL;
	}
	struct ll* new_head = head->next;
	free(head);
	return new_head;
}

// Odobratie z konca spojkového zoznamu
struct ll* remove_end(struct ll* head){
	if (head == NULL){
    	return NULL;
	}
	if (head->next == NULL){
    	free(head);
    	return NULL;
	}
	struct ll* prev = NULL;
	struct ll* this = head;
	while(this->next != NULL){
    	prev = this;
    	this = this->next;
	}
	free(this);
	prev->next = NULL;
	return head;
}

// Rekurzívne odobratie z konca spojkového zoznamu
struct ll* remove_end_recursive(struct ll* head){
	if (head == NULL){
    	return NULL;
	}
	if (head->next == NULL){
    	free(head);
    	return NULL;
	}
	head->next = remove_end_recursive(head->next);
	return head;
}

// Zmazanie celého spojkového zoznamu
void destroy_list(struct ll* head){
    while (head != NULL){
        struct ll* this = head;
        head = head->next;
        free(this);
    }
}

// Rekurzívne zmazanie celého spojkového zoznamu
void destroy_list_recursive(struct ll* head){
    if (head != NULL){
    	destroy_list_recursive(head->next);
    	free(head);
    }
}

int main(){
    return 0;
}
