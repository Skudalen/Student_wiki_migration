---
title:Vetvenie a cykly
published: true

---
# Štruktúrované programovanie

---
# Funkcia, vetvenie a cyklus
---
# Opakovanie: Funkcia 

Keď píšeme román, alebo list tak slová spájame do viet.
Pri písaní programu pre robota Karla spájame príkazy do funkcií.

---

# Funkcia je základná jednotka programu

(skoro) každý príkaz musí patriť do funkcie.
Pomocou funkcie vieme robotovi vysvetliť určitú činnosť.

---
# Funkciu sme už videli

```c
// Typ návratovej hodnoty, názov funkcie a zoznam argumentov (prázdny)
int main(){
    // Tu napíšeme kód
    return 0; // Návratová hodnota bud v tomto prípade 0
}
```
[note]
Alebo graficky:

<div class="mermaid">
graph LR
   P(argumenty) --> funkcia
   funkcia --> B(návratová hodnota)
</div>
[/note]

---
# Názov funkcie

- mal by byť výstižný a nie mätúci
- mal by byť zapísaný s malým písmenom na začiatku
- dodržujeme jednotnú schému zápisu mena funkcie
- pri vymýšľaní názvu funkcie zároveň vymýšľame nové slovo nového jazyka

---
# Z čoho sa skladá funkcia

- Predpis: hovorí o argumentoch a návratovej hodnote
- Telo: hovorí čo treba robiť


---
# Predpis funkcie

- Typ návratovej hodnoty
- Názov funkcie
- Zoznam argumentov

---
# Telo funkcie

- začína sa `{` a končí `}`
- telo musí obsahovať príkaz `return` na vrátenie návratovej hodnoty daného typu

---

Naučme robota tancovať

```c
void tancuj(){
   step();
   turn_left();
   turn_left();
   turn_left();
   step();
   turn_left();
}
```

---
# Funkcia sa dá zapísať ako

- deklarácia (predpis)
- definícia (predpis a telo funkcie)

---
# Príklad na definíciu a deklaráciu

[note]
https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration
[/note]

- Deklarácia: TUKE
- Definícia: TUKE znamená Technická univerzita Košice

---
To isté vieme zapísať ako

[note]
V jazyku C môžeme použiť ľubovoľné množstvo deklarácií, ale iba jedinú definíciu.
[/note]

```c
void tancuj(); // Deklarácia
void tancuj(){ // Definícia
   step();
   turn_left();
   turn_left();
   turn_left();
   step();
   turn_left();
}
```

---
# Hlavičkový súbor obsahuje deklarácie

- Pripojením hlavičkového súboru naučíte robota nové "slová".

---
Celý program
```c
#include <karel.h> // Hlavičkový súbor
void tancuj(); // Deklarácia

int main(){
  return 0;
}

void tancuj(){ // Definícia
   step();
   turn_left();
   turn_left();
   turn_left();
   step();
   turn_left();
}
```
---
Definícia vs. volanie funkcie

```c
#include <karel.h> // Najprv načítame zoznam slov, ktoré budeme použivať
void tancuj(); // Oznámime, že budeme používať nové slovo - zatiaľ nevieme, čo znamená.

int main(){ // Tu definujeme počiatočný bod programu
  tancuj(); // Volanie funkcie
  return 0;
}

void tancuj(){ // Definícia
   step();
   turn_left();
   turn_left();
   turn_left();
   step();
   turn_left();
}
```
---
# Vetvenie

---
# Senzory robota Karla

Robot Karel je schopný vnímať okolitý svet pomocou svojich senzorov.
Senzory sú síce "mierne" obmedzené, ale fungujú veľmi spoľahlivo.

---
# Robot Karel má senzory

- Tlačítko, ktoré sa stlačí, ak je v blízkosti robota stena.
- Kamera, ktorá dovidí iba na zem.
- Inteligentný iBatoh.
- Kompas ktorý ukazuje na sever.

---
# Slovník pre prácu so senzormi

```c
int front_is_clear()  // Tlačítko vpredu
int beepers_present() // Kamera
int facing_north()    // Kompas
int beepers_in_bag()  // iBatoh
```
---
# Funkcia má návratovú hodnotu

- `int` je celé číslo
- `0` je nepravdivá hodnota
- nenulová hodnota je pravdivá

---
# Volanie funkcie

nám povie v akom stave sú senzory

(aktívne alebo neaktívne)

---
# Výraz

Zápis ktorý môže byť vyhodnotený na určitú hodnotu

- `1`
- `beepers_present()`
- `2 + 2`

---
# Vetvenie programu

```c
if (vyraz == 0){
  podmienka_nie_je_pravdiva();
}
else{
  podmienka_je_pravdiva();
}
```

---
# Práca so senzormi

---
Zober žetón iba ak tam je

```c
if (beeper_is_present()){
  pick_beeper();
}
```

---
Choď dopredu ak sa dá

```c
if (front_is_clear())){
  step();
}
```
---
Vylož žetón ak máš, inak choď rovno.

```c
if (beepers_in_bag()){
  put_beeper();
}
else{
  step();
}
```

[note]
<div class="mermaid" style="transform: scale(0.9, 0.9)">
graph TD
	Z((Začiatok)) --> I
	I{výraz}--áno --> A
	I--nie --> B
	A[blok1] --> K
	B[blok2] --> K((Koniec))
</div>
[/note]

---
# Cykly

- Cyklus je podmienka ktorá sa opakuje pokiaľ je výraz pravdivý

---
# Cyklus while

Skoro to isté ako `if`

---
Choď dopredu pokiaľ sa dá

```c
while(front_is_clear()){
  step();
}
```


[note]
# Grafické znázornenie cyklu typu while

<div class="mermaid" style="transform: scale(0.9, 0.9)">
graph TD
	Z((Začiatok)) --> I
	I{výraz}--áno --> A
	A[blok1] --> I
    I--nie --> K((Koniec))
</div>

# Cyklus typu do-while

Podmienku je možné vyhodnotiť aj na konci bloku príkazov:

```c
do {
  teloCyklu();
}
while (podmienka);

```
Tento druh cyklu prebehne vždy minimálne raz;

<div class="mermaid" style="transform: scale(0.9, 0.9)">
graph LR
	Z((Začiatok)) --> A
	I{výraz}--áno --> A
	A[blok1] --> I
    I--nie --> K((Koniec))
</div>
[/note]

---
# Štruktúrované programovanie

- funkcie
- cykly
- podmienky

---
# Štruktúrované programovanie

Vieme vymyslieť a porozprávať aj zložitejší príbeh s názvom Zadanie.

---
# Zadanie riešte po častiach

1. zamyslite sa nad zadaním
1. vyberte si časť ktorú viete riešiť, problém sa stane jednoduchší
1. ak je čo riešiť, pokračujte bodom 1

---
# DRY

Funkcie, podmienky a cykly nm umožňujú stručnejší a prehľadnejší zápis kódu.

Zlaté programátorské pravidlo hovorí, že je potrebné využívať abstrakciu vždy keď to má zmysel.

---
# Don't repeat yourself.

---
# Domáca úloha

Vytvor si vlastnú funkciu

- `turn_right()`
- `find_wall()`
- `drop_beepers()`
- `turn_north()`
