# Linux pre vývojárov

## Príkazový riadok

Naučíte sa:

- Získať nápovedu
- Pracovať s históriou
- Rozdiel medzi súborom a adresárom
- Vytvárať súbory a adresáre
- Pohybovať sa po adresárovej štruktúre
- Vyhľadávať v súboroch a adresároch
- Pracovať s textovým vstupom a výstupom

### Kruh života v príkazovom riadku


Príkazový riadok je špeciálny program (shell), ktorý pracuje interaktívne v cykle:

- Načítaj príkaz;
- Vykonaj príkaz;
- Vypíš výsledok;
- Pokračuj.


```
      +--------+      +---------+
      | Napiš  +----->| Vykonaj |
      | príkaz |      | príkaz  |
      +--------+      +---------+
         ^                  |
         |                  |
         |   +---------+    |
         +---| Vypíš   |<---+
             | výsledok|
             +---------+
```


### Prvé kroky

Po prihlásení sa Vám zobrazí výzva na zadanie príkazu. Výzva obsahuje informáciu o aktuálne prihlásenom používateľovi (`dh343ko`), mene stroja na ktorý sme prihlásení (`omega`) a aktuálnom adresári (`~`). Znak `~` (tilda) je symbolické meno pre domovský adresár v ktorom sa aktuálne nachádzame.

```bash
dh343ko@omega:~$
```

Čierna obrazovka na prvý pohľad pôsobí odstrašujúco. Myš, ktorá je vedľa klávesnice je zrazu zbytočná (môžeme ju odložiť za monitor).
Po krátkom cviku sa v príkazovom riadku pracuje pohodlnejšie a rýchlejšie ako s graficky s myšou.

Príkaz

```
dh343ko@omega:~$ ls
```

napíše zoznam súborov v aktuálnom adresári. Výsledkom ale budete asi sklamaní, zatiaľ žiadne súbory ani adresáre nemáme.
V príkazovom riadku platí pravidlo: "Žiadna správa je dobrá správa", takže nemusíme byť nespokojní. Ak by niečo nebolo v poriadku,
systém by nás na to upozornil chybovým hlásením. Ak by sme napríklad napísať nejaký príkaz, ktorý neexistuje, dostali by sme:

```
dh343ko@omega:~$ ahoj
-sh: ahoj: command not found
```

Skúsime to napraviť a vytvoríme si prázdny súbor:

```bash
dh343ko@omega:~$ touch Matematika
```

Príkaz na výpis súborov môžeme zopakovať a výsledok bude o niečo lepší:

```bash
dh343ko@omega:~$ ls
Matematika
```

### Adresáre

Okrem súborov si vieme vytvárať aj adresáre. Adresár slúži na uchovávanie súborov alebo iných adresárov. Pomocou adresárov si vieme ľahšie organizovať našu prácu tak, aby veci ktoré spolu súvisia boli blízko seba. Príkaz na vytvorenie adresára:

```bash
dh343ko@omega:~$ mkdir matematika
```

Pozorný čitateľ si všimne, že by sme mali mať spolu dve matematiky, jedna s malým a druhá s veľkým písmenom. Operačný systém Linux rozlišuje
malé a veľké písmená. Skúsime sa o tom presvedčiť pomocou príkazu `ls`. Výpis môžeme obohatiť o ďalšie informácie pomocou prepínača `-l`.

NOTE: Každý príkaz môže mať zoznam argumentov oddelených medzerou.

```bash
dh343ko@omega:~$ ls -l
drwxr-xr-x 2 dh343ko tuke 4096 Feb  7 12:37 matematika
-rw-r--r-- 1 dh343ko tuke    0 Feb  7 12:37 Matematika
```

Výpis súborov a adresárov vyzerá o niečo veselšie.  Prvou informáciou, je zoznam príznakov, ktoré k súboru patria.
Príznaky súboru na prvom mieste vyjadrujú, či je súbor adresárom (`d`) alebo klasickým súbor (`-`), Zaujíma nás aj ďalšia trojica príznakov (`rwx` alebo `-rw`). Príznak `r` znamená, že máme právo na čítanie súboru alebo obsahu adresára, `w` je právo na zápis do súboru alebo vytváranie nových súborov v adresári a `x` je právo na vykonávanie alebo zmenu adresára na aktuálny.

### Pohyb po adresároch

Adresáre v Unixe sú radené do stromu. Koreň stromu sa nazýva hlavný adresár a je označený `/`. Všetky ostatné súbory a adresáre sa nachádzajú na nižšej úrovni. Overiť si to môžeme pomocou príkazu `pwd` (print working directory) na výpis aktuálneho adresára:

```bash
pwd
```

Aktuálny adresár si môžeme zmeniť pomocou príkazu `cd`:

```bash
dh343ko@omega:~$ cd matematika
dh343ko@omega:~/matematika $ ls
Matematika
dh343ko@omega:~$ pwd
/home/tuke.sk/dh/343/dh343ko/matematika
```

