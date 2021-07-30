class: center,middle
# Polia a generické typy

Prednáška č. 7

Objektovo orientované programovanie

Ing. Daniel Hládek PhD.

---

# Obsah prednášky

- Odovzdávanie hodnoty a referencie
- Polia
- Generické typy

---
# Zaujímavosť

Môžete vyskúšať počas prednášky

Online Java IDE

- https://www.compilejava.net/
- https://www.jdoodle.com/online-java-compiler

---
# Odovzdávanie hodnoty jednoduchých typov

Jednoduché typy sa odovzdávajú kópiou:

```java
public class MyValue {
	public static void uprav(int v){
    	// Dostali sme novú kópiu
    	v  = 2;
        // Výsledok hneď zabudneme
    }
    public static void main(String[] args) {
		int v = 1; 
        uprav(v);
        System.out.println(v);
    }
}
```
Nedôjde k modifikácii.

---
# Odovzdávanie hodnoty v Jave

V Jave sa objekty (zložené typy) odovzdávajú vždy referenciou:

```java
public class MyValue {
	int hodnota = 1;
	public static void uprav(MyValue v){
    	// Modifikujeme objekt na ktor ukazuje referencia
    	v.hodnota = 2;
        // Do loálnej premennej sa uloží nová rteferencia, 
        // tá sa ale hneď zabudne
        v = new MyValue();
         
    }
    public static void main(String[] args) {
		MyValue v = new MyValue();
        uprav(v);
        System.out.println(v.hodnota);
    }
}
```

Keď odovzdávame referenciu, tak odovzdávame právo objekt modifikovať.

---
# Slovíčko final

Pomocou slovíčka final môžeme zabrániť priradeniu hodnoty:
```java
public class MyValue {
	int hodnota = 1;
	public static void uprav(final MyValue v){
    	// nemôžeme urobiť
        // v = new MyValue()
    	v.hodnota = 2;
    }
    public static void main(String[] args) {
		MyValue v = new MyValue();
        uprav(v);
        System.out.println(v.hodnota);
    }
}

```

To ale nezabráni modifikácii členskej premmennej.

Pomocou final môžeme zabrániť dedičnosti.

---
# V  Jave neexistuje nemodifikovateľný objekt

Modifikácii objektu zabránime pomocou zapuzdrenia.

Je rozdiel modifikovať objet a referenciu na objekt.

Na objekt môže existovať viacero referencií.

http://www.javapractices.com/topic/TopicAction.do?Id=29


---
# Kontrola prístupu k členským premenným

Modifikácii môžeme zabrániť pomocou prístupových metód:

```java
public class MyValue {
	public final int hodnota = 1;
    private int hodnota2 = 2;
    public int getHodnota2(){
    	return hodnota2;
    }
	public static void uprav(MyValue v){
    	// nemôžeme urobiť
        //  v.hodnota = 2;
        // ani
        // v.hodnota2 = 3;
        // Môžeme iba:
        int h1 = v.hodnota;
        int h2 = v.getHodnota2();
    }
    public static void main(String[] args) {
		MyValue v = new MyValue();
        uprav(v);
        System.out.println(v.hodnota);
    }
}

```

---

# Hierarchia Tried v Jave

Pomocou dedičnosti si vieme tvoriť hierarchiu tried.

Skoro všetky typy sú potomkom Object (okrem jednoduchých dátových typov).

Každý zložený typ v Jave je možné kopírovať, porovnávať a vypisovať na obrazovku.

Všeobecné vlastnosti všetkých objektov:

(rozhranie všetkých objektov)

- clone(): kopírovanie
- equals(): porovnanie
- toString(): výpis na obrazovku

Pozor - všeobecná implementácia nefunguje podľa očakávania.
Pre dosiahnutie požadovaného efektu je nutné tieto metódy prekryť.

---
# Kopírovanie primitívnych objektov v Jave

Pri primitívnych objektoch je situácia jednoduchá -
kopírovať sa dá jednoznačným spôsobom.

```java
public class MyValue {
	public int value = 1;
	 public static void main(String[] args) {
		int a = 1;
        // Dôjde ku kopírovaniu
        int b = a;
        b = 2;
        System.out.println(a);
        
        MyValue c = new MyValue();
        // Dôjde k odovzdaniu referencie
        MyValue d = c;
        d.value = 4;
        System.out.println(c.value);
    }
}

```

---

# Kopírovanie zložených objektov v Jave

Na implementáciu kopírovania objektu môžeme  preťažiť metódu clone()

