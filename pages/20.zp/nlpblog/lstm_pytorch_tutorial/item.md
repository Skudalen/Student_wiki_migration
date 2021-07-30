---
title: Pytorch - LSTM tutoriál
published: true
visible: true
taxonomy:
    category: [tp2020]
    tag: [python,lstm,nn,nlp,pytorch,anaconda]
    author: Dárius Lindvai
---

Tímový projekt 2020, Dárius Lindvai


### Čo je to Pytorch?

[Pytorch](https://pytorch.org/) je open-source knižnica založená na knižnici Torch a určená primárne na účely strojového učenia (*machine learning*) a hĺbkového učenia (*deep learning*). Táto knižnica sa najčastejšie používa v kombinácii s jazykom **Python**, avšak je možné ju použiť aj s jazykom C++. Jej najväčšie využitie je v oblasti Spracovania prirodzeného jazyka (NLP). Je vyvíjaná hlavne výskumným tímom Facebooku pre umelú inteligenciu (FAIR = Facebook's AI Research lab).

Vlastnosti Pytorchu:
- je jednoduchý na naučenie a používanie,
- obsahuje rozsiahlu dokumentáciu a rôzne tutoriály, ktoré môžu začiatočníci vhodne využiť pri učení,
- poskytuje možnosť rýchleho počítania tzv. **tensorov** (forma výstupu v knižnici Pytorch podobná matici) použitím GPU.

### Čo je to LSTM?

Problematikou LSTM (Long Short-Term Memory networks) som sa zaoberal v mojej [Bakalárskej práci](http://opac.crzp.sk/?fn=detailBiblioForm&sid=2D0B46080A5AC858AA11B21AE978&seo=CRZP-detail-kniha). LSTM sú špeciálny typ **Rekurentných neurónových sietí** (RNN), schopné naučiť sa využívať dlhodobé kontextové súvislosti (napr. pri dopĺňaní chýbajúcej interpunkcie alebo veľkých písmen). Najväčšie využitie LSTM je v oblasti strojového učenia a hĺbkového učenia.

Vlastnosti LSTM:
- dokážu spracovávať nielen jednoduché dáta (napr. obrázky), ale aj celé sekvencie dát (napr. reč alebo video),
- sú vhodné na klasifikáciu, spracovanie a vytváranie predikcií na základe časových údajov (v Bakalárskej práci som sa venoval **Interpunkčným znamienkam**),
- LSTM boli navrhnuté tak, aby si na rozdiel od RNN vedeli poradiť s problémom, ktorý sa nazýva “[Exploding and vanishing gradient problems](https://medium.com/learn-love-ai/the-curious-case-of-the-vanishing-exploding-gradient-bf58ec6822eb)”.

|![LSTM](https://i1.wp.com/www.jessicayung.com/wp-content/uploads/2018/09/short_term_memory_by_toxicpaprika.png?w=630)|
|:--:|
|*Obr.1 Problém "krátkej" pamäte RNN*|

Tento tutoriál sa delí na 2. časti. V prvej časti ukážem návod ako si nainštalovať Pytorch a v druhej predvediem vzorový kód pomocou knižnice Pytorch na vyžitie LSTM.

## 1. Inštalácia knižnice Pytorch
Na inštaláciu Pytorchu existuje viacero možných spôsobov. Pracovať s ním je možné či už vo Windowse alebo aj v Linuxovom prostredí. Taktiež je možné vybrať si, či bude inštalácia vykonaná pomocou **Anacondy** alebo PIP. Ja som sa rozhodol pracovať v prostredí  Ubuntu (keďže v tomto prostredí som pracoval aj na Bakalárskej práci. Preto teraz predstavím spôsob ako nainštalovať Pytorch v tomto prostredí pomocou Anacondy.

Pred inštaláciou Anacondy a Pytorchu je potrebné nainštalovať prostredie **Ubuntu 16.04 LTS**. Môžete si ho stiahnuť napr. z Microsoft Store.

###  a. Inštalácia Anacondy
Pred samotnou inštaláciou Anacondy je potrebné overiť, či sú všetky balíčky (*packages*) aktualizované. Je to možné vykonať pomocou príkazu `apt-get`:
```bash
dl874wn@Darius-PC:~$ apt-get update -y
```
Následne je treba stiahnuť inštalačný súbor Anacondy. Jedným zo spôsobov ako to urobiť, je stiahnutie tohto súboru priamo cez terminál. Avšak pri tomto spôsobe je potrebné uistiť sa o bezpečnosti stránky, ktorá poskytuje inštalačný skript. Na stiahnutie súboru pomocou terminálu je možné použiť príkaz `curl`:
```bash
dl874wn@Darius-PC:~$ curl -O https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh
```
Zadanie tohto príkazu vám zabezpečí stiahnutie najnovšej verzie Anacondy. Po stiahnutí súboru je možné spustiť inštalačný skript použitím príkazu `bash`:
```bash
dl874wn@Darius-PC:~$ bash Miniconda3-latest-Linux-x86_64.sh
```
Vrámci inštalácie Anacondy sa nainštaluje aj Python 3.7.4. Počas inštalácie je potrebné potvrdiť licenčné podmienky a umiestnenie, kam sa Python nainštaluje.

Po stiahnutí a nainštalovaní Anacondy ju už stačí iba spustiť. Pre spustenie bude stačiť refresh terminálu, čo je možné vykonať príkazom `source`:
```bash
dl874wn@Darius-PC:~$ source ~/.bashrc
```

### b. Inštalácia Pytorchu
Ďalším krokom je nainštalovanie Pytorchu. Inštalácia je veľmi jednoduchá a rýchla. Stačí zadať jednoduchý príkaz:
```bash
dl874wn@Darius-PC:~$ conda install pytorch torchvision cpuonly -c pytorch
```
Taktiež je potrebné zadať “**y**” po výzve terminálu. Po nainštalovaní bude treba odpovedať „**yes**“ na otázku, či chceme, aby bola Anaconda hneď incializovaná.

Na záver je ešte potrebné overiť, že Pytorch bol skutočne nainštalovaný. Toto overenie je možné vykonať sériou príkazov. Na začiatok je potrebné dostať sa do módu “Python REPL (a read-eval-print loop)”, čo je možné vykonať veľmi jednoducho - zadaním príkazu `python3` do terminálu:
```bash
(base) dl874wn@Darius-PC:~$ python3
Python 3.7.4 (default, Aug 13 2019, 20:35:49)
[GCC 7.3.0] :: Anaconda, Inc. on linux
Type “help”, “copyright”, “credits” or “license” for more information.
>>>
```
> Python REPL je jednoduché interaktívne prostredie, ktoré spracováva jednoduché užívateľské vstupy po jednom riadku a vracia výsledok (výstup). Užívateľ teda zadáva príkazy po jednom a program ich spracováva a vyhodnocuje postupne.

Keď sa už nachádzame v móde Python REPL, môžeme spustiť napr. tento jednoduchý skript, ktorý vygeneruje maticu 3x5 náhodných čísel (tensor) v intervale (0,1). Prvé číslo v zátvorke udáva počet riadkov a druhé počet stĺpcov.
```bash
>>> import torch
>>> x = torch.rand(3,5)
>>> print(x)
```
Výstup skriptu by mal vyzerať nasledovne:
```bash
tensor([[0.8490, 0.5107, 0.2124, 0.8478, 0.6296],
        [0.9270, 0.8925, 0.0260, 0.3883, 0.4998],
        [0.7393, 0.9261, 0.7133, 0.6712, 0.4431]])
>>>
```
Týmto skriptom sme overili funkčnosť Pytorchu a teda môžeme Python REPL opustiť stlačením klávesovej skratky **CTRL + D**. V prípade potreby môžete Anacondu deaktivovať príkazom `conda deactivate`, avšak ak budete chcieť znova pracovať s Pytorchom, je potrebné ju znova aktivovať.
```bash
(base) dl874wn@Darius-PC:~$ conda deactivate
dl874wn@Darius-PC:~$ 
```
##  2. Vzorový kód na využitie LSTM v Pytorchu

Vstup a výstup v LSTM v knižnici Pytorch je tvorený 3D tensormi. V tomto tutoriáli predvediem, ako tento vstup a výstup funguje.

Na začiatok je potrebné importovať pár relevantných knižníc.
Budeme pridávať základnú knižnicu **torch** a knižnicu **nn**, ktorá obsahuje základný balík Neurónových sietí (NN).
```python
import torch
import torch.nn as nn
```
Následne sa presunieme k vytváraniu LSTM vrstvy, ktoré funguje rovnako ako pri ostatných typoch vrstiev. LSTM vrste totiž budeme priradzovať argumenty. V tomto príklade budú použité 3 argumenty:
- vstupná dimenzia (*input dimension*): definuje veľkosť vstupu v každom časovom kroku, napr. ak má vstupná dimenzia veľkosť 5, vstup bude vyzerať podobne - `[5, 3, 8, 6, 2]`,
- skrytá dimenzia (*hidden dimension*): predstavuje veľkosť "cell state" a "hidden state" v každom časovom kroku,
- počet vrstiev: počet LSTM vrstiev "naskladaných" na seba.

```python
input_dim = 5 #velkost vstupnej dimenzie
hidden_dim = 10 #velkosť skrytej dimenzie
n_layers = 1 #pocet vrstiev
```

Tieto parametre potom uložíme do LSTM vrstvy nasledovne:

```python
lstm_layer = nn.LSTM(input_dim, hidden_dim, n_layers)
```

V ďalšom kroku si vytvoríme fiktívne dáta aby sme videli, ako funguje vstup na vrstve. Keďže sme veľkosť dimenzie definovali ako 5, potrebujeme vytvoriť tensor vo tvare `(1, 1, 5)`. Hodnoty v tensore reprezentujú `(veľkosť vzorky, dĺžka sekvencie, veľkosť vstupnej dimenzie)`.
Taktiež potrebujeme inicializovať "cell state" a "hidden state" jednotky LSTM. Tieto 2 parametre sú uložené vo "zväzku" vo formáte `(hidden state, cell state)`.

```python
batch_size = 1 #velkost vzorky
seq_len = 1 #dlzka sekvencie

inp = torch.randn(seq_len, batch_size, input_dim)
hidden_state = torch.randn(n_layers, batch_size, hidden_dim)
cell_state = torch.randn(n_layers, batch_size, hidden_dim)
hidden = (hidden_state, cell_state)
```

> Ak máme vstupnú sekvenciu (*seq_len*) napr. 100, veľkosť vzorky (*batch_size*) udáva, v akých dávkach sa bude sekvencia spracovaná a vyhodnotená. Ak máme napr. veľkosť vzorky 20, sekvencia bude spracovaná v 5 dávkach po 20.

Ak si chceme skontrolovať v akom tvare bude vyzerať tvar vstupnej vrstvy a skrytej vrstvy, môžeme to urobiť pomocou príkazov `print` a `shape`:

```python
print("Input shape:", inp.shape)
print("Hidden shape:", hidden_state.shape, ",", cell_state.shape)
```

Výstup bude vyzerať nasledovne:

```bash
(base) dl874wn@Darius-PC:~$ python test.py
Input shape: torch.Size([1, 1, 5])
Hidden shape: torch.Size([1, 1, 10]) , torch.Size([1, 1, 10])
```

Na záver pridáme vstupy a skryté stavy (*hidden states*):

```python
out, hidden = lstm_layer(inp, hidden)
print("Output shape:", out.shape)
print("Hidden:", hidden)
```

Na výstupe by sa mal objaviť tvar výstupných tensorov a taktiež samotné tensory pre "cell state" a "hidden state":

```bash
Output shape: torch.Size([1, 1, 10])
Hidden: (tensor([[[-0.3184, 0.0795, -0.2122, -0.0699, -0.1824, -0.1231, -0.1314, 0.3096, -0.0371, 0.0488]]], grad_fn=<StackBackward>), tensor([[[-0.5415, 0.2349, -0.4794, -0.1918, -0.2433, -0.2443, -0.2989, 0.5557, -0.0896, 0.1062]]], grad_fn=<StackBackward>))
```

