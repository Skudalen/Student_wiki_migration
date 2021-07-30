---
title: Inštalácia Docker v prostredí Linux
published: true
---

! Tento postup platí pre systémy Linux
! 


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

