class: center, middle
# Kolekcie

Objektovo orientované programovanie

Prednáška č. 8

Ing. Daniel Hládek PhD.

---
# Obsah prednášky

- Implementácia niektorých vlastných pamäťových štruktúr
	- Dynamické pole
    - Spojkový zoznam
- Použitie štandardných implementácií pamäťových štruktúr
	- Java Collection Framework
- Algoritmy pre prácu s kolekciami
	- prechádzanie
    - triedenie
- Generické programovanie
	- Typové žolíky a obmedzenia typových žolíkov

---

# Dynamické pole

Polia majú fixnú veľkosť. Skúsme navrhnúť pole, ktoré sa bude automaticky zväčšovať:

```java
public class DynamicArray {
	private Object[] array = new Object[20];
    private int size = 20;
    public int size() {
    	return size;
    }
    public void set(int i, Object val){
    	if (i >= size){
        	size = i + 1;
            Object[] newarray = new Object[size];
            System.arraycopy( newarray, 0, array, 0, array.length );
            array = newarray;
        }
        array[i] = val;
    }
    public Object get(int i){
    	return array[i];
    }
} 
```

---
# Problémy vlastnej implementácie

- Vieme uložiť iba zložené dátové typy
- Implementácia je neefektívna
	- Pri pridávaní objektu na koniec veľa kopírujeme a alokujeme novú pamät
- Je nutné robiť explicitnú typovú konverziu
	- Nekontroluje sa správnosť uložených typov
- Rozhranie nášho poľa nie je kompatibilné s klasickým poľom
- Nevieme mazať prvky
- Nie je jasné či je na mieste uložené null alebo nič

Ako by sme to pole skompatibilitilnili?

---

# Spojkový zoznam

Pamäťová štruktúra, ktorá umožňuje jednoduché vloženie do prostriedku.

Jendnosmerný spojkový zoznam:
- Hodnota alebo referencia
- Referencia na ďalší element

---

```java
class LinkedList {
    public class LinkedListItem {
        public LinkedListItem next;
        public Object value;
    }
    private LinkedListItem first;
    void add(Object value){
    	LinkedListItem nitem = new LinkedListItem();
    	nitem.value = value;
    	if (first == null){
    	    first = nitem;    
    	}
    	else {
        	LinkedListItem item = first;
    	    while(item.next != null)
        	    item = item.next;
	        item.next = nitem;
	   }
    }
    Object first(){
    	return first.value;
    }
}
```

---

# Použitie spojkového zoznamu:

```java
public class Main{
    public static void main(String args[]){
        LinkedList ll = new LinkedList);
        // Akého typu bude prvý člen?
        ll.add(1);
        Object f = ll.first();
        System.out.println(f);
        // Dá sa urobiť?
        Integer firstNumber = (Integer)f;
    }
}
```

---

# Problémy a vlastnosti spojkového zoznamu:

- Prístup do prostriedku zoznamu má lineárnu zložitosť.
- Hodnoty nie sú uložené spolu - nastáva fragmentácia pamäte pri väčšom počte hodnôt
- Typ hodnoty nie je kontrolovaný - do zoznamu je možné uložiť čokoľvek a typová konverzia pri výbere môže zlyhať.
- Vloženie do zoznamu má vždy konštatntnú zložitosť

```java
public class Main{
    public static void main(String args[]){
        LinkedList ll = new LinkedList);
        // Akého typu bude prvý člen?
        ll.add(1);
        //
        ll.add("Ahoj svet");
        Object f = ll.first();
        // Dá sa urobiť?
        String val = (String)f;
    }
}
```

---
# Spojkový zoznam s generickým typom

Problém s typovou koverziou môžeme riešiť pomocou generických typov. 
Nastane skorá väzba - kontrola typu hodnoty už počas prekladu.

```java
class LinkedList<Type> {
    public class LinkedListItem {
        public LinkedListItem next;
        public Type value;
    }
    private LinkedListItem first;
    void add(Type value){
    	LinkedListItem item = first;
    	LinkedListItem nitem = new LinkedListItem();
    	nitem.value = value;
    	if (first == null){
    	    first = nitem;    
    	}
    	else {
    	    while(item.next != null)
        	    item = item.next;
	        item.next = nitem;
	   }
    }
    Type first(){
    	return first.value;
    }
}

```

---
# Použitie generického spojkového zoznamu:

