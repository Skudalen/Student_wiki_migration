/**
 * Rekurzívna implementácia binárneho vyhľadávacieho stromu.
 *
 *
 * Výsledný strom môže byť nevyvážený (na jednej strane môže byť oveľa viac uzlov ako na druhej), čo
 * zvyšuje zložitosť vyhľadávania.
 *
 * Implementácia môže trpieť na "stack overflow", pri veľkom množstve uzlov.
 *
 * v 1.0 
 * (c) 2018 Daniel Hládek a Technická univerzita v Košiciach 
 *
 * Na výukové účely
 *
 */

// na fukcie calloc a free
#include <stdlib.h>
// na makro assert
#include <assert.h>
// na printf
#include <stdio.h>

/**
 * Jeden uzol binárneho vyhľadávacieho stromu
 */
struct bst {
    // Strom, ktorého hodnoty sú menšie ako aktuálna hodnota
    struct bst* left;
    // Strom, ktorého hodnoty sú väčšie ako aktuálna hodnota
    struct bst* right;
    // Aktuálna hodnota
    int value;
};

/**
 * Vyhľadanie uzla so zadanou hodnotu.
 *
 * @arg root koreň stromu kde sa má vyhľadávať
 * @arg hodnota, na vyhľadanie
 * @return adresa uzla s hodnotou alebo NULL, ak sa hodnota v strome nenachádza,
 */
struct bst* search(struct bst* root,int value){
    // Hľadáme stratégiou postorder 
    // Ak sme natrafili na NULL, nemusíme hľadať ďalej
    if (root == NULL){
        return NULL;
    }
    // Ak je hľadaná hodnota menšia ako aktuálna, hľadáme naľavo
    else if (root->value > value){
        return search(root->left,value);
    }
    // Ak je hľadané hodnota väčšia ako aktuálna, hľadáme napravo
    else if (root->value < value){
        return search(root->right,value);
    }
    // Inak je hľadané hodnota rovná aktuálnej a našli sme ju.
    return root;
}

/**
 * Vytvorenie a inicializácia nového uzla.
 * Pravý a ľavý podstrom sú nastavené na NULL.
 *
 * @arg Hodnota, ktorá sa má do uzla uložiť.
 * @return Adresa nového uzla
 */
struct bst* create_node(int value){
    // Funkcia calloc nastaví všetku pamäť na nulu, a teda aj ľavý a pravý podstrom na NULL. 
    struct bst* newnode = calloc(1,sizeof(struct bst));
    newnode->value = value;
    return newnode;
}

/**
 * Pridanie nového uzla do stromu. V prípade, že sa hodnota
 * už v strome nachádza, neurobí nič.
 *
 * @arg strom, kde sa má nový uzol pridať. Môže byť aj NULL, ak je strom prázdny
 * @arg hodnota ktorá sa má uložiť.
 * @return adresa koreňového uzla stromu.
 */
struct bst* add(struct bst* root,int value){
    // Ak je strom prázdny, nový uzol bude jeho koreň
    if (root == NULL){
       root = create_node(value);
    }
    // Miesto na pridanie hľadáme stratégiou postorder
    //
    // Ak je pridávaná hodnota menšia, vkladáme do ľavého podstromu
    else if (root->value > value){
        // Ak sú uzly na ľavej strane, pridávame tam,
        if (root->left != NULL){
            add(root->left,value);
        }
        else{
            // Ak je ľavý podstrom nulový, vytvoríme tam nový uzol s hodnotou.
            root->left = create_node(value);
        }
    }
    // Ak je pridávaná hodnota väčšia, vkladáme do pravého podstromu
    else if (root->value < value){
        // Ak existuje podstrom na pravej strane, pridávame tam.
        if (root->right != NULL){
            add(root->right,value);
        }
        // Ak je na pravej strane NULL, dáme tam nový uzol.
        else{
            root->right = create_node(value);
        }
    }
    // Inak sme našli pridávanú hodnotu (Zistili sme, že hodnota už v strome existuje).
    // Nie je potrebné modifikovať strom.
    return root;
}

/**
 * Vymazanie celého stromu
 * @arg strom kde vymažeme všetky uzly
 */
void delete(struct bst* root){
    // Postorder
    if (root == NULL)
        return;
    if (root->left != NULL){
        delete(root->left);
    }
    if (root->right!= NULL){
        delete(root->right);
    }
    free(root);
}

/**
 * Výpis hodnôť v strome pomocou stratégie inorder.
 *
 * Uzly sa vypíšu vo vzostupnom poradí.
 */
void print_inorder(struct bst* root){
    if (root == NULL){
        return;
    }
    print_inorder(root->left);
    printf("%d ",root->value);
    print_inorder(root->right);
}

/**
 * Výpis hodnôť v strome pomocou stratégie preorder
 * 
 * Poradie výpisu závisí od tvaru stromu. Ako prvá sa vypíše hodnota na koreni stromu.
 */
void print_preorder(struct bst* root){
    if (root == NULL){
        return;
    }
    printf("%d ",root->value);
    print_inorder(root->left);
    print_inorder(root->right);
}

/**
 * Výpis hodnôť v strome pomocou stratégie postorder
 * 
 * Poradie výpisu závisí od tvaru stromu. Ako posledná sa vypíše hodnota na koreni stromu.
 */
void print_postorder(struct bst* root){
    if (root == NULL){
        return;
    }
    print_inorder(root->left);
    print_inorder(root->right);
    printf("%d ",root->value);
}

/**
 * Funkcia na spustenie testov implementácie.
 *
 * Algoritmus vloí hodnoty z poľa do stromu a potom ich vyhľadá.
 *
 * Aplikujeme rôzne stratégie pre výpis prvkov.
 *
 * Demonštrujeme, že vo vyhľadávacom strome sa každá hodnota nachádza maximálne raz 
 * a hodnoty sú v pamäti vždy zoradené  (pri prechádzaní inorder).
 *
 */
int main(){
    struct bst* tree = NULL;

    int values[12] = {3,4,4,2,2,1,9,8,3,9,11,0};

    for (int i = 0; i < 12;i++){
        tree = add(tree,values[i]);
    }


    for (int i = 0; i < 12;i++){
        struct bst* value = search(tree,values[i]);
        if (value != NULL){
            printf("Found %d\n",value->value);
        }
        assert(value!= NULL);
    }
    print_inorder(tree);
    printf("\n");

    print_preorder(tree);
    printf("\n");

    print_postorder(tree);
    printf("\n");

    delete(tree);
}

