class: center, middle
# Unix tr

Základy algoritmizácie a programovania

Ing. Daniel Hládek PhD.

---
# Organizačné pokyny

Môžete pracovať na:
- zadaní č. 5 (k skúške)
- zadaní č. 6 (k zápočtu)




---
# Obsah prednášky

- Opakovanie: Reťazce
- Štandardný vstup a štandardný výstup
- Argumenty príkazového riadka
- Utilita tr
- Implementácia tr

---

# Opakovanie: Reťazce

- Pole znakov s nulou na konci
- Bezpečné načítanie pomocou fgets
- Bezpečná konverzia pomocou sscanf
- Algoritmy na prácu s reťazcami zo štandardnej knižnice:
	- Kopírovanie:
    	. strncpy
    - Vyhľadávanie"
    	- strstr

---

# Opakovanie

Štandardný vstup  a výstup

Filtre

Štandardný vstup a výstup je podobný ako súbor.

Terminál je možné zameniť za súbor a pracovať s ním podobným spôsobom.

---
# Operátory presmerovania v príkazovom riadku BASH

Presmerovanie štandardného výstupu programu do súboru
	
    PROGRAM > SUBOR  
    
Presmerovanie štandardného vstupu programu do súboru

	PROGRAM < SUBOR  
    
Presmerovanie štandardného výstupu prvého programu na vstup druhého 
    
    PROGRAM1 | PROGRAM2
---
# Príkazy pre prácu zo štandardným vstupom a výstupom

Výpis súboru na štandardný výstup

	cat

Výpis reťazca na štandardný výstup

	echo

Výpis reťazca na štandardný výstup so stránkovaním
    
    less

Kompresia štandardného vstupu na štandardný výstup
    
    gzip
---
# Príklad práce s presmerovaním 

Vytvoríme textový súbor

```bash
echo "Ahoj Svet" > ahoj.txt
```

Skomprimujeme textový súbor

```bash
cat ./ahoj.txt | gzip > ahoj.txt.gz
```

Prečítame skomprimovaný textový súbor a spočítame v ňom slová

```bash
zcat ./ahoj.txt.gz > ahoj.txt
wc < ahoj.txt
```

---
# Utilita tr

Translate, Transliterate

Slúži na prepis znakov

Pomocou nej je množné implementovať Cézarovu šifru z predošlej prednášky

---

# Práca s tr

```bash
man tr
```

Znaky sa čítajú zo štandardného vstupu a vypisujú na štandardný výstup.

```bash
tr SET1 SET2
```

Pravidlá tr:

- Všetky znaky z množiny SET1 prepíše na zodpovedajúci znak z množiny SET2. Ostatné znaky nechá tak.
- Znaky v množine SET1 sa nemôžu opakovať.
- Množina SET1 a SET2 musí byť rovnako veľká.


---
# Príklad práce s tr

```bash
echo "Ahoj svet" | tr aeiou AEIOU > translated.txt
cat translated.txt
 
AhOj SvEt
```


---
# Cézarova šifra pomocou tr

```bash
tr a-zA-Z f-za-eF-ZA-E
Ahoj, ako sa mas?
Fmto, fpt xf rfx?
Hello, how are you?
Mjqqt, mtb fwj dtz?
```
Podľa http://it4kt.cnl.sk/c/zap/#!/2017%252Flecture.09

Unix tr podporuje aj rozsah znakov:

	a-d == abcd

Aký je kľúč tejto Cézarovej šifry?

---
# Vlastná implementácia tr

1. Načítajme SET1 a SET2 z príkazového riadka
1. Overme či sú SET1 a SET2 správne:
	- či je SET1 unikátna
    - či obsahuje iba viditeľné znaky ASCII
    - či je veľkosť SET1 a SET2 rovnaká
1. Načítavajme text zo štandardného vstupu po riadkoch
1. Na každý riadok aplikujme transformáciu
1. Výpíšme výsledok


---
# Argumenty príkazového riadka


```c
#include <stdio.h>

// ARGC: počet dostupných argumentov
// ARGV: pole začiatkov reťazcov s argumentami, správa sa ako dvojrozmerné pole znakov.

int main(int argc, char** argv){
	// Musíme zaistiť že argumenty sú k dispozícii
    if (argc != 3){
        printf("Usage: tr SET1 SET2");
        return 1;
    }
    // V poli argv máme k dispozícii začiatky reťazcov
    char* set1 = argv[1];
    char* set2 = argv[2];
    printf("Zadali ste argumenty: \"%s\" a \"%s\"",set1,set2);
    return 0;
}
```

---
# Kontrola unikátnosti znakov v reťazci

Musíme zistiť, či sa niektorý znak v reťazci neopakuje.

Možnosť 1:

Zober znak a skontroluj, či sa v reťazci nenachádza taký istý znak na inej pozícii

