# Kopa zábavy

Kopa žiadateľov o zamestnanie sa uchádza o pozície súvisiace s kopením. Pracovníci technických služieb zhŕňajú lístie na kopu, kopáči kopú priekopy a kopia kopy hliny, futbalisti kopú do lopty, poštári roznášajú kopy zásielok. 
Len študentom sa kopia zadania bez toho aby museli niečo urobiť.

Pomôže našim budúcim kolegom na úrade práce. Technická univerzita usporiada školenie o binárnej kope. Máte šancu vypracovať príklad na školenie ktorým raz a navždy vyriešite problém binárneho kopenia.

## Cieľ

- Naučiť sa pracovať s binárnou kopou

## Úloha

Vytvorte program, ktorý používateľovi pomôže vysvetliť čo je je to binárna kopa.

Na vstupe program dostane niekoľko celých čísle oddelených medzerou.

Vašou úlohou je zistiť, či čísla všetky čísla spĺňajú podmienku binárnej minimálnej kopovitosti.

Pre číslo  v poli s indexom  `i` vypočítajte index jeho ľavého a pravého syna:

    l = i * 2 + 1
    r = i * 2 + 2

Ak ľavý a pravý syn čísla v poli existuje, potom jeho hodnota musí byť väčšia ako hodnota aktuálneho čísla.

Ak postupnosť spĺňa podmienku binárnej minimálnej kopovitosti, potom vypíšte spôsobom "preorder" výsledný binárny strom.
Jeden uzol vypíšte na jeden riadok. Číselnú hodnotu uzla odsaďte medzerami podľa úrovne na ktorej sa nachádza.
Potom rekurzívne vypíšte ľavého a pravého syna s väčšou úrovňou odsadenia ak existujú.

Ak postupnosť nie je binárna kopa, vypíšte správu a ukončite program.

Príklad na vstup:

    5 10 36 20 78

Príklad na výstup:

    Je to taka kopa:
    5
     10
      20
      78
     36

Iný príklad na vstup:

    34 41 40 28 60

Výstup:

    Nie je kopa.



## Binárna kopa

Binárna kopa je údajová štruktúra ktorá umožňuje ľahký prístup ($O(1)$) k minimálnemu alebo maximálnemu prvku usporiadanej množiny. Má malé nároky na pamäť, lebo prvky v nej sú uložené za sebou v poli.
Do binárnej kopy si môžeme uložiť ľubovoľný prvok, ktorý vieme porovnať. 

Ak do kopy chceme uložiť meno a vek osoby, použijeme podobný prístup ako pri zásobníku. 

Takto si vytvoríme prázdnu kopu:

```c
struct osoba{
    char meno[100];
    int vek;
};

int main(){
    // Pole pre ulozenie databazy
    struct osoba*[20];
    memset(osoba,0, sizeof(struct osoba*));
    // Pocet prvkov v databaze
    int pocet = 0;
    return 0;
}
```

V tomto príklade som použil pole smerníkov, aby sa prvky ľahšie vymieňali medzi sebou. Pri výmene mi stačí kopírovať smerníky a nemusím kopírovať celé hodnoty.

Aby sme mohli ľubovoľné pole prehlásiť za minimálnu binárnu kopu, tak všetky prvky v ňom musia spĺňať podmienku minimálnej binárnej kopovitosti.

Pre každý prvok binárnej kopy vieme nájsť jeho ľavého a pravého syna. 
Pozíciu ľavého a pravého syna v poli si vypočítame z indexu:

```c
int left_index = (2*index) + 1;
int right_index = (2*index) + 2;
```

Vieme si vypočítať aj polohy rodiča:

```
int parent_index =  (index -1) / 2;
}
```

Všetky prvky v binárnej kope spolu tvoria binárny strom:

![Kopa](./Binary_Heap_as_Array.svg)

Na prvom mieste je vždy uzol s minimálnou hodnotou.
Podmienka minimálnej kopovitosti hovorí, že žiadny potomok nesmie mať väčšiu hodnotu ako rodič. Na rozdiel od binárneho vyhľadávacieho stromu ale nič nehovorí o poradí prvkov. 

Vloženie do kopy znamená pridanie nového  prvku na koniec a obnovenie kopovitosti pre všetkých jeho rodičov. 
Znamená to, že ak je niektorý rodič väčší, tak prvky vymeníme. Tak sa môže najmenší prvok dostať z konca až celkom na začiatok stromu.

```c
// Počet prvkov v kope sa zväčší o jedna
void add_person(struct person** heap,int hsz, const char* name, int age ){
    struct person* item = calloc(1,sizeof(struct person));
    item->age = age;
    strcpy(item->name,name);
    // Uložíme na koniec
    heap[hsz] = item;
    // Pozrieme na jeho rodiča
    int p = (hsz -1) / 2;
    int i = hsz;
    // Pokiaľ rodič existuje a jeho hodnota je väčšia
    while(p >= 0 && heap[p]->age > heap[i]->age){
        // Vymeníme ich hodnoty
        struct person* this = heap[i];
        heap[i] = heap[p];
        heap[p] = this;
        // Pokračujeme ďalším rodičom
        i = p;
        p = (p - 1) / 2;
    }
}
```

Odobratie najmenšieho prvku znamená jeho nahradenie posledným prvkom a obnovenie kopovitosti pre všetkých potomkov.
Najprv si vytvoríme funkciu pre obnovenie kopovitosti všetkých potomkov pre i-ty prvok:


```c
// Funkcia predpokladá, že v kope je iba jedna chyba
void heapify(struct person** heap, int hsz,int i){
    struct person* this = heap[i];
    int left_index = (2*i) + 1;
    int right_index = (2*i) + 2;
    // Zistíme kde sa nachádza minimum
    int m = i;
    if (left_index < hsz && heap[left_index]->age < this->age){
        m = left_index;
    }
    if (right_index < hsz && heap[right_index]->age < this->age){
        m = right_index;
    }
    if (m != i){
        heap[i] = heap[m];
        heam[m] = this;
        heapify(heap,hsz,m);
    }
}
```

Úplné odobranie znamená výmenu prvého a posledného prvku z kopy a obnovenie kopovitosti pre  nový prvý člen.

## Ako na to

V tejto úlohe Vám stačí rozhodnúc, či zobrazená postupnosť spĺňa podmienku kopovitosti alebo nie. Nemusíte programovať pridávanie a odoberanie.
Stačí prejsť všetky členy a zistiť či spĺňajú podmienku kopovitosti.

Najťažšie bude asi načítať všetky čísla z riadka ktoré sú oddelené medzerou.
Najlepšie asi bude využiť funkciu `strtol` pomocou ktoré viete premeniť ľubovoľný reťazec na číslo s desatinnou čiarkou.

1. Načítajte všetky čísla z riadku do poľa
2. Prejdite všetky čísla v poli o overte podmienku kopovitosti.
3. Ak je podmienka splnená, zobrazte pole ako keby to bol binárny strom.

## Odovzdanie

Ako aktivita 3 do súboru `a3/program.c`.

