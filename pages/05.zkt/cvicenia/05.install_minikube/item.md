---
title:  Inštalácia Minikube
published: true
---

! Naučíte sa:
!
! - Vytvoriť jednoduchý Kubernetes klaster z jedného uzla pomocou virtuáleho stroja Minikube
! - Tento postup použijete v prípade, že nemáte nainštalovaný Docker Desktop

## Inštalátor minikube

Nainštalujte si systém `minikube` podľa [návodu](https://minikube.sigs.k8s.io/docs/start/). Požiadavky sú podobné ako pri inštalácii Docker Toolbox -
bežiaci hypervisor (virtualbox alebo Hyper-V), 4GB RAM.

Pre systém Windows stačí stiahnuť a spustiť [inštalátor](https://storage.googleapis.com/minikube/releases/latest/minikube-installer.exe). Z príkazového riadku Git Bash vykonajte tieto príkazy aby ste vytvorili virtuálny stroj s nainštalovaným systémom Kubernetes:


```
minikube start
```

Nastavenie minikube na Windows-e, ak používate Hyper-V je trošku zložitejšie. Najvhodnejšie je použiť [tento návod](https://medium.com/@JockDaRock/minikube-on-windows-10-with-hyper-v-6ef0f4dc158c). Kroky s chocolate môžete preskočiť a postupovať až do riadku s 
```
minikube stop
```

!!! Môže sa stať, že Vaše internetové pripojenie bude fungovať veľmi zle. Medzi sieťovými adaptermi sa Vám zjaví "Network Bridge". Keď si toto rozkliknete, vo vlastnostiach nájdete "Internet Protocol Version 4 (TCP/IPv4)" (v spodnom okne). Tento si zakliknite a internet by mal fungovať správne.

Stroj `minikube` je podobný ako stroj `docker-machine`.
Obsahuje inštaláciu Docker pre spúšťanie aplikácií v kontajneroch. Okrem toho obsahuje aj všetko potrebné pre beh jedno uzlového klastra typu Kubernetes. 

Po chvíli sa vytvorí virtuálny stroj `minikube` ktorý bude vykonávať Vaše príkazy.

Stav `minikube` si viete overiť príkazom:

```
minikube status
```

V prípade, že je všetko v poriadku, zobrazí sa správa:

```
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
```

Stav Vášho fungujúceho  súkromného klastra Kubernetes si môžete ľahko skontrolovať príkazom:

```
minikube dashboard
```

Otvorí sa vám webová aplikácia. Prezrite si čo máte k dispozícii.

Po skončení práce môžme vypnúť pokusný klaster (lebo berie pomerne veľa systémových zdrojov):

```
minikube stop
```

O prípadných chybách pri spustení sa môžme dozvedieť pomocou:

```
minikube logs
```

## Kubectl

Príkaz `minikube` slúži hlavne na inštaláciu pokusného klastra a na ovplyvňovanie jeho behu.
Bežnú prácu s klastrom - pridávanie a odoberanie záťaže
vykonávame pomocou klienta `kubectl`.

Funguje to podobne ako v prípade klienta `docker` - 
príkazy zadané z príkazového riadka sa prenášajú pomocou TCP protokolu na klaster a tam sa potom vykonávajú.

V tomto príkaze využijeme klienta `kubectl` ktorý je súčasťou `minikube`. Výhoda je tá, že nemusíme vykonávať ďalšiu konfiguráciu.


```
minikube kubectl
```

## Inštalácia kubectl

Zabudovaný klient je vhodný iba na začiatok. Pre bežnú prácu
je dobré nainštalovať a nakonfigurovať oficiálneho klienta `kubectl` (je súčasťou Docker Desktop for Windows).

Ak ho ešte nemáte, na inštaláciu pre prostredie Git Bash vo Windows  využite tento postup:

    # Vytvorte si adresár s právom na zápis. 
    # Tilda (~) je synonym pre domovský adresár
    mkdir ~/apps/kubectl
    cd ~/apps/kubectl
    # Stiahnite aplikáciu
    curl -LO https://storage.googleapis.com/kubernetes-release/release/v1.17.0/bin/windows/amd64/kubectl.exe
    # Vyskúšajte či ide:
    ./kubectl
    # Pridajte adresár do premennej PATH
    echo "export PATH=\$PATH:~/apps/kubectl" >> ~/.bash_profile
    # Pri novom spustení budete mať k dispozícii príkaz kubectl

Inštalácia na Linuxe je triviálna - stačí využiť Váš manažér balíčkov. Pozrite si oficiálny [návod](https://kubernetes.io/docs/tasks/tools/install-kubectl/).

## Spojenie s Kubernetes

Práca s `kubectl` je do určitej miery podobná práci s klientom `docker`. Podobnosti sú zhrnuté v tomto [návode](https://kubernetes.io/docs/reference/kubectl/docker-cli-to-kubectl/).

Pozrite aj [oficiálny návod](https://kubernetes.io/docs/setup/learning-environment/minikube/) na prvé kroky s minikube.

Najprv vyskúšajte, či klient funguje v poriadku a či má spojenie s klastrom. S ktorým klastrom komunikujem?

```
kubectl cluster-info
```

Príkaz `minikube start` pridá záznam o kofigurácii do súboru `~/.kube/config`. Príkaz `kubectl` si podľa toho načíta informácie o prístupových údajoch a adrese klastra s ktorým komunikuje.


Zistite adresu minikube:

```
minikube ip
```

Vyskúšajte si to pomocou Vášho webového prehliadača.

