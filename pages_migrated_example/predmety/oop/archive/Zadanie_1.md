# Zadania

# Zadanie_1

(20 bodov, odovzdanie - 9. týždeň)

(Nič ľahšie ako) STVORENIE SVETA

Vytvorte triedu Planeta, ktorá bude reprezentovať planétu slnečnej sústavy. Každá planéta má meno, nejakú hmotnosť, priemer, vzdialenosť od slnka. Po vytvorení, nech planéta stojí (netočí sa). Vytvorte v planéte metódu, ktorá bude realizovať točenie sa planéty okolo svojej osi a okolo zeme. Vytvorte v triede Planeta, členskú premennú, ktorá bude indikovať stav planéty (či sa točí alebo nie). 

Vytvorte abstraktnú triedu Cicavec, ktorá bude obsahovať abstraktné metódy cicat() a pohybovatsa(). Trieda nech má parametrický konštruktor s parametrom meno typu String. V rámci konštruktora nech sa volá privátna metóda Cicavca naroditsa(), ktorá zabezpečí narodenie daného cicavca. 

Vytvorte rozhranie Restartable, ktoré umožní objektom tried, ktoré ho implementujú sa reštartovať. Do rozhrania Restartable vložte abstraktnú metódu restart().

Vytvorte triedu Clovek, ktorá bude dediť z abstraktnej triedy Cicavec. Trieda Clovek nech implementuje rozhranie Restartable. 

Človek je definovaný mnohými atribútmi. Vytvorte pre človeka aspoň 5 členských premenných, ktoré budú uchovávať jeho vlastnosti (pohlavie, farbu vlasov, očí a pod).

Pridajte do triedy Clovek členskú premennú, ktorá bude indikovať či spí alebo je hore. 

Človek má okrem cicania a hýbania, veľké množstvo ďalších dôležitých schopností. Implementujte aspoň 5 z nich. Okrem toho implementujte metódy zobuditsa(), a zaspat(). 

Imlementujte do triedy Clovek metodu rozpravat(), ktorá vypíše text, ktorý metóda príjme ako argument funkcie.

V main() funkcii svojho programu, spustite “virtualny zivot”. Urobte to nasledovne:
1.	VyStvorte planétu s názvom ZEM. 
2.	Stvorte Adama
3.	Nech Adam zaspí.
4.	Stvorte Evu
5.	Zobuďte Adama.
6.	Vytvorte pomocou metody rozpravat kratku konverzaciu medzi Adamom a Evou (obsah je na vás – vidia sa prvýkrát v živote).
7.	Dajte Adama a Evu spat. 


# Zadanie_2

Ako začínajúci stvoritelia, sme sa pustili do vytvárania sveta a ľudí veľmi hŕŕŕ. Teraz nastal čas v tom trošku poupratovať ( a nemyslite hneď na potopu!) 
Planéta Zem, ktorú ste stvorili sa momentálne nachádza vo vzduchoprázdne. Trošku sme zabudli stvoriť vesmír (to sa začínajúcim stvoriteľom, niekedy stáva). 

## Úloha 1: 
Vytvorte triedu Vesmír a z nej nový objekt vesmíru, ktorý bude obsahovať zoznam všetkých planét. Planétu Zem, ktorú ste vytvorili zaraďte do tohto zoznamu.  
Ďalší veľký problém, ktorý sme spôsobili je, že Adam a Eva, ktorých ste stvorili, v skutočnosti nežijú na planéte Zem, ale sú taktiež v nejakom vzduchoprázdne. A teda ďalšou vašou úlohou bude dostať ich nohami pevne na zem 😊 . 
Poďme to ale urobiť trošku sofistikovanejšie. 

## Úloha 2: 
Keďže predpokladáme, že Adam a Eva nebudú poslední a jediní obyvatelia planéty Zem, vytvorte v rámci triedy Planéta aj nejaký zoznam (pomocou kolekcií), ktorý bude obsahovať všetkých obyvateľov (typu Clovek), ktorí budú žiť na vašej planéte. Nezabudnite na to, že budeme potrebovať, aby do tohto zoznamu bezproblémovo pribúdali nový ľudia a tiež aby bolo možné ich z daného zoznamu odstrániť. Nie je teda možné použiť jednoduché statické polia. Nezabudnite Adama a Evu pridať do vytvoreného zoznamu. 
Aby sa nám s ľuďmi pracovalo ľahšie, preťažte metódu toString v triede Clovek tak, aby vracala meno a prezvisko každého človeka. 

## Úloha 3: 
Vieme, že na planéte neustále pribúdajú noví ľudia. Keďže čas je drahý, vytvorte pomocou sľučky for cyklus, v ktorom vznikne aspoň desať tisíc nových ľudí. (Prezradím vám tajomstvo – aby ste to mohli urobiť, musíte vytvoriť v triede Clovek taký konstruktor, ktorý bude nastavovať iba členské premenné, ktoré sú rovnaké pre všetkých ľudí – tak budete schopný produkovať „anonymných“ ľudí masovo)

