# Ahoj Svet

# Tutoriál č. 1

Cieľom tohto tutriálu je naučiť vás vytvoriť triviálny program v jazyku C. 

Jazyk C patrí medzi tzv. **kompilované** jazyky. 
Znamená to, že pred spustením programu musí prebehnúť proces kompilácie (prekladu), pro ktorom sa človeku
zrozumiteľný zápis prepíše do tvaru, ktorý je zrozumiteľný iba stroju. 
Výhody kompilovaného jazyka sú, že spustenie programu je rýchlejšie a sme schopní odhaliť niektoré chyby 
ešte pred tým ako program vyskúšame.

# Potrebné nástroje

Pre tvorbu vlastných programov budeme potrebovať minálne tieto tri nástroje:
1. Textový editor
1. Kompilátor
1. Textový terminál.

Textový editor je program vytváranie a úpravy textových súborov.
Zdrojový kód píšeme ako textový súbor a preto je dôležité, aby sme boli schopní
ľahko pracovať aj s veľkým množstvom textu. Výber vhodného textového
editora je vecou osobnej preferencie. Pri práci v textovom termináli 
v prostredí OS Linux odporúčame texotový editor vim.

Kompilátor je program, pomocou ktorého preložíme zdrojový text do strojovo čitateľnej formy.
Jedným z najčastejšie používaných kompilátorov je GCC (GNU Compiler Collection).
Hoci je GCC veľmi zložitý systém, jeho použitie je jednoduché.

Textový terminál je priestor interakcie programátora a počítača. Programátor píše sadu príkazov 
pre a systém odpovedá správami. Na začiatku sa Vám môže zdať práca v textovom móde málo intuitívna, 
ale ak sa terminál naučíte správne využívať, môžete pracovať oveľa efektívnejšie ako
keď kombinujete klávesnicu a myš.

# Prvé kroky

Programátorskú prácu začneme tak, že si vyhliadneme vhodný prázdny  **projektový adresár**, 
kde budeme ukladať všetky súbory, ktoré súvisia s naším projektom.
Na začiatku si vystačíme s dvoma súbormi (zdrojovým textom a spustiteľným súborom), 
ale postupom času budeme schopní pracovať s projektami, ktoré sa skladajú zo stoviek súborov.

Aby sa situácia nestala príliš komplikovanou, odporúčame pre každý program vyhradiť osobitný adresár
a nemiešať viacero programov v jednom.

# Vytvorenie zdrojového textu

V textovom editore si otvorme súbor, ktorý môžeme nazvať hello.c a do neho napíšeme:

```c
#include <stdio.h>

int main(){
	printf("Ahoj svet\n");
	return 0;
}
```

Textový súbor uložíme a prvý krôčik máme za sebou. Práve sme vytvorili svoj prvý program.

# Preklad

Náš program, je síce správny, ale počítač bude mať ťažkosti s jeho vykonaním. 
Zdrojový text v jazyku C nie je priamo vykonateľný. 
Našou ďalšou úlohou bude preklad zdrojového textu do tvaru, ktorý sa dá spustiť.
Pužitie kompilátora na zdrojový text, ktorý sme vytvorili je jednoduché:

	gcc hello.c -o hello
    
Ak sme pri prepise neurobili žiadnu chybu,
tak by preklad mal prebehnúť bez problémov a vznikne spustiteľný súbor hello.

# Chybové hlásenia

Ak sme predsa len nejakú chybu urobili, prekladač napíše chybovú hlášku a preklad neprebehne.
Pozorne si hlásenie prečítajte a skúste opraviť chybu. Chybové hlásenie (skoro) vždy obsahuje číslo riadku a znak, kde sa chyba nachádza
a podľa toho sa ku chybe vieme vrátiť. Ak je chybových hlásení viac, ignorujeme všetky okrem prvého. 
Opravíme prvú chybu, preložíme program a sledujeme, či oprava pomohla. 
Ak nie, postup opakujeme dovtedy, pokiaľ nie je preklad úspešný.

# Spustenie programu

