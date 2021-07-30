# /inner/Prednasky/Odpad/


---

Tejto situácii chceme zabrániť.

V našej továrni na robotov vznikol problém - do skladu plného robotov sa nám niekedy zamiešal kávovar.
Sklady v továrni totiž nemajú menovky typov na dverách a niekedy sa stane, že roboty uskladnia v sklade, kde pred tým boli roboty:

```java

List sklad_kavovarov = new ArrayList();
for (int i = 0; i < 10; i++){
  l.add(new DrinkJava2000());
}

```

  
https://stackoverflow.com/questions/2159338/what-is-the-java-equivalent-of-cs-templates

http://docs.oracle.com/javase/1.5.0/docs/guide/language/generics.html




---

## Problém:

Pri výrobe sú súčiastky háhodne porozhadzované po výrobnej hale. Bolo by dobré ich mať pekne spolu tak aby bolo ľahké s nimi manipulovať.
Problém je ale, že každý proces si vyžaduje osobitný prístup.

Napr. 
- maľovanie si vyžaduje naukladať súčiastky do radu
- pri skladaní je potrebné súčiastky ukladať jednu na druhú (posledne položená súčiastka je vždy navrchu).
- Pri odosielaní sa žiadna súčiastka nemôže opakovať.
- Pri expedícii je každej vyrobenej súčiastke potrebné prideliť adresu doručenia.


---

---

# Zobrazenie triedy v UML

- Názov
- Rozhranie
- Chránené metódy (určené pre potomkov)
- Skryté metódy

statické členy

- Konštanta a premenná
    - final, static, const
- Viditeľnosť v Jave - public, protected, private
- Tvorba a volanie metódy

- Funkcia a metóda
- statická metóda
- Stav objektu a zmena stavu objektu



---

# Príklad na rozhranie a dedičnosť

Ako reprezentovať pohon auta?


Auto môže čerpať benzín, naftu, plyn alebo byť aj na elektrický pohon.

Niektoré pohony je možné aj kombinovať - hybridné auto čerpá aj benzín a aj elekrický prúd.

Plynové auto čerpá aj benzín aj plyn.

---
# Abstraktné triedy - iný príklad

Navrhnime reprezentáciu možných palív do auta:

```java
abstract class Palivo {
	private int amount;
    public int getAmmount(){
    	return ammount;
    }
    public abstract String getName();
}

class Benzin extends Palivo {
	private final int oktany;
    Benzin(int oktany){
    	this.oktany = oktany;
    }
    public String getName(){
    	return "Natural " + oktany; 
    }
}

class Nafta extends Palivo {
    public String getName(){
    	return "Nafta"; 
    }
}

```

## Rozhrania

Vďaka novému typu robota sa naša továreň na roboty dostala do zisku a nastal čas na akvizície.
Manažment továrne sa rozhodol pre nákup startupu "DrinkJava" na výrobu kávových automatov.

Riaditeľ dostal geniálny nápad naučiť robotov variť kávu s využitím kávových automatov z nového sortimentu.
Robot by mal vedieť zastúpiť kávový automat.

Inžinierska sekcia má ako vždy zabezpečiť implementáciu geniálnych nápadov:

Kávový automat typu DrinkJava2000 vyzerá takto:

```java
class DrinkJava {
	public int centy = 0;
    public int kava = 10;
    // Funkcia vráti zvyšné centy a urobí kávu
	public int daj_kavu(int centy){
    	this.centy += centy;
        if (centy < 50){
        	System.out.println("Figu");
            // Automat zožerie mince, zatiaľ sa to nepodarilo opraviť
            return 0;
		}
    	kava -= 1;
        this.centy -= 50;
        System.out.println("Vaša Java");
        // Automat vráti zvyšné  mince
        return centy - 50;
    }
}

```


---



## Viacnásobná dedičnosť

Riešením by bola viacnásobná dedičnosť - RobotKarel by bol naraz Robot aj kávový automat DrinkJava2000.
Java to ale neumožňuje a bolo by to aj nepraktické - Automat sa na robota nezmestí.

Naučíme preto robota chodiť po kávu do automatu. Pri štarte robotovi povieme, kde je automat:

```java
class Robot {
	DrinkJava2000 automat;
	Robot(DrinkJava2000 automat){
    	this.automat = automat;
    }
    // Funkcia vráti zvyšné centy a urobí kávu
	public int daj_kavu(int centy){
    	chod();
        // Robot doniesie kávu z automatu
        return automat.daj_kavu(centy);
    }
}
```

Použili sme techniku kompozície pre rozšírenie funkčnosti robota o funkciu varenia kávy. 

Nastal ale problém - šéf dostal ďalší geniálny nápad. Robot vie variť kávu a správa sa teda ako kávový automat.
Prečo by teda nebolo možné, aby si jeden robot bral kávu od druhého?

