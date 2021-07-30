# Frekvenčná tabuľka písmen

Vypracujte [tutoriál č. 1](http://it4kt.cnl.sk/c/pvjc/2017/labs.01.html)

## Dodatočné materiály

  - [Prednáška Unix TR z predmetu
    ZAP](http://nlp.web.tuke.sk/zap/prednasky/09Tr/)

  - Vypracovaná implementácia [Unix TR](danotr.c)

## Potrebné funkcie

  - Konštantu s počtom písmen

<!-- end list -->

``` c
#define ASIZE 26
```

  - Funkciu pre zotriedenie poľa
    [qsort](http://www.cplusplus.com/reference/cstdlib/qsort/)

  - Funkciu pre vyhľadávanie v poli
    [bsearch](http://www.cplusplus.com/reference/cstdlib/bsearch/)

  - Funkciu pre načítanie znaku zo štandardného vstupu
    [getchar](http://www.cplusplus.com/reference/cstdio/getchar/)

## Riešenie

1.  Vytvoríme si funkcia na prevod znaku na index `int char_to_ind(char
    c)`
    
      - Ak je znak veľké alebo malé písmeno, vráti jeho poradie v
        abecede
    
      - Inak vráti konštantu

2.  Vytvorenie frekvenčnej tabuľky písmen: Funkcia `build_ftable`
    
    1.  Vynulujeme frekvenčnú tabuľku (pole)
    
    2.  Načítavame znaky zo štandardného vstupu až do konca
    
    3.  Konvertujeme znak na index
    
    4.  Ak je index v poli, zväčšíme jeho hodnotu vo frekvenčnej tabuľke

3.  Vytvoríme funkciu `compareints` pre porovnanie dvoch smerníkov typu
    int
    
    ``` c
    int compareints (const void * a, const void * b){
      return ( *(int*)a - *(int*)b );
    }
    ```

4.  Funkcia `build_ttable`
    
    1.  Vytvoríme nové pole sortedt, do ktorého uložíme zotriedenú
        frekvenčnú tabuľku. Tabuľku zotriedime pomocou `qsort` a funkcie
        pre porovnianie `compareints`
    
    2.  Vyhľadáme každý prvok frekvenčnej tabuľky `ftable` v zotriedenej
        frekvenčnej tabuľke `sortedt` a jeho index uložíme do
        prekladovej tabuľky `ttable`
        
        ``` c
        ttable[i] = bsearch(&ftable[i],sortedt,ASIZE,sizeof(int)) - sortedt;
        ```
