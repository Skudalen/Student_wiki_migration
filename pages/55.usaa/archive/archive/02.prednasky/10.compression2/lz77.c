// LZ77 Compresion Example
// Daniel Hladek (c) 2019 Technical University of Kosice
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define SIZE 1000
#define BSIZE 9


int main(){
        // Data that are encoded
        char data[SIZE];
        memset(data,0,SIZE);
        int dsz = 0;
        while (dsz < SIZE){
                int c = getchar();
                if (c == EOF){
                        break;
                }
                data[dsz++] = c;
        }
        int head = 0;
        int osz = 0;
        while (head < dsz && data[head] > 0){
                // Search buffer size
                int bsz = BSIZE;
                if (head < bsz){
                        bsz = head;
                }
                // Search buffer start
                char* buffer = data + head -bsz;
                // Lookahead buffer start
                char* window = data + head;
                // Lookahead buffer size
                int wsz = BSIZE;
                if ((dsz - head) < wsz){
                        wsz = BSIZE - head;
                }
                // Max largest match size
                int msz = wsz;
                if (bsz < wsz){
                        msz = bsz;
                }
                // Offset and largest match size of window prefix in search buffer
                int offset = -1;
                int size = -1;
                for (int i = 0; i < msz; i++){
                        char* r = memmem(buffer,bsz,window,i);
                        if (r > 0){
                                offset = bsz - (r - buffer);
                                size = i;
                        }
                }
                // Print match
                if (size > 0){
                        printf("%d",offset);
                        printf("%d",size);
                        printf("%c\n",data[head]);
                        head += size;
                }
                else {
                        printf("00%c\n",data[head]);
                        head += 1;
                }
                osz += 1;
        }
        printf("---\n");
        printf ("%d characters into %d codewords\n",dsz,osz);
        return 0;
}

