---
title:  QA systémy
published: true
visible: true
---
# Systémy pre generovanie odpovede na otázku v prirodzenom jazyku


Umelý agent schopný zmysluplne odpovedať na otázku položenú v ľudskom jazyku

---
Typ otázky:

- Kto, kde, ako, kedy, Čo je to

Odpoveďou by mal byť nejaký fakt.

---
Prečo o tom hovoriť?

- Používame to každý deň: vyhľadávanie Google 
- Hlasový asistent: (Google, Siri, Cortana...)
- Systémy automatickej zákazníckej podpory a chatboty

---
## Ako to celé funguje

Porozumenie otázke:

- Transformovanie otázky do podoby zrozumiteľnej pre stroj

Generovanie odpovede:
- Vyhľadanie odpovede a transformovanie do podoby zrozumiteľnej pre človeka


---
Systémy založené na symbolickej umelej inteligencii

- Preložia otázku na dopyt
- Obsahujú databázu faktov vo forme grafu  

    otec(Jan,Peter) // Ján je petrov otec
    rodic(Peter,Viera) // Peter je Vierin rodič
    stary_otec(X,Z) :- otec(X,Y), rodic(Y,Z) // Starý otec X je otec rodica Z

    // kto je Vierin starý otec?
    ? stary_otec(X,Viera)

---
Systémy založené na symbolickej umelej inteligencii

Nevýhody:  Potrebujeme veľa pravidiel, systém rozumie iba zopár otázkam

Výhody: Nepotrebujeme veľa dát, odpoveď je ľahko vysvetliteľná

---
## Systémy založené na získavaní informácií

Získavanie imformácii = vyhľadávanie v dokumentoch

Vyhľadávací korpus - obsahuje dokumenty s odpoveďami

Otázka je transformovaná na dopyt.

Dopyt sa skladá z termov a logických operátorov. 

Term = kľúčové slovíčko

--- 
DrQA

- Vie zopovedať faktické otázky na ktoré existuje odpoveď na Wikipédii
- Vyhľadávač vo Wikipédii ktorý vie porozumieť prirodzenémy jazyku
- Chceme aby tento vyhľadávač hovoril po slovensky a vyhľadával vo Wikipédii


Document Retriever && Document Reader

---
## Document Retriever

- bigram hashing & TF IDF


Premení otázku na vyhľadávacie "termy".
Vráti 5 najviac relevantných dokumentov.
Dokumety sa skladajú z odsekov.

---
## Document Reader
  
- deep neural network

Vstup je odsek a otázka.

Zakódujeme odsek a otázku do podoby ktorej rozumie neurónová sieť
Neurónová sieť vráti časť odseku kde sa nachádza odpoveď spolu s pravdepodobnosťou.

---
## Ako naučíme takýto systém hovoriť po slovensky?

- Spracujeme slovenskú wikipédiu (done)
- Vytvoríme trénovaciu databázu (in progress)
- Vyskúšame a odladíme (to be done)
- Vytvoríme demo (to be done)

---
## Ako môžete pomôcť?

- Anotujte otázky a odpovede - vylešíte dátovú množinu.
- Pomôžte pri trénovaní neurónových sietí. - vyskúšate ako funguje neurónová sieť
- Pomôžete pri demonštrácii - vytvoríte webové demo.

---
## Zdroje 

- [Wikipedia](https://en.wikipedia.org/wiki/Question_answering)
- [DrQA](https://github.com/facebookresearch/DrQA#machine-reading-at-scale)
