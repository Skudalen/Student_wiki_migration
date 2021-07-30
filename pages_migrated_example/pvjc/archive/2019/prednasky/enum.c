#include <stdio.h>
// Priklad na enumerator
// (c) 2018 Daniel Hladek a Technicka Univerzita v Kosiciach
//
// Na ucely vyuky
//
enum day {
    PONDELOK,
    UTOROK,
    STREDA,
    STVRTOK,
    PIATOK,
    SOBOTA,
    NEDELA
};

void napis_den(enum day d){
    switch(d){
        case PONDELOK:
            printf("Dnes je pondelok\n;");
            break;
        case  UTOROK:
            printf("Dnes je utorok\n;");
            break;
        case  STREDA:
            printf("Dnes je streda\n;");
            break;
        case  STVRTOK:
            printf("Dnes je stvrtok\n;");
            break;
        case  PIATOK:
            printf("Konecne!\n;");
            break;
        case  SOBOTA:
            printf("Dnes je sobota\n;");
            break;
        case NEDELA:
            printf("Dnes je nedela\n;");
            break;
    }
}
int main(){

    enum day dnes = STVRTOK;
    napis_den(dnes);
    return 0;

}
