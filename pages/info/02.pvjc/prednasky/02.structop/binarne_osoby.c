/**
 *
 * Program na pracu s telefonnym zoznamom konstantnej velkosti
 *
 * Kompilacia: gcc binarne_osoby.c -o binarne_osoby 
 *
 * Program pre účely výuky
 * (c) 2018 Daniel Hládek, Technická univerzita Košice
 */

// Pre funkcie fread,fwrite,fopen,fclose,printf,scanf
#include <stdio.h>
// Pre funkciu qsort
#include <stdlib.h>
// Pre funkciu memset
#include <string.h>

// Maximalna velkost zonamu s kotrou pracujeme
#define SIZE 4

// Parametre v zozname
struct person {
  char name[10];
  char surname[10];
  int age;
};

// Textove nacitanie jednej polozky zoznamu
void write_person_binary(FILE* subor,struct person p){
  fwrite(p.name,sizeof(char[10]),1,subor);
  fwrite(p.surname,sizeof(char[10]),1,subor);
  fwrite(&(p.age),sizeof(int),1,subor);
}

// Binarne nacitanie jednej polozky zoznamu zo suboru
void read_person_binary(FILE* subor,struct person* p){
  fread(p->name,sizeof(char[10]),1,subor);
  fread(p->surname,sizeof(char[10]),1,subor);
  fread(&(p->age),sizeof(int),1,subor);
}

// Zapis polozky na konzolu
void write_person_text(struct person p){
  printf("%s\n",p.name);
  printf("%s\n",p.surname);
  printf("%d\n",p.age);
}

// Precitanie polozky a konzoly
void read_person_text(struct person* p){
  scanf("%s",p->name);
  scanf("%s",p->surname);
  scanf("%d",&(p->age));
}

// Porovnavacia funkcia veku. PRedpis musi vyhovovat funkcii qsort.
// @return nula, ak maju polozky rovnaky vek
int person_age_compare(const void* a,const void* b){
  struct person* osoba_a = (struct person*)a;
  struct person* osoba_b = (struct person*)b;
  return osoba_a->age - osoba_b->age;
}


// Jednoduche rozhranie z prikazoveho riadka
int main(int argc, char** argv){
    struct person zoznam[SIZE];
    // Inizializacia pamete na nulu aby sme nepracovali s nedefinovanou pametou.|
    memset(zoznam, 0,sizeof(struct person)* SIZE);

    // Ak je pocet argumentov prikazoveho riadka nespravny, vypise sa navod na pouzitie a skonci program
    if (argc != 3){
       printf("Program nacita zoznam osob velkosti %d, zotriedi ho a ulozi na disk.\n",SIZE);
       printf("\n");
       printf("Program berie dva argumenty: meno vstupneho suboru a meno vystupneho suboru.\n");
       printf("\n");
       printf("V pripade, ze je meno vstupneho suboru -, pouzije sa standardny vstup.\n");
       printf("V pripade, ze je meno vystupneho suboru -, pouzije sa standardny vystup\n");
       printf("\n");
       printf("Pouzitie standardneho vstupu a vystupu :  cat vstup.txt | binarne_osoby - -  > vystup.txt\n");
       printf("Pouzitie binarnych suborov :   binarne_osoby vstup.bin vystup.bin\n");
       return 0;
    }
    // Ak nie je prvý znak prvého argumentu -
    if (argv[1][0] != '-'){
        // Načítavame v binárnom móde
        FILE* vstupny_zoznam = fopen(argv[1],"r");
        for (int i = 0; i < SIZE; i++){
            // Pre načítanie do premennej musíme použiť jej adresu
            read_person_binary(vstupny_zoznam,&zoznam[i]);
        }
        fclose(vstupny_zoznam);
    }
    else {
        // Inak čítame zo štandardného vstupu
        for (int i = 0; i < SIZE; i++){
            read_person_text(&zoznam[i]);
        }
    }

    qsort(zoznam,SIZE,sizeof(struct person),person_age_compare);

    // Ak nie je prvý znak druhého argumentu -
    if (argv[2][0] != '-'){
        // Zapisujeme v binárnom móde
        FILE* vystupny_zoznam = fopen(argv[2],"w");
        for (int i = 0; i < SIZE; i++){
            write_person_binary(vystupny_zoznam,zoznam[i]);
        }
        fclose(vystupny_zoznam);
    }
    else {
        // Inak vypisujeme na konzolu
        for (int i = 0; i < SIZE; i++){
            write_person_text(zoznam[i]);
        }
    }

    return 0;

}
