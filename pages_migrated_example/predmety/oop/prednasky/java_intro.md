---
title: Úvod do objektovo-orientovaného programovania v jazyku Java
--- 

# Úvod do objektovo-orientovaného programovania v jazyku Java. 

Ing. Stanislav Ondáš, PhD., Ing. Daniel Hládek PhD.

[Katedra elektroniky a multimediálnych telekomunikácií](http://kemt.fei.tuke.sk)

---

## Objektovo orientované programovanie


V predmete sa zoznámime so záklanými princípmi objektovo orientovaného programovania 
a jazykom Java. 


## Vyučujúci

- Ing. Stanislav Ondáš PhD. (prednášky, cvičenia)
- __Kontakt__: stanislav.ondas@tuke.sk, 
- B.Nemcovej 32, 5.posch., č.d. 509
    
---

## Hodnotenie

- Cvičenia: max. 40 bodov - prevažne zo zadaní 

- Skúška: max 60 bodov - praktickou formou.

- Na cvičeniach sa tolerujú maximálne 3 ospravedlnené neúčasti.

- Na získanie zápočtu budete potrebovať: min. 21 bodov.


---

## Obsah prednášky

1. Úvod
1. Krátke opakovanie jazyka C
1. Porovnanie jazyka C a Javy
1. Predstavenie Javy
1. Príklad vytvorenia objektu


---
# Stvorenie sveta (a priľahlých galaxií)

 - je možné stvoriť svet (vesmír) z ničoho?
   (len pomocou slov, jazyka?)
 - ako to súvisí s objektovo-orientovaným programovaním?
 - POĎME STVORIŤ (presnejšie STVÁRAŤ) SVET!
 - Problém! V čom napísať svet?
    - C, C++, Java, Python? 

---
# STVÁRANIE SVETA (Ako to urobil????)


```clike
struct PLANETA {
  int priemer;
  int vaha;
  int poloha[3];
  int rychlost_rotacie;
  float rychlost_pohybu;              
                
};

void TocSA(struct PLANETA* planeta){
	rychlost_pohybu = 29.8; // km/h                              
}

int main(){

  struct PLANETA zem;
  
  memset(&zem,0,sizeof(struct PLANETA));
  
  TocSa(&zem);

}
```
Problémy:
- vyhradenie pamäte, inicializácia, uvoľňovanie pamäte
- zložitosť kódu (čím komlexnejšie, tým väčší masaker) 
- znovupoužiteľnosť kódu? 

---
class: center, middle
# Programovací jazyk C

---

# Príklad: Robot v jazyku C

Pre porovnanie uvediem príklad:


```clike
struct Robot {
  int bateria;
  int rychlost;
  int poloha[2];              
};

void dopredu(struct Robot* robot){
	poloha[0] += 1;                               
}

int main(){
  // Vyhradímne pamäť a určíme ako bude vyzerať
  struct Robot karel;
  // Aký je počiatočný stav robota? Musíme ho inicializovať
  memset(&karel,0,sizeof(struct Robot));
  // Čo ak používame zložitejšie členy štruktúry?
  // Na inicializáciu potom potrebujeme špeciálnu metódu
  dopredu(&karel);
  // Čo sa stane s pamäťou?
}
```

---
# Robot v jazyku C

Jazyk C podporuje aj dynamickú alokáciu pamäte:

```clike
#include "robot.h"
#include <stdlib.h>
    
int main(){
    // Pracujeme so smerníkmi na pamäť
    struct Robot* karel;
    karel = malloc(sizeof(struct Robot));
  	// Na inicializáciu potom potrebujeme špeciálnu metódu
  	dopredu(karel);
    // Koľko chýb obsahuje môj program???
}
```


Typický program v jazyku C obsahuje definíciu pamäťových štruktúr (struct)
a množinu operácií s pamäťou určitého typu.

---

# Problémy ktoré často vznikajú v jazyku C

```clike
#include "robot.h"
#include <stdlib.h>
    
int main(){
    struct Robot* karel;
    karel = malloc(sizeof(struct Robot));
    // Pamäť musíme ručne inicializovať
    memset(karel,0,sizeof(struct Robot));
  	dopredu(karel);
    // Pamäť musíme ručne uvoľniť
    free(karel);
    // v premennej karel je stále adresa pamäte, ktorá ale nie je platná. 
    // To si musíme pamätať.
}
```

---

# Výhody jazyka C

- Syntax je veľmi jednoduchá, dobre sa píše a pamätá

- Program je veľmi rýchly - beh má minimálnu réžiu

- Programátor má detailnú kontrolu nad situáciou

- Program beží blízko k hardware a OS.

---

# Oblasti využitia jazyka C

Z toho dôvodu sa jazyk C využíva hlavne na písanie operačných systémov, programovacích jazykov a nízkoúrovňových knižníc.

- Keď je najdôležitejšia rýchlosť a efektivita.

- Keď je potrebné rovnaký systém udržiavať dlhé roky

Aj Java je napísana v C (len jej časti).

# Obmedzenia jazyka C

- Veľké možnosti prinášajú veľkú zodpovednosť - manažment pamäte je náchylný na chyby (pri neomylnosti si môžeme dovoliť nejakú zodpovednosť)

- Program je "ukecaný" - musíme explicitne napísať aj "samozrejmé" časti.

- Jazyk C nepredpisuje žiadne "overené" postupy.

- štandardná knižnica toho obsahuje málo, ostatné knižnice sú často ťažko prenositeľné

- pre ladenie musíme využívať nástroje ako je valgrind a gdb

---

class: center, middle
# Programovací jazyk Java

---
# Princípy jazyka Java

Java je všeobecný jazyk (General Purpose):  
- nie je obmedzený na špecifickú oblasť (môžeme v nej napísať aj vesmír a svet ;).
- nevnucuje špecifický štýl (ale uprednostňuje objektovo-orientovaný)

Java je objektovo orientovaný jazyk: 
- podporuje paradigmy Objektovo orientovaného programovania
	- dedičnosť, zapuzdrenie, polymorfizmus, znovupoužiteľnosť
- dá sa v nej programovať aj štruktúrovane.

Java je platformovo nezávisla a prenostiteľná (na iný OS, do iného vesmíru): 
- kód nie je závislý na platforme (super, ktovie, aké platformy budú za miliony rokov ;)
- abstrakcia platformovo závislých častí sa deje pomocou virtuálneho stroja (všetko virtuálne sa v nadprirodzenom svete zíde)
- prenositeľnosť je väčšinou triválna


Java má za úlohu vyriešiť niektoré nedostatky jazyka C a C++.

---
# Rozdiely Javy a jazyka C

Java je syntaxou veľmi podobná jazyku C

Rozdiely:
- kľúčové slovíčka
- proces kompilácie a spustenia
- model práce s pamäťou
- podpora objektovo orientovaného programovania

---

# Je Java pomalšia ako C-C++ ?

- Väčšionou na tom nezáleží (kto je strojcom času, vie si to prispôsobiť :) )
- Prebieha preklad za behu 
- Zlá povesť 

