---
title: Pracovné prostredie
---

Na absolvovanie tohoto predmetu odporúčame tieto nástroje:

Vývojové nástroje:
- Prekladač: `gcc`
- Systém na zostavenie: `make`

Nástroje na ladenie:
- Debugger: `gdb`
- Analyzátor pamäte: `valgrind`
- Systém pre statickú analýzu kódu: `cppcheck` (nepovinné)

Textový editor:
- `vim`

Systém pre správu verzií:
- `git`

Všetky tieto nástroje sú určené na beh v linuxe. 

!! Pozor  - program preložený na platforme Windows sa môže správať inak na platforme Linux.

Tieto pracovné nástroje sú k dispozícii na školskom servri `omega.tuke.sk` na ktorý sa pripojíte pomocou klienta Putty (alebo iného).

V prípade, že Vám z nejakého dôvodu systém omega nevyhovuje alebo nefunguje, máte možnosť si vytvoriť pracovné prostredie aj na Vašom počítači s OS Windows.

Môžete využť natívne nástorje alebo nástroje využívajúce virtualizáciu. Nevýhoda je trochuu zložitejšia inštalácia:

- Nainštalujte si linux ako dual boot.
- Ak máte MacOS, viete si natívne nástroje nainštalovať pomocou [Homebrew](https://brew.sh/)
- Ak máte Windows, použite [Virtuálny stroj VirtualBox](https://kurzy.kpi.fei.tuke.sk/zap/problemsets/ps-00.html) s Ubuntu, obsahuje všetky potrebné nástroje. Mali by ste ho mať z predmety Základy algoritmizácie a programovania.
- [WSL2](https://docs.microsoft.com/en-us/windows/wsl/install-win10): virtulizácia Linuxu v prostredí Windows od Microsoftu.

Núdzovo môžete použiť nástroje založené na emulácii. Nevýhoda je možnosť nekompatibility a nedostupnosť nástroja valgrind:

- [GIT Bash](https://git-scm.com/downloads), obsahuje príkazový riadok v prostredí Windows. Neobsahuje Valgrind.
- [CygWin](https://cygwin.com/install.html): emulácia linuxu v prostredí Windows.
- [WSL](https://docs.microsoft.com/en-us/windows/wsl/install-win10): emulácia Linuxu v prostredí Windows od Microsoftu.

Alternatívne prístupy ktoré neodporúčam kvôli možnej nekompatibilite, problémom pri odovzdávaní pomocou GITu a problémom pri ladení:

- Visual Studio Code na Windows
- Iné Windows IDE
- Webové editory a kompilátory
- Písanie do webového rozhrania na GITe.


