# Rôzne poznámky

## Slabé miesta vo výuke:
- čítanie technickej dokumentácie
- algoritmizácia
- práca s reťazcami

## Príklady

https://www.w3resource.com/java-exercises/

http://codingbat.com/java

N árna kalkulačka

2d hra, podľa Tiles

Fitness náramok - spočítaj priemerný počet úderov za určitý čas.



Možno podľa

http://www.learningwithrobots.com/


Actor Model (v Erlang)

http://www.brianstorti.com/the-actor-model/


Vlákna nie sú cesta

Actor
- kompletne izolovaný od iných (nepoužíva zdieľanú pamäť)
- komunikuje prostredníctvom správ (podobne ako objekty v OOP

Actorov musí byť viac

Actor má poštovú schránku do ktorej príma správy)

Actor po prijatí spravy m§že:
- správu poslať ďalej
- alebo vytvoriť novéhoé Actora
- alebo spracovať správu a zmeniť svoj stav

Actor môže zlyhať (spadnáť), ale pred zlyuhaním to oznámi dohľadu


## Vzťahy medzi tredami

Dependency
- Zmena definície zdroja zmení definiciu cieľa
- prerušovaná šípka
 One class depends on another if the independent class is a
 parameter variable or local variable of a method of the dependent class.

---
Association
- an association, an attribute of the dependent class is an instance of the independent class.
- Obyčajná šípka alebo čiara
- Druh vzťahu, ktorý má meno
- poznáme aj ternárnu asociáciu
- každý koniec má kardinalitu
- Typy:
	- Obojsmerná
    - Jednosmerná
    - Agregácia
    - Reflexíva
---
Aggregation
- Šípka s prázdnym diamantom
- Typ asociácie "má".
- kontajner má nejaký obsah

Composition
- Šípka s plným diamantom
- má vo fyzickom zmysle, napr, auto má koleso. Plný diamant je pri aute.

---

Inheritance, generalization
- Čiara s prázdnym trojuholníkom
- Znázorňuje dedičnosť
- trojuholník je pri supertype.

Realization, implementation
- Prerušovaná čiara s prádznym trojuholníkom

 diamant je pri aute.

Inheritance, generalization
- Čiara s prázdnym trojuholníkom
- Znázorňuje dedičnosť
- trojuholník je pri supertype.

Realization, implementation
- Prerušovaná čiara s prádznym trojuholníkom

