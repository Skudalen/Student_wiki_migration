class: center, middle
# Návrhové vzory - vytváranie objektov

Objektovo orientované programovanie

Ing. Daniel Hládek PhD. 

---
# Obsah prednášky

1. Návrhové vzory
1. Vytváracie návrhové vzory
1. Návrhové anti-vzory

---
# Programovanie je kreatívna činnosť, ale ...

Pri návrhu a vytváraní programu sa často rieša problémy, ktoré už niekto vyriešil.

Koleso a teplá voda už vymyslené boli.

Je dobré sa poučiť na úspechoch a chybách iných ľudí.

---
# Čo je to návrhový vzor

> In software engineering, a design pattern is a general repeatable solution 
    to a commonly occurring problem in software design. A design pattern isn't a finished design 
    that can be transformed directly into code. It is a description or template for how to solve
    a problem that can be used in many different situations. 
    
Zaužívané riešenie konkrétneho problému
- opis probému, ktorý sa rieši
- návrh riešenia

Zoznam návrhových vzorov:
- Zoznam častých probémov a ich riešenie

Návrhový anti-vzor:

Opis problému a časté nesprávne riešenie

---
# Bibliografia

Pôvodne pre C++ a SmallTalk od The "Gang of Four": 
[Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides : Design Patterns: Elements of Reusable Object-Oriented Software](https://en.wikipedia.org/wiki/Design_Patterns)


Pôvodne pre C a GW Basic:
[Steve McConnell :Code Complete](https://en.wikipedia.org/wiki/Code_Complete)

https://sourcemaking.com/design_patterns

http://www.oodesign.com/


---
# Druhy návrhových vzorov

- Vytváracie (Creational)
	- vytváranie tried pomocou dedičnosti a vytváranie objektov pomocou delegácie.
- Štrukturálne (Structural)
	- metódy znovupoužitia tried pomocou dedičnosti a kompozícia objektov.
- Vzory správania (Behavioral)
	- komunikácia objektov navzájom 

---
# Vytváracie vzory / Creational


Vytváranie pomocou statickej metódy:
- Singleton: Obmedzenie na jedinú inštanciu
- Factory Method: "Abstraktný" konštruktor
- Abstract Factory: Objekty, ktoré sú závislé na platforme

Vytváranie pomocou objektu:
- Builder: Skladanie viacerých objektov dohromady
- Prototype

---
# Singleton

Problém:

Potrebujeme práve jednu inštanciu objektu pre celý proces.

Napr.

- spojenie s databázou
- externá knižnica v jazyku C

**Globlne premenné používame iba vtedy ak vieme prečo**

- Skoro nikdy
- Naozaj sa to nedá robiť inak?
---
# Postup pri návrhu Singleton

https://sourcemaking.com/design_patterns/singleton

1. Define a private static attribute in the "single instance" class.
1. Define a public static accessor function in the class.
1. Do "lazy initialization" (creation on first use) in the accessor function.
1. Define all constructors to be protected or private.
1. Clients may only use the accessor function to manipulate the Singleton.

---

# Príklad na Singleton

```java
public class DatabaseConnection{
	private static Connection connection = null;
    public static Connection getInstance(){
    	if (connection == null){
        	connection = new Connection();
        }
        return connection;
	}
}

```

---
# Príklad na Singleton v Java SDK

https://docs.oracle.com/javase/8/docs/api/java/lang/Runtime.html#getRuntime--

---
# Factory method

Pomocou "Factory Method" implemetujeme polymorfický konštruktor.

https://en.wikipedia.org/wiki/Factory_method_pattern


    How can an object be created so that subclasses can redefine which class to instantiate?
    How can a class defer instantiation to subclasses?


Statická metóda, ktorá vráti inštanciu nejakého typu podľa požiadaviek.

Môôže vrátiť aj inštanciu niektorej z podried.

	An increasingly popular definition of factory method is:
    a static method of a class that returns an object of that class' type. 
    But unlike a constructor, the actual object it returns might be 
    instance of a subclass. Unlike a constructor, an existing object 
    might be reused, instead of a new object created. Unlike a constructor, 
    factory methods can have different and more descriptive names 
    
- Color.make_RGB_color(float red, float green, float blue) 
- Color.make_HSB_color(float hue, float saturation, float brightness)

---
# Príklad na Factory v JDK


https://docs.oracle.com/javase/8/docs/api/java/nio/charset/Charset.html#forName-java.lang.String-

---
# Príklad na Factory

![Factory example](https://upload.wikimedia.org/wikipedia/commons/4/43/W3sDesign_Factory_Method_Design_Pattern_UML.jpg)

---
# Abstract Factory

Zovšeobecnená Factory - Factory,ktorá vracia inú factory.

Prolém:

Potrebujeme zakryť závislosť na platforme. 
Na rôznych platformách potrebujeme pracovať s rôznymi objektami.

	
    How can an application be independent of how its objects are created?
    How can a class be independent of how the objects it requires are created?
    How can families of related or dependent objects be created?



---
# Príklad na Abstract Factory v JDK

https://docs.oracle.com/javase/8/docs/api/javax/xml/parsers/DocumentBuilderFactory.html#newInstance--

---
# Builder

Problém:

Spájanie viacerých inštancií do jednej.

Objekt, ktorý spája viaceré objekty do jedného.

---
# Príklad na Builder

Spájanie kusov reťazca do jedného.

https://stackoverflow.com/questions/8725739/correct-way-to-use-stringbuilder


https://www.dotnetperls.com/stringbuilder-java

```java
import java.lang.StringBuilder;

public class Program {
    public static void main(String[] args) {

        // Create a new StringBuilder.
        StringBuilder builder = new StringBuilder();

        // Loop and append values.
        for (int i = 0; i < 5; i++) {
            builder.append("abc ");
        }
        // Convert to string.
        String result = builder.toString();

        // Print result.
        System.out.println(result);
    }
}
```

---
# Prototype

https://dzone.com/articles/design-patterns-prototype

Využitie metódy clone()

1. Ak je to možné, navrhnite objekty tak aby sa nemenili (inmutable). Ak sa objekt nemení, nie je potrebné ho kopírovať.
1. Ak je to možné, využite radšej kopy konštruktor



---
# Návrhové anti vzory

https://en.wikipedia.org/wiki/Anti-pattern


    A commonly used process, structure, or pattern of action that despite initially appearing to be an appropriate and effective response to a problem, has more bad consequences than good ones.
    Another solution exists that is documented, repeatable, and proven to be effective.

---
# Vybrané anti vzory

Používanie návrhových vzorov bez toho aby som vedel prečo
- https://en.wikipedia.org/wiki/Cargo_cult_programming

Používanie referencie super:
- https://en.wikipedia.org/wiki/Call_super

Kruhové závislosti
- Ak komponent A závisí na B, B na C a C na A

Coding by Exception
- https://en.wikipedia.org/wiki/Coding_by_exception
- Ak sa výnimky zneužívajú na normálny beh programu.

---

# Bibliografia

https://stackoverflow.com/questions/1673841/examples-of-gof-design-patterns-in-javas-core-libraries

https://sourcemaking.com/design_patterns

https://dzone.com/refcardz/design-patterns

---
# Koniec