# Posledná hra

Vytvorte a prezentujte Vašu vlastnú hru v textovo-grafickom rozhraní. Pri návrhu, môže využívať knižnicu ["svet"](https://github.com/hladek/world).

### Priebeh prezentácie
 
Prezentácia bude prebiehať vo forme telekonferencie. Váš výtvor predstavíte cvičiacim a kolegom.

- Stručne predstavte hru (cca 2 min.). Môžete použiť krátku prezentáciu (2 alebo 3 slajdy).
- Ukážte ako sa hra hrá (max. 2 min.). Ukážka môže byť vo forme videa z obrazovky.
- Zodpovedajte otázky publika alebo cvičiaceho. (max. 2 min.).

### Podmienky 

Váš návrh musí obsahovať:

- Definíciu štruktúry pre stav hry.
- Načítanie stlačenej klávesy.
- Minimálne jednu funkciu, ktorá modifikuje stav hry podľa stlačenej klávesy.
- Minimálne 3 funkcie, ktoré modifikujú stav hry.
- Funkcia pre vykreslenie stavu hry.
- Hra musí využívať knižnicu curses. Táto podmienka je splnená ak používate knižnicu "svet".
- Funkčný súbor Makefile. Hra sa musí dať preložiť na servri 'omega' príkazom 'make'.


### Hodnotenie

Hodnotí sa:

- Zaujímavý a originálny nápad 10b.
- Funkčnosť a hrateľnosť 10b.
- Prezentácia hry 10b.

### Vypracovanie

Najprv musíte hru vymyslieť. Nápad môže byť Váš, alebo sa inšpirujte niektorou klasickou hrou. Hra vôbec nemusí byť komplexná.
stačí že bude zábavná.

Vyhľadajte si klasické hry a môžete sa aj ich zahrať. 

- Piškvorky
- 2048
- Sokoban
- Pong
- Arkanoid
- Tetris
- Space Invaders
- Asteroids
- Nethack
- Scrabble
- Krížovka
- Sudoku
- John Conway's Game of Life
- Supaplex
- Mandelbrot Generator
- Night Driver

Stiahnite si knižnicu Svet a doprogramujte Vašu hru do súborov `game.h` a `game.c`.
Do hlavičkového súboru napíšte štruktúru ktorá vyjadruje stav Vašej hry a predpisy funkcií. Do súboru `game.c` doplňte funkcie pre modifikáciu stavy podľa stlačenej klávesy a pre vykreslenie stavu na obrazovku.

### Odovzdanie

Všetky súbory odovzdajte do Vášho GIT repozitára do adresára`final`.
Hodnotenie bude osobné, ale prosím zaznačte odovzdanie "Finálneho zadania" cez systém Traktor. Termín na odovzdanie je do 22.5.

Je dôležité aby ste odovzdali všetky súbory aby sa hra dala preložiť a vyskúšať.
