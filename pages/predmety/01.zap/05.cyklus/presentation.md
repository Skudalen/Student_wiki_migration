---
title: Cykly a rekurzia
published: true
---
# Cykly a rekurzia

Ing. Daniel Hládek PhD.

---
# Obsah prednášky

- Sekvenčný prístup: Výrazy a príkazy 
- Iteratívny prístup: Nasledovanie steny
- Rekurzívny prístup: Fibonacciho postupnosť
- Proces prekladu programu - preprocessor (define, loop)

---
# Algoritmus

[note]
- https://en.wikipedia.org/wiki/Algorithm
- https://www.khanacademy.org/computing/computer-science/algorithms/intro-to-algorithms/v/what-are-algorithms
[/note]

Algoritmus je dobre definovaná postupnosť krokov, ktoré po splnení rovnakých podmienok vedú k dosiahnutie rovnakého výsledku v konečnom čase.

---
 E-mail prednášajúcemu je tiež "algoritmus".

 - vysvetlite kto ste
 - opíšte Váš problém
 - položte konkrétnu otázku
 - uvedte presný dátum

---
# Vlastnosti algoritmu

- Konečnosť
- Rezultatívnosť
- Univerzálnosť


---

Každý algoritmus alebo jeho časť by mala mať definované:

- vstup
- výstup
- podmienky vykonania:
- predpokladaný počiatočný a konečný stav

---
# Návrh algoritmu

Snažíme sa problém "rozbiť" na menšie časti.

---
# Návrh algoritmu v jazyku C

1. Zvoľ potrebné nástroje (funkcie)
1. Vytvor jednoduchý algoritmus
1. Vylepši jednoduchý algoritmus
1. Ak riešenie nestačí, opakuj postup

---
# Prístupy k návrhu algoritmov

- sekvenčný: z postupnosti po sebe nasledujúcich krokov
- iteratívny: z opakujúcej sa časti a ukončovacej podmienky
- rekurzívny: z opakujúcej sa časti ktorá volá samu seba a ukončovacej podmienky

---
# Sekvenčný prístup

- funkcie
- podmienky
- výrazy a príkazy

---

1. Choď doľava
1. Choď rovno
1. Ak sa dá, choď rovno
1. Choď rovno

---
# Príkaz a výraz 

---
# Výrazy

Výraz môže byť súčasťou definície cyklu alebo podmienky.

Výraz sa skladá z operátorov, aritmetických operácií a volaní funkcií.

---
# Operátory

Operátor je funkcia, ale zapisuje sa inak.

Aritmetické operátory:

	+ - * / 
Logické operátory:

	&& || !

[Operátory v jazyku C](https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/CONCEPT/expressions.html)
---
AND: batoh je prázdny a zároveň je cesta voľná:

	beepers_in_bag() && front_is_clear()

---
OR: vidím žetóny alebo je cesta voľná

	beepers_present() || front_is_clear()
    
---
NOT: nemám žiadne žetóny v batohu

	!beepers_in_bag()
	
---


# Výrazy sú vyhodnocované v určitom poradí

- Výraz sa vyhodnocuje z ľava do prava.
- Zátvorka má prednosť
- Súčin má prednosť pred súčtom

---
Napr. Aký je výsledok výrazov:

    2 + 3 * 2
    (2 + 3) * 2
    