```java
public class MyValue {
	public int value = 1;
    public Object clone(){
    	MyValue v = new MyValue();
        v.value = value;
        return v;
    }
	public static void main(String[] args) {
       
        MyValue c = new MyValue();
        // Dôjde k odovzdaniu referencie
        MyValue d = c;
        // Dôjde ku kopírovaniu, musíme urobiť typovú konverziu
        MyValue e = (MyValue)c.clone();
    }
}

```
Koľko inštancií MyValue máme k dispozícii na konci programu?

---
# Nevýhody metódy clone

Ak implementujeme metódu clone, musia ju implementovať aj všetky podtriedy.

http://www.javapractices.com/topic/TopicAction.do?Id=71

Musíme urobiť typovú konverziu.

Nepoužívajte metódu clone()!


---
# Kopírovanie pomocou kopy konštruktora

Tú istú funkcionalit vieme implementovať pomocou tzv. kopy konštruktora.

Kopy konštruktor, je konštruktor, ktorý ako parameter berie referenciu na aktuálny typ:

```java
public class MyValue {
	public final int value;
	public MyValue(){
    	this.value = 1;
    }
    public MyValue(MyValue other){
    	this.value = other.value;
    }
    public static void main(String[] args) {
        MyValue c = new MyValue();
        // Dôjde k odovzdaniu referencie
        MyValue d = c;
        // Dôjde ku kopírovaniu
        MyValue e = new MyValue(c);
    }
}

```
http://www.javapractices.com/topic/TopicAction.do?Id=12


---

# Polia v Jave


http://introcs.cs.princeton.edu/java/14array/
https://docs.oracle.com/javase/tutorial/java/nutsandbolts/arrays.html

Pole je zložený dátový typ.
Pole v Jave je objekt.

---
# Vytvorenie poľa

Do poľa si vieme uložiť jednoduchý alebo zložený typ.

Pole má fixnú veľkosť.

Pri inicializácii sa použije defaultná hodnota typu.

- Operátorom new
- Pomocou literálu (statická inicializácia)

---
# Vytvorenie poľa príklad 

```java
class MyValue {
	int hodnota = 1;
    
    public static void main(String[] args) {
		int[] firstArray = new int[10];
        char[] secondArray = { 'd', 'e', 'c', 'a', 'f', 'f', 'e',
			    'i', 'n', 'a', 't', 'e', 'd' };
   
       MyValue[] thirdArray = new MyValue[10];
    }
}

```

Čo bude obsahovať jednotlivé polia?

---

# Prechádzanie poľa

Ako sa polia inicializovali? Využijeme cyklus for a členskú premennú lenght.

K prvkom poľa pristupujeme pomocou indexu a operátora \[\].


```java
public class MyValue {
    public static void main(String[] args) {
		int[] firstArray = new int[10];
        for (int i = 0; i < firstArray.length; i++){
			System.out.println(firstArray[i]);        
    	}
        char[] secondArray = { 'd', 'e', 'c', 'a', 'f', 'f', 'e',
			    'i', 'n', 'a', 't', 'e', 'd' };
        for (int i = 0; i < secondArray.length; i++){
			System.out.println(secondArray[i]);        
    	}
        MyValue[] thirdArray = new MyValue[10];
        for (int i = 0; i < thirdArray.length; i++){
			System.out.println(thirdArray[i]);        
    	}
    }
}

```

---

# Inicializácia poľa objektov

Defaultná hodnota referencie je null. Pole objektov je nutné inicializovať explicitne pomocou cyklu:

```java
public class MyValue {
	public final int hodnota = 1;
    public static void main(String[] args) {
      MyValue[] thirdArray = new MyValue[10];
      for (Object value:thirdArray){
      		System.out.println(value);
      }
      for (int i = 0; i < thirdArray.length; i++){
      	thirdArray[i] = new MyValue(); 
      }
      for (Object value:thirdArray){
      		System.out.println(value);
      }
    }
}
```

---
# Prechádzanie poľa 2

Môžeme použiť skrátenú formu prechádzania poľa:

```java
public static void printIntArray(MyValue[] array) {
    for (MyValue v:array{
		System.out.println(v);        
    }
}
```

Existuje mechanizmus na prechádzanie všetkých prvkov - **iterácia**.

- https://stackoverflow.com/questions/85190/how-does-the-java-for-each-loop-work
- https://docs.oracle.com/javase/specs/jls/se8/html/jls-14.html#jls-14.14.2

Aký bude výsledok?


## Cyklus typu for - each

---
# Výpis objektu