```java
public class Main{
    public static void main(String args[]){
        LinkedList<Integer> ll = new LinkedList<>();
        ll.add(1);
        // Nie je problém s typovou konverziou, s
        // stará sa o to prekladač
        Integer i = ll.first();
        System.out.println(i);
    }
}
```

https://www.developer.com/java/data/working-with-java-linked-list.html

---
# Problémy vlastnej implementácie pamäťových štruktúr

- Je to pomerne náročne na implementáciu
- Každá pamäťová štruktúra má svoje vlastnosti, ktoré je potrebné brať do úvahy.
	- Spojkový zoznam má konštantnú zložitosť vloženia, ale lineárnu zložitosť prístupu.
    - Dynamické pole má konštantnú zložitosť vloženia na koniec, 
    	ale lineárnu zložitosť vloženia na začiatok (je potrebné poposúvať ostatné prvky).
- Kvôli typovej kontrole je potrebné využívať generické typy.

Pamäťové štruktúry sú ideálne na znovupoužitie.

Je výhodné mať definované štandardné rozhrania pre prístup k skupine objektov.

JDK obsahuje Collections Framework, kotrý rieši tieto problémy.

---
# Kolekcie

Collections Framework

Poskytuje sadu nástrojov a postupov pre prácu s kolekciami:

- Rozhrania
- Implementácie
- Algoritmy

Lepšie polia:
- automaticky sa starajú o veľkosť
- starajú sa o typovú správnosť
- Každá kolekcia sa dá zmeniť na pole

https://docs.oracle.com/javase/tutorial/collections/

---
# Čo je to kolekcia

Skupina objektov rovnakého typu s ktorou je možné manipulovať.

https://docs.oracle.com/javase/7/docs/technotes/guides/collections/index.html

> A collection — sometimes called a container — is simply an object that groups multiple 
elements into a single unit. Collections are used to store, retrieve, manipulate, and 
communicate aggregate data. Typically, they represent data items that form a natural group, 
such as a poker hand (a collection of cards), a mail folder (a collection of letters), 
or a telephone directory (a mapping of names to phone numbers). 
If you have used the Java programming language — or just about any other programming language — 
you are already familiar with collections.

---

# Rozhrania 

## Abstrakcia poľa
- List
- Queue
- Deque

## Abstrakcia množiny
- Set 
- Map


