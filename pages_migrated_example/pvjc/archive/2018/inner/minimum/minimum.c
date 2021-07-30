#include <stdio.h>

float mocnina(float);

int main() {
    printf("Mocninová kalkulačka\n");
    float vysledok = 0;
    printf("Výsledok je zatiaľ %f\n",vysledok);
    char vstup[10];
    printf("Zadaj hodnotu na max. 10 miest:");
    fgets(vstup,10,stdin);
    printf("Zadali ste %s\n",vstup);
    float parameter = 0;
    sscanf(vstup,"%f",&parameter);
    printf("Hodnota parametra je %f\n",parameter);
    vysledok = mocnina(parameter);
    printf("Výsledok je %f\n",vysledok);
    return 0;
}

float mocnina(float arg){
    float parameter = arg * arg;
    return parameter;
}
