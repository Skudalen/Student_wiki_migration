---
title: Generovanie náhodného textu

---

# 8. Generovanie náhodného textu


Ciele:

- Praktická práca s asociatívnym poľom.
- Načítanie textu po slovách.

Dnešná úloha nájde široké uplatnenie v dennej študentskej, úradníckej aj politickej praxi.
Častým problémom v praktickom živote je potreba vytvárať najrôznejšie eseje, reporty, výkazy, články referáty alebo rigorózne práce na rôzne témy.
Tí menej šikovní na túto úlohu využívajú služby profesionálnych spisovateľov alebo drzo kopírujú cudziu prácu.

My šikovnejší si na tento účel naprogramujeme pomocníka, ktorý nám v budúcnosti pomôže na požiadanie vytvoriť esej alebo program na ľubovoľnú tému ktorú si vyberieme. Náš program analyzuje zadaný text a vytvorí z neho jednoduchý štatistický model, ktorý bude vyjadrovať pravdepodobnosť výskytu jednotlivých slov. Ak vieme pravdepodobnosť výskytu, nebude ťažké vytvoriť ľubovoľne dlhý text s podobným výskytom slov, ako bolo
zadané na začiatku.

## 1.  Zistenie početnosti slov v texte

Zo štatistiky vieme, že pravdepodobnosť výskytu javu je priamo úmerná jeho početnosti.
Prvou úlohou bude naprogramovania počítadla slov zo štandardného vstupu.

Počítadlo slov je tvorené asociatívnym poľom, kde reťazcu priradíme celé číslo.
Asociatívne pole si vytvorte ľubovoľným spôsobom - môžete
využiť binárny vyhľadávací strom, hešovaciu tabuľku alebo upravený spojkový zoznam.

Počítadlo slov je asociatívne pole, ktoré slovu priradí jeho početnosť. V prípade, že sa slovo v poli nenachádza, vytvoríte nový
prvok s početnosťou jedna. Ak sa slov o v asociatívnom poli nachádza, zvýšite jeho početnosť o jedna.
Na konci získame asociatívne pole s početnosťami slov.

### 2. Načítanie súboru po riadkoch a tokenizácia textu

Druhou časťou bude modul pre načítanie slov. Zo štandardného vstupu načítava slová a vkladá ich do počítadla.

Pri načítaní textu po slovách môžete využiť funkciu `scanf()`. Načítanie ukončite, keď funkcia vráti hodnotu `EOF`: V prípade, že funkcia vráti hodnotu jedna, bola úspešne načítaná jedna hodnota, teda slovo. Ak bol slovo úspešne načítané, môžete ho vložiť do počítadla.

### 3. Ruleta pre výber ďalšieho slova

Treťou časťou bude generátor slov. Generátor slov bude vyberať slová z počítadla tak, aby slová s väčšou početnosťou budú mať väčšiu pravdepodobnosť výberu. Počet slov na generovanie získajte ako argument príkazového riadka.

Zostrojte generátor náhodných čísel ktorý bude vyberať slová s určitou pravdepodobnosťou.

Každé slovo dostane váhu, ktorá je ekvivalentná jeho početnosti.

Generátor náhodných čísel vyberie číslo z intervalu 0 až N, kde N je celková početnosť slov.

Pri ruletovom výbere postupne prechádzajte všetky slová a spočítavajte ich početnosti. Ak je súčet väčší ako náhodné číslo, vyberieme predošlé číslo. Tak dostaneme generátor náhodných slov, ktorý bude "hovoriť" podobne ako zadaný text.

### Challenge

Vytvorte generátor náhodných slov, ktorý bude brať do úvahy dvojice slov.

