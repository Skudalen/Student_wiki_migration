---
title: Inštalácia Docker Toolbox
published: true
---

! Cieľ:
!
! - príprava základnej sady nástrojov pre prácu s kontajnermi na báze Virtual Box, Docker Toolbox a príkazového riadka GIT Bash
! - tento postup použijete v prípade, že máte Windows, ale z nejakého dôvodu nedokážete nainštalovať [Docker Desktop](/zkt/cvicenia/desktop).

Potrebujete:

- Počítač s Windows 7 alebo 10
- Aktivovanú podporu virtualizácie v BIOSe

Pripravíte si všetko potrebné na to aby ste mohli začať pracovať s aplikačnými kontajnermi.
Aplikácie budú bežať vo virtuálnom stroji VirtualBox, ktorý si nainštalujete pomocou nástroja `docker-machine`.
Práca bude prebiehať v príkazovom riadku `GIT BASH`. S kontajnermi budete pracovať pomocou klienta `docker` ktorý komunikuje s virtuálnym strojom `docker-machine`. Všetko potrebné  nainštalujete pomocou inštalátora "Docker Toolbox".


Výsledok bude vyzerať nejako takto:


```
  +----------------+                +----------------+
  | docker-machine |                | Docker Engine  | 
  | docker CLI     |<--spojenie---->| na VirtualBoxe |
  +----------------+  cez virt.sieť +----------------+
         ^                               ^
         |                               |
  Git Bash na Windows                 VirtualBox Monitor

```

## Inštalácia Docker Toolbox

Inštalátor [Docker Toolbox](https://docs.docker.com/toolbox/toolbox_install_windows/) nainštaluje všetko potrebné pre prácu so systémom Docker. Docker Toolbox je možné použiť aj na systéme OS X a na systéme Windows 7.

Docker Toolbox získate z [GitHubu](https://github.com/docker/toolbox/releases/tag/v19.03.1).

- [VirtualBox](https://www.virtualbox.org/) poskytuje prostredie pre beh rôznych virtuálnych strojov. Po inštalácii program nezabudnite spustiť.
- [Docker Machine](https://docs.docker.com/machine) vytvorí virtuálny stroj Virtual Box, ktorý obsahuje prostredie pre beh kontajnerov Docker.
- Docker klient pre prácu v príkazovom riadku
- Git Bash

Git Bash Poskytuje základnú sadu Unix nástrojov pre Windows

- `bash`: príkazový riadok a nástroj na robenie skriptov
- `git`: správa projektov, odovzdávanie zadaní
- `vim`: Váš obľúbený textový editor
- `ssh`: vzdialené pripojenie
- `scp`: kopírovanie súborov
- `curl`: získavanie súborov z webu
- `gcc`: kompilátor

Ak chcete Git Bash inštalovať samostatne, získate ho z [webovej stránky](https://git-scm.com/downloads).
Pri inštalácii môžte postupovať podľa [návodu](https://www.techoism.com/how-to-install-git-bash-on-windows/).

## Inštalácia Docker Engine pomocou docker-machine

Po inštalácii Docker Toolbox by ste mali mať v príkazovom riadku GIT Bash k dispozícii príkazy `docker-machine` a `docker`.

Spustite si aplikáciu "GIT Bash". Overíte si, či "Docker Machine" funguje príkazom:

    docker-machine

Ak ste postupovali správne, zobrazí sa Vám nápoveda `docker-machine`. Pozrite si, čo všetko sa dá robiť.


## Vytvorenie virtuálneho stroja

Inštalátor Docker Toolbox by mal zvládnuť vytvorenie virtuálneho stroja za Vás. Ak nie, použite príkazový riadok na vytvorenie.

Nový virtuálny stroj s názvom `default` na VirtualBoxe si vytvoríte príkazom (chvíľu to trvá):

    docker-machine create --driver virtualbox default

Zoznam a stav existujúcich Docker virtuálnych strojov si overíte pomocou príkazov:

    docker-machine ls
    docker-machine status default

Na bežiaci virtuálny stroj sa pripojíte príkazom:

    docker-machine ssh default

Ak všetko prebehlo v poriadku, príkaz `docker` by mal komunikovať s bežiacim virtuálnym strojom Docker Engine.

Vyskúšajte príkaz:

    docker version

V prípade, že sa riadkový klient Docker nevie spojiť so vzdialeným strojom Docker Engine, môžete vyskúšať tento [návod](https://www.kevinkuszyk.com/2016/11/28/connect-your-docker-client-to-a-remote-docker-host/).

Spojenie klienta by Vám mal uľahčiť príkaz:

    docker-machine env

