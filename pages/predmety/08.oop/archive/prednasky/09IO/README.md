class: center, middle
# Enumerátory, Vstup a výstup

Objektovo orientované programovanie

Prednáška č. 9

Ing. Daniel Hládek PhD.

---

# Obsah prednášky

Enumerátory

Chyby v programe - teroretický úvod

Čítanie zo súboru

Výnimky, ich ošetrenie a tvorba

---
# Enumerátory

Podľa https://docs.oracle.com/javase/tutorial/java/javaOO/enum.html

Enumerátor je trieda pre uchovávanie viacerých konštánt.

---
# Konštanty v Jave

```java
public class Den {
	public static final int PONDELOK = 1;
    public static final int UTOROK = 2;
    public static final int STREDA = 3;
    public static final int STVRTOK = 4;
    public static final int PIATOK = 5;
    public static final int SOBOTA = 6;
    public static final int NEDELA = 7;
}

public class Robota {
   public void chodDoRoboty(int den){
   		switch(den) {
        	case Den.PONDELOK:
            	System.out.println("Auu");
                break;
            default: 
            	System.out.println("Idem domov");
                break;
                
        }
   }
}

```

---
# Enumerátor

Reprezentujeme uzavretú množinu hodnôt. Kompilátor sa postará o priradenie konkrétnych hodnôt.

```java
public enum Den {
	PONDELOK, 
    UTOROK,
    STREDA,
    STVRTOK,
    PIATOK,
    SOBOTA,
    NEDELA
}

public class Robota {
   public void chodDoRoboty(Den den){
   		switch(den) {
        	case PONDELOK:
            	System.out.println("Auu");
                break;
            default: 
            	System.out.println("Idem domov");
                break;
        }
   }
}

```

---
# Hodnoty Enumerátora

Pomocou konštruktora vieme priradiť enumerátoru atribúty:

```java
enum Den {
	PONDELOK (1),
    UTOROK (2),
    STREDA (3),
    STVRTOK (4),
    PIATOK (5),
    SOBOTA (6),
    NEDELA (7);
    
    private int poradie;
    // Konstruktor nemoze byt public
    Den(int poradie){
    	this.poradie = poradie;
    }
    public int getPoradie(){
    	return poradie;
    }
}

```

---
# Použiti hodnôt enumerátora

```java

public class Robota {
   public void chodDoRoboty(Den den){
   		switch(den) {
        	case PONDELOK:
            	System.out.println(String.format("Auu v %d dni",den.getPoradie()));
                break;
            default: 
            	System.out.println("Idem domov");
                break;
        }
   }
  public static void main(String[] arv){
    Robota r = new Robota();
    r.chodDoRoboty(Den.PONDELOK);
  }
}
```

---

# Chyby v programe

Program má byť:

- Správny
- Rýchly
- Dobre čitateľný

Vyber si dve možnosti z troch, ale jedna z nich musí byť "správny".

---

# Čo znamená správny program

Program, ktorý robí to čo má a nerobí to čo nemá.

Príklad:

- Recept na praženicu, ktorého výsledkom bude rezeň nie je správny.
- Recept na rezeň, ktorého výsledkom bude živočíšne uhlie nie je správny.
- Stavebnica, ktorej postavenie trvá nekonečný čas nie je použiteľná.

Program môže mať aj nežiadúce vedľajšie účinky:

Príklad:

- Recept na praženicu, ktorý obsahuje inštrukciu "Choď do obchodu" nie je správny.
- Auto, do ktorého prší nie je všeobecne použiteľné auto.
- Nápoj z ktorého ma vždy bolí hlava nie je zdravý.
	
---
# Princíp Occamovej Britvy

Ak program robí to čo nemá, nie je správny.

Len minimálny program je ten správny.

Ak napíšem program na 200 riadkov a to isté sa dá napísať na 20 riadkov, môj kód obsahuje 150 riadkov chýb.

UNIX vs. WINDOWS 

---
# Murphyho zákon

Každý program obsahuje aspoň jednu chybu.

---
# Čo znamená robustný program:

Program by mal byť schopný prakcovať aj za hraničných podmienok

- Ak je vstup reťazec, žadny reťazec by nemal predčasne ukončiť program.
- Ak je možné aby s programom pracovanli viacerí naraz, nemali by vznikať konflikty

Robustný program nemá špeciálne požiadavky na používateľa

Je "blbuvzdorný" - rieši všetky očakávané chyby.

---
# Riešenie chybových stavov v Jave

- Očakávaná chyba (chyba používateľa)
    - Ošetri chybu a pokračuj
    - Stav programu je dobre definovaný
