# Editor Vim

Pri vzdialenom prístupe na server si väčšinou nevystačíte s Vaším
obľúbeným textovým editorom pracujúcim v grafickom móde (napr.
Notepad). Je výhodné naučiť sa terminálový editor aj keď s ním nebudete
pravidelne pracovať.

Textový editor sa odlišuje od textového procesora (napr. LibreOffice
alebo Word) tým, že pracuje priamo priamo s textom a neumožňuje
formátovacie operácie (napr. tučné písmo). Hlavné použitie textového
editora nie sú kancelárske dokumenty, ale zdrojové texty programov alebo
konfiguračné súbory.

Textový editor musí byť prispôsobený možnostiam terminálu:

  - Pomalé prenosové rýchlosti
  - Nízka odozva
  - Nekompatibilné mapy klávesnice

Textový editor, podobne ako ostatné príkazy v Unixe nepracuje v
grafickom móde ale iba v textovom. Z toho dôvodu obsahuje iba obmedzenú
podporu pre myš a neobsahuje klasické výberové menu. Namiesto toho
príkazy editoru zadávame výlučne pomocou klávesnice.

Existuje veľa rôznych textových editorov pre vhodných do terminálu.

  - emacs
  - vi
  - vim
  - neovim
  - nano, pico
  - joe
  - sed (neinteraktívny editor)

Budeme sa sústrediť na editor `vim`.

# Módy editora VIM

Editor ViM je de-facto štandard pre editovanie textových súborov v
prostredí terminálu.

Na začiatku je práca s VIM ťažšia a menej intuitívna. Každá naučená
operácia ale spôsobuje výrazne zvýšenie rýchlosti práce. Vycvičený
používateľ s ním dokáže pracovať oveľa rýchlejšie ako s klasickým
editorom. Viaceré profesionálne editory obsahujú VIM mód, ktorý
napodobňuje správanie editora VIM.

ViM je modálny editor. V každom móde sú dostupné iné funkcie.

  - Normálny mód  
    Príkazy zadávame stlačením kláves. Jedna klávesa je
    spravidla jeden príkaz, napr. príkazom `p` vložíme slovo zo
    schránky. Návrat do normálneho módu je vždy pomnocou `ESC`.

  - Príkazový mód  
    V príkazovom móde píšeme dlhšie príkazy editoru do príkazového
    riadka. Môžeme prejsť na konkrétny riadok, alebo môžeme vykonať
    príkaz SHELL.

  - Editovací mód  
    Editovací mód začneme príkazom `i`,`I` alebo `a`,`A`. V editovacom
    móde píšeme text. Snažíme sa byť v ňom čo najkratšie a čo najviac
    operácií s textom vybaviť v normálnom alebo príkazovom móde.

  - Označovací mód  
    Aktivujeme ho príkazom `v`. Šípkami označíme text. Príkazom `y`
    skopírujeme text do schránky. Príkazom `ESC` skončíme označovací
    mód.

Z každého módu sa vždy viete ľahko prepnúť do normálneho módu pomocou
`ESC`. Ak ste zabudli v akom ste móde, prepnite sa do normálneho módu a
zopakujte akciu.

# Príklad

Napíšeme svoj prvý román v editore `ViM`.

Najprv sa prihláste na Váš obľúbený `UNIX` server. Príkazom `vim` spustíte
editor. Zobrazí sa Vám uvítacia obrazovka. Prečítajte si ju, a príkazom
`:help` otvorte vstavanú pomoc. Príkazom `ESC :q` skončíte editor. Ak
ste náhodou vložili nejaký text, musíte potvrdiť ukončenie bez uloženia
pomocou výkričníka.

    <ESC>:q!

Hoci táto skupina znakov na prvý pohľad vyzerá zložito, má to svoje
opodstatnenie. Klávesu `ESC` nájdete ľahko, podobne aj `:` a `q`. Častým
používaním určitých kláves sa naučíte prstoklad a budete písať podobne
intuitívne ako hráči na klavíri.

Skončite editor a otvorte nový súbor:

``` shell
vim tazkyzivot.txt
```

Editor sa spustí v normálnom móde. Román začnete písať po stlačení `i`,
ktorým editor prepnete do editovacieho módu. Na začiatok napíšeme tento
text:

    Ťažký život námorníka na suchej zemi

    Bola to ťažká noc. Ráno som nevedel rozlepiť oči.
    Rýchlo som vstal.

