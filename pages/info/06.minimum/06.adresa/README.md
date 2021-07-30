<div class="note">

<div class="title">

Naučíte sa

</div>

  - Čo je to adresa premennej a ako ju zistíme.

  - Ako pracovať s adresou premennej.

  - Vytvoriť si funkciu ktorá zapisuje do premennej.

</div>

Dostali sme sa do stavu, že automatická kalkulačka funguje vynikajúco.
Vieme načítať viaceré čísla z klávesnice a vieme s nimi urobiť
aritmetické operácie. Nevýhodou tohto programu je, že sa v ňom stále
opakuje tá istá časť - načítanie celého čísla do premennej.

V prípade krátkeho programu to nie je problém, ale v prípade dlhšieho
program to komplikuje situáciu. Ak sme sa pomýlili v jednej časti,
musíme opraviť aj všetky ostatné kópie.

# Funkcia pre načítanie do premennej

Je výhodné zabezpečiť, aby rovnakú vec riešila práve jedna časť kódu.
Vytvoríme si preto funkciu, ktorá sa bude starať o načítanie čísla z
klávesnice. Túto funkciu bude možné použiť na viacerých miestach
programu podľa potreby. Kód na načítanie čísla bude iba na jednom mieste
a nemusíme stále kopírovať túto časť, stačí zavolať funkciu, ktorú už
máme hotovú. Program sa bude možné jednoduchšie opraviť alebo vylepšiť,
lebo nemusíme hľadať kde všade sa vyskytuje podobný kód.

## Argument funkcie je lokálna premenná

Funkcie na načítanie a premenu vstupu z klávesnice zapisujú výsledok do
jedného z argumentov a využívajú návratovú hodnotu na hlásenie
výsledkov. Vyskúšajme si vytvoriť podobnú funkciu, čo zapisuje do
jedného z argumentov. Táto funkcia spočíta dve čísla, výsledok uloží do
premennej a vypíše ho na obrazovku. Bude stačiť zapísať súčet argumentov
funkcie a výsledok uložiť do premennej? Keď napíšeme takýto program:

``` c
int mocnina(int argument){
    return argument * argument;
}

int main() {
    int argument = 7;
    int vysledok = mocnina(argument);
    printf("Vysledok je %d",vysledok);
    return 0;
}
```

Stane sa niekoľko vecí:

1.  Do premennej s názvom `argument` sa uloží hodnota 7.

2.  Hodnota, ktorá je uložená v premennej `argument` vo funkcii `main()`
    sa skopíruje do premennej argument vo funkcii `mocnina()`. Tieto dve
    premenné sú rozdielne, hoci sa volajú rovnako. Každá premenná má
    svoj rozsah platnosti - prvá premenná `argument` platí v rámci
    funkcie `main()` a druhá premenná `argument` platí iba v rámci
    funkcie `mocnina()`.

3.  V rámci funkcie `mocnina()` sa vypočíta návratová hodnota.

4.  Riadenie programu sa vráti do funkcie `main()`, návratová hodnota
    funkcie `mocnina()` sa skopíruje do premennej `vysledok`.

Vidíme, ak funkcii odovzdáme hodnotu premennej, funkcia nie je schopná
zapísať do pôvodnej premennej. Namiesto toho sa urobí kópia a výsledok
spracovania kópie môžeme využiť ako návratovú hodnotu funkcie. Výhoda
tohto prístupu je, že sme si istý, že funkcia nám nezmení hodnotu
pôvodnej premennej, ktorej ktorú požijeme pri volaní funkcie, ani
žiadnej ďalšej premennej.

V jazyku C sú funkcie volané vždy s kópiou argumentov. Volanie funkcie
vždy spôsobí vytvorenie nových premenných do ktorých sa skopíruje
hodnota argumentov funkcie. Po skončení sa argumenty správajú ako iné
lokálne premenné a hodnoty v nich uložené sa zabudnú.

## Cvičenie

