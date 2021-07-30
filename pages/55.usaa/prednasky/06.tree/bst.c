// Príklad na nevyvážený binárny vyhľadávací strom
//
#include <stdio.h>
#include <stdlib.h>

struct bst {
    int value;
    struct bst* left;
    struct bst* right;
};

struct bst* create(int value){
    struct bst* res = calloc(1,sizeof(struct bst));
    res->value = value;
    return res;
}

struct bst* add(struct bst* root, int value){
    if (root == NULL){
        return create(value);
    }
    int r = root->value - value;
    if (r == 0){
        // Prvok uz je pritomny, strom sa nemeni.
    }
    else if (r < 0){
        root->left = add(root->left,value);
    }
    else {
        root->right = add(root->right,value);
    }

    return root;
}


// Na ulozenie
void print_postorder(struct bst* root){
    if (root != NULL){
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d ",root->value);
    }
    else {
        printf("NULL ");
    }
}


// Zoradeny
void print_inorder(struct bst* root){
    if (root != NULL){
        print_inorder(root->left);
        printf("%d ",root->value);
        print_inorder(root->right);
    }
}
void delete(struct bst* root){
    if (root != NULL){
        delete(root->left);
        delete(root->right);
        free(root);
    }
}

int main(){
    struct bst* root = NULL;
    root = add(root,20);
    root = add(root,40);
    root = add(root,10);
    root = add(root,2);
    root = add(root,200);
    root = add(root,20);
    print_postorder(root);
    printf("\n");
    delete(root);
    return 0;
}
