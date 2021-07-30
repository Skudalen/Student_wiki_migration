// Príklad na AVL strom
// (c) 2020 Daniel Hládek, Technická Univerzita v Košiciach
// Pre potreby predmetu Údajové štruktúry a algoritmy
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Použité materiály:
//
// https://gist.github.com/tonious/1377768
// https://www.cpp.edu/~ftang/courses/CS241/notes/self%20balance%20bst.htm
// https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
// https://codereview.stackexchange.com/questions/71854/avl-tree-implementation-in-c
// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
// http://www.algolist.net/Data_structures/Binary_search_tree/Removal


// Typ pre jeden uzol stromu
// V strome si ukladáme celé čísla
struct node {
    struct node* left;
    struct node* right;
    int value;
};

// Vytvorenie prázdneho uzla
struct node* create_node(int value){
    struct node* node = malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    return node;
}


// Postorder rekurzívne zrušenie stromu
void destroy_node(struct node* node){
    if(node != NULL){
        destroy_node(node->left);
        destroy_node(node->right);
        free(node);
    }
}

// Výška stromu, rekurzívne určenie
int height(struct node* node){
    // Triviálny prípad, 
    // Prázdny strom má výšku nula
    if (node == NULL){
        return 0;
    }
    // Inak je výška maximum z výšky potomkov plus jedna
    int l = 0;
    if (node->left){
        l = 1 + height(node->left);
    }
    int r = 0;
    if (node->right){
        r =  1 + height(node->right);
    }
    if (r > l){
        return r ;
    }
    return l;
}

// Ak je bf kladné, strom je naklonený doľava
// Ak je záporné, strom je naklonený doprava
int balance_factor(struct node* node){
    if (node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Rotácia doprava
// z bf 1 sa stane bf -1
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
    return pivot;
}

// Rotácia doľava
// z bf -1 sa stane bf 1
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
    parent->right = pivot->left;
    pivot->left = parent;
    return pivot;
}

struct node* balance_tree_node(struct node* p){
    assert(p);
    // Vyvazovanie podla 
    // https://codereview.stackexchange.com/questions/71854/avl-tree-implementation-in-c
    int bf = balance_factor(p);
    // Left heavy
    if (bf > 1 )
    {
        // Aby korekcia bf nebola príliš veľká
        int lbf = balance_factor(p->left);
        if ( lbf < 0 )
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }
    // Right Heavy
    else if ( bf  < -1 )
    {
        // Aby korekcia bf nebola príliš veľká
        int rbf = balance_factor(p->right);
        if ( rbf > 0  )
            p->right = rotate_right(p->right);
        return rotate_left(p);
    }
    return p;
}

struct node* search(struct node* current, int value){
    // sekvenčné prechádzanie postorder
    while( current != NULL ){
        // Najprv do ľava
        if (value < current->value ){
            current = current->left;
        }
        // Potom do prava
        else if (value > current->value){
            current = current->right;
        }
        // Inak sme našli prvok
        else {
            break;
        }
    }
    return current;
}

// Rekurzívne vkladanie preorder
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
    // Korekcia vyváženia
    node = balance_tree_node(node);
    return node;
}

// Vyhľadanie minimálneho prvku
struct node* minimum(struct node* node){
    assert(node);
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

// Rekurzívne vymazanie ľubovoľného prvku
struct node* delete(struct node* node,int value){
    if (node == NULL){
        return NULL;
    }
    struct node* res = node;
    // Ak sme našli prvok
    if (node->value == value){
        // Ak má oboch potomkov
        if (node->left && node->right){
            // Nájdeme ďalší prvok 
            struct node* min = minimum(node->right);
            // Nahradíme ho za aktálny provk ktorý sa má vymazať
            // teda ho prepíšeme 
            node->value = min->value;
            // Vymažeme ďalší prvok, aby nebol dva krát
            node->right = delete(node->right,min->value);
        }
        else if (node->left && node->right == NULL){
            // Nový vrchol je ľavý syn
            res = node->left;
            free(node);
        }
        else if (node->right && node->left == NULL){
            // Nový vrchol je pravý syn
            res = node->right;
            free(node);
        }
    }
    // Ak sme nenašli, pozrieme sa najprv naľavo
    else if (node->value < value){
        node->left = delete(node->left,value);
    }
    // Potom sa pozrieme napravo
    else {
        node->right = delete(node->right,value);
    }
    return res;
}

// Výpis stromu vo formáte Graphviz bez hlavičky
void print_dot_node(struct node* node){
    if (node == NULL){
        return;
    }
    print_dot_node(node->left);
    printf("%d [label=\"%d %d\"];\n",node->value,node->value, height(node));
    if (node->left){
        printf("%d -> %d;\n",node->value,node->left->value);
    }
    if (node->right){
        printf("%d -> %d;\n",node->value,node->right->value);
    }
    print_dot_node(node->right);
}

// Test, či je strom naozaj AVL
// musí spĺňať vlastnosť AVL
void check_avl(struct node* node){
    if (node == NULL){
        return;
    }
    // Balance faktor musí byť v intervale -1 až 1
    int bf = balance_factor(node);
    assert(bf >= -1 && bf <= 1 );
    check_avl(node->left);
    check_avl(node->right);
}


// Výpis stromu vo formáte Graphviz
// obrázok stromu vytvoríte:
// program | dot -T png -o obrazok.png
void print_dot(struct node* node){
    printf("digraph G {\n");
    print_dot_node(node);
    printf("}\n");
}


int main(){
   time_t t;
   srand((unsigned) time(&t));
   for (int j = 0; j < 100; j++){
       struct node* tree = NULL;
       for (int i = 0; i < 100; i++){
          tree = insert(tree,rand() % 200);
       }
       check_avl(tree);
       destroy_node(tree);
   }
   return 0;
}
