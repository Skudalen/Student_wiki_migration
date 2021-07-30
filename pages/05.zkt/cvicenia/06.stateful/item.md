---
title: Stavové aplikácie, virtuálne disky v Kubernetes
published: true
---

! Naučíte sa
! 
! - Vytvoriť trvalý zväzok.
! - Vytvoriť aplikáciu, ktorá vie uchovať svoj stav vo zväzku.
! - používať objekty `StatefulSet`, `PersistentVolumeClaim`, `PersistentVolume`.

## Trvalé Zväzky a dáta Kubernetes

Vo svete Kubernetes musíme rátať s tým, že kontajner sa môže naštartovať na ktoromkoľvek uzle a kedykoľvek môže skončiť svoju činnosť. To nie je problém v prípade, že kontajner iba spracúva požiadavky a posiela odpovede, napr. vykonáva nejaké výpočty. Komplikácia nastáva, ak kontajner ukladá
dôležité dáta.

Ak výstup aplikácie závisí iba od vstupu tak vravíme, že aplikácia je bezstavová - nič okrem vstupu neovplyvňuje výstup. Príkladom môže byť služba na kompresiu obrázkov - z nekomprimovaného obrázku na vstupe vie vyrobiť komprimovaný obrázok a nepotrebuje žiadne ďalšie údaje.
Ak kontajner nemá svoj stav, tak je v zásade jedno, na ktorom uzle beží.

Ak kontajner ukladá a číta nejaké dáta a dáta ovplyvňujú výsledok spracovania, vravíme že má svoj stav.
Stav je množina dát ktorá je dôležitá pre výsledok spracovania. Príkladom je databáza - podľa príkazov upravuje alebo číta množinu súborov v nejakom adresári.
Je jasné, že nastanú problémy, ak databáza prestane fungovať na jednom uzle a presunie sa na druhý ak sa nepresunú aj súbory ktoré predstavujú stav databázy.

Väčšinou sa tento problém rieši tak, že dôležité súbory
vyjadrujúce stav sa nachádzajú na osobitnom mieste na to určenom, napríklad na sieťovom súborovom systéme ktorý je prístupný zo všetkých uzlov. Ak vieme správne oddeliť stav od zvyšku kontajnera, tak je možné ľahko reštartovať pod na inom uzle, lebo dôležité dáta zostávajú stále na jednom mieste.

## Trvalé zväzky

Trvalé zväzky (`PersistentVolumes`) sú spôsob, ako oddeliť stav aplikácie od kontajnera.

`PersistentVolume` je typ objektu, ktorý vyjadruje jedno miesto kde je možné uložiť dáta - celý disk, adresár, sieťový disk alebo zdieľaný adresár v sieťovom súborovom systéme.

Poznáme viac druhov trvalých zväzkov podľa toho, aký zdroj reprezentujú:

- `hostPath`: adresár na aktuálnom uzle (použiteľné len pre jednouzlový klaster)
- `localPersistentVolume`: adresár alebo disk na konkrétnom uzle.
- `iSCSI`: sieťový disk storage servra s protokolom iSCSI
- `NFS`: zdieľaný sieťový adresár UNIX
- `GlusterFS`: distribuovaný súborový systém
- `RBD`: blokové zariadenie distribuovaného súborového systému Ceph
- rôzne iné spôsoby pre rôznych poskytovateľov (Azure, Amazon,Google.. )