- Neočakávaná chyba
    - zapíš podmienky za ktorých nastala chyba a skonči.
    - stav programu je nedefinovaný
    - Je potrebné zabrániť šíreniu chyby - nedefinovaný stav programu sa nevie sá dostať do definovaného stavu
---

## Očakávaná chyba - Príklad:

Program si vyžaduje zadať číslo s desatinnou čiarkou

pomocou textového vstupu je možné zadať ľubovoľný reťazec.

Formát desatinného čísla je závislý aj od lokálneho nastavenia desatinného oddeľovača (boka alebo čiarka)

---
# Neočakávaná chyba - Príklad

Program sa pokúsi alokovať pamäť, tá ale nie je dostupná

Riešenie:

vypíše chybovú hlášku, že nie je možné pokračovať kvôli nedostatku pamäte.

Dostali sme sa do nedefinovaného stavu

Nikdy sa nepokúšajme ošetriť nedefinovaný stav programu a pokračovať, chyba sa bude šíriť.

---
# Čítanie zo súboru po riadkoch

1. Otvoríme súbor
1. Načítavame, pokiaľ nenájdeme koniec riadku alebo koniec súboru
1. Ak nájdem koniec riadku, spracujeme riadok a načítavame ďalej
1. Ak nájdeme koniec súboru, spracujeme načítané bajty a skončíme.


---
# Otvorenie súboru

InputStreamReader