Ak preklad prebehol správne, môžeme vyskúšať výsledkok. 
Najprv overíme situáciu, či sa tam spustiteľný súbor naozaj nachádza:

	ls
    hello.c hello
    
Príkaz ls by mal zobraziť zdrojový súbor aj spustiteľný súbor. Spustiteľný súbor môžeme spustiť:

	./hello
    Ahoj svet-
    
# Vývojový cyklus

Tento proces budeme opakovať stále dookola. V prvok kroku sme vytvorili alebo upravili existujúce zdrojové kódy. 
V druhom kroku sme sa pokúsili ich preložiť. 
Ak sa vyskytla chyba, tak sme sa museli vrátiť, znova upraviť zdrojové kódy a znova program preložiť.
Posledným krokom vývojového cyklu je spustenie programu. Ak sme s výsledkom spokpjní, nemusíme pokračovať a výsledný program
môžeme odovzdať do používania. Ak nie, musíme začať znova.

TODO: Vývojový diagram vývoja.

# Úprava programu

Ak aj spustenie prebehlo úspešne, môžem Vám gratulovať - práve ste sa stali 
(začínajúcim) programátorom. Náš prvý program je hotový.

Základy sú síce vybudované, ale výsledná stavba je malá. Zatiaľ vieme slušne pozdraviť, ale to je všetko.
Skúsime využiť vedomosti ktoré máme aby sme výsledok trochu vylepšili.
Okrem sveta skúsme pozdraviť aj niekoho iného.

Nájdime riadok v programe, kotrý pravdepodobne spôsobuje výpis
správy na obrazovku a pozrime sa na neho bližšie:

	printf("Ahoj svet\n");

Okrem správy "Ahoj svet" si všimneme niekoľko vecí, koré nám veľa povedia o jazyku C.  
- Riadok je zakončený bodkočiarkou. Takýto riadok nazývame **príkaz**.
- Správa Ahoj svet je ohraničená uvodzovkami a zakončená znakmi '\n'. 
	Znaky ohraničené úvodzovkami nazývame **reťazec**.
- Okrem správy, ktorá sa má vypísať tam vidíme printf a úvodzovky. Takýto zápis so zátvormai nazývame **volanie funkcie**,
	kde časť pred zátvorkou je **názov funkcie**  a časť v zátvorke sú **argumenty funkcie** .

Program v jayzku C sa skladá z definícií funkcií a ich volaní. Každú funkciu v jazyku C musíme pred volaním definovať, 
lebo jazyk C ako taký nepozná žiadne funkcie, iba spôsob ako ich definovať a volať. 

V prípade funkcie printf je situácia jednoduchá, lebo funkciu už zadefinoval niekto za nás. Nám už iba stačí
"naučiť" kompilátor, čo znamená printff tým, že oznámime, kde definiciu funkcie nájde. 

Na overenie týchto tvrdení použijeme tzv. kreatívnu chirurgiu a mierne zmrzačíme
náš program. Upravíme niektorý riadok programu a zopakujeme proces prekladu. 
S vedeckým odstupom sledujeme čo sa stane:

1. Zmente "svet\n" na "TUKE"

Zistili sme, že "\n" je zápis pre koniec riadku.

1. Zmente printf na print:

Zistili sme, že takú funkciu systém nepozná. Opravte chybu a pokračujeme.

1. Vymažte riadok s "include"

Zistili sme, že napriek očakávaniam kompilátor hlási chybu na riadku s "printf". 

Zoznam funkcií, ktoré môžeme pri práci použiť sa nazýva "Štandardná knižnica jazyka C".

# Úlohy na precvičenie:

1. Modifikujte program tak, aby do prvého riadka vypísal Vaše meno a do druhého riadka Vašu obľúbenú farbu napr.:

	Moje meno je Chuck Norris
    a moja obľúbená farba je čierna.

1. Pozrite si dokumentáciu štandardnej knižnice a skúste využiť ľubovoľnú ďalšiu funkciu, napr. "sleep".
Nezabudnite, že pred použitím musíte funkciu "naučiť" pomocou #include.




