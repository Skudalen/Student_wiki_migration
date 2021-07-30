// Huffmanovo kódovanie znakov
//
// Príklad z prednášky Údjové štruktúry a algoritmy
//
// Daniel Hládek (c) Technická Univerzita v Košiciach, 2019
//
// Na vstup zadáte text. Pre každý znak sa spočíta jeho 
// početnosť a určí optimálny Huffmanov kód
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

// Jedna položka v Hufmannovom strome
// Kód znaku je určený pozíciou v Huffmanovom strome
// Na začiatku je uložená v poli pre spočítanie
struct item {
	/// Znak ktorý kódujeme
        char character;
	// Početnosť
        int count;
        struct item* left;
        struct item* right;
};

// Obnovenie kopovitosti pre zadaný prvok v poli
// a všetkých jeho potomkov
void heapify(struct item* heap,int i,int hsz){
        int b = i;
        int v = heap[i].count;
        int l = i * 2 + 1;
        if (l < hsz && heap[l].count < v){
                b = l;
                v = heap[l].count;
        }
        int r = l + 1;
        if (r < hsz && heap[r].count < v){
                b = r;
        }
        if (b !=i){
                struct item val = heap[i];
                heap[i] = heap[b];
                heap[b] = val;
                heapify(heap,b,hsz);
        }
}


// Výpis kódu znaku v Huffmanovom strome
void print_prefix(struct item* root,char* pref, int psz){
        if (root == NULL){
                return;
        }
        if(root->left == NULL){
            pref[psz] = 0;
            printf("%c %s\n",root->character,pref);
        }
	// Ak je cesta naľavo tak 0
        pref[psz] = '0';
        print_prefix(root->left,pref,psz +1);
	// Cest napravo je 1
        pref[psz] = '1';
        print_prefix(root->right,pref,psz +1);
}



int main(){
	// Inicializácia počítadla
        struct item heap[SIZE];
        memset(heap,0,SIZE*sizeof(struct item));
	// Vložíme všetky možné znaky a nastavíme početnosť na nulu
        for (int i = 0; i< SIZE; i++){
                heap[i].character = i;
        }
        int hsz = SIZE;
	// Načitanie znakov a spočítanie početnosti
        while(1){
                int r = getchar();
                if (r == EOF){
                        break;
                }
                heap[r].count += 1;
        }
	// Vytvorenie minimálnej binárnej kopy
        for (int i = SIZE/2; i >= 0; i--){
            heapify(heap,i,SIZE);

        }
	// Prvok s minimálnou početnosťou je vždy prvý
	//  Odstránenie všetkých nulových prvkov
        while(heap[0].count == 0 && hsz > 0){
            heap[0] = heap[--hsz];
	    // Obnovenie kopovitosti
            heapify(heap,0,hsz);
        }
	// Vytváranie Huffmanovho stromu
        while (hsz > 1){
	    // Vyberieme ľavého syna
            struct item*  left = calloc(1,sizeof(struct item));
            memcpy(left,heap,sizeof(struct item));
            heap[0] = heap[--hsz];
            heapify(heap,0,hsz);
	    // Vyberieme pravého syna
            struct item*  right = calloc(1,sizeof(struct item));
            memcpy(right,heap,sizeof(struct item));
            heap[0] = heap[--hsz];
            heapify(heap,0,hsz);
	    // Posledný prvok zmeníme na nový nelistový prvok
            heap[hsz].character = 0;
	    // Jeho početnosť je súčtom početností jeho potomkov
            heap[hsz].count = left->count + right->count;
            heap[hsz].left = left;
            heap[hsz].right = right;
	    // Nový prvok vložíme do kopy
            int i = hsz;
            hsz += 1;
	    // Obnovíme kopovitosť
            while (i > 0){
                    i = (i -1) /2;
                    heapify(heap,i,hsz);
            }
	    // v kope je o jeden prvok menej
        }
	// Zvyšný prvok je koreň Hufmanovho stromu
        char buffer[SIZE];
        memset(buffer,0,SIZE);
	// rekurzívne vypíšeme kódy prvkov
        print_prefix(heap,buffer,0);
        return 0;
}