### Špeciálne adresáre

V OS Linux sa adresár počíta ako súbor (nie je teda možné mať súbor a adresár s rovnakým názvom). Niektoré adresáre majú špeciálny význam, ako napr. hlavný adresár, domovský adresár, aktuálny adresár alebo adresár o úroveň vyššie.  Tieto adresáre sa 
často používajú a preto existujú skratky (špeciálne názvy) pre ľahkú prácu.

Aktuálny adresár zapíšeme pomocou  `.` , adresár o úroveň vyššie je  `..`.
Domovský adresár je `~`, hlavný adresár `/`.

Príkaz na presun o úroveň vyššie bude:

```bash
cd ..
```

V našich adresároch sa vieme aj poprechádzať. Po každom kroku si môžme overiť kde sa skutočne nachádzame pomocou `pwd`.

```bash
dh343ko@omega:~$ cd matematika
dh343ko@omega:~$ pwd
/home/tuke.sk/dh/343/dh343ko/matematika
dh343ko@omega:~/matematika $ cd .
dh343ko@omega:~$ pwd
/home/tuke.sk/dh/343/dh343ko/matematika
dh343ko@omega:~/matematika $ cd ..
dh343ko@omega:~$ pwd
/home/tuke.sk/dh/343/dh343ko/
```

Symbolické mená si môžeme hneď vyskúšať aj s príkazom `ls`:

```bash
dh343ko@omega:~$ ls -l .
drwxr-xr-x 2 dh343ko tuke 4096 Feb  7 12:37 matematika
-rw-r--r-- 1 dh343ko tuke    0 Feb  7 12:37 Matematika
dh343ko@omega:~$ ls -l ~
drwxr-xr-x 2 dh343ko tuke 4096 Feb  7 12:37 matematika
-rw-r--r-- 1 dh343ko tuke    0 Feb  7 12:37 Matematika
dh343ko@omega:~$ ls -l ..
/home/tuke.sk/dh/343/dh343ko
drwxr-xr-x 2 dh343ko tuke 4096 Feb  7 12:37 dh343ko
```

NOTE: Koreňový adresár je / , všetky ostatné adresáre sú pod ním.
(neexistujú disky `C:` a `D:` ako na systéme Windows, ďalšie disky alebo diskové oddiely sú tiež adresáre).


#### Úloha

. Zistite, ako sa volá Váš domovský adresár a kde sa nachádza.
. Zistite, aké sú podadresáre hlavného adresára.
. Zistite, aké iné domovské adresáre sa na systéme nachádzajú a aké k nim máte prístupové práva.

### Shell je Váš priateľ

Do teraz to bolo pomerne veľa písania. Na začiatok to nie je na škodu, lebo sme sa aspoň naučili, kde na klávesnici sa nachádzajú špeciálne znaky.
Také množstvo písania môže pri reálnej práci a reálnych termínoch na odovzdanie výsledkov trochu zdržovať.

Autori príkazového riadku na šťastie na to mysleli a vymysleli šetrič práce.
K posledne zadanému príkazu sa viete dostať pomocou šípok.
Klávesa TAB slúži na magické dopĺňanie názvov súborov a príkazov.

Ak napíšete:

```bash
l<TAB>
```

Systém Vám vráti zoznam príkazov, ktoré sa začínajú na _l_.
Ten istý trik funguje na názvy súborov. Znak tilda `~` zastupuje Váš domovský adresár, takže:

```
ls ~/<TAB>
```

navrhne súbory vo Vašom domovskom adresári ako argument príkazu `ls`.

NOTE: V príkazovom riadku nič nemusíme (ale môžeme) písať viac krát.

Ak ste zabudli príkaz, ktorý ste napísali pred chvíľou, viete vyvolať históriu.

```shell
history
```

### Školská knižnica - organizácia súborov a adresárov:

Súborový systém má vlastnosti databázy.
Vytvorme databázu kníh v školskej knižnici. Adresár zodpovedá oddeleniu v knižnici alebo poličke s knihami
Súbor zodpovedá jednej knihe.
Súbory vieme umiestniť do najvhodnejšieho adresára. Príkaz na presunutie súboru `Matematika` do adresára `matematika` je:

```shell
mv Matematika matematika
```
Príkaz na presun `mv` má dva argumenty - zdrojový a cieľový adresár,

Príkaz `cp` slúži na kopírovanie. Prázdny súbor Matematika si vieme ľahko skopírovať (preniesť do ďalšieho semestra):

```shell
cp Matematika Matematika2
```
Súbor s názvom `Matematika` musí byť samozrejme prítomný v aktuálnom adresári. Ak nie je, dostaneme chybovú hlášku:

```shell
dh343ko@omega:~$ cp Matematika matematika
cp: cannot stat Matematika: No such file or directory
```