Splnením úlohy č.3 sme si narobili množstvo problémov. V prvom rade, na vašej zemi sa stupňuje hlad. Ľudia, ktorých ste stvorili začínajú byť hladní. Je najvyšší čas riešiť tento pálčivý problém. 
Opäť to ale treba riešiť nejako inteligentne. Aby ste sa vy ako stvoriteľ nemuseli celý „život“ venovať iba „kŕmeniu svojich ľudí“, musíte ich naučiť ako si jedlo dopestujú sami. 

## Úloha 4: 
Naučme ľudí dopestovať jedlo. 

4.1. Vytvorte rozhranie sadable 😊 (od slova sadiť, ktoré bude definovať tri funkcie – zasadit(), rast() – od slova rásť, a pozbierat().

4.2. Vytvorte triedy pre najužitočnejšie plodiny, ktoré sa dajú zasadiť, napr. triedu Zemiak, Kapusta, Cibuľa, Mrkva, Petržlen. Všetky tieto triedy nech implementujú rozhranie sadable. 

4.3. V main funkcii programu, potom, čo ste vytvorili desať tisíc nových ľudí, vytvorte pomocou statických polí nasledujúce polia: 

- Vedrobandur – pole objektov triedy Zemiak o veľkosti 1000 zemiakov (mohlo by stačiť)
- Mechkapusty – pole objektov triedy Kapusta o veľkosti 1000 kapust
- MechCibule – pole objektov triedy Cibula o veľkosti 500 cibúľ
- SemienkaMrkvy – pole objekov triedy Mrkva o veľkosti 5000 semiačok.
- SemienkaPetrzlenu – pole objektov triedy Petrzlen o veľkosti 5000 semiačok. 

4.4.Teraz si spravte prestávku a dajte si kávu/čaj/štamperlik/čokoládu, alebo aj všetko naraz podľa vlastného uváženia. Opakujte podľa potreby. 
4.5. Okej, posilnení, môžeme pokračovať. Vytvorte generickú triedu PESTOVANIE, pomocou ktorej sa budú dať pestovať akékoľvek plodiny. Aby bolo možné v rámci triedy volať funkcie zasadit(), rast() a pozbierat(), musíte použiť nasledujúcu deklaraciu triedy: 

	public class PESTOVANIE<Type extends sadable> {
    

4.6. V triede PESTOVANIE použite typovú premennú Type na vytvorenie poľa sadenicka, ktoré bude uchovávať pole plodín, s ktorým sa bude na danej brigáde pracovať.  

4.7. V rámci triedy PESTOVANIE vytvorte členskú metódu saditPlodinu(), ktorá bude v sľučke for sadiť plodiny, ktoré máte uložené v jednotlivých poliach (vedrobandur, mechkapusty, ...). To znamená, že pre každý zemiak z vedrabandur sa zavolá funckia zasadit().

4.8. V triede PESTOVANIE obdobným spôsobom vytvorte členskú metódu rastPlodin(), v ktorych bude volana funkcia rast() nad každou plodinou.

4.9. V triede PESTOVANIE obdobným spôsobom vytvorte členskú metódu zberPlodin(), v ktorej bude volaná funkcia pozbierat() nad každou plodinou.


## Úloha 5: 
V main funkcii vytvorte objekty triedy PESTOVANIE pre každé pole plodín. Budete teda potrebovať vytvoriť objekty: pestovaniezemiakov, pestovaniekapusty, pestovaniecibule, pestovaniemrkvy a pestovaniepetrzlenu. Bude sa jednať o objekty triedy PESTOVANIE, ktoré budú realizovať pestovanie jednotlivých plodín. Bude to vyzerať asi takto: 

	PESTOVANIE<ZEMIAK> pestovaniezemiakov= new PESTOVANIE<>(vedrobandur);
	pestovaniezemiakov.saditPlodinu();
	pestovaniezemiakov.rastPlodin();
	pestovaniezemiakov.zberPlodin();


Vypestujte teda všetky vytvorené plodiny. 

## Úloha 6: 
Aj v úlohe 5 sme urobili logické chyby. Trieda PESTOVANIE je síce pekná, ale chýba nám niekto, kto by ju realizoval. A mal byt o byť objekt triedy Clovek, teda nejaký človek. Taktiež, sadenie a zber plodín, by mali byť skôr členské funkcie triedy človek. Popremýšľajte ako to všetko urobiť viac logickejšie. (Splnenie tejto úlohy Vám môže priniesť bonusové body ku skúške). 

## Rady na záver: 
1.	Nezúfajte.
2.	Na prednáške sme tieto veci implemenovali.
3.	Ak si s niečím neviete rady, poraďte sa s najvyšším, v našom prípade s Googlom
4.	Nezúfajte! 😊 