Pre uľahčenie ladenia si môžeme preťažiť metódu toString():

```java
public class MyValue {
	public final int hodnota = 1;
    @Override
    public String toString(){
    	return Integer.toString(hodnota);
    }
    public static void main(String[] args) {
      MyValue[] thirdArray = new MyValue[10];
      for (int i = 0; i < thirdArray.length; i++){
      	thirdArray[i] = new MyValue(); 
      }
      for (Object value:thirdArray){
      		System.out.println(value);
      }
    }
}
```




---

# Vytvorenie dvojrozmerného poľa

Dvojrozmerné pole je pole polí.

```java
class MultiDimArrayDemo {
    public static void main(String[] args) {
        String[][] names = {
            {"Mr. ", "Mrs. ", "Ms. "},
            {"Smith", "Jones"}
        };
        // Mr. Smith
        System.out.println(names[0][0] + names[1][0]);
        // Ms. Jones
        System.out.println(names[0][2] + names[1][1]);
    }
}
```

z https://docs.oracle.com/javase/tutorial/java/nutsandbolts/arrays.html


---

# Prechádzanie poľa a vyhľadávanie hodnoty

Príklad podľa:

https://stackoverflow.com/questions/14489590/iterating-through-array-java

```java
public static boolean inArray(char[] array, char check) {
    for (int i = 0; i < array.length; i++){
        if (array[i] == check) 
            return true;
     }
    return false;
}
```

---

# Príklad na kopírovanie poľa 2

Metódy pre prácu s poliami:

[java.utils.Arrays](https://docs.oracle.com/javase/8/docs/api/java/util/Arrays.html)


```java
class ArrayCopyOfDemo {
    public static void main(String[] args) {
        
        char[] copyFrom = {'d', 'e', 'c', 'a', 'f', 'f', 'e',
            'i', 'n', 'a', 't', 'e', 'd'};
            
        char[] copyTo = java.util.Arrays.copyOfRange(copyFrom, 2, 9);
        System.out.println(new String(copyTo));
        
        char[] copyTo2 = new char[7];
        System.arraycopy(copyFrom, 2, copyTo2, 0, 7);
        System.out.println(new String(copyTo2));
        
        char[] copyTo3 = copyFrom.clone();
   
    }
}
```

---
# Vzťah medzi poliami jednotlivých typov

Ako súvisia:

```java

int[] firstArray = new int[10];
char[] secondArray = { 'd', 'e', 'c', 'a', 'f', 'f', 'e',
        'i', 'n', 'a', 't', 'e', 'd' };
MyValue[] thirdArray = new MyValue[10];

```
- Aké majú tieto objekty spoločné vlastnosti?
- Majú spoločného potomka?

---
# Ako by ste vylepšili tento kód?

Aby bol stručnejší a prehľadnejší?

```java
public class MyValue {
    public static void main(String[] args) {
		int[] firstArray = new int[10];
        for (int i = 0; i < firstArray.length; i++){
			System.out.println(firstArray[i]);        
    	}
        char[] secondArray = { 'd', 'e', 'c', 'a', 'f', 'f', 'e',
			    'i', 'n', 'a', 't', 'e', 'd' };
        for (int i = 0; i < secondArray.length; i++){
			System.out.println(secondArray[i]);        
    	}
        MyValue[] thirdArray = new MyValue[10];
        for (int i = 0; i < thirdArray.length; i++){
			System.out.println(thirdArray[i]);        
    	}
    }
}

```

---
# Motivácia - Generické typy

Každé pole má svoj vlastný typ - pre prácu s každým typom
poľa je nutné spraviť osobitnú metódu, ktorá sa líši iba typom.

Typ poľa je možné zovšeobecniť pomocou typovej premennej.

Generické typy umožňujú:

- kontrolu správnosti typov už počs prekladu
- nie sú nutné operácie pretypovania
- je možné generické implementovať algoritmy, ktoré pracujú s rôznymi typmi ktoré spolu nemusia súvisieť

Generické typy umožnujú "skorú väzbu".

---
# Viac implementácií toho istého

```java
public static void printIntArray(int[] array) {
    for (MyValue v:array{
		System.out.println(v);        
    }
}

public static void printCharArray(char[] array) {
    for (MyValue v:array{
		System.out.println(v);        
    }
}

```

---

# Typová premenná

Premenná, do ktorej sa uloží názov typu s ktorým sa pracuje.

Obsah typovej premennej (aktuálny typ) určuje aké rozhranie máme k dispozícii.

Je možné skontrolovať to už počas prekladu.


---
# Generická metóda

Môžeme si definovať typovú premennú a 
pomocou nej zovšeobecniť prácu rôznymi typmi polí.

```java
public class GenericMethod {
    public static <Type> void printArray(Type[] array) {
        for (Type v:array){
            System.out.println(v);        
        }
    }
    public static void main(String[] argv){
    	Integer[] a = {1,2,3};
        printArray(a);
        Character[] b = {'a','b','c'};
        printArray(b);
    }
}

```
Pri volaní generickej metódy si kompilátor počas prekladu odvodí a skontroluje typ s ktorým sa pracuje.


---

# Obmedzenia typovej premennej

Typ v typovej premennej musí byť potomkom Object, čo neplatí pre primitívne typy:

```java
public class MyValue {
	public final int value = 1;
    @Override
    public String toString(){
    	return Integer.toString(value);
    }
    public static <Type> void printArray(Type[] array) {
    	// Môžeme používať všetky metódy ktoré má trieda Object
        for (Type v:array){
            System.out.println(v);        
        }
    }
    public static void main(String[] argv){
    	int[] a = {1,2,3};
        printArray<int>(a); // Nebude fungovať
        char[] b = {'a','b','c'};
        printArray(b); // Nebude fungovať
        MyValue c[] = new MyValue[3];
        for (int i = 0; i < c.length; i++){
        	c[i] = new MyValue();
        }
        printArray(c);
    }
}

```

---

# Obmedzenia typovej premennej

Integer a Character sú triedy, ktoré obaľujú primitívne dátové typy aby bolo možné
používať generické metódy.


```java
public class MyValue {
	public final int value = 1;
    @Override
    public String toString(){
    	return Integer.toString(value);
    }
    public static <Type> void printArray(Type[] array) {
    	// Môžeme používať všetky metódy ktoré má trieda Object
        for (Type v:array){
            System.out.println(v);        
        }
    }
    public static void main(String[] argv){
    	Integer[] a = {1,2,3};
        printArray(a); 
        Character[] b = {'a','b','c'};
        printArray(b);
        MyValue c[] = new MyValue[3];
        for (int i = 0; i < c.length; i++){
        	c[i] = new MyValue();
        }
        printArray(c);
    }
}

```

---

# Generické triedy

Typovú premennú je možné využiť aj v definícii triedy:

```java
class MyValue<Type>  {
	private Type value;
    public MyValue(Type value){
    	this.value = value;
    }
    public String toString(){
    	// Túto metódu môžeme použiť, lebo vieme že Type je potomkom Object
    	return value.toString();
	}
   
}

public class Main{
 	public static void main(String[] argv){
    	// Kompilátor si vie odvodiť typ inštancie
    	MyValue<Integer> val = new MyValue<>(1);
        System.out.println(val);
        MyValue<Character> val2 = new MyValue<>('c');
        System.out.println(val2);
    }
}

```

---

# Raw typy

Generický typ, ktorý voláme ako obyčajný typ:

```java
class MyValue<Type>  {
	private Type value;
    public MyValue(Type value){
    	this.value = value;
    }
    public String toString(){
    	// Túto metódu môžeme použiť, lebo vieme že Type je potomkom Object
    	return value.toString();
	}
   
}
public class Main{
 	public static void main(String[] argv){
    	MyValue val = new MyValue(1); // Nesprávne
        System.out.println(val);
        MyValue val2 = new MyValue('c');  // Nesprávne
        System.out.println(val2);
    }
}

```

Zbavujeme sa výhod generických typov - kontrolu typov už počas prekladu.


---
# Vzťahy generických typov

Dá sa urobiť?

```java
MyValue<Number> val = new MyValue<Float>();
```


---

# Vzťahy medzi generickými typmi

Generické typy nie sú navzájom vo vzťahu,

ale sú potomkami Object.


https://docs.oracle.com/javase/tutorial/extra/generics/subtype.html



---

# Zhrnutie

Jednoduché typy odovzdávame hodnotu, zložené referenciou.

Zložené typy musíme kopírovať explicitne, najlepšie pomocou kopy konštruktora.

Referencie alebo jednoduché hodnoty si môžeme uložiť do poľa.

Pole má fixnú veľkosť, a je inicializované na defaultnú hodnotu. Pole môžeme prechádzať pomocou
cyklu typu for alebo cyklu typu for-each.

Defaultná hodnota referencie je null.

Pomocou generických typocv môžeme využiť polymorfizmus so skorou väzbou.
Generické typy nemajú medzi sebou priame vzťahy.

---

# Koniec
