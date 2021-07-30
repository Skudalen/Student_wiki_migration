#include <stdio.h>
#include <string.h>

int main(){
    int head  = -1;
    int length = 0;
    while(1){
        int c = getchar();
        if (c == EOF){
            printf("%c",head);
            printf("%c",length);
            break;
        }
        if (c == head){
            length += 1;
        }
        else {
            printf("%c",head);
            printf("%c",length);
            head = c;
            length = 1;
        }
    }
    return 0;
}

