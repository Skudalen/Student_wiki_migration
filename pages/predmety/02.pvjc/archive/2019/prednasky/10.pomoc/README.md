# Pomoc, môj program nefunguje\!

Časté problémy a techniky ladenia

# Verím svojmu kódu?

Som si istý, aký bude výsledok?

# Spracovávanie neurčitej hodnoty má neurčitý výsledok\!

# Program sa správa nepredvídateľne

  - Inak na rôznych počítačoch.

  - Niekedy funguje, niekedy nie.

  - Nevypíše nič.

  - Vypíše `segmentation fault`.

  - Návratová hodnota je -11.

# Ako chybu odhalím a ako jej zabránim

  - Ladenie programu.

  - Písanie dôverhodného kódu.

# Zásady dôveryhodného kódu

  - Načúvajte chybovým hláseniam.

  - Uistite sa o predpokladoch.

  - Zabráte šireniu neistoty.

# Načúvajte hláseniam o chybe

``` c
char* r = fgets(pole,100,stdin);
if (r == NULL){
// Vstup sa prerušil
}
```

# Uistite sa o predpokladoch pre činnosť

``` c
int search(int pole, int velkost){
    assert(velkost > 0);
```

# Zabránte šíreniu neistoty

  - Prerušte program hneď ako sa dostane do neurčitého stavu.

  - Funkcia assert

  - Funkcia abort

# Funkcia assert

  - Preruší program, ak nebola splnená podmienka.

  - Zabezpečí "dôveryhodný" kód.

# Príklad: Vyhľadajte znak `c` v prvých `n` znakoch reťazca

``` c
int vyhladaj(const char* retazec, char c,int n){
    for (int i = 0; i < n; i++){
        if (retazec[i] == c){
            return i;
        }
    }
    return -1;
}
```

# Príklad na dôveryhodný kód

``` c
int vyhladaj(const char* retazec, char c,int n){
    assert(retazec != NULL);
    for (int i = 0; i < n; i++){
        assert(retazec[i] != 0);
        if (retazec[i] == c){
            return i;
        }
    }
    return -1;
}
```

# Statická analýza

  - Program `cppcheck`

  - Prepínač `-Wall`

# Používanie programu valgrind

  - Prepínač `-g`

# Analýza core dump

  - funkcia assert

<!-- end list -->

    gcc -g ./program.c -o ./program
    ulimit -c unlimited
    ./program
    Segmentation fault, core dumped
    gdb ./program vgcore.1234
    bt

# Ladenie pomocou gdb

    gcc -g ./program.c -o ./program
    gdb ./program
    break 12
    run
    bt
    p a

# Poznámky k zadaniu "Pán hadov"

Pozri spojkový zoznam.

# Poznámky k zadaniu "Slovár slovenský"

Nebojte sa opýtať.
