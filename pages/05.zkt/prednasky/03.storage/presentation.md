---
title: Dáta v klaude
published: true
---
# Dáta v klaude

- Ako dá prenajať a využiť diskový priestor 
- Ako spravovať diskový priestor v privátnom klaude

---
Množstvo potrebného diskového priestoru sa mení - spravidla rastie:

- je potrebné "prikúpiť" a "zamontovať" disky.
- čo ak disky už nie sú ptrebné? (napr. projekt skončil).

---
Disky sú nespoľahlivé:

- pravidelne vymieňať zlyhané zariadenia.

- Je potrebná redundancia - viac kópií tých istých dát.
- Je potrebné zálohovanie.
- Je potrebné riešiť aj bezpečnosť a prístupové práva.

---
## Celková cena za diskový priestor.

Fixné náklady:
- Serverovňa, disky, zariadenia

Pohyblivé náklady:

- Manažment, údržba, elektrická energia

---
## Klasický prístup

- Ak mám miesto v servri - kúpim disk.
- Ak mám miesto v serverovni a rozpočet - kúpim server.
- Ak nemám rozpočet - musím niečo vymazať.
- Ak nemám miesto v serverovni - postavím serverovňu.

----
# Virtualizácia diskového priestoru

- Anulujem fixné náklady.
- Zefektívnim pohyblivé náklady.
- Zvýšim flexibilitu - platím iba za to čo potrebujem.

Ale niekedy aj tak treba mať vlastný HW.

---
# Virtualizácia diskového priestoru

- blokové zariadenia.
- súborové systémy.
- objektové úložisko s aplikačným protokolom.

---
# Virtualizácia na úrovni blokových zariadení

Vo virtuálnom stroji sa "objaví" nový disk

---

# Virtualizácia na úrovni súborového systému

Do kontajnera si viem namapovať nový adresár

- sieťové súborové systémy: NFS, SMB
- distribuované súborové systémy: Gluster, Ceph

---
# Diskový priestor na aplikačnej úrovni

- object storage: S3, Swift
- NoSQL databázy
- Relačné databázy
- Vyrovnávacie pamäte a brokery: Redis

Aplikácia komunikuje s úložiskom pomocou aplikačného protokolu

---
# Práca so súborovým systémov v aplikačnom kontajneri

- Súborový systém je virtuálny
- Súborový systém sa po reštarte sa vždy vráti do pôvodného stavu

---
# Čo je to stav kontajnera?

časť súborového systému ktorá sa mení a ktorá je podstatná aj po reštarte.

- napr. databáza

---
# Mapovanie súborového systému 


Oddelíme:

- konfigurácia (kde sa naše nachádzajú konfiguračné súbory ktoré sa nemenia)
- stav (kde sa nachádzajú súbory ktoré sa menia a sú podstatné)
- aplikácia (všetko ostatné)

---
# Vytvorenie mapovania medzi storage a kontajnerom

Docker dokáže čiastočne "manažovať" diskový priestor.

Docker Volume Plugin

- Kontajner vidí "súborový systém".
- Súbory môžu byť uložené kdekoľvek inde.
- Pripojí diskový priestor na blokovej úrovni alebo na úrovni FS

