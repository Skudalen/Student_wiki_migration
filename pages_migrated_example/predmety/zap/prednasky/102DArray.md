class: center, middle
# N rozmerné polia

Základy algoritmizácie a programovania

Prednáška č. 10

Ing. Daniel Hládek PhD.

---
# Opakovanie: Dátový typ

Dátový typ má:
- veľkosť  v bajtoch
- Metódu, ako interpretujeme postupnosť bajtov.
    
Dátové typy:
- jednoduché
	- celé číslo
    - znak
    - číslo s desatinnou čiarkou
- zložené (skladajú sa z iných dátových typov)
	- pole
    - štruktúra

---
# Opakovanie: Polia


Pole je súvislá oblasť v pamäti

Viac miest rovnakého typu za sebou

- int
- char
- float ....

Všetky bunky v poli musia mať rovnaký typ


---
# Pole v pamäti


	int pole[4] = {4,3,2,1};
    
       
    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22 
        
---
# Odovzdávanie poľa ako argument

V jazyku C všetko odovzdávame hodnotou.

Pole je možné odovzdať jeho hodnotou, ale nie je to veľmi praktické:
- kopírovanie môže byť náročne
- funkcia by bola obmedzená na konkrétny rozmer poľa



Pole odovzdávame *hodnotou adresy jeho začiatku* a veľkosťou.

---
# Smerník a pole


Názov poľa je smerník na jeho začiatok.

Ľubovoľný smerník môže byť začiatkom poľa.

Smerník = Adresa

     
---

# Dvojrozmerné pole

Také jednorozmerné pole, ktorého prvky sú iné jednorozmerné polia.


	int pole2d[2][2] = {,
    					{4 ,3 },
                        {5, 6 }
                       };
    
    
    index1:    0               1  
    index2:    0     1         0      1  
             ++------+------++------+------++
    hodnota: ||  4   |  3   ||  5   |  6   ||
             ++------+------++------+------++
    adresa:  \#10   \#14   \#18    \#22 
    
- Prvky poľa musia mať vždy rovnakú veľkosť.
- Dvojrozmerné pole v pamäti vyzerá rovnako ako jednorozmerné


---
# 1 prvok 2 rozmerného poľa

Skúsme viaceré polia zoskupiť do jedného.

Pole, ktorého prvkom je iné pole.

Jeden prvok dvojrozmerného pola bude pole s dvoma prvkami:

	int pole[2] = {4,3};
    
       
    index:    0     1       
             +------+------+
    hodnota: |  4   |  3   |
             +------+------+
    adresa:  \#10   \#14    
   
---
# Inicializácia dvojrozmerného poľa


	int pole2d[2][2] = {
    					{4 ,3 },
                        {5, 6 }
                       };
    

Dvojrozmerné pole je možné inicializovať rovnako ako jednorozmerné:


	int pole2d[2][2] = {4 ,3 ,5, 6};

Prvý rozmer je možné vynechať, kompilátor si ho odvodí:
    
	int pole2d[][2] = {,
    					{4 ,3 },
                        {5, 6 }
                       };


---
# Odovzdávanie jednorozmerného pola ako argument


Jednorozmerné pole odovzdávame:

- typom jeho bunky
- adresou začiatku
- veľkosťou

```c
// Zápis pomocou smerníka (adresy)
void spracuj_jednorozmerne_pole_int1(int velkost,int* pole);
// Zápis toho istého kde zvýrazníme, že ide o pole
void spracuj_jednorozmerne_pole_int2(int velkost,int pole[]);
```

---

# Odovzdávanie dvojrozmerného pola ako argument

Pri dvojrozmernom poli je typ jeho bunky iné pole:
- musíme byť jasné, aká je šírka jednej bunky (iného jednoromzenrého poľa)

```c
void spracuj3(int pocet_riadkov,int pole[][3]);
```

Šírka druhého rozmeru (vnútorného pola), nemusí byť konštanta:

```c
void spracuj4(,int pocet_riadkov,int pocet_stlpcov, int pole[][pocet_stlpcov]);
```

