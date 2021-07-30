class: center, middle 
# Úvod do objektového programovania

Prednáška na predmet Objektovo Orientované programovanie

Katedra elektroniky a multimediálnych telekomunikácií

Ing. Daniel Hládek PhD.

---
class: center, middle 
# Opakovanie

---
# Rozdiely Javy a C

Java patrí do rodiny jazykov ktoré sa inšpirovali jazykom C.

Na Javu je možné pozerať ako na určité rozšírenie jazyka C
- zjednodušenie správy pamäte: 
	- objekty sú odovzdávané referenciou
    - objekty na ktoré neexistuje referencia sú automaticky dealokované
- jednoduchšia tvorba knižníc a modulov
- virtuálny stroj umožňuje spúšťať rovnaký kód na ľubovoľnej platforme
	- neexistuje klasický proces linkovania, program sa "spája" pri spustení
    
---

# Objektové programovanie v C ?

http://www.javamex.com/tutorials/how_to/java_for_c_programmers.shtml#.WagWOtGxU2w

http://davin.50webs.com/research/1999/tsj4cp.html

---

# Štruktúrované programovanie v Jave

V Jave je možné programovať štruktúrovane.
Syntax štruktúrovaného programovania je veľmi podobná jazyku C.
Poznáme podobné konštrukcie:

- for
- break
- continue
- if
- while
- switch
- return

---

## Statická metóda

- je ekvivalent funkcie v jazyku C
- môže pracovať so svojimi argumentami a statickými premennými

https://www.programmingsimplified.com/java/source-code/java-static-method-program

## Statická premenná

- je ekvivalent globálnej premennej v jazyku C
- používame ju iba vtedy keď vieme prečo
- nemá ale nevýhody globálnej premmennej v jazylu C lebo býva v svojom mennom priestore (nehrozí konflikt mien).
---
# Obsah dnešnej prednášky

- Stučná charakteristika OOP
- Čo je objekt a čo je trieda
- 4 princípy OOP

Naučíme sa: 
- tvoriť triedy a objekty,
- využívať dedičnosť a polymorfizmus,
- definovať rozhranie objektu.

---
class: center, middle 
# Objektovo orientované programovanie

---

# Objektovo orientované programovanie

Klasický jazyk C má svoje výhody a obmedzenia, ktoré mu určujú typickú oblasť nasadenia:
- operačné systémy,
- nízko-úrovňové knižnice,
- databázy,
- vždy keď je rýchlosť a afektivita vykonávania oveľa dôležitejšia ako rýchlosť a cena vývoja.

## Platiť nového programátora je ale vždy drahšie ako platiť nový server!

---

# Ciele OOP

Cieľom je zlepšiť slabiny klasického štruktúrovaného programovania.
Štruktúrované programovanie je podmnožinou objektového programovania.

- Lepšia abstrakcia
- Znovupoužiteľnosť
- Modulárnosť
- Skrytie implementačných detailov
- Zvýraznenie dôležitých častí

## Konečným cieľom je zníženie nákladov na vývoj
- lacnejší a lepší software

---
# Filozofické otázky OOP

Kĺúčovým slovíčkom je *objekt* a *trieda*.

Čo je objekt?
Čo je trieda?

Aký je medzi nimi vzťah?

---

# Čo je objekt v reálnom svete

Entita, ktorá má identitu.
- skriňa v kúte
- smetný kôš

Objekt má svoj stav, úlohu a funkčnosť:
- do skriňe múžeme uložiť skriptá
- do koša vyhadzujeme papieriky
- keď je kôš plný, je potrebné ho vysypať.
- Ak je skriňa stará, je treba ju vymeniť alebo namaľovať.

---

# Čo je trieda v reálnom svete

Východ slnka nie je objekt. Východ z miesnosti je objekt, len v prípade, že myslím konkrétnu 
miestnosť a konkrétne dvere (alebo okno).

Trieda je abstrakcia - spoločné pomenovanie skupiny objektov.
Všetky objekty danej triedy majú rovnaké vlastnosti.

---

# Úloha na zamyslenie