Aby sme si overili tvrdenie že pri volaní funkcie dochádza ku
kopírovaniu, môžeme skúsiť modifikovať tento program a overiť si, že
premenné s názvom `argument` sú v skutočnosti dve rôzne premenné.
Modifikujeme hodnotu druhej premennej a sledujeme, či sa zmena prejaví v
prvej premennej. Ak sú premenné rovnaké, nastane zmena v prvej
premennej. Ak sú rôzne, zmena sa neprejaví.

``` c
int mocnina(int argument){
    argument = 2;
    return argument * argument;
}

int main() {
    int argument = 7;
    int vysledok = mocnina(argument);
    printf("Vysledok je %d",vysledok);
    printf("Hodnota premennej argument je %d",argument);
    return 0;
}
```

1.  Akú hodnotu premennej `argument` vypíše program?

2.  Vypíšte adresu pamäte všetkých premenných s názvom `argument`.

# Načítanie do lokálnej premennej

Skúsme preto na výsledok načítania využiť návratovú hodnotu funkcie.
Budeme potrebovať pole na uloženie načítaného reťazca, premennú na
uloženie výsledku a pomocnú premennú na overenie si, či bolo načítanie
a konverzia úspešná. Najprv načítame reťazec. Ak je načítanie
úspešné,pokúsime sa premeniť reťazec na číslo. Ak je premena reťazca
na číslo úspešná vrátime výsledok. V inom prípade vrátime nulu.

``` c
#define BUFSIZE 20 // konštanta s veľkosťou pomocnéo poľa
int nacitaj_cele_cislo(){
   // Lokálna premenná pre uloženie výsledku
   int vysledok = 0;
   // Pole pre ulozenie vstupu vo forme reťazca
   char buffer[BUFSIZE];
   // Je dobrý zvyk stále inicializovať pamäť
   memset(buffer,0,BUFSIZE);
   // Pomocná premenná
   // pre ulozenie infrmácie o úspešnosti načítania
   int r = 0;
   r = fgets(buffer,BUFSIZE,stdin);
   // Ak sa načítanie podarilo
   if (r > 0){
      // Konvertujeme reťazec na číslo
      r = sscanf(buffer,"%d",&vysledok);
      // Ak sa konverzia podarila,
      if (r == 1){
          // vrátime výsledok
          return vysledok;
      }
   }
   return 0;
}
```

Premenné definované vo funkcii `nacitaj_cele_cislo()` nazývame lokálne
premenné. Lokálna premenná platí iba v bloku v ktorom bola napísaná. Ak
sa ju pokúsime využiť v inom bloku, napr. vo funkcii `main()` tak nám to
prekladač nedovolí.

Takáto funkcia funguje skvele, vyskúšajte:

``` c
int main(){
  int c = nacitaj_cele_cislo();
  // printf("Nacitany retazec je %s\n",vstup);
  printf("Nacital som %d\n",c);
  return 0;
}
```

# Načítanie s hlásením chyby

Čo ale stane ak namiesto čísla zadáme písmená? Takto napísaný program
nie je schopný rozlíšiť chybne zadaný vstup od správne zadanej nuly.
Takáto funkcia nie je použiteľná na našu slávnu kalkulačku -
spôsobovala by neočakávané správanie v prípade nesprávneho vstupu. V
prípade, že sme sa pomýlili by predstierala, že bola správne načítaná
nula a spokojne by napísala výsledok.

Mali by sme nájsť spôsob pomocou ktorého by funkcia hlásila chybu.
Funkcia by mala vrátiť až dve hodnoty - výsledok a informáciu o tom, či
je výsledok platný. Vyzerá to tak že sa to nedá - jazyk C umožňuje iba
jednu návratovú hodnotu. Musíme využiť bočné cesty a obísť tento
nedostatok.

