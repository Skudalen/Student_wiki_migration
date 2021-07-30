---
title: Title
---
## Ovocie a Zelenia "ANINELEZ"

Pomôžte pracovníkom v školskom bufete.

## Odovzdanie

- názov `usaa19cv9`
- heslo `expert`
- odovzdanie cez [GIT](https://git.kemt.fei.tuke.sk)
- za 4 body
- hodnotenie systémom [Traktor](https://traktor.kemt.fei.tuke.sk).

Automatické hodnotenie pomocou kontroly vstupov a výstupov programu.

Odovzdávanie do súboru `program.c`.

## Ciele

- Práca s jednoduchým znalostným systémom.
- Práca s nevyváženým vyhľadávacím stromom.
- Prechádzanie binárneho stromu spôsobom preorder a postorder.

## Úvod 

Je to ovocie alebo zelenina? Nad touto otázkou si lámali hlavu celé generácie
najlepších mozgov z celého sveta. Vedenie Technickej univerzity si v nasledovnej päťročnici naplánovalo
vyskúmať konečnú odpoveď na problém klasifikácie tovaru v oddelení Ovocia a zeleniny
v sklade Študentských domovoch a jedální.
Nový spôsob rozdelenia tovaru bude vyskúšaný v novom bufete "Aninelez" (pravdepodobne v budove TaHni-Com).

Pri identifkácii tovaru pomôže pracovníkom bufetu Váš automatický dialógový systém, a.k.a chatbot.
Je dôležité, aby výsledok bol čo najlepší, pretože
konkurzu na túto pozíciu v novom bufete sa môžete zúčastniť aj VY!

## Binárny vyhľadávací strom

Binárne stromy sú zovšeobecnenie spojkových zoznamov.
Každý uzol binárneho vyhľadávacieho stromu má namiesto jedného smerníka na ďalší prvok až dva smerníky.
Vďaka tomu je vhodný na reprezentáciu informácií ktoré majú hierarchický charakter - napr. sada otázok v znalostnom systéme. 

V binárnom vyhľadávacom strome poznáme dva druhy uzlov: vnútorný (nelistový) uzol a listový uzol.   
Listový uzol je taký, ktorý neobsahuje odkazy na žiadne ďalšie uzly. Vnútorný uzol obsahuje odkazy na iné listové alebo nelistové uzly.
V našom znalostnom systéme sú nelistové uzly otázky a listové uzly odpovede.

```c
struct tree {
   // Otázka aleo odpoveď
   char value[SIZE];
   // Odpoveď áno
   struct tree* left;
   // Odpoveď nie
   struct tree* right;
};
```

Smerníky `left` alebo `right` hovoria, čo má chatbot radiť ak používateľ odpovie na otázku áno (left) alebo nie (right).
Základnú otázku výskumu si uložíme listový uzol do koreňového uzlu binárneho stromu klasickým spôsobom. Ak sú oba smerníky nulové, ide o listový uzol.

```c
struct tree* chatbot = calloc(1,sizeof(struct tree));
strcpy(chatbot->value,"Je to ovocie alebo zelenina?");
```

Do ľavého a do pravého podstromu si môžme uložiť ďalšie orázky alebo odpovede.  Ak chceme rozlišovať medzi dvoma druhmi ovocia a zeleniny,
poznačíme si ich do listových uzlov a tie napojme na koreňový uzol. Takto zmeníme listový uzol na vnútorný a na otázku napojíme odpovede.

```c
struct tree* mrkva = calloc(1,sizeof(struct tree));
strcpy(mrkva->value,"*Mrkva");
struct tree* jablko = calloc(1,sizeof(struct tree));
strcpy(mrkva->value,"*Jablko");

chatbot->left = jablko;
chatbot->right = mrkva;
```

Ak chceme rozlišovať medzi troma druhmi ovocia alebo zeleniny, musíme na vhodné miesto vložiť ďalšiu ozázku:

```c
struct tree* mrkva = calloc(1,sizeof(struct tree));
strcpy(mrkva->value,"*Mrkva");
struct tree* kalerab = calloc(1,sizeof(struct tree));
strcpy(mrkva->value,"*Kalerab");
struct tree* jablko = calloc(1,sizeof(struct tree));
strcpy(mrkva->value,"*Jablko");
struct tree* zelena = calloc(1,sizeof(struct tree));
strcpy(zelena->value,"Je zelenej farby?");

chatbot->left = jablko;
chatbot->right = zelena;
zelena->left = kalerab;
zelena->right = mrkva;
```

Samozrejme, je nepraktické binárny strom vytvárať takto. Na vytváranie aj na prechádzanie binárneho stromu si navrhneme funkcie, podobne ako 
pri spojkovom zozname, napr. 

```
struct tree* add(struct tree* root,const char* data);
```

## Úloha

# Mudrc zo supermarketu

Vašou úlohou bude naprogramovať chatbota, ktorý pomôže budúcim
zamestancom bufetu pri rozlišovaní druhov tovaru.
pomocou série otázok. 
Báza znalostí sa skladá z otázok typu áno a nie a odpovedí.

Systém najprv načíta bázu otázok a odpovedí. Každá otázka alebo odpoveď sa nachádza na práve jednom riadku. Odpovede sú vyznačené hviezdičkou na začiatku riadka.
Po otázke na najprv nasleduje načítanie ďalšieho kroku áno a potom kroku nie.
Každý krok znalostného systému je alebo odpoveď alebo ďalšia otázka.
Báza pravidiel je ukončená prázdnym riadkom.

Otázky a odpovede spolu tvoria binárny vyhľadávací strom zapísaný vo formáte pre-order.

Príklad bázy pravidiel s dvoma otázkami a troma druhmi tovaru:

    Rastie to na strome (a/n) ?
    *Jablko
    Rastie to pod zemou (a/n) ?
    *Mrkva
    *Šalát


Po načítaní bázy pravidiel vypíšte počet tovarov v báze pravidiel.
V prípade, že sa nedá správne načítať báza pravidiel vypíšte chybové hlásenie.

Ak sa bázu pravidiel podarilo načítať, spustite znalostný systém prvou otázkou.
Spustenie znalostného systému znamená jeho rekurzívne prechádzanie typu preorder od koreňového uzla.
Pri prechádzaní najprv zobrazte otázku alebo odpoveď ktorá sa nachádza v aktuálnom uzle.
Ďalšie otázky alebo odpovede zobrazujte podľa toho, či používateľ odpovedá `a` pre prvú
možnosť  alebo `n` pre druhú. Ak systém nájde odpoveď, vypíšte správu a skončite program.
Ak používateľ zadá nesprávny vstup, vypíšte správu a skončite program.

Príklad vstupu:

	Je to ovocie alebo zelenina (a/n) ?
	*Jablko
	*Mrkva

	n


Príklad výstupu:

	MUDrC to vie.
	Pozna 2 druhov ovocia a zeleniny.
	Odpovedajte 'a' alebo 'n'
	Je to ovocie alebo zelenina (a/n) ?
	*Mrkva
	Koniec




## Budete potrebovať

Budete potrebovať ovládať základy spojkových zoznamov.
Inak nebudete potrebovať žiadne špeciálne knižnice, len štandardné na:

- prácu s reťazcami 
- prácu so vstupom a výstupom
- prácu s pamäťou

## Ako na to

Na návrh a implementáciu znalostného systému, ktorý bude vedieť odpovedať na otázky typu áno a nie je vhodný binárny vyhľadávací stom. 
Na uloženie jednej položky databázy budete potrebovať tieto položky:

- Znenie otázky alebo odpovede
- Smerník na odpoveď áno
- Smerník na odpoveď nie

V prípade, že sú smerníky na áno a nie nulové, uzol je listový a naznačuje konečnú odpoveď znalostného systému.

## Načítanie bázy pravidiel súboru do binárneho stromu

Vzorovú znalostnú databázu vieme zapísať do textového súboru takto:

    Je to zelenina (a) alebo ovocie (n) ?
    Rastie to nad zemou (a) alebo pod zemou (n) ?
    Je to červené (a/n) ?
    * Paradajka.
    Dáva sa to do polievky (a/n) ?
    Je to biele (a/n) ?
    * Kaleráb
    * Karfiol
    * Šalát
    Dáva sa to do polievky (a/n) ?
    Je to biele (a/n) ?
    * Petržlen
    * Mrkva
    * Arašid
    Pestuje sa na Slovensku (a/n) ?
    Rastie na strome (a/n)?
    Má pevnú šupku (a/n) ?
    * Moruša
    * Orech
    * Jahoda
    Je to citrus (a/n) ?
    * Pomaranč
    * Banán

Takto zapísanú databázu vieme načítať do binárneho vyhľadávacieho stromu.
Použivame prefixovú notáciu:

1. Najprv načítame hodnotu. (Názov otázky alebo ovocia). Prípade, že sa názov začína na '*', tak je uzol listový a potomkov ďalej nemusíme načítavať.
1. Potom načítame ľavý uzol, ktorý zodpovedá odpovedi áno.
1. Potom potom načítame pravý uzol (Odpoveď nie).

Výsledný binárny strom môže vyzerať takto (zobrazené vo forme vnoreného zoznamu):

	Je to zelenina (a) alebo ovocie (n) ?
	   a- Rastie to nad zemou (a) alebo pod zemou (n) ?
	      a - Je to červené (a/n) ?
		 a- * Paradajka.
		 n- Dáva sa to do polievky (a/n) ?
		    a- Je to biele ?
		       a- * Kaleráb 
		       n- * Karfiol
		    n- * Šalát
	      n- Dáva sa to do polievky (a/n) ?
		 a- Je to biele?
		    a- * Petržlen
		    n- * Mrkva
		 n- * Arašid
	   n- Pestuje sa na Slovensku (a/n) ?
	      a -Rastie na strome (a/n) ?
		 a- Má pevnú šupku (a/n) ?
		    a- * Jablko
		    n- * Kokos
		 n- * Moruša
	      n- Je to citrus (a/n)?
		 a- * Pomaranč
		 n- * Banán

Najprv si vytvorte funkciu, ktorá načíta bázu pravidiel s jednou otázkou.


```c
struct tree* read_tree(){
    char buffer[SIZE];
    memset(buffer,0,SIZE);
    char* r = fgets(buffer,SIZE,stdin);
    assert(r);
    struct tree* node = calloc(1,sizeof(struct tree));
    memcpy(node->value,buffer,SIZE);
    return node;
}
```

Nezabudnite dynamicky alokovanú pamäť uvoľniť:

```c
void destroy_tree(struct tree* tree){
    free(tree);
}
```

Ďalej si skúste funkciu pre vytvorenie stromu zovšeobecniť tak, aby načítala ľubovoľnú databázu.
Načítavať sa bude podľa pravidiel preorder, teda najprv ide otázka, potom odpoveď áno a potom nie.
Môžete to navrhnúť ako rekurzívnu funkciu. Využijeme fakt, že načítať jeden riadok už vieme.

Ak sa riadok začíta symbolom `*`, nebude potrebné načítať ďalšie otázky na nižšej úrovni.
V prípade, že sa riadok nezačína symbolom `*`, rekurzívne načíta ľavého
a pravého syna, ktoré sa nachádzajú na ďalších riadkoch.
Ľavý syn bude obsahovať, to čo sa má diať po odpovedi "áno", pravý syn bude
obsahovať to, čo sa bude diať po odpovedi "nie".

Upravte aj funkciu pre uvoľnenie pamäte tak aby uvoľnila celý binárny strom.
Inšpirujte sa funkciou pre uvoľnenie spojkového zoznamu. 

Pri ladení môžte využiť aj rekurzívnu funkciu pre vizualizáciu binárneho stromu:

```c
void print_tree(struct node* tree,int offset){
    for (int i = 0; i < offset; i++){
        printf(" ");
    }
    printf("%s",tree->question);
    if (tree->left){
        print_tree(tree->left,offset +3);
        print_tree(tree->right,offset +3);
    }
}
```

Táto funkcia zároveň demonštruje preorder prechádzanie binárneho stromu ktoré využijete pri načítaní.
Najprv sa vypíše otázka alebo odpoveď a ak existujú podstromy, tak výpis rekurzívne pokračuje na ľavý a pravý podstrom.

## Vyutvorte funkcie pre spočítanie listových a nelistových uzlov

Spočítať uzly v strome môžme rekurzívne alebo iteratívne.

Ak sa rozhodneme pre iteratívny spôsob, vytvoríme si pomocný smerník na aktuálny uzol a ten potom posuňme ďalej podľa zvolených pravidiel 
prechádzania.

Ak je si zvolíme spôsob inorder, potom ak existuje, navštívime najprv ľavého syna. Potom vyhodnotíme hodnotu a nakoniec, ak existuje, navštívime 
pravého syna:

```c
// TODO - vyskúšať
int counter = 0;
int si = 0;
struct tree* stack[SIZE];
struct tree* this = tree;
while (si >= 0){
    assert(si < SIZE);
    if (this->left){
       stack[si++] = this;
       this = this->left;
       continue;
    }
    counter += 1;
    if (this->right){
       stack[si++] = this;
       this = this->right;
       continue;
    }
    si = si -1;
}
```

## 3. Spustenie znalostného systému

Keď budete mať znalostný systém v pamäti, môžete.ho vyskúšať.
Beh znalostného systému je rovnaky ako preorder prechádzanie binárneho vyhľadávacieho  stromu.

Najprv zobrazte otázku alebo odpoveď, ktorá je uložená ako hodnota uzla. V prípade, že uzol nemá potomkov, skončite program.
V prípade, že uzol má potomkov, zobrazte výzvu na zadanie odpovede áno alebo nie.
Ak bola odpoveď áno, rekurzívne pokračujete ľavým potomkov, v prípade, že odpoveď bola nie pokračujte pravým potomkov.
Ak odpoveď bola niečo iné , zobrazte chybové hlásenie a ukončite program.

Príklad funkčnosti programu:

    Program MUDrC.
    Načítaných 23 pravidiel.
    Odpovedajte na otázky a alebo n.
    Je to zelenina (a) alebo ovocie (n) ?
    a
    Rastie to nad zemou (a) alebo pod zemou (n) ?
    n
    Dáva sa to do polievky (a/n) ?
    n
    Arašid