Vyhľadajte ["flight carrier"](https://www.google.sk/search?q=flight+carrier). 

Aké existujú triedy lietadlových lodí?

Ako sa triedy lietadlových lodí navzájom líšia? 

Čo majú spoločné?

Aký je rozdiel medzi konkrétnou lietadlovou loďou a triedou lietadlových lodí?

---

# Čo je objekt v informačných technológiách?

Entita v pamäti, ktorá má svoju funkčnosť a identitu.
- dáta (atribúty): V zásade, je to to isté ako premenná
- funkcie (metódy): K skupine objektov rovnakého typu väčšinou patrí aj skupina funkcií (metód), ktoré s ním vedia pracovať.

Dáta a funkcie ktoré s nimi vedia pracovať vieme naprogramovať aj v jazyku C.

---

# Čo je trieda v informačných technológiách?

- Opis dátového typu
- Skupina funkcií, ktoré pracujú s týmto dátovým typom.

V pamäti si vieme vytvoriť viac objektov rovnakéhop typu (triedy) a so všetkými budeme pracovať rovnako.

---
# Princípy OOP

Princípy OOP sa týkaju tried - skupín objektov s rovnakými vlastnosťami.

- https://docs.oracle.com/javase/tutorial/java/concepts/object.html
- https://en.wikipedia.org/wiki/Object_(computer_science)


Pri práci s triedami (skupina objektov rovnakého typu) uplatňujeme princípy OOP:

- Abstrakcia
- Dedičnosť
- Zapuzdrenie
- Polymorfizmus

---

# Abstrakcia

Abstrakcia je proces pri ktorom sa sústredíme na dôležité veci a zanedbávame tie nepodstatné.

Je to proces zovšeobecnenia - skupiny objektov zdieľajú rovnaké vlastnosti.

Napr. vieme vymyslieť abstraktné "Auto" ktoré bude reprezentovať skupinu áut a vykonávať s ním určitú činnosť.

Môžeme povedať zamesnancovi - Na nákup budeš potrebovať auto a je jedno ktoré.

Napr. 

Firma na kávové automaty môže pri svojich procesoch uvažovať 
abstraktný "kávový automat" a mať definované operácie s "kávovým automatom", bez toho, aby musela riešiť ktorý konkrétne.

Jazyk C umožňoval iba obmedzenú abstrakciu pomocou štruktúr a funkcií.

---
# Čo je abstrakcia?

- Vytvorenie modelu skutočného sveta
- Model je  *vždy zjednodušenie*.
	- zákonite musíme niektoré veci vynechať ak ich chceme vytvoriť ich model.

Kto z vás vie naprogramovať auto?

---
class: center, middle 
# Je toto fajka?

![Fajka](https://upload.wikimedia.org/wikipedia/en/b/b9/MagrittePipe.jpg)



---
# Príklad abstrakcie v jazyku Java

Jazyk Java u možňuje presnejšiu abstrakciu pomocou tried, ktoré sa skladajú z členských premenných a metód.

```java
// Trieda auto je zjednodušením pojmu "auto"
Auto moje = new Auto();
// Trieda Auto je v našom prípade abstrakciou pre všetky autá
Auto tvoje = new Auto();

```
Napokon predsa vieme naprogramovať auto, len to nebude auto ale trieda s názvom Auto pomocou ktorej môžeme pracovať napr. s databázou áut.

```java
public class Auto {
	private int objemMotora = 80;
    public void plyn(){
    	System.out.println("Vrrr");
    }
    public void start(){
    	System.out.println("Vrrr");
    }
}

```

---

# Dedičnosť
(Inheritance)

Dedičnosť umožňuje znovupoužiteľnosť kódu pomocu zovšeobecnenia viacerých tried. 
Skupina tried s rovnakými vlastnosťami môže tvoriť "nadtriedu".

Triedy tvoria hierarchiu pomocou dedičnosti.

---

# Príklad dedičnosti

Trieda:
- Auto (má volant a dvere, má párny počet kolies)

Podtrieda : 
- Osobné auto (má štyri kolesá a kabínu)

Podtrieda:
- Nákladné auto (má korbu, môže mať aj viac kolies ako 4)

Podtrieda:
- Škoda Favorit (má retro farbu)

Inštancia:
- sivý Škoda Favorit KE 123AB
    
---

# Dedičnosť v Jave
## Kľúčové slovíčko extends

```java

// Favorit je potomkom auta
// Správa sa rovnako ako všeobencné auto, až na nejaké výnimky
public class Favorit extends Auto {
	// So štartérom sú niekedy problémy
    // Metóda štart prekrýva metódu obyčajného Auta
    public void start(){
    	System.out.println("Škrab, Škrab, Buch, Buch");
    }
    // Inak je to obyčajné auto - metóda plyn funguje normálne
}
public class Lada extends Auto {
	// Každé auto štartuje svojim spôsobom
    public void start(){
    	System.out.println("Klep klep škyt");
    }
}


```

---
# Dedičnosť pomocou kompozície

Dedičnosť pomocou kompozície dokáže dosiahnuť to isté.

https://en.wikipedia.org/wiki/Composition_over_inheritance

```java

// 
public class BMW  {
	// BMW má podvozok obyčajného auta, na podvozok sú primontované ďalšie funkcie, ktoré s ním vedia robiť.
	Auto podvozok = new Auto();
    public void start(){
    	System.out.println("Vrrrrr");
    }
    // Inak je to obyčajné auto - využíva metódy podvozku
    // Je ale potrebné ich explicitne prepojiť
    public void plyn(){
    	podvozok.plyn();
    }
}

```

---


# Zapuzdrenie

(Encapsulation)

Implementačné detaily triedy sú skryté a vlastná funkčnosť je zvýraznená.

Metódy a atribúty sú rozdelené na dve skupiny:

- Implementačné detaily
- Vlastná funkčnosť objektu

Zapuzdrenie nám definuje rozhranie objektu, pomocou ktorého môžeme vykonávať funkčnosť.

---
# Príklad zapuzdrenia

- Volant, benzínová nádrž a riadiaca páka patria k rozhraniu auta.
- Ovládanie sviečok je implementačný detail (je pod krytom motora).

Zapuzdrenie je možné implementovať aj na základe dohody, napr. 
- vnútorné metódy a atribúty budeme zapisovať s _ na začiatku
- metódy a atribúty, ktoré patria rozhraniu budú tie ostatné

ako to je v jazyku Python.

Alebo je zapuzdrenie implementované priamo v jazyku (Java, C++):
- kľúčové slovíčko public označuje rozhranie
- kľúčové slovíčko private označuje vnútorné časti.

---

# Príklad v zapuzdrenia v Jave

```java
public class Auto {
	// Z vonku nevidno, kolko je benzinu v nádrži
	private int benzin = 100;
    // Je detail koľk má auto valcov, ide aj tak
    private int valce = 4;
    
    // Diagnoza sa spúšťa v servise alebo automaticky pri naštartovaní
    private void diagnoza(){
    	System.out.println("Pii Pii");  	
	}
    
    // Štartér vieme ľahko používať
    public void start(){
    	System.out.println("Škrab, Škrab, Vrrrrr");
    }
    
    // Plyn je dôležitý pre pohyb
    public void plyn(){
    	benzin -= 1;
    	System.out.println("Eeeee!");
    }
    
    // Bez bŕzd by sme havarovali
    public void stop(){
    	System.out.println("Iii.");
    }
}
```
---
# Zapuzdrenie v Jave

Kľúčové slovíčka

- *private*: Použitie iba v rámci triedy
- *protected*: Puužitie aj pre potomkov
- *public*: Rozhranie objektu, použiteľné pre všetkých

---

# Zapuzdrenie funguje aj na úrovni modulov: Balíčky v Jave

Skupina tried, ktoré spolu súvisia zaradíme do jedného balíčka.

Jeden balíček tvorí jeden menný priestor (ako keby "priezvisko" balíčka).



https://docs.oracle.com/javase/tutorial/java/concepts/package.html

https://stackoverflow.com/questions/1088509/what-is-the-purpose-of-defining-a-package-in-a-java-file


---


## Polymorfizmus

Polymorfizmus umožňuje pod rovnakým menom skrývať rôznu činnosť.
To umožní skryť implementačné detaily a pracovať s objektom bez toho, aby sme mu podrobne rozumeli.

https://www.tutorialspoint.com/java/java_polymorphism.htm

Napr.

Na to aby sme vedeli využiť rozhranie "Volant", nie je potrebné vedieť či auto má benzínový alebo naftový motor.

Na to aby sme vedeli využiť rozhranie "Uvar kávu", nie je potrebné vedieť či to bude espresso alebo neska.

---

# Polymorfická referencia

Typ potomka je zároveň typ rodiča.

Favorit je zároveň auto.
BMW je tiež auto.

Autá poznáme BMW, Favorit, Škoda, Voklswagen, Audi ...

```java
Auto ke123ab = new Favorit();
Auto ke234cd = new BMW();
// Rovnaka referencia môže ukrývať inštancie rovnakého typu
public void chod_na_nakup(Auto auto){
	auto.otvor_dvere();
	auto.nastartuj();
	auto.soferuj_do_obchdu();
}
```

---


## Zhrnutie: 4 princípy OOP

- abstrakcia
- dedičnosť
- zapuzdrenia
- polymorfizmus

Objekt má stav, správanie a identitu.

Objekt má rozhranie a poskytuje služby

Objekt je možné znovupoužiť
- Kompozícia
- Dedičnosť

Trieda je skupina objektov s rovnamými vlastnosťami.

Objektovo orientované programovanie je hlavne o filozofickom prístupe - to isté sa vždy dá naprogrogramovať štruktúrovane.

---
class: center, middle 
# Čo bude nabudúce

Životný cyklus objektu

---
# Bibliografia

http://codebetter.com/raymondlewallen/2005/07/19/4-major-principles-of-object-oriented-programming/

https://anampiu.github.io/blog/OOP-principles/

---
class: center, middle 
# Koniec

Odpoviem na akúkoľvek otázku








