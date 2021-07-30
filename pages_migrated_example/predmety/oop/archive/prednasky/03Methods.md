class: center, middle 
# Životný cyklus objektu a balíčky

Prednáška č.3 z Objektovo orientovaného programovania

Ing. Daniel Hládek PhD.

---

# Opakovanie

Princípy objektovo orientovaného programovania:
- abstrakcia
- dedičnosť
- zapuzdrenie
- polymorfizmus

Kľúčové pojmy:
- objekt
- trieda

---

# Objektové programovanie v Jave
     
programovanie = Abstrakcia

- (skoro) všetko je objekt
- Program je skupina objektov ktoré medzi sebou komunikujú správami
- Každý objekt má svoj typ
- Objekty rovnakého typu rozumejú rovnakým správam

---
# Z čoho sa skladá trieda

Patria k inštancii:
- členské premenné 
- členské metódy: majú prístup k členským premenným


# Slovíčko static

Patria k triede:

- statické atribúty
    - existuje jediná inštancia atribútu
    - podobné ako globálna premenná
- statické metódy
	- podobné ako fukcia v jazyku C
    - majú prístup k statickým atribútom 

---

# Čo sú metódy a atribúty

- stav objektu a zmena stavu objektu

Členské atribúty definujú stav objektu.

Metódy pracujú s atribútmi a menia stav objektu.

---
# Rozhranie triedy

Trieda má svoje rozhranie, ktoré definuje ktoré časti sú dôležité pre znuvupoužitie a ktoré sú implementačné detaily.

- public : Verejné časti definujú rozhranie triedy.
- private : Atribúty by mali byť súkromné.
- protected : Časti určené na využitie potomkami triedy

# Prístupové metódy


Členské premenné by mali byť súkromné.

Prístupové metódy sú súčasť rozhrania - umožnňujú modifikáciu stavu objektu.

https://stackoverflow.com/questions/11498287/accessor-methods-in-java


---



# Obsah prednášky

- Životný cyklu objektu
	- inicializácia
    - používanie referencie
    - uvoľnenie
- Tvorba a používanie balíčkov

---

# Životný cyklus objektu

Veľké množstvo chýb sa týka zanedbanej inicializácie a uvoľneniu pamäte. 
Objektový štýl programovania to rieši pomocou predpísanej formy inicializácie a 
finalizácie (uvoľnenia prostriedkov).

- Inicializácia
	- vyhradenie zdrojov
    	- pamäť
        - súbor
        - spojenie
	- definovanie počiatočného stavu
    	- inicializácia premenných
- Zmena stavu objektu
	- volanie členských metód
- Uvoľnenie zdrojov
	- zatvorenie súborov, spojení a uvoľnenie pamäte

---
# Príklad: Životný cyklus kávového automatu

https://www.google.sk/search?q=coffee+machine

1. Zapni sa
	- Vykoná sa inicializácia a automat sa pripraví na činnosť - nahreje vodu.
1. Vykonaj činnosť
	- Automat robí to, čo má (varí kávu).
1. Vypni sa
	- Automat sa vypne a uvoľní zdroje (vysype usadeninu).
    
---
# Inicializácia objektu

Každá členská premenná musí mať povinne 
pridelenú nejakú počiatočnú hodnotu konštruktorom alebo statickým inicializátorom.

- statický inicializátor
- konštruktory

Kompilátor Java kontroluje správnu inicializáciu objetov.
Nedovolí, aby sme používali nesprávne inicializovaný objekt.

Tvorba a inicializácia objektu sa v Jave nedá oddeliť.

---

# Čo je statický inicializátor

Výraz, ktorý vráti refenciu na hotový objekt.
- konštanta (napr. Math.PI)
- literál (napr. 2, "Ahoj")
- statická metóda
- tvorba nového objektu pomocou new

---
# Čo je to konštruktor

Konštruktor je špeciálna metóda pre tvorbu objektu a inicializuje čerstvo vytvorený objekt.
Podľa dohody konštruktor nemá návratový typ. 

Dohoda hovorí, že konštruktor je metóda, ktorá sa musí volať rovnako ako trieda.

Aké je poradie inicializácie v triede (členy, konštruktory)?
- najprv statická inicializácia
- potom vybraný konštruktor

