#include <stdio.h>

struct person {
  char name[10];
  char surname[10];
  int age;
};

void write_person(struct person p){
  printf("%s\n",p.name);
  printf("%s\n",p.surname);
  printf("%d\n",p.age);
}

void read_person(struct person* p){
  scanf("%s",&(p->name));
  scanf("%s",&(p->surname));
  scanf("%d",&(p->age));
}
int main(){

    struct person daniel = {
        .name = "Daniel",
        .surname = "Hladek",
        .age = 35
    };

    write_person(daniel);

    struct person janko;
    read_person(&janko);
    write_person(janko);

}
