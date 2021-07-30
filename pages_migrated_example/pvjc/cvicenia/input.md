---
title: Načítanie čísla
published: true
---

! Naučíte sa:
!
! - Bezpečne načítať číselnú alebo inú hodnotu zo štandardného vstupu.
! - Vyhradiť a inicializovovať statické pole

Do teraz ste väčšinou na načítanie používali funkciu `scanf`. Jej nesprávne použivanie môže spôsobiť neočakávané správanie Vášho programu. 

- Každý vstup ktorý je iný ako očakávaný zlyhá.
- Načítanie reťazca sa preruší pri prvej medzere alebo pri konci riadka.
- Ak zadáte nesprávny vstup, ten zostane "zaseknutý" a každé ďalšie volanie funkcie zlyhá.
- Funkcia `scanf` nevie celkom dobre rozlíšiť, prečo zlyhalo načítanie.
- Funkcia `scanf` vie pracovať iba so štandardným vstupom, nie so smerníkom na otvorený  súbor. 
- Príliš dlhý vstup môže spôsobiť pád programu.

## Načítanie zo štandardného vstupu

Aby sme obišli obmedzenia funkcie `scanf` pre načítanie čísla, môžeme použiť iný postup. Najprv si vyhradíme a inicializujeme pole, do ktorého sa pokúsime načítať ľubovoľný reťazec.
Sledujeme, či sa načítanie podarilo. Načítanie zlyhá v prípade, že už žiadny riadok nie je k dispozícii (koniec súboru alebo koniec štandardného vstupu).

Na načítanie ľubovoľného reťazca do statického poľa môžeme použiť cyklus a načítavať znaky pomocou `getchar()` pokiaľ nenájdeme koniec riadka, nevyčerpáme miesto v poli, alebo nenastane koniec vstupu.
Jednoduchšie je použiť funkciu [fgets()](https://www.cplusplus.com/reference/cstdio/fgets/). 

Najprv sa zoznámte  s jej manuálovou stránkou. Pozrite si aké argumenty prijíma a akú má návratovú hodnotu. Akým spôsobom funkcia signalizuje chyby?

Príklad použitia:

```
char riadok[LINE_SIZE];
memset(riadok, 0,LINE_SIZE);
char* r = fgets(riadok,LINE_SIZE,stdin);
if (r == NULL){
    // Nacitanie sa nepodarilo.
}
```

Takto načítame ľubovoľný reťazec bez toho aby hrozilo nejaké zaseknutie. 
Je možné, že riadok ktorý načítavame sa nezmestí do poľa ktoré sme vytvorili. V tom prípade funkcia `fgets()` načíta toľko znakov koľko sa dá a zvyšok sa načíta pri ďalšom volaní. Túto situáciu spoznáme tak, že v načítanom reťazci sa na konci nebude nachádzať koniec riadka (`\n` alebo `\r\n` na Windows).


!!! Nikdy nezabudnite skontrolovať, či sa načítanie podarilo.
!!! Ak sa načítanie nepodarí, program nebude pokračovať ďalej, ale budeme pracovať s pôvodným obsahom premennej do ktorej sme chceli načítať.

Ak sa vám nechce špecificky ošetrovať neplatný vstup, je lepšie zabrániť tomu aby program pokračoval s neplatnými vstupmi a program "zhodiť" v prípade, že sa načítanie nepodarí. Na predčasné ukončenie programu používame makro `assert()` alebo funkciu `exit()`.

```
// Vyhradíme pamäť
char riadok[LINE_SIZE];
// Inicializujeme pamäť
memset(riadok, 0,LINE_SIZE);
// Načítame pamäť
char* r = fgets(riadok,LINE_SIZE,stdin);
// V prípade že sa načítanie nepodarilo, ukončíme program.
assert(r!=NULL);
// Sme si istí, že načítanie sa podarilo 
// vyhneme sa práci s poľom v ktorom nič nie je
```

Ak prejde tento program tak si môžeme byť istí, že v poli sa nachádza platný reťazec.

## Konverzia reťazca na číslo

V druhom kroku sa pokúsime premeniť reťazec na číselnú hodnotu.
Na konverziu reťazca na číslo existuje viac funkcií. Použijeme tú, ktorá sa nám najviac hodí:

- [atof()](https://www.cplusplus.com/reference/cstdlib/atof/) - premena desatinného čísla
- [atol()](https://www.cplusplus.com/reference/cstdlib/atol/) - premena celého čísla
- [strtol()](https://www.cplusplus.com/reference/cstdlib/strtol/) - premena  celého čísla s ľubovoľným základom s rozpoznávaním konca zápisu.
- [strtof()](https://www.cplusplus.com/reference/cstdlib/strtof/)- premena desatinného  s rozpoznávaním konca zápisu.
- [sscanf()](https://www.cplusplus.com/reference/cstdio/sscanf/) - premena ľubovoľného vstupu vrátane čísel podľa formátovacieho reťazca.

Pred použitím konverznej funkcie sa oboznámte ako konverzia funguje a ako funkcia hlási chybové stavy.

Napríklad `atol()` premení reťazec na celé číslo. V prípade, že sa konverzia nepodarila vráti nulu. Ak sa konverzia podarila, vráti rozpoznané číslo. 
Nevýhoda tejto funkcie je, že nevie rozlíšiť načítanie nuly od chybového stavu. Ak je nula prijateľný vstup tak ho musíme ošetriť osobitne.

```
int r2 = atol(line);
if (r2 == 0){
    // Konverzia sa nepodarila alebo v reťazci sa nachádza nula.
}
```

Funkcia `atol()` preskočí všetky biele znaky na začiatku a na konci vynechá znaky ktoré nie sú cifry.
Takýto vstup je rozpoznaný ako 3:

         3x

Ak nám záleží na konci zápisu čísla, použijeme funkciu `strtol`. Do smerníka `endptr` v prípade úspechu uloží koniec zápisu čísla.

```
char* endptr = NULL;
int r = strtol(line, &endptr,10);
if (r){
    // Nacitanie sa podarilo
}
```

Funkciu `strtol` vieme použiť v prípade, že sú hodnoty uložené v riadku a oddelené medzerou alebo čiarkou:

```
// Pole s retazcom
char line[LINE_SIZE] = "1 2 3 4";
// Pocet znakov retazca
int len = strlen(line);
// Koniec zapisu aktualneho cisla
char* endptr = NULL;
// Zaciatok aktualneho cisla
char* start = line;
// Rozpoznane cislo
int num = 0;
// Pokial je zaciatok v ramci retazca
while (start < (line + len)){
    // Rozpozname cislo
    num = strtol(start,&endptr,10);
    if (num){
        printf("Nacital som %d\n",num);
        // Smernik nastavime na dalsie cislo
        start = endptr + 1;
    }
    else {
        break;
    }
}

```

Smerník na koniec rozpoznaného čísla vieme využiť aj na zistenie dĺžky rozpoznaného čísla.

```
char line[10] = "33x";
char* endptr = NULL;
int n = strtol(line,&endptr,10);
if (n != 0){
    // Dva smerniky, smernink je ciselna adresa
    // Ich rozdiel je pocet znakov, jeden znak je jeden bajt
    int l = endptr - line;
    printf("Rozpoznali sme %d a sklada sa z %d znakov.\n",n,l);
}
```

## Vypracovanie

Na precvičenie štandardného vstupu je pripravená úloha "Hornerova schéma".
[Úlohu budete odovzdávať](https://traktor.kemt.fei.tuke.sk/#/submit/145) do súboru `program.c` v adresári `a1`  vo Vašom GIT repozitári.

