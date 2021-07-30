# N rozmerné polia


Ing. Daniel Hládek PhD.


---
# Pamäť je ako papierová páska

Hodnoty sú uložené za sebou

Každá hodnota má svoju adresu

---
# Pole v pamäti


	int pole[\4] = {4,3,2,1};
    
       
    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22 
        

---
# Smerník = Adresa

premennej nejakého typu

---
# Smerník a pole


Názov poľa je smerník na jeho začiatok.

Ľubovoľný smerník môže byť začiatkom poľa.

---
# Dvojrozmené pole neexistuje

Ale existuje pole polí

---

	int pole2d[\2][\2] = {,
    					{4 ,3 },
                        {5, 6 }
                       };
    
    
    index1:    0               1  
    index2:    0     1         0      1  
             ++------+------++------+------++
    hodnota: ||  4   |  3   ||  5   |  6   ||
             ++------+------++------+------++
    adresa:  \#10   \#14   \#18    \#22 
    

   
---
# Inicializácia dvojrozmerného poľa

    

---
# kompilátor si vie domyslieť
    
	int pole2d[][\2] = {,
    					{4 ,3 },
                        {5, 6 }
                       };

---
Dvojrozmerné pole je možné inicializovať rovnako ako jednorozmerné:


	int pole2d[\ROWS][\COLS] = {4 ,3 ,5, 6};

---
# 2D pole ako argument

[note]
Toto podporujú iba nové prekladače 

(VLA - variable length array)

veľkosť dátového typu sa mení počas behu programu
[/note]

```c
void spracuj(int pocet_riadkov,int pocet_stlpcov, int pole[\pocet_riadkov][\pocet_stlpcov]);
```

---
Šírka druhého rozmeru (vnútorného pola), nemusí byť konštanta:


```c
void spracuj(int pocet_riadkov,int pocet_stlpcov, int pole[][\pocet_stlpcov]);
```

---
# 2D pole ako argument

```c
void spracuj(int* 2dpole,int rows,int cols);
```

---
# Jednorozmerné pole je možné používať ako dvojrozmerné

Jednoducho vypočítame pozíciu bunky v jednorozmernom poli.

Jednorozmerné pole vyzerá v pamäti rovnako ako dvojrozmerné.

---
```c
void draw(const int rows, const int cols, char* array){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            int z = x + cols * y;
            printf("%c", array[\z]);
        }
        printf("\n");
    }
}
```


---
# Pole smerníkov

```c
void spracuj(int** 2dpole,int rows,int cols);
```

Robí sa s ním ako s dvojrozmerným poľom

---
# Vypísanie obsahu

```c
void draw(const int rows, const int cols, char array[][\cols]){
    for(int y = 0; y < rows; y++){
        for(int x = 0; x < cols; x++){
            printf("%c", array[\y][\x]);
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
char arr2[][\4] = {
    "  |",
    "  |",
    "  |",
    "  |",
    "  |"
};
```
---

je to isté ako:

```c
char arr3[][\4] = {
{' ',' ','|',0},
{' ',' ','|',0},
{' ',' ','|',0},
{' ',' ','|',0},
{' ',' ','|',0}
};
```

---

# Dvojrozmerné pole reťazcov je trojrozmerné pole znakov

---

```c
char arr2[][\5][\4] = {
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


---

Takže môžeme napísať:

```
draw(rows, cols, arr2[\0]);
```

pre vykreslenie dvojrozmerného poľa.

---
# Zhrnutie

- Pole je vždy súvislá oblasť v pamäti
- Prvok poľa môže byť iné pole.
- N rozmerné pole je zovšeobecnením jednorozmerného poľa.
- V pamäti N rozmerné pole vyzerá ako jednorozmerné.
- Prvok N-rozmerného poľa môže byť n-1 rozmerné pole.

---
# Príklady

- [7 segmentový displej](7seg.c)
- [7 segmentový displej ako jednorozmerné pole](7seg1d.c)


---
# Koniec

