# Programovanie v jazyku C
pre študentov programu "Počitačové siete" na [Katedre elektroniky a multimediálnych telekomunikácií](http://kemt.fei.tuke.sk).


Prednášky:

- Ing. Daniel Hládek PhD.

Cvičenia:

- Ing. Daniel Hládek PhD.
- Ing. Stanislav Ondáš PhD.
- Ing. Slavomír Gereg
- Ing. Renát Haluška

## Oznamy
- Odovzdanie Konečnej hry bude 5.6., počíta sa ako domáca úloha pre získanie DU Bonus
- Obhajoba Konečnej hry bude 9.6. o 9:30 cez MS Teams

## Dôležité odkazy

- [Správa zdrojových kódov](https://git.kemt.fei.tuke.sk)
- [Systém pre automatické hodnotenie](https://traktor.kemt.fei.tuke.sk)
- [Študijné materiály](../../info/materialy)

## 1. týždeň

- Prednáška:
    - [Modulárne programovanie](./prednasky/modular)
    - [Etický kódex](../../info/kodex)
- Cvičenie:
    - [Vstup po znakoch](./cvicenia/inout)
    - [Oboznámte sa s GITom](/info/git)
    - [Programátorské minimum](../../info/minimum)
    - [BASH tutoriál](../../info/bash)
    - [VIM Tutoriál](/info/vim)
- Ďalšie materiály:
    - [Interaktívny BASH tutoriál](https://www.katacoda.com/kulinacs/courses/linux/filesystem)
    - [VIM konfigurák](https://github.com/hladek/vimrc)
    - [WiFi cez notebook](/info/eduroam)

## 2. týždeň

- Prednáška: [Smerníky](./prednasky/pointer)
- Cvičenie: Formátovaný vstup a výstup - [Limonádový pohár](./cvicenia/limonada)

## 3. týždeň

- Prednáška: [Štruktúry](./prednasky/struct)
- Cvičenie:
    - **vstupná zápočtovka** (7B)
    - Aktivita 1 (odovzdanie cez git do `a1/program.c` za 7 bodov)
- Odovzdanie: domácej úlohy 1

Úlohou zápočtovky bude zostaviť kalkulačku, ktorá zvládne delenie celých čísel a ošetrený vstup. Na prípravu si stačí prečítať a vyskúšať [Programátorské minimum](../../info/minimum).

## 4. týždeň

[Usmernenie k výuke](http://www.tuke.sk/wps/portal/tuke/university/news/koronavirus/!ut/p/z1/04_Sj9CPykssy0xPLMnMz0vMAfIjo8zifRxNTYy8TAx83Z093AwcA0IDA00dnQz83Y30w8EKDHAARwP9KPz6vQgpALrAqMjX2TddP6ogsSRDNzMvLV8_Iju_KB_k0KLSYqATosCGmBiaOBqagAwxD3IxcLQMDDUKtggzNLAwhiqA2-JvYWYEtMUzxM_FxDfAz9QAqgCPNwpyI6p80oI90x0VFQEDAt0r/dz/d5/L0lDUmlTUSEhL3dHa0FKRnNBLzROV3FpQSEhL3Nr/)

Práca na doma:

- Preštudujte si: [Dynamické polia](./prednasky/dynamicarray),
- Príklad na dynamické pole [dynamic.c](./prednasky/dynamicarray/dynamic.c)
- Vypracujte cvičenie: [Štruktúry, práca s časom](./cvicenia/nextweek)
- Odovzdanie: domácej úlohy 2

## 5. týždeň

Práca na doma:

- Preštudujte si:
    - [Funkcia na načítanie do premennej](../../info/minimum/adresa)
    - [Smerníková aritmetika a práca s reťazcami](../../info/minimum/pole)
    - [Hľadanie chýb práce s pamäťou](../../info/valgrind)
- Pozrite si [video prednášky z predmetu Programovanie](https://www.youtube.com/channel/UCcDMjlmdQIuFgyZIhIXuGcQ) na katedre KPI, Ing. Miroslav Biňas PhD.
- Vypracujte cvičenie a domácu úlohu 4: [Spracovanie reťazca](./cvicenia/math)
- Odovzdanie aktivita 1
- Vypracujte doplňujúce úlohy z Geek for Geeks [Practice](https://practice.geeksforgeeks.org/explore/?category%5B%5D=Arrays&category%5B%5D=Mathematical&category%5B%5D=Strings&company%5B%5D=Amazon&company%5B%5D=Microsoft&company%5B%5D=Adobe&company%5B%5D=Samsung&company%5B%5D=Accolite&difficulty%5B%5D=-2&difficulty%5B%5D=-1&sortBy=submissions)

## 6. týždeň

- Odovzdanie: domáca úloha 3
- Vypracujte cvičenie a domácu úlohu 5: [Anketa](./cvicenia/anketa)
- Virtuálny seminár: štvrtok 26.3 o 9:15  cez skupinu MS TEAMS [Programovanie KEMT](https://teams.microsoft.com/l/team/19%3afccdf41ce7d349a4a499d0156dd60e58%40thread.tacv2/conversations?groupId=a8975a2b-1035-40f6-871e-bd53dab6877f&tenantId=1c9f27ef-fee6-45f4-9a64-255a8c8e25a5)
- Naštudujte si:
    - [Smerníková aritmetika a pole smerníkov](./prednasky/pointerarray)
    - Príklad na [triedenie riadkov](./prednasky/pointerarray/sortlines.c) pomocou statického poľa smerníkov.
    - Príklad na [triedenie slov](./prednasky/pointerarray/sortwords.c) pomocou dynamického poľa smerníkov.
    - Príklad na [triedenie slov](./prednasky/pointerarray/static-sortwords.c) pomocou dvojrozmerného poľa.

## 7. týždeň

- Odovzdanie: domáca úloha 4
- Vypracujte [Cvičenie a domácu úlohu 6](./cvicenia/triedic)
- Naštudujte si:
    - [Spojkový zoznam](./prednasky/linkedlist)
    - [Príklad na spojkový zoznam 1](./prednasky/linkedlist/linkedlist.c)
    - [Príklad na spojkový zoznam 2](./prednasky/linkedlist/linkedlist2.c)
- Virtuálny seminár: piatok 3.4. o 9:30 cez skupinu MS TEAMS [Programovanie KEMT](https://teams.microsoft.com/l/team/19%3afccdf41ce7d349a4a499d0156dd60e58%40thread.tacv2/conversations?groupId=a8975a2b-1035-40f6-871e-bd53dab6877f&tenantId=1c9f27ef-fee6-45f4-9a64-255a8c8e25a5)

## 8. týždeň

- Odovzdanie: Domáca úloha 5
- Naštudujte si:
    - [Binárny vyhľadávací strom](./prednasky/bst)
    - [Makefile tutoriál](/info/makefile)
- Vypracujte: Aktivita č. 2 - [Tomáš a Juraj](./cvicenia/tomandjerry)

Aktivita č. 2 sa počíta zároveň ako náhradná alebo opravná zápočtovka č. 1. Hodnotiť sa bude ručne. Odovzdanie pomocou systému Traktor do Vášho GIT repozitára do súboru `a2/game.c` za max. 7 bodov.

Aktivita č. 2 Vám zároveň pomôže pri vypracovaní domácej úlohy č. 7 a finálnej úlohy s obhajobou.

## 9. týždeň

Odovzdanie: Domáca úloha č. 6

- Virtuálny seminár: štvrtok 16.4. o 9:30 cez skupinu MS TEAMS [Programovanie KEMT](https://teams.microsoft.com/l/team/19%3afccdf41ce7d349a4a499d0156dd60e58%40thread.tacv2/conversations?groupId=a8975a2b-1035-40f6-871e-bd53dab6877f&tenantId=1c9f27ef-fee6-45f4-9a64-255a8c8e25a5) [záznam seminára](https://web.microsoftstream.com/video/d175acb6-b57e-4a28-99cf-20aa819a079d)

## 10. týždeň

Odovzdanie: Aktivita 2

- Vypracujte cvičenie [Pán hadov](./cvicenia/snake) (domáca úloha č. 7)
- Virtuálny seminár: piatok 24.4. o 9:30 cez skupinu MS TEAMS [Programovanie KEMT](https://teams.microsoft.com/l/team/19%3afccdf41ce7d349a4a499d0156dd60e58%40thread.tacv2/conversations?groupId=a8975a2b-1035-40f6-871e-bd53dab6877f&tenantId=1c9f27ef-fee6-45f4-9a64-255a8c8e25a5)

## 11. týždeň

- Vypracujte [Poslednú hru](./cvicenia/finalgame) (finálne zadanie s prezentáciou za 30b).
- Dokončite hru Snake do hrateľnej podoby. (Aktivita 3)

## 12. týždeň

- Odovzdanie: Domáca úloha 7
- Virtuálny seminár: pondelok 4.5. o 9:30

## Skúškové obdobie

- Zápis hodnotení do systému Traktor: 29.5.2020
- Odovzdanie "Konečnej hry": 5.6.2020
- Záverečná obhajoba: 9.6.2020



## Plán semestra

|     | Prednáška                  | Odovzdanie | Cvičenie                      |
|---  |---                         |---       |---                              |
|  1. | Modulárne programovanie    |          | 1. CAPS LOCK  Vstup po znakoch  |
|  2. | Smerníky, polia            |          | 2. Limonádový pohár Formátovaný vstup |
|  3. | Štruktúry                  | DU1, Z1  | Zápočtovka 1. , Build, A1 BFU   |
|  4. | Dynamické pole             | DU2      | 3. O Týždeň, štruktúry          |
|  5. | Triedenie                  | A1       | 4. Matikár, Parsovanie textu    |
|  6. | Pole smerníkov             | DU3      | 5. Anketa, Triedenie štruktúr   |
|  7. | Spojkový zoznam            | DU4      | 6. Triedič, Množina             |
|  8. | Binárny vyhľadávací strom  | DU5      | A2: Curses 1 Tomáš a Juraj      |
|  9. | - (Veľkonočný týždeň)      | DU6      | -          |
| 10. | - (virtulány seminár)      | A2       | 7. Pán Hadov               |
| 11. | -       | -        | DU8 - Posledná hra,A3 Hra Snake |
| 12. | -  (virtulány seminár)        |               | DU7      | -          |
| 13. | -          |               | A3       |  A3 Snake  |
| Skúškové | -     | Obhajoba DU8  | final    |            |

## Zhrnutie  hodnotených aktivít

|    | Spolu        | Body        | Poznámka |
|----|--------------|-------------|----------|
| DU | domáca úloha 1-4 | 4 x 7B = 28 | vypracovanie doma |
| DU | domáca úloha 5-7 | 3 x 10B = 30 | osobná obhajoba podľa potreby |
| Z1 | zápočtovka 1 | 7B          | vypracované na cvičení č.3  |
| Z2 | domáca úloha 8 | 30B         | obhajoba vlastnej hry formou telekonferencie |
| A  | aktivita     | cca 3 x 7B  | rôzne úlohy |
|    | DU Bonus     | 14B         | min. 5 domácich úloh za min. 50% |
