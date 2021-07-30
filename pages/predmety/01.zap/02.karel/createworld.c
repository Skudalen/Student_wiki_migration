/**
 * Program pre generovanie Karlovho sveta
 * Daniel Hladek, (c) 2016 Technicka Univerzita Kosice
 *
 * preklad: gcc createword.c -o createworld
 * spustenie: ./createworld > myworld.kw
 *
 * Podla potreby si mozete upravit rozmer sveta a podmienku pre polozenie zetonov a stien
 *
 */
#include <stdio.h>

int main(){
    int sizex  = 10;
    int sizey = 10;
    // Vypis prveho riadku karlovho sveta
    // format: rozmer_x rozmer_y karol_x karol_y karol_smer počet_žetónov_v_batohu
    printf("%d %d 1 1 E 99\n",sizex,sizey);
    // Prechadzam kazdy stvorec Karlovho sveta
    // i,j su suradnice
    // Suradnice idu od 1 po size
    for (int i = 1; i <= sizex; i += 1 ){
        for (int j = 1; j <= sizey; j++){
            // Na kazdy stvorec s parnou suranicou i a zarove s parnou suradnocou y
            // Podla potreby upravte podmienku
            if (i % 2 == 0 && j % 2 == 0){
                // Polozim zeton
                printf("B %d %d 1\n",i,j);
                // Ohradim zo severu a vychodu
                printf("W %d %d N\n",i,j);
                printf("W %d %d E\n",i,j);
            }

        }
    }

    return 0;
}