http://benchmarksgame.alioth.debian.org/

---

# Krátka história Javy

Prvá verzia bola uvoľnená v roku 1995  v Sun Microsystem, aktuálna stabilná verzia Java 10 (Oracle).
V roku 2006 Sun Javu uvoľnil ako open source.

Programovací jazyk sa pôvodne volal Oak , podľa dubu ktorý stál vedľa kancelárie Jamesa Gosslinga. 
Projekt neskôr premenovali na Green (Oak) a neskôr Java.

Java znamená káva pôvodom z Jávy.


- https://www.tecmint.com/what-is-java-a-brief-history-about-java/
- https://en.wikipedia.org/wiki/Java_(programming_language)
- http://www.oracle.com/technetwork/java/javase/overview/javahistory-index-198355.html

---

# Popularita jazyka Java

Java je momentálne jeden z  najpopulárnejších jazykov.

Aby nebolo zložité sa naučiť Javu, Gossling využil syntax jazyka C. Jazyk navrhol tak, aby bol jednoduchší na používanie
a podporoval objektovo orientovaný prístup. Java rieši niektoré nedostatky klasických prekladaných jazykov.


https://www.javatpoint.com/features-of-java


Podľa počtu profesionálov, kurzov a ponúk: https://www.tiobe.com/tiobe-index/ 

