// LZ78
// Example on LZ78 Compression
// Daniel Hladek at TUKE (c) 2019
// v.1.1
// Thanks to https://medium.com/@dbudhrani/how-data-compression-works-exploring-lz78-e97e539138
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

// One codeword is previous index - new index -character

// Trie (a.k.a prefix tree)
struct dict {
        int index;
        // Character is encoded as non zero value in characters
        struct dict* characters[SIZE];
};

// Free trie
void delete(struct dict* tree){
   if (tree == NULL){
           return;
   }
   for (int i = 0 ;i < SIZE; i++){
           delete(tree-> characters[i]);
   }
   free(tree);
}

void print(struct dict* tree,char* prefix,int level){
   if (tree == NULL){
       return;
   }
   printf("%d %s\n",tree->index,prefix);
   for (int i = 0 ;i < SIZE; i++){
       if (tree-> characters[i] > 0){
            prefix[level] = i;
            print(tree-> characters[i],prefix,level +1 );
       }
   }
}

// https://medium.com/@dbudhrani/how-data-compression-works-exploring-lz78-e97e539138
int main(){
    // The trie represents the current phrase
    // The first node represents the empty string with index 0
    struct dict* root = calloc(1,sizeof(struct dict));
    struct dict* current = root;
    int lettercounter = 0;
    int wordcounter = 0;
    int index = 1;
    while (1){
        int c = getchar();
        if (c == EOF){
            break;
        }
        lettercounter += 1;
        // Current character is in dictionary, continue searching
        if (current->characters[c] > 0){
            current = current->characters[c];
        }
        else {
            // Current character is not in the dictionary
            // Create codeword node
            // The parent represents the previous string
            // the new node represents the new character.
            current->characters[c] = calloc(1,sizeof(struct dict));
            current->characters[c]->index = index;
            // Condeword is encoded as:
            // parent index, current index, character
            printf("%d-%d-%c\n",current->index,index,c);
            index += 1;
            wordcounter += 1;
            // Continue searching for the next word
            current = root;
        }
    }
    char buffer[SIZE];
    memset(buffer,0,SIZE);
    printf("Dictionary>>>");
    print(root,buffer,0);
    printf("%d letters encoded into %d words and %d dictinary items\n",lettercounter,wordcounter,index);
    delete(root);
}

