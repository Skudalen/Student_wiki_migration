#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* p1,const void* p2){
    char* s1 = *((char**)p1);
    char* s2 = *((char**)p2);
    return strcmp(s1,s2);
   
}

int main() {
    char* pole[100];
    char buffer[100];
    int counter = 0;
    for (int i =0; i < 100; i++){
        char* r = fgets(buffer,100,stdin);
        if (r == NULL){
            break;
        }
        int l = strlen(buffer);
        if (l == 0){
            break;
        }
        pole[i] = malloc(l + 1);
        memcpy(pole[i],buffer,l+1);
        counter += 1;
    }
    qsort(pole,counter,sizeof(char*),compare);
    for (int i =0; i < counter; i++){
        printf(pole[i]);
        free(pole[i]);
    }
    
     

    return 0;
}