podľa:
http://it4kt.cnl.sk/c/zap/#!/2017%252Flecture.09

Nevýhoda: je kvadratická zložitosť

Možnosť 2:

Priprav si počítadlo pre každý znak a zisti, či niektoré znaky nemajú početnosť vyššiu ako 1

Nevýhoda: Je potrebné správne alokovať počítadlo.

---
# Počítadlo znakov v reťazci

Využijeme fakt, že pracujeme s ASCII znakmi - každý znak má kód v rozsahu 0-255

Každý znak bude mať v poli jedno políčko s početnosťou,

	  znak                   'a'   'b'   'c'   'd'  
      index                  97    98     99   100		
            +----------------------------------------------+
	  počet |    ..        |  0  |  1  |  1  |  0  |  ...  |
	        +----------------------------------------------+

Počítadlo bude pole s jedným políčkom pre každý kód.
```c
int pocitadlo[255];
```

---
# Inicialízícia počítadla 


Počítadlo musíme inicializovať na nulu pre každý kód:
```c
for (int i = 0; i < 255; i++){
	pocitadlo[i] = 0;
}
```

alebo stručnejšie:

```c
memset(pocitadlo,0,sizeof(int)*255);
```

---
# Počítanie výskytu znakov v reťazci

Prejdeme reťazec a zvýšime početnosť každého znaku o jedna

```c
for (int i = 0; str[i] != 0; i++){
	// q = str[i] je kód znaku
    // pocitadlo[q] je početnosť znaku q
	pocitadlo[str[i]] += 1;
}
```

---
# Kontrola, či reťazec obsahuje iba unikátne znaky

Ak vieme spočítať početnosť znakov v reťazci,
vieme povedať, či sa niektorý z nich nevyskytuje viac krát.

```c
int is_unique(char* str){
	int pocitadlo[256];
    // Inicializácia počítadla
	memset(pocitadlo,0,sizeof(int)*256);
    // Prechádzanie reťazca po znakoch
    for (int i = 0; str[i] != 0; i++){
    	// Index nesmie byť záporný
    	unsigned int code = str[i];
        // Počítanie výskytu znakov
        pocitadlo[code] += 1;
        if (pocitadlo[code] > 1){
        	return 0;
        }
    }
    return 1;
}
```

Ako by ste pridali kontrolu či sú všetky znaky zobraziteľné?

---

# Kontrola veľkosti reťazcov

Využijeme funkciu strlen:
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    if (argc != 3){
        printf("Usage: tr SET1 SET2");
        return 1;
    }
    char* set1 = argv[1];
    char* set2 = argv[2];
    if (strlen(set1) != strlen(set2)){
        printf("Size of SET1 and SET2 must be equal");
        return 1;
    }
    return 0;
}
```

---
# Preklad znakov z množiny 1 do množiny 2

Množiny definujú mapu na prepis jedného znaku na iný.

	


| a | b | c | d | e |
|---|---|---|---|---|
| a | b | C | D | e |
	

---
# Preklad znakov z množiny 1 do množiny 2

Možnosť 1:

Pre všetky znaky reťazca:

1. Zober znak
1. Vyhľadaj znak v množine 1
1. Ak sme našli znak v množine 1, vyhľadaj znak s rovnakým indexom v množine 2
1. Nahraď znak z monžiny 1 za znak z množiny 2 s rovnakým indexom.
1. Ak znak nebol nájdený nerob nič.

Nevýhody: Kvadratická zložitosť

Možnosť 2:

1. Podľa množiny 1 a množiny 2 zostav prekladovú tabuľku:
	1. Do poľa ulož postupnosť hodnôt od nula až 255
    1. Pre každý znak z množiny 1 ulož znak z množiny 2 do prekladovej tabuľky
1. Nahraď všetky znaky z reťazca hodnotami z prekladovej tabuľky

Nevýhody: Potrebujeme vytvoriť prekladovú tabuľku

---
# Prekladová tabuľka

Je podobná ako počítadlo, ale kódu znaku priradzujeme iný kód znaku.

```bash
		tr	bcd BCD
```


	  znak             'a'   'b'   'c'   'd'  'e'    
      index            97    98     99   100  101		
              +------------------------------------------+
	  preklad | ...  | 'a' | 'B' | 'C' | 'D' | 'e' | ... | 
	          +------------------------------------------+

---
# Inicializácia prekladovej tabuľky

Do poľa vložíme postupnost hodnôt od nuly:

```c
char preloz[256];
for (unsigned int i = 0; i < 256; i++){
	preloz[i] = i;
}

