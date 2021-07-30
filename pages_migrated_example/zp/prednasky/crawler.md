---
title: Programovanie komunikačných systémov 
published: true
---
## Programovanie komunikačných systémov

Ing. Daniel Hládek PhD.

---
## Výuka programovanie na KEMT

- Základy algoritmizácie a programovania (C, Staš)
- Programovanie (C, Hládek)
- Údajové štruktúry a algoritmy (C, Hládek)
- Objektovo orientované programovanie (Java, Ondáš)
- Iné predmety a záverečné práce (Matlab, C, Python)

---
# Prečo jazyk C?

- Ostatné jazyky (Python, Java) sú napísané v C
- Syntax viacerých jazykov je podobná C: (C++, Java, C#, JavaScript,...)
- Kto vie C, ľahko sa naučí iné jazyky.
- V jazyku C sa programujú mikrokontroléry a programy kde záleží na rýchlosti.

---
# Programovanie je dôležité

... aj keď nebudem programátor.

,ale budem bakalár v odbore "Informatika".

---
# Programovanie je...

- štúdium technickej dokumentácie.
- algoritmizácia problému.
- poznanie hardvéru a softvéru ktorý mám k dispozícii.
- prekonávanie a obchádzanie prekážok (mentálnych aj fyzických).
- zručnosť ktorú sa musím naučiť.

---
# Ak nebudem na vývojárskej pozícii

- môj kolega bude programovať.
- môj budúci podriadený alebo partner bude programovať.
- budem používať softvér a hardvér.
- budem si vytvárať skripty.
- budem vymýšľať a používať algoritmy.

---
## Informačné a komunikačné technológie 

sa nedajú oddeliť.

Obsahom komunikácie je informácia. 

---
## Počítačová sieť

Zariadenie na riadenie a udržiavanie toku informácií.

---
# Architektúra webových aplikácií

Ako medzi sebou komunikujú programy na internete?

---
# Webová aplikácia nie je webová stránka

- môže to byť appka
- môže bežať kdekoľvek

---
## Architektúra webovej aplikácie


```
     Frontend               Backend

   O   +--+   
  -+-/ |__|                 +------+
 / |      <- komunkácia ->  | oo = |
   ^                        +------+
  / \                       |______|
 =   =

```

---
# Front End

- to čo beží na zariadení používateľa
- HTML + Javascript

---
### Frontend Javascript

- React.js
- Vue.js
- Angular
- jQery, Bootstrap
- React Native - Natívna aplikácia pre mobilný OS napísaná v Javascripte

---
## Frontend Javascript

- `SSR`: Server-Side Rendering : HTML sa renderuje na servri
- `SPA`: single page application: HTML sa renderuje na klientovi
- `PWA`: progressive web application - Aplikácia je integrovaná s mobilným OS 

---
# Back End

- to čo beží na servri

---
## Back End Framework

- Python (Flask, Django, )
- Javascript (Node.js, Express, )
- Java (Tomcat, Spring, JBoss. )

---
# Mikroslužba

Backend sa skladá z viacerých nezávislých 
komponentov

---
### Mikroslužba

```
+--------+
| Klient |
+--------+
    ^
    |                     +----------+
 HTTP+JSON                | Databáza | 
    |              /----> |     2    |
    |              |      +----------+
    V              |
+----------+       |     
|          |       |      +----------+ 
| REST API |<--protokol-->| Databáza |
|          |   databázy   |     1    |
+----------+              +----------+

```
---
### Komunikácia s frontendom

- *synchrónna* (prebieha niekedy) :  HTTP 
- *asynchrónna* (prebieha kedykoľvek): WebSockets 

Jedna správa je asociatívne pole:

- akcia: "vyhľadaj"
- obsah_akcie: "koľko je hodín?"

---
## REST API

- Komunikácia frontendu a backendu pomocou protokolu HTTP
- Server reaguje na HTTP požiadavku a posiela HTTP odpoveď

---
## Príklad REST API (Express)

```javascript
// Knižnica
var express = require('express');
var app = express();
// Funkcia ktorá reaguje na dopyt
app.get('/', function (req, res) {
   res.send('Hello World');
})
```

[*](https://www.tutorialspoint.com/nodejs/nodejs_express_framework.htm)

---
## Príklad REST API (Flask)

```python
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'
```

[*](https://flask.palletsprojects.com/en/1.1.x/quickstart/#a-minimal-application)

---
## Protokol HTTP

Jedna správa sa skladá z dvoch častí:

HTTP Hlavička

HTTP Telo

---
## Informácie v HTTP hlavičke

- Druh správy (HTTP VERB) – GET, POST, PUT, DELETE
- Prihlasovacie údaje
- URL, parametre

---
# Obsah HTTP Tela


HTTP BODY- JSON

---
## Jedna správa HTTP

```
<initial line, different for request vs. response>
Header1: value1
Header2: value2
Header3: value3

<optional message body goes here, like file contents or query data;
 it can be many lines long, or even binary data $&*%@!^$@>
```

[*](https://jmarshall.com/easy/http/)

---
## Kódovanie obsahu správ

Serializácia

- JSON
- XML
- YAML
- Multipart
- FormData

---
## Riadkový klient HTTP

Niečo ako prehliadač - posiela dopyt a zobrazuje výsledok

```
    SLOVESO   URL
curl -XPUT 'www.example.com:9200/myIndexName?pretty'
```

---
# Príklad

Webový vyhľadávač nie je len okienko v prehliadači…..

---
### Ako funguje webový vyhľadávač?

1. Dopyt putuje na server.
2. Server sa pozrie do indexu
3. Index vráti niekoľko odkazov
4. Server prepošle výsledok prehliadaču.

---

```
+------------+
| Prehliadač |              internet
+------------+                 ^
    ^                prechádza |
    |                     +----------+
 HTTP+JSON                | Crawler  |
    |                     +----------+
    |                          ^ 
    V                 indexuje | 
+----------+                   v
|          |              +----------+ 
| REST API |<--protokol-->| Databáza |
|          |   databázy   | Index    |
+----------+              +----------+

```

---
## Vyhľadávací index

dababáza dokumentov s možnosťou vyhľadávania v texte

---
## Príklad na index

Databáza Elasticsearch 

– NosqlDatabáza
- dokumentovo orientovaná
- JSON REST API

---
## Crawler

Index je potrebné naplniť dokumentami

---
Crawler (Agent pre získavanie textu):

1. zoberie odkaz
2. Získa a spracuje HTML text
3. Získa a prefiltruje odkazy na nové stránky
4. Vloží odkazy a text do indexu

---
## Obsah webových stránok a sociálnych sietí napísal človek...

---

# Čo to ten človek napísal ???

Prichádza mágia spracovania textu

---
### Spracovanie prirodzenej komunikácie

Prináša komerčné benefity

- kvalitné vyhľadávanie
- komunikačné agenty (chatboty)
- cielenie reklamy
- dolovanie znalostí pre marketing

---
## Zarobili na spracovaní prirodzeného jazyka


```
Google
   Facebook
      Twitter
          Amazon
              Microsoft ...
```

---
## Záverečné práce Ing. Daniel Hládek PhD.

Spracovanie prirodzeného jazyka

[zp.kemt.fei.tuke.sk](https://zp.kemt.fei.tuke.sk)

---
## Naučíte sa

- programovací jazyk Python
- základy strojového učenia
- najnovšie metódy spracovania prirodzeného jazyka

---
## Zaujímavé témy

- vyhľadávanie v textových dátach z internetu
- chatbot
- strojový preklad
- trénovanie neurónových sietí

---
## Laboratórium rečových komunikačných technológií

