# Návrh príkladov na skúšku

# Triviálne úlohy

## Svet naopak

Napište program na obrátenie reťazca. Program bude tvorený jednou statickou metódou s predpisom:

	public static String run(String srt);

Ako vstup použite štandardný vstup, výsledok vypíšte na štandardný výstup.

## Kontrolný súčet

Napíšte program na zistenie súčtu ASCII hodnôt všetkých znakov v reťazci. Program bude tvorený jednou statickou metódou s predpisom:

	public static int run(String srt);



   
# Normálne úlohy

## 1. Zmenáreň

Napíšte program, ktorý sa spýta na počet mincí, ktoré máte v peňaženke. 
Na načítane zo štandardného vstupu môžete použiť triedu Scanner.
Používateľ za základe výzvy zadá počet mincí každého typu.
Na konci program vypíše, koľko peňazí má človek v peňaženke, osobitne eurá a osobitne centy.

Napr:

    Koľko máte 2 euroviek?
    1
    Koľko máte 1 euroviek?
    1
    Koľko máte 50 centoviek?
    0
    Koľko máte 20 centoviek?
    1
    Koľko máte 10 centoviek?
    1
    Koľko máte 5 centoviek?
    1
    Koľko máte 1 centoviek?
    1
    Spolu máte 3 eurá a 36 centov.

## 2. Výkaz hodnotenia

Máte zadaný textový súbor, kde sú v riadkoch zapísané informácie o študentoch. Stĺpce sú oddelené čiarkou.
Prvý stĺpec je meno študenta, druhý stĺpec je počet bodov na skúške, tretí stĺpec je známka.
Spracujte súbor a napíšte priemerný počet bodov a najčastejšiu známku.

Príklad súboru:
	
    Ján Hraško		,32,Fx
    Peter Mrkvička	,65,D
    Honza Hlavatý	, 71,C
    Marián Vyvalený ,99 ,A
    Jarmila Pokrývková, 88, B
    Ignác Odkrútený , 78, C
    
Príklad výstupu:

	Priemerný počet bodov je: 72.1 
    Najčastejšia známka je C.



## 3. Matikár

Napíšte program na automatické testovanie žiakov základnej školy.
Program by mal vygenerovať 10 otázok zo spočítavania dvoch náhodne vygenerovaných (malých) číslel.

Na konci vypíšte protokol zo skúšky, kde vyznačíte otázku, odpoveď, a či bola odpoveď správna.

Napr.

    Koľko je 2 + 2 ?
    5
    Koľko je 1 + 2 ?
    3

    Protokol o výsledku:
    2 + 2 = 5 je nesprávne, má byť 4
    1 + 2 = 3 je správne
    
    Máte 1 správnu odpoveď z 2 otázok.

Časť programu by mala implementovať rozhranie:

```
interface MathTest {
	String getQuestion();
    int getCorrectAnswer();
}
```



## 4. Počítadlo slov

V zadanom súbore spočítajte pravdepodobnosť výskytu slov s malým a veľkým písmenom. Obsah súboru môžete skopírovať z dokumentácie JDK.
Zobrazte nájdené slová v abecednom poradí. Dajte pozor, aby program vedel správne identifikovať hranice slov - každé slovo sa musí skladať iba z písmen.

Príklad výstupu:

	Pravdepodobnosť, že sa slovo začína veľkým písmenom: 0.12
    a
    aby
    ak
    ako
    by
    

## 5. Štatistik

Navrhnite triedu pre vykonávanie štatistických výpočtov.
Trieda by mala implementovať nasledovné rozhranie:

```
interface Statistik {
	// Pridá číslo do zoznamu
	void addNumber(float number);
    // Počet čísel v zozname
    int getCount();
    // Súčet čísel v zozname
    float getSum();
    // Aritmetický priemer čísel v zozname
    float getMean();
    // Štandardná odchýlka číslel v zozname
    float getStandardDeviation();
}
```

Príklad výstupu:

	Súčet čísel je: 123
    Počet zadaných čísel: 10
    Priemerná hodnota je: 12,3
    Štandardná odchýlka: 1.12

## 6. Benchmark

Napíšte program na meranie rýchlosti triediaceho algoritmu.
Zmerajte rýchlosť 100 kôl vykonania metódy Arrays.sort.
Pre každý beh si vygenerujte dostatočne veľké náhodné dáta (aspoň 1 000 000 hodnôt).
Pre meranie času môžete použiť metódu System.currentTimeMillis.

Príklad výstupu:

	Meranie rýchlosti triedenia bolo vykonané 1000 krát.
	Zotriedenie 100000 náhodných hodnôť pomocou Arrays.sort trvalo priemerne 123 ms.
	Zotriedenie 100000 náhodných hodnôť pomocou Arrays.selectionSort trvalo priemerne 163 ms.


## 7. Kalkulačka

Implementujte jednoduchú kalkulačku.

Kalkulačka bude ovládaná z príkazového riadka, 
prvý argument je prvý operand, druhý argument je operácia, tretí argument je druhý operand.
Kalkulačka by mala vedieť spočítavať, odpočítavať, násobiť a deliť.

Príklad použitia kalkulačky:

	2 + 2
	4
    2.4 * 5.4
    12.96
    23 24
    Chyba, 24 nie je povolená operácia. Správne použitie je: <arg1> <operácia> <arg2>
    a + b
    Chyba, a nie je povolené číslo. Správne použitie je: <arg1> <operácia> <arg2>


## 8. Konkordancia

Napíšte program, ktorý analyzuje textový súbor a pre každé slovo napíše na ktorých riadkoch sa nachádza.
Do textového súboru skopírujte časť dokumentácie JDK.

Príklad výstupu:

	Slovo	Riadky
    Java	1,3,5,11
    text	4,6,7
    exception	7