![Collections](https://docs.oracle.com/javase/tutorial/figures/collections/colls-coreInterfaces.gif)

---

# Rozhrania Java Collections Frameworku

Diagram tried zobrazuje vzťahy medzi rozhraniami

                 +------------------+                         +-------------+
                 |    Collection    |                         |      Map    |
                 +------------------+                         +-------------+
                         ^                	                         ^
                         |                                           |
        +-------------+---------------+-------------+                |
        |             |               |             |                |
    +---+----+    +---+-----+    +----+----+   +----+----+   +-----------------+
    |   Set  |    | List    |    |  Queue  |   | Deque   |   |  Sorted Map     |
    +--------+    +---------+    +---------+   +---------+   +-----------------+
         ^
         |
     +--------+
     | Sorted |
     |   Set  |
     +--------+

---
# Abstrakcia poľa a implementácie

Prvou časťou riešenia problému ukladania (Collections Framework) sú rozhrania prístupu k abstraktnému poľu:

- List: Abstrakcia klasického poľa 
	Náhodný prístup k objektom
	- LinkedList
    - ArrayList
	- Stack: zásobík (LIFO)
    	Ukladanie a vyberanie z konca
- Queue: ukladanie do radu (FIFO) alebo do zásbníka (LIFO). Umožnňuje ľahké operácie na ziačiatku alebo na konci kontajnera.
	- LinkedList
    Vkladanie na začiatku, vyberanie na konci zoznamu
- Deque: podobné ako Queue, ale umožňuje aj operácie na oboch koncoch naraz
	- LinkedList
    Vkladanie a vyberanie na začiatku a konci zoznamu

---

# Abstrakcia množiny

- Set: ukladanie unikátnych objektov
	- HashSet
	- SortedSet: unikátne objekty ktoré sú stále zotriedené
    	- TreeSet
- Map: každý objekt má svoju identitu.
	- HashMap
	- SortedMap: objekty s menom, stále zotriedené

---
# Použitie spojkového zoznamu zo štandardnej knižnice


```java
import java.util.LinkedList;
import java.util.List;

public class LinkedListDemo {
   public static void main(String[] args) {
      List<String> llist=new LinkedList<>();
      llist.add("purple");
      llist.add("red");
      String val = llist.get(0);
      System.out.println(val);
	}
}
```


---
# Algoritmy pre prácu s kontajnerami

- Prechádzanie
- Vyhľadávanie
- Triedenie a zamiešanie
- Kopírovanie
- Spájanie kolekcií

https://docs.oracle.com/javase/tutorial/collections/algorithms/index.html

Použitie algoritmov je jednoduché vďaka jednotným rozhraniam a generickým typom.

---
# Triedenie

```java
import java.util.*;

public class Sort {
    public static void main(String[] args) {
        List<String> list = Arrays.asList(args);
        Collections.sort(list);
        System.out.println(list);
    }
}
```

---
# Triedenie podľa vlastných pravidiel

Niekedy nie je jasné, ako porovnať dve hodnoty.

Napr. ako porovnať 2 zoznamy čísel:
- podľa maximálneho čísla
- podľa minimálneho čísla
- podľa veľkosti
- podľa priemeru atď.

Je potrebné dodať spôsob ako porovnať dve hodnoty

---
# Komparátor

Vlastný spôsob porovnávania implementujeme rozhraním Comparator:

```java
public class SizeListofStringsComparator implements Comparator<List<String>> {
	public int compare(List<String> o1, List<String> o2) {
        return o2.size() - o1.size();
    }
}
```
Potom môžme:

```java
List<List<String>> winners = new ArrayList<List<String>>();
Collections.sort(winners, new SizeListofStringsComparator());
```

https://docs.oracle.com/javase/tutorial/collections/algorithms/index.html

---
# Anonymné triedy

Triedu na jedno použitie môžeme implementovať ako anonymnú:


```java
// Sort anagram groups according to size
Collections.sort(winners, new Comparator<List<String>>() {
    public int compare(List<String> o1, List<String> o2) {
        return o2.size() - o1.size();
    }});
```
Anonymnú triedu môžeme implementovať hneď za volaním konštruktora.

http://www.geeksforgeeks.org/anonymous-inner-class-java/

Pre porovnanie: Smerník na funkciu v qsort v jazyku C 

http://www.kiwiki.info/index.php/Qsort_(jazyk_C)

---

# Prechádzanie: Iterator

Rozhranie Collection obsahuje metódu iterator(), ktorá vráti objekt pomocou ktorého môžeme prechádzať kolekciu:

Iterátor je návrhový vzor:

Iterator
- next()
- hasNext()

Iterator iterator();

---
# Prechádzanie kolekcií pomocou iterátora

https://beginnersbook.com/2014/06/java-iterator-with-examples/

Prechádzať je možné každú kolekciu, ktorá implementuje rozhranie java.util.Collection

```java
import java.util.ArrayList;
import java.util.Iterator;
 
public class IteratorDemo3 {
  public static void main(String args[]){
    ArrayList<String> names = new ArrayList<String>();
    names.add("Chaitanya");
    names.add("Steve");
    names.add("Jack");
 
    Iterator<String> it = names.iterator();
 
    while(it.hasNext()) {
      String obj = it.next();
      System.out.println(obj);
    }
 }
}
```

---
# Päť spôsobov prechádzania zoznamu

http://crunchify.com/how-to-iterate-through-java-list-4-way-to-iterate-through-loop/

- For
- For each
- Iterator
- While
- Lambda funkcia

---

# Mapa

Niekedy potrebujeme ukladať objekty pod unikátnym menom.
Mapa definuje tzv. **asociatívne pole**, kde prvky môžu byť uložené pod ľuvoľným menom, ktoré nemusí byť celé číslo.

Napr. početnosť krstných mien v skupine študentov
	
     		 +------+-------+-------+--------+
    Kľúč:    | Ján  | Peter | Jozef | Daniel |
    	     +------+-------+-------+--------+
	hodnota: |  4   |  3    |  2    |   1    |
        	 +------+-------+-------+--------+

---
# Hashovacia tabuľka

Vnútorne je mapa implemtovaná ako hashovacia tabuľka (HashMap)

https://en.wikipedia.org/wiki/Hash_table

Hashovacia funkcia vráti takmer unikátny identifikátor pre zadaný reťazec bytov.
(ľubovoľný reťazec napamuje na celé číslo).

1. Na kľúč je aplikovaná hashovacia funkcia.
1. Pamäťová štruktúra je rozdelená na oddiely.
1. Hashovacia funkcia určí, do ktorého oddielu sa uloží hodnota.

Zjednodušene:

	hash = hashfunc(key)
	index = hash % array_size

Iný spôsob uloženia Mapy je použitie binárneho stromu, napríklad 
Red-Black tree alebo B-tree. Výhodou stromu je, že poriadie kľúčov je vždy zotriedenié.

---

# Spočítajte početnosť slov z príkazového riadku

Použijeme mapu

```java
import java.util.*;

public class Freq {
    public static void main(String[] args) {
        Map<String, Integer> m = new HashMap<String, Integer>();

        // Initialize frequency table from command line
        for (String a : args) {
            Integer freq = m.get(a);
            m.put(a, (freq == null) ? 1 : freq + 1);
        }

        System.out.println(m.size() + " distinct words:");
        System.out.println(m);
    }
}
```

https://docs.oracle.com/javase/tutorial/collections/interfaces/map.html

---
# Precházanie mapy

Mapa nie je priamo podtypom java.util.Collection, vieme si ju ale premeniť na zoznam dvojíc "kľúč-hodnota" pomocou entrySet():
```java
long i = 0;
for (Map.Entry<Integer, Integer> pair : map.entrySet()) {
    i += pair.getKey() + pair.getValue();
}
```

```java
long i = 0;
Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
while (it.hasNext()) {
    Map.Entry<Integer, Integer> pair = it.next();
    i += pair.getKey() + pair.getValue();
}
```

---

Druhou možnosťou je získanie zoznamu kľúčov pomocou keySet():

```java
long i = 0;
for (Integer key : map.keySet()) {
    i += key + map.get(key);
}
```
# 10 spôsobov prechádzania mapy

https://stackoverflow.com/questions/46898/how-to-efficiently-iterate-over-each-entry-in-a-map

---

# Opakovanie: Čo je generické programovanie


Generické programovnanie rozširuje systém typov tak, aby jeden typ alebo metóda mohli 
pracovať rovnakým spôsobom s ľubovoľným iným typom.
https://en.wikipedia.org/wiki/Generics_in_Java

Kontrola môže prebiehať už v čase prekladu.

---
# Funkcia pre výpis obsahu poľa

```java
void printCollection(Collection<Object> c) {
    for (Object e : c) {
        System.out.println(e);
    }
}
```

Problémy tejto immplementácie: 
- Využívame neskorú väzbu
- Funguje iba na Collection\<Object\>, ale už nie na potomkov Object.

```java
Collection<Integer> ints = new Collection<Integer>();
ints.add(2);
printCollection(ints); // Nebude fungovať

```

**Generické typy s rôznymi typovými premennými spolu priamo nesúvisia!**

---
# Typové Žolíky (wildcards)

Problém sa dá riešiť pomocou žolíka ?

```java
void printCollection(Collection<?> c) {
    for (Object e : c) {
        System.out.println(e);
    }
}
```

Prekladač vie žolíka nahradiť za typ aký je prítomný a vykonať typovú kontrolu:

```java
Collection<?> c = new ArrayList<String>();
c.add(new Object()); // Compile time error
```

---

# Obmedzenia generických typov

Pomocou žolíka a kľúčového slova **extends** (alebo **implements**) vieme typovú premennú obmedziť na všetkých potomkov zadanej triedy:

Generický typ na ľavej strane funguje na všetky zoznamy v ktorých sú objekty ktoré sú potomkom Number (napr. Integer, Float)

```java
Collection<? extends Number> c = new ArrayList<Float>();
```

Pomocou žolíka a kľúčového slova **super**  vieme typovú premennú obmedziť na danú triedu a jej predkov:

```java
Collection<? super Float> c = new ArrayList<Number>();
```

Bude akceptovať zoznam čísel Number, ale nebude akceptovať napr. zoznam celých čísel  ArrayList\<Integer\>.



---
# Zhrnutie

Pri ukladaní skupín objektov je možné že typová konverzia zlyhá.

Generická dátové typy umožnňujú skorú väzbu a kontrolu typovej správnsoti už počas prekladu.

Rámec kolekcií poskytuje sadu rozhraní, implementáíciíí a algoritmov 
pre prácu s kolekciami (skupinami objektov rovakého typu).

Anonymnú triedu je možné použiť na rýchle vytvorenie objektu s jednou metódou.

Trieda, ktorá má zmyslel iba s inou triedou môže byť navrhnutá ako vnútorna.

Pomocou ? je možné bližšie špecifikovať generický typ.


---

# Koniec


