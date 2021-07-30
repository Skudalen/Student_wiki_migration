# Príkazový riadok UNIX

Vývoj systému UNIX začal v 70 rokoch minulého storočia.
Podieľali sa na ňom Ken Thompson a Dennis Ritchie.
V tých časoch počítače mali veľkosť celých budov, boli extrémne drahé a pomalé.
Ciele pri vyvoji boli:
  - Jedhoduchý a elegantný systém.
  - Napísaný v jazyku C.
  - Znovupoužiteľnosť napísaného kódu.
      - Každý hardware si do vtedy vyžadoval osobitný prístup.
      - Znovupoužiteľnosť bola dosiahnutá vďaka štandardným knižniciam.

## Filozofia Unix

https://en.wikipedia.org/wiki/Unix_philosophy


>   Toto je filosofia Unixu: 
Píšte také programy, ktoré robia len jednu vec a robia ju dobre. 
Píšte programy tak, aby spolupracovali. 
Píšte programy pre štandardné textové prúdy, lebo to je univerzálne rozhranie. 

Typický UNIX program:

- Je jednoúčelový,
- Má textový vstup a výstup (štandardné textové prúdy).

            
Unix bol postavený tak, aby bol prenositeľný, viacúlohový a viacpoužívateľský.
Jeho myšlienky pretrvali do dnešných dní v podobe systému Linux, ktorému sa bude,e venovať.
Hoci jeho základy sú veľmi staré, stále nie sú zastaralé. Prakticky každá serverová aplikácia
beží na niektorej variante systému s Linuxovým jadrom. Aj keď to nie je viditeľné, základy Unixu sa nachádzajú aj vo vašom mobilnom telefóne.


## Vzdialené prihlásenie sa do systému

Viac používateľov vie pracovať so vzdialeným servrom v textovom móde.

Textový mód umožňuje kvalitné spojenie aj na pomalých linkách
Stačí veľmi jednoduchý klient (emulátor terminálu).

- Na OS Windows: Puttty;
- Iný UNIX: ssh user@omega.tuke.sk.


## Príkazový riadok

Príkazový riadok je špeciálny program (shell), ktorý pracuje interaktívne v cykle:

- Načítaj príkaz;
- Vykonaj príkaz;
- Vypíš výsledok;
- Pokračuj.

https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop

Na príklad, príkaz

	ls -l

napíše zoznam súborov v aktuálnom adresári.
 
## Shell je Váš priateľ
 
Po krátkom cviku sa v shelli pracuje pohodlnejšie a rýchlejšie ako s graficky s myšou.

Ak ste zabudli príkaz, ktorý ste napísali pred chvíľou, viete vyvolať históriu.
 
  
```shell
history
```
 
K posledne zadanému príkazu sa viete dostať aj pomocou šípok.
Klávesa TAB slúži na magické dopĺňanie názvov súborov a príkazov.
 
Ak napíšete:
 
 	l<TAB>
 
Systém Vám vráti zoznam príkazov, ktoré sa začínajú na l.
Ten istý trik funguje na názvy súborov. Ak napíšeme
 
 	ls /etc/<TAB>
    
tak systém Vám napovie zoznamom súborov a adresárov v adresári /etc/.
Znak tilda ~ zastupuje Váš domovský adresár, takže:
 
 	ls ~/<TAB>
 
navrhne súbory vo Vašom domovskom adresári ako argument príkazu ls.
Adresáre v Unixe sú radené do stromu.
Koreňový adresár je / , všetky ostatné adresáre sú pod ním.
(neexistujú disky c a d ako na Windowse, ďalšie disky alebo diskové oddiely sú tiež adresáre).

Príkaz (print working directory)

```shell
pwd
```
vypíše názov aktuálneho adresára. 

 
## Úloha
 
Zistite, ako sa volá Váš domovský adresár.
 
## Získanie pomoci v shelli:
 
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
 
 
## Spustenie programu pre výpis súborov
 
Jeden príkaz = jeden program
Každý príkaz môže mať zoznam argumentov oddelených medzerou
 
```shell
ls -l
```
 
## Príklad: Školská knižnica
 
Súborový systém má vlastnosti databázy. 
Vytvorme databázu kníh v školskej knižnici. Adresár zodpovedá oddleleniu v knižnici alebo poličke s knihami
 
Súbor zodpovedá jednej knihe.
 
Vytvorenie prázdneho súboru:
 
```shell
touch Matematika
``` 

Vytvorenie adresára:

```shell

mkdir matematika
``` 

Presunutie súboru do adresára:


```shell

mv Matematika kniha
``` 

## Úloha

Vytvorte databázu aspoň 6 kníh a zatriedte ich do dvoch poličiek. Pre každú knihu a poličku 
vymyslite knižničný kód (názov súboru alebo adresára) ktorý ju bude dobre vystihovať
ich obsah.

Poličky:

- Beletria;
- Informačné techológie.

Knihy:

- Základy algoritmizácie;
- 30 tisíc míľ pod morom;
- Používame Linux;
- ABC Linuxu;
- 50 odtieňov sivej;
- Dokonalý kód;

Presunte knihu "50 odtieňov sivej" do novovytvorenej sekcie "Červená knižnica".

## Kopírovanie a mazanie

Príkazom 

```shell
cp -r ./kniznica ./zaloha
du -ch
```
vytvoríme zálohu našej knižnice a overíme veľkosť vytvorenej zložky

Zbytočné zálohy vymažeme:

```shell
rm  ./zaloha
```
Tento príkaz neprebehne, lebo zložka obsahuje podzložky.
Argument -r spôsobí rekurzívne volanie algoritmu a vymazanie alebo skopírovanie aj vnorených zložiek.

 
## Presmerovanie štandardného vstupu a výstupu

Program v Unixe vezme štandardný vstup, spracuje ho a výsledok pošle na štandardný výstup.

Operátory:

```bash
> # Presmerovanie štandardného výstupu do súboru
< # Presmerovanie štandardného vstupu do súboru
>> ## Presmerovanie štandardného výstupu a pridanie na koniec súboru

| ## Presmerovanie štandardného výstupu na štandardný vstup iného programu
```  
Pomocou presmerovania vstupu viete manipulovať textové súbory alebo spájať viaceré príkazy do jedného.

## Úloha

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

Nezabudnite, že TAB dopĺňa názvy súborov. 
Presmerovanie výstupu môžeme využiť na pridanie textu do súboru. Skúste do knihy "Základy algoritmizácie" na koniec 
pridať text "Ahoj svet!".

```shell
echo "Ahoj svet!" > ./it/zap
```

## Úloha

Uložte si záznam z cvičenia do súboru pomocou history. Záznamu vymyslite vhodné meno. Overte, či súbor naozaj obsahuje príkazy z cvičenia.
V manuálovej stránke zistite, ako sa vyhľadáva v histórii.


## Bibliografia

- http://www.abclinuxu.cz/download/ucebnice_abc_linuxu-20061019.pdf
- http://www.tldp.org/LDP/intro-linux/html/
- https://sk.wikipedia.org/wiki/Unix
