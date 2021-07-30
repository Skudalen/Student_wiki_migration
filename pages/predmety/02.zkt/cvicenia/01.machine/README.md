# Nainštalujte si Docker Machine

Cieľ:

- príprava základnej sady nástrojov pre prácu s kontajnermi.

Pripravíte si všetko potrebné na to aby ste mohli začať pracovať s aplikačnými kontajnermi.

Aplikácie budú bežať vo virtuálnom stroji VirtualBox, ktorý si nainštalujete pomocou nástroja `docker-machine`.
Práca bude prebiehať v príkazovom riadku `GIT BASH`. S kontajnermi budete pracovať pomocou klienta `docker` ktorý komunikuje s virtuálnym strojom `docker-machine`. Všetko potrebné  nainštalujete pomocou inštalátora "Docker Toolbox".

## Docker Toolbox

Inštalátor [Docker Toolbox](https://docs.docker.com/toolbox/toolbox_install_windows/) nainštaluje všetko potrebné pre prácu so systémom Docker. Docker Toolbox je možné použiť aj na systéme OS X.
Docker Toolbox získate z [GitHubu](https://github.com/docker/toolbox/releases/tag/v19.03.1).

- [VirtualBox](https://www.virtualbox.org/) poskytuje prostredie pre beh rôznych virtuálnych strojov.
Po inštalácii program nezabudnite spustiť.
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


## Práca s Docker Machine

Spustite si aplikáciu "GIT Bash". 

Overíte si, či "Docker Machine" funguje príkazom:

    docker-machine

Ak ste postupovali správne, zobrazí sa Vám nápoveda `docker-machine`. Pozrite si, čo všetko sa dá robiť.

Zoznam a stav existujúcich Docker virtuálnych strojov si overíte pomocou príkazov:

    docker-machine ls
    docker-machine status default

Na bežiaci virtuálny stroj sa pripojíte príkazom:

    docker-machine ssh default

## Vytvorenie virtuálneho stroja

Inštalátor Docker Toolbox by mal zvládnuť vytvorenie virtuálneho stroja za Vás. Ak nie, použite príkazový riadok na vytvorenie.

Nový virtuálny stroj s názvom `default` na VirtualBoxe si vytvoríte príkazom (chvíľu to trvá):

    docker-machine create --driver virtualbox default

## Inštalácia nástrojov na Linuxe

Ak už používate OS Linux, Váš život bude o niečo jednoduchší.
Všetko potrebné sa na Vašom systéme už nachádza, alebo to nainštalujete niekoľkými príkazmi. Nebudete potrebovať ani GIT Bash
ani Docker Machine. 

Na Ubuntu môžte využiť [tento návod](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04).

V skratke:

```bash
# Update systému
sudo apt update
# Inštalácia potrebných baličkov
sudo apt install apt-transport-https ca-certificates curl software-properties-common
# Pridanie repozitára
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
sudo apt update
apt-cache policy docker-ce
# Inštalácia docker
sudo apt install docker-ce
sudo systemctl enable docker
sydo systemctl start docker
# Pridanie aktuálneho používateľa do skupiny docker
sudo usermod -aG docker ${USER}
```

## Prečítajte si

Aby ste si vytvorili svoj obraz o tom čo vlastne ten "Docker" je, prečítajte si niekoľko článkov:

- [Elektronický kurz UDEMY](https://www.udemy.com/course/docker-mastery/?LSNPUBID=mDjthAvMbf0&ranEAID=mDjthAvMbf0&ranMID=39197&ranSiteID=mDjthAvMbf0-ctos0Qt9MHHJzANn.zz.mA)
- [Čo je to aplikačný kontajner](https://www.docker.com/resources/what-container)
- [Docker na Fedore](https://mojefedora.cz/stitek/docker/)
- [Blog 1](https://www.master.cz/blog/docker-kubernetes-kontejnery-jak-funguji-proc-je-chtit/)
- [Blog 2](https://blog.josefjebavy.cz/unix/docker)

