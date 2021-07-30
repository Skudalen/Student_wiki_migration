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
        // Load data into array
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
                // Search buffer is before head
                // Search buffer size
                int bsz = BSIZE;
                if (head < bsz){
                    bsz = head;
                }
                // Search buffer start
                // Search buffer contains data from the past
                char* buffer = data + head -bsz;
                // Lookahead buffer start
                // Lookahead buffer contains data in the future
                char* window = data + head;
                // Lookahead buffer size
                int wsz = BSIZE;
                if ((dsz - head) < wsz){
                     wsz = BSIZE - head;
                }
                // We search in search buffer
                // for the longest string in lookahead that starts with head
                // search and lookahead buffers can have different sizes
                // Max largest match size is the minimum
                int msz = wsz;
                if (bsz < wsz){
                        msz = bsz;
                }
                // Offset of the match in the past 
                int offset = -1;
                // Size of the match in the past
                int size = -1;
                for (int i = 1; i < msz; i++){
                    // Searches window,i in buffer,bsz
                    char* r = memmem(buffer,bsz,window,i);
                    if (r > 0){
                        offset = bsz - (r - buffer);
                        size = i + 1 ;
                    }
                    else {
                        break;
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