Globálne premenné nie sú závislé od aktuálneho bloku a platia v každom
mieste programu. Ich použitie so sebou nesie niekoľko rizík: Funkcie,
ktoré používajú globálne premenné menia celkový stav programu. Pri prvom
spustení funkcie s globálnou premennou sa zmení je je hodnota a tá
ostane aj pri ďalších spusteniach. Takýto problém jě pomerne ťažké
odhaliť, lebo pokiaľ podrobne nepoznáme zdrojové texty funkcie, o
globálnych premenných nemusíme vedieť.

Môžeme povedať, že globálne premenné sú ťažko vypočítateľné - ich stav
môže závisieť od predchádzajúceho behu programu.

Globálnu premennú použite iba v prípade že ste si istí že je jediným
možným spôsobom riešenia problému.

Potrebovalil by sme spôsob ako by funkcia vrátila viac hodnôt -
informáciu o úspešnosti načítania a výsledok.

Namiesto globálnej premennej môžme využiť podobný postup ako v
štandardnej knižnici - návratová hodnota funkcie bude hlásiť úspešnosť
načítania a načítanú hodnotu uložíme do smerníkovej vstupnej premennej
(argumentu funkcie), podobne ako to je vo funkciách `fgets()` alebo
`sscanf()`.

Ak chceme napísať funkciu, ktorá vracia viac hodnôt, musíme zapisovať do
vstupných argumentov.

Na zápis do argumentu funkcie musíme využiť adresu premennej.

# Smerník

Každý údaj v pamäti je uložený na určitom mieste v pamäti. Pamäťové
miesto má svoju adresu ktorú voláme **smerník**.

Pamäť počítača si vieme predstaviť ako obrovskú policu, rozdelenú na
rovnako veľké priehradky. Priehradky sú očíslované od 0 až po `N-1`, kde
`N` je dĺžka police. Do jednej priehradky sa dá uložiť práve jedna
správa.

V jazyku C adresu v pamäti (číslo priehradky v polici) nazývame smerník.

Náš kamarát procesor je veľmi šikovný a dokáže spracovať čokoľvek, čo je
uložené v polici, stačí mu povedať kde je to uložené. Komunikácia s
procesorom by mohla vyzerať takto:

    Zober hodnotu z priehradky číslo 7 a pripočítaj k nej hodnotu v priehradke číslo 20. Výsledok ulož do priehradky číslo 40.

Vyber hodnoty z priehradky 17, odpočítaj sedem a výsledok ulož do
priehradky 34. Tento spôsob komunikácie je pre procesor ľahko
zrozumiteľný - jediné čomu rozumie sú čísla.

Kompilátor dokáže adresám v pamäti prideliť symbolické mená - prideliť
názov premennej. Tento názov potom môžeme používať v programe.
Komunikácia s procesorom potom môže vyzerať o niečo lepšie:

    Priehradka číslo 7 sa bude volať výsledok. Priehradka 6 sa bude volať argument. Zober argument, vynásob ho samým sebou a ulož do výsledku.

Výsledok operácie druhá mocnina z argumentu bude uložený v priehradke s
názvom "výsledok". Prekladač sa stará aj o veľkosť potrebnú pre uloženie
jedného údaju.

Operačný systém sa stará o to, aby každý program mal prístup iba k
svojej časti pamäte (vyhradí priehradky pre pracovníka) a nezasahoval do
práce iných programov a nezasahoval do práce iných programov. Zabráni
tým tomu, aby jeden program modifikoval pamäť, ktorá mu nepatrí.

Ak "poštový úrad" patrí k tým väčším (napr. Pošta 1) a pri polici sa
točí viacero pracovníkov, rýchlo stratíme prehľad o situácii. Ak sa
poštár pomýli tak ľahko "primieša" časti hodnôt ktoré patria inému
pamäťovému miestu. Ak je ukladaná hodnota príliš veľká, prepíše údaje,
ktoré sú uložené vedľa.

# Smerníková premenná

Vidíme že pamäťová adresa je nejaké číslo, ktoré je priradené
konkrétnemu pamäťovému miestu. Dostupné pamäťové miesta sú zoradené za
sebou a vzostupne očíslované - podobne ako priehradky na polici na
pošte.