Kopírovať a presúvať môžeme aj súbory ktoré nie sú v aktuálnom adresári. Musím ale potom zadať ich plné meno alebo cestu k nim z aktuálneho adresára. Pri zadávaní cesty môžeme využiť aj symbolické mená:

```shell
cp ./Matematika2 ~/
```

Skúsme si spraviť zálohu našej práce v adresári `~/matematika` do adresára `~/zaloha_matematiky`.

```shell
dh343ko@omega:~$ cp ~/matematika ~/zaloha_matematiky
cp: omitting directory ~/matematika
```

Pokus sa neskončil úspešne. Príkaz `cp` hlási, že vynechal zdrojový adresár.  Dôvodom je to, že príkaz na kopírovanie odmieta pracovať s adresármi, pokiaľ mu to výslovne nepovieme pomocou prepínača `-r`.

```shell
dh343ko@omega:~$ cp -r ~/matematika ~/zaloha_matematiky
```

Teraz to vyzerá byť v poriadku. Výsledok si môžeme overiť pomocou príkazu `ls`.

Zbytočné zálohy si viem aj vymazať. Keďže je `Matematika2` (pre niektorých) zbytočná, pomocou príkazu `rm` ju vieme vymazať.

```shell
rm  ~/zaloha_matematiky/Matematika2
```
WARNING: Nezabúdajte, že pomocou klávesy TAB dopĺňate mená súborov a adresárov. Je zbytočné to písať ručne.

Pri použití príkazu `rm` platia tie isté obmedzenia ako pri príkaze `cp`.
Bez špeciálneho povolenia pomocou prepínača `-r` príkaz odmietne vymazať celý adresár. Nakoniec sme prišli, že tento prepínač slúži ako
dodatočná ochrana pred nechceným vymazaním všetkých súborov v domovskom adresári.

NOTE: Vždy pred použitím prepínača `-r` odporúčam použiť príkaz `ls` aby sme si overili, čo sa bude mazať alebo presúvať.

#### Úloha

Vytvorte databázu aspoň 6 kníh a zotrieďte ich do dvoch poličiek. Pre každú knihu a poličku
vymyslite knižničný kód (názov súboru alebo adresára) ktorý ju bude dobre vystihovať
ich obsah.

Poličky:

- Beletria;
- Informačné technológie.

Knihy:

- Základy algoritmizácie;
- 30 tisíc míľ pod morom;
- Používame Linux;
- ABC Linuxu;
- 50 odtieňov sivej;
- Dokonalý kód;

Presuňte knihu "50 odtieňov sivej" do novovytvorenej sekcie "Červená knižnica".

### Získanie pomoci v príkazovom riadku

Každý príkaz má svoju pomoc.
Podľa dohody tieto argumenty vrátia stručnú nápovedu:

```shell
--help
-?
```

Manuálové stránky prehliadame príkazom:

```shell
man
info
```
kde ako argument zadáme názov príkazu, ku ktorému chceme vyhľadať pomoc.

Keď všetko ostatné zlyhá, pomôže Váš obľúbený internetový vyhľadávač.

### Presmerovanie štandardného vstupu a výstupu

Program v Unixe vezme štandardný vstup, spracuje ho a výsledok pošle na štandardný výstup.

Operátory:

```bash
> # Presmerovanie štandardného výstupu do súboru
< # Presmerovanie štandardného vstupu do súboru
>> ## Presmerovanie štandardného výstupu a pridanie na koniec súboru

| ## Presmerovanie štandardného výstupu na štandardný vstup iného programu
```
Pomocou presmerovania vstupu viete manipulovať textové súbory alebo spájať viaceré príkazy do jedného.

#### Úloha

Do každej knihy pridajte názov pomocou príkazu ```echo```.

Zapíšte zoznam kníh v oddieli beletrie do súboru:

```shell
ls ./beletria > index
```

Pridajte k nemu aj knihy z oddielu informačných technológií:

```shell
ls ./it >> index
```

Výsledok príkazu sa pripojí na koniec súboru.

Vypíšte výsledný zoznam kníh v súbore:


```shell
cat index
```

Nezabudnite, že `TAB` dopĺňa názvy súborov.
Presmerovanie výstupu môžeme využiť na pridanie textu do súboru. Skúste do knihy "Základy algoritmizácie" na koniec
pridať text "Ahoj svet!".

```shell
echo "Ahoj svet!" > ./it/zap
```

#### Úloha

Uložte si záznam z cvičenia do súboru pomocou `history`. Záznamu vymyslite vhodné meno. Overte, či súbor naozaj obsahuje príkazy z cvičenia.
V manuálovej stránke zistite, ako sa vyhľadáva v histórii.


### Bibliografia

- http://www.abclinuxu.cz/download/ucebnice_abc_linuxu-20061019.pdf
- http://www.tldp.org/LDP/intro-linux/html/
- https://sk.wikipedia.org/wiki/Unix