[Oficiálna dokumentácia trvalých zväzkov](https://kubernetes.io/docs/concepts/storage/persistent-volumes/)

Druh trvalého zväzku vyberieme podľa toho, akú diskovú kapacitu máme k dispozícii.
Objekt s trvalým zväzkom vieme vytvoriť ručne alebo automaticky podľa požiadavky.

## Trvalý zväzok v Docker Engine

Pokiaľ používame inštaláciu Kubernetes pomocou Docker Engine tak trvalý zväzok implementujeme pomocou `hostPath`.

Viac nájdete v [tutoriáli](https://laptrinhx.com/using-kubernetes-local-persistent-volumes-on-docker-desktop-1704935115/).

Vytvorte si konfiguračný súbor `desktoppv1.yaml` s trvalým zväzkom.


```yaml
apiVersion: v1
kind: PersistentVolume
metadata:
  name: desktoppv1
labels:
  type: local
spec:
  storageClassName: local
  capacity:
    storage: 1Gi
  accessModes:
    - ReadWriteOnce
  persistentVolumeReclaimPolicy: Delete
  hostPath:
    path: "/tmp/desktoppv1"
```

Trvalé zväzky v klastri nepatria do žiadneho menného priestoru,

Takto si vytvoríte trvalý zväzok:

    kubectl apply -f desktoppv1.yaml
    kubectl get pv

Trvalý zväzok vyjadrí, že je dostupný priestor v konkrétnom adresári na virtuálnom stroji kde beží Kuberntes a "obalí" ho kubernetes objektom typu `PersistentVolume`. Ak chceme tento priestor využiť v niektorom kontajneri, musíme vytvoriť mapovanie.

Na konfiguráciu automatického prideľovania slúži objekt typu `StorageClass`. Ak je na to systém nakonfigurovaný, tak sa automaticky z dostupnej diskovej kapacity vyhradí časť podľa požiadavky.

Ak nie, tak potom systém čaká na to aby administrátor vytvoril priestor (adresár alebo disk) ručne a k nemu vytvoril objekt typu `PersistentVolume`. 

## StatefulSet

Mapovanie medzi trvalým zväzkom a Podom zabezpečuje objekt typu `PersistentVolumeClaim`. Tento objekt vyjadruje konkrétnu požiadavku aplikácie na úložný priestor. Ak ku nemu existuje `PersistentVolume` ktorý vyhovuje požiadavke, tak sa vytvorí mapovanie.

Tento objekt môžeme vytvoriť samostatne, alebo využijeme špeciálny objekt typu `StatefulSet`. Ten obsahuje pravidlá pre vytváranie a rušenie podov na ľubovoľnom uzle tak, aby sa zachoval prístup k ich stavu. Ak sa dáta aplikácie
nachádzajú na lokálnom disku, tak Kubernetes zabezpečí to, aby pod vykonával iba na tom uzle, kde sa nachádza zväzok. Vďaka tomu sú súbory v trvalom zväzku prístupné transparentne. Kontajner spravidla nemusí vedieť, kde a ako sú uložené súbory s ktorými pracuje.


Vyskúšajme si príklad na `StatefulSet` a ukážme si nasadenie relačnej databázy. 

Objekt `StatefulSet` bude podobný ako objekt typu `Deployment`, 
ale bude obsahovať aj šablónu pre vytvorenie požiadavky 
na trvalý zväzok typu `PersistentVolumeClaim`:

Vytvorte si súbor `postgres_ss.yaml` a zapíšte do neho:

```yaml
# Použité API
apiVersion: apps/v1
# Druh objektu
kind: StatefulSet
# Meno objektu
metadata:
  name: postgres
# Špecifikácia objektu
spec:
  # prepojenie s podom podľa štítku podu
  selector:
    matchLabels:
      app: postgres
  # meno služby
  serviceName: postgres
  # Počet inštancií podov
  replicas: 1
  # Šablóna podu
  template:
    metadata:
      # Štítok podu
      labels:
        app: postgres
    spec:
      # Kontajnery podu
      containers:
        # meno kontajnera
      - name: postgres
        # Meno obrazu
        image: postgres:10.5
        # otvorený port kontajnera
        ports:
          - name: postgres
            containerPort: 5432
            protocol: TCP
        # Premenné prostredia pre konfiguráciu kontajnera
        env:
            # Meno používateľa databázy
          - name: POSTGRES_USER
            value: postgres
            # Meno databázy
          - name: POSTGRES_DB
            # Heslo na pripojenie do databázy
            value: postgres
          - name: POSTGRES_PASSWORD
            value: verysecret
        # Požiadavky na trvalý zväzok
        volumeMounts:
          - mountPath: /var/lib/postgresql/data
            # Meno požiadavky na zväzok 
            name: postgrespvc
  volumeClaimTemplates:
  - metadata:
      # meno požiadavky na trvalý zväzok
      # Musí byť rovnaké ako meno zväzku 
      # vo volumeMounts v Pode
      name: postgrespvc
    spec:
      accessModes: ["ReadWriteOnce"]
      # Automatické pridelenie trvalého zväzku
      # Podľa toho vieme, ktorý zväzok prideliť
      storageClassName: "local"
      resources:
        requests:
          # Požiadavky na veľkosť trvalého zväzku
          storage: 1Gi
```

V časti `volumeClaimTemplates` zapisujeme šablóny pre požiadavky na trvalý zväzok typu `PersistentVolumeClaim` (môže ich byť aj viac).
V tomto prípade sme deklarovali záujem o adresár s veľkosťou minimálne 1 GB (`storage: 1Gi`) do ktorého sa dá zapisovať maximálne jedným procesom a čítať ľubovoľným počtom procesov
(`accessMode: ["ReadWriteOnce"]`). Požiadali sme o automatické pridelenie trvalého zväzku  (`storageClassName: local`).

Vytvorme si objekt typu `StatefulSet`

    kubectl apply -f  postgres_ss.yaml -n cv6

Pri vytvorení objektu typu `StatefulSet` sa automaticky vytvorí aj objekt typu `PersistentVolumeClaim` ktorý reprezentuje požiadavku na vytvorenie trvalého zväzku. Overme si čo sa deje v našom klastri:

```
# Najdôležitejšie objekty, ale PersistentVolumeClaim nevidno
kubectl get all -n cv6
kubectl describe statefulset/postgres -n cv6
# PersistenVolume Claim musíme pozrieť samostatne
kubectl get pvc -n cv6
# Zistite meno požiadavky na trvalý zväzok
kubectl describe statefulsets/postgres -n cv6
kubectl describe pvc/postgrespvc-postgres-0 -n cv6
# Pozrieme v akom stave je trvalý zväzok
kubectl describe desktoppv1
```

Objekt `StatefulSet`, podobne ako `Deployment` vytvorí objekty typu `ReplicaSet` a `Pod`.
Okrem toho vytvorí aj požiadavku na vytvorenie trvalého zväzku typu `PersistentVolumeClaim` podľa zadanej šablóny.
Keď k objektu `PersistentVolumeClaim` existuje vhodný objekt typu `PersistentVolume` (trvalý zväzok), tak je možné vytvoriť mapovanie a spustiť nový pod manažovaný objektom typu `StatefulSet`.


Databáza by mala bežať. Ak nie, tak pátrajte po príčine pomocou  príkazov `get`, `describe` alebo `logs`.

### Zverejnenie služby

Ak je trvalý zväzok v poriadku, môžeme si vyskúšať funkčnosť
nového objektu typu `StatefulSet`.

Prítomnosť novej služby v klastri vyjadríme pomocou objektu `Service`. Tým povieme pod akým menom a portom bude služba dostupná.

Vytvorme si službu s databázou `postgresql`  aby ju iné objekty vedeli využívať.

Konfiguráciu služby si uložte napr. do súboru `postgres-service.yaml`.


```
apiVersion: v1
kind: Service
metadata:
  name: postgresservice
spec:
  selector:
    app: postgres
  type: ClusterIP
  ports:
    - protocol: TCP
      # Port služby
      port: 5432
      # Port kontajnera
      targetPort: 5432
```

Táto služba s názvom `postgresservice` bude dostupná iba v rámci klastra na porte 5432.

## Grafické rozhranie k databáze

Vytvorme si rozhranie pomocou ktorého sa vieme napojiť na databázu. 

Webové rozhranie "pgadmin" bude bežať ako samostatný objekt typu `Deployment` so službou. Keď sa na ňu pripojíme pomocou webového prehliadača, budeme mať k dispozícii aj službu databázy. Databáza bude bežať pod DNS menom `postgresservice`.

Rozhranie "pgadmin" bude prístupné z prehliadača na porte 30881.

V tomto príklade umiestnime službu aj deployment do jedného súboru, konfigurácie sú oddelené `---`.

Súbor `pgadmin-deploymentservice.yaml`:

```yaml
apiVersion: v1
kind: Service
metadata:
  name: pgadmin
spec:
  selector:
    app: pgadmin
  # Typ služby sa mení z ClusterIP na NodePort
  type: NodePort
  ports:
    - protocol: TCP
      port: 8800
      targetPort: 80
      # Port viditeľný na každom uzle
      nodePort: 30881
---
# verziu API zistíte z dokumentácie
apiVersion: apps/v1
# Druh objektu
kind: Deployment
# O objekte
metadata:
  # Meno objektu
  name: pgadmin-deployment
# špecifikácia objektu
spec:
  # Počet podov ktorý sa má vytvoriť
  replicas: 1
  # Selektor vytvára prepojenie Deploymentu a Podu
  # Vyberá tie PODy ktoré majú štítok nginx
  selector:
    matchLabels:
      app: pgadmin
  # Šablóna PODu
  template:
    metadata:
      # štítok PODu - na spojenie Deploymentu a Podu
      labels:
        app: pgadmin
    spec:
      # kontajnery PODu
      containers:
      # Len jeden kontajner s aplikáciou nginx
      - name: pgadmin
        # Meno a verzia obrazu
        image: dpage/pgadmin4
        ports:
        # POD má otvorený port 80
        - containerPort: 80
        env:
        - name: PGADMIN_DEFAULT_EMAIL
          value: admin@admin.sk
        - name: PGADMIN_DEFAULT_PASSWORD
          value: verysecret
```

Aplikujeme konfiguráciu a po čase by v klastri mala bežať webová aplikácia pomocou ktorej sa vieme pripojiť na databázu a niečo do nej vložiť.

Pomocou premenných prostredia vieme určiť prihlasovacie meno a heslo. 

## Ďalšie materiály

- [Oficiálny StatefulSet tutoriál](https://kubernetes.io/docs/tutorials/stateful-application/basic-stateful-set/)
- [Lokálne zväzky Kubernetes](https://vocon-it.com/2018/12/20/kubernetes-local-persistent-volumes/)


