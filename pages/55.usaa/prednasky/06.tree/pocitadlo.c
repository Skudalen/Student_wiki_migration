#include <stdio.h>
#include <stdlib.h>

struct tree {
    int key;
    int value;
    struct tree* left;
    struct tree* right;
};

struct tree* add(struct tree* root,int key){
    if (root == NULL){
        struct tree* newnode = calloc(1,sizeof(struct tree));
        newnode->key = key;
        newnode->value = 1;
        return newnode;
    }
    if (root->key == key){
        root->value += 1;
    }
    else if (root->key > key){
        root->left = add(root->left,key);
    }
    else if (root->key < key){
        root->right = add(root->right,key);
    }
    return root;
}

void destroy(struct tree* root){
    if (root == NULL){
        return;
    }
    destroy(root->left);
    destroy(root->right);
    free(root);
}

void display(struct tree* root){
    if (root == NULL){
        return;
    }
    display(root->left);
    printf("%d:%d\n",root->key,root->value);
    display(root->right);
}

int main(){
    int mnozina[20] = {1,3,4,2,5,2,3,7,6,5,4,3,4,5,6,7,8,8,6,70};
    struct tree* pocitadlo = NULL;
    for (int i = 0; i<20; i++){
        pocitadlo = add(pocitadlo,mnozina[i]);
    }
    display(pocitadlo);
    destroy(pocitadlo);
    //
    //  2 => 4
    //  6 => 12
    //
    return 0;
}
