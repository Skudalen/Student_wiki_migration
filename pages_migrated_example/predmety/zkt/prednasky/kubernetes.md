# Kubernetes

---
## Prečo Kubernetes

Vaša aplikácia beží kontajneri na Vašom klastri alebo na cloude.

---
## Kubernetes nie je Docker

Aplikácia beží v kontajneri ale...

Kubertenes sa stará kde a ako

---
## Čo je to Kubernetes

Klastrový operačný systém

---
## Na čo je Kuberntes

- Pridelenie a nepretržité využitie zdrojov klastra:
    - diskový priestor
    - CPU
    - GPU
    - sieťové spojenie
    - RAM

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

voči čiastočnému výpadku hardware alebo software.

---

- Ak havaruje aplikácia , reštartuje sa na inom uzle.
- ak havaruje celý uzol, záťaž preberie iný uzol.

---
## Škálovanie a elasticita

Zdroje sa prispôsobujú potrebám
- rastú alebo zanikajú
- platíme iba za to čo spotrebujeme

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

Beží viac inštancií podľa potreby, systém zabezpečí rozloženie záťaže (Load Balancing)

Ak sa záťaž zníži, môžme uzol zrušiť. Ak sa záťaž zníži, môžme uzol zrušiť..

---
![Kubernetes](./Kubernetes.png)

[note]
Ako súvisí Kubernetes a Docker:

- docker sa stará o beh procesov
- Kubernetes sa stará o celý cluster

Docker Vychádza z módy
[/note]

---
### Kubernetes Architektúra

- api server
- etcd
- scheduler
- controller manager
- kubelet
- kube proxy

---
## API server

- komunikácia s klastrom
- komunikácia s uzlami

---
## etcd

distribuovaná databáza s konfiguráciou klastra

---
## scheduler

rozhoduje kde sa bude spúšťať zátaž

---
## controller manager 

zabezpečuje súlad stavu klastra s konfiguráciou

- spúšťa alebo ruší záťaž podľa potreby

---
## kubelet

stará sa o beh záťaže v kontajneri na pracovnom uzle 

---
## kubeproxy

sprostredkuje spojenie medzi uzlami


---
### Ako budeme pracovať s k8s

pomocou klienta kubectl

- vytvárame a rušíme objekty v klastri

---
## Kubernetes Objekt

Entita v klastri reprezentujúca nejaký zdroj:
- CPU, sieť, storage ...

---
## Zápis Aplikácie

Niekoľko k8s objektov zapísaných pomocou Yaml

---
## YAML

"Inštalačný skript" aplikácie

---
## definujeme ako má aplikácia vyzerať

deklarujeme želaný stav. Kubernetes povie ako ten stav dosiahnuť a udržať.

---
# Objekty

---
## Kubernetes Objekt

- apiVersion - kompatibilta
- kind - druh objektu
- metadata - meno, štítky a anotácie
- spec - špecifikácia objektu

---
### Kubernetes API Objekty

- PersistentVolume
- PersistentVolumeClaim
- Deployment 
- StatefulSet
- Service
- Ingress

---
# POD

tento objekt nevytvárame priamo ale pomocou StatefulSet alebo Deployment

---
## POD

Jedna jednotka aplikácie:

- jeden alebo viac kontajnerov
- jeden alebo viac zväzkov

Pod je nedeliteľný - všetky jeho časti bežia spolu na jednom uzle


---
## Deployment

Deklarujeme PODy ktoré aplikácia potrebuje

Deployment sa dá jednoducho škálovať

---
## Deployment

- riadi POD pomocou objektu ReplicaSet
- POD vytvára podľa zadanej šablóny

---

```
+------------+
| Deployment |
+------------+
     | controlplane
     v
+------------+
| ReplicaSet |
+------------+
     | controlplane
     v
+------------+
|    POD     |
+------------+
        node

```
---
## Service

Funguje pre ľubovoľný TCP protokol

Verejná IP adresa je cenný tovar

Deklarujeme symbolické meno mikroslužby

---
## Service 

- ClusterIP: služba je viditeľná v rámci klastra (dostane virtuálnuu IP adresu a DNS meno)
- NodePort: služba bude dostupná na každom uzle na konkrénom porte.
- LoadBalancer: služba bude dostupná pomocu nástrojov Vášho poskytovateľa

---
## Ingress


Zverejníme službu HTTP pomocou reverzného proxy servra (nginx, HAProxy)

---
## StatefulSet

(podobné ako Deployment)
 
Deklarujeme PODy ktoré aplikácia potrebuje

Deklarujeme nároky aplikácie na zväzky

StatefulSet je závislý na PersistentVolume


---
## StatefulSet

- riadi `POD` pomocou `ReplicaSet`
- Stará sa aj o `PersistentVolume` pomocou `PersistentVolumeClaim`

---

```
        Storage
  +------------------+
  | PersistentVolume |     LoadBalancer 
  +------------------+ 
     ^ P.V.Claim               ^
     |                         | 
  +--------------+ Port  +-----------+
  | POD Template |------>| Service   |
  |  ReplicaSet  |       +-----------+
  |  StatefulSet |
  +--------------+
        node

```

---
## PersistentVolume

Deklarujeme zväzky  k dispozícii

PersistentVolumeClaim - deklarujeme nárok aplikácie na zväzky

Prístup k lokálnemu alebo distribuiovanému súborovému systému


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