Slovíčko *this*:
- Iba v ne-statických metódach a konštruktoroch
- aj volanie iných konštruktorov v rovnakej triede

---

# Default konštruktor

Nemá žiadne parametre.

Poznámka: Default konštruktor je dôležitý aj v prípade, že používame kolekcie.

Keď nie je jasné, ktorý konštruktor použiť, použije sa tento.

Príklad triedy s konštruktorom:
```java
class Robot{
	int bateria;
    Robot(){
    	bateria = 100;
    }
}
```

Konštruktor Robot() je volaný vždy, ked vytvoríme novú inštanciu triedy Robot.

---
# Viacnásobný konštruktor

Čo ak existuje viac metód inicializácie objektu?

Nemusíme mať vždy všetky možnosti a informácie k dispozícii.

Príklad:

https://www.youtube.com/watch?v=IYoQLfrvPzU

---
# Parametrický konštruktor

Môže mať niekoľko parametrov.


```java
class Robot{
	private int bateria;
    private String name;
    public Robot(){
    	bateria = 100;
    }
    public Robot(String name){
    	this.name = name;
    }
}
```
Kde som spravil chybu?

(Akú bude mať hodnotu bateria a name?)


---
# Oprava: Trochu lepší robot


Počiatočné hodnoty je dobré vždy vyjadriť explicitne (tak aby sa to dalo vyčítať z kódu) a nespoliehať sa na prekladač.

```java
class Robot{
	private int bateria;
    private String name;
    public Robot(){
    	// V konštruktore je možné volať rôzne metódy
    	init("Karel");
    } 
    public Robot(String name){
        init(name);
    }
    private init(String name){
    	bateria = 100;
        this.name = name;
        System.pout.println("Ahoj volám sa " + name);
    }
}
```

---
# Pozor, vznikol polymorfizmus! - Preťažovanie konštruktorov

Konštruktor Robot je polymorfický - tá istá metóda má viacero možných správaní.

Môžeme si definovať viac metód s rovnakým menom ale s rôznymi parametrami.

To ktorá metóda (konštruktor) sa bude volať sa určuje počas prekladu podľa toho aký typ oužívame pri volaní.
- static binding
- early binding
- compile-time polymorphism

http://freefeast.info/difference-between/difference-between-runtime-polymorphism-and-compile-time-polymorphism/

---

# Príklad na viacnásobný polymorfický konštruktor

Využitie referencie this na volanie konštruktora

```java
class Robot{
	private int bateria;
    private String name;
    private cislo;
    public Robot(){
    	// referenciu this je možné využiť na volanie iného konštruktora
    	this(5,"Karel");
    } 
    public Robot(String name){
        this(5,name);
    }
    public Robot(int cislo){
    	this(cislo,"Karel");
	}
    public Robot(int cislo,String name){
    	bateria = 100;
        this.cislo = cislo;
        this.name = name;
        System.pout.println("Ahoj volám sa " + name + "a mam cislo " + cislo);
    }
}
```

---
# Volanie polymorfického konštruktora

rovnaký názov metódy a rôzna funkčnosť

```java
class Main{
	static int main(String[] argv){
    	// Default konštruktor - tu je to jasné?
    	Robot nejaky = new Robot();
        // Konštruktor s jedným parametrom
        Robot karel = new Robot("Karel");
        //Ako sa bude volať nový robot?
        Robot cislo5 = new Robot(5);
   
    }
}
```

---

# Preťažovanie metód

Aj obyčajné metódy môžu byť polymorfické.
Kompilátor správnu metódu vyberie podľa typu a počtu parametrov.

```java
class KavovyAutomat {
	// Táto metóda je ľahko rozlíšiteľná podľa počtu parametrov
    public void zaplat(int bankovky,int mince){
	    System.out.println("Zaplatili ste v hotovosti");
    }
    // Tu je treba rozlišovať podľa typu parametra
    public void zaplat(int mince){
	    System.out.println("Zaplatili iba v drobnych");
    }
    public void zaplat(String cisloKarty){
    	System.out.println("Zaplatili kartou");
    }
}

```

---
# Príklad na polymorfizmus

Trieda Math zo štandardnej knižnice, ktorú budete potrebovať pri zadaniach.

