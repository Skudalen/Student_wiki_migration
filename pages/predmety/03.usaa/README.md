---
title: 'Údajové štruktúry a algoritmy'
---

# Údajové štruktúry a algoritmy

Zimný semester 2020/21, [Katedra elektroniky a multimediálnych telekomunikácií](https://kemt.fei.tuke.sk) pre študentov programu "Počítačové siete" a "Počítačové modelovanie".

Prednášky: Ing. Daniel Hládek PhD. 

Cvičenia a konzultácie: Ing. Daniel Hládek PhD., Ing. Maroš Baumgartner, Ing. Anton Buday

Výuka prebieha cez skupinu [MS TEAMS](https://teams.microsoft.com/l/team/19%3a695c39fc34ec4693843336d5cd1dfd4c%40thread.tacv2/conversations?groupId=807d66aa-ff22-4109-bb1e-dca0d3f6e41a&tenantId=1c9f27ef-fee6-45f4-9a64-255a8c8e25a5) a osobnou konzultáciou v určenom čase.

!! Všetky cvičenia sa budú konať virtuálne


## Hodnotenie

- Zápočet 40b, min. 21 bodov, povinná účasť na osobných konzultáciách podľa rozvrhu
  - Zadanie 6 x 4b
  - Obhajoba 2 x 8b
  - Aktivita: 0 až 10 bodov
- Skúška 60b, min. 31

!! Ak získate počas semestra min. 40 bodov  získavate bonus 40 bodov ku skúške.

## Dôležité odkazy

- [Správa zdrojových kódov](https://git.kemt.fei.tuke.sk)
- [Systém pre automatické hodnotenie](https://traktor.kemt.fei.tuke.sk)
- [Študijné materiály](/info/materialy)
- [Predbežný plán semestra](./plan)

## Týždeň 1

- Prednáška: Zložitosť algoritmov, vyhľadávanie
   - [Slajdy](./prednasky/algoritmus)
   - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr1.mp4)
- Cvičenie: 
   - Domáca úloha: [CV1: vyhľadávanie](./cvicenia/search) 
   - [Video pondelok](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20cv1-pondelok.mp4) práca so systémom GIT a Traktor, načítanie reťazcov
   - [Video utorok](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20cv1-utorok.mp4) ladenie pomocou Valgrindu
- Ďalšie materiály:
   - [Etický kódex](/info/kodex)
   - [Prihlásenie sa na server Omega a práca so systémom GIT](/info/git)
   - [Editovanie programu pomocou editora VIM](/info/vim)
   - [Ladenie programu pomocu Valgrind a gdb](/info/valgrind)
   - [Základy práce s príkazovým riadkom](/info/bash)

## Týždeň 2

- Prednáška:  Triedenie 
  - [Slajdy](./prednasky/sort)
  - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr2.mp4)
  - Príklad na rekurzívne bublinkové triedenie [recursive_bubble.c](./prednasky/sort/recursive_bubble.c)
  - Príklad na Fibonacciho postupnosť [fibonacci.c](./prednasky/sort/fibonacci.c)
- Cvičenie: 
  - Domáca úloha CV2: [Triedenie](./cvicenia/sort)

## Týždeň 3

- Prednáška:  Údajové štruktúry, zásobník
    - [Slajdy](./prednasky/stack)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr3.mp4)
    - [Príklad dynamický zásobník](./prednasky/stack/pr161019.c)
- Cvičenie: 
    - Domáca úloha CV3: [Poľská kalkulačka](./cvicenia/stack)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20cv3-pondelok.mp4)
- Odovzdanie: CV1

## Týždeň 4

- Prednáška:  Spojkový zoznam
    - [Slajdy](./prednasky/linked)
    - Príklad [linkedlist.c](./prednasky/linked/linkedlist.c)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr4.mp4)
- Cvičenie:
    - Vypracovanie Aktivity 2
- Odovzdanie: CV2

## Týždeň 5

