
# Archív 2016

# Základy algoritmizácie a programovania 2016 - Informácie o cvičeniach

Katedra elektroniky a multimediálnych komunikácií

Zimný semester 2016

Cvičiaci: Ing. Daniel Hládek PhD.


# Oznamy

- 06.12.2016 : Predtermín skúšky ZAP je 20.12.2016
- 29.11.2016 : Prosím pozrite si [pokyny k skúške](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fexam)
- 22.11.2016 : Cvičenia v stredu 23.11 budú prebiehať formou samoštúdia [tutoriálu č.10](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.10).
- 11.10.2016 : [64-bitová verzia Karlovej knižnice](http://it4kt.cnl.sk/c/zap/2016-ZS/resources/lib/libkarel64-lin.a). Pre použitie upravte aj Makefile
- 19.9.2016 : Odporúčaný čas individuálnych konzultácií je pondelok 12:00 (BN32 L609).

# Obsah

[TOC]

# Študijné materiály

- [Web stránka predmetu](http://it4kt.cnl.sk/c/zap/)
- [video Mirek Biňas - Úvodná prednáška do jazyka C](http://it4kt.cnl.sk/c/pvjc/2016/lecture.01.html)
- [kniha Podlubný: Úvod do programovanie v jazyku C](http://people.tuke.sk/igor.podlubny/C/index.htm)
- [kniha Belan: Kurz jazyka C](https://www.smnd.sk/anino/moje/C.pdf)
- Pôvodné stránky robota [Karel](https://www.cs.mtsu.edu/~untch/karel/)
- Elektronická kniha [Pro Git](https://git-scm.com/book/cs/v1) (česky)
- Pavel Herout : Učebnice jazyka C (1. díl) (Vydavateľstvo: Kopp, 2009)
- [Kreslenie vývojových diagramov](http://it4kt.cnl.sk/c/zap/#!/flowcharts)
- [Štandardná knižnica jazyka C](http://www.cplusplus.com/reference/clibrary/)
- [Zmeny git repozitára](https://git-scm.com/book/cs/v1/Z%C3%A1klady-pr%C3%A1ce-se-syst%C3%A9mem-Git-Nahr%C3%A1v%C3%A1n%C3%AD-zm%C4%9Bn-do-repozit%C3%A1%C5%99e)

# Osnova cvičení

## 1. Úvodné cvičenie a podmienky zápočtu

Vytvorte a spustite si prvý program v jazyku C.

1. Prihláste sa na server omega.tuke.sk
    - Pre Linux: `ssh ab123cd@omega.tuke.sk`
    - Pre Windows: použite klient Putty, vyplňte prihlasovacie meno a heslo
1. Zmente si klávesnicu na anglickú
1. Vytvorte si adresár hello
    - `mkdir hello`
1. Zmente aktuálny adresár na hello
    - `cd hello`
1. Vytvorte textový súbor hello.c a napíšte program
    - Nápoveda editoru Nano sa nachádza na dolnej časti obrazovky
    - Ctrl+X uloží a skončí
    - `nano hello.c`

            #include <stdio.h>
            int main(int argc, char** argv) {
               printf("Hello world!");
            }

1. Preložte Váš program
    - `gcc hello.c -o hello`
    - Pozorne sledujte prípadné chybové hlásenia
1. Spustite program
    - `./hello`

### Práca v príkazovom riadku

- `TAB` dopĺňa názvy súborov a príkazov
- šípky hore a dole vrátia príkaz z histórie
- `Crtl+C` preruší vykonávanie príkazu
- `Ctrl+D` preruší vykonávanie alebo odpojí
- `rm -r ./hello ` vymaže adresár hello
- `cd ..` prepne adresár o úroveň vyššie
- `ls -l` vypíše súbory v aktuálnom adresári
- `mc` súborový manažér podobný T*tal c*mmanderu

### Domáca úloha

- Nainštalujte si virtuálny [stroj](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.00)
- Na stránke [Hour of Code](https://code.org/learn) si vyberte jednu z hier a snažte sa dosiahnuť čo najvyšší level.

## Cvičenie 2: Robot Karel

Opakovanie: Práca v termináli

- používajte anglickú klávesnicu
- využívajte šípky a TAB
- poriadne čítajte čo je na obrazovke

Naučte sa vytvárať funkcie,cykly  a podmienky typu if v jazyku C

- Štruktúra programu v jazyku C
    - Hlavičkové súbory
    - Funkcia Main
- Proces prekladu programu
    - Program make a Makefile
- Funkcie
    - `turnOn(const char* mapfile)`
    - `turnOff()`
    - `turnLeft()`
    - `pickBeeper()`
    - `putBeeper()`
    - `movek()`
- Podmienky a cyklus for
    - `frontIsClear()`
    - `beeperIsPresent()`

- Zoznam príkazov, ktoré pozná Karel je v súbore karel.h
- [Dokumentácia robota Karel](http://it4kt.cnl.sk/c/zap/#!/api)
- Vypracujte tento [tutoriál](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.02)
    1. Pomocou príkazu wget získajte súbory Makefile, karel.h, stairs.kw
    1. Pomocou príkazu nano vytvorte súbor stairs.c
    1. Pomocou príkazu make preložte súbor stairs.c a vytvorte spustiteľný súbor stairs
    1. Spustite súbor stairs
    1. Pokračujte v tutoriáli

## Cvičenie 3 : Robot Karel 2

 Vypracujte [tutorál č. 3](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.03)

### Opakovanie

- Funkcie
- Podmienky
    - if, else
- Cykly
    - While
    - For
    - continue, break

## Cvičenie 4 : Robot Karel 3

Vypracujte [tutorál č. 4](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.04)

Vypracujte Vaše zadanie

### Opakovanie

- Podmienky
- Cykly

### Nová látka

- Komentáre v zdrojovom kóde
- Vývojové diagramy
    - Kreslenie vývojových diagramov a generovanie C++ kódu [Flowgorithm](http://www.flowgorithm.org/)
    - Diagram pre prehľadávanie miestnosti
        - Choď dopredu a zober všetky žetóny

## Cvičenie 5. Odovzdávanie a vypracovávanie zadania 1

## Cvičenie 6

Vypracujte [tutorál č. 6](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.06)

Obhajoba zadania č. 1

### Nová látka

Štandardná knižnica jazyka C

- stdio.h
    - [printf()](http://www.cplusplus.com/reference/cstdio/printf/)
    - [scanf()](http://www.cplusplus.com/reference/cstdio/scanf/)
- stdlib.h a time.h
  - 'srand(time(NULL))'
- math.h
  - 'rand()'

Makrá preprocesora
- '#define'

    // Inizializacia nahodneho generatora
    srand(time(NULL));
    // Celociselne delenie pre generovanie cisla v intervale
    int nahodneCislo = (rand() % 100) + 1; 
    int mojeCislo = 0;
    // Vypis na obrazovku
    printf("Zadaj cislo\n"); 
    // Nacitanie do premennej
    int r = scanf("%d",&mojeCislo); 
    // Navratova hodnota vravi kolko cisel sa podarilo nacitat
    if (r != 1){ 
        printf("Nezadali ste cele cislo\n");
        // Ak bolo nacitanie neuspesne, v premennej moze byt nepredvidatelna hodnota
    }
    // Ak bolo nacitanie uspesne, mozme vysledok porovnat
    else if (mojeCislo > nahodneCislo){ 
        printf("Zadali %d a je vacsie ako nahodne cislo\n",mojeCislo);
    }

## Cvičenie 7

Vypracujte [tutoriál č. 7](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.07)


### Nová látka:

- Algoritmus lineárneho vyhľadávania
  - Polia a smerníky
  - Operátor sizeof
- Preklad programu pre ladenie
  - Informácie pre ladenie
  - Parameter -g
- Ladenie programu pomocou CGDB / GDB
  - Breakpoint
  - Krokovanie (step,continue)
  - Výpis premennej
  - Používanie assert

### Domáca úloha

- Vypracujte tutoriál [Systém GIT](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.08)
  - Implementujte hru Tiktak

## Cvičenie 8


- Zápočtovka cez Moodle
    - Prednáška 1 a 2
    - Je dostupný testovací test
- Konzultácie GIT

## Cvičenie 9

### Opakovanie

- Ladenie programu pomocou programu gdb
    - Vypracujte [tutoriál č. 7](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.07)
    - [GDB Tutoriál 1](http://www.unknownroad.com/rtfm/gdbtut/)
    - [GDB Tutoriál 2](https://www.tutorialspoint.com/gnu_debugger/index.htm)
- Systém Git
    - Vypracujte tutoriál [Systém GIT](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.08)
    - Implementujte hru Tiktak

### Postup pri ladení pomocou programu GDB:

1. Preložte Váš program s parametrom -g
    
        gcc linear.c -g -o linear

1. Spustite debugger
    
        gdb linear

1. Zobrazte pomoc pre príkaz list a zistite ako sa zobrazuje zdrojový kód
    
        help list

1. Zobrazte pomoc pre príkaz break na nastavenie breakpointu
    
        help break

1. Nastavte breakpoint na funkciu main alebo na číslo riadku
    
        b main

1. Spustite program
    
        run

1. Program zastane na breakpointe. Príkazom backtrack (bt) zobrazíte aktuálne spustené funkcie. Príkaz info locals vám vypíše lokálne premenné. Príkaz print (p) vypíše obsah premennej.
    
        bt
        p it

1. Krokujte program príkazom step (s). Príkaz continue (c) pokračuje až po ďaľší breakpoint alebo po koniec.
    
        s
        c

1. Ladený program prerušíte Ctrl+C. Debugger skončíte Ctrl+D alebo quit
    
        quit


### Pomôcka pre GIT


1. Prihláste sa na [GitLab](https://git.kpi.fei.tuke.sk.sk)
2. Na omege alebo na inom lokálnom stroji vyvorte ssh kľúč príkazom ssh-keygen a vložte ho na GitLab. Nastavené cesty súborov neprepisujte!
    
        dano@staviarsky:~/apps$ ssh-keygen -t rsa -C "daniel.hladek@tuke.sk"
        Generating public/private rsa key pair.
        Enter file in which to save the key (/home/dano/.ssh/id_rsa): 
        Enter passphrase (empty for no passphrase): 
        Enter same passphrase again: 
        Your identification has been saved in /home/dano/.ssh/id_rsa.
        Your public key has been saved in /home/dano/.ssh/id_rsa.pub.
        The key fingerprint is:
        20:7d:33:db:df:1c:db:b0:16:27:d3:04:c5:2e:63:5a daniel.hladek@tuke.sk
        The key's randomart image is:
        +--[ RSA 2048]----+
        |              .o.|
        |     .         ..|
        |    . o +      ..|
        |     . o =    Eo.|
        |        S .  +*oo|
        |           ..o @ |
        |            . * .|
        |             .   |
        |                 |
        +-----------------+
        dano@staviarsky:~/apps$ cat ~/.ssh/
        id_rsa       id_rsa.pub   known_hosts  
        dano@staviarsky:~/apps$ cat ~/.ssh/id_rsa.pub 
        ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDAWK9Fk9vBt9/TTOHbbZNj6oazn9qXJaO0mnqmuLGkc9tlOcOksDErjME3SI90enGbq5mLzqToKhv7aEHJHTBb1wtKCIAYE8WYOHRC7A7IVJZuDA5cJLmwjljZ/aFcfvHVghXuYnLF29fmgd6vDiAQ3liFXdw6ih3DoQArKnUofOOhWcVpwrrw1fqDFoWbYVpqJfiKEnGbxJssfSIi0wLtpv3P+fudNDi8hl84jznsVQkVCDqfagunjUWJpHn9izbPg7NnZh5hUEGz2ZxUfppvwHRD9ndT/s2vDzOI9hqJZiwp9NwCZKgNS1HQDuenY0wTVwJuuuTLrVXXwvCGGDIr daniel.hladek@tuke.sk


3. Na GitLabe Vytvorte si prázdny Git projekt z názvom zap-2016 podľa návodu na GitLabe
3. Obsah súboru ~/.ssh/id_rsa.pub vložíme do GitLabu:
    Menu vľavo hore => Profile Settings => SSH Keys => Key
3. Príkazom git clone vytvorte prázdny repozitár na lokálnom stroji.
4. Implementujte hru TiTak
5. Potvrďte Vaše zmeny na GitLab príkazom git add, git commit a git push
    
        touch README.md
        git add README.md
        git commit -m "first commit"
        git push -u origin master

### Niektoré príkazy Git


Zobrazenie manuálovej stránky
    
    git help

Pridanie súboru do oblasti zmien (staging area)
    
    git add

Potvrdenie oblasti zmien
    
    git commit

Zobrazenie zmenených súborov
    
    git status

Odoslanie potvrdených zmien na vzdialený repozitár
    
    git push


Zobrazenie potvrdených zmien

    git log

Pridanie nových zmien ktoré odstraňujú už potvrdené zmeny
    
    git revert

Vymazanie z histórie potvrdených zmien alebo zrušenie oblasti zmien
    
    git reset


## Cvičenie 10

Vypracujte [tutoriál č. 10](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.10)

Nová látka:

Dvojrozmerné polia

## Cvičenie 11


Vypracujte [tutoriál č. 11](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.11)

Opakovanie:

Dvojrozmerné polia

Nová látka:

- Práca so súbormi
    -  [fopen()](http://www.cplusplus.com/reference/cstdio/fopen/) Inicializácia práce so súborom
    -  [fclose()](http://www.cplusplus.com/reference/cstdio/fclose/) Ukončenie práce so súborom
    -  [fscanf()](http://www.cplusplus.com/reference/cstdio/fscanf/) Načítanie obsahu zo súboru s určitým formátom
    -  [fgets()](http://www.cplusplus.com/reference/cstdio/fgets/) Načítanie riadku (reťazca) zo súboru
    -  [fgetc()](http://www.cplusplus.com/reference/cstdio/fgetc/) Načítanie znaku zo súboru

- Smerníky ako výstupné argumenty


## Cvičenie 12


Vypracujte [tutoriál č. 12](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.12)

Opakovanie:

Práca so súbormi

## Cvičenie 13

Obhajoba zápočtov a odovzdávanie dodatočných zadaní L610 BN32, odporúčaný čas pondelok 12:30



# Zadanie číslo 1

- Zadanie odovzdávame ako prílohu na e-mail cvičiaceho, do hlavičky uveďte "zap zadanie 1", do správy uveďte Vaše meno a skupinu
- Zadanie obhajujeme osobne na cvičení č. 5 alebo na ďalších cvičeniach

## Hodnotenie

- 2 body správnosť
    - Viete ho preložiť
    - Spĺňa zadanie
- 2 body dokumentácia
    - Komentáre v zdrojovom kóde
    - PDF dokumentácia
    - Vývojový diagram
- 2 body včasnosť
    - Cvičenie č. 5 plný počet
    - Cvičenie č. 6 plný počet
    - Cvičenie č. 7 -2 body
    - Neskôr: zadanie nehodnotím

## Pokyny pre vypracovanie

[Podrobné podmienky](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.01) pre odovzdanie zadania. Znenie zadania Vám povie cvičiaci.

- Zadanie musí obsahovať
    - Vami naprogramovaný súbor .c so zadaním
    - 2 x súbor sveta Karla .kw potrebný pre spustenie zadania. Návod na vytvorenie sveta je na tejto stránke dole.
    - Dokumentáciu
- Zdrojový kód musí:
    - byť preložiteľný
    - spĺňať zadanie
    - samostatne vypracovaný
    - okomentovaný
        - Vaše meno a skupinu
        - Stručný návod na preloženie
        - Stručný opis úlohy čo riešite
        - použité premenné, funkcie, vetvenia a slučky
    - môže obsahovať premenné ak ich viete odôvodniť
- Dokumentácia musí:
    - Byť vo formáte PDF
        - Pre Windows môžete použiť [PDF Printer](http://www.pdfforge.org/pdfcreator)
        - Alebo LibreOffice.org
    - Úvodná strana - hlavička s názvom univerzity a fakulty, názov zadania, meno a priezvisko, rok
    - Presné znenie zadania
    - Slovný opis alebo obrázok počiatočnej a koncovej pozície Karla
    - Návrh riešenia - Slovný návrh riešenia daného problému
    - Stručný opis navrhnutých funkcií
    - Vývojový diagram programu resp. jeho najdôležitejších funkcií
        - Kreslenie vývojových diagramov a generovanie C++ kódu [Flowgorithm](http://www.flowgorithm.org/)

# Zadanie č. 2

- 5 bodov do skúšky typu A
- [Podmienky pre vypracovanie](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.02)
- Odovzdanie pomocou e-mailu podľa návodu do 30.10.2016
    - Do hlavičky uvedte "ZAP Zadanie 2"
    - Do tela správy Vaše meno a skupinu a opis zadania podľa návodu

## Hodnotenie

- 4 body včasnosť
    - Zadanie spĺňa minimálne podmienky a je odovzdané načas
- 1 bod správnosť
    - Zadanie je dostanočne zložité

# Zadanie č. 3

- 5 bodov do skúšky typu A
- [Podmienky pre vypracovanie](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.03)
- Odovzdanie pomocou e-mailu do 6.11.2016
    - Do hlavičky uvedte "ZAP Zadanie 3"
    - Do tela správy Vaše meno a skupinu
    - Do prílohy zdrojové súbory, súbory sveta a PDF dokumentáciu
    - Pre kompresiu príloh používajte ZIP 

## Hodnotenie

- 1 body správnosť
    - zadanie je vypracované dostatočne všeobecne
- 2 bod včasnosť
    - Zadanie spĺňa minimálne podmienky a je odovzdané načas
- 2 body dokumentácia
    - komentáre v zdrojovom kóde
    - vývojový diagram a PDF dokumentácia

# Zadanie č. 4


Najprv vypracujte tutoriál [Systém GIT](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Flabs.08)

Znenie zadania  [Tiktak a Tesco](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.04)

Dobrvoľne 5 bodov od 2.11. do 13.11.2016

## Hodnotenie

Hodnotenie automaticky pomocou systemu Arena

Odovzdanie pomocou [GitLab](http://git.kpi.fei.tuke.sk)

# Zadanie 5 a 6

Zadanie 5 je dobrovoľné, zadanie 6 povinné.

Hodnotenie automaticky pomocou systemu Arena

Odovzdanie pomocou [GitLab](http://git.kpi.fei.tuke.sk)

# Zadanie č. 7

[Znenie zadania](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.07)

- Zadanie odovzdávame ako prílohu na e-mail cvičiaceho, do hlavičky uveďte "zap zadanie 7", do správy uveďte Vaše meno a skupinu
- Zadanie obhajujeme osobne na cvičení č. 12 alebo 13

## Hodnotenie

- 5 bodov do skúšky typu A

- 2 body správnosť
    - Spĺňa zadanie
- 2 body dokumentácia
    - Komentáre v zdrojovom kóde
    - Viete sa orientovať v zdrojovom kóde
    - PDF dokumentácia
    - Vývojový diagram
- 1 bod včasnosť


# Zadanie č. 8

[Znenie zadania](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.08)

- Zadanie odovzdávame ako prílohu na e-mail cvičiaceho, do hlavičky uveďte "zap zadanie 8", do správy uveďte Vaše meno a skupinu
- Zadanie obhajujeme osobne na cvičení č. 12 alebo 13

Hodotenie ako pri zadaní 7

# Formát Karlovho sveta

[Program na generovanie Karlovho sveta](/static/files/createworld.c)

[Podrobný opis formátu Karlovho sveta](http://it4kt.cnl.sk/c/zap/#!/api)

Tu sa nachádza opis súboru Karlovho sveta v súbore .kw
Vzorové súbory môžete získať zo stránky tutoriálu číslo 1.
Súbor sveta potom upravíte pomocou textového editora.

Každý riadok opisuje jeden objekt. Položky na riadku sú oddelené medzerami.
Počiatočný smer Karla alebo smer prekážky sa udáva v svetových stranách N (hore) S (dole) W (na ľavo) E (na pravo).


Prvý riadok obsahuje rozmer sveta, počiatočnú Karlovu pozíciu, Karlov smer a počet značiek v batohu vo formáte:

```
rozmer_x rozmer_y karol_x karol_y karol_smer počet_žetónov_v_batohu
```

Riadky začínajúce sa W opisujú pozíciu prekážky vo formáte:

```
W pozícia_x pozícia_y smer_prekážky
```

Riadky začínajúce sa B opisujú pozíciu žetónu vo formáte:

```
B pozícia_x pozícia_y počet žetónov
```



# Nástroje pre prácu doma

- [Virtuálny stroj](http://it4kt.cnl.sk/c/zap/#!/2016-ZS%252Fproblemset.00)
- Klient pre pripojenie sa na školský server [Putty](http://www.chiark.greenend.org.uk/~sgtatham/putty/)
- Vývojové prostredie [Dev-C++](http://orwelldevcpp.blogspot.sk/) pre Windows 
- Kreslenie vývojových diagramov a generovanie C++ kódu [Flowgorithm](http://www.flowgorithm.org/)
- Linux na doma [Ubuntu](http://www.ubuntu.com/download/desktop)


# Pomôcka pre editor Vim

- Esc - Normálny mód
- i - vkladací mód
- a - koniec riadka a vkladací mód
- v - vizuálny (označovací) mód
- V - riadkový vizuálny mód
- y -kopíruj (vo vizuálnom móde)
- x - vyber (vo vizuálnom móde)
- = - uprav odsadenie, uprac kód (vo vizuálnom móde)
- yy - kopíruj riadok
- dd - vymaž riadok
- dw - vymaž slovo
- P - vlož
- ZZ - ulož a skonči
- / - vyhľadávanie
- \* - vyhľadávanie aktuálneho slova alebo mena
- G choď na koniec súboru
- :2 choď na riadok číslo 2
- :w - ulož
- u - undo
- Crtl-R - redo
- :make stairs - prelož program stairs
- :!./stairs.run - spusti program stairs



# Návod na používanie siete eduroam

1. Prečítajte si [návod](https://nastavenia.tuke.sk/wifi/prirucka-pouzivatela)
1. Nastavte si [WiFi heslo](https://identity.tuke.sk) (View and Edit Profile)
1. Vaše meno je vo formáte ab123cd@tuke.sk

# Podmienky zápočtu

20 bodov za zápočet

- Zadanie 1:  Robot Karel, odovzdanie v 5. týždni, 6 bodov
- Zápočtovka : (Z prvých dvoch prednášok), 8. týždeň,  8 bodov
- Zadanie 2 : (Hangman) 12. týždeň, 6 bodov

- Maximálne 3 ospravedlnené neúčasti.
- Získanie aspoň 11 z 20 možných bodov.
- Podrobné [podmienky na zápočet a skúšku](http://it4kt.cnl.sk/c/zap/#!/about)
