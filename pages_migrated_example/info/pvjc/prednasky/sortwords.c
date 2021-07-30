// Načítanie do dynamicky alokovaného poľa smerníkov
// Spotreba pamäte je  priamo úmerná počtu načítaných znakov
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program je obmedzený konštantami.
// Je možné program prerobiť tak, aby bol schopný načítať 
// ľubovoľne veľký riadok a ľubovoľný počet slov.
#define WORDCOUNT 1000
#define WORDSIZE 100

int main(){

    // Pole smerníkov
    char** words = malloc(WORDCOUNT * sizeof(char*));
    
    int word_counter = 0 ;

    // Pomocná premenná na načítanie riadka
    char* line = malloc(WORDSIZE * sizeof(char));

    // Načítanie riadkov
    while(fgets(line,WORDSIZE,stdin)){
        // Veľkosť riadka (polus 1 je na koniec)
        size_t line_size = strlen(line) + 1;
        // Alokácia novej pamäte na uloženie riadka
        char* string_in_mem = malloc(line_size);
        // Kopírovanie do novej pamäte
        memcpy(string_in_mem,line,line_size);
        // Uloženie adresy novej pamäte do poľa smerníkov
        words[word_counter] = string_in_mem;
        // Zýšenie počítadla
        word_counter++;
    }
    free(line);


    // Bublikové triedenie slov
    for (int j = 0; j < word_counter; j++){
        for (int i = 1; i < word_counter - j; i++){
            // Lexikografické porovnanie dvoch slov
            int cmp = strcmp(words[i-1],words[i]);
            if (cmp > 0){
                // Pri výmene dvoch pamäťových miest kopírujeme iba adresu
                char* s = words[i-1];
                words[i-1] = words[i];
                words[i]  = s;
            }
        }
    }
    // Výpis slov na obrazovku a uvoľnenie pamäte pre každý reťazec
    for (int j = 0; j < word_counter; j++){
        printf("%s",words[j]);
        free(words[j]);
    }
    // Uvoľnenie pamäte pre pole smerníkov
    free(words);

    return 0;

}
