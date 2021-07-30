# 5. Pole smerníkov


## 5. Pole smerníkov

## Organizačné pokyny

- Buďte pripravení na Zadanie č. 2
- Opravná zápočtovka

## Chyby prístupu do pamäte

Nezabúdajte na Valgrind, pomôže Vám

- ak náhodou používate nevyhradenú alebo neinicializovanú pamäť

## Opakovanie

- Smerník
- Operátor referencie
- Operátor dereferencie

## Názov poľa je adresa jeho začiatku

Adresa v pamäti môže byť začiatkom poľa hodnôt.


## Outline: načítanie zoznamu slov a jeho zotriedenie


Pravouhlé pole

Pole smerníkov

## Jednorozmerné pole

Je vhodné na uloženie vektora hodnôt fixnej veľkosti.

Veľkosť poľa nie je možné meniť, ale je možné alokovať iné.

## Jednorozmerné pole

	int pole[4] = {4,3,2,1};
    
       
    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22 

## Dvojrozmerné pole

Je vhodné na uloženie matice,
kde každý riadok je rovnako veľký.


          0     1     2     3
       +-----+-----+-----+-----+
    0  |  o  |  n  |  i  |  0  |
       +-----+-----+-----+-----+
    1  |  a  |  0  |     |     |
       +-----+-----+-----+-----+
    2  |  a  |  j  |  0  |     |
       +-----+-----+-----+-----+
    3  |  o  |  n  |  y  |  0  |
       +-----+-----+-----+-----+

## Dvojrozmerné pole v pamäti

Také jednorozmerné pole, ktorého prvky sú jednorozmerné polia.


	char pole2d[2][2] = {,
                        {'a' ,'b' },
                        {'c', 'd' }
                       };
    
    
    index1:    0               1  
    index2:    0     1         0      1  
             ++------+------++------+------++
    hodnota: ||  a   |  b   ||  c   |  d   ||
             ++------+------++------+------++
    adresa:  #10    #11    #12     #13 

## Príklad

Načítanie zoznamu slov do dvojrozmerného poľa a zotriedenie zoznamu slov.

## Pole smerníkov v pamäti

    +------+
    |      |           +-----+-----+-----+-----+
    | eeff | --> #eeff |  o  |  n  |  i  |  0  |
    +------+           +-----+-----+-----+-----+
    |      |           +-----+-----+
    | 11aa | --> #11aa |  a  |  0  |
    +------+           +-----+-----+
    |      |           +-----+-----+-----+
    | ccac | --> #ccac |  a  |  j  |  0  |
    +------+           +-----+-----+-----+
    |      |           +-----+-----+-----+-----+
    | 66a2 | --> #66a2 |  o  |  n  |  y  |  0  |
    +------+           +-----+-----+-----+-----+
          

## Príklad

Vytvorenie poľa smerníkov.

Načítanie zoznamu slov

## Načítanie reťazca

Potrebujeme pamäť fixnej veľkosti (sme obmedzení veľkosťou alokovanej pamäte).

	char riadok[100];
    // Načíta po prvú medzeru alebo koniec riadka
    scanf("%s",riadok); 
    // Načíta po prvý koniec riadku
    fgets(riadok,100,stdin);

## Načítanie ľubovoľne veľkého reťazca

	getline(char** line,size_t line_size, FILE* file)

	// Smerník pre uloženie pamäte s riadkom
	char* line;
    // Uloženie veľkosti načítaného riadka
    size_t line_size;
    // Funkcia alokuje pamäť na riadok podľa potreby
    getline(&line,&line_size,stdin);
    // Je potrebné uvoľniť pamäť
    free(line);

Príklad z minulej prednášky

## Challenge at HOME

Modifikujte príklad tak aby vedel načítať ľubovoľne veľký riadok a ľubovoľný počet slov

## Koniec