Podľa počtu vyhľadávaní tutoriálov: http://pypl.github.io/PYPL.html 

## Heslo Javy


*Write Once, Run Everywhere*


---

class: center, middle
# Java - štartujeme

---

# Čo budeme potrebovať

## Kompilátor a vývojárska sada

JDK - Java Developent Kit 
- kompilátor javac 
- dokumentácia javadoc
- debugger jdb

Zdrojový kód je najprv preložený do bajtkódu

## Virtuálny stroj

JRE (Java Runtime Environment) - virtuálny stroj pre konečných používateľov. Bajtkód je vykonávaný na virtuálnom stroji.
- štandardné knižnice
- virtuálny stroj JVM Java Virtual Machine
- JustInTime kompilátor

---

## Integrované vývojové prestredie (IDE - Integrated Development Environment)

- Na cvičeniach budeme používat IntelliJ Idea
- Ale kódy je možné písať v vo ViM

https://www.javatpoint.com/simple-program-of-java

Čo je potrebné:

1. Nainštalovať JDK
1. Nastaviť premenné prostredia PATH a CLASSPATH	
1. Napísať program
1. Preložiť a spustiť

---

# Ahoj svet Java

```java
class Main {
	// Metoda je nieco podobne ako funkcia
    public static void main(String args[]){  
    	System.out.println("Hello Java");  
    }  
}  
```
- *class* označuje začiatok triedy. Kód v Jave je organizovaný v triedach. Trieda sa skladá z členských premenných a metód. Táto trieda má iba jednu metódu.
- *static* : Zatiaľ jediná metóda triedy Main je deklarovaná ako statická. Statická metóda znamená, že sa správa ako funkcia v jazyku C (nemá prístup k členským premenným, pre vyvolanie nepotrebujeme vytvoriť objekt)
- *public*: Metódy v jazyku Java majú definovanú viditeľnosť. Public znamená, že viditeľnosť nie je obmedzená.
- *void*: návratový typ metódy- *main*: dohodnutý názov hlavnej metódy
- *String\[\] args* sú argumenty metódy main, typu pole reťazcov.
- *System.out.println()*: Príkaz pre výpis reťazca na obrazovku. Využívame volania iných statických metód.

---

# Proces prekladu a spustenia

https://www.javatpoint.com/internal-details-of-hello-java-program

Preklad:

1. Zdrojový kód sa prekladá pomocu *prekladača*. 
	Prekladom zdrojového textu vznikne *class súbor*. 
    Každá jedna trieda má svoj class súbor. Class súbor obsahuje tzv. *bytecode (bajtkód)*. Java neobsahuje linker ani preprocesor.
2. Program je spustený pomocou *virtuálneho stroja*, ktorý rozumie bytecodu. Pri spustení sa vyhľadajú všetky potrebné class súbory.
	CLASSPATH je dôležitá premenná prostredia - obsahuje zoznam miest, kede všade sa hľadá bytecode.
3. Keď je bytecode nájdený, môže byť overený a spustený. Preklad do strojového kódu niekedy prebieha za behu (Java HotSpot).

---

# Stvorenie triedy PLANÉTA v Jave


```java
class Planeta {
  private int priemer = 100000; // das teľo
  private int vaha = 56404343;  //kus tlusta
  private double poloha[] = {5346435,757438439, 43422242}; 
  private float rychlost_rotacie= 0; // zatym še nekruci
  private float rychlost_pohybu =0; // zatym še nehybe     
  
  // Metóda má prístup k členským premenným a vie ich meniť
  
  public void TocSa(){
		rychlost_rotacie = 29,4; // a uš še kruci                                 
  }
};

```