https://docs.oracle.com/javase/8/docs/api/java/lang/Math.html

---

# Polymofizmus a návratová hodnota

Otázka na rozmýšľanie - Je možné rozlíšť metódu podľa jej návratovej hodnoty?

Je možné mať dve metódy ktoré sa líšia iba návratovým typom?

```java
class Robot{
	int daj_peniaze(){
    	return 1;
	}
    double daj_peniaze(){
    	return 1.1;
	}
}
```

Vyskúšajte!

---
# Referencie -  Fáza života objektu

Počas života objektu voláme metódy a meníme stav objektu. 
Volanie konštruktora pomocou *new* vráti referenciu na nový objekt.
Referenciu na objekt je možné odovzdať inému objektu ako argument metódy.

```java
class Auto {
	private benzin = 100;
    Robot naKorbe;
    void nalozRobota(Robot robot){
    	benzin -= 1;
        naKorbe = robot;
    } 
    
    Robot vylozRobota(){
    	Robot result = naKorbe;
        naKorbe = null;
        return result;
    }
}
```

Na jeden objekt môže existovať viac referencií.

---
# Koniec života objektu

Objekt môže byť uvoľnený, ak na neho neexistuje žiadna referencia.

```java
class Main{
	static int main(String[] argv){
       Robot karel = new Robot();
       karel.uvarKavu();
       // Karla už nebudem potrebovať, radšej zavolám Jozefa
       karel = new Robot("Jozef");
       // Čo sa stalo s karlom? 
       // stal sa z neho objekt vhodný na uvoľnenie
    }
}
```

Tu nenastáva memory-leak vďaka garbage collectoru.

---
# Zrušenie referencie

O uvoľnenie objektu môžeme požiadať aj pomocou prázdnej referencie (null).


```java
class Main{
	static int main(String[] argv){
       Robot karel = new Robot();
       Auto dodavka = new Dodavka();
       dodavka.nalozRobota(karel);
       karel = null;
       dodavka.cestuj();
       // Koľko existuje referencí na Karla?
       karel = dodavka.vylozRobota();
    }
}


```

---
# Deštruktor v Jave

Ak na objekt neexistujú referencie, je možné ho uvoľniť.

Nie je jasné, kedy bude metóda finalize volaná (nemusí byť nikdy).

Táto metóda sa používa na uvoľnenie prostriedkov ako sú otvorené súbory a spojenia.

Aj tak je dobré uvoľniť prostriedky objektu explicitne volaním metódy (napr. shutdown()). 


---
# Príklad na deštruktor

(ale nie je to v pravom slova zmysle deštruktor)

Len pre zaujímavosť - vyskúšajte si sami.

```java
class Robot{
	
    public Robot(){
    	System.out.println("Ahoj svet");
    } 
    public void finalize(){
    	// Túto meódu bude volať deštruktor, nie je ale jasné kedy a či vôbec
       	System.out.println("Astalavista");
    }
}
```

---
# Ako funguje Garbage Collector

- Java Garbage Collector je veľmi zložitý
- Počítanie referencií (nie v Jave)
- Hľadanie objektov v stacku na ktoré nie sú referencie

Ak na objekt neexistujú referencie, stane sa vhodným na uvoľnenie.

*V Jave nie je jasné, kedy bude objekt uvoľnený!*

---
# Tvorba a používanie balíčkov

---
# Moduly

Kód je organizovaný do:
- Knižníc (JAR súbor)
- Balíčkov
- Tried

Na úrovni balíčkov a tried vieme oddeliť rozhranie a zakryť implementačné detaily.

Na verejné časti sú kladené väčšie nároky
- rozhranie by sa nemalo meniť
- rozhranie by malo byť dobre zdokumentované

Čo nie je verejné by malo byť súkromné.

Utajovať a utajovať - vždy používať private, pokiaľ sa to dá.

---
# Balíčky v Jave

https://docs.oracle.com/javase/tutorial/java/package/index.html

Kód v organizujeme do balíčkov.

Balíček nie je knižnica
balíček je skupina tried ktoré spolu súvisia.

---

# Plné meno triedy

Balíček je jeden menný priestor - skupina tried, ktoré spolu súvisia.

Každá trieda má svoje plné meno, ktoré zahŕňa aj meno balíčka.
(podobne ako meno a priezvisko)

