#include <stdio.h>
#include <string.h>

#define CHARSIZE 256

int is_unique(const char* str){
    int counter[CHARSIZE];
    // Tabula pocetnosti ASCII kodov
    memset(counter,0,sizeof(int) * CHARSIZE);
    for(int i = 0; str[i] != 0; i++){
        unsigned char code = str[i];
        // Pocitame kolko krat sa kod vyskytuje v retazci
        counter[code] += 1;
        // Ak sa kod vyskytuje viac ako jeden krat
        // retazec nie je unikatny
        if (counter[code] > 1)
            return 0;
    }
    return 1;
}

void translate(char* str,unsigned char* table){
    for (int i = 0; str[i] != 0; i++){
        unsigned char code = str[i];
        char r = table[code];
        str[i] = r;
    }
}

void read_table(const char* set1,const char* set2,unsigned char* table){
    for (unsigned int i = 0; i < CHARSIZE; i++){
        table[i] = i;
    }
    for (int i = 0; set1[i] != 0; i++){
        unsigned char code = set1[i];
        table[code] = set2[i];
    }
}


int main(int argc, char** argv){
    if (argc != 3){
        printf("Usage: tr SET1 SET2");
        return 1;
    }
    char* set1 = argv[1];
    char* set2 = argv[2];
    if (!is_unique(set1)){
        printf("Letters in SET1 must be unique");
        return 1;
    }
    if (strlen(set1) != strlen(set2)){
        printf("SET1 and SET2 should have same size");
        return 1;
    }
    unsigned char table[CHARSIZE];
    read_table(set1,set2,table);

    char buffer[1024];
    while (fgets( buffer, 1024, stdin) != NULL){
        translate(buffer,table);
        printf("%s",buffer);
    }
    return 0;
}
