# Pán hadov

Vytvorte implementáciu klasickej hry
[Snakes](https://en.wikipedia.org/wiki/Snake_videogame), ktorú poznáte
zo starých mobilných telefónov.

# Počiatočný stav

Svet je viditeľná oblasť obrazovky. Po svete je náhodne rozhádzaných 20
odmien, vykreslených ako `*`. Svet nemá žiadne prekážky a je ohraničený
okrajom obrazovky Telo hada je tvorené značkou `x`. Na začiatku je telo
hada dlhé 5 `x` a je umiestnený v strede obrazovky.

    [0,0]                              [width,0]
    +------> x
    |
    |       *                 *
    |
    v           ^
                x
    y           x
                x
                x
    [0,height]                         [width,height]

# Pohyb hada

Pohyb hada sa riadi pomocou šípiek podľa týchto pravidiel:

  - Ak nebola stlačená žiadna klávesa, vektor rýchlosti sa nemení.

  - Nová pozícia sa vypočíta z aktuálnej pozície plus vektor rýchlosti.

  - Had sa pohne každé kolo podľa vektora rýchlosti uloženého v
    premenných `sx, sy`

  - Vektor rýchlosti hada sa zmení podľa stlačených šípiek (`y` pre
    vertikálny smer je negatívny, lebo bod `[0,0]` je v ľavom hornom
    rohu obrazovky).

<!-- end list -->

``` 
                  DIR_UP [0,-1]
                        ^
                        |
    DIR_LEFT [-1,0] <---+---> DIR_RIGHT [1,0]
                        |
                        v
                 DIR_DOWN [0,1]
```

Ďalšia hra je ovplyvnená budúcou polohou hada:

  - Ak je nová pozícia na tele hada, hra sa končí.

  - Ak je nová pozícia na odmene, had sa zväčší o jedna. Odmenu označte
    ako zjedenú tým, že jej nastavíte negatívne súradnice. Ak sú všetky
    odmeny zjedené, hra sa končí.

  - Ak je nová pozícia hlavy mimo rozmerov sveta, hra sa končí.

  - Ak sa na novej pozícii hlavy nenachádza odmena, vymaže sa posledný
    článok hada a pridá sa nový článok na novej pozícii.

# Analýza riešenia

Pre reprezentáciu hada je najprirodzenejšie použiť spojkový zoznam. Had
je tvorený viacerými za sebou idúcimi článkami typu `struct snake`, kde
každý článok má svoju pozíciu `x,y`. Pohyb hada sa dá implementovať
pridaním nového prvého článku (funkcia `add_snake`) a zmazaním
posledného článku (funkcia `remove_snake`).

Pre reprezentáciu viacerých odmien je možné použiť dva polia celých
čísel (`foodx,foody`) (jedno pre x-ové súradnice, druhé pre y-ové
súradnice).

Ak je odmena zjedená, bude sa nachádzať na mieste mimo hracej plochy
(`i`-ta hodnota v poliach `foodx` a `foody` bude záporná).

# Odovzdanie

Úlohu vypracujte a uložte do repozitára `pvjc19cv9`. Heslo na
vypracovanie je `snake`.

Kostru zadania môžte získať ako [zip
súbor](https://student.kemt.fei.tuke.sk/pvjc/cvicenia/09.snake/pvjc19cv9.zip).

    curl -O https://student.kemt.fei.tuke.sk/pvjc/cvicenia/09.snake/pvjc19cv9.zip
    unzip pvjc19cv9.zip
    cd pvjc19cv9

Pozorne si prečítajte súbor `README.md`.

    cat README.md

Hodnotenie bude pozostávať z dvoch častí:

  - Splnenie automatických testov (10 bodov). Implementujte súbor
    `snake.c` podľa predpisov v `snake.h`.

  - Osobná obhajoba (10 bodov). Pri osobnej obhajobe budete prezentovať,
    že Vaša hra funguje a že sa orientujete vo Vašich zdrojových kódoch.
    Na získanie plného počtu bodov navrhnite zlepšenie hry, napr.
    uloženie a nahranie stavu pri štarte, zobrazenie okrajov,
    zobrazenie počtu nezjedených odmien alebo krajšie zobrazenie hada
    (odlíšenie hlavy, tela a chvosta).
