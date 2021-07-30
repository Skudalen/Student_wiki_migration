---
title: Azure Kubernetes Service
published: true
---
# Azure Kubernetes Service

---

Platform as a Sevice

Dá sa vytvoriť na požiadanie

---

Vlastnosti

---

- Dynamické prideľovanie zdrojov podľa aktuálnej potreby.
- Integrácia s CI-CD reťazcom.
- Integrácia s inými službami a SW od MS (Visual Studio).
- Autentifikácia pomocou Active Directory.

---

- Možnosti logovania, zabezpečenia a monitorovania klaudu.
- Rôzne druhy virtuálnych strojov, vrátane GPU.
- Rôzne druhy úložného priestoru (object, block, file) - Azure Disk, Azure Files

Na požiadanie sa v klaude vytvorí jeden alebo viacero pracovných uzlov,
naništaluje sa Kubernetes.

---
## Networking v AKS

Zverejnenie služby v AKS

- LoadBalancer Service
- Ingress

---

- ClusterIP - virtuálna IP v rámci klastra
- NodePort - virtuálna IP v rámci klastra, IP každého pracovného uzla
- Load Balancer - virtuálna IP v rámci klastra, verejná IP zastupujúca celý klaster

---
Zverejnenie pomocou LoadBalancer

- Pridelí sa verejná IP adresa
- LoadBalancer spostredkúva kontakt medzi klastrom a vonkajším svetom

---

```
+-----------+           +-------------+     +---------------+
| POD       | Cluster   | Service     |     | Load Balancer |  Public  
| ClusterIP | Traffic   | Cluster DNS |     | Public IP     |  TCP
+-----------+           +-------------+     + --------------+
```

---

# Ingress

Verejný webový server so symbolickým DNS menom

- Obsahuje pravidlá ktoré presmerujú prevádzku na služby klastra.
- Stará sa o TLS certifikáty

---

```
+-----------+           +-------------+     +---------------+
| POD1      | Cluster   | Service 1   |     | Ingress       |  Public  
| ClusterIP | Traffic   | Cluster DNS |     | Public DNS    |  HTTPS
+-----------+           +-------------+     + --------------+
                                        \     Ingress Rules
+-----------+           +-------------+  \__  /service1
| POD2      | Cluster   | Service 2   |     
| ClusterIP | Traffic   | Cluster DNS | <--- /service2
+-----------+           +-------------+   
```

---

## Úložisko

https://docs.microsoft.com/en-us/azure/aks/concepts-storage

- Volumes
- PersistentVolumes
- PersistentVolumeClaims
- Storage Classes

---

Diskový priestor sa dá prideliť manuálne alebo dynamicky

- Azure Disks - blokové zariadenie, pripojené ReadWriteOnce
- Azure File - SMB zložka, pripojená ReadWriteMany

---

Viac na cvičení


