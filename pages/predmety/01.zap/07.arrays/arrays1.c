// Priklad z prednasky ZAP  c. 5
// Daniel Hladek 2019
//
#include <stdio.h>
#include <assert.h>

#define ASIZE 30



int suma(int* premenna, int size){
        assert(premenna != NULL);
        int sum = 0;
        for (int i = 0; i < size; i++){
                //assert((i+1) < ASIZE);
                sum += premenna[i];
        }
        return sum;
}


int main() {

        int premenna[ASIZE];
        //for (int i = 0; i < ASIZE; i++){
        //      premenna[i] = 0;
        //}

        int pocitadlo = 0;
        for (int i = 0; i < ASIZE; i++){
                printf("Zadaj cislo\n");
            int r = scanf("%d",&premenna[i]);
            if (r != 1){
                    break;
            }
            pocitadlo += 1;
        }
        int sum = suma(premenna,ASIZE);
        printf("%d\n",sum);
        return 0;
}

