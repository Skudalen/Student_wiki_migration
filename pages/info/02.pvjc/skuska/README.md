# Skúška
:toc:

## Skúška pre študentov Počítačových sietí

Tieto informácie budú postupne aktualizované.

### Príprava na skúšku

- Programátorské minimum
  * načítanie reťazca
  * konverzia reťazca na celé číslo a naopak
  * vytvorenie a používanie funkcie s parametrami a návratovou hodnotou
  * aritmetické operácie: sčítanie, odčítanie, delenie, násobenie, modulo
- Štruktúry
  * definícia
  * inicializácia
  * operátor . a ->
- Polia
  * meno poľa je smerník na jeho začiatok
  * prístup pomocou indexu
- Reťazce
  * posledný prvok reťazca je nula
  * zisťovanie dĺžky reťazca
  * kopírovanie reťazca
- Dynamická alokácia pamäte
  * funkcia malloc a free
  * operátor sizeof
  * operátor *
  * operátor ->
- Spojkový zoznam
  * definícia jedného prvku spojkového zoznamu
  * pridanie prvku na koniec spojkového zoznamu
  * prechádzanie spojkového zoznamu
- Regulárne výrazy
  * zistenie či je reťazec dátum alebo nie
  
### Odporúčané študijné materiály

Odporúčam si prejsť ešte raz príklady z týchto materiálov:

- Programátorské minimum
- Prednáška 2, 4, 6, 8
- Cvičenie 1, 4, 7, 8, 10


## Možné príklady na skúšku

### Spracovanie reťazcov

1. Navrhnite funkciu ```is_date```, ktorá zistí, či je zadaný reťazec dátum vo formáte DD.MM.YYYY . Argument funkcie bude reťazec.
Funkcia bude mať celočíselný návratový typ. Nenulová návratová hodnota znamená, že zadaný reťazec je dátum v platnom tvare, nula znamená, že nie je. 
+
1. Navrhnite funkciu ```is_ip```, ktorá zistí, či je zadaný reťazec platná IP adresa v desiatkovom tvare A.B.C.D , kde (ABCD sú celé čísla v intervale od 1 až po 255) . Argument funkcie bude reťazec.
Funkcia bude mať celočíselný návratový typ. Nenulová návratová hodnota znamená, že zadaný reťazec je dátum v platnom tvare, nula znamená, že nie je. 
+
1. Vytvorte program, ktorý zo súboru alebo zo štandardného vstupu načíta zoznam celých čísel a vypíše ich aritmetický priemer. Zoznam celých čísel
môže byť oddelený medzerou alebo novým riadkom. Posledným číslom zo zoznamu bude nula.
+
Príklad vstupu:

    1 2 3 4 5 0
+    
Príklad výstupu:
    
    3.0
      
1. Vytvorte program, ktorý načíta zoznam slov oddelených medzerou alebo koncom riadku. Na konci vypíše každé slovo na osobitný riadok ohraničené znakmi ```>>``` a ```<<```.
+
Príklad vstupu:

	Ahoj svet.
    Ako sa mas?
+
Príklad výstupu:
        
    >>Ahoj<<
    >>svet.<<
    >>Ako<<
    >>sa<<
    >>mas?<<      

### Spojkový zoznam

Vytvorte program kde využijete spojkový zoznam na správu zamestnancov závodu na spracovanie kovového šrotu.

Pri návrhu postupujte nasledovne:

1. Navrhnite štruktúru ```struct employee```, ktorá bude reprezentovať jeden prvok spojkového zoznamu.
Spojkový zoznam bude uchovávať informácie o mene a veku zamestnanca.

1. Vytvorte funkciu ```create_employee```, ktorá vráti smerník na dynamicky alokovanú pamäť s jedným prvkom spojkového zoznamu.
Argumenty funkcie budú počiatočné hodnoty, ktoré sa uložia do prvku spojkového zoznamu. 
Pamäť inicializujte podľa argumentov funkcie.

1. Vytvorte funkciu ```add_employee``` pre pridanie nového prvku na koniec spojkového zoznamu. 
Argumentom funkcie bude smerník na prvý prvok spojkového zoznamu a smerník na prvok, ktorý sa má pridať. Prvý prvok spojkového zoznamu môže byť NULL v prípade, že 
je spojkový zoznam prázdny. Návratová hodnota funkcie bude smerník na prvý prvok modifikovaného spojkového zoznamu. 
+
Triviálna implementácia funkcie bude vyzerať takto:

    struct employee* add_employee(struct employee* first,struct employee* first){
        return NULL;
    }

1. Vytvorte funkciu ```free_employees``` pre uvoľnenie všetkých prvkov dynamicky alokovaného prvku spojkového zoznamu.
+
Triviálna implementácia bude vyzerať takto:

    void free_employees(struct employee* first){
    }
    
1. Vytvorte funkciu ```print_young_employees``` pre výpis zamestnancov mladších ako 35 rokov v zadanom spojkovom zozname. Funkcia bude mať prázdnu návratovú hodnotu.

    void print_young_employees(struct employee* first){
    }

1. Vytvorte hlavnú funkciu ```main```, ktorá načíta údaje o zamestnancoch do spojkového zoznamu a vypíše zamestnancov mladších ako 35 rokov. 
  
