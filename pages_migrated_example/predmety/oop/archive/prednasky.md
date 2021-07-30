# Prednášky

# 1.Úvod do jazyka Java

[Prezentácia](01JavaIntro)

(Everything is an Object, Operators, Controlling Execution, Arrays)

 - Organizačné pokyny
   - podmienky skúšky a zápočtu
   - odporúčaný software, literatúra
 - Inštalácia potrebného software - čo budeme potrebovať? 
  - Ako vyzerá IDE ?
 - Motivácia: Java vo firmách - typické oblasti nasadenia
 - Virtuálny stroj Java
 - Ahoj Svet Java
 - Proces zostavenia Java programu = bajtkód
 - Syntax Jazyka Java 

 
# 2. Úvod do OOP

[Prezentácia](02OOP)

- Prečo je dôležité OOP
- Objekt a trieda
- Statické metódy a premenné
- 4 vlastnosti OOP:
	- abstrakcia
    	- Tvorba modelu reálneho sveta
    - dedičnosť
    	- klasická
        - kompizíciou
    - zapuzdrenie
    	- publilc
        - private
        - protected
    - polymorfizmus
    	- polymorfická referencia
        
# 3. Životný cyklus objektu a balíčky

[Prezentácia](03Methods/presentation)


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

# 4. Dátové typy, dedičnosť a polymorfizmus

Všetky triedy sú potomkom triedy Object.

Polymorfizmus nám zjednodušuje znovupoužiteľnosť kódu.

Potomok má všetky typy jeho predkov.

Typ objektu vieme meniť za behu pomocou pretypovania.

Polymorfizmus môže byť dosiahnutý počas behu aj počas prekladu:

- Počas behu: dedením
- Počas prekladu: preťaženie metód

[Prezentácia](04Inheritance/presentation)

# 5. Abstraktné typy a rozhrania

Triedu môžeme určiť len na dedenie ak určíme že je abstraktná.

Metódu môžem určiť na prekrytie tak, že je abstraktná.

Rozhranie je typ, ktorý je ekvivalentný abstraktnej triede s abstraktnými metódami.

Rozhranie nám umožňuje "viacnásobnú" dedičnosť.

Triedy a rozhrania medzi sebou majú vzťhy, ktoré vieme zobraziť pomocou diagramu tried.

[Prezentácia](05Abstract/presentation)

# 6. Sviatok

# 7. Polia a generické typy

[Prezentácia](07Generic/presentation)

Jednoduché typy odovzdávame hodnotu, zložené referenciou.

Zložené typy musíme kopírovať explicitne, najlepšie pomocou kopy konštruktora.

Referencie alebo jednoduché hodnoty si môžeme uložiť do poľa.

Pole má fixnú veľkosť, a je inicializované na defaultnú hodnotu. Pole môžeme prechádzať pomocou
cyklu typu for alebo cyklu typu for-each.

Defaultná hodnota referencie je null.

Pomocou generických typocv môžeme využiť polymorfizmus so skorou väzbou.
Generické typy nemajú medzi sebou priame vzťahy.

# 8. Kolekcie

[Prezentácia](08Collections/presentation)

Pri ukladaní skupín objektov je možné že typová konverzia zlyhá.

Generická dátové typy umožnňujú skorú väzbu a kontrolu typovej správnsoti už počas prekladu.

Rámec kolekcií poskytuje sadu rozhraní, implementáíciíí a algoritmov 
pre prácu s kolekciami (skupinami objektov rovakého typu).

Anonymnú triedu je možné použiť na rýchle vytvorenie objektu s jednou metódou.

Trieda, ktorá má zmyslel iba s inou triedou môže byť navrhnutá ako vnútorna.

Pomocou ? je možné bližšie špecifikovať generický typ.

# 9. Enumerátory, Výnimky, Vstup a výstup

[Prezentácia](09IO/presentation)

Enumerátory používame na reprezentovanie množiny konštantných hodnôt ktoré spolu súvisia.

- Každá funkcia má chybový výstup, cez ktorý oznamujeme chyby (throws)
- Ak nastala nepredvídaná situácia, oznámime výnimku pomocou príkazu throw
- vykonávanie sa okamžite preruší a výnimka putuje do nadradených funkcií v stacku.
- Výnimku je možné zachytiť pomocou try a ošetriť pomocou catch
- Neošetrené výnimky spôsobia koniec vykonávania a výpis stacku.

Nie každú výnimku je potrebné ošetrovať.
V prípade neočakávanej chyby je dobré ak výnimka preruší beh programu.

- Lepšia pekná smrť (programu) ako škaredý život
- Dobre ukončený program nám umožní ľahko chybu opraviť.

Najhoršia chyba je taká o ktorej nevieme a ktorú nevieme zopakovať.

# 10. Návrhové vzory - vytváranie objektov

[Prezentácia](10.Patterns/presentation)

1. Návrhové vzory
1. Vytváracie návrhové vzory
1. Návrhové anti-vzory


# 11. Návrhové vzory - vytváranie objektov

[Prezentácia](11.Behavioral/presentation)


# 12. Reťazce

[Prezentácia](12.Strings/presentation)


Pri vytváraní reťazca zo súboru  je potrebé riešiť kódovanie.

Reťazec je nemodifikovateľný.

StringBuffer je modifikovateľný.

HashMap sa dá zmeniť na zoznam dvojíc.







