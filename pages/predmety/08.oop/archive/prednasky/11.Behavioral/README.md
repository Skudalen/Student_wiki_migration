class: center, middle
# Návrhové vzory správania a štruktúry

Objektovo orientované programovanie


Ing. Daniel Hládek PhD.

---
# Dôležité návrhové vzory (budú na cvičeniach)

- Factory Method
- Singleton


- State
- Strategy
- Observer
- Iterator
---
# Behaviorálne vzory

- Reťaz zodpovednosti – Chain of Responsibility
- Command
- Interpreter
- Iterator
- Mediator
- Memento
- Observer
- State
- Strategy
- Template Method
- Visitor

---
# Strategy

- Skupina algoritmov implementuje rovnaké rozhranie
- Rozhranie závisí na určitom kontexte

![Strategy](https://upload.wikimedia.org/wikipedia/commons/4/45/W3sDesign_Strategy_Design_Pattern_UML.jpg)


---
# State

- Objektová implementácia stavového stroja
- State Context je stavový stroj a Stratégia
- Stav je Stratégia, ktorá mení StateContext.

http://it4kt.cnl.sk/c/oop/alienbreed.10.html

https://sourcemaking.com/design_patterns/state


---
# State

![StateClass](https://sourcemaking.com/files/v2/content/patterns/State1.svg)

---

## Observer

- subjekt udržuje zoznam "divákov" (observer)
- subjekt informuje divákov o zmene stavu volaním ich metódy.
- Dôležitá časť Model-View- Controller
- pub / sub
- event driven
- observer reaguje na určitú udalosť

---
# Observer

![Observer](https://sourcemaking.com/files/v2/content/patterns/Observer.svg)

---
# Iterator

https://docs.oracle.com/javase/9/docs/api/java/util/Iterator.html

---

# Visitor

https://en.wikipedia.org/wiki/Visitor_pattern#Java_example

---
# Štrukturálne vzory

1. Adapter
1. Bridge
1. Composite
1. Decorator
1. Facade
1. Flyweight
1. Proxy

---
# Decorator

https://www.tutorialspoint.com/design_pattern/decorator_pattern.htm

- Objekt obalíme iným objektom ktorý spĺňa dané rozhranie.
- Vykoná počas behu dodatočnú funkcionalitu.
- scrollovacie lišty alebo okno dokumentu

---
# Adapter

- Pozná obidve rozhrania a mapuje jedno na druhé
- Využíva viacnásobnú dedičnosť alebo kompozíciu a dedičnosť

https://www.tutorialspoint.com/design_pattern/adapter_pattern.htm

---
# Composite

- Rozkladá objekt do stromovej štruktúry
- Reprezentuje hierarchiu objektov
- Umožňuje prístup k skupine objektov ako keby to bol jeden objekt
- Problém – uvoľnenie pamäte

https://www.tutorialspoint.com/design_pattern/composite_pattern.htm


---
# Facade
https://www.tutorialspoint.com/design_pattern/facade_pattern.htm

- Podobne ako Adapter
- Zjednocuje viac rozhraní do jedného
- Zjednodušuje prístup k viacerým rozhraniam
- Príklad – kompilátor

---
# Proxy

https://www.tutorialspoint.com/design_pattern/proxy_pattern.htm


- Poskytuje prístup k inému objektu
- Keď sa priamo nedá pristupovať k pôvodnému objektu
- Umožňuje implementovať napr. oneskorenú inicializáciu

---

# Koniec