Kávu je teda možné získať dvoma spôsobmi (dve rôzne implementácie daj_kavu):
- Uvarením priamo v automate (v triede DrinkJava2000)
- Poprosením robota, ktorý ju donesie (v triede Robot).

Automat na kávu nie je možné namontovať priamo na robota (nie je možné rozšíriť triedu DrinkJava2000  triedou Robot).

Riešením je spoločné rozhranie "Coffeinable":

```java
public interface Coffeinable {
	public static final cena_kavy = 50;
	public int daj_kavu(int centy);
}
```

Toto rozhranie definuje všeobecný spôsob získania kávy. Je pritom jedno, či si kávu kúpime priamo, alebo nám ju odniekiaľ prinesie robot.

Všetky naše zariadenia, ktoré vedia robiť kávu implementujú toto rozhranie svojím spôsobom:


```java
public class DrinkJava implements Coffeinable {
	public int centy = 0;
    public int kava = 10;
    // Funkcia vráti zvyšné centy a urobí kávu
	public int daj_kavu(int centy){
    	this.centy += centy;
        if (centy < Coffeinable.cena_kavy){
        	System.out.println("Figu");
            // Automat zožerie mince, zatiaľ sa to nepodarilo opraviť
            return 0;
		}
    	kava -= 1;
        this.centy -= Coffeinable.cena_kavy;
        System.out.println("Vaša Java");
        // Automat vráti zvyšné  mince
        return centy - Coffeinable.cena_kavy;
    }
}

```

Takto je možné, aby robot typu Karel vedel variť kávu, ale robot typu Jozef nie:


```java
class KarelRobot extends Robot implements Coffeinable {
	DrinkJava2000 automat;
    
	KarelRobot(DrinkJava2000 automat){
    	this.automat = automat;
    }
    // Funkcia vráti zvyšné centy a urobí kávu
    @implements
	public int daj_kavu(int centy){
    	chod();
        // Robot doniesie kávu z automatu
        return automat.daj_kavu(centy);
    }
}
```
Na rozhrania sa nevzťahujú obmedzenia, ktoré platia pre dedičnosť. Trieda môže dediť od maximálne jedného predka, ale môže implementovať 
hocikoľko rozhraní.

## Composition over inheritance

Rozhrania a kompozcia umožňujú úplne vynechať dedičnosť:


```java
interface Robotable {
	public void chod();
}

interface Coffeinable{
  public int daj_kavu(int centy);
}

class DrinkJava2000 implements Coffeinable {
  public int daj_kavu(int centy){
      System.out.println("Vasa kava");
  }
}

class NewKarelRobot implements Coffeinable,Robotable {
	Coffeinable coffe_source;
    Podvozok nohy;
    NewKarelRobot(Coffeinable coffee_source){
    	this.coffee_source = coffee_source;
    }
    public int daj_kavu(int centy){
       chod();
       return coffee_source.daj_kavu(centy);
  	}
    public int chod(){
    	nohy.kracaj();
    	System.out.println("Krok krok");
    }
}

```
# Abstrakný trupík

Komponenty v našej továrni na roboty si vieme usporiadať do hierarchie:

TorzoRobota
	RobotKarel
    RootJozef

Všetky naše roboty vedia využívať funkčnosť TorzoRobota. TorzoRobota má pripojenú navigáciu a robotické rameno.

Nastal však problém, lebo naši zamestnanci sú zlomyseľní a bavia sa s TorzomRobota bez toho, aby mu pripojili nohy alebo kolesá.

```java
TorzoRobota trupik = new TorzoRobota();
trupik.chod(); // Chudak nema nozicky
```
To im chceme zakázať.

Využijeme kľúčové slovíčko abstract a TorzoRobota premenujeme na Robot:

```java
public class Robot {
	private Rameno lavaruka;
	public void naviguj(){
    	chod();
    }
	protected abstract void chod();
    
    public void zober(){
    	lavaruka.zober();
    }
}
```
Zrušili sme časť, kde sa torzo robota namiesto pohybu sťažovalo na chýbajúci podvozok.

Metóda chod() sa stala abstraktná - zostalo meno a konkrétnu implementáciu sme nechali na potomkov.

Čo sa stane, keď sa pokúsime vytvoriť inštanciu typu Robot?

- Nastane chyba, lebo z Robot sa stala abstraktná trieda.
- Inak povedané: neexistuje všeobecný robot, existuje len konkrétny. Ale existuje skupina všeobecných robotov (trieda Robot) s ktorou 
	vieme urobiť nejaké operácie.

Nie je možné vytvoriť inštanciu abstraktnej triedy, ale vďaka polymorfizmu ju vieme využívať ako typ.
Do referencie, ktorej typ je abstraktný stále vieme uložiť typ jej potomka:

```java
// Tu nastane chyba
Robot karel = new Robot();
// Toto je v poriadku
Robot karel1 = new Karel();

karel1.chod();

```

# Životný cyklus a dedenie

Situácia sa komplikuje, ak používame vlastné konštruktory. Pri dedení je potrebné zabezpečiť, 
aby sa konštruktory všetkých predkov volali v správnom poradí.

Ak si napr.chceme aby robot vedel svoje meno, môžeme si ho zapamätať v hlave:


```java
public class TorzoRobota {
	Rameno laverameno = new Rameno();
    String meno;
	public TorzoRobota(String meno){
    	this.meno = meno;
	}
	public void zober(){
    	System.out.pintln("Mam zeton!");
	}
}

```

---

# Príklad na polymorfizmus 

Naša firma na programovanie robotov by chcela, aby sa všetky naše roboty vedeli pohybovať po miestnosti.
Všetky naše roboty preto vybavila tým istým navigačným systémom GPS. Navigačný systém robota vie o aktuálnej polohe 
a vie povedať kam a kadiaľ by mal robot ísť.
Je v zásade jedno, či je robot na nohách alebo na kolesách.

Naše robory by sme mohli montovať týmto spôsobom:

1. Najprv si pripraviť hlavu robota, ktorý budeme montovať do všetkých našich typov. Mozog bude obsahovať navigáciu, ktorá
	bude hovoriť kam má robot íst a čo má robot robiť. Navigácia bude posielať príkazy do pohonnej jednotky.
1. K hlave primontujeme telo a ruku.
1. Hlavu rozšírime o rôzne druhy pohonných jednotiek Pohonná jednotka vykoná príkazy z navigácie.

---


```java
public class TorzoRobota {
	private Rameno lavaruka;
	public void naviguj(){
    	chod();
    }
	public void chod(){
    	System.out.println("Neviem ako...");
	}
    
    public void zober(){
    	lavaruka.zober();
    }
}

public class RobotKarel extends TorzoRobota {
	public void chod(){
    	System.out.println("Krok krok"/);
    }
}

public class RobotJozef extends TorzoRobota {
	public void chod(){
    	System.out.println("Bzzz"/);
    }
}

```

---

Týmto postupom sme dosiahli, že:

Využívame komponent Rameno vyrobený externou firmou.
Naša firma vyrába spolu tri časti:

- Torzo robota, ktoré obsahuje hlavu, telo a ruku.
- Robot Karel, ktorý je tvorený torzom a nohami.
- Robot Jozef, ktorý je tvorený torzom a kolesami.

Celé rozhranie robota je prístupné už na torze robota.
Preto je možné programovať rôzne roboty bez toho, aby smne vedeli akým spôsobom sa pohybujú.

Môžeme napísať:

```java
public class ProgramUpratovac {
	public void upratuj(TorzoRobota robot){
    	for (int i = 0; i < 10; i++){
    		robot.chod();
        	robot.zober();
        }
    }
}

```

---

Tento program bude fungovat pre lubovolného robota, lebo každý robot je ovládeteľný z jeho torza.
TorzoRobota je rozhranie, vďaka ktorému môžeme pristupovať k ľubovoľnému robotovi rovnako.

Nasledujúci zápis je platný:


```java
public class Main {
	public static int main(String[] argv){
    	RobotJozef jozef1 = new RobotJozef();
        ProgramUpratovac.upratuj(jozef1);
        
        
        RobotKarel karel1 = new RobotKarel();
        // Inštancia typu RobotKarel je zároveň inštanciou TorzoRobota.
        ProgramUpratovac.upratuj(karel1);
        // M
        
        TorzoRobota karel2 = new RobotKarel();
        ProgramUpratovac.upratuj(karel2);
        
        // Alebo aj
        TorzoRobota karel2_copy = (RobotKarel)karel2;
        // a dostaneme druhú referenciu na ten ist objekt robota karla číslo 2   
        
    }
}

```

---

Naše ḱódy môžeme vylepšiť tak, že implicitne označíme, ktoré časti sú určené na dedenie.

Rozhranie triedy rozdelíme na 3 časti:

- Vnútorná časť: private
- Časť určená iba na dedenie: protected
- Rozhranie triedy: public

Torzo robota potom môže vyzerať:

```java
public class TorzoRobota {
	private Rameno lavaruka;
	public void naviguj(){
    	chod();
    }
	protected void chod(){
    	System.out.println("Neviem ako...");
	}
    
    public void zober(){
    	lavaruka.zober();
    }
}
```

---

V podtriedach tiež môžeme vyznačiť, ktoré časti sú zdedené (prekryté metódy) pomocou anotácie override:

```java
public class RobotKarel extends TorzoRobota {
	@override
	public void chod(){
    	System.out.println("Krok krok"/);
    }
}
```

Všimnime si, že sme zmenili viditeľnosť metódy z "protected" na "public".

---

