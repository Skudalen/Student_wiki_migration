Tutoriál č. 2

V druhom bloku sa naučíme využívať pamäť počítača.

Potrebné znalosti z predošlého tutoriálu.

Naučíte sa:

  - Je možné uložiť hodnotu a tú neskôr použiť

  - Každá hodnota má dátový typ.

  - Dátové typy je možné meniť, má to ale vedľajšie efekty.

  - Výpis premennej v rôznom formáte

  - Rovnaký typ je možné vypisovať rôznymi spôsobmi

  - aj číslo s desatinnou čiarkou vieme zapisovať rôznym spôsobom

  - Čítať dokumentáciu funkcie printf

# Celočíselná premenná

V prvom kroku upravíme náš jednoduchý program:

``` c
#include <stdio.h>

int main(){
    int pocitadlo  = 7;
    printf("Ahoj svet\n",pocitadlo);
    return 0;
}
```

Pridali sme riadok, pomocou ktorého sme vytvorili pamäťové miesto s
názvom "pocitadlo". Číslo v pamäťovom meiste vieme podľa ľubovôle
meniť, preto ho nazývame **premenná**.

Pozrime sa bližšie na príkaz pomocou ktorého vytvárame premennú:

    int pocitadlo  = 7;

Prvá vec, ktorú si všimneme je slovíčko **int**. Týmto slovičkom
označujeme **dátový typ** s ktorým pracujeme. Dátových typov je
niekoľko, v tomto prípade pracujeme c celými číslami (integer).
Celočíslelný dátový typ nám umožňuje pracovať s celými číslami.

Druhým slovíčkom za dátovým typom je **názov premennej**. Názov
premennej funguje podobne ako menovka na poštovej schránke alebo názov
políčka vo formulári. Pomocou názvu premennej vykonávame všetky
operácie.

Tretím slovíčkom na radku je symbol =. V klasickom matematickom zápise
to znamená znamienko rovnosti. V zápise jazyka C je ale význam úplne iný
a znamená operáciu **priradenia**. V tomto prípade sa do premennej s
názvom pocítadlo priradí (zapíše) hodnota 7.

# Výpis premennej

To, že si vieme zapamätať nejaké číslo je síce skvelé, ale samo o sebe
zbytočné. Aby boli premenné naozaj užitočném potrebujeme s premennou
vykonávať nejaké operácie. Pozrime sa bližšie na riadok s príkazom na
výpis an obrazovku a modifikujem ho tak, aby vypisoval aj hodnotu
premennej:

    printf("Počítadlo má hodnotu %d\n", pocitadlo);

V riadku s príkazom na výpis správy sme za čiarku pridali ďalší argument
s menom premennej ktoú máme zahrnúť do výpisu. Znaky medzi úvodzovkami
obsahujú správu ktorá sa má vypísať a znaky, ktoré zastupujú hodnotu
premennej na výpis. Zástupné znaky vyjadrujú akým spôsobom sa má
premenná vypísať, v tomto prípade "%d" znamená výpis vo forme celého
čísla.

\#=== Úloha na vyriešenie:

Preštudujte si formátovacie reťazce pre funkciu printf a vypíšte hodnotu
premennej na minimálne zadaný počet miest, chýbajúce znaky doplňte
nulami.

# Inicializácia premennej

Skúste upraviť program nasledovným spôsobom (vynecháme operáciu
priradenia):

``` c
#include <stdio.h>

int main(){
    int pocitadlo;
    printf("Ahoj %d\n",pocitadlo);
    return 0;
}
```

Zistili sme, že na prvý pohľad síce program pracuje normálne, ale nie je
jasné aká hodnota bude v premennej počítadlo.

