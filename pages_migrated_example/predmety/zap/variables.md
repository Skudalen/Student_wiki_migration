# Premenné a dátové typy

Základy algoritmizácie a programovania

Ing. Daniel Hládek PhD.

---
# Počítač slúži na spracovanie informácií

Ako si informáciu uložiť?

---
# Premenná

Premenná je miesto s menom na uloženie informácie.

---
# Premennú vieme meniť

- Karlov batoh 
- políčko na ploche
- poštová schránka
- šuflík

---
# Reprezentácia premennej

![PuchTape](640px-PaperTapes-5and8Hole.jpg)

---
# Reprezentácia premennej

Množina bitov fixnej veľkosti na určitej adrese

	0100011 0100011

---
# Meno premennej

"Prezývka" pre pamäťovú adresu

"Ta najedličke" je na poštovej adrese "Jedlíkova 9, Košice"

"mojapremenna" je na pamäťovej adrese "#12121212" v mojom počítači.


---
# Ako rozkódujeme premennú?

podľa dátového typu

---
# Dátový typ

- počet bajtov k dispozícii
- spôsob ich interpretácie

---
# Typy premenných

- znakové typy (`char`)
- celočíselné typy (`int`,`long`,`short`)
- čísla s desatinnou čiarkou (`float`,`double`)
- všeliaké iné... (`void*`,`struct time`,...)

---
# Veľkosť dátového typu

Každý dátový typ je obmedzený svojou veľkosťou

Podľa počtu bitov môžeme reprezentovať určitý počet rôznych hodnôt.

[note]
Veľkosť dátového typu je závislá na platforme.

S tým súvisí aj obmedzenie 32 bitových počítačov na 4GB RAM pre jeden program.

(nevieme priamo adresovať viac ako 4 miliardy pamôťových miest)
[/note]

---

