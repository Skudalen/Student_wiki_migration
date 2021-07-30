---
title:  Inštalácia Kubernetes pomocou Docker Desktop
published: true
---

! Naučíte sa:
!
! - Vytvoriť jednoduchý Kubernetes klaster z jedného uzla pomocou Docker Desktop
! - Tento postup použijete v prípade, že máte nainštalovaný WSL2 a Docker Desktop. Vyžaduje sa nový systém Windows 10

## Inštalácia Kubernetes

Súčasťou balíčka Docker Desktop je aj výukový jednouzlový Kubernetes klaster.
Ak máte Docker Desktop, situácia je jednoduchá - ťuknite "Settings - Kubernetes - Enable Kubernetes" a chvíľu počkajte.

V prípade, že sa Vám inštalácia Kubernetes zasekne na správe "Kubernetes startning... " a dlhšie sa nič nebude diať, aplikujte postup v [tomto návode](https://stackoverflow.com/questions/57711639/docker-for-windows-stuck-at-kubernetes-is-starting-after-updating-to-version-2).

V skratke:
- Zastavte inštaláciu Kubernetes.
- Uveďte Docker Desktop do "Factory Settings".
- Vymažte zložky c:/ProgramData/DockerDesktop a c:/Users/user/.kube .
- Reštartujte DockerDesktop.
- Obnovte inštaláciu Kubernetes.


## Inštalácia kubectl

S klastrom budete komunikovať pomocou príkazu `kubectl`.
Práca s `kubectl` je do určitej miery podobná práci s klientom `docker`. Podobnosti sú zhrnuté v tomto [návode](https://kubernetes.io/docs/reference/kubectl/docker-cli-to-kubectl/).

Kubectl používa sieťový protokol pre komunikáciu s aplikačným rozhraním zvoleného Kubernetes klastra, preto musí mať prihlasovacie údaje pre ovládanie klastra.

Prihlasovacie údaje sa nachádzajú v súbore `~/.kube/config`. Príkaz `kubectl` si podľa toho načíta informácie o prístupových údajoch a adrese klastra s ktorým komunikuje.
Súbor `~/.kube/config` by mal modifikovať WSL2 a zapísať do neho potrebné informácie.


Asi najjednoduchšie je stiahnutie a nakopírovanie binárnej distribúcie kubectl:

    curl -LO https://dl.k8s.io/release/v1.20.0/bin/linux/amd64/kubectl
    sudo mv ./kubectl /usr/local/bin

Tento postup je možný vďaka tomu, že kubectl je naprogramovaný v jazyku GO.
Programy v jazyku GO sú preložené s prilinkovanými všetkými závislosťami a nie sú závislé na systémových knižniciach.

V prípade, že sa v prostredí WSL2 príkaz kubectl nevie pripojiť na bežiaci klaster aj keď jeho inštalácia prebehla úspešne, skúste tento postup:
    

```
# Urobte si zálohu pôvodnej konfigurácie
# V starej konfigurácii sa môžu nachádzať aj iné prihlasovacie údaje
mv ~/.kube ./oldkube
# user nahraďte za prihlasovacie meno ktoré používate vo Windows
# Skopírujte údaje z Windows - Tie boli nastavené pomocou integrácie Docker Desktop
cp -r /mnt/c/Users/user/.kube ~
```
