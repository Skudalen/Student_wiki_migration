# Bicyklová reťaz: cykly a reťazce

Pomocou našich zázračných programátorských schoností sme boli schopní vo veľmi krátkom čase 
navrhnúť a implementovať kalkulačku vhodnú aj pre netechnické typy.
Stále tam však zostávajú viaceré nedostatky. 
V prípade, že zadáme nesprávny vstup, musíme celý proces začať od znova. 

V tejto kapitole upravíme kalkulačku tak, aby sa nevzdávala pri prvom neúspechu,
ale vytrvalo prosila o správny vstup až kým sa to nepodarí. Na to využijeme cyklus typu while,
ktorý bude prebiehať dovtedy, pokiaľ je splnená podmienka:

	while(1){
    	printf("Ja neprestanem\n");
    }

Zápis cyklu typu while je veľmi podobný podmienke if, hlavný rozdiel je v tom, že telo cyklu
môže byť vykonané viac krát (pokiaľ platí podmienka).
Podmienka je splnená ak je vyhodnotená na nenulovú hodnotu, takže takýto cyklus bude 
priebiehať do nekonečna (alebo pokiaľ nezrušíme celý proces).

Ak vieme napísať cyklus, nebude problém modifikovať program tak, aby požiadavka na vstup 
prebiehala dovtedy, pokiaľ nebude vstup správny. Inými slovami, ak bide vstup nesprávny tak sa bude požiadavka
opakovať. Aby nám cyklus prebehol aspoň raz, 
nastavíme počiatočnú hodnotu premennej pocet_hodnot na nulovú hodnotu.


```c
#include <stdio.h>

int spocitaj(int a,int b){
	return a + b;
}

void vypis_sucet(int a,int b){
	int vysledok = spocitaj(a,b);
    printf("Vysledok spocitania %d + %d je %d\n",a,b,vysledok);
}

int main(){
	printf("Súčtová kalkulačka\n");
	int pocet_hodnot = 0;
    int a = 0;
    while (pocet_hodnot != 1){
		printf("Prosím zadajte prvý argument\n");
    	pocet_hodnot = scanf("%d",&a);
    }
    int b = 0;
    pocet_hodnot = 0;
    while (pocet_hodnot != 1){
		printf("Prosím zadajte druhý argument\n");
    	pocet_hodnot = scanf("%d",&b);
    }
    vypis_sucet(a,b);
	return 0;
}
```

# Úloha na precvičenie

Vyskúšajte si tento program a skúste zistiť, prečo sa program v prípade nesprávneho vstupu správa nečakane.
Modifikujte tento program tak, aby v rípade nesprávneho vstupu o tom vypísal správu.

# Načítanie reťazca

Zistili sme, že takto napísaný program síce funguje skvele, ale iba v prípade že sa nevyskytnú "neočakávané" okolnosti
(nesprávny vstup od používateľa). Dôvodom je to, že funkcia scanf nie je veľmi užitočná. Obsahuje vnúotorný buffer (pomocnú premmnnú),
ktorá sa vyprázdni iba v prípade, že vstup z klávesnice bol správny. V prípade, že bol vstup nesprávny
tak tam nesprávna hodnota ostane, až pokiaľ nebude spracovaná. Ďalšie volania funkcie scanf 
potom namiesto vstupu od používateľa stále pracujú s pôvodným, nesprávnym vstupom. Vyplýva z toho, že funkcia scanf
je použiteľná iba na veľmi jednoduché príklady, ale nie je vhodná na reálne použitie.
Našťastie, riešenie je pomerne jednoduché - naprogramovať si vlastný "buffer", do ktorého budeme ukladať vstup od používateľa.
Premenu vstupu z klávesnice na číslo budeme vykonávať osobitne na vlastnom buffri.

Zmena nášho programu bude taká, že namiesto celého čísla, ktoré je možné zapísať nesprávne budeme očakávať
všeobecnejší typ **reťazec**.  Každý znak je v pamäti reprezetnovaný
jedným kódom. Reťazec je sada znakov ukončená nulou.

