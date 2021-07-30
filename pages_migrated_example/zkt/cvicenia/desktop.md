---
title: Týždeň 1: Inštalácia Docker Desktop
published: true
date: 15.2.2021
---

! Cieľ:
!
! - príprava základnej sady nástrojov pre prácu s kontajnermi pre systém Windows na báze WSL2 a Docker Desktop
! - tento postup použijete v prípade, že máte aktuálny Windows 10

Potrebujete:

- Windows 10, version 1903 alebo vyššie. Číslo zostavenia (buildu) musí byť 18362.1049+ alebo 18363.1049+. Ak Vaša verzia Windows nesedí, môže pomôcť Windows Update. Presnú verziu zistíte príkazom `winver`.
- Aspoň 4GB RAM a 64bit systém
- [Zapnutú podporu](https://docs.docker.com/docker-for-windows/troubleshoot/#virtualization-must-be-enabled) virtualizácie v BIOSe.

Výsledok bude vyzerať nejako takto:


```
  +----------------+                +---------------+
  | Ubuntu na WSL2 |                | Docker Engine | 
  | Docker CLI     |<--spojenie---->| na WSL2       |
  +----------------+  cez virt.sieť +---------------+
         ^                               ^
         |                               |
  Windows Terminal                 Docker Desktop


```

Postup: 

1. Nainštalujte WSL2 a súvisiace nástroje. Nasledujte tento [návod](https://docs.microsoft.com/en-us/windows/wsl/install-win10#manual-installation-steps). Po tomto návode by ste mali mať nainštalované: 
    - WSL , Windows Subsystem for Linux - vrstva "emulácia linuxu" bez virtualizácie
    - WSL2, Windows Subsystem for Linux 2 - virtuálny stroj pre inštaláciu Linuxu s použitím Hyper-V. 
    - "Linux Kernel Update Package" - nejaký fix čo je potrebný.
    - Ubuntu 20.04 - kompletné prostredie Ubuntu.
    - Windows Terminal - pohodlný príkazový riadok pre pripojenie sa na Ubuntu virtuálny stroj alebo iné. 

2. Skúste či WSL2 funguje.
    - Spustite Windows Terminal pomocu menu Štart.
    - Ťuknite na šípku a zvoľte "Ubuntu 20.04". Spustí sa Vám príkazový riadok Ubuntu.
    - Zistite IP adresu Ubuntu stroja: `ip address`.


3. Potom nainštalujte Docker Desktop podľa [tohoto návodu](https://docs.docker.com/docker-for-windows/install/). Získate:
    - Docker Engine: virtuálny stroj ktorý sa stará o spúšťanie kontajnerov. Virtuálny stroj využíva WSL2 a Hyper-V podsystémy.
    - Docker CLI: utlita pre komunikáciu s Docker Engine.
    - Kubernetes: orchestrátor pre vytváranie zložitejších nasadení kontajnerov. 

4. Skúste, či Docker funguje. 
    - V pravom dolnom rohu počítača by sa mala objaviť ikonka "Docker Desktop" a správa "Docker is running."

5. Prepojte riadkového klienta Docker a Docker Engine.
    - Pomocou Windows Terminal spustite Ubuntu 20.04
    - Nainštalujte potrebné balíčky:
    ```
        apt-get update
        apt-get upgrade
        apt-get install docker.io vim
    ```
    - Vytvorte prepojenie: 
        - Ťuknite na ikonku "Docker Desktop". 
        - Zvoľte ikonku "Settings". 
        - Nájdite menu Resources/WSL Integration.
        - Povoľte "Enable integration with additional distros".
    - Overte či to funguje.

Na konci v príkazovom riadku Ubuntu napíšte `docker version`.

Vypíše sa niečo takéto:


```
Client:
 Version:           19.03.8
 API version:       1.40
 Go version:        go1.13.8
 Git commit:        afacb8b7f0
 Built:             Fri Dec 18 12:15:19 2020
 OS/Arch:           linux/amd64
 Experimental:      true

Server: Docker Engine - Community
 Engine:
  Version:          20.10.2
  API version:      1.41 (minimum version 1.12)
  Go version:       go1.13.15
  Git commit:       8891c58
  Built:            Mon Dec 28 16:15:28 2020
  OS/Arch:          linux/amd64
  Experimental:     false
 containerd:
  Version:          1.4.3
  GitCommit:        269548fa27e0089a8b8278fc4fc781d7f65a939b
 runc:
  Version:          1.0.0-rc92
  GitCommit:        ff819c7e9184c13b7c2607fe6c30ae19403a7aff
 docker-init:
  Version:          0.19.0
  GitCommit:        de40ad0
```


        
