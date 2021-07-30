class: center, middle
# Reťazce

Objektovo orientované programovanie

Ing. Daniel Hládek PhD.

---
# Organizačné pokyny

- Zápočty
- Predtermín
- Skúšky

Sledujte stránku predmetu pre oznamy


---
# Čo je reťazec v Jave?

- https://docs.oracle.com/javase/tutorial/java/data/strings.html
- https://docs.oracle.com/javase/7/docs/api/java/lang/String.html

- Zložený dátový typ
- Vnútorne je implementovaný ako pole znakov v kódovaní UTF-16
- Nie je meniteľný - na vytvorenie je potrebné vytvoriť nový reťazec
- dá sa ľahko vytvoriť
- Práca s reťazcami bude na skúške

---
# Tvorba reťazca

Pomocou literálu:

	String ahoj = "Ahoj svet";

Z poľa znakov (a pomocou operátora new):

	char[] helloArray = { 'h', 'e', 'l', 'l', 'o', '.' };
	String helloString = new String(helloArray);
	System.out.println(helloString);

---
# Tvorba reťazca z binárnych dát

- Vnútorne je implementovaný ako pole znakov v kódovaní UTF-16

```java
package com.company;

import java.io.UnsupportedEncodingException;

public class Main {
    public static void main(String args[]) {

        try {
            String euro = "hello €";
            System.out.println(euro);
            byte[] eurobytes = euro.getBytes("UTF-8");
            for (byte b: eurobytes){
                System.out.printf("%02X ",b);
            }

            String h = new String(eurobytes,"UTF-8");
            System.out.println(h);
        }
        catch (UnsupportedEncodingException ex){
            ex.printStackTrace();

        }
    }
}
```

---
# Výpis reťazca a formátovanie reťazca

System.out

- Formátovacia šablóna
- Podobne ako printf, sprinf 

String.format

---
# Premena reťazca na číslo

https://docs.oracle.com/javase/tutorial/java/data/converting.html

```java
public class ValueOfDemo {
    public static void main(String[] args) {
        // this program requires two 
        // arguments on the command line 
        if (args.length == 2) {
            // convert strings to numbers
            float a = (Float.valueOf(args[0])).floatValue(); 
            float b = (Float.valueOf(args[1])).floatValue();

            // do some arithmetic
            System.out.println("a + b = " +
                               (a + b));
            System.out.println("a - b = " +
                               (a - b));
            System.out.println("a * b = " +
                               (a * b));
            System.out.println("a / b = " +
                               (a / b));
            System.out.println("a % b = " +
                               (a % b));
        } else {
            System.out.println("This program " +
                "requires two command-line arguments.");
        }
    }
}
```

---

# Premena čísla na reťazec

Pomocou

	Integer.toString(vale)
    
Pomocou formátovacieho reťzazca a String.format

---
# Iné operácie

Dĺžka reťazca:
- length

Získanie konkrétneho znaku:
- charAt
    
Vyhľadanie podreťazca
	- idnexOf
    
Porovnávanie: 
	- equals

---
# Spájanie reťazcov

Metóda concat()

	"My name is ".concat("Rumplestiltskin");

operátor +

	"Hello," + " world" + "!"

---
# StringBuilder

Modifikovateľný reťazec

https://docs.oracle.com/javase/tutorial/java/data/buffers.html


klasické spájanie reťazcov je neefektívne, lebo každé pridanie nového reťazca 
si vyžaduje novú alokáciu pamäte.


- Návrhový vzor

- insert
- append
- replace
- delete


---
# Delenie reťazca (tokenizácia)

https://docs.oracle.com/javase/7/docs/api/java/util/StringTokenizer.html

String.split

StringTokenizer - správa sa podoben ako Iterátor


```java
StringTokenizer st = new StringTokenizer("this is a test");
while (st.hasMoreTokens()) {
	System.out.println(st.nextToken());
}
```

---
# Príklad

Zoberte súbor so slovenským textom a zostavte slovník. Zistite, koľko krát sa nachádza každé slovo v texte.

Zostavte zoznam slov a usporiadajte ho podľa početnosti.

---
# Príklad - tvorba slovníka

```java
 public static Map<String,Integer> count(InputStream in) throws IOException {
        // Premeni bajty na znaky
        InputStreamReader isr = new InputStreamReader(in);
        // Pocitadlo na retazce
        Map<String, Integer> counter = new HashMap<>();
        // nacitavanie po riadkoch
        BufferedReader lines = new BufferedReader(isr);

        for (String line = lines.readLine(); line != null; line = lines.readLine()) {
            // Rozdelenie riadka na slova podla medzier
            StringTokenizer tok = new StringTokenizer(line);
            while (tok.hasMoreTokens()) {
                String t = tok.nextToken();
                // Zistenie aktualneho poctu
                Integer count = counter.getOrDefault(t, 0);
                count += 1;
                // Ulozenie noveho poctu
                counter.put(t, count);
            }
        }
        return counter;
    }
```

---
# Príklad - triedenie zoznamu podľa početnosti

```java
 public static List<Map.Entry<String, Integer>> sort(Set<Map.Entry<String, Integer>> entrySet){
        // Premena mapy na zoznam dvojic
        List<Map.Entry<String, Integer>> items  = new LinkedList<>(entrySet);
        // Zotriedenie zoznamu podla hodnoty
        Collections.sort(items, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o1.getValue().compareTo(o2.getValue());
            }
        });
        return items;
    }
```

---
# Príklad - výpis zoznamu
```java
public class Main {
    public static void main(String[] args) {
        try {
            FileInputStream ifs = new FileInputStream("inputfile.txt");
            Map<String, Integer> dict = UnigramCounter.count(ifs);
            List<Map.Entry<String,Integer>> list = UnigramCounter.sort(dict.entrySet());
            // Prechadzanie zotriedeneho zoznamu
            Iterator<Map.Entry<String, Integer>> it = list.iterator();
            while(it.hasNext()){
                Map.Entry<String, Integer> e = it.next();
                // Vypis
                System.out.println(String.format("%s %d",e.getKey(),e.getValue()));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
```

---
# Zhrnutie

Pri vytváraní reťazca zo súboru  je potrebé riešiť kódovanie.

Reťazec je nemodifikovateľný.

StringBuffer je modifikovateľný.

HashMap sa dá zmeniť na zoznam dvojíc.

---
# Koniec

Znamená nový začiatok.
