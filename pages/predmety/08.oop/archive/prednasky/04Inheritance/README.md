class: center, middle
# Dátové typy, dedičnosť a polymorfizmus

Prednáška č. 4

Objektovo orientované programovanie

Ing. Daniel Hládek PhD.

---
# Obsah prednášky

- Jednoduché a zložené dátové typy: Odovzdávanie referencie a odovzdávanie hodnoty pri volaní metódy.
- Znovupoužiteľnosť
- Druhy polymorfizmu
	- Preťažovanie metód
	- Prekrývanie metód
    
---
# Čo všetko je objekt v Jave?

Čo je objekt - množina dát a prislúchajúcich metód.

Niektoré typy v Jave túto definíciu nespĺňajú.


---
# Dátové typy jazyka Java

Primitívne typy sa odovzdávajú hodnotou, objekty sa odovzdávajú referenciou.

Objekty sú vždy na kope.

- Primitívne typy
	- odovzdávajú sa vždy hodnotou
	- defaultné hodnoty
- Zložené typy
	- Sú potomkom triedy Object
	- odovzdávajú sa referenciou
    - objekty, alokované na kope.
    
---
# Primitívne typy 

https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html

- Majú definovanú default hodnotu.
- Odovzdávajú sa hodnotou.
- Sú definované pomocou literálu.
- Nedá sa od nich dediť.
- Sú alokované na stacku - kontexte aktuálne volanej finkcie.

Napr.

	boolean result = true;
	char capitalC = 'C';
	byte b = 100;
	short s = 10000;
	int i = 100000;
    // The number 26, in decimal
	int decVal = 26;
	//  The number 26, in hexadecimal
	int hexVal = 0x1a;
	// The number 26, in binary
	int binVal = 0b11010;

---

# Literál

- Výraz, ktorý vráti referenciu no nový objekt alebo hodnotu primitívneho typu.
- Uľahčuje tvorbu niektorých objektov.
- Zápis nejakej konštanty

Pomocou literálu môžeme tvoriť:
- celé čisla
- čísla s desatinnou čiarkou
- binárne čísla
- osmičkové a šestnástkové čísla
- reťazce
- polia


---
# Zložené typy

- Sú vždy potomkom triedy Object
- Sú alokované na kope.
- Inicializácia pomocou operátora new, ktorý volá konštruktor.
- Statická inicializácia 
- Inicializácia pomocou literálu

Defaultná hodnota referencie je konštanta *null*.

https://docs.oracle.com/javase/7/docs/api/java/lang/Object.html

---
# Premenné a konštanty

- *premenné*: Môže existovať viac inštancií
	- členské premenné, patria konkrétnemu objektu
    - statické premenné, patria triede
    - lokálne premenné
- *konštanty*: Existuje práve jedna inštancia
	- mali by to byť statické premenné
	- kľúčové slovíčko final zakazuje zmenu objektu (priradenie je možné ba pri inicializácii)
    - public final static
---
# Príklad na premenné a konštanty

```java
public class Radio {
	// Statické konštanty
	public static final float SLOVENSKO = 96.6;
    public static final float FM = 100.3;
    
    // Členská premenná
    private float frekvencia;
    Radio(){
    	frekvencia = Radio.SLOVENSKO;
    }
    
	public void prelad(float frekvencia){
    	// frekvencia je lokálna premenná
    	this.frekvencia = frekvencia;
        // this.frekvencia je členská premenná
	}
    public float getFrekvencia(){
    	return frekvencia;
    }
}
```

---
# Príklad na odovzdávanie hodnoty

```java
public class Auto {
	private Radio autoradio;
    public void namontuj(Radio autoradio){
    	this.autoradio = autoradio;
    }
    public Radio pozriRadio(){
    	return autoratio;
    }
    
    
    public static void oprav(){
    	Auto chrobak;
        // Akú hodnotu má chrobak?
        chrobak = new Auto();
        // Aku hodnotu ma chrbak.radio ?
        Radio elektronkove = new Radio();
        chrobak.namontuj(elektronkove);
        float f = Radio.FM;
        elektronkove.prelad(f);
        f = 99.0;
        
        
    }
}
```