Editovanie ukončíte stlačením `ESC`. Po texte sa pohybujete šípkami,
klávesami `hjklwWbB`. Zistite aký je medzi nimi rozdiel (môžete využiť
príkaz `:help`).

Nápoveda - profesionáli používajú `w` a `b`, nemusia pritom veľa
rozmýšľať a hľadať kde stratili myš.

Po kontrole ste zistili, že veta číslo 3 (`Rýchlo som vstal.`) je príliš
ľahká na taký ťažký román. Príkazom `:4` sa expresne presuniete na
tretiu vetu na štvrtom riadku. Dajte pozor, aby ste boli v normálnom
móde (presvedčiť sa o tom môžete pomocou klávesy `ESC`). Príkazom `dd`
celý riadok vymažete.

Vymazaný riadok môžete vrátiť príkazom `p` (vloženie zo schránky) alebo
`u` (undo). Príkaz `.` (bodka) vie zopakovať poslednú operáciu. Ľahko
potom viete celý román odľahčiť touto ľahkou vetou, tak aby text
vyzeral:

    Ťažký život námorníka na suchej zemi

    Bola to ťažká noc. Ráno som nevedel rozlepiť oči.
    Rýchlo som vstal.
    Rýchlo som vstal.
    Rýchlo som vstal.

Ak chceme text spraviť menej dynamický, nahradte všetky výskyty "Rýchlo"
na "Pomaly". Prístup neznalého študenta by bol prepnúť sa do vkladacieho
módu, vymazať písmená pomocou klávesy `del` a tri krát napísať to isté.
Využijeme ale možnosti editora ViM na kreatívne písanie.

Ak ste v normálnom móde, napíšte:

    /Rý<ENTER>

Kurzor skočí na prvý výskyt "Rý" v súbore. Príkazom `n` a `N` sa môžeme
pohybovať medzi nájdenými reťazcami. Príkazom `Ctrl+V` sa prepneme do
blokového označovacieho módu a označíme všetky slová "Rýchlo". Príkazom
`c` (change) vymažeme všetko označené a prepneme sa do vkladacieho módu.
Napíšeme "Pomaly" a ukončíme editovanie. Vymazaný text máme v schránke a
môžeme ho niekde vložiť pomocou `p`.

Výsledok by mal vyzerať:

    Ťažký život námorníka na suchej zemi

    Bola to ťažká noc. Ráno som nevedel rozlepiť oči.
    Pomaly som vstal.
    Pomaly som vstal.
    Pomaly som vstal.

    Rýchlo
    Rýchlo
    Rýchlo

Zbytočné riadky viete vymazať pomocou `dd`, zbytočné slová pomocou
`daw`, zbytočné vety pomocou `das`. Súbor uložíme pomocou `:w`.

Uložiť a skončiť `:wq` alebo `ZZ`.

## Upratovačka zdrojového kódu.

Zoberte nejaký Váš program a skúste ho upratať pomocou VIM. Upratovanie
označenej časti vykonáme klávesou `=`. Príkazom `gg` skočíme na začiatok
súboru, `v` aktivuje označovací mód. príkazom `G` skočíme na koniec
súboru a tým je celý súbor označený.

## Úloha

Čo najrýchlejšie nakreslite vo ViM textovú tabuľku s menným kalendárom
pre aspoň jeden vybraný týždeň, kde uvediete:

  - Meno
  - Dátum
  - Deň v týždni

Bunky oddeľte pomocou zvislej čiary `|`, prvý riadok oddeľte pomocou
`=`. Tabuľku začnite a skončite pomocou `_ a -`.

Pomôcka:

Využite blokové editovanie, kopírovanie riadkov a opakovanie poslednej
operácie.

# ViM Ťahák

Zhrnutie práce s editorom ViM:

``` 
 :tutorial - Spustí interaktívny tutoriál
 :help spustí pomoc. ] a Ctrl+T funguje na hpertextové odkazy.
 :q! skončí editovanie a zahodí zmeny.
 Esc - Normálny mó
 i - vkladací mód
a - koniec riadka a vkladací mód
 v - vizuálny (označovací) mód
 V - riadkový vizuálny mód
 Ctrl-V - blokový označovací mód
 y - kopíruj (vo vizuálnom móde)
 x - vyber (vo vizuálnom móde)
 = - uprav odsadenie, uprac kód (vo vizuálnom móde)
 yy - kopíruj riadok
 dd - vymaž riadok
 dw - vymaž slovo
 das - vymaž aktuálnu vetu
 P - vlož
 ZZ - ulož a skonči
 / - vyhľadávanie
 * - vyhľadávanie aktuálneho slova alebo mena
 gg choď na začiatok
 G choď na koniec súboru
 :2 choď na riadok číslo 2
 :w - ulož
 u - undo
 Crtl-R - redo
 :make stairs - prelož program stairs
 :!./stairs.run - spusti program stairs
```

