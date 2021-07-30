# Cvičenie 2

## Frekvenčná tabuľka písmen

Vypracujte http://it4kt.cnl.sk/c/pvjc/2017/labs.01.html[tutoriál č. 1]

### Dodatočné materiály

* http://nlp.web.tuke.sk/zap/prednasky/09Tr/[Prednáška Unix TR z predmetu ZAP]
* Vypracovaná implementácia link:danotr.c[Unix TR]


### Potrebné funkcie

* Konštantu s počtom písmen

```c    
#define ASIZE 26
```



    
* Funkciu pre zotriedenie poľa http://www.cplusplus.com/reference/cstdlib/qsort/[qsort]
* Funkciu pre vyhľadávanie v poli http://www.cplusplus.com/reference/cstdlib/bsearch/[bsearch]
* Funkciu pre načítanie znaku zo štandardného vstupu http://www.cplusplus.com/reference/cstdio/getchar/[getchar]

### Riešenie

. Vytvoríme si funkcia na prevod znaku na index `int char_to_ind(char c)`
    ** Ak je znak veľké alebo malé písmeno, vráti jeho poradie v abecede
    ** Inak vráti konštantu
. Vytvorenie frekvenčnej tabuľky písmen: Funkcia `build_ftable`
.. Vynulujeme frekvenčnú tabuľku (pole)
.. Načítavame znaky zo štandardného vstupu až do konca
.. Konvertujeme znak na index
.. Ak je index v poli, zväčšíme jeho hodnotu vo frekvenčnej tabuľke
. Vytvoríme funkciu `compareints` pre porovnanie dvoch smerníkov typu int
+
```c    
int compareints (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}
```
. Funkcia `build_ttable`

.. Vytvoríme nové pole sortedt, do ktorého uložíme zotriedenú frekvenčnú tabuľku. Tabuľku zotriedime pomocou `qsort` a funkcie pre porovnianie `compareints`
.. Vyhľadáme každý prvok frekvenčnej tabuľky `ftable`  v zotriedenej frekvenčnej tabuľke `sortedt` a jeho index uložíme do prekladovej tabuľky `ttable`
+
```c
ttable[i] = bsearch(&ftable[i],sortedt,ASIZE,sizeof(int)) - sortedt;
```