[Priorita operátorov](http://en.cppreference.com/w/c/language/operator_precedence)

---
# Výrazy je možné kombinovať

pomocou okrúhlych zátvoriek

	(beepers_in_bag() && front_is_clear()| || beepers_present()


---
# Príkaz (statement) 

je výraz a bodkočiarka.

Výraz je niečo čo po vyhodnotení vracia hodnotu.

	beepers_present() // Výsledok je možné použiť napr. v podmienke.


---

Príkaz niečo okamžite vykoná.

	beepers_present(); // Výsledok sa hneď zabudne

[Výraz vs. príkaz](https://stackoverflow.com/questions/19132/expression-versus-statement)


---
# Break a Continue

**break** skonči cyklus, pokračuj za cyklom

**continue** pokračuj v cykle novým opakovaním

---
# Príklad na break a continue

Choď k stene. Keď nájdeš žetón, tak stoj

```c
while (front_is_clear()){
    step();
    if (beepers_preent()){
    	break; // Spôsobí okmažité ukončenie cyklu
    }
}

```
Choď dopredu a ber všetky žetóny:

```c
while (front_is_clear()){
    step();
    if (!beepers_present()){
    	continue; // Preskočí zvyšok cyklu a pokračuje.
    }
    pick_beeper();
}

```


---
# Iteratívny návrh

---
# Nájdi žetón v bludisku

	0   TURNOFF
     CORNER  FACING  BEEP-BAG  BEEP-CORNER
     (1, 1)   EAST       0         0
    ST.+-----------------------------------------------+
     6 | .   .   .   .   . | . | . | .   .   .   .   1 |
       |----   |   |   +---+   |   +---+   |   |   ----|
     5 | .   . | . | . | .   .   .   . | . | . | .   . |
       |   +---+   |   |   +---+---+   |   |   +---+   |
     4 | . | .   . | . | . | . | . | . | . | .   . | . |
       |   |   ----+---+   |   |   |   +---+----   |   |
     3 | . | .   .   . | .   . | .   . | .   .   . | . |
       |   +---+----   +---+   |   +---+   ----+---+   |
     2 | .   . | .   .   . | . | . | .   .   . | .   . |
       |   +---+   ----+   |   |   |   +----   +---+   |
     1 | > | .   .   . | .   . | .   . | .   .   . | . |
       +-----------------------------------------------+
         1   2   3   4   5   6   7   8   9   10  11  12  AVE.

---
Počiatočné podmienky: 

- Stojím niekde v bludisku, neviem kde. 
- Bludisko je v jednej miestnosti
- Žetón je pri stene miestnosti

---
Ukončovacia podmienka:

stojím na žetóne

---
Algoritmus v slovenskom jazyku

Nájdi najbližšiu stenu a potom podľa ľavej ruky nasleduj stenu, pokiaľ nenájdeš žetón.



---
# Sekvenčné riešenie

- Funguje iba na jednu mapu
- Dlhý "špagetový" kód
- Ťažko sa hľadá chyba

---
# Iteratívne riešenie

Identifikujeme opakujúce sa časti

---
# Iteratívne riešenie

```c
void find_wall(){
    while (front_is_clear()){
        step();
    }
}
```

---
# Algoritmus nasledovania steny

Počiatočná podmienka: Stenu mám pri ľavej ruke

Posuniem sa tak aby som mal zase stenu po ľavej ruke

---
# Algoritmus nasledovania steny

Ak stojím oproti stene, otočím sa doprava => stenu mám na ľavej strane

Pokiaľ nevidím stenu, urobím krok a otočím sa doľava.

---
# Rekurziz

---
# Rekurzia

- https://www.khanacademy.org/computing/computer-science/algorithms/recursive-algorithms/a/recursion
- https://www.cs.utah.edu/~germain/PPS/Topics/recursion.html
- https://en.wikipedia.org/wiki/Recursion_(computer_science)

- opakovanie bez cyklov
- reprezentácia nekonečného množstva objektov konečným počtom pravidiel
- rekurzia sa dá vždy vyjadriť pomocou iterácie


---

# Príklad na fraktál

https://en.wikipedia.org/wiki/Fractal

Fraktál sa vytvára rekurzívne.

Fraktál je štruktúra, ktorá obsahuje menšie kópie samého seba.

- Mrak
- Strom
- Mandelbrotova množina

https://en.wikipedia.org/wiki/Mandelbrot_set

https://www.youtube.com/watch?v=0jGaio87u3A

---
# Fibonacciho postupnosť

[Fibonacci](https://en.wikipedia.org/wiki/Fibonacci_number)

Ďaľšie číslo je súčtom dvoch predchádzajúcich.

	0 1 1 2 3 5 8 13 21 34 55 ....

---
# Naučme robota Karla napísať Fibonacciho postupnosť

- Úloha: Napíšte pomocou Karla Fibonacciho postupnosť.
- Podmienky: Robot Karel sa nachádza v miestnosti s batohom plných žetónov. Stojí na jednom žetóne.
- Konečný stav: Postupnosť je napísaná a nemáme už ďalšie žetóny

---
Riešenie:
1. Polož nula žetónov
1. Na dalšie políčko polož jeden žetón
1. Pokiaľ je miesto, na ďalšie políčko skopíruj žetóny z dvoch predošlých políčok

---
# Kopírovanie žetónov

![Počítadlo](abacus-1866497_1280.jpg)

---

# Rekurzívne kopírovanie n žetónov

čo treba urobiť, aby sme skopírovali n žetónov

---
# Koppírovanie 0 žetónov

Netreba robiť nič.

---
# Kopírovanie 1 žetónu

- Zober žetón
- Polož ho o jedno ďalej
- Vráť sa (máme o jeden žetón menej)
- Polož žetón

---
# Kopírovanie 2 a n žetónov

- Zober žetón
- Polož ho o jedno ďalej
- Vráť sa
- Kopíruj 1 žetón
- Polož žetón

---

# Rekurzívne kopírovanie

1. *Ak je žetón prítomný*, zober ho a prenes na nové miesto, inak skonči.
2. Vráť sa a *kopíruj*.
3. Polož žetón.

---

# Rekurzívna operácia kopíruj žetóny o dva kroky

To isté ako v predošlej funkcii, ale o dva kroky dopredu.


---
# Proces prekladu

1. Preprocessor (definovanie makier a pripojenie hlavičkových súborov s deklaráciami funkcií)
1. Kompilátor (preklad zdrojových súborov do strojového kódu)
1. Linker (spojenie zdrojových súborov a knižníc)

Preprocessor prikladá súbory a definuje makrá

---

# Príkazy preprocesora
	
Príkazy pre preprocesor automatizujú "nájdi a nahraď".

Pomocou príkazov preprocesora definujeme časti kódu, ktoré sa vložia pred prekladom.

```c
// vloží deklarácie zo súboru v aktuálnom adresári
#include "karel.h"
// vloží deklarácie zo súboru v štandardnom adresári (napr. /usr/include)
#include <karel.h> 
```
---
Zaujímavosť: 
	Používanie preprocesora je *metaprogramovanie* - jazyk preprocesora je špeciálny programovací jazyk, pomocou ktorého vytvárame programny. (programujeme program).

---
# Makrá

Pomocou makra môžeme definovať konštantu alebo blok kódu.

```c
#define SPEED 100
```
Každý výskyt `SPEED` v kóde sa nahradí za `100`.

(konštantky sa píšu veľkými písmenami podľa dohody).

---
!!! Nikdy nepoužívajte globálne premenné (ak neviete prečo). !!!

Makro nie je globálna premenná.

---

# Zhrnutie: Makrá

Pri definícii konštánt môžeme využiť makro

```c
#define
```

Preprocesor pomocou 

```c
#include 
```
    
pripája deklarácie funkcií z knižnice. 


---
# Zhrnutie dnešnej prednášky: Návrh algoritmov

- Za akých podmienok bude funkcia fungovať?
- Aký bude stav po ukončení funkcie?

---
# Zachovať pôvodný stav 

(polohu robota, počet žetónov v batohu)
aby navrhnutá funkcia mala minimálne vedľajšie efekty.

# Overiť si  akciu 

---
# White Night Challenge

- Nasleduj stenu rekurzívne
- Počítaj Fibonacci  iteratívne
