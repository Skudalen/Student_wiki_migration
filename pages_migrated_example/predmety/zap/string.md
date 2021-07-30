---
title: Reťazce
published: true
---

# Reťazce


---
# Ako reprezentovať reťazec?

- znaky zakódujeme pomocou ASCII Tabuľky
- množina číselných hodnôt rovnakej veľkosti
- Reťazec je pole znakov zakončené nulou.

---
# ASCII Tabuľka

Znakom anglickej abecedy a pomocným znakom sú pridelené čísla.
![ASCII](asciifull.gif)



---

# Pole znakov

```c
char pole_znakov[\4] = {'a','b','c','D'};
```

Pole znakov nemusí byť reťazec.

---
# Pole znakov
       
    index:        0     1       2       3
                  +------+------+-------+-------+
    hodnota DEC:  |  97  |  98  |  99   |  68   | 
    hodnota CHAR: |  'a' |  'b' |  'c'  |  'D'  |
                  +------+------+-------+-------+
    adresa:       \#10   \#11   \#12    \#13 

---
# Reťazec


```c
char retazec[\5] = "abcD";
```

       
    index:        0     1       2       3       4
                  +------+------+-------+-------+-------+
    hodnota DEC:  |  97  |  98  |  99   |  68   |  0    |
    hodnota CHAR: |  'a' |  'b' |  'c'  |  'D'  |  0    |
                  +------+------+-------+-------+-------+
    adresa:       \#10   \#11   \#12    \#13    \#14


---
# Algoritmus hľadania malých písmen

---

```c
int count_lower(const char* str){
	// Potrebujeme počítadlo
	int counter = 0;
    // Použijeme cyklus for
	for (int i = 0; retazec[\i] != 0; i++){
    	// Písmená vieme používať ako keby to boli ich čísla v ASCII
        if (retazec[\i] >= 'a' && retazec[\i] <= 'z'){
        	// Inkrementácia počítadla ak sa písmeno 
            // nachádza medzi malými písmenami
        	counter += 1;
        }
    }
    return counter;
}
```

---
# Reťazec je pole znakov zakončené nulou.

- uprostred reťazca nemôže byť nula.
- podľa nuly zistíme koniec reťazca.



---
# Znak je celé číslo

Znaky sa dajú porovnávať

---
# Index nulového prvku je veľkosť reťazca.

Keď odovzdávame reťazec ako argument, nemusíme zadať jeho veľkosť. 
reťazca sa dá ľahko dopočítať

---

```c
int velkost_retazca(const char* retazec){
	int i = 0;
	while (retazec[i] != 0){
    	i++;
    }
    return i;
}
```

[note]
Čo sa stane, ak zadané pole nie je reťazec?
[/note]

---
# Použitie strlen

Štandardná knižnica nám poskytuje inplementáciu hľadania dĺžky reťazca

---

```c
#include <string.h>
#include <stdio.h>

int main(){
    char dlhyretazec[] = "Ja som veľmi dlhý reťazec";
    int dlzka = strlen(dlhyretazec);
    printf("Retazec \"%s%\" je dlhy %d znakov\n",dlhyretazec,dlzka);
    return 0;
}
```

---
# Kopírovanie reťazcov

Operátor priradenia pri reťazci nefunguje.

---


```c
int copy_str(const char* src,char* dst){
    int i = 0;i
    while (src[i] != 0){
    	dst[i] = src[i];
    	i++;
    }
    dst[i] = 0;
    return i;
}
```
---
# Formátovacie operácie s reťazcami

`printf` už poznáte

---
# Riziko úrazu

scanf je nebezpečná funkcia

---
# Nesprávny vstup scanf

Zostane "zaseknutý" vo vnútri

---

```c
float celsius;
int degrees;
scanf("%f",&celsius);
// Čo ak namiesto čísla zadám písmená?
scanf("%d",&degrees);
```

---

[note]

Konverziu reťazca na číslo je výhodné vykonať až po načítaní do pamäte, lebo zlyhanie môže spôsobiť nepredvídané správanie.

http://www.cs.utah.edu/~zachary/isp/tutorials/io/io.html

Používanie funkcie scanf aj pre to nie je odporúčané v "bežnom" živote.
[/note]

---

