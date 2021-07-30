#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SYMBOLS 255

struct node {
    struct node* left;
    struct node* right;
    int weight;
    int symbol;
};

int parent(int i){
    return (i -1) / 2;
}

int left_child(int i){
    return (2*i) + 1;
}

int right_child(int i){
    return (2*i) + 2;
}

void heapify2(struct node** array,int size,int i){
    int largest = i;
    int l = left_child(i);
    int r = right_child(i);
    if (l < size && array[largest]->weight > array[l]->weight){
        largest = l;
    }
    if (r < size && array[largest]->weight > array[r]->weight){
        largest = r;
    }
    if (largest != i){
        struct node* v  = array[i];
        array[i] = array[largest];
        array[largest] = v;
        heapify2(array,size, largest);
    }
}

void heapify_array(struct node** array, int size){
    for (int i = size / 2; i >= 0; i-- ){
        heapify2(array,size,i);
    }
}

void remove_min(struct node** array,int size){
    array[0] = array[size-1];
    heapify2(array,size-1,0);
}

void add(struct node** array,int size){
    int i = size - 1;
    int p = parent(i);
    while(p >= 0 && array[p]->weight > array[i]->weight){
        struct node* v = array[p];
        array[p] = array[i];
        array[i] = v;
        i = p;
        p = parent(p);
    }
}

void print_huffman_codes(struct node* node,int depth,char* code){
    if (node == NULL) {
        return;
    }
    if (node->symbol != 0){
        code[depth] = 0;
        printf("%c\t%s\t%d\t%d\n",node->symbol,code,node->weight,depth);
    }
    else{
        code[depth] = '0';
        print_huffman_codes(node->left,depth+1,code);
        code[depth] = '1';
        print_huffman_codes(node->right,depth+1,code);
    }
}

void free_tree(struct node* root){
    if (root != NULL){
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(int argc, char** argv){
    int c = 0;
    int counter[SYMBOLS];
    memset(counter,0,sizeof(int)*SYMBOLS);
    int tc = 0;
    FILE *infile = fopen(argv[1],"r");
    int chc = 0;
    while ((c = getc(infile)) != EOF){
        assert(c != 1);
        assert(c != 0);
        if (counter[c] == 0){
            chc += 1;
        }
        counter[c] += 1;
        tc += 1;
    }
    fclose(infile);

    printf("%d\n",chc);
    printf("%d\n",tc);
    if (chc == 0){
        return 0;
    }
    struct node** nodes = calloc(chc,sizeof(struct node*));
    int size = 0;
    for (int i = 0; i< SYMBOLS; i++){
        if (counter[i] > 0){
            printf("%c %d\n",i,counter[i]);
            nodes[size] = calloc(1,sizeof(struct node));
            nodes[size]->weight = counter[i];
            nodes[size]->symbol = i;
            size += 1;
        }
    }
    printf(" >>>>>> \n");
    heapify_array(nodes,size);

    for (int i = 0; i< size ; i++){
        printf("%c %d\n",nodes[i]->symbol,nodes[i]->weight);
    }

    while(size > 1){
        struct node* parent = calloc(1,sizeof(struct node));
        parent->left = nodes[0];
        remove_min(nodes,size);
        size -= 1;
        parent->right = nodes[0];
        remove_min(nodes,size);
        size -= 1;
        printf("%d %d\n",parent->left->weight , parent->right->weight);
        parent->weight = parent->left->weight + parent->right->weight;
        if (parent->left->weight > parent->right->weight) {
            struct node* n = parent->left;
            parent->left = parent->right;
            parent->right = n;
        }
        nodes[size] = parent;
        size += 1;
        add(nodes,size);
    }

    char zzz[1000];
    memset(zzz,0,1000);
    print_huffman_codes(nodes[0],0,zzz);
    free_tree(nodes[0]);
    free(nodes);

}

