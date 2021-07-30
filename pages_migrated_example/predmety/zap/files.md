# Súbory

Základy algoritmizácie a programovania

Ing. Daniel Hládek PhD.

---
### Práca so zariadeniami na ukladanie dát

- pevný disk
- flash (SSD disk)

---
# Čo je pevný disk

https://en.wikipedia.org/wiki/Hard_disk_drive

- Môžeme si to predstaviť ako platňu.
- Existuje čítacia a zapisovacia hlava, ktorá sa vie presúvať.
- Presunutie hlavy je relatívne náročné, lebo znamená fyzický presun čítacieho zariadenia.

--
# Čo je SSD

Solid State Drive

- čip bez pohyblivých častí
- rýchly prístup na ľubovoľné miesto
- obmedzený počet zápisov

---
# Súbor

Oblasť v súborovom systéme, ktorá sa skladá zo súvislých blokov.

---
# Súborový systém

- meno súboru
- miesto v adresárovej štruktúre
- vlastníka
- prístupové práva
- veľkosť v bajtoch

---
# Práca so súbormi

- otvorenie a zatvorenie súboru
- čítanie a zápis
- presun čítacej a zapisovacej hlavy

---
# Otvorenie súboru

Pomocou funkcie [fopen](http://www.cplusplus.com/reference/cstdio/fopen/):
- mód otvorenia súboru
- meno súboru

Návratová hodnota je smerník `FILE*`, ktorý predstavuje čítaciu hlavu.

---
# Módy otvorenia súboru

	rwa

čítanie, zápis, pridávanie

---

- `r` Čítanie zo súboru:
	- hlava sa nastaví na začiatok súboru
- `w` Zápis do súboru
	- hlava sa nastaví na začiatok súboru
    - **veľkosť súboru sa nastaví na nulu.**
    - vytvorí sa nový súbor ak to je potrebné
- `a` Pridávanie do súboru
	- hlava sa nastaví na koniec súboru
    - vytvorí sa nový súbor ak to je potrebné

---

# Otvorenie a zatvorenie súboru

http://www.cplusplus.com/reference/cstdio/fopen/

---

- Otvoríme súbor na čítanie - obsah súboru bude zmazaný.
- Otvorenie súboru môže zlyhať - nemusíme mať práva na zápis do súboru alebo na vytvorenie súboru. 
- V prípade, že otvorenie zlyhalo, funkcia `fopen` vráti hodnotu `NULL`. 

---

```c
#include <stdio.h>
int main ()
{
  FILE * pFile = fopen ("myfile.txt","w");
  if (pFile!=NULL)
	  {
    fclose (pFile);
  }
  return 0;
}
```

Tento príklad nám vytvorí prázdny súbor. Zmaže starý súbor.

---
# Čítanie textu zo súboru

http://www.cplusplus.com/reference/cstdio/fopen/

---
Načítame zo súboru riadok, veľký **max. 99** znakov.


Čo môže zlyhať:
- súbor nemusí existovať alebo nemusíme mať prístupové práva
- môže nastať chyba pri čítaní (súbor medzi tým niekto zmaže alebo presunie)
- môžeme nájsť koniec súboru
- riadok môže byť dlhší

---

Argumenty `fgets`:

- smerník na buffer (pole znakov)
- veľkosť buffra
- smerník na súbor

Návratová hodnota:
- NULL v prípade, že nastala chyba (koniec súboru).

---
## Čítanie textu zo súboru

`fgets` číta aj koniec riadka `\n`.

---

```c
#include <stdio.h>

int main() {
   FILE * pFile;
   char mystring[100];
   pFile = fopen ("myfile.txt" , "r");
   if (pFile == NULL){
        perror("Error opening file");
   }
   else {
     if ( fgets (mystring , 100 , pFile) != NULL ) {
     	printf("%s",mystring);
     }
     fclose (pFile);
   }
   return 0;
}
```

---

# Čítanie jedného riadka textu

zo štandardného vstupu

---

```c
#include <stdio.h>
#define SIZE

int main(){
    char buffer[SZIE];
    memset(buffer,0,SIZE);
    pFile = fopen ("myfile.txt" , "r");
    if (pFile == NULL){
        perror("Error opening file");
        return 1;
    }
    while (fgets( buffer, SIZE, pFile) != NULL){
        printf("%s",buffer);
    }
    fclose (pFile);
    return 0;
}
```

---
# Čítanie jedného riadka textu

Štandardný vstup je tiež súbor, ktorého smerník máme k dispozícii ako globálnu premennú **stdin**.

---

```c
#include <stdio.h>

int main(){
   char mystring[100];
   memset(0,mystring,100);
   if ( fgets (mystring , 100 , stdin) != NULL )
       printf("%s",mystring);
   }
   return 0;
}
```

---

# Čítanie všetkých riadkov textu zo štandardného vstupu

---

```c
#include <stdio.h>

int main(){
    char buffer [1024];
    while (fgets( buffer, 1024, stdin) != NULL){
    	printf("%s",buffer);
    }
    return 0;
}
```

---
# Čítanie textu a konverzia na číslo

---
Program očakáva, že text bude vo formáte jedno číslo na jeden riadok, napr:
	
    2
    4
    78
    
Možné chyby - zadaný text nemusí byť v požadovanom formáte.

---
čítanie textu a konverzia na číslo

1. Čítame súbor po riadkoch pomocou `fgets`.
1. Každý riadok uložíme do buffra
1. Na text v buffri aplikujeme konverziu na číslo pomocou `sscanf`.

---
```c
#include <stdio.h>

int main(){
    char buffer [1024];
	while (fgets( buffer, 1024, stdin) != NULL){
    	int number = 0;
    	int res = sscanf("%d",&number);
        if (res != 1){
            perror("Input file format");
            return 1;
        }
    	printf("%d",number);
    }
    return 0;
}
```

---
# Zápis do súboru

`fopen` nastavme na:
- `w` Vynulovanie súboru (vložím novú pásku a nastavím ju na začiatok)
- `a` Pripojenie do existujúceho súboru - append

podobný ako výpis na obrazovku pomocou funkcie [fprintf](http://www.cplusplus.com/reference/cstdio/fprintf/).

---
# Utilita na kopírovanie súborov

príklad s `fprintf`

---

```c
#include <stdio.h>

void copy(FILE* inf,FILE* outf);
int main(int argc, char** argv){
    if (args != 3){
    	perror("Správne použitie: cp <fromfile> <tofile>\n");
        return 1;
    }
    FILE* inf = fopen(argv[1],"r");
    if (inf == NULL){
    	printf("Súbor %s sa nepodarilo otvoriť alebo neexistuje",argv[1];
     	return 1;
    }
    FILE* outf = fopen(argv[2],"w");
    if (outf == NULL){
    	printf("Súbor %s neexistuje alebo nie je zapisovateľný",argv[1];
     	return 1;
    }
    copy(inf,outf);
    fclose(inf);
    fclose(outf);
}
```

---
# Kopírovanie textu z jedného súboru do druhého

```c
void copy(FILE* inf,FILE* outf){
	char buffer [1024];
	while (fgets( buffer, 1024, inf) != NULL){
           fprintf(outf,"%s",buffer);
        }
}
```
---
Funguje takýto program na všetky súbory?

Reťazec nie je pole znakov, lebo nemôže osahovať nulu v strede. 

---
## Binárne kopírovanie

Pre prácu s ľubovoľnými dátami musíme využiť iné metódy:

- [fread](http://www.cplusplus.com/reference/cstdio/fread/)
- [fwrite](http://www.cplusplus.com/reference/cstdio/fwrite/)

---
# Binárne kopírovanie súborov

---
```c
void copy_binary(FILE* inf,FILE* outf){
    char buffer [1024];
    int count =- 0;
    // Ak funkcia fread vráti nulu, čítanie sa skončilo
    while((count = fread(buffer, sizeof(int), 1024, inf)) > 0){
        fwrite(buffer, sizeof(int), count, outf);
        counter++;
    }
}
```

---
# Záver

- Práca so súbormi je veľmi podobná práci so štandardným výstupom a vstupom
- Pri práci so vstupno-výstupnými zariadeniami nič nie je isté
	- je potrebné ošetriť "nečakané" situácie
- Binárne dáta nie sú reťazce, treba používať príslušné funkcie.

