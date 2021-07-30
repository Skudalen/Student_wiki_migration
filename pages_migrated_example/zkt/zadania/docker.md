---
title: Zadanie 1
published: true
date: 8.3.2021
---

### Úloha 

Nasaďte s pomocou aplikačných kontajnerov Docker kompletnú webovú aplikáciu pomocou systému Docker skladajúcu sa minimálne z dvoch služieb a minimálne jedného trvalého zväzku.

Pre každú službu webovej aplikácie by malo platiť:

- počúva na svojom porte,
- beží vo vlastnom Docker kontajneri,
- dokáže komunikovať s ostatnými službami ktoré potrebuje.

Minimálne jedna služba by mala udržiavať svoj stav pomocou trvalého zväzku.

Pre návrh služby môžete využiť existujúci obraz v registri Docker Hub, napr. databázu alebo webový server. Ak chcete, môžete zostaviť vlastné obrazy. Služby nakonfigurujte pomocou konfiguračných súborov, argumentov pri spustení alebo premenných prostredia.

### Súbory na odovzdanie

Súčasťou odovzdania by mal byť:

- skript pre prípravu aplikácie nazvaný  `prepare-app.sh`. V skripte `prepare-app.sh` uveďte docker príkazy potrebné pre zostavenie obrazov a vytvorenie konfigurácií, sietí, vytvorenie a inicializáciu  pomenovaných zväzkov.
- bash skript pre štart nazvaný `start-app.sh`. Do skriptu `start-app.sh` napíšte príkazy pre systém docker na spustenie a konfiguráciu všetkých kontajnerov služieb webovej aplikácie.  Kontajnery nakonfigurujte tak, aby sa spustili znovu v prípade poruchy. Vypíšte správu na ktorom porte sa môžem pripojiť na aplikáciu pomocou webového prehliadača.
- bash skript pre koniec nazvaný `stop-app.sh`. Do skriptu `stop-app.sh` napíšte príkazy na zastavenie všetkých služieb. Pozastavenie aplikácie a jej opätovné spustenie by nemalo spôsobiť reset do východzieho stavu ani v prípade, že sa zmení konfigurácia aplikácie. 
- skript pre odstránenie všetkých stôp po vytvorenej aplikácii `remove-app.sh`.  Skript by mal odstrániť všetko čo sa vytvorilo v skripte `prepare-app.sh`.
- Ak chcete, môžete na nasadenie použiť systém docker-compose alebo "docker swarm mode". V tom prípade konfiguráciu aplikácie uložte do súboru `docker-compose.yaml`.
'
- Súbor s dokumentáciou `README.md`.

### Dokumentácia

Do súboru s dokumentáciou uveďte:

- Podmienky na nasadenie a spustenie Vašej aplikácie - podrobný zoznam potrebného softvéru.
- Opis čo robí Vaša aplikácia.
- Opis virtuálnych sietí a pomenovaných zväzkov ktoré aplikácia využíva.
- Opis konfigurácie kontajnerov ktorú ste vykonali.
- Zoznam použitých kontajnerov a ich stručný opis.
- Návod ako pripraviť, spustiť, pozastaviť a vymazať aplikáciu.
- Návod ako si pozrieť aplikáciu na webovom prehliadať.

### Príklad práce s aplikáciou

Práca sa aplikáciou by mohla vyzerať takto:

```
# Vytvorím všetko ptrebné pre aplikáciu
./prepare-app.sh
Preparing app...
# Spustím aplikáciu
./start-app.sh
Running app ...
The app is available at http://localhost:5000
# Otvorím webový prehliadač a pracujem s aplikáciou.
# Pozastavím aplikáciu
./stop-app.sh
Stopping app...
# Vymažem všetko čo súvisí s aplikáciou
./remove-app.sh
Removed app.
```

Predpokladajte, že skripty budú vykonávané na počítači s nainštalovaným systémom Linux a  nakonfigurovaným príkazom `docker`.

### Odovzdanie

Vytvorte si prázdny repozitár s názvom zkt21 na katedrovom [GITe](https://git.kemt.fei.tuke.sk).
Súbory aplikácie odovzdajte do repozitára do adresára `z1`.

Po odobzdaní skontrolujte, či sú odovzdané súbory v poriadku pomocou [systému Traktor](https://traktor.kemt.fei.tuke.sk/#submit/146) a ťuknite na "Pozri na GIT". Heslo na vstup to predmetu je "zkt21". Termín na odovzdanie je 4.4.2021.

### Hodnotenie

Zadanie bude hodnotené osobne. Slovné hodnotenie zapíšem do systému Traktor.

Pri hodnotení sa budem sústrediť na tieto oblasti:

- Použiteľnosť: Sú dodané skripty spustiteľné bez chýb? 
- Kompletnosť: Spĺňajú odovzdané súbory podmienky uvedené v zadaní?
- Funkčnosť: Funguje webová aplikácia bez problémov?
- Dokumentácia: Je dokumentácia kompletná a pravdivá?
- Úprava: Je dokumentácia ľahko čitateľná? Sú skripty prehľadné?
- Originalita: V odovzdaných súboroch by mal byť jasný Váš osobný vklad. V prípade že sa inšpirujete existujúcim riešením, tak uveďte zdroj.

