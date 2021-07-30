---
visible: true
published: true
author: Maroš Harahus
title: Morfologická analýza pomocou knižnice Spacy
date: 2020
---

Tímový projekt 2020, Maroš Harahus

## Spracovanie prirodzeného jazyka

Je založené na umelej inteligencii, ktorá sa zaoberá interakciami medzi počítačom a jazykmi. NLP uľahčuje proces analýzy a
porozumenia ľudského jazyka pre počítače a umelú inteligenciu. Pomáha extrahovať informácie z textu. V dnešnej dobe sa textové údaje vytvárajú vo veľkom množstve a je ich dôležité spravovať a odovzdať informácie z neštruktúrovaných údajov. Preto musíme údaje reprezentovať vo formáte v ktorom počítače rozumejú a v tomto prípade nám pomáha NLP. Má niekoľko prípadov použitia:


* Automatické zhrnutie
* Uznanie pomenovaného subjektu
* Systémy odpovedania na otázky
* Analýza sentimentu 

# SPACY


 Je bezplatná knižnica pre NLP v programovacom jazyku python. Táto knižnica je napísala v Cythone a je určená pre budovanie extrakcie informácii alebo pochopenie prirodzeného jazyka. Je navrhnutý pre použitie v pythone a ponuka priateľské rozhranie API. 

## Detekcia viet

Detekcia viet je proces lokalizácie začiatku a konca vety v danom texte. Tato detekcia nám umožňuje rozdeliť vetu resp. text na jazykovo významne jednotky. Tieto jednotky potom môžem využívať pri spracovaní text na vykonávanie úloh ako napríklad označovanie reči. 

## Part-of-speech (Part of Speech)


Značkovanie pomocou Part of Speech je proces označovania slova pomocou príslušnej časti reči, ako je podstatné meno, prídavné meno, sloveso, príslovka atď. Podľa gramatických pravidiel jazyka, ktoré sa ďalej konštruujú na základe kontextu výskytu slova a jeho vzťahy s inými slovami vo vete. Po tokenizácii môže spacy daný objekt označiť pomocou svojich najmodernejších štatistických modelov. Značky sú k dispozícii ako atribút objektu Token. 


## Tokenizácia


Tokenizácia sa voľne označuje ako segmentácia textového dokumentu na slová, ktoré sa tiež nazývajú tokeny. Token je definovaný ako postupnosť znakov, ktoré spolu tvoria sémantickú jednotku pri spracovaní textu. V niektorých kontextoch nemusia byť tokeny slovami a môžu pozostávať zo slov alebo dokonca viacslovných fráz v závislosti od toho, čo sa považuje za sémantickú jednotku. Spacy tonizuje daný text na slová a interpunkcie použitím pravidiel, ktoré sú vyladené pre konkrétny jazyk. Najnákladnejšie pravidlo pre anglický jazyk je rozdelenie postupnosti znakov v texte na medzery (napr. Medzeru), často známe ako točenie medzier. 
* **text_with_ws** tlačí tokenový text s medzerou (ak je k dispozícii),
* **is_alpha** zistí, či token pozostáva z abecedných znakov alebo nie,
* **is_punct** zistí, či je token interpunkčný symbol alebo nie,
* **is_space** zistí, či je token medzerou alebo nie,
* **shape_** vytlačí tvar slova,
* **is_stop** zistí, či je token zastavovacím slovom alebo nie,

| Skratka | Anglicky vyznam           | Slovensky vyznam   |
|:-------:|:-------------------------:|:------------------:|
| ADJ     | adjective                 | prídavné meno      |
| ADP     | adposition                | umiestnenie        |
| ADV     | adverb                    | príslovka          |
| AUX     | auxiliary verb            | pomocné sloveso    |
| CONJ    | coordinating conjunction  | koordinačná spojka |
| DET     | determiner                | determinant        |
| INTJ    | interjection              | prerušenie         |
| NOUN    | noun                      | podstatné meno     |
| NUM     | numeral                   | číslice            |
| PART    | particle                  | častica            |
| PRON    | pronoun                   | zámeno             |
| PROPN   | proper noun               | vlastné meno       |
| PUNCT   | punctuation               | interpunkcia       |
| SCONJ   | subordinating conjunction | podriadená spojka  |
| SYM     | symbol                    | symbol             |
| VERB    | verb                      | sloveso            |
| X       | other                     | iné                |