# Regulárne výrazy a editor VIM

Regulárne sú nevyhnutnou pomôckou pri práci s veľkým množstvom textu.
Pomocou nich vieme vyhľadávať a nahrádzať niektoré vzory. Zápis
regulárnych výrazov je závislý na konkrétnej implementácii, ale
existujú niektoré všeobecné pravidlá.

Regulárne výrazy môžeme využiť v programoch:

  - vim
  - Váš iný obľúbený textový editor
  - grep:: vyhľadávanie súborov
  - sed:: neinteraktívne editovanie súborov z príkazového riadku.
  - Váš vlastný program v jazyku C
    
    1.  Editor vi pracuje v rôznych módoch. V normálnom móde pohybujete
        kurzorom a manipulujete s blokmi textu. Príkazy v normálom móde
        zadávame stlačením kláves. Príkazom `i` alebo `A` aktivujete
        vkladací mód v ktorom píšete text. Vkladací mód opustíme
        klávesou `ESC`. Otvorte si editor vi a vložte do neho testovací
        text:
        
            vim test.txt
        
            Otvorí sa prázdny súbor a editor vim je v príkazovom móde. Skúste napísať "Ahoj svet". Editovanie ukončite klávesou ESC. Súbor uložíme  a skončíme editovanie príkazom ZZ. Overíme si výsledok editovanie pomocou programu cat.
        
            cat test.txt
    
    2.  Do súboru test.txt vložte nasledovný testovací text. Môžete
        použiť schránku.
        
            toto je mac adresa: 01:23:45:67:89:0a
            Nesprávne MAC adresy:
            xx:xx:xx:xx:xx:xx
            01:23:45-67-89-0a
            01:23:45:67:89:0a:
            :01:23:45:67:89:0a
            01:
            Správna mac adresa:
            a1:3d:56:99:01:ee
    
    3.  Príkazom `/` vyhľadávate. Vyhľadajte všetky výskyty slova
        adresa. Príkazom `n` kurzor skočí na ďalší vyskyt, `N` skočí na
        predošlý výskyt hľadaného reťazca. Príkazom `:set hlsearch`
        zapnite zvýraznenie nájdených reťazcov. Príkazom `:nohl` zrušíte
        aktuálne zvýraznenie vyhľadávania.
    
    4.  Na miesto vyhľadávaného reťazca môžete zadať aj regulárny výraz.
        Regulárny výraz je špeciálny reťazec, ktorým viete "zachytiť" a
        opísať viac reťazcov naraz. Napíšte regulárny výraz, ktorý
        zachytí slová "adresa" a "adresy". V reguárnom výraze použijete
        operátor `[]` pre zachytenie skupiny znakov:
        
            /adres[ay]

Znaky `[` a `]` majú špeciálny význam. Ak ich chceme vyhľadať, musíme
pred nich napísať spätné lomítko `\`.

1.  V hranatých zátvorkách vieme uvádzať aj rozsahy znakov pomocou `-`.
    Vyhľadajte všetky dvojice desiatkových čísel. Pri vyhľadávaní môžeme
    využiť aj históriu hľadaní pomocou šípok hore a dole.
    
        /[0-9][0-9]

2.  V regulárnych výrazoch vieme vytvoriť opakujúce sa skupiny. Skupinu
    ohraničíme znakmi `\( a \)` . P očet opakovaní zapíšeme skupiny
    zapíšeme pomocou `\{m,n}`. (`m` je minimálny počet opakovaní, `n`
    je maximálny). Napíšte regulárny výraz pre zachytenie mac adresy
    tvorenej desiatkovými číslami alebo malými písmenami a oddelenej
    dvojbodkami:
    
        \([0-9a-z][0-9a-z]:\)\{6}

Upravte výraz tak aby zachytával aj adresy oddelené pomlčkou. Všimnite
si, že uvedený zápis nie je celkom správny, lebo si vyžaduje, aby na
konci bola dvojbodka.

1.  Napísaný regulárny výraz môžeme využiť pre operáciu typu "hľadaj na
    nahraď". Nahradte všetky MAC adresy v súbore reťazcom "MAC". Využite
    príkaz `:%s/hladaj/nahrad/gc`. Reťazec hladaj je regulárny výraz
    ktorý vyjadruje hľadané reťazce. nahrad je reťazec ktorým
    nahradzujeme. Znak `%` hovorí, že hľadáme v celom súbore. `g`
    hovorí, že nahradzujeme všetky výskyty na riadku, nie len prvý.
    Znak c hovorí, že si vyžadujemem osobitné potvrdenie každého
    nahradenia.
    
        :%s/\([0-9a-z][0-9a-z]:\)\{6}/MAC/gc

Posledný regulárny výraz z vyhľadávania nemusíte vypisovať odznova,
môžete využiť fintu `<Ctrl-R>/` ktorá vloží posledne hľadaný výraz. Ak
sa Vám vykonané nahradenia nepáčia, zmeny môžete vrátiť príkazom u (ako
undo). Opakom undo je `<Ctrl-R>` (redo). V príkazovom móde tiež môžete
využívať históriu pomocou kláves hore a dole.

1.  Regulárne výrazy môžeme napísať aj v jazyku C. Stiahnite si program,
    preložte a spustite ho. Skúste využiť editor vim.

<!-- end list -->

``` c
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

