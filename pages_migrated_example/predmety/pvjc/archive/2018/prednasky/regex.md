# 8\. Regulárne výrazy

# Úvod

Často potrebujeme spracovať veľké množstvo textu:

  - overiť vstup od používateľa

  - vypracovať štatistiku z logov

# Čo je to regulárny výraz

Śablóna reťazca

Umožňuje odpovedať na otázky typu:

  - Môže byť reťazec e-mail?

  - Kde sa v reťazci nachádza dátum?

# Vyhľadávanie šablóny

Zistenie, či reťazec vyhovuje šablóne alebo nie

Šablónu reťazcov nazývame regulárny výraz

Šablónu zapíšeme v špeciálnom jazyku

# Doménovo-orientovaný jazyk

špeciálny zápis, ktorý vyjadruje skupinu reťazcov

Existuje veľa nekompatibilných implementácií:

  - PCRE (Perl)

  - [Regex.h](http://pubs.opengroup.org/onlinepubs/7908799/xsh/regex.h.html)
    POSIX implementácia (pre Unixové OS)

  - grep

# Na čo je to dobré

  - Vyhľadávanie v textových dátach

  - Validácia vstupu od používateľa

Môžeme hľadať:

  - dátum a čas

  - e-mail alebo URL

  - prihlasovacie meno v určivom formáte

  - číslo kreditnej karty alebo číslo učtu

# Operácie s regulárnymi výrazmi

  - vyhľadávanie vzoru — Kde sa nachádza podreťazec?

  - validácia reťazca — Vhovuje reťazec vzoru?

# Online Tester

<https://regex101.com/>

# Vyhľadávanie reťazca

ab ide za sebou

ab

**ab**cd**ab**cd**ab**cd**ab**cd**ab**cd**ab**cd

# Množina znakov

Na druhom mieste môže byť b alebo c

    a[bc]

ffaf**ac**ffff**ab**fff**ac**ggg

"af" nevyhovuje

# Množina znakov s rozsahom

    a[0-9][c-d]

a, za ním číslo a za ním c,d alebo e.

xx**a1c**yyy**a5d**yya1qqqq

a1q nevyhovuje

# Ľubovoľný znak

Za a môže byť ľubovoľný znak

``` 
a.
```

fff**ac**f**af**ff**ab**fff**ac**ggga

a na konci nevyhovuje

# Opakovanie nula až jeden krát

Za a môže byť b, ale nemusí

    ab?

fffff**ab**ffff**a**fff

# Opakovanie veľa krát

Za a môže byť hocikoľko b

    ab*

ff**abbbbbbbbbbb**ffff**ab**ff**a**f

Za a môže byť jedno alebo hocikoľko b

    ab+

ff**abbbbbbbbbbb**ffff**ab**ffaf

# Opakovanie x až y krát

Za a je bb, bbb alebo bbbb

    ab{2,4}

fffabfff**abb**ffff**abbbb**bbfff

# Koniec a začiatok reťazca

    ^abc

**abc**ffffabcffffabc

    abc$

abcffffabcffff**abc**

# Skupiny

Opakovanie časti regulárneho výrazu

    zz(a[a-z])+

ffff**zzabacadaf**ffffzzaff

# Skupiny

Skupina je "výsledok" v rámci výsledku.

Zachytíme dátum a všetky jeho časti

    ([01]?[0-9])\.([01]?[0-9])\.([12][0-9][0-9][0-9])

  - Prvá skupina: celý dátum

  - Druhá skupina: deň

  - Tretia skupina: mesiac

  - Štvrtá skupina: rok

fffff**1.2.2018**fffffff

# Špeciálne znaky

Niektoré znaky v Regex majú špeciálny význam

Pre zrušenie špeciálneho významu treba použiť \\

    aaa\(abc\)\+

# Príklady na Regex

E-mail

    [a-z.]{3,20}@[a-z]{3,20}\.[a-z]{2,4}

Dátum

    ([01]?[0-9])\.([01]?[0-9])\.([12][0-9][0-9][0-9])

URL

    [-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)

<https://stackoverflow.com/questions/3809401/what-is-a-good-regular-expression-to-match-a-url>

# Bibliografia

  - <https://www.codeproject.com/Questions/275223/Regular-expressions-using-regex-h>

  - <https://gist.github.com/ianmackinnon/3294587>

# Koniec
