---
title: Spracovanie prirodzeného jazyka a jazyk Python
published: true
---

# Tímový projekt 2019

Vedúci: 

[Daniel Hládek](../) - odporúčaný čas konzultácie: štvrtok o 9:00

[Pokyny KEMT](http://kemt.fei.tuke.sk/studium/diplomova-praca/organizacne-pokyny-k-predmetu-timovy-projekt-v-st-programe-pocitacove-siete-2019-2020/)

Ciele:

- oboznámiť sa so základmi spracovania prirodzeného jazyka
- oboznámiť sa s jazykom Python
- špecifikovať zadanie diplomovej práce
- naučiť sa pracovať s [odbornou literatúrou](../zp)
- oboznámiť kolegov s obsahom vykonanej práce

Výstupy:

Rozsah výstupu min. 3 A4 kvalitného textu

- Vypracovaný tutoriál alebo rešerš vybranej metódy (8. a 13. týždeň)
- vypracovaný prehľad literatúry vybranej metódy (min. 10 odkazov)
- odovzdanie cez [MOOODLE](https://moodle.tuke.sk/moodle35/course/view.php?id=874) kľúč je  TP2019


Odporúčané nástroje:

- Prostredie [Anaconda](https://www.anaconda.com/distribution/)
- Chatbot [RASA](https://rasa.com/)
- Knižnica [Spacy](https://spacy.io/)
- Anotácie [Prodigy](https://prodi.gy/)
- Získavanie informácií [Elasticsearch](https://www.elastic.co/products/elasticsearch)
- seq2seq Neurónové siete [Fairseq](https://github.com/pytorch/fairseq)
- webové aplikácie a REST [Flask](https://www.fullstackpython.com/flask.html)

Odporúčané témy:

- [identifikácia pomenovaných entít](./named-entity) (named entity recognition)
- [dialógové systémy](./chatbot) (chatbot)
- strojový preklad (machine translation)
- oprava preklepov (spelling error correction, diacritics restoration)
- získavanie informácií (vyhľadávanie v texte)
- identifikácia viacslovných výrazov (chunking)
- anotácia textových dát

Informácie a literatúra:

- [Spacy Tutoriál](https://nlpforhackers.io/complete-guide-to-spacy/)
- [Dive into Python](https://diveintopython3.problemsolving.io/)  [(česky)](http://diveintopython3.py.cz/index.html)
- [Natural Language Processing in Action](https://www.manning.com/books/natural-language-processing-in-action) [(git)](https://github.com/totalgood/nlpia)
- [Python Data Science Handbook](https://github.com/jakevdp/PythonDataScienceHandbook)
- [Speech and Language Processing 2rd edition](https://github.com/rain1024/slp2-pdf)
- [Speech and Language Processing 3rd edition](https://web.stanford.edu/~jurafsky/slp3/)

Postup: 

- Nainštaluj si Anacondu
- Prečítaj si materiály
- Vyber si zaujímavú úlohu a nástroj
- Vyskúšaj nástroj
- Napíš správu o riešení úlohy

Tím 2019:

- Lukáš Pokrývka (flask demo, named entity)
- Dominik Nagy (spelling correction, fairseq)
- Maroš Harahus (part-of-speech tagging)
- Ján Holp (získavanie informácií)
- Dárius Lindvai (punctuation restoration, [tutorial](https://medium.com/@praneethbedapudi/deepcorrection2-automatic-punctuation-restoration-ac4a837d92d9), pytorch, LSTM tutorial)
- Jakub Maruniak (prodigy, vytvorenie korpusu, [named-entity](../prodigy),

Dátumy stretnutí:

- 10.10 - Harahus, Holp
- 14.10. - Nagy, Maruniak, Pokrývka (prečítať knihu, vybrať tému)
- 17.10 - Harahus, Lindvai (Prečítať knihu, prejsť Spacy tutoriál, nainštalovať Anaconda)
- 24.10 - Pracovná cesta
- 28.10 o 9:00, Holp, Harahus
- 31.10 - Dekanské voľno
- 4.11 - Maruniak
- 7.11 o 13:40 - Lindvai, Nagy, Pokrývka, Harahus
- 14.11 - Lindvai, Harahus, Holp 

Maroš Harahus

- Vypracovať tutoriál pre prácu s nástrojom Spacy pre úlohu zisťovania gramatických značiek (part-of-speech). Súčasťou tutoriálu by mali byť aj odkazy na relevantné zdroje (odborné članky, min. 4).
- Návrh na zadanie: Doplnenie podpory slovenského jazyka do nlp frameworku (spacy alebo flair) 

Dárius Lindvai

- Rešerš tak na 3 strany - čo najnovšie sa píše na tému "puctuation restoration"
- krátky program  a tutoriál (program s rozsiahlym komentárom ) v Pythone na využitie LSTM, napr. podobne [ako](https://pytorch.org/tutorials/beginner/nlp/sequence_models_tutorial.html).
- [zaujimavy blog](http://jalammar.github.io/illustrated-transformer/)

Ján Holp

- Vypracujte min. 4 stranový abstrakt z knihy "Hang Li: Learning to Rank for Information Retrieval and Natural Language Processing"
- citujte 10 najvýznamnejších bibliografických zdrojov

Jakub Maruniak

- Vypracujte min. 4. stranový rešerš na tému "Crowdsourcing"
- citujte min. 10 najvýznamnejších bibliografických zdrojov

Dominik Nagy:

- Vypracujte min. 4 stranový rešerš na tému: "Sequence to Sequence" (Encoder-Decoder, seq2seq, transformer, attention)
- citujte min. 10 najvýznamnejších bibliografických zdrojov

Lukáš Pokrývka:

-  min. 4 strany rešerš na tému: "Paralelné spracovanie prirodzeného jazyka" alebo "Paralelné trénovanie sémantických modelov prorodzeného jazyka" (word2vec, word embeddings, GloVe, fastText)
- citujte min. 10 najvýznamnejších bibliografických zdrojov

