---
title: Zadanie 2 - Kubernetes
published: true
---
Vytvorte a prezentujte nasadenie webovej aplikácie do systému Kubernetes. 
Webová aplikácia by mala byť funkčná. Môžete použiť a upraviť zadanie č. 1.
Zadanie prejde kontrolou originality.

Riešenie by malo obsahovať: 

- aspoň jeden funkčný objekt typu `Namespace`. Všetky ostatné vytvorené objekty musia patriť do tohoto menného priestoru.
- aspoň jeden funkčný objekt typu `Deployment`.
- aspoň jeden funkčný objekt typu `StatefulSet`. Tento objekt si vyžaduje aj objekt `PersistentVolume` a `PersistentVolumeClaim`.
- aspoň jeden funkčný objekt typu `Service`.

Zadanie musí obsahovať aspoň tieto súbory:

- bash skript pre štart nazvaný `start-app.sh`. Do skriptu `start-app.sh` napíšte príkazy pre `kubectl` na vytvorenie všetkých Kubernetes objektov. Skript predpokladá nakonfigurovaný a funkčný  príkaz `kubectl`.
- bash skript pre koniec nazvaný `stop-app.sh`. Do skriptu `stop-app.sh` napíšte príkazy na zrušenie vytvorených Kubernetes objektov. 
'
- `deployment.yaml`: konfiguračný súbor pre objekt typu `Deployment`.
- `service.yaml`: konfiguračný súbor pre objekt typu `Service`
- `prepare-app.sh`: skript na prípravu aplikácie, zostavenie obrazov a vytvorenie trvalých zväzkov.
- `statefulset.yaml`: konfiguračný súbor pre objekty typu `StatefulSet`, `PersistentVolumeClaim` a `PersistentVolume`.
- iné potrebné súbory, napr. `Dockerfile`,  sql skripty a pod.
- Súbor s dokumentáciou `README.md`.

Do súboru s dokumentáciou uveďte:

- Opis čo robí Vaša aplikácia.
- Zoznam použitých kontajnerov a ich stručný opis.
- Zoznam Kubernetes objektov a ich stručný opis.
- Opis virtuálnych sietí a pomenovaných zväzkov ktoré aplikácia využíva.
- Opis konfigurácie kontajnerov ktorú ste vykonali.
- Návod ako pripraviť, spustiť, pozastaviť a vymazať aplikáciu.
- Návod ako si pozrieť aplikáciu na webovom prehliadať.


### Odovzdanie

Súbory aplikácie odovzdajte do repozitára `zkt21` do adresára `z2`.

Po odovzdaní skontrolujte, či sú odovzdané súbory v poriadku pomocou [systému Traktor](https://traktor.kemt.fei.tuke.sk/#submit/150) a ťuknite na "Pozri na GIT". Heslo na vstup to predmetu je "zkt21". Termín na odovzdanie je 18.4.2021.

### Hodnotenie

Zadanie bude hodnotené osobne. Slovné hodnotenie zapíšem do systému Traktor.
Buďte pripravení odpovedať na otázky týkajúce sa obsahu odovzdaných súborov.

Pri hodnotení sa budem sústrediť na tieto oblasti:

- Použiteľnosť: Sú dodané skripty spustiteľné bez chýb? 
- Kompletnosť: Spĺňajú odovzdané súbory podmienky uvedené v zadaní?
- Funkčnosť: Funguje webová aplikácia bez problémov?
- Dokumentácia: Je dokumentácia kompletná a pravdivá?
- Úprava: Je dokumentácia ľahko čitateľná? Sú skripty prehľadné?
- Originalita: V odovzdaných súboroch by mal byť jasný Váš osobný vklad. V prípade že sa inšpirujete existujúcim riešením, tak uveďte zdroj.

