#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// https://gist.github.com/tonious/1377768
// https://www.cpp.edu/~ftang/courses/CS241/notes/self%20balance%20bst.htm
// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
// https://codereview.stackexchange.com/questions/71854/avl-tree-implementation-in-c
// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
// http://www.algolist.net/Data_structures/Binary_search_tree/Removal
struct node {
    struct node* left;
    struct node* right;
    int height;
    int value;
};

struct tree {
    struct node* root;
    size_t size;
};

struct tree* init_tree(){
    return calloc(1,sizeof(struct tree));
}

struct node* create_node(int value){
    struct node* node = malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->height = 0;
    return node;
}

void destroy_node(struct node* node){
    if(node != NULL){
        destroy_node(node->left);
        destroy_node(node->right);
        free(node);
    }
}

void destroy_tree(struct tree* tree){
    destroy_node(tree->root);
    free(tree);
}

int height(struct node* node){
    int l = 0;
    if (node == NULL){
        return 0;
    }
    if (node->left){
        l = node->left->height;
    }
    int r = 0;
    if (node->right){
        r = node->right->height;
    }
    if (l > r){
        return l + 1;
    }
    return r + 1;
}

int balance_factor(struct node* node){
    if (node == NULL){
        return 0;
    }
    return height(node->right) - height(node->left);
}

//
//      ROOT          PIVOT
//      /   \   =>   /    \
//   PIVOT   C      A     ROOT
//   /   \                /   \
//  A     B              B     C
//
//
struct node* rotate_right(struct node* parent){
    struct node* pivot = parent->left;
    assert(pivot != NULL);
    //    printf("R %d\n",pivot->value);
    parent->left = pivot->right;
    pivot->right = parent;
    parent->height = height(parent);
    pivot->height = height(pivot);
    return pivot;
}

//
//   ROOT             PIVOT
//   /   \       =>   /   \
//  A    PIVOT      ROOT   C
//       /   \      /   \
//     B      C    A     B
//
//
struct node* rotate_left(struct node* parent){
    struct node* pivot = parent->right;
    assert(pivot != NULL);
//    printf("L %d\n",pivot->value);
    parent->right = pivot->left;
    pivot->left = parent;
    parent->height = height(parent);
    pivot->height = height(pivot);
    return pivot;
}

struct node* balance_tree_node(struct node* node){
    assert(node);
    node->height = height(node);
    // Left heavy
    if (balance_factor(node) < -1){
        if (balance_factor(node->left) > 1) {
            node->left  = rotate_left(node->left);
        }
        node = rotate_right(node);
    }
    // Right Heavy
    else if (balance_factor(node) > 1){
        if (balance_factor(node->right) < -1){
            node->right = rotate_right(node->right);
        }
        node = rotate_left(node);
    }
    return node;
}

struct node* search(struct tree* tree, int value){
    struct node* current = tree->root;
    while( current != NULL ){
        if (value < current->value ){
            current = current->left;
        }
        else if (value > current->value){
            current = current->right;
        }
        else {
            break;
        }
    }
    return current;
}

struct node* insert(struct node* node, int value){
    if (node == NULL){
        return create_node(value);
    }
    if (value < node->value){
        node->left = insert(node->left,value);
    }
    else if (value > node->value){
        node->right = insert(node->right,value);
    }
    node = balance_tree_node(node);
    return node;
}

struct node* minimum(struct node* node){
    assert(node);
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

struct node* delete(struct node* node,int value){
    if (node == NULL){
        return NULL;
    }
    struct node* res = node;
    if (node->value == value){
        if (node->left && node->right){
            struct node* min = minimum(node->right);
            node->value = min->value;
            node->right = delete(node->right,min->value);
        }
        else if (node->left && node->right == NULL){
            res = node->left;
            free(node);
        }
        else if (node->right && node->left == NULL){
            res = node->right;
            free(node);
        }
    }
    else if (node->value < value){
        node->left = delete(node->left,value);
    }
    else {
        node->right = delete(node->right,value);
    }
    return res;
}

void print_dot_node(struct node* node){
    if (node == NULL){
        return;
    }
    print_dot_node(node->left);
    printf("%d [label=\"%d %d\"];\n",node->value,node->value, node->height);
    if (node->left){
        printf("%d -> %d;\n",node->value,node->left->value);
    }
    if (node->right){
        printf("%d -> %d;\n",node->value,node->right->value);
    }
    print_dot_node(node->right);
}


void print_dot(struct node* node){
    printf("digraph G {\n");
    print_dot_node(node);
    printf("}\n");
}


int main(){
   time_t t;
   srand((unsigned) time(&t));
   struct node* tree = NULL;
   for (int i = 0; i < 100; i++){
    tree = insert(tree,rand() % 150);
   }
    print_dot(tree);
    return 0;
}