Smerník je celé číslo, ktoré vyjadruje, kde je údaj uložený. Hodnotu
smerníka si vieme uložiť do smerníkovej premennej.

Hodnotu adresy v pamäti si môžeme uložiť do premennej. Takúto premennú
nazývame **smerníková premenná** a jej typ obohatíme znakom `*`.

Ak si chceme vytvoriť smerníkovú premennú a uložiť si do nej adresu
premennej typu `int`, smerníkovú premennú zapíšeme ako `int*`.

Napráklad, do premennej `adresa_argumentu` typu `int*` si môžeme uložiť
adresu pamäťového miesta typu `int`. Adresu premennej (jej smerník)
zistíme pomocou operátora `&`:

``` c
int argument = 7;
int* adresa_argumentu = &argument;
printf("Premenná argument je uložená na adrese %p",adresa_argumentu);
```

Formátovacia značka `%p` slúži n výpis celého čísla v hexadeximálnom
tvare:

    Premenná argument je uložená na adrese `0xffffffffef`.

## Práca so smerníkovou premennou

Schopnosť poznamenať si pamäťovú adresu niektorej premennej na prvý
pohľad nie je veľmi užitočná. (Niekoho síce môže hriať pri srdci
možnosť sa pozrieť "pod kapotu" a ručne skontrolovať, či sa prekladač
nepomýlil a nepridelil tú istú pamäť dva krát, ale to asi nebude náš
prípad).

So smerníkovou premennou môžeme pracovať podobne ako s klasickou
premennou, lebo pomocou operátorov vieme ľahko získať hodnotu, kotrá je
uložená na smerníku (adrese pamäťového miesta) v smerníkovej premennej.

Smerníkovú premennú na určitý typ môžeme využívať podobne ako klasickú
premennú, musíme ale pamätať, že v nej uchovávame nie hodnotu ale adresu
kde je hodnota uložená.

K hodnote, ktorá je uložená na zadanej adrese sa dostaneme pomocou
operátora `*`.

<div class="note">

Operátor `  ` pomocou ktorého získame adresu je rozdielny od
`</emphasis>` ktorou vyznačujeme smerníkovú premennú.

</div>

Pomocou operátora `*` môžeme zo smerníkovej premennej získať hodnotu, na
ktorú smerník ukazuje:

``` c
int argument = 7;
int* adresa_argumentu = &argument;
printf("Premenná argument je uložená na adrese %p a obsahuje hodnotu %d",adresa_argumentu,*adresa_argumentu);
```

### Cvičenie

Skúsme si jednoduchý program na výpočet mocniny čísla s pozrieme sa na
pamäťové adresy, ktoré nám priradí prekladač. Hodnotu pamäťovej adresy
zistíme pomocou operátora `&`. Hodnotu adresy môžeme vypísať v
hexadecimálnom tvare pomocou formátovacieho znaku `%p`.

``` c
int argument = 7;
printf("Premenná argument je uložená na adrese %p.\n",&argument);
```

Výsledok bude podobný:

    Premenná argument je uložená na adrese `0xffffffffef`.

# Funkcia na zápis do premennej

Do teraz sme pracovali iba so symbolickým menom pamäťového miesta a jeho
adresu a veľkosť sme vďaka prekladaču nepotrebovali poznať. V niektorých
prípadoch sa ale bez nich nezaobídeme.

Ak vieme adresu premennej, vieme aj zapisovať aj do samotnej premennej.
To vieme využiť a vytvoriť funkciu, ktorá ako argument prijme adresu
premennej a je schopná do nej zapisovať. Tak obídeme fakt, že hodnota
argumentu funkcie sa zabudne po jej skončení.

Pomocou smerníkovej premennej môžeme definovať taký vstupný argument
(alebo viac argumentov), ktorý sa bude správať ako návratová hodnota.
Program na mocniny môžeme prepísať tak, aby využívali smerníkovú vstupnú
premennú na uloženie výsledku:

Navrhnime si funkciu, ktorá načíta reťazec a premení ho na celé číslo.
Ak bolo načítanie úspešné, funkcia vráti hodnotu nula a výsledok zapíše
do vstupného argumentu. Ak bolo načítanie neúspešné, funkcia vráti
nenulovú hodnotu.

``` c
int nacitaj_cele_cislo(int* vysledok){
   printf("Zadajte celé číslo\n");
   char buffer[BUFSIZE];
   memset(buffer,0,BUFSIZE);
   // Načítanie z klávesnice
   // Premenná stdin je globálna premenná
   // ktorá reprezentuje klávesnicu
   int r = fgets(buffer,BUFSIZE,stdin);
   // Ak sa načítanie nepodarilo
   if (r == NULL){
      printf("Načítanie sa nepodarilo.\n");
      // Funkcia hlási kód chyby
      return 1;
   }
   // Vykonáme konverziu reťazca na celé číslo
   r = sscanf(buffer,"%d",vysledok);
   if (r != 1){
      // Ak sa konverzia nepodarila
      printf("Zadaná hodnota nie je celé číslo.\n");
      // Funkcia hlási kód chyby
      return 2;
   }
   // Funkcia hlási že načítanie sa podarilo
   // Výsledok sa zapísal do premennej vysledok
   return 0;
}
```

Znak `  ` pri argumente nám naznačuje, že funkcia má moc zapísať do
premennej, ktorej adresu odovzdáme. Zápis do pamäťového miesta na ktoré
ukazuje smerníková premenná `adresa_vysledku` sa deje s pomocou
operátora `</emphasis>`, ktorý sme využili na pravej strane výrazu.

Ak vám volanie novej funkcie pripomína funkciu `scanf()`, nie je to
náhoda. Návratová hodnota funkcie `scanf()`, ktorá sa odovzdáva
kopírovaním sa používa na signalizovanie chybového stavu (načítanie do
pamäťového miesta nemuselo prebehnúť v poriadku).

Keď máme hotovú funkciu na načítanie, program Kalkulačka sa stáva oveľa
krajší:

``` c
int main(){
   printf("Súčtová kalkulačka\n");
   int a = 0;
   int b = 0;
   int r = 0;
   r = nacitaj_cele_cislo(&a);
   if (r){
       printf("Chyba načítania\n");
       return 0;
   }
   r = nacitaj_cele_cislo(&b);
   if (r){
       printf("Chyba načítania\n");
       return 0;
   }
   vypis_sucet(a,b);
   return 0;
}
```

## Cvičenie

Modifikujte kalkulačku tak, aby v prípade nesprávneho vstupu vypísala
chybové hlásenie a vypýtala si vstup ešte raz.

## Použitie smerníkovej premennej vo funkcii

Otázka je, či je pri návrhu funkcie lepšie využiť návratovú hodnotu
alebo smerníkový argument. O tom by mal rozhodnúť autor programu tak,
aby funkcia bola dobre čitateľná a efektívna. Ako pomôcku môžeme využiť
tieto pravidlá:

  - ak je výsledkom jediná hodnota, použijeme návratovú hodnotu.

  - Návratová hodnota sa často používa na signalizovanie chybového
    stavu, napr. funkcia vráti hodnotu 0 v prípade, že prebehla v
    poriadku alebo kód chyby ak nastala.

  - V prípade, že funkcia má mať viac návratových hodnôt, použijeme
    smerníkové premenné.

  - Ak je argument funkcie malý, odovzdávame ho klasicky kopírovaním
    pomocou návratovej hodnoty.

  - Ak je argument funkcie veľký, použijeme smerníkovú premennú aby sme
    zjednodušili kopírovanie. Napr. reťazce sa väčšinou odovzdávajú iba
    pomocou smerníka, ktorý označuje začiatok reťazca.

  - Pole vždy odovzdávame pomocou smerníkovej premennej ako adresu jeho
    začiatku.

  - Ak dopredu nevieme, aký veľký bude argument, použijeme smerníkovú
    premennú a premennú s veľkosťou.