- Hešovacia tabuľka
    - [Slajdy](./prednasky/hash)
    - Príklad na hešovaciu tabuľku so zreťazením [chainedhash.c](./prednasky/hash/chainedhash.c)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr5.mp4)
- Cvičenie: 
    - Domáca úloha CV5: [Spojkový zoznam](./cvicenia/linked)
- Odovzdanie: CV3

## Týždeň 6

- Prednáška: Binárny vyhľadávací strom
    - [Slajdy](./prednasky/tree)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr6.mp4)
    - Príklad z prednášky - binárny strom na počítadlo [pocitadlo.c](./prednasky/tree/pocitadlo.c)
- Cvičenie:
    - Domáca úloha CV6: [Hešovacia tabuľka](./cvicenia/hash)
- Odovzdanie: Aktivita 2

## Týždeň 7

! Musíte mať funkčný mikrofón


- Prednáška: Binárny vyhľadávací strom
    - [Slajdy](./prednasky/balanced)
    - [Príklad AVL strom](./prednasky/balanced/avl2.c)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr7.mp4)
- Obhajoba CV1, CV2, CV3
    - Zdrojové kódy môžete ešte upravovať, prezentuje sa posledná odovzdaná verzia na GIT.
    - Kompletnosť: 1 chýbajúce riešenie -2 body, 2 chýbajúce riešenia -6 bodov, 3 chýbajúce riešenia -8 bodov. Neoriginálne riešenie je hodnotené ako chýbajúce.
    - Obhajoba 2 riešení ktoré vyberie cvičiaci:
        - Zodpovedanie otázky z odovzdaných zdrojových kódov Viete rýchlo a zrozumiteľne reagovať na otázku? (3b)
        - Hodnotenie úpravy zdrojových kódov a návrhu algoritmu, dokumentácia, použitie globálnych premenných. (1B)
- Odovzdanie: CV5

## Týždeň 8

- Prednáška: Binárna kopa
    - [Slajdy](./prednasky/heap)
    - Príklad na binárnu kopu [heap.c](./prednasky/heap/heap.c)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr8.mp4)
- Cvičenie: Binárny strom
    - Domáca úloha CV8: [Expert z bufetu](./cvicenia/tree).
- Odovzdanie: CV6

## Týždeň 9

- Prednáška: Kompresia a Huffmanovo kódovanie
  - [Slajdy](./prednasky/compression)
  - Príklad na zostavenie Huffmanovho stromu [huffman3c](./prednasky/compression/hufencode3.c)
  - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr9.mp4)
- Cvičenie: Binárna kopa
  - Aktivita 3: Kopa zábavy (cez Traktor)
  - Aktivita 4: [Veľa otázok](https://zp.kemt.fei.tuke.sk/topics/question/navod). 3 body za 100 otázok a odpovedí.


## Týždeň 10

- Odovzdanie: CV8
- Prednáška: Spracovanie prirodzeného jazyka
  - [Slajdy](./prednasky/nlp)
  - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr10.mp4)
- Cvičenie: Aktivita 5 - Telegrafista (cez Traktor)

## Týždeň 11

- Prednáška: Kompresia LZ77 a LZ78
  - [Slajdy](./prednasky/compression2)
  - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr11.mp4)
  - Príklad [lz77.c](./prednasky/compression2/lz77.c)
  - Príklad [lz78.c](./prednasky/compression2/lz78.c)
  - Príklad [runlength.c](./prednasky/compression2/runlength.c)
- Cvičenie:
    - Obhajoba CV5,CV6,CV8
- Odovzdanie:
    - Aktivita 3


## Týždeň 12

- Prednáška:
    - [Príklady na skúšku](./skuska)
    - [Video](https://files.kemt.fei.tuke.sk/predmety/usaa/videa/usaa20pr12.mp4)
    - https://en.wikipedia.org/wiki/Turing_machine
    - https://en.wikipedia.org/wiki/Brainfuck
- Cvičenie:
    - Obhajoba CV5,CV6,CV8
- Odovzdanie:
    - Aktivita 4


## Týždeň 13

- Cvičenie:
    - Zápočty