Jazyk Java nás núti, aby sme vždy definovali počiatočnú hodnotu. Program sa nepreloží, ak by sme to neurobili.
To eliminuje veľkú skupinu problémov s inicializáciou.


 
---
# Jak vznikla naša žem...



```java
class Main{  
    public static void main(String args[]){
    	
        // Lokálna premenná maticka_zem obsahuje referenciu na novo vytvorený objekt
        // maticka_zem je inštancia triedy PLANETA = z teho vyplyva, že žem je planeta.
     	
        Planeta maticka_zem = new Planeta();
        // Zavoláme metódu objektu
        maticka_zem.TocSa();
    }  
}  
```

ci pana.. a Galileo može spokojne povedzedz: "A predsa še točí". 

Uvoľnenie pamäte prebehne automaticky. Java nepozná smerníky, ale referencie na pamäť.

Vtip: 
Bratislavčan sa pýta: "Prečo vy vychodniari všade dávate to "dz"?
Vychodňar: "dze všadzi?"

---
## Smerník
- číselná hodnota adresy pamäťovej bunky
- je možné vykonávať operácie smerníkovej aritmetiky
	- pripočítavať a odpočítavať

## Referencia
- Ukazuje vždy na vyhradenú pamäť (nemôže ukazovať na nevyhradenú pamäť)
- Vždy má nejaký typ
- Nie sú možné operácie smerníkovej aritmetiky
- Pamäť, na ktorú neukazujú žiadne referencie je automaticky uvoľnená s pomocu Garbage Collectora
- Memory leak je možný, ak na nepotrebnú pamäť existuje referencia

---
# Konštruktor

Na inicializáciu objektu si môžeme definovať špeciálnu funkciu (je to priam užitočné).
V nej priradíme počiatočné hodnoty všetkým členským premenným.

```java
class Planeta {
  private int priemer = 0; // nula
  private int vaha = 0;  // nula
  private double poloha[] = {0,0,0}; 
  private float rychlost_rotacie= 0; // zatym še nekruci
  private float rychlost_pohybu =0; // zatym še nehybe     
  
  // pozor!!!! Ide KONSTRUKTOR
  public Planeta(){
  	priemer = 3500000;
    vaha = 55555555222;
    poloha = {36353443,3423424,768788878};
  }
    
};
```
---
class: center, middle
# Skoro koniec

---
# Čo sme sa naučili

- Ako stvoriť svet (wau) ...

- Porovnali sme Javu s jazykom C

- Predstavili sme si základné princípy Javy

- Naučili sme sa z čoho sa skladá trieda:
	- členské premenné
    - členské metódy

- Zistili sme, ako sa vytvára objekt
	- pomocou operátora new

- Java vám pomáha odhaliť chyby pri práci s pamäťou

---
# Čo bude nabudúce

- BUDEME STVÁRAŤ ĎALEEEEEEJ (možno aj človeka)  ;)

- Štruktúrované programovanie v Jave

- Základy objektovo orientovaného programovania

- Zobrazenie vzťahov medzi triedami


---


# Študijné materiály

- http://it4kt.cnl.sk/c/oop/
- [Introduction to Programming Using Java, Seventh Edition](http://math.hws.edu/javanotes/)
- ECKEL, B.: Thinking in Java. 4th Edition, Prentice Hall, 2006
- GAMMA, E. – HELEM, R. – JOHNSON, R. – VLISSIDES, J. M.: Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley Professional, 1994

https://www.javatpoint.com/
https://go.java/student-resources/index.html


# Domáca úloha

Nainštalujte si Javu 10, IDE IntelliJ Idea a naprogramujte si Ahoj Svet

---
class: center, middle
# Koniec

http://nlp.web.tuke.sk/oop



ELEM, R. – JOHNSON, R. – VLISSIDES, J. M.: Design Patterns: Elements of Reusable Object-Oriented Software. Addison-Wesley Professional, 1994

https://www.javatpoint.com/
https://go.java/student-resources/index.html


# Domáca úloha

Nainštalujte si Javu 10, IDE IntelliJ Idea a naprogramujte si Ahoj Svet

---
class: center, middle
# Koniec

http://nlp.web.tuke.sk/oop







