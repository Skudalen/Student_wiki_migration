---
title:NLP
---
# NLP

Spracovanie prirodzeného jazyka

---
# NLP

- Aplikácie údajových štruktúr a algoritmov
- Heuristické spracovanie

---
## Dáta sú nové zlato

Google,, Facebook ... majú najviac dát a vedia dáta premeniť na peniaze.

---
## Ako dáta premeniť na peniaze?

Vytiahnuť z nich užitočné informácie  (zvané ZNALOSTI).

- Kto si chce kúpiť moju značku parfému?
- Aké videá mám najradšej?

---
## Znalosť je užitočná  informácia 

- podporí biznis.
- pomôže pri riešení problému.
- pomôže pri každodennom živote.

---
## Znalosti sa dajú premeniť na peniaze

Vložíme dáta do systému a naučíme ho robiť niečo užitočné:

- vyhľadávať v databáze
- odpovedať na otázky
- rozpoznávať obrázky alebo prepisovať reč

---
## Ako dáta premeniť na znalosti?

Dáta sú slabo štruktúrované - potrebujeme metódy umelej inteligencie.

Dát môže byť veľa - potrebujeme metódy spracovania veľkých dát.

---
## Slabo štruktúrované dáta - opak programovacieho jazyka

- Text napísaný v ľudskom (prirodzenom) jazyku
- Obrázok  alebo fotografia

---
## Ako dáta premeniť na znalosti?

Získať znalosti vo forme modelu (neurónovej siete).

Model vie  zovšeobecniť naučené príklady a odpovedať aj na otázky ktoré nevidel.

---
## Strojové učenie

Najčastejšie používané neurónové siete

Najčastejšie používané klasické metódy.

---
## Trénovanie neurónových sietí 

- Model
- Trénovacia databáza
- Vyhodnotenie

---
# Question Answering

Stroj odpovedá na faktické otázky, na1998pr.

- Kto bol prezidentom SR v roku 2003?
- Kedy sa narodil Ľudovít Štúr?
- Ako sa volá hlavné mesto Angoly?

---
# Vedel by sa stroj zúčastniť televízneho kvízu?

Ako "naučiť" taký systém?

---
## Systémy QA založené na znalostiach

- Disponujeme databázou faktov vo forme predikátov:
  - prezident(SR,MichalKovac,1993-1998)
  - narodilsa(MIchalKovac,3.8.1930)
- Fakty sa dajú usporiať do grafu.
- Otázka sa transformuje na predikát:
  - prezident(SR,?,2003)
- Odpoveďou je fakt z databázy faktov 

---
# Systémy QA založené na dokumentoch

- Disponujeme databázou dokumentov 
- Odpoveďou je časť dokumentu z databázy dokumentov.
  - Musíme vyhľadať dokument
  - Musíme vyhľadať relevantnú časť dokumentu
---
## Komerčné QA systémy sú hybridné

- Vedia využívať znalosti aj dokumenty.

---
## Ako funguje QA založené na dokumentoch?

- predspracovanie otázky
- vyhľadanie v dokumentoch
- zodpovedanie = vyhľadanie relevantnej časti dokumentu

---
## Predspracovanie otázky

- Premena otázky v prirodzenom jazyku na dotaz
    - V ktorom dokumente sa bude odpoveď nachádzať?
- Zistenie typu otázky:
    - Aký druh entity chceme zistiť? (osoba, rok, číslo, miesto...)

---
## Vyhľadanie dokumentu

Information retrieval

Máme množinu dokumentov a index kľúčových slov.

Hľadáme dokumenty ktoré sú najviac relevantné k položenej otázke (kľúčovým slovám).

---
## Zodpovedanie otázky

Máme dokument a k nemu otázku.

Vyznačenie  časti v dokumente, ktorá je odpoveďou na otázku.

---
## Zodpovedanie otázky pomocou neurónovej siete

(Chen 2017)

Predspracovanie: Otázka -> Príznaky -> sémantický vektor (word-embedding)

Klasifikácia: 

- vektor  + dokument -> začiatok oblasti v dokumente
- vektor  + dokument -> koniec oblasti v dokumente


---
## Príklady v anglickom jazyku

- https://www.wolframalpha.com/
- Watson DeepQA od IBM
- https://google.com a iné

---
## Existujúce trénovacie databázy

Squad

---
# Literatúra

Jurafsky and Martin: Speech and Language Processing, 2nd Edition.,

Jurafsky and Martin: Speech and Language Processing, 3rd Edition.
