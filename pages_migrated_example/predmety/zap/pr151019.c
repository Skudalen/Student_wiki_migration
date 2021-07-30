#include <stdio.h>


int spocitaj(int a,int b){
    int c = a + b;
    return c;
}

int main() {
    int a = 0;
    int r = scanf("%d",&a);
    if (r != 1){
        printf("problem\n");
        return 0;
    }
    int b = 0;
    r = scanf("%d",&b);
    if (r != 1){
        printf("problem 2\n");
        return 0;
    }
    int c = spocitaj(a,b);
    printf("Vysledok suctu %d %d je %d\n",a,b,c);
    return 0;
}