fully qualified name

Jedna trieda = jeden súbor

---
# Meno balíčka

- malými písmenami
- obsahuje bodky
- napr. webová stránka mojej školy, od zadu
	
    sk.tuke.oop.mojbalicek

Platí dohoda, že balíček umiestnim do adresárovej štruktúry, ktorá vyjadruje meno balíčka

napr.

	src/tuke/oop/mojbalicek/Robot.java
    src/tuke/oop/mojbalicek/Auto.java
    
src je miensto kde dávama zdrojové súbory, všetky ostatné zložky vyjadrujú meno balíčka.

---
# Príklad nového balíčka
   
Prvý riadok v súbore označíme menom balíčka do ktorého trieda patrí

kľúčové slovo package
```java
package sk.tuke.kemt.oop

public class Robot {
	void pozdrav(){
    	Systemout.println("Ahoj svet");
    }
}

```
Plné meno triedy bude: sk.tuke.kemt.oop.Robot
a musí byť v súbore src/sk/tuke/kemt/oop/Robot.java.

---

# Používanie balíčka


V zdrojovom kóde môžeme využívať:
- ľubovoľnú triedu s použitím jej plného mena
- triedy z balíčka
- triedy, ktoré sme importovali z iných balíčkov pomocou príkazu import

Import jedného balíčka neovplyvňuje import druhého.

Medzi balíčkami *neexistuje hierarchia* (aj keď to tak môže vyzerať, lebo mená balíčkov tvoria hierachiu).

Každý balíček je samostatná jednotka.

Pomocou * vieme importovať všetky triedy z balíčka.

---

# Príklad používania balíčka

Ak pracujeme na zadaní v balíčku sk.tuke.kemt.oop.zadanie a chceme využívať Robota z prednášky,
môžeme využiť plné meno triedy:

```java
package sk.tuke.kemt.oop.zadanie;

public class Uloha {
	void static robotPozdrav(){
    	sk.tuke.kemt.oop.Robot robot = new sk.tuke.kemt.oop.Robot();
        robot.pozdrav();
    }
}

```

---
# Import

To nie je veľmi praktické. Môžeme použiť import a Robot sa stane súčasťou aktuálneho menného riestoru.

```java
package sk.tuke.kemt.oop.zadanie;
import sk.tuke.kemt.oop.Robot;
// alebo môžeme naimportovať všetko
import sk.tuke.kemt.oop.*;

public class Uloha {
	void static robotPozdrav(){
    	Robot robot = new Robot();
        robot.pozdrav();
    }
}

```


---
# Zhrnutie

Život objektu má tri fázy (v jazyku C to je podobne):
- inicializácia
- použite referencie
- uvoľnenie

Pri inicializácii pomocou new voláme konštruktor.
Konštruktor aj metódy môžu byť polymorfické, rozlišuje sa medzi nimi počas 
prekladu podľa počtu a typu argumentov.

Triedy organizujeme do balíčkov.
Balíček by mal byť v zložke podľa svojho mena, inak ale balíčky medzi sebou nesúvisia.
Ak chceme využívať nejakú triedu, môžeme využiť jej plné meno, alebo import do aktuálneho menného priestoru.

---
# Na domácu úlohu

Tu je poloha vyjadrená pomocou 2 nezávislých atribútov
Bolo by výhodné si spravit triedu Poloha a pracovat s ňou.

Pridajte do Robota metódu poloha(), ktor8 bude vracať inštanciu triedy Poloha.
Stav robota bude vyjadrený jeho polohou.
Poloha bude vyjadrená pozíciu x a y.

```java

public class Robot {
    private int x = 0;
    private int y = 0;
    public void chod_na_sever() {
        x = x + 1;
    }
    public void chod_na_juh() {
        x = x + 1;
    }
    public void povedz_kde_som() {
        System.out.println(String.format("%d %d",x,y));
    }
    
}

```

---

#  Bibliografia 

ECKEL, B.: Thinking in Java. 4th Edition, Prentice Hall, 2006

    Initialization & Cleanup (pp. 107 – 144)
    Access Control (pp. 145 – 164)


class: center, middle 
---
# Koniec

<img src="three-comrades-end-title-still.jpg" width="600" height="400"/>
