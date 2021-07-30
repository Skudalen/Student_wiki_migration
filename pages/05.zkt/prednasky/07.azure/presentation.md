---
title: Azure Cloud
published: true
---
## Čo je to Azure Cloud?

Prepojené verejné služby dátových centier Microsoftu

---
## Serverless

> With serverless applications, the cloud service provider automatically provisions, scales, and manages the infrastructure required to run the code. Serverless architectures are highly scalable and event-driven. They use resources only when a specific function or trigger occurs.

---
# Prenájom Azure služby

Account
 :  prihlásenie a identita

Subscription 
 : predplatné, účtovná jednotka

---
# Organizácia a konfigurácia služieb 

ResourceGroup 
 : skupina zdrojov v rámci predpatného

Resource 
 : konkrétny zdroj za ktorý platíme

resourceManagerTemplate 
 : súbor ktorý definuje použitie jedného alebo viacerých zdrojov.

---
## Kvalita služby

SKU
 : Stock Keeping Unit

- Basic alebo  Premium
- rýchlosť, redundancia,  zálohovanie, stabilita, latencia

---
# Výber lokácie

Je rozdiel kde fyzicky beží služba:
- latencia
- jurisdikcia

Region 
 : kde sa nachádza datacentrum

Datacenter 
 : konkrétne datacentrum

---
# Manažment klaudových služieb

Azure portal
 : Webové rozhranie pre manažment klaudových služieb

Azure Command Line
 : `az` riadkové rozhranie pre manažment klaudových služieb. Umožnuje vytváranie skriptov. 

---
## Rozdelenie klaudových služieb 

Anything As a Service, Pay as You Go

- Infraštruktúra - IASS
- Platforma - PASS
- Aplikácie - SASS

---

https://docs.microsoft.com/en-us/learn/azure-fundamentals/intro-to-azure-fundamentals/media/iaas-paas-saas-expanded.png

---
## IASS - Infrastructure as a service

Virtualizácia a zverejnenie aplikácie:

- Prenájom virtuálnych servrov a sietí
- prenájom diskov a blokových zariadení
- load balancer

---
## PAAS - Platform as a service

Nasadenie webovej aplikácie:

- Využie "klaudového OS", napr. AKS
- Azure App services - Docker Compose, Docker, Aplikácie

---
## SAAS - Software as a service

Hotové aplikácie alebo komponenty:

- azure container registry
- databáza
- systémy strojového učenia
- strojový preklad, vyhľadávací stroj

---
# Najdôležitejšie služby

---
## Storage (Úložisko)

File (súborový systém), Disk (blokové zariadenie), Blob (Objekt)

Špeciálne  úložiská:  DataLake (analytická databáza), Archive (archivácia), HPC Cache (vyrovnávacia pamäť)

---
### Virtual Machines

Virtuálny stroj

- Linux (CentOS, RHEL, Suse, Debian, Ubuntu)
- Windows (Server)
- Vlastný obraz

---
# Web Apps

- Web aplikácia bez kontajnera
    - Java, Node.js, PHP, Python, .NET, Ruby
- Web aplikácia s kontajnerom 
    - ľubovoľné závislosti
- Napojenie na storage (adresár /home alebo iný)
- Automatické zostavenie a nasadenie (CI/CD continous integration and  deploymnet), Prepojenie s GitHub

---
# Database

SQL

- Azure SQL
- SQL Server
- Postgres, Mysql-MariaDB

NoSQL

- CosmosDB (MongoBD, Cassandra compatible)
- Redis, Cassandra, 

---
#  LoadBalancer

- Zverejnenie služby
- Zabezpečenie vysokej dostupnosti
- HTTPS termination

---
# ACR Container Registry

Register obrazov kontajnera

Pre použitie v App Services a AKS

---
# AKS Kubernetes Service

Kubernetes klaster

- Vytvorenie klastra na požiadanie
- Automatické škálovanie
- CI/CD
- Využitie na strojové učenie
- Podpora hybridných klaudov - manažment viacerých klastrov z jedného miesta.

---
# Bibliografia

- [Azure fundamentals](https://docs.microsoft.com/en-us/learn/modules/intro-to-azure-fundamentals/)

---
# Vendor Lock-In

Niektoré služby sú špecifické pre poskytovateľa.

Navrhujte aplikáciu tak aby bola ľahká migrácia:

- privátny - verejný klaud
- verejný klaud - iný verejný klaud

"Uzamknutie" môže spôsobiť problémy v budúcnosti.
