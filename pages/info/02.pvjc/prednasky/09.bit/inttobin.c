#include <stdio.h>
#include <string.h>

int main(){
    int val = 0;
    printf("Zadaj cele kladne cislo:\n");
    char nacitanie[32];
    fgets(nacitanie,32,stdin);
    int r = sscanf(nacitanie,"%d",&val);
    if (r != 1 || val < 0){
        perror("Chyba pri nacitani\n");
        return 1;
    }
    char vysledok[32];
    memset(vysledok,0,32);
    int i = 0;
    while (val > 0){
        unsigned int bit = val & (unsigned int)1;
        if (bit){
            vysledok[i] = '1';
        }
        else {
            vysledok[i] = '0';
        }
        val = val >> (unsigned int)1;
        i += 1;
    }
    for (int j = i; j >= 0; j--){
        printf("%c",vysledok[j]);
    }

    printf("\n");
}
