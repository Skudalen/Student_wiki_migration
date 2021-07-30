// Príklad na dynamické pole z prednášky č. 4 predmetu Programovanie 
// (c) 2021 Technická univerzita, Daniel Hládek
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Konštanta pre veľkosť poľa
#define SIZE 6

// Načítanie riadku s fixnou veľkosťou.
void read_static(){
    char pole[SIZE];
    memset(pole,0,SIZE);
    char* r = fgets(pole,SIZE,stdin);
    if (r != NULL){
        printf("%s",pole);
    }
}

// Načítanie ľubovoľne veľkého riadku
void read_dynamic(){
    char* pole = malloc(SIZE);
    // Veľkosť poľa
    int size = SIZE;
    // Počet znakov v poli
    int chars = 0;
    while(1){
        // Načitanie po znakoch
        int c = getchar();
        if (c == EOF){
            // Načítanie skonči ak nastane koniec súboru
            // alebo používateľ stlači Ctrl D
            break;
        }
        else {
            // Ak je málo miesta v poli
            // Posledné miesto v poli je vyhradené na nulu.
            if (chars >= size -1 ){
                //printf("Nenam pamet\n");
                //break;
                // Zväčíme pole
                size = size * 2;
                pole = realloc(pole,size);
                // to isté zapísané menej efektívne
                //char* pole2 = malloc(size * 2);
                //memcpy(pole2,pole,size / 2);
                //free(pole);
                //pole = pole2;
                // Ak má OS málo pamäte tak prerušíme program
                assert(pole);
                printf("Mame %d znakov, pole ma velkost %d",chars,size);
            }
            // Zápis znaku do poľa
            // Sme si istí že máme v poli dosť miesta
            pole[chars] = c;
            // Počítadlo znakov
            chars += 1;
        }
    }
    // Pole znakov musí býť platný reťazec
    // teda musí byť zakončené nulou
    pole[chars] = 0;
    // Na konci sa všetky znaky nachádzajú v poli, 
    // pole má ľubovoľnú veľkosť
    printf("%s",pole);
    free(pole);


}

int main(){
    read_dynamic();
    return 0;
}