# Inštalácia spacy

```python
pip install -U spaCy //instalacia spacy
python -m spacy download en //instalacia anglickeho jazyka
```
#### prvý kód
```python
import spacy
nlp = spacy.load('en')
doc = nlp('Hello     World!')
for token in doc:
    print('"' + token.text + '"', token.idx)
#Vystup
# "Hello" 0
# "    " 6
# "World" 10
# "!" 15
```
Ako prvé si importujeme spacy knižnicu. Zadáme vetu, ktorú chceme prejsť tokenizáciu. V tomto pípade používame iba dva tokeny. Prvý nám vypíše text a medzeri, druhý token nám napíše, na ktorom mieste sa nachádza naše slovo.
```python
doc = nlp("Next week I'll   be in Madrid.")
for token in doc:
    print("{0}\t{1}\t{2}\t{3}\t{4}\t{5}\t{6}\t{7}".format(
        token.text,
        token.idx,
        token.lemma_,
        token.is_punct,
        token.is_space,
        token.shape_,
        token.pos_,
        token.tag_
    ))

#vystup
# Next  0   next    False   False   Xxxx    ADJ JJ
# week  5   week    False   False   xxxx    NOUN    NN
# I 10  -PRON-  False   False   X   PRON    PRP
# 'll   11  will    False   False   'xx VERB    MD
#       15      False   True        SPACE   _SP
# be    17  be  False   False   xx  VERB    VB
# in    20  in  False   False   xx  ADP IN
# Madrid    23  madrid  False   False   Xxxxx   PROPN   NNP
# . 29  .   True    False   .   PUNCT  
```
* **token.text** reprezentácia textu dokumentu v Unicode,
* **token.idx**  znakový index začiatku,
* **token.lemma_** základná podoba tokenu bez inflexných prípon,
* **token.is_punct** je to interpunkcia znamienka,
* **token.is_space** pozostáva token z bielych znakov,
* **token.shape_** transformácia reťazca tokenov na zobrazenie ortografických prvkov, 
 napríklad „Xxxx“ alebo „dd“
* **token.pos_** hrubozrnná časť reči,
* **token.tag_** jemnozrnná reč.
    
Poďme si rozobrať výstup prvého slova Next. Ako prvé sa nám vypíše samotné slovo, ďalej nasleduje, na ktorom indexe slovo začína. V našom prípade je to index 0. V ďalšom stĺpci máme slovo napísané pomocou malých písmen. Ďalšie dva stĺpce nám zisťujú, či dané slovo obsahuje interpunkčné znamienko (napr. apostrof) a či slovo nepozostáva z medzery. Predposledný stĺpec nám zisťuje, aký slovný druh (viď. tabuľku nižšie) je dané slovo v našom prípade je to podstatné meno atd.

#### Detekcia vety

```python
doc = nlp("These are apples. These are oranges.")
 
for sent in doc.sents:
    print(sent)
 
# These are apples.
# These are oranges.
```
#### Pomenovanie entit

```python
import spacy

nlp = spacy.load("en_core_web_sm")
doc = nlp("Apple is looking at buying U.K. startup for $1 billion")

for ent in doc.ents:
    print(ent.text, ent.start_char, ent.end_char, ent.label_)
 
#Apple 0 5 ORG
#U.K. 27 31 GPE
#$1 billion 44 54 MONEY
```
Na tomto príklade môžme pozorovať, že spacy dokáže rozlíšiť slova. Dokáže zistiť či dané slovo je napr. mesto(GPE-Geopolitical entity) alebo nejaká organizácia (ORG- Companies). Ďalej vie určiť či sa jedná o dátum, sumu peňazí, osobu atď. .