---
# Funkcia, ktorá spracuje dvojrozmerné pole

Vypísanie obsahu dvojrozmerného poľa:

```c
void draw(const int rows, const int cols, char array[][cols]){
    for(int y = 0; y &lt; rows; y++){
        for(int x = 0; x &lt; cols; x++){
            printf("%c", array[y][x]);
        }
        printf("\n");
    }
}
```

---

# Celý príklad - výpis 7 segmentovky

Podľa http://it4kt.cnl.sk/c/zap/#!/2017%252Flecture.10

```c
#include <stdio.h>
void draw(const int rows, const int cols, char array[][cols]);
int main(){
    int rows = 5, cols = 4;

    char array[][4] = {
        {' ', '-', '-', ' '},
        {'|', ' ', ' ', '|'},
        {' ', '-', '-', ' '},
        {'|', ' ', ' ', '|'},
        {' ', '-', '-', ' '}
    };

    draw(rows, cols, array);

    return 0;
}
void draw(const int rows, const int cols, char array[][cols]){
    for(int y = 0; y &lt; rows; y++){
        for(int x = 0; x &lt; cols; x++){
            printf("%c", array[y][x]);
        }
        printf("\n");
    }
}
```

---
# Viac rozmerné polia

Môže byť dvojrozmerné pole prvkom iného poľa?
Vedeli by sme priradiť číslu jeho podobu na sedemsegmentovom displeji:

	1        2        3
      |    - - |   - - |
      |        |       |
      |    - - |   - - |
      |    |           |
      )    | - -   - - |

---
# Pole reťazcov

Je dvojrozmerné pole znakov (každý riadok je zakončený nulou)
```c
char arr2[][4] = {
    "  |",
    "  |",
    "  |",
    "  |",
    "  |"
};
```
je to isté ako:

```c
char arr3[][4] = {
{' ',' ','|',0},
{' ',' ','|',0},
{' ',' ','|',0},
{' ',' ','|',0},
{' ',' ','|',0}
};
```

---

# Dvojrozmerné pole reťazcov je trojrozmerné pole znakov

```c
char arr2[][5][4] = {
    {
    "  |",
    "  |",
    "  |",
    "  |",
    "  |",
    },
    {
    "--|",
    "  |",
    "--|",
    "| ",
    "|__",
    },
    {
    "--|",
    "  |",
    "--|",
    "  |",
    "__|",
    }
};
```

---
# Prvok trojrozmerného poľa je dvojrozmerné pole

Takže môžeme napísať:

```
draw(rows, cols, arr2[0]);
```

pre vykreslenie dvojrozmerného poľa.

---
# Skoro celý príklad

```c
void draw(const int rows, const int cols, char array[][cols]);
int main(){
    int rows = 5, cols = 4;

    char arr2[][5][4] = {
        {
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        },
        {
        "--|",
        "  |",
        "--|",
        "| ",
        "|__",
        }
    };
    draw(rows, cols, arr2[0]);

    return 0;
}
```

---
# Jednorozmerné pole je možné používať ako dvojrozmerné

Jednoducho vypočítame pozíciu bunky v jednorozmernom poli.

Jednorozmerné pole vyzerá v pamäti rovnako ako dvojrozmerné.

```c
void draw(const int rows, const int cols, char* array){
    for(int y = 0; y &lt; rows; y++){
        for(int x = 0; x &lt; cols; x++){
        	int z = x + cols * y;
            printf("%c", array[z]);
        }
        printf("\n");
    }
}
```




---
# Zhrnutie

Pole je vždy súvislá oblasť v pamäti

Prvok poľa môže byť iné pole.

N rozmerné pole je zovšeobecnením jednorozmerného poľa.

V pamäti N rozmerné pole vyzerá ako jednorozmerné.

Prvok N-rozmerného poľa môže byť n-1 rozmerné pole.

---
# Príklady

- [7 segmentový displej](7seg.c)
- [7 segmentový displej ako jednorozmerné pole](7seg1d.c)




---
# Koniec

