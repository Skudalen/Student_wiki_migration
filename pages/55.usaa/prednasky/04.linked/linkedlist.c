#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct todolist {
    char task[12];
    struct todolist* next;
};

struct todolist* create(struct todolist* next,const char* task) {
    struct todolist* n = calloc(1,sizeof(struct todolist));
    strcpy(n->task,task);
    n->next = next;
    return n;

}

struct todolist* add_start(struct todolist* list,const char* task){
    struct todolist* n = create(list,task);
    return n;
}

struct todolist* add_end(struct todolist* list,const char* task){
    struct todolist* n = create(NULL,task);
    if (list == NULL){
        return n;
    }
    // Prejdem spojkovy zoznam a najdem posledny prvok
    struct todolist* this = list;
    while(this->next != NULL){
        this = this->next;
    }
    this->next = n;
    return list;
}

void delete_list(struct todolist* list){
    if (list == NULL)
        return;
    delete_list(list->next);
    free(list);
}

void print_list(struct todolist* list){
    for (struct todolist* this = list; this != NULL; this = this->next){
        printf("%s\n",this->task);
    }

}

int main(){

    struct todolist* one = add_start(NULL,"Studujem");
//
    struct todolist* two = add_start(one,"Vstanem");

    print_list(two);
    delete_list(two);
//    one.next = &two;
//
//    process(one);

    return 0;
}
