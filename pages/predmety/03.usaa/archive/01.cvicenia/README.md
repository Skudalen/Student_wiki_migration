---
title: Cvičenia
published: true
---

# Cvičenia

1. [Vyhľadaj](./search).
2. Samostatná práca na domácej úlohe.
3. [Zotrieď](./sort).
4. [Poľská zásobníková kalkulačka](./stack).
5. Samostatná práca na domácej úlohe.
6. Obhajoba `usaa19cv1`,`usaa19cv3`. Vypracovanie aktivity `usaa19a6`. Odovzdanie cez GIT do repozitára z názvom usaa19a6 do súboru `program.c`, heslo je `usaa19a6`.
7. [Vlak do neba](./linked) - spojkový zoznam.
8. [Pekelná stanica](./hash) - hešovacia tabuľka so zreťazením
9. [Expert zo supermarketu](./tree) - binárny vyhľadávací strom
10. Aktivita "Kopa zábavy". Meno `usaa19a10`, heslo `heapfun`, odovzdanie cez GIT za 4 body.

## Chyby pri práci s pamäťou

Ak sa program pri automatickom hodnotení správa inak ako predpokladáte, signalizuje to 
chybu pri práci s pamäťou. Tento druh cyby sa prejavuje iba za určitých okolností.
Program sa môže predčasne ukončiť so zápornou návratovou hodnotou.

Aby ste sa chybe vyhli:

- vždy si inicializujte alokovanú pamäť napr. pomocou memset.
- vždy si overte úspešnosť načítania reťazca alebo jeho konverzie.
- pri prechádzaní poľa si overte, či nepoužívate hodnoty mimo poľa.
- preložte Váš program s prepínačom `-Wall` a vyriešte všetky varovania.

Aby ste chybu našli:

- preložte Váš program s prepínačom `-g` pre pridanie debugovacích informácií
- použite `valgrind` spolu s programom: `valgrind ./program < test1.txt` a vyriešte všetky upozornenia
- ak program spadne, analyzujte výpis pamäte`core` pomocou debugera `gdb`:

```bash
# Prezime spolu s debug. 
$ gcc -g -Wall ./program.c -o program
# povolime vypis pamate
$ ulimit -c unlimited
# spustime program
$ ./program
Segmentation fault
# Ak spadne, vznikne nam subor core
$ ls
program program.c core.1234
# Pri ladeni sa ocitneme v okamihu ked program spadol
$ gdb ./program ./core.1234
# vieme zistit, na ktorom riadku spadol
bt
```

## Povolenie prístupu na GIT

Tento postup Vám umožní odoslať vypracované zadanie na GIT:

Prihláste sa na Váš pracovný počítač (napr. server omega).

Zadajte príkaz:

```bash
cat ~/.ssh/id_rsa.pub
```

skopírujte obsah súboru do schránky.

Ak sa tam taký súbor nenachádza, zadajte príkaz:

```bash
ssh-keygen
```

!! Nevypĺňajte žiadne hodnoty!

a stále stláčajte ENTER.  Opakujte príkaz `cat`.

Prihláste sa na [GIT](https://git.kemt.fei.tuke.sk).

Nájdite si nastavenia Profile and Settings / Settings / SSH GPG Keys / Add SSH key

Pridajte obsah súboru `id_rsa.pub` do políčka "Content" a ťuknite na "Add Key".

## Postup pri vypracovaní úlohy

- Pozorne si prečítajte návod a zistite si názov úlohy, napr. `NAZOV`.
- Prihláste sa  sa na [GIT](https://git.kemt.fei.tuke.sk/) a vytvorte si prázdny repozitár s rovnakým názvom.
- Prihláste sa na Váš pracovný počítač napr. 

```bash
ssh LOGIN@omega.tuke.sk
```

- Zvoľte vhodný adresár, napr. `usaa2019` kde si budete ukladať vypracované úlohy
- Naklonujte šablónu repozitára:

```bash
git clone git@git.kemt.fei.tuke.sk:USAA2019/NAZOV.git
```

- Zmente aktuálny adresár

```bash
cd NAZOV
```

- Nastavte vzdialený repozitár na Váš, `LOGIN` je Vaše prihlasovacie meno:

```bash
git remote set-url origin git@git.kemt.fei.tuke.sk:LOGIN/NAZOV.git
```

- Vypracujte úlohu
- zadajte prikazy pre odovzdanie riešenia

```bash
git commit -am "Prva verzia"
git push
```

- ak nefunguje odoslanie na git, je potrebné povoliť prístup pomocou verejného SSH kľúča.

## Postup pre získanie hodnotenia úlohy

- Prihláste sa na server [https://traktor.kemt.fei.tuke.sk](https://traktor.kemt.fei.tuke.sk)
- Zvoľte si predmet Údajové štruktúry a algoritmy, heslo je `usaa2019zs`
- Zvoľte si riešenú úlohu
- Kliknite na "Pozri na GIT"
- Počkajte na výsledky automatického hodnotenia.
- V prípade technických problémov kontaktujte prednášajúceho.

## Automatické hodnotenie

Úlohy sa odovzdávajú na systém GIT a hodntia automaticky pomocou systému [Traktor](https://traktor.kemt.fei.tuke.sk).

Automatické hodnotenie je dohoda medzi študentom a pedagógom v ktorej má konečné slovo pedagóg.

Pedagóg kontroluje dodržiavanie etického kódexu osobne a s využitím systému pre overenie zhody.

Na požiadanie je možné prehodnotiť zadanie osobne.

## Kontrola zhody

Zadania prechdzajú kontrolou originality. Vysoké skóre zhody má za následok pridelenie 0 bodov za danú úlohu.


