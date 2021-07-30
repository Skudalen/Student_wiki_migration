# Smerníková aritmetika

# Outline

  - Smerníková aritmetika a spracovanie reťazcov

  - Pole smerníkov

  - Práca s pamäťou

# Čo je smerníková aritmetika?

  - Aritmetické operácie s adresou
    
      - spočítavania a odčítanie
    
      - porovnanie

# Načo smerníková aritmetika?

  - Vieme sa pozrieť do vedľajšieho miesta.
    
      - pripočítaním konštanty.

  - Vieme prechádzať pole pomocou smerníka.
    
      - posunúť smerník pripočítaním konštanty a ukončiť porovaním s
        adresou konca poľa.

# Načo smerníková aritmetika?

  - Vieme zistiť aký index v poli má daná adresa.
    
      - odpočítaním začiatku poľa.

  - Vieme zistiť či adresa patrí do poľa.
    
      - porovaním so začiatkom a koncom poľa.

# Pole znakov

    char ahoj[6] = "ahoj";

    index:    0   1   2   3   5   6
             +---+---+---+---+---+---+
    hodnota: | a | h | o | j | 0 | x |
             +---+---+---+---+---+---+
    adresa:   10  11  12  13  14  15

# Pole celých čísel

    int pole[4] = {4,3,2,1};

    index:    0     1       2       3
             +------+------+-------+-------+
    hodnota: |  4   |  3   |  2    |   1   |
             +------+------+-------+-------+
    adresa:  \#10   \#14   \#18    \#22

# Pri aritmetických operáciách sa berie do úvahy veľkosť jedného miesta

Posun smerníka o 1 znamená posun o jedno **pamäťové miesto**

(nie o jeden bajt).

# Meno poľa je adresa jeho začiatku

Každá adresa môže byť začiatkom poľa.

# Posun smerníka v poli znakov

``` c
char ahoj[7] = "ahoj";
char* zaciatok = ahoj;
char* adresa_druheho_prvku = zaciatok + 1;
char hodnota_druheho_prvku = *adresa_druheho_prvku;
```

# Posun smerníka v poli celých čísel

``` c
int pole[4] = {4,3,2,1};
int* zaciatok = pole;
int* adresa_druheho_prvku = zaciatok + 1;
int hodnota_druheho_prvku = adresa_druheho_prvku[0];
```

# Zistenie hodnoty v poli

Pomocou smerníkovej artitmetiky:

    int hodnota = *(pole + index);

Pomocou indexu:

    int hodnota = pole[index];

# Príklad: Premena reťazca na celé číslo

Na začiatku reťazca máme cifry a tie chceme premeniť na celé číslo.

Chceme aj zistiť, kde sa nachádza koniec.

# Premena reťazca na celé číslo (pomocou indexu)

``` c
int convert(const char* str,int* result){
    int l = strlen(str);
    *result = 0;
    for (int i = l-1 ; i>=0; i++){
        char c = str[i];
        if (c >= '0' && c <= '9'){
            result += (l -1 -i) * 10 + c - '0';
        }
        else {
            return -1;
        }
    }
    return l;

}
```

# Premena reťazca na celé číslo

Pomocou smerníkov a Hornerovej schémy

``` c
char* convert(const char* str,int* result){
    char* head = str;
    *result = 0;
    while (*head >= '0' && *head <= '9'){
        *result += *result*10  + *head - '0';
    }
    return head;
}
```

# Pole smerníkov

# Pole smerníkov

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

# Pole smerníkov

<https://en.wikipedia.org/wiki/Quipu>

# Príklad: Načítanie riadkov a ich zotriedenie

``` c
char* words[100];
char line[100];
for (int i = 0; i<100; i++){
    char* r = fgets(line,100,stdin);
    if (r == NULL){
        break;
    }
    int l = strlen(line);
    words[i] = malloc(l + 1);
    memcpy(words[i],line,l+1);
}
```

# Zotriedenie reťazcov v poli smerníkov

``` c
int compare(const void* s1,const void* s2){
    char* str1 = *((char**)s1);
    char* str2 = *((char**)s2);
    return strcmp(str1,str2);
}
```

# Dvojrozmerné pole vs pole smerníkov

Pracuje sa s nimi podobne

``` c
char** pole_smernikov[10];
char z1 = pole_smernikov[1][1];

char dvojrozmerne_pole[10][10];
char z2 = dvojrozmerne_pole[1][1];
```

## Matica

``` 
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
```

# Dvojrozmerné pole v pamäti

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

# Časté chyby pri práci s pamäťou

  - Neinicializovaná pamäť

  - Prístup mimo vyhradenej oblasti

# Ladenie s pomocou Valgrindu

pomôže Vám ak náhodou používate nevyhradenú alebo neinicializovanú pamäť