```

---
# Výpočet prekladovej tabuľky

Index v tabuľke je znak z množiny 1, hodnota v tabuľke je znak z množiny 2.

Funkcia si vyžaduje, aby pamäť už bola alokovaná.

```c
void read_table(const char* set1,const char* set2,unsigned char* table){
    for (unsigned int i = 0; i < CHARSIZE; i++){
        table[i] = i;
    }
    for (int i = 0; set1[i] != 0; i++){
        unsigned char code = set1[i];
        // Z kódu znaku sa stáva index v poli
        table[code] = set2[i];
    }
}
```

Prekladová tabuľka nie je reťazec, ale pole znakov.

---
# Použitie prekladovej tabuľky na prepis reťazca

Hotovú tabuľku vieme odovzdať ako argument do inej funkcie

```c
void translate(char* str,unsigned char* table){
	// Prechádzame všetky znaky reťazca
    for (int i = 0; str[i] != 0; i++){
        unsigned char code = str[i];
        char r = table[code];
        // Každý znak nahradíme za jeho ekvivalent v prekladovej tabuľke
        str[i] = r;
    }
}
```

---
# Načítanie riadkov zo štandardného vstupu


STDIN - globálna konštanta, ktorá reprezentuje štandardný vstup

buffer - pole znakov pre uloženie riadku

Funkcia vracia NULL v prípade chyby alebo konca súboru

```c
char buffer[1024];
while (fgets( buffer, 1024, stdin) != NULL){
    translate(buffer,table);
    printf("%s",buffer);
}
```

---
# Celý príklad

1. Načítame argumenty príkazového riadka
1. Skontrolujeme ich
1. Zostavíme prekladovú tabuľku
1. Načítavame štandardný vstup po riadkoch
1. Prepisujeme riadky a vypisujeme výsledok

---
# Celý príklad

```c
#include <stdio.h>
#include <string.h>
#define CHARSIZE 256
int is_unique(const char* str);
void translate(char* str,unsigned char* table);
void read_table(const char* set1,const char* set2,unsigned char* table);
int main(int argc, char** argv){
    if (argc != 3){
        printf("Usage: tr SET1 SET2");
        return 1;
    }
    char* set1 = argv[1];
    char* set2 = argv[2];
    if (!is_unique(set1)){
        printf("Letters in SET1 must be unique");
        return 1;}
    if (strlen(set1) != strlen(set2)){
        printf("SET1 and SET2 should have same size");
        return 1;}
    unsigned char table[CHARSIZE];
    read_table(set1,set2,table);
    char buffer[1024];
    while (fgets( buffer, 1024, stdin) != NULL){
        translate(buffer,table);
        printf("%s",buffer);
    }
    return 0;
}
```

---

```c
int is_unique(const char* str){
    int counter[CHARSIZE];
    // Tabula pocetnosti ASCII kodov
    memset(counter,0,sizeof(int) * CHARSIZE);
    for(int i = 0; str[i] != 0; i++){
        unsigned char code = str[i];
        // Pocitame kolko krat sa kod vyskytuje v retazci
        counter[code] += 1;
        // Ak sa kod vyskytuje viac ako jeden krat
        // retazec nie je unikatny
        if (counter[code] > 1)
            return 0;
    }
    return 1;
}

void translate(char* str,unsigned char* table){
    for (int i = 0; str[i] != 0; i++){
        unsigned char code = str[i];
        char r = table[code];
        str[i] = r;
    }
}

void read_table(const char* set1,const char* set2,unsigned char* table){
    for (unsigned int i = 0; i < CHARSIZE; i++){
        table[i] = i;
    }
    for (int i = 0; set1[i] != 0; i++){
        unsigned char code = set1[i];
        table[code] = set2[i];
    }
}
```

---
# Vylepšenie

Kontrolu unikátnosti a zostavenie prekladovej tabuľky môžeme vykonať v jednom kroku.
- zefektívni sa kód
- skráti sa nám kód.
- odstránia sa duplicity

```c
int read_table(const char* set1,const char* set2,unsigned char* table){
    for (unsigned int i = 0; i < CHARSIZE; i++){
        table[i] = i;
    }
    for (int i = 0; set1[i] != 0; i++){
        unsigned char code = set1[i];
        // Ak prekladová tabuľka bola zmenená už pred tým
        // potom SET1 nie je unikátny
        // Pre jedno písmeno potom existuje viac pravidiel pre prepis.
        if ([code] != code)
        	return 1;
        table[code] = set2[i];
    }
    return 0;
}
```

---
# Predčasná optimalizácia je koreňom všetkého zla

Donald E. Knuth

Aj tak sme tou úpravou nič nevyhrali, len dobrý pocit, že sme šikovní.

---
# Opakovanie: modifikátory dátových typov

unsigned: bezznamienkový typ (je vhodný ako index)

const: nie je možná modifikácia danej hodnoty.


---
# Pre porovnanie

Riešenie od kolegov

http://it4kt.cnl.sk/c/zap/#!/2017%252Flecture.09


---
# Koniec
