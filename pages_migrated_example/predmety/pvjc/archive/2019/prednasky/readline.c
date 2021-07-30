// Načítanie súboru po znakoch do dynamicky alokovaného poľa
//
// Program číta znaky zo štandardného vstupu a ukladá ich do poľa.
// V prípade, že natrafí na koniec riadku, vypíše obsah poľa
//
// V prípade, že je pole príliš malé, zväčší sa jeho veľkosť.
//
// Program je schoný načítať ľubovoľne dlhý riadok.
// Veľkosť riadka je obmezená iba veľkosťou operačnej pamäte.
//
// Príklad na výukové účely
//
// (c) 2018 Daniel Hládek a Technická univerzita v Košiciach
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Momentalna velkost riadka
    int line_size = 5;
    // Pamet pociatocneho riadka
    char* line = malloc(line_size);
    // Inicializacia nacitavaneho znaku
    // Pre nacitany znak zvolime premennu int, 
    // pretoze funkcia getc moze vratit hodnotu EOF, co je -1
    // https://stackoverflow.com/questions/18540179/getc-return-value-stored-in-a-char-variable
    int c = EOF;
    // Index kde sa nacitava
    int i = 0;
    // Nacitanie znaku do premennej c. Ak je nacitana hodnota EOF, nacitanie konci.
    while ((c = getc(stdin)) != EOF){
        // Overenie si, ci je dynamicke pole dost velke.
        if (i  + 1 >= line_size){
            // Zvacsime pole
            line_size = line_size * 2;
            char* nline = realloc(line,line_size);
            // Overime si, ci nam bola pridelena nova pamat
            if (nline == NULL){
                // Ak nebola, uvolnime povodnu pamat a skoncime
                free(line);
                return -1;
            }
            else {
                // Inak nastavime smernik na novu pamat.
                line = nline;
            }
        }
        // Sme si isti ze nezapisujeme mimo.
        line[i] = c;
        // Posunieme index zapisu
        i += 1;
        // V pripade, ze sme nasli koniec riadka, vypiseme ho.
        if (c == '\n'){
            // Zabezpecime, ze obsah pola je retazec
            // zakonceny nulou
            line[i] = 0;
            printf("%s",line);
            i = 0;
        }
    }
    // Ak sme nasli koniec suboru, ale su este nejake nezobrazene znaky,
    // Tato situacia nastane, ak posledny riadok suboru nie je zakonceny \n
    if (i > 0){
        line[i] = 0;
        printf("%s",line);
    }
    // Uvolnenie pamate.
    free(line);
    return 0;
}
