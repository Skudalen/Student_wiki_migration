---
title: Kubernetes
published: true
---

# Kubernetes

---
## Čo je to Kubernetes

- Klastrový operačný systém
- Orchestrátor kontajnerov
---
## Kubernetes nie je Docker

Aplikácia beží v kontajneri ale...

Kubertenes sa stará kde a ako

manažuje viac strojov (virtuálnych alebo fyzických) kde bežia kontajnery

---
![Kubernetes](./Kubernetes.png)

[note]
Ako súvisí Kubernetes a Docker:

- docker sa stará o beh procesov
- Kubernetes sa stará o celý cluster

[/note]


---
## Na čo je Kubernetes

Nástroj na manažment klastra, pridelenie a nepretržité využitie zdrojov:

- diskový priestor
- CPU
- GPU
- sieťové spojenie
- RAM

---
## Prečo Kubernetes

Vaša aplikácia beží kontajneri na Vašom klastri alebo na cloude.

Aby sme mohli jendoducho horizontálne škálovať

---
## Kubernetes pre vývojárov

- DevOps
- Continous Integration - Continous Deployment
- uľahčenie procesu nasadenia a kontroly kvality aplikácie
- build, test, inštalácia, nasadenie 

---
## Kubernetes pre manažérov

- optimalizácia nákladov
- vrstva kompatibility medzi jednotlivými poskytovateľmi cloud služieb
    - ľahši prenos medzi private-public cloud

---
## Kuberntes pre správcov

- ľahší manažment veľkého množstva fyzických zdrojov
- zdroje nemusia byť na jednom mieste
- zabezpečenie odolnosti voči výpadku

---
## Vysoká dostupnosť

Môžeme vyradiť ľubovoľný uzol klastra bez výpadku.

Neexistuje "jediný bod zlyhania"

---
## Kubernetes je odolný

voči výpadku hardware alebo software.

- Ak havaruje aplikácia , reštartuje sa (možno na inom uzle).
- ak havaruje celý uzol, záťaž preberie iný uzol.

---
## Škálovanie a elasticita

Zdroje sa prispôsobujú potrebám

- rastú alebo zanikajú
- platíme iba za to čo spotrebujeme

Množstvo potrebných prostriedkov sa v čase mení.

- výpočtový výkon
- diskový priestor
- konektivita

---
### Škálovateľnosť

Horizontálna škálovateľnosť - pridáme nové (virtuálne) zariadenie.

Vertikálna škálovatenosť - rozšírime existujúce zariadenie (pridáme disk, procesor alebo pamäť).

---
### Vertikálne škálovanie

Rozšírime server

- viac RAM
- viac CPU
- výmena servra

---
### Horizontálne škálovanie

Kúpime alebo prenajmeme ešte jeden server

---
## Elasticita

Veľkosť klastra sa prispôsobuje potrebám.

- Beží viac inštancií podľa potreby, systém zabezpečí rozloženie záťaže (Load Balancing)

- Ak sa záťaž zníži, môžme uzol zrušiť. Ak sa záťaž zníži, môžme uzol zrušiť..

---
### Public Cloud: Poskytovatelia Kubernetes

Kubernetes Cluster môže bežať na:

- Vašom notebooku
- Vašom datacentre
- U poskytovateľa ako PAAS

---
### Private Cloud: Distribúcie Kubernetes

- kubeadm / vanilla Kubernetes
- OpenShift - Tectonic - OKD
- Rancher
- Ubuntu

---
### Mini K8S distribúcie

- minikube
- minishift
- microk8s
- k3s

---
### Kuberetes na Cloude

- Amazon Elastic Kubernetes Service EKS
- Google Kubernetes Engine GKE
- Microsoft Azure Kubernetes Service AKS
- Alibaba Container Service for Kubernetes ACK

---
## Kubernetes

Nový operačný systém

