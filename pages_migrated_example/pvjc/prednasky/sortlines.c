/**
 * Príklad na triedenie riadkov
 * pomocou poľa smerníkov
 *
 * Daniel Hládek pre predmet Programovanie @ TUKE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funkcia lexikograficky porovná dva reťazce
// Ak sú rovnaké, vráti nula
// Jeden reťazec má typ char*, smerník na začiatok reťazca ma adresu char**
int compare(const void* p1,const void* p2){
    char* s1 = *((char**)p1);
    char* s2 = *((char**)p2);
    return strcmp(s1,s2);
   
}

int main() {
    // Riadky si uložíme do poľa smerníkov
    char* pole[100];
    // Pomocné pole na načítanie
    char buffer[100];
    // Počítdlo úspešne načítaných riadkov
    int counter = 0;
    for (int i =0; i < 100; i++){
        char* r = fgets(buffer,100,stdin);
        // Ak sa riadok nepodarilo načítať
        // tak prerušíme načítanie
        if (r == NULL){
            break;
        }
        // Zistenie počtu načítaných znakov
        int l = strlen(buffer);
        if (l == 0){
            break;
        }
        // Alokácia novej pamäte
        // Adresu novej pamäte zapíšeme do poľa smerníkov
        pole[i] = malloc(l + 1);
        memcpy(pole[i],buffer,l+1);
        counter += 1;
    }
    // Zotriedenie
    // adresa poľa na zotriedenie, počet prvkov, veľkosť jedného porvku, porovnávacia funkcia
    // Jeden prvok v poli má typ char*
    qsort(pole,counter,sizeof(char*),compare);
    // Výpis výsledku
    for (int i =0; i < counter; i++){
        printf("%s",pole[i]);
    }
    // Uvoľnenie pamäte
    for (int i =0; i < counter; i++){
        free(pole[i]);
    }
    return 0;
}