# Bezpečné načítanie

Funkcia fgets

---

```c
char buffer[SIZE];
memset(buffer,0,SIZE);
char* r = fgets(buffer,SIZE,stdin);
if (r != NULL){
   printf("urcite som nacital aj s koncom riadka: %s",buffer)
}
```


---
# Cézarova šifra:

https://learncryptography.com/classical-encryption/caesar-cipher

---

- Šifrovacia tabuľka je tvorená veľkými písmenami abecedy usporiadaných za sebou..
- Kľúč je kladné číslo
- Šifrovanie prebieha tak, že písmeno z originálnej správy posunieme o počet miest doprava.
- Ak presiahneme písmeno Z, pokračujeme od A.

---
# Aritmetika písmen

```c
char a = 'a';
char c = a + 2;
```

---
# Delenie modulo

Ak znak prekročí hranicu abecedy, je potrebné ho vrátiť do správneho intervalu.

---

Ľubovoľné celé číslo vrátime do zadaného intervalu 0 až n -1.

```c
int n = 10;
int a = 999;
int b = a % n;
```

---
# Cézarova šifra jedného písmena

```c
char ceasar_char(char c,int kluc){i
    // char moze sposobit pretecenie
    int res = (int)c + kluc;
    // Číslo prevedieme do intervalu 0 až n
    res = (res - 'A');
    // Číslo prevediem do intervalu 0 až 26
    res = res % ('Z' - 'A');
    // Číslo prevediem do intervalu 'A' až 'Z'
    res = res + 'A';
    return res;
}
```
---

Zlepšite to tak, aby fungoval aj na malé písmená.

---
# Cézarova šifra celého reťazca

Ak vieme zašifrovať jeden znak, vieme zašifrovať celý reťazec:

---

```c
void ceasar_string(char* message,int key, char* result){
    int i = 0;
    while (message[i] != 0){
    	result[i] = caesar_char(message[i]);
    }
    // Nesmieme zabudnúť na koniec reťazca.
    result[i] = 0;
}
```

---
# Celý program na šifrovanie

- Načíta kľúč ako argument príkazového riadka
- Ak sa nepodarilo načítať kĺuč tak skončí.
- Načíta všetky riadky zo štandardného vstupu až do konca, zašifruje ich a zobrazí.

---

# Štandardný vstup a výstup

Súbor, štandardný vstup a výstup sú si podobné. Ak si uložíme textové 
hodnoty do súboru, môžeme si ich načítať rovnakým spôsobom:

---

```bash
cat vstup.txt
ahoj
svet

gcc converter.c -o converter
./converter 2 < vstup.txt > vystup.txt
```

---
# Presmerovanie vstupu

Nemusím stále písať písmená , môžem si ich poznamenať do súboru a "prehrať".

---
# Argumenty príkazového riadka 

```
int main(int argc, char** argv){
  printf("Zadali ste %d argumentov\n");
  printf("Nazov programu je %s\n",argv[0]);
  if (argc > 1){
     printf("Zadali ste aj argument %s\n",argv[1]);
  }
}
```

---
# Konverzia reťazca na číslo

- strtof
- strtol
- sscanf

---
# Funkcia sscanf

- adresa začiatku reťazca
- formátovací reťazec
- adresa kde sa má uložiť výsledok

Návratová hodnota je počet rozpoznaných hodnôt

---
# Konverzia reťazca na  číslo sa nemusí podariť.


---
# Výzva

Vedeli by ste implementovať algoritmus na zlomenie Cézarovej šifry?

ak máte veľa zašifrovaného textu?

---
# Na margo: Kódovanie UTF-8

Text potrebuje kodek

Aký je dlhý reťazec v UTF-8

Koľko bytov potrebuje jeden znak?

---
# Ternárny operátor

Operátor, ktorý berie 3 argumenty:

3 výrazy

- IF
- THEN
- ELSE

Výhoda je, že celý operátor je možné použiť ako výraz.
(netreba to ale prehánať).

---
# Ternárny operátor

The basic syntax of using the ternary operator is thus:

	(condition) ? (if_true) : (if_false)

Which is basically the same as:

    if (condition)
        if_true;
    else
        if_false;
	

http://www.cplusplus.com/forum/articles/14631/