---

# Kĺúčové slovíčko final

Sľubujeme, že *hodnotu* po inicializácii nebudeme meniť (a prekladač sa o to postará).

https://en.wikipedia.org/wiki/Final_(Java)
https://stackoverflow.com/questions/15655012/how-final-keyword-works

---
# Kopa alebo zásobník

- Kopa: používa sa na dynamickú alokáciu.
- Heap: používa sa na statickú alokáciu. 

https://dzone.com/articles/stack-vs-heap-understanding-java-memory-allocation
http://net-informations.com/faq/net/stack-heap.htm

---

# Znovupoužiteľnosť

- Jeden kód je použiteľný v rôznych sitúáciách.
- To isté nemusíme písať viac krát.
- Vieme ľahšie použiť aj kód ktorý písal niekto iný.
- Ľahko vieme rozšíriť existujúci kód o nové vlastnosti.

---
# Znovupoužiteľnosť v C

V jazyku C si vieme urobiť funkciu a tú funkciu používať viacerými spôsobmi. 

Problém pri znovupoužiteľnosti je:

- Funkciu a štruktúru je ťažko zovšeobecniť.
- Funkciu a štruktúru neviem rozdeliť na menšie časti a využívať iba tie.
- V sade funkcií nie je na prvý pohľad jasné že ktoré funkcie sú podstatné a ktoré nie.

V porovnaní s jazykom C vieme v Jave ľahšie urobiť znovu použiteľný kód.

Princípy objektového programovania nám to uľahčujú.
(Zapuzdrenie, Abstrakcia, Polymorfizmus, Dedičnosť).

---

# Znovupoužiteľnosť pomocou kompozície


Trieda v Jave predstavuje "uzavretú" jednotku dátových štruktúr - modul, ktorý vieme použiť ako celok.

Predstavme si obchod, kde sa dajú kúpiť súčiastky do robotov. Máme robotické ramená, 
ktoré chceme využiť pri konštrukcii robota Karla.

Môžeme si to naprogramovať ako:

```java
public class Rameno {
	public void zober(){
    	System.out.pintln("Mam zeton!");
	}
}
```

---
# Kompozícia - príklad

Robotické rameno síce vie brať žetóny, ale nevie sa pohybovať.
Chceme znovu použiť túto funkcionalitu a skonštruovať robota Karla, ktorý bude pochodovať po miestnosti a brať žetóny.

Ak využijeme kompozíciu, rameno primontujeme na robota Karla:


```java
public class RobotKarel {
	private Rameno lavaruka;
    private Rameno pravaruka;
	public void zober(){
    	lavaruka.zober();
	}
    public void chod(){
    	System.out.println("Krok krok"/);
    }
    Rameno getRameno() {
    	return rameno;
    }
}
```

Takto pri konštrukcii robota Karla nemusíme riešiť, ako robotické rameno funguje, stačí využívať jeho rozhranie. 
Rameno kľudne mohol spraviť niekto druhý, alebo sme ho mohli kúpiť z Číny.

---

# Znovupoužiteľnosť pomocou dedičnosti

Trochu iný prístup môžeme využiť pri konštrukcii robota Jozef, ktorý nemá nohy ale kolesá (podobá sa na pohyblivý kôš na odpadky).

Uvažujeme, že robotické rameno je tiež, robot ale sa nevie pohybovať. 
Rozšírime funkcionalitu robotického ramena tak, že k nemu primontujeme kolesá:

```java
public class RobotJozef extends Rameno {
	public void chod(){
    	System.out.println("Bzzz");
	}
    // metóda zober je zdedená z triedy Rameno
}
```

Robot typu Jozef potom bude vedieť to, čo robotické rameno a plus vlastnú funkčnosť pohybu pomocou kolies.

---
# Znovupoužiteľnosť - príklad

Výsledok bude, že oba roboty je možné ovládať rovnákým spôsobom:

```java
static void main(String args[]){
	RobotKarel karel = new RobotKarel();
    RobotKarel jozef = new RobotJozef();
    karel.chod();
    karel.zober();
    jozef.chod();
    jozef.zober();
}
```

Pozor - karel a jozed sú dve rozdielne inštancie. 
Polymorfickú referenciu je možné využiť iba pri RobotJozef - jeho referencia je zároveň referencou na Rameno.

```java
static void main(String args[]){
    Rameno jozef = new RobotJozef();
    jozef.zober();
    // Pri karlovi musíme povedať. ktoré rameno chceme ovládať
    RobotKarel karel = new RobotKarel();
    // Rozhranie ramena je na karlovi prístupné vďaka prístupovej metóde
    Rameno karlovorameno = karel.getRameno();
    karlovorameno.zober();   
}
```

---

# Aký je rozdiel medzi kompozíciou a dedičnosťou?

Dedičnosť:
- Je možné mať iba jedného predka
- Automaticky môžeme využívať všetky public a protected metódy
- Metódy vieme prekryť pomocou neskorej väzby
- Môžeme využívať výhody polymorfickej referencie

Kompozícia:
- Môžeme použiť hocikoľko komponentov
- Metódy musíme explicitne delegovať (píšeme viac).
- Je na prvý pohľad zrejmé, čo robíme

- https://www.thoughtworks.com/insights/blog/composition-vs-inheritance-how-choose
- https://en.wikipedia.org/wiki/Composition_over_inheritance

---
# Kompozícia a dedičnosť

Pri návrhu treba pozorne zvážiť, ktorú formu znovupoužitia zvolíme.

*Vždy keď sa to dá tak by sme mali využiť kompozíciu*

---
# Polymorfizmus

Poznáme dva druby polymorfizmu:

- prekrytie (run-time)
- preťaženie (compile time)

---

# Preťažovanie metód

Overloading

Urobíme metódu, ktorá sa volá rovnako, má rovnaký počet argumentov, ale sú iného typu.

---

# Príklad na preťažovanie

Naučme základný automat na kávu príjmať aj platobné karty:

```java
class BasicCofeeMachine {
	public void pay(int eur){
    	System.out.println("Accepted %d eur".format(eur));
    }
}

class SuperCofeeMachine extends BasicCofeeMachine {
	public void pay(String card){
    	System.out.println("Accepted credit card");
    }
}
```

Inštancia SuperCofeeMachine bude mať k dispozícii dve metódy pay, medzi ktorými sa bude dať rozlíšiť podľa typu argumentu.

---
# Prekrývanie metód

Overriding

Urobíme metódu, ktorá vyzerá rovnako ako metóda predka.

Prekryjeme zdedenú funkčnosť.

---
# Príklad na prekrývanie

Pripravme verziu SuperKávového automatu pre americký trh, kde sa platí dolármi a American Expressom.


```java
class AmericanSuperCofeeMachine extends SuperCofeeMachine {
	public void pay(int usd){
    	System.out.println("Accepted %d USD".format(eur));
    }
    public void pay(String ae){
    	System.out.println("Accepted American Express card");
    }
}

```

---

# Ako sa potom určuje, ktorá metóda sa použije?

Kávové automaty sa nám v sklade mierne pomiešali:

```java
public static void kava_v_sklade(){
	String mojavisa = "1234 5678 5678 2546";
    String mojexpress = "6578 5678 3456 3245";
    int eura = 1;
    int dolare = 1;
    
    AmericanSuperCofeeMachine automat1 = new AmericanSuperCofeeMachine();
    automat1.pay(dolare);
    automat1.pay(mojavisa);
    
    BasicCofeeMachine automat2 = new AmericanSuperCofeeMachine();
    // Platim eurami alebo dolarmi?
    automat1.pay(eura);
    
    SuperCofeeMachine automat2 = new AmericanSuperCofeeMachine();
     // Platim visa alebo express?
    automat1.pay(mojavisa);

}

```

---


# Neskorá a skorá väzba

