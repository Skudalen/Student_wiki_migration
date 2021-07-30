---
published: true
title: Úvod do spracovania prirodzeného jazyka
---
# Spracovanie prirodzeného jazyka

Ing. Daniel Hládek PhD.

daniel.hladek@tuke.sk

---
Rastie potreba spracovávať veľké množstvo človekom vytvoreného textu alebo hovorenej reči

---
Čo je spracovanie prirodzeného jazyka
Natural Language Processing (NLP)

---
Kombinácia viacerých techník z oblasti:

- Teórie formálnych jazykov
- Štatistiky
- Strojového učenia
- Lingvistiky
- Psychológie

---

Spracovanie prirodzeného jazyka získavaním znalostí pomáha pri bežných činnostiach.

---

dáta => informácie => znalosti

text => príznaky => zistenia

---

## Znalosť je užitočná informácia

(dá sa premeniť na peniaze).

---
Typické úlohy NLP

---
Motivačný príklad: Alexa, WolframAlpha, Siri

Počítač "porozumie" ľudskej komunikácii

---
Každý Váš deň:

Google, Facebook, Apple

---
Porozumenie otázke : Google, počítačové hry, WolframAlpha (Siri)
Fulltextové vyhľadávanie: Google
Cielenie reklamy: AdSense, eTarget

---
Ohodnotenie sentimentu a detekcia nevhodných alebo podozrivých príspevkov: Facebook , LinkedIn

Strojový preklad: Googe Translate
Detekcia spamu: Spam Assasin, Gmail

---
Získavanie informácií (Information Retrieval)

Vyhľadávanie na webe napr. Vyhľadanie stránok súvisiacich s “natural language processing”

Monitoring médií
Čo všetko sa napíše alebo odvysiela v televízii alebo v rádiu o mojej spoločnosti?

---

Cielenie reklamy

Analýza sentimentu na sociálnych sieťach

Dolovanie v dátach a získavanie znalostí
Aká je priemerná cena hamburgeru v Južnej Amerike?

---
Prepis textu (Machine Translation):

Strojový preklad. Napr. Ako sa povie “Dnes je pekný deň” po japonsky?

Parafrázovač. Napr. Akým iným spôsobom sa dá povedať “Mám rád bryndzové halušky”

Porozumenie jazyku (Natural Language Understanding)

---

Chatboty, Umelý psychiater.

“Umelá inteligencia” - počítač na lodi Enterpise, ktorý rozumie slovným príkazom kapitána a vie mu odpovedať na jeho požiadavky
Morfologická analýza (hľadanie gramatickej a sémantickej funkcie slova)


---
Prirodzený jazyk je veľmi neurčitý (ambiguity)

---

- To isté vieme povedať rôznymi spôsobmi
- Jedna výpoveď môže mať veľa rôznych významov
- Často pri komunikácii prenášame aj neverbálnu informáciu:
    - Pocity
    - Gestá
    - Prízvuk a štýl reči

---
Homonymá:

	Práve sedím v škole. Nevyznám sa v občianskom práve.
	To auto stojí 10000 eúr. Auto stojí na kraji cesty.

---
Synonymá:

	Išiel som do Bratislavy. Išiel som do Blavy.

---
Neurčité poradie slov vo vete:

	Dnes je pekný deň. Pekný deň je dnes. Deň je dnes pekný.

---
Neurčitý význam slov:

	„Po tráve sa nechodí, po tráve sa smeje”

---
Novotvary a slangové výrazy:

Vygoogli si to a potom to postni na fb.

---
Emócie a spoločenské konvencie:

	Pane! Pekne ste sa doriadil!

---
Preklepy a brepty:

	Viď prednašku.

---

Počítačový jazyk je jednoznačný
Potrebujeme metódy pre prácu s neurčitosťou

---
Práca s neurčitosťou v NLP

- Klasifikácia kontextov alebo ich postupností
- Prepisovanie postupnosti symbolov

---
Klasifikácia kontextov

Mapovanie:

	c => S

- C: kontext: Veta,Dokument
- S: symbol: Morfologická značka, léma, vetný člen...


---
Využitie

- detekcia sentimentu
- detekcia spamu
- identifikácia pomenovaných entít

---
Pri klasifikácii nám pomáha, ak vieme ktorá časť kontextu je dôležitá pre klasifikáciu.

- Slovo
- Koncovka, Koreň slova
- Predchádzajúce slovo, Nasledujúce slovo
- Typ prvého písmena

---
## Príznaková funkcia

Taká binárna funkcia kontextu, ktorá je pravdivá iba v prípade výskytu daného príznaku v kontexte.
Vhodná sada príznakových funkcií nám pomáha riešiť problém.

---
## Príznaková funkcia

Mapovanie

	Symbol => jednotkový vektor

	dnes =>  0000100001


---
## Klasifikátor kontextov

Extrakcia príznakov, klasifikácia

	symbol=> príznakový vektor => trieda

---
## Klasifikátor kontextov

- Ľudskú znalosť vo forme pravidiel
- Štatistické informácie z trénovacích korpusov
- Kombináciu oboch prístupov

---
## Pravidlá

- Slovníky
- Formálna gramatika
- Regulárne výrazy

---
## Štatistické prístupy

- HMM
- N-gram model
- Umelá neurónová sieť

---
## Hlboké neurónové siete

- LSTM, Konvolučné siete, Transformery

Výpočtovo náročné

---
## Prepisovanie postupnosti symbolov

Mapovanie:

	postupnosť => iná postupnosť

---
## Prepisovanie postupnosti symbolov

- strojový preklad
- korekcia preklepov a gramatiky
- dialógové systémy

---
## Enkóder-Dekóder

Enkóder:

    symboly => príznaky => významový vektor

Dekóder:
    
    model a významový vektor => výstupné symboly

---
## Enkóder Dekóder

Hlboké neurónové siete

---

# Aj vy môžte robiť NLP

---

## Všeobecný programovací jazyk

Python

---

## Všeobecné knižnice pre strojové učenie

- keras 
- pytorch

---

## Všeobecné knižnice pre NLP

- Spacy
- Flair

---
## Strojový preklad

- fairseq

---
## Extrakcia sémantických príznakov

- glove
- fasttext
- word2vec

---
## Získavanie informácií a spracovanie logov

Elasticsearch

---
## Dialógové systémy a porozumenie jazyku

RASA

---
## Bibliografia

Jurafsky, Martin: Natural Language Processing
Christopher Manning: Natural Language Processing, Stanford University Online Video Lectures


