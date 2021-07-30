---
title: Architektúra Kubernetes 
published: true
---

### Architektúra Kubernetes

---
## Kubernetes je klastrový operačný systém

- vysoko dostupný
- elastický
- ľahko škálovateľný

---
k8s klaster:

- Riadiace uzly
- Pracovné uzly
- Uzly infraštruktúry - register, load balancer

jeden až tisíce uzlov

---
## Komponenty

- api server
- etcd 
- scheduler
- controller manager
- kubelet
- kubeproxy
- container run-time

---

![arch](components-of-kubernetes.svg)

[Podľa oficiálnej dokumentácie](https://kubernetes.io/docs/concepts/overview/components/)

---
### Komponenty na riadiacich uzloch

- api server
- etcd 
- scheduler
- controller manager

---
## API server

- komunikácia s klastrom
- komunikácia s uzlami

Má svoje URL pomocou ktorého vieme riadiť klaster.

---
## etcd

- distribuovaná databáza 
    - konfigurácia
    - logy
    - stav objektov

---
## scheduler

rozhoduje kde sa bude spúšťať zátaž

---
## controller manager 

zabezpečuje súlad stavu klastra s konfiguráciou

- spúšťa alebo ruší záťaž podľa potreby

---
## Komponenty na pracovných uzloch

- kubelet
- kube proxy

Môžu bežať aj na riadiacich uzloch

---
## kubelet

stará sa o beh záťaže v kontajneri na pracovnom uzle 

- spúšťa a ruší procesy (kontajnery)

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
# Objekt

- opisuje želaný a aktuálny stav
- týka sa nejakého zdroja
- má meno a anotácie
- má definované podmienky 

---
## Kubernetes Objekt

- `apiVersion` - kompatibilta
- `kind` - druh objektu
- `metadata` - meno, štítky a anotácie
- `spec` - špecifikácia objektu

---
### Kubernetes API Objekty

- `PersistentVolume`
- `PersistentVolumeClaim`
- `Deployment` 
- `StatefulSet`
- `Service`
- `Ingress`

---
# POD

tento objekt nevytvárame priamo ale pomocou `StatefulSet` alebo `Deployment`

---
## POD

Jedna jednotka aplikácie:

- jeden alebo viac kontajnerov
- jeden alebo viac zväzkov

Pod je nedeliteľný - všetky jeho časti bežia spolu na jednom uzle

---
## Deployment

Deklarujeme PODy ktoré aplikácia potrebuje

Deployment sa dá jednoducho škálovať (vytvárať a rušiť inštancie).

---
## Deployment

- riadi POD pomocou objektu `ReplicaSet`
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

`StatefulSet` je závislý na `PersistentVolume`.


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

Prístup k lokálnemu alebo distribuovanému súborovému systému