[FileReader](https://docs.oracle.com/javase/7/docs/api/java/io/FileReader.html)

Vie čítať súbor po znakoch

metóda read

	InputStreamReader r = new FileReader("subor.txt");
    int byte = r.read()
    char buf[] = new char[32];
    r.read(buf,0,32);
    r.close()

---

# Možné problémy

Kde všade môže nastať problém? (Všade)

- súbor nemusí existovať
- nemusíme mať práva na čítanie
- súbor môže prestať existovať počas čítania
- Súbor nemusí obvsahovať koniec riadku
- V pamäti nemusí byť dosť miesta na uloženie načítaných údajov.


Niektoré problémy môžeme ošetriť pomocou výnimiek.

# Obmedzenia 

- čítame iba po znakoch. Ako načítame po riadkoch?

---
# Riešenie chybových stavov v Jave

Výnimku vieme zachytiť a ošetriť klauzulou try-catch-finally

Skladá sa z troch blokov kódu:

- Do try ide kód, ktorý môže vyvolať výnimku
- Do catch ide kód, ktorý ošetrí výmimku. Každý typ výnimky, ktorý nás zaujíma by mal mať svoj blok catch
- Do finally ide kód, ktorý súvisí s blokom try, ale vykoná sa vždy.
	Využíva sa na uvoľneinie prostridkov nezávisle od toho, či prvý blok zlyhal.


---
# blok try

Kód, ktorý môže vyvolať výnimku ohraničíme do osobitného bloku.

To vytvorí osobitný kontext - premenné definované v tomto bloku inde neplatia.

Kód v tomto bloku môže vyhodiť výnimku na ktoromkoľvek riadku.

Táto výnimka bude zachytená v bloku catch.

---

# Bloky catch

Vyvolaná výnimka bude zachytená v bloku catch podľa jej **typu**.

Nikdy neošetrujeme všeobecnú výnimku Exception!

---
# Príklad s ošetrením výnimky

	try {
    	InputStreamReader r = new FileReader("subor.txt");
    	char buf[] = new char[32];
    	r.read(buf,0,32);
        r.close();
    }
    catch (FileNotFoundException ex){
    	System.out.println("Súbor sa nepodarilo najst...").
    }
    catch (IOException ex){
    	System.out.println("Súbor sa nepodarilo spracovať...").
    }

---
# Problémy tohto ošetrenia

Nevieme na ktorom riadku nastal problém

Nebol vydaný príkaz na zatvorenie súboru - zostane neuvoľnený zdroj.

---
# Blok finally

Do finally píšeme príkazy na uvoľnenie

	InputStreamReader r = null;
    try {
    	r = new FileReader("subor.txt");
    	int byte = r.read()
    	char buf[] = new char[32];
    	r.read(buf,0,32);
    }
    catch (FileNotFoundException ex){
    	System.out.println("Súbor sa nepodarilo najst...").
    }
	catch (IOException ex){
    	System.out.println("Súbor sa nepodarilo spracovať...").
    }
    finally {
        try {
            if (r != null)
                r.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

---
Každý riadok by mal mať svoj vlastný blok try catch

	InputStreamReader r = null;
	try {
    	r = new FileReader("subor.txt");
    	try {
    		char buf[] = new char[32];
    		r.read(buf,0,32);
        }
        catch (IOException ex){
    		System.out.println("Súbor sa nepodarilo spracovať...");
        }
    }
    catch (FileNotFoundException ex){
    	System.out.println("Súbor sa nepodarilo najst...");
    }
	
    finally {
            try {
                if (r != null)
                    r.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

---

# Povinné a nepovinné výnimky

Zodpovednosť za ošetrenie výnímy môžeme presúnúť ďalej.

Metóda môže oznámiť prekladaču, že môže spôsobiť výnimky pomocou klauzuly throws.

Všetky výnimky oznámené pomocou throws musia byť ošetrené.

---
Príklad

	 public char[] readFile(String filename) throws FileNotFoundException {
        InputStreamReader r = null;
        try {
            r = new FileReader("subor.txt");
            try {
                char buf[] = new char[32];
                r.read(buf,0,32);
                return buf;
            }
            catch (IOException ex){
                System.out.println("Súbor sa nepodarilo spracovať...");
            }
        }
        finally {
            try {
                if (r != null)
                    r.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return null;
    }

---

# Vyvolanie vlastnej výnimky

Výnimka je mechanizmus na "ohlásenie" chyby. Chybu potom môžeme ošetriť alebo aj nie.
Výnimka je zároveň zovšeobecnienie neočakávaného stavu.

Výnimku vyvoláme príkazom:

    throw new Exception()

tento príkaz spôsobí okamžitú "žiadosť" o vyriešenie neočakávaného stavu. 

Ak výnimku nezachytíme, spôsobí okamžité ukončenie. 


---
# Spôsoby ošetrenia výnimiek

- Vypíš chybu sa skonči (pre neočakávané chyby)
    - je dôležité aby aplikácia mala systém pre zaznamenávanie chyb - log.
    - log by mal čo najpodrobnejšie opisovať za akých podmienok nasatal aneočakávaná chyba.
- vyrieš chybu a pokračuj (pre očakávané)


# Slabiny systému výnimiek

- výnimka je zachytená pomocou typu výnimky, nie hodnoty, nie je preto možné používať generické výnimky
- Výnimka tvorí ďalší možný výstup metódy, ktorý je nutné brať do úvahy.
- Kód je komplikovanejší
- Je treba sa správne rozhodnúť, ktorú výnimku ošetriť a ktorú nie.


---
# Čitanie s buffrom


Použijeme wrapper - obalíme jeden objekt do druhého pre pridanie funkcionality

Obyčajný FileReader alebo InputStreamReader nevie čítať po riadkoch.

Táto trieda obsahuje aj buffer na riadok.

Metóda readLine


     For top efficiency, consider wrapping an InputStreamReader within a BufferedReader. For example:

     BufferedReader in
       = new BufferedReader(new InputStreamReader(System.in));
 
 

---
Celý príklad
http://www.avajava.com/tutorials/lessons/how-do-i-read-a-string-from-a-file-line-by-line.html

```java
package test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class ReadStringFromFileLineByLine {

	public static void main(String[] args) {
		try {
			File file = new File("test.txt");
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			StringBuffer stringBuffer = new StringBuffer();
			String line;
			while ((line = bufferedReader.readLine()) != null) {
				stringBuffer.append(line);
				stringBuffer.append("\n");
			}
			fileReader.close();
			System.out.println("Contents of file:");
			System.out.println(stringBuffer.toString());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
```




---

# Zhrnutie: Chyby a výnimky

- Čo je to chyba v programe?
- Druhy chýb v programe
 - Runtime
    - Expected
    - Fatal
 - Compile Time

---

# Systém výnimiek

- Každá funkcia má chybový výstup, cez ktorý oznamujeme chyby (throws)
- Ak nastala nepredvídaná situácia, oznámime výnimku pomocou príkazu throw
- vykonávanie sa okamžite preruší a výnimka putuje do nadradených funkcií v stacku.
- Výnimku je možné zachytiť pomocou try a ošetriť pomocou catch
- Neošetrené výnimky spôsobia koniec vykonávania a výpis stacku.

Nie každú výnimku je potrebné ošetrovať.
V prípade neočakávanej chyby je dobré ak výnimka preruší beh programu.

- Lepšia pekná smrť (programu) ako škaredý život
- Dobre ukončený program nám umožní ľahko chybu opraviť.

Najhoršia chyba je taká, ktorú nevieme zopakovať

---

# Bibliografia

https://docs.oracle.com/javase/tutorial/essential/io/

---

# Koniec