Klasické premenné v jazyku C umožnujú uloženie iba jednej hodnoty. Aby sme si mohli do premennej uložiť
viac hodnôt, musíme o tom prekladaču povedať. Napríklad ak chceme "rozšíriť" celočíselnú premennú na viacero miest,
môžeme napísať:

	int viac_cisel[4];

Rozdiel od klasického zápisu deklarácie premennej (príkazu na vyhradenie pamäťového miesta) 
je použitie hranatých zátvoriek. Pomocou hranatých zátvoriek v deklarácii premennej vravíme prekladaču, aby 
vyhradil viac miest naraz. Vyhradeniu viacerých pamňťových miest rovnakého typu vedľa seba vravíme **pole**. Celé si to vieme predstaviť ako rebrík:

OBRAZOK

Pole si môžeme zostaviť z ľubovoľného dátového typu, napr. float. Na uloženie znaku je v jayzku C najvhodnejší typ char.
Keďže reťazec je pole znakov zakončené nulou, pamäť pre uchovanie 10 znakového reťazca si vyhradíme takto:

	char retazec[11];

Posledné políčko poľa musíme vyhradiť pre zápis nuly na konci.

Ak si chceme zapamätať ľubovoľný vstup od používateľa, môžeme zapísať:

	char retazec[100];
    printf("Zadajte hocijaký vstup:");
    scanf("%s",retazec);
    printf("Napísali ste: %s\n");

Formátovacím znakom pre načítanie reťazca je %s. Ďalším rozdielom je, že pri druhom argumente funkcei scanf
nemusíme uviesť operátor &, lebo **názov poľa je zároveň adresou jeho prvého prvku**. Slabinou thoto programu je,
že používateľ nesmie zadať viac ako 99 znakov, inak sa zvyšné znaky zapíšu mimo vyhradenej pamäte.

# Konverzia reťazca na číslo

Zistili sme, že v jazyku C sú reťazec a číslo dve rozdielne veci. Zjednodušene môžme povedať, že reťazec je viac
hodnôt vedľa seba, číslo je iba jediná hodnota. 
Na to aby sme so zadaný reťazcom vedeli vykonávať matematické operácie, musíme si ho premeniť na číslo.
Tento krok do teraz robila za nás funkcia scanf, ktorá premieňala vstup na z klávesnice vo forme reťazca 
bez toho, aby sme o nejakých reťazcoch tušili. Zistili sme ale, že má určité obmedzenia, kotré je potrebné obísť.

Riešenie je našťastie jednoduché - konverziu na číslo je močné jendoduchu vykonávať nie len z klávesnice,
ale aj z hdoôt, kotré sme si poznačili pred tým do poľla. Slúži na to funkcia sscanf, ktorá sa správa rovnako ako funkcia scanf,
ale namiesto klávesnice pracuje s reťazcom, ktorý jej zadáme ako argument. Netrpí teda problémom so zasekávajúcim sa buffrom.

Konverziu reťazaca na číslo pomocou fiunkcie sscanf vykonávame takto:

	int cislo = 0;
    int pocet_hodnot = 0;
    char retazec[10] = "12";
    pocet_hodnot = sscanf(retazec,"%d",&cislo);
    printf("Vase cislo je %d",);

# Celý program

Celý program bude potom vyzerať takto:

```c
#include <stdio.h>

int spocitaj(int a,int b){
	return a + b;
}

void vypis_sucet(int a,int b){
	int vysledok = spocitaj(a,b);
    printf("Vysledok spocitania %d + %d je %d\n",a,b,vysledok);
}

int main(){
	printf("Súčtová kalkulačka\n");
	int pocet_hodnot = 0;
    int a = 0;
    char buffer[100];
    while (pocet_hodnot != 1){
		printf("Prosím zadajte prvý argument\n");
    	scanf("%s",buffer);
        pocet_hodnot = sscanf(buffer,"%d",&a);
    }
    int b = 0;
    pocet_hodnot = 0;
    while (pocet_hodnot != 1){
		printf("Prosím zadajte druhý argument\n");
 		scanf("%s",buffer);
        pocet_hodnot = sscanf(buffer,"%d",&b);
    }
    vypis_sucet(a,b);
	return 0;
}
```
    