void bad(){
    fprintf(stderr, "Wrong password!\n");
    exit(EXIT_FAILURE);
}


int main(){
    char buffer[101];
    int result;
    regex_t regex;

    // read input
    printf("Enter password: ");
    scanf("%100s", buffer);

    regcomp(&regex, "^k.*.*k+.*$", REG_EXTENDED);
    result = regexec(&regex, buffer, 0, NULL, 0);
    if(result == REG_NOMATCH){
        bad();
    }

    regcomp(&regex, "^.(ab|ac|ad).(bu|cu|du).*$", REG_EXTENDED);
    result = regexec(&regex, buffer, 0, NULL, 0);
    if(result == REG_NOMATCH){
        bad();
    }

    regcomp(&regex, "^...h?o?v?n?i|v?a?l?...$", REG_EXTENDED);
    result = regexec(&regex, buffer, 0, NULL, 0);
    if(result == REG_NOMATCH){
        bad();
    }

    regcomp(&regex, "^.*(..[dD].){2}.*$", REG_EXTENDED);
    result = regexec(&regex, buffer, 0, NULL, 0);
    if(result == REG_NOMATCH){
        bad();
    }

    regcomp(&regex, "^(.?.?.?.?.?.?a){2}$", REG_EXTENDED);
    result = regexec(&regex, buffer, 0, NULL, 0);
    if(result == REG_NOMATCH){
        bad();
    }

    printf("Correct password\n");
}
```

Príkazy príkazového riadka môžete zadávať priamo z VIMu pomocou `:!`

    vim heslo.c
    :!gcc -std=c99 heslo.c -o heslo
    :!./heslo

Zistite, aké heslo program očakáva. Na pohyb kurzora v normálnom móde
využite klávesy `w` `b` (ďalšie alebo predošlé slovo) alebo `h` `j` `k`
`l` (pohyb kurzorom z klávesnice). Ak máte pripravený `Makefile`, môžete
použiť príkaz `:make`

Pomôcka špeciálne znaky REGEX:

|         |                                                       |
| ------- | ----------------------------------------------------- |
| `.`     | Ľubovoľný znak                                        |
| `^`     | Začiatok reťazca                                      |
| `$`     | Koniec reťazca                                        |
| `[A-Z]` | skupina znakov s rozsahom                             |
| `()`    | skupina pre opakovanie                                |
| `?`     | 0-1 opakovaní                                         |
| `*`     | 0-nekonečno opakovaní predošlého znaku alebo skupiny. |
| `+`     | 1-nekonečno opakovaní                                 |
| '       | '                                                     |

Význam a zápis špeciálnych znakov je závislý od implementácie. (napr. vo
VIM musíte pred niektoré špeciálne znaky písať \\)

# Dodatočný materiál

  - [Regex Tutoriál](http://www.regular-expressions.info/tutorial.html)
  - [Regex Cheat Sheet](http://www.petefreitag.com/cheatsheets/regex/)
  - [Editor VIM prakticky](http://www.abclinuxu.cz/clanky/navody/editor-vim-prakticky-i)
  - [Stránky Pavel Satrapa](http://www.nti.tul.cz/~satrapa/docs/vim/)
  - [Mapa klávesnice VIM a
    tutoriál](http://www.viemu.com/a_vi_vim_graphical_cheat_sheet_tutorial.html)
