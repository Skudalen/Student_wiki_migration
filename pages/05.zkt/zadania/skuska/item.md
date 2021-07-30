---
title: Skúška
published: true
---

Skúška bude pozostávať z:

- vytvorenie nasadenia webovej aplikácie do verejného klaudu.
- odovzdanie súvisiacich súborov na GIT pred termínom skúšky.
- prezentácie Vášho projektu.
- v zodpovedaní jednej alebo dvoch otázok o to čo ste odovzdali a o tom čo bolo na prednáške.

## Nasadenie webovej aplikácie

Počas skúšky  budete prezentovať webovú aplikáciu nasadenú do prostredia verejného klaudu podľa Vášho výberu.

Môžete využiť tú istú webovú aplikáciu ktorú ste využili počas prvého alebo druhého zadania.

Aplikácia by mala spĺňať tieto podmienky:

- mala by byť verejne prístupná pomocou URL aspoň v čase skúšky.
- aplikácia by mala byť použiteľná v prostredí webového prehliadača.
- nasadenie aplikácie by malo byť opakovateľné pomocou skriptov a konfiguračných súborov.
- nasadenie aplikácie do klaudu by nemalo vyžadovať interakciu s webovým rozhraním. 
- aplikáciu by malo byť ľahké zrušiť pomocou skriptu.
- aplikácia by mala využívať trvalý zväzok, dátové úložisko alebo databázu.
- aplikácia sa by mala automaticky reštartovať v prípade chyby.

## Odovzdanie na GIT

Súvisiace súbory odovzdajte na GIT do adresára `sk1` podobne ako pri zadaniach. Hotovú aplikáciu odovzdajte najneskôr 2 dni pred termínon skúšky. To znamená, že ak je termín v utorok, odovzdajte najneskôr v nedeľu.

- `prepare-app.sh`: skript na prípravu aplikácie a vytvorenie všetkých súvisiacich služieb.
- `remove-app.sh`: zrušenie aplikácie a všetkých súvisiacich služieb..
- iné potrebné súbory, napr. `Dockerfile`,  sql skripty a pod.
- Súbor s dokumentáciou `README.md`.

Dokumentácia nemusí byť dlhá, ale musí byť prehľadná a ľahko čitateľná. 
Gramatika je Vašou vizitkou. 
Do súboru s dokumentáciou uveďte:

- Opis čo robí Vaša aplikácia.
- Opis súborov ktoré ste odovzdali.
- Návod ako si pozrieť aplikáciu na webovom prehliadať.
- Slovný opis použitého verejného klaudu, služieb klaudu, Kubernetes alebo Docker objektov, trvalých zväzkov, databáz ktoré ste využili pri tvorbe nasade nia. 
- Podmienky za akých je možné spustiť skripty `prepare-app.sh` a `remove-app.sh`.

!! Do GITu neposielajte žiadne informácie ktoré by umožňovali zneužiť Vaše konto. 

## Prezentácia

Priebeh obhajoby spolu  max 7 min.:

1. Prezentácia (max. 4 min., max. 5 slajdov) - Vaše meno, názov predmetu,rok,  názov zadania. V prezentácii využite informácie ktoré ste zapísali do súboru `README.md`. Prezentácia by mala obsahovať:

  1. predstavenie Vašej aplikácie - čo vie urobiť a pre koho je určená. Aplikácia by mala byť verejne prístupná v deň skúšky. V prezentácii uveďte URL a prihlasovacie údaje kde je možné aplikáciu vyskúšať.
  2. predstavenie Kubernetes objektov, Docker kontajnerov aplikácie a služieb verejného klaudu ktoré ste využili.
  3. Pracovný postup pri vytvorení nasadenia  aplikácie do verejného klaudu.

2. Jedna alebo dve otázky týkajúce sa toho čo ste odovzdali a toho čo zaznelo na prednáškach  (cca 2 min) a Vaše odpovede.

## Hodnotenie

Maximálne 60 bodov. 

Hodnotí sa to, čo bolo odovzdané,  ako to bolo prezentované  a ako boli zodpovedané otázky. Plné hodnotenie získa:
    
- pekná, stručná a výstižná, pútavo a zrozumiteľne vysvetlená prezentácia.
- dôsledne pripravená a správne nasadená aplikácia.
- pohotová a správna odpoveď na položené otázky.
- použitie Kubernetes je výhodou.

