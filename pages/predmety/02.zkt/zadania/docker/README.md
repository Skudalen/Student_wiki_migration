# Zadanie 1

Nasaďte na Docker Machine kompletnú webovú aplikáciu pomocou systému Docker skladajúcu sa minimálne z dvoch služieb.

Pre každú službu webovej aplikácie by malo platiť:

- počúva na svojom porte,
- beží vo vlastnom Docker kontajneri,
- dokáže komunikovať s ostatnými službami ktoré potrebuje.

Pre návrh služby môžete využiť existujúci obraz v registri Docker Hub, napr. databázu alebo webový server. Ak chcete, môžeteč zostaviť vlastné obrazy. Službu nakonfigurujte pomocou konfiguračných súborov, argumentov pri spustení alebo premenných prostredia.

Súčasťou odovzdania by mal byť:

- bash skript pre štart nazvaný `start-app.sh`. Do skriptu `start-app.sh` napíšte príkazy pre systém docker na spustenie a konfiguráciu všetkých kontajnerov služieb webovej aplikácie.  Kontajnery nakonfigurujte tak, aby sa spustili znovu v prípade poruchy.
- bash skript pre koniec nazvaný `end-app.sh`. Do skriptu `end-app.sh` napíšte príkazy na zastavenie všetkých služieb.
- ak je to potrebné, pridajte aj skript pre zostavenie aplikácie nazvaný  `prepare-app.sh`. v skripte `prepare-app.sh` uveďte docker príkazy potrebné pre zostavenie obrazov a vytvorenie konfigurácií, sietí, vytvorenie a inicializáciu  pomenovaných zväzkov.
- Súbor s dokumentáciou `README.md`  kde vymenujete zoznam komponentov a uvediete odkaz ako aplikáciu po štarte zobraziť vo webovom prehliadači.


