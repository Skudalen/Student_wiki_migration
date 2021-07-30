// Načítanie zoznamu slov do dvojrozmeného poľa
//
// Program je obmedzený na naximálny počet slov a na maximálnu veľkosť slova
// vždy bude potrebovať rovnaké množstvo pamäte

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDCOUNT 1000
#define WORDSIZE 100

int main(){
    // Uloženie slov
    char words[WORDCOUNT][WORDSIZE];

    // Počet slov
    int word_counter = 0 ;

    // Načítanie po riadkoch do dvojrozmerného poľa
    // Načítava sa vrátane medzery
    while (fgets(words[word_counter],WORDSIZE,stdin)){
        word_counter++;
    }

    // Bubblesort
    // POmocná premenná pre výmenu slov
    char buffer[WORDSIZE];
    for (int j = 0; j < word_counter; j++){
        for (int i = 1; i < word_counter - j; i++){
            int cmp = strcmp(words[i-1],words[i]);
            if (cmp > 0){
                // Vymena dvoch retazcov cez pomocnu premennu
                // Muysime urobit operaciu kopirovania
                strcpy(buffer,words[i-1]);
                strcpy(words[i-1],words[i]);
                strcpy(words[i],buffer);
            }
        }
    }

    // Výpis zoznamu slov
    for (int j = 0; j < word_counter; j++){
        printf("%s\n",words[j]);
    }

    return 0;

}
