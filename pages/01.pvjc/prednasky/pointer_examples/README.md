
## Adresa premennej

<div class="note">

%p je formátovací znak pre adresu

</div>

``` c
#include <stdio.h>
void zapis_do_premennej(int a){
    a = 2;
    printf("V zapis_do_premennej():\n");
    printf("V premennej a vo funkcii je %d\n",a);
    printf("Premenna a je vo funkcii na adrese %p\n",&a);
    printf("koniec funkcie zapis_do_premennej():\n");
}
int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    printf("Premenna a je  na adrese %p\n",&a);
    zapis_do_premennej(a);
    printf("V premennej a je po zapise %d\n",a);
    printf("Premennej a je  na adrese %p\n",&a);
    return 0;
}
```
---
## Argument funkcie sa vždy kopíruje

``` c
#include <stdio.h>

void zapis_do_premennej(int a){
    a = 2;
}
int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    zapis_do_premennej(a);
    printf("V premennej a je po zapise %d\n",a);
}
```

<div class="note">

Zistili sme, že program nefunguje podľa očakávania. Dôvodom je to, že v
jazyku C sa argumenty odovzdávajú vždy kópiou.

</div>

---
## Funkcia na zápis do premennej

``` c
#include <stdio.h>
void zapis_do_premennej(int* a){
    *a = 2;
    printf("V premennej a vo funkcii je %d\n",*a);
    printf("Premenna je vo funkcii na adrese %p\n",a);
}
int main(){
    int a = 0;
    printf("V premennej a je %d\n",a);
    printf("Premenna a je  na adrese %p\n",&a);
    zapis_do_premennej(&a);
    printf("V premennej a je po zapise %d\n",a);
    printf("Premennej a je  na adrese %p\n",&a);
    return 0;
}
```

<div class="note">

Vidíme, že program funguje podstatne lepšie a podarilo sa nám
implementovať funkciu, ktorá bude manipulovať s hodnotou premennej.

</div>

---
## Funkcia na prácu s poľom

``` c
#include <stdio.h>

void male_a_na_velke_A(char* retazec){
   while (*retazec != 0){
        if (*retazec == 'a'){
            *retazec = 'A';
        }
        retazec += 1;
   }
}
int main(){
    char retazec[] = "ahoj";
    puts(retazec);
    putc('\n');
    male_a_na_velke_A(retazec);
    puts(retazec);
    putc('\n');
    return 0;
}
```