Pod rovnakým symbolickým menom sa skrýva rôzny obsah.
Podľa toho, kedy sa rozlíši (binding):

https://stackoverflow.com/questions/321864/java-dynamic-binding-and-method-overriding

- Preťažovanie metód : Skorá väzba
- Prekrývanie metód: Neskorá väzba


---

## Preťažovanie metód: Skorá väzba (Compile time, early binding)

Metódy vieme rozlíšiť už _počas prekladu_ podľa *typu referencie*.

Metódu alebo konštruktor s rovnakým menom rozlíšime podľa počtu a typu argumentov.

napr. polymorfický konštruktor a preťažovanie metód

## Prekrývanie metód: Neskorá väzba (Run time, late binding)

Metódu rozlišujeme _za behu_ podľa *typu objektu*.

Typ referencie je možné dynamicky meniť.

mapr. polymorfická referencia a prekrývanie metód

---

# Využitie prekrytej metódy pomocou referencie super a Override


```java
class Robot {
	protected void chod() {
    }
}

class KarelRobot extends Robot {
	@Override // Pre lepšiu prehľadnosť
    public void chod() {
        System.out.println("Krok Krok");
    }
}

// Toto je nová verzia robota Karel, ktorá pridáva efekt píp pri chôdzi:
class NewKarelRobot extends Robot {
	@Override // Kompilátor skontroluje, či nadradený typ naozaj má takú metódu
    public void chod() {
        // Tu volme metódu z rodiča
        super.chod();
        System.out.println("Pip");
    }
}

```
https://docs.oracle.com/javase/tutorial/java/IandI/override.html

---
# Príklad: Polymorfická referencia a neskorá väzba

Ak máme hierarchiu tried s prekrytými metódami, ktorá metóda sa zavolá?

```java

class Main {
	public static int main(String[] argv){
    	// Kúpime si nového robota typu Karel
        Robot mojkarel = new KarelRobot();
        // Vyšiel nový typ, kúpime si aj ten:
        Robot mojnovykarel = new NewKarelRobot();
        // Každý robot bude chodiť svojim spôsobom
        mojkarel.chod();
        mojnovykarel.chod();
        // Vďaka polymorfizmu môžeme oba roboty uložiť do rovnakej garáže:
        Robot garaz[] = new Robot[2];
        garaz[0] = mojkarel;
        garaz[1] = mojnovykarel;
	}
}

```

---

# Kľúčové slovíčko super

Slovíčko _super_ je referencia na rodičovskú triedu. Využívame ho podobne ako _this_.
Pomocou super vieme zavolať konštruktor, alebo metódu predka.
Pomocou super vieme znovupoužiť metódu z predka v prekrytej metóde.


```java
public class RobotKarel {
	public RobotKarel(String meno){
    	super(meno);
	}
}
```

Pomocou kľúčového slovíčka super musíme zavolať explicitný konštruktor nadradenej triedy. Dohoda je taká, že super musíme volať
vždy na prvom mieste. (Inak nastane chyba).

https://docs.oracle.com/javase/tutorial/java/IandI/super.html


---

## Zhrnutie

Všetky triedy sú potomkom triedy Object.

Polymorfizmus nám zjednodušuje znovupoužiteľnosť kódu.

Potomok má všetky typy jeho predkov.

Typ objektu vieme meniť za behu pomocou pretypovania.

Polymorfizmus môže byť dosiahnutý počas behu aj počas prekladu:

- Počas behu: dedením
- Počas prekladu: preťaženie metód

---

# Bibliografia

ECKEL, B.: Thinking in Java. 4th Edition, Prentice Hall, 2006

    Reusing Classes (pp. 165 – 192)
    Polymorphism (pp. 193 – 218)

- http://www.developer.com/design/article.php/10925_3525076_2/Encapsulation-vs-Inheritance.htm
- https://stackoverflow.com/questions/36552343/is-inheritance-necessary-for-encapsulation-abstraction-and-polymorphism
- https://en.wikipedia.org/wiki/Composition_over_inheritance

---
class: center,middle
# Koniec 