Keďže sme žiadnu hodnotu do premennej nepriradili a v ďalšom riadku túto
neznámu hodntu využívame, program sa správe nepredvídateľné. Ak do
premennej žiadnu hodnotu nepriradíme tak jej hodnota závisí od toho, akú
pamäť nám operačný systém pridelil. V premennej môže byť hodnota nula,
ale aj akákoľvek iná hodnota ktorú nevieme predvídať. Na skutočnosť, že
pracujeme s nedefinovanou hodnotou nás ale program nevie upozorniť a
vyzerá to tak, že je všetko v poriadku. Je zospovednosťou programátora
aby sa vyhol takýmo situáciám a využíval postupy a nástroje ktoré tomu
zabránia.

# Dátový typ

Dátový typ definuje možnosti a obmedzenia premennej s ktorou pracujeme.
Premenná funguje podobne ako obrazovka na kalkulačke. Obrazovka na
kalkulačke má určité obmedzenia ktoré sa podobajú obmedzeniam dátového
typu - na kalkukulačke môžeme pracovať s číslami, ale nie s písmenami.
Číslo na kalkulačke môžeme prečítať alebo ho zmeniť. Podľa typu
kalkulačky s ním môžeme vykonávať sadu operácií - spočítavanie alebo
násobenie.

Do teraz napísaný program nám umožňuje prácu iba s celočíselnými
hodnotami. Do celočíselnej premennej nie je možné uložiť hodnotu s
desatinnou čiarkou. Pokiaľ sa o to pokúsime, hodnota za desatinnou
čiarkou sa zanedbá a dôjde k zakorúhlenu smerom nadol. Na túto
skutočnosť nás kompilátor nemusí upozorniť.

Modifikujme náš program:

``` c
#include <stdio.h>

int main(){
    int pocitadlo = 1.1;
    printf("Ahoj %d\n",pocitadlo);
    return 0;
}
```

Aká hodnota sa vypíše?

Zmeňme formát výpisu premennej na číslo s desatinnou čiarkou:

``` c
#include <stdio.h>

int main(){
    int pocitadlo = 1.1;
    printf("Ahoj %f\n",pocitadlo);
    return 0;
}
```

Pozitívna zmena nenastala, lebo stále platia obmedzenia pre celočíselný
dátový typ. Na to aby sme správne vedeli pracovať s číslom s desatinnu
čiarkou, musíme použiť vhodný dátový typ:

``` c
#include <stdio.h>

int main(){
    float pocitadlo = 1.1;
    printf("Ahoj %f\n",pocitadlo);
    return 0;
}
```

Dátový typ premennej a formát výpisu na obrazovku sú dve rozdielne veci.
Aj keby sme zmenili formátovaciu značku na %d, obsah premennej pocitadlo
to neovplyvní.

# Operácie s dátovými typmi

Celočíselný dátový typ (int) je vhodný najmä ako počítadlo alebo na
uchovávanie indexov. Nie je veľmi vhodný na matematické operácie ako
napr. násobenie alebo delenie. Výsledkom delenia dvoch celých čísel je
reálne číslo, a túto skutočnosť musíme brať do úvahy. Môžeme si to
vyskúšať na jednoduchom matematickom programe, ktorý vykonáva operáciu
delenia (/):

``` c
#include <stdio.h>

int main(){
    int vysledok = 5 / 2;
    printf("Ahoj %f\n",pocitadlo);
    return 0;
}
```

Keďže premenná vysledok má celočíselný dátový typ, je jasné, že výsledok
nebude správny. Navyše, nepomôže ani intuitívna oprava:

``` c
    float vysledok = 5 / 2;
    printf("Ahoj %f\n",pocitadlo);
```

Dôvodom je to, že podľa štandardu je výsledkom delenia dvoch celých
číslel opäť celé číslo, takže automaticky dochádza k zaokrúhľovaniu.
Tento proces, keď prekladač zmení dátový typ bez nášho dovolenia sa
nazýva **implicitná dátová konverzia**. Do premennej, ktorá je vhodná
na uloženia čísla s desatinnou čiarkou (typ float) sa uloží už
zaokrúhlená hodnota. Prekladač jazyka C musíme presvedčiť, že delíme
čísla s desatinnou čiarkou:

``` c
    float vysledok = 5.0 / 2.0;
    printf("Ahoj %f\n",pocitadlo);
```

Teraz to už funguje správne.

# Typová konverzia

Matematické operácie vieme vykonávať aj s obsahom premennej, ktorý sme
si zapamätali v predošlých krokoch. Stačí nahradiť číselné hodnoty v
predošlom príklade názvami premenných, ktoré sme si inicializovali pred
tým.

``` c
    float podiel = delenec / delitel;
    printf("Ahoj %f\n",pocitadlo);
```

Samozrejme, musíme definovať premenné "deliteľ" a "delenec", t.j.
priradiť im vhodný dátový typ a počiatočnú hodnotu. Problém s dátovými
typmi platí aj keď pracujeme s hodnotami, kotré sú uložené v premenných.
Navyše, prvý pohľad na riadok, kde priradíme hodnotu do premennej
"podiel", nám nič nepovie o tom, či operácia prebehne správne. Aby sme
si boli istí, že delenie prebehne správne, musíme splniť tieto
predpoklady: - obidva operandy musia mať typ s desatinnou čiarkou -
deliteľ nesmie byť nula.

Keby sme chceli správne deliť dva celé čísla, nemusíme dostať správny
výsledok:

``` c
    int delenec = 5;
    int delitel = 2;
    float podiel = delenec / delitel;
    printf("Ahoj %f\n",pocitadlo);
```

# Úloha na precvičenie

Čo sa stane ak bude deliteľ nulový? Čo sa stane, ak budeme ďalej narábať
s výsledkom delenia nulou?

# Vyhodnotenie operácií

Aby sme si boli istý, že delenie dvoch premenných bolo správne, musíme
vykonať tzv. **explicitnú typovú konverziu**:

``` c
    int delenec = 5;
    int delitel = 2;
    float podiel = (float)delenec / (float)delitel;
    printf("Ahoj %f\n",pocitadlo);
```

Typová konverzia je ďalšia operácia s premennými, ktorú pozná jazyk C.
Do zátvorky uvededieme typ do ktorého chceme meniť. Prekladač vytvorí
dočasné pamäťové miesto so zadaným dátovým typom do ktorého uloží
hodnotu za zátvorkou. Toto dátové miesto s novým typom sa potom použije
pri ďalších operáciach vo výraze.

Operácia priradenia (=) je vyhodnocovaná v určitom poradí. Najprv sa
vyhodnotí výraz (expression) na pravej strane a výsledok sa uloží do
premennej, ktorej názov sa nachádza na ľavej strane (lvalue). Iné
pravidlá platia pre vyhodnocovanie operácie delenia. Najprv sa vyhodnotí
výraz na ľavej strane, potom na pravej strane.

# Kopírovanie hodnoty

Operácia priradenia je ekvivalentná operácii kopírovaniu hodnoty.
Hodnotu z jednej premennej môžeme nakopírovať do druhej premennej a tam
s ňou pracovať bez toho, aby to ovplyvnilo pôvodnú premennú. Napr.
môžeme napísať:

``` c
    int povodna = 5;
    int nova = povodna;
    printf("Ahoj %d\n",nova);
```

Zistili sme, že hodnota premennej povodna sa nakopírovala do premennej
nova. Že ide naozaj o operáciu kopírovania si môžeme overiť tým, že
zmeníme hodnotu pôvodnej premennej a sledujeme, či to ovplyvní hodnotu
novej premennej.

``` c
    int povodna = 5;
    int nova = povodna;
    printf("Nova hodnota je  %d\n",nova);
    printf("Povodna hodnota je  %d\n",povodna);
    povodna = 4;
    printf("Po priredeni je povodna hodnota  %d\n",povodna);
    printf("a nova hodnota stale je  %d\n",nova);
```
