#include <stdio.h>
#include <stdlib.h>

/**
 * Jeden prvok binárneho stromu
 */
 
struct node {
    int value;
    struct node* left;
    struct node* right;
};

/**
 * Rekurzívne pridanie do binárneho stromu.
 * 
 * Strom nepovoľuje opakovanie prvku (je množina).
 */
struct node* add(struct node* root,int value){
   // Ak je strom prázdny, vytvorím nový prvok
   if (root == NULL){
       struct node* newn = calloc(1,sizeof(struct node));
       newn->value = value;
       newn->left = NULL;
       newn->right = NULL;
       return newn;
   }
   // Ak je hodnota menšia, pridám naľavo
   if (value < root->value){
       // Prvok vľavo je koreňom ďalšieho  stromu
       root->left = add(root->left,value);
   }
   // Ak je hodnota väčšia, pridám vpravo
   else if (value > root->value) {
       // Prvok vpravo je koreňom ďalšieho  stromu
       root->right = add(root->right,value);
   }
   // Ak je hodnota rovnaká, neurobím nič
   return root;
}

void destroy(struct node* root){
    if (root == NULL){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    free(root);
}

void print(struct node* root){
    if (root == NULL){
        return;
    }
    print(root->left);
    printf("%d ",root->value);
    print(root->right);
}


int main() {
    struct node* root = NULL;
    root = add(root,2);
    root = add(root,3);
    root = add(root,6);
    root = add(root,6);
    root = add(root,3);
    root = add(root,3);
    root = add(root,11);
    root = add(root,1);
    print(root);
    printf("\n");
    destroy(root);
  
}