[*](https://msdn.microsoft.com/en-us/library/s3f49ktz.aspx)

|Meno			|Veľkosť| Rozsah		|
|-------|---|--------------------------------|
|char	|1|0 to 255| 
|short	|2| –32,768 to 32,767 |
|int	|4 |	–2,147,483,648 to 2,147,483,647|
|float	|4 |	3.4E +/- 38 (7 digits) |
|double	|8|	1.7E +/- 308 (15 digits)|

---
# Celočíselná premenná

```c
int pocitadlo = 0;
```

---
# Vždy si inicializujte

```c
int pocitadlo;
// Aka bude hodnota????
pocitadlo = pocitadlo + 1; 
```


---
# Čo si vieme uložiť?

- nula ?
- miliarda?
- mínus tisíc miliárd?

Koľko bajtov máme k dispozícii?

---
## Operátor sizeof

Vráti veľkosť dátového typu v bajtoch

```c
int sz = sizeof(int);
```

[note]
Štandard jazyka C hovorí iba o minimálnych požiadavkých na rozsah dátového typu.

Operátor sizeof je potrebný pri dynamickej spráce pamäti.

Veľkosť dátového typu nie je štandardizované, preto je potrebné využívať tento operátor.
[/note]

---

# Možnosť pretečenia

- Overflow: ak je celé číslo mimo rozsahu

---
# Príklad na overflow

```c
short v = 0;
for (int i = 0; i < 40000; i++){
	v += 1;
}
printf("%d\n",v);
```


---
# Modifikátory dátových typov

Upravujú počet bitov a bajtov k dispozícii

---
# signed, unsigned

- Pre celočíselné typy
- Signed typy umožnujú reprezentovať záporné čísla
- Unsigned typy umožňujú väčší horný rozsah

---
# long

- použije sa dvojnásobný počet bajtov

```c
unsigned long int cislo;
```

---
# const

- zakazuje modifikáciu premennej
- dá sa ignorovať


---
## Typy s desatinnou čiarkou


```c
float
double
```

---
# norma IEEE754

https://en.wikipedia.org/wiki/Floating-point_arithmetic

```c
double c = 0;
c = 1.2;
c = 1;
c = 123.456e-67;

```



---

# Underflow

Pozor - existuje najmenšia možná hodnota.

Premennú nie je možné deliť donekonečna - po čase sa z hodnoty stane nula.

ak je desatinné číslo príliš malé

	https://en.wikipedia.org/wiki/Arithmetic_underflow
---
## Znakový typ

```c
char c = 'z';
```

---

# ASCII kódovanie

https://en.wikipedia.org/wiki/ASCII

Na siedmich bitoch vieme reprezentovať 127 znakov

---

	ASCII Table

	BIN			Dec		Oct Hex C 
    =============================
    011 1110 	076 	62 	3E 	>
    011 1111 	077 	63 	3F 	?
    100 0000 	100 	64 	40 	@
    100 0001 	101 	65 	41 	A
    100 0010 	102 	66 	42 	B
    100 0011 	103 	67 	43 	C
    100 0100 	104 	68 	44 	D
    100 0101 	105 	69 	45 	E
    100 0110 	106 	70 	46 	F

---
# Diakritika

Pozor, tabuľka neobsahuje národné znaky a diakritiku. 
Kódovanie špeciálnych znakov je oveľa zložitejšie.

Unicode - utf8

---
# Pretypovanie 

---
# Pretypovanie 

Dátový typ hodnoty je možné dynamicky meniť.

Nie je možné meniť dátový dyp premennej.

---
# Pretypovanie

- implicitné ()
- explicitné (pomocou operátora pretypovania).

---
# Implicitné pretypovanie

Hodnotu uložíme do premennej iného typu.

```
int c = 'a';
```

---
Pri pretypovaní môžeme stratiť informáciu.

Aká hodnota sa uloží do premennej a?

```
char c = 256;
```

---
# Explicitné pretypovanie

Zaznačíme si ho do kódu

```
float c = (int)1.1;
```
(opäť nastala strata informácie)

---
# Operácie s premennými

---
# Celočíslelné operácie


- plus, krát, delenie
- modulo
- priradenie a porovnanie
- aritmetické oprácie
- bitové operácie = binárna reprezentácia premennej

---
# Celočíslené delenie

Výsledkom celočíselného delenia je celé číslo

Aký bude výsledok?

```c
int a = 1  / 3;
int b = 3  / 1;
int c = 1.0  / 3;

```

---
# Celočíselné delenie

```c
// Implicitné celočíselné pretypovanie
int a = 1.0  / 3.0;
int b = 3.0  / 1.0;
int c = 1.0  / 3.0;
// Desatinné delenie
float af = 1.0  / 3.0;
float bf = 3.0  / 1.0;
float cf = 1.0  / 3.0;

```

V jazyku C je delenie desatinných čísel iná operácia!

---
# Delenie modulo

Zvyšok po celočíselnom delení.

```c
for (int i = 0; i < 28; i++ ){
	int z = i % 15 + 1;
	printf("Študent %d ma zadanie %d\n",i+1,z);
}
```

---
# Generovanie náhodných čísel


Vygenerujte  náhodné čislo z intervalu a až b.

---

```c
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
#include <time.h>
#include <stdlib.h>
// pozor, b môže byť menšie ako a
int getRand (int a, int b) {
    // rand() returns a pseudo-random integer between 0 and RAND_MAX
    return a + (rand() % (b - a));      
}

int main(){
    srand(time(NULL));   // should only be called once
    getRand(-2,20);
}
```

---
# Priradenie a porovnanie


```c
int c = 1;
if (c = 2){
	printf("Priradil som hodnotu do premennej.\n");
}
if (c == 1){
	printf("Porovnal som hodnotu a premennu.\n");
}
```

---

```c
int c = 1;
if (c = 2){
    // výraz (c = 2) vždy vráti nenulovú hodnotu
    // Ako vedľajší efekt sa priradí hodnota 2 do premennej c
    // Táto podmienka je vždy pravdivá a reťazec na vypíše
    printf("Priradil som hodnotu do premennej.\n");
}
if (c == 1){
    // V podmienke vykonáme porovnanie premennej a hodnoty.
    // V premennej C je hodnota 2, 
    // takže podmienka bude nepravdivá a správa sa nevypíše
    printf("Porovnal som hodnotu a premennu.\n");
}
```

---
# Rozsah platnosti premennej

- Lokálna premenná platí iba v aktuálnom bloku

---
## Globálna premenná

Globálna premenná ma platnosť všade !!!

Môžeme mať inú globálnu premennú s rovnakým menom.

http://wiki.c2.com/?GlobalVariablesAreBad

---

# Argumenty funkcie

---
# Funkcia s argumentom

```c
int spocitaj(int a,int b){
    return a + b;
}
int main() {
    int a = 2;
    int b = 3;
    int c = spocitaj(a,b);
    printf("Viem spocitat %d a %d a vyslo mi: %d",a,b,c);
    return 0;
   
}
```

---
# Návratová hodnota

Funkcia hlási výsledok

---
# Argument funkcie je lokálna premenná

---
# Lokálna premenná platí v aktuálnom bloku

---
# Hodnota premennej sa vždy kopíruje

---
# V jazyku C sa premenné odovzdávajú vždy hodnotou


---
# Štandardný vstup a výstup

---

# Štandardný výstup

Vypíše znaky na obrazovku

```c
printf("Ahoj Svet\n");
```

---

# Opakovanie: Ahoj Svet

```c
#include <stdio.h> // deklarácia funkcie printf

int main(){
	printf("Ahoj TUKE\n");
	return 0;
}
```
---
# Formátovací reťazec

Formátovací reťazec je podobný technickej šablóne.

Hovorí ako sa má zobraziť hodnota premennej.

---

Jeden dátový typ je možné zobraziť viacerými spôsobmi:

- `int` ako desatinné číslo
- desatinné číslo ako celé číslo
- desatinné čislo s rôznum počtom miest
- číslo môže byť zarovnané alebo doplnené nulami

http://en.cppreference.com/w/cpp/io/c/fprintf

---

```c

// http://www.cplusplus.com/reference/cstdio/printf/
/* printf example */
#include <stdio.h>

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}

```

---

```c
    Characters: a A
    Decimals: 1977 650000
    Preceding with blanks:       1977
    Preceding with zeros: 0000001977
    Some different radices: 100 64 144 0x64 0144
    floats: 3.14 +3e+000 3.141600E+000
    Width trick:    10
    A string
```

---
# Štandardný vstup

Načítame znaky z klávesnice a uložíme ich do premennej

---

```c
int c = 0;
scanf("%d",&c);
printf("Nacital som %d",c);
```

---
# Načítanie je neistá operácia

---

# Overte si výsledok

```c
int c = 0;
int r = scanf("%d",&c);
if (r == 1){
    printf("Nacital som %d",c);
}
else{
   printf("Nenacital som\n");
}
```


---

## Smerník na premennú

Adresu premennej si vieme poznačiť do špeciálnej premennej s `*`.

Smerník na pamäť je hodnota adresy pamäte s určitým dátovým typom.


---
# Príklad: Algoritmus pre rodičovskú kontrolu

1. Spýtame sa na vek
1. Ak je vek menej ako 18, odporúčíme obsah pre deti.
1. Inak návštevníka pustíme ďalej

---

Vstup a  výstup je podobný súboru

Súbor: Magnetofónová páska

https://www.youtube.com/watch?v=BnHW-f5ayhs

Štandardný vstup a výstup predpokladá "vzdialený" textový terminál.

https://sk.wikipedia.org/wiki/%C4%8Ealekopisn%C3%BD_stroj

---
# Premenné

Aby sme mohli pracovať s hodnotou veku, musíme ju uložiť do pamäte.

1. Vyhradenie pamäte
1. Výpis výzvy
1. Načítanie z klávesnice do pamäte
1. Porovnanie
1. Výpis vysledku


---
# Vyhradenie pamäte

- Deklarácia: vyhradenie pamäťového miesta určitého typu
- Definícia: priradenie počiatočnej hodnoty do pamäťového miesta.

```c
int vek = 0;
```

Premenná má svoje meno, hodnotu a adresu.

Pozor - počiatočnú hodnotu premennej vždy musíme priradiť sami. Inak nie je definovaná.

Adresu premennej zistíme podľa operátora referencie.


```c
int* adresavek = &vek;
```

Adresa je dôležitá pre načítanie.

---

# Výpis výzvy

Funkcie printf pracuje so štandardným výstupom.

```c
printf("Aký je Váš vek?\n");
```

---

# Načítanie do pamäte

Využijeme funkciu scanf, ktorá tiež používa rovnaký formátovací reťazec.

Na získanie adresy premennej použijeme operátor referencie.

```c
scanf("%d",&vek);
```

- Formátovací reťazec
- Operátor referencie
- Návratová hodnota hovorí o úspešnosti načítania (vracia počet úspešne načítaných čísel)

Alebo:

```c
int* adresavek = &vek;
scanf("%d",adresavek);
```
http://www.cplusplus.com/reference/cstdio/scanf/


---
# Štábna kultúra

Je dôležité písať pekné zdrojové kódy

- Aby boli čitateľné pre seba
- Čitateľné pre druhých

[note]
Ako písať pekné zdrojové kódy

- Správne odsadzovať bloky
	https://en.wikipedia.org/wiki/Indentation_style
- Používať komentáre zdrojových kódov
- Používať jednotnú schému pomenovania funkcií
	https://en.wikipedia.org/wiki/Camel_case
    https://en.wikipedia.org/wiki/Snake_case
[/note]

---
# Techniky obfuskácie zdrojových kódov

Ako písať škaredý kód?

- Nikto nebude rozumieť Vašim kódom
- Zabránite druhým prepísať Váš kód
- *Nebude možné Vás prepustiť*

- http://www.ioccc.org/years.html
- https://stackoverflow.com/questions/17080750/tutorials-for-code-obfuscation-in-c
- https://github.com/Droogans/unmaintainable-code

---
# Príklad na AhojSvet

https://codegolf.stackexchange.com/questions/22533/weirdest-obfuscated-hello-world

Kto to rozšifruje?

```c
#include <stdio.h>
main() {
  long long P = 1,
            E = 2,
            T = 5,
            A = 61,
            L = 251,
            N = 3659,
            R = 271173410,
            G = 1479296389,
            x[] = { G * R * E * E * T , P * L * A * N * E * T };
  puts((char*)x);
}
```

---

# Opakovanie: Proces prekladu

	gcc hello.c -o hello

- Deklarácia a definícia
- Preprocesor
- Kompilátor
- Linker

<div class="mermaid">
graph LR
	H(hlavičkové <br /> súbory .h) --> C
    P(zdrojový <br />kód .c) --> C(prekladač)
	C --> O(objektový <br /> súbor .o)
	O --> L(linker)
	K(knižnice .a) --> L
    L --> S(spustiteľný <br /> subor)	
</div>

---
# Spustenie programu

	./hello

Ako bežný príkaz

---
# Koniec

