---
title: Anketa Študent roka
published: true
---

! Naučíte sa
!
! - Pracovať poľom štruktúr.
! - Pracovať s operátorom `->`.
! - Dynamicky pretypovať smerník pomocou operátora `()`.
! - Vytvoriť porovnávaciu funkciu.
! - Triediť pomocou funkcie `qsort`.


Časopis Emmma vypísal každoročnú anketu v ktorej čitatelia určia "Emmma Študent roka 2021". Do súťaže sa môže prihlásiť ktokoľvek\! Našou úlohou bude pomôcť pri sčítavaní hlasov.

Navrhneme jednoduchú databázu mien, v ktorej budeme ku každému menu evidovať počet hlasov, ktoré študent dostal od čitateľov časopisu Emmma.

Meno a počet hlasov bude uvedený na jednom riadku a bude oddelený medzerou.

Vaša aplikácia by mala spočítať všetky hlasy pre každého študenta a výsledky zotriediť podľa podľa počtu hlasov.
V prípade, že viac študentov má rovnaký počet hlasov tak ich zotrieďte podľa abecedy (lexikograficky).

## Naštudujte si

Využijete tieto časti štandardnej knižnice:

  - [fgets()](http://www.cplusplus.com/reference/cstdio/fgets/) na načítanie jedného riadka,
  - [qsort()](http://www.cplusplus.com/reference/cstdlib/qsort/) na triedenie,
  - [strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/) na lexikografické porovnanie dvoch reťazcov,
  - [memcpy()](http://www.cplusplus.com/reference/cstring/memcpy/) na kopírovanie ľubovoľného poľa alebo reťazca.
  - [strtol()](https://www.cplusplus.com/reference/cstdlib/strtol/) na premenu reťazca na celé číslo a na zistenie konca čísla.
  - [strlen()](https://www.cplusplus.com/reference/cstring/strlen/) na zisťovanie dĺžky reťazca.
  - [memset()](https://www.cplusplus.com/reference/cstring/memset/) na inicializáciu pamäte.

Pozrite si predpis funkcie, návratovú hodnotu, spôsob hlásenia chybových statvov, opis argumentov a čo funkcia robí.

## Analýza riešenia

Definujeme si dátový typ štruktúra pre uloženie jednej položky databázy. 

Jeden študent je definovaný pomocou:

- mena (reťazec),
- počtu hlasov (celé číslo).

To si vieme vyjadriť napríklad pomocou takejto štruktúry:

```c
#define SIZE 100

struct student {
    char name[SIZE];
    int votes;
};
```

Konštanta `SIZE` nám pomôže pri práci s reťazcami a poliami.


Databáza bude tvorená poľom štruktúr konštantnej veľkosti, ktoré si vyhradíme na začiatku. 

Budeme potrebovať aj premennú na uloženie aktuálneho počtu študentov v databáze (to nie je to isté ako maximálny počet ktorý sa zmestí do poľa).
Nikdy nesmieme zabudnúť na inicializáciu pamäte:


```c
struct student databaza[SIZE];
memset(databaza,0,SIZE*sizeof(struct student));
int size = 0;
```

Takto si vyhradíme miesto v pamäti pre maximálne 100 študentov a poznačíme si, že momentálne nemáme zapísaný žiadny záznam.


### Načítanie jednej položky do databázy

Jeden záznam v databáze sa nachádza na jednom riadku.

Prvou úlohou bude premeniť reťazec zo štandardného vstupu na
celé číslo a meno.

Načítajte celý riadok zo štandardného vstupu do pomocného poľa a overte, či ste ho načítali správne:

```
char line[SIZE];
memset(line,0,SIZE);
char* r = fgets(line,SIZE,stdin);
if (r == NULL){
    // Nastal koniec načítania
}
```

Ak sa načítanie podarilo, v poli by sme mali mať celé číslo a meno oddelené medzerou. Za menom sa nachádza aj znak pre koniec riadka.

V pamäti by tom malo vyzerať nejako takto (ak Janko dostal od niekoho 10 hlasov a pole `line` má 11 miest):


```
|<--------------line------------------------>|
+---+---+---+---+---+---+---+---+----+---+---+
| 1 | 0 |   | J | a | n | k | o | \n | 0 | 0 |
+---+---+---+---+---+---+---+---+----+---+---+

|<----->|    |<---------------->|
  počet              meno
```

Našou úlohou bude v reťazci nájsť počet hlasov a meno.

#### Načítanie celého čísla

Pri určovaní počtu hlasov nám pomôže funkcia [strtol()](https://www.cplusplus.com/reference/cstdlib/strtol/) 
ktorá premení reťazec cifier na číslo a zároveň do smerníkovej premennej zapíše adresu prvého znaku ktorý nie je celé číslo. To využijeme pri hľadaní mena za číslom.


```c
char* end = NULL;
int value = strtol(line,&end,10);
if (value == 0){
    // Premena sa nepodarila
}
```

Ak sa konverzia podarila, tak v premennej `end` bude adresa
miesta, kde môžeme pokračovať v hľadaní mena.

Hodnota `end` bude ukazovať na medzeru za číslom:


```
 line    end
  |       |
  v       V
+---+---+---+---+---+---+---+---+----+---+---+
| 1 | 0 |   | J | a | n | k | o | \n | 0 | 0 |
+---+---+---+---+---+---+---+---+----+---+---+

```

#### Načíanie mena

Na uloženie mena bude dobré si vyhradiť ďalšie pomocné pole do ktorého nakopírujeme zvyšok reťazca.
Adresa v pamäti je zároveň aj začiatok poľa, takže zistiť meno bude jednoduché pomocou smerníkovej aritmetiky.
Treba len dávať pozor na to, že koniec riadka nie je súčasťou mena.

Môžme to urobiť napríklad takto:

```c
// pomocné pole
char name[SIZE];
// vynulujeme
memset(name,0,SIZE);
// Vypocitame zaciatok mena
// Jedno miesto za medzerou
char* zaciatok_mena = end + 1;
// Velkost mena je pocet znakov do konca retazca
// minus koniec riadka
int velkost_mena = strlen(zaciatok_mena) - 1;
if (velkost_mena > 0){
    // nakopirujeme
    memcpy(name,zaciatok_mena,velkost_mena);
    // Na konci je v poli name ulozeny retazec s menom
    // bez konca riadka a s nulou na konci
}
else {
    // nepodarilo sa nacitat meno
}
```

### Vyhľadanie položky v databáze

Pri spočítavaní si najprv musíme overiť, či záznam v databáze existuje alebo nie.

Ak sa meno človeka v databáze nenachádza, vložíme ho do prvého voľného
miesta v databáze. Ak sa meno človeka v databáze nachádza, zväčšíme jeho
počet hlasov. 

Na vyhľadanie mena v databáze si vytvorte funkciu, v ktorej prejdete všetky položky v databáze a ak nájdete položku so zadaným menom tak vrátite jej index.

Inak vrátite -1.

Funkcia na vyhľadanie môže vyzerať nejako takto:

```
int find_student(struct student* students,int size, const char* name){
    // Dopíšte cyklus, ktorý prejde všetky položky v databáze
    // a ak nájde zhodné meno tak vráti jeho index.
    return -1;
}
```

### Pridanie položky do databázy

Do pomocnej premennej si uložte index,  kde sa nachádza
položka databázy. Podľa indexu budete vedieť s ktorým miestom v poli manipulujete. Pre prístup k členom štruktúry v poli použite operátor `.` (bodka).

Ak sa položka v databáze nenachádza, nastavte index na prvé
voľné miesto v poli a zväčšite počítadlo počtu prvkov v poli.
Do prvého voľného miesta zapíšte novú položku databázy.

Pozor - reťazce sa nedajú kopírovať pomocou `=`, musíte použiť `memcpy` alebo `strcpy`. Ak použijete `memcpy` tak dávajte pozor, aby bol výsledný reťazec zakončený nulou.


```
int id = find_student(databaza,size,name);
if (id< 0){
    // Skopirujte zaznam na posledne miesto v poli
    memcpy(databaza[size].name,name,velkost_mena);
    // Zvacsite pocet zaznamov 
    size+=1;
}
else {
    // pripocitajte pocet hlasov
}
```

### Triedenie

Po konci načítania zotrieďte
databázu podľa počtu získaných hlasov a zobrazte jej obsah.


Na zotriedenie databázy použite štandardnú funkciu 
[qsort()](http://www.cplusplus.com/reference/cstdlib/qsort/) na triedenie. 

Na správne
zotriedenie je potrebné definovať funkciu na porovnanie dvoch hodnôt,
ktoré dostanete adresu. Názov tejto funkcie uveďte ako posledný argument do funkcie `qsort`.

Funkcia pre porovnanie má vždy rovnaký predpis, ale dá sa použiť na triedenie ľubovoľného poľa.

```
int compare(const void* p1, const void* p2);
```

Pre správne porovnanie dvoch záznamov  je potrebné zmeniť typ smerníka na typ s ktorým pracujeme. 
Vo vašej funkcii pre porovnanie  zmeňte typ (`const void*` na (`struct student*`). Potom s pomocou operátora `->`
získate počet hlasov alebo meno., ktorý môžte porovnať.


``` c
int compare(const void* p1, const void* p2){
    struct student* s1 = (struct student*)p1;
    struct student* s2 = (struct student*)p2;
    // s1->votes je počet hlasov
    // s1->name je meno študenta
    return 0;
}
```
### Odovzdanie

Do Vášho [GIT repozitára](https://git.kemt.fei.tuke.sk) do súboru `program.c` v adresári `du5` cez systém [Traktor](https://traktor.kemt.fei.tuke.sk/#submit/149).

