#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

struct dict {
        int data;
        struct dict* children[SIZE];

};


void delete(struct dict* tree){
   if (tree == NULL){
           return;
   }
   for (int i = 0 ;i < SIZE; i++){
           delete(tree->children[i]);
   }
   free(tree);
}

void print(struct dict* tree,char* prefix,int level){
        if (tree == NULL){
                return;
        }
   printf("%d %s\n",tree->data,prefix);
   for (int i = 0 ;i < SIZE; i++){
           if (tree->children[i] > 0){
                prefix[level] = i;
                print(tree->children[i],prefix,level +1 );
           }
   }
}

// https://towardsdatascience.com/how-data-compression-works-exploring-lz78-87f44b487d92
int main(){
        struct dict* root = calloc(1,sizeof(struct dict));
        struct dict* current = root;
        int lettercounter = 0;
        int wordcounter = 0;
        int index = 0;
        while ( 1){
                int c = getchar();
                if (c == EOF){
                        break;
                }
                lettercounter += 1;
                if (current->children[c] > 0){
                        current = current->children[c];
                }
                else {
                        current->children[c] = calloc(1,sizeof(struct dict));
                        index += 1;
                        printf("%d%c\n",current->data,c);
                        wordcounter += 1;
                        current->children[c]->data = index;
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

