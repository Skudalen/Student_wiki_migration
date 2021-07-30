---
title: Konfiguračné súbory Kubernetes
published: true
---

! Naučíte sa:
!
! - vytvoriť a zverejniť webový server NGINX.
! - používať menné priestory.
! - vytvárať  a upravovať Kubernetes objekty `Service` a `Deployment` pomocou konfiguračných súborov.


V konfiguračnom súbore definujeme želaný stav aplikácie (nie postupnosť príkazov ako ho dosiahnuť).

Jednoduchým príkazom vieme konfiguráciu upraviť a opäť aplikovať. Kubernetes sa postará o to, aby sa stav objektu upravil podľa potreby. Ak sa konfigurácia nezmenila, neurobí sa nič. Inak sa vykonajú len tie zmeny ktoré sú potrebné a možne. Ak sa zmena konfigurácie nedá spraviť, napr. kvôli závislostiam na iných objektoch, je možné ľahko objekt odstrániť celý a vytvoriť ho nanovo.

Pomocou konfiguračných súborov si vieme poznačiť želaný stav
každého objektu a uložiť napríklad do GIT repozitára.
V prípade havárie alebo servisných zásahov na hardvéri vieme celú inštaláciu zopakovať podľa potreby na inom mieste aj u iného poskytovateľa klaudových služieb.

## Značkovací jazyk YAML

Konfiguračné súbory zapisujeme vo formáte YAML.

[YAML](https://sk.wikipedia.org/wiki/YAML) je
značkovací jazyk pre zápis štruktúrovaných dát
Je ľahký na naučenie a stručný (na rozdiel od XML).
Podobá sa zápisu [JSON](https://en.wikipedia.org/wiki/JSON).
Pozná tieto dátové typy: čísla, reťazce, zoznamy a asociatívne polia.

Štruktúra v YAML sa vyznačuje pomocou odsadenia na začiatku, 
nemusíme používať žiadne zátvorky ani úvodzovky.

Písanie je jednoduché:

```yaml
atribút1: retazec
zoznam: 
    - polozka 2
    - polozka 2
cislo: 4
objekt:
    parameter1: hodnota 1
    zoznam_objektov:
        - o1_parameter1: hodnota2
          o1_parameter2: hodnota2
        - o2_parameter1: hodnota1
          o2_parameter2: hodnota2
```

## Pozrite si konfiguráciu vytvoreného objektu

Vráťte sa k deploymentu vytvorenému minule.
Ak nefunguje, vytvorte ho znova:

```
kubectl create deployment hello-kube --image=k8s.gcr.io/echoserver:1.10
```

Aktuálnu konfiguráciu objektu si môžte aj zobraziť vo formáte YAML:


```
kubectl get deployment hello-kube -o yaml
```

Pozrite sa, ako konfigurácia objektu vyzerá.

Každý Kubernetes objekt má definované tieto atribúty:

- `apiVersion`: Verzia API ktorú objekt využíva
- `kind`: Druh objektu
- `meta`: Informácie o objekte
    - `name`: Meno objektu - to čo sa nám zobrazí v `kubectl get`
    - `labels`: zoznam štítkov objektu - identita pre iné Kubernetes objekty
- `spec`: špecifikácia objektu

Okrem týchto parametrov tam nájdete aj veľa iných. Ich význam si viete pozrieť v dokumentácii k objektu typu [Deployment](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/).

Ukážeme si, ako si vytvoriť minimálnu konfiguráciu objektu typu `Deployment`. Hodnoty ostatných parametrov určí systém Kubernetes.

## Príprava

Na súbory vytvorené v rámci cvičenia je dobré mať osobitnú zložku:

```
cd zkt21
mkdir cv6
cd cv6
```

Súbory si môžete ľahko poznačiť na GITe.

## Menný priestor

Je možné, že na jednom klastri beží viac aplikácií naraz. Objekty ktoré sme vytvorili doteraz sa umiestnili do východiskového menného priestoru `default`.Po čase sa môže stať, že vo východiskovom mennom priestore sa nachádza príliš veľa objektov. Pokiaľ nepovieme inak, tak sa všetky príkazy `kubectl` týkajú východiskového menného priestoru.

Aby bola správa a manažment objektov patriacich k aplikácii jednoduchšia, vieme objekty organizovať do menných priestorov. 

Do jedného menného priestoru vieme uložiť všetky objekty ktoré spolu súvisia, napr. patria k jednej aplikácii.  Menné priestory umožnia správu jednej aplikácie bez toho aby sme ovplyvnili druhú, nesúvisiacu aplikáciu ktorá beží na tom istom klastri.

Pozrite si zoznam všetkých menných priestorov a obsah menného priestoru `kube-system`:

    kubectl get namespaces

Konkrétny menný priestor si zvolíme prepínačom `-n`:

    kubetcl get all -n kube-system

Procesy, ktoré patria ku správe klastra sú umiestnené v mennom priestore `kube-system`. Doteraz vytvorené objekty sa nachádzajú v mennom priesore `default`.


Menný priestor s názvom `cv6` si vytvoríme príkazom:

    kubectl create namespace cv6

Ak chceme zvoliť menný priestor ktorý sme vytvorili, použijeme prepínač `-n`.

Takto zistíme, že nový menný priestor je zatiaľ prázdny.

    kubectl get all -n cv6


Viac o menných priestoroch je v [oficiálnej dokumentácii](https://kubernetes.io/docs/tasks/administer-cluster/namespaces-walkthrough/).

Na uľahčenie prepínania medzi mennými priestormi a medzi viacerými klastrami môžete použiť nástroje [kubectx a kubens](https://github.com/ahmetb/kubectx)

## Konfiguračný súbor pre Kubernetes objekt

Pomocou konfiguračného súboru si vieme objekt opísať oveľa presnejšie ako pomocou viacerých argumentov príkazového riadka.

Do konfiguračného súboru musia ísť všetky povinné položky:

- `apiVersion`:  Do položky `apiVersion` ide použitá verzia API ktorú vyčítame z dokumentácie.
- `meta`: Do atribútu `meta` uvedieme meno objektu, hlavne pre našu potrebu. 
- `kind`:  Do položky `kind` ide typ objektu, teda `Deployment`.
- `spec`:  Do položky `spec` uvedieme podrobnejšiu špecifikáciu - počet inštancií podov na vytvorenie a šablónu podľa ktorej sa pody budú vytvárať.

Zapíšme si jednoduchý objekt typu `Deployment`. Je to podobný proces ako keď sme napísali príkaz `kubectl create`,
ale vieme ovplyvniť viac parametrov.

Vytvorte si textový súbor  `nginx-deployment.yaml` a zapíšte do neho:

```yaml
# verziu API zistíte z dokumentácie
apiVersion: apps/v1
# Druh objektu
kind: Deployment
# O objekte
metadata:
  # Meno objektu
  name: nginxdep
# špecifikácia objektu
spec:
  # Počet podov ktorý sa má vytvoriť
  replicas: 1
  # Selektor vytvára prepojenie Deploymentu a Podu
  # Vyberá tie PODy ktoré majú štítok nginx
  selector:
    matchLabels:
      app: nginx
  # Šablóna PODu
  template:
    metadata:
      # štítok PODu - na spojenie Deploymentu a Podu
      labels:
        app: nginx
    spec:
      # kontajnery PODu
      containers:
      # Len jeden kontajner s aplikáciou nginx
      - name: nginx
        # Meno a verzia obrazu
        image: nginx:1.14.2
        ports:
        # POD má otvorený port 80
        - containerPort: 80
        # Ak je to potrebné, tu uvedieme ďalšiu 
        # konfiguráciu kontajnera, napr. mapovanie zväzkov
        # alebo premenné prostredia
```

Objekt viete vytvoriť pomocou príkazu:

```
kubectl apply -f nginx-deployment.yaml -n cv6
```

Overte si nový stav klastra pomocu  príkazov 
`get`, `logs` a `describe`:

```
kubectl get deployments/nginxdep
kubectl describe deployments/nginxdep
```

Prieskumom zistíte, že objekt `Deployment` vytvoril ešte objekt `ReplicaSet` a ten vytvoril objekt typu `Pod`.
Pod je vytvorený podľa šablóny v časti `template` a má automaticky generované meno, odvodené od mena deploymentu.

Ďalšie informácie o tom ako vytvárať objekt `Deployment` nájdete v [oficiálnej dokumentácii](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/).

## Vytvorenie služby v rámci klastra

K deploymentu je potrebné vytvoriť aj službu aby porty kontajnerov boli prístupne pre iné kontajnery alebo pre používateľov.

Služba je symbolické meno a číslo portu pod ktorým je dostupná funkcionalita v rámci klastra alebo mimo klastra.

Podobne ako pri deploymente, musíme špecifikovať ktoré pody
budú vykonávať službu. Skupinu podov ktoré súvisia so službou definujeme pomocou položky `selector` v časti `meta`.

Vytvorte si súbor `nginx-service.yaml` a zapíšte do neho:


```yaml
# verzia API z dokumentácie
apiVersion: v1
# Druh objektu
kind: Service
# informácie o objekte
metadata:
  # Meno služby
  name: nginxservice
# Špecifikácia služby
spec:
  # Ktoré pody vykonávajú službu
  selector:
    app: nginx
  # Porty služby
  ports:
    - protocol: TCP
      # Port služby
      port: 8800
      # Port na Pode
      targetPort: 80
```

Táto služba vytvorí DNS meno `nginxservice` platné v rámci klastra. Služba prepojí všetky porty 80 na podoch so štítkom `app: nxinx` s DNS menom `nginxservice` a portom 8800.

Viac o tom, ako sa prideľujú DNS mená nájdete v [oficiálnej dokunetácii](https://kubernetes.io/docs/concepts/services-networking/dns-pod-service/)

IP adresa so službou platná v rámci klastra sa dá zistiť aj pomocou [premennej prostredia](https://kubernetes.io/docs/concepts/services-networking/service/#discovering-services) v kontajneri.

Funkčnosť služby si viete overiť tak, že si spustíte príkazový riadok v bežiacom kontajneri a vyskúšate HTTP požiadavku.

Vytvorte si nový kontajner (služba nie je prístupná z kontajnera ktorý službu poskytuje) a vyskúšajte z neho službu
`nginxservice`:


```
# Vytvorenie nového kontajnera
kubectl create deployment inspector --image=k8s.gcr.io/echoserver:1.10 -n cv6
# Zistenie mena podu
kubectl get pod
# Spustenie príkazového riadku v pode
kubectl exec -it <pod_name> bash
# Inštalácia sieťových nástrojov
apt-get upate
apt-get install curl iputils-ping
# Vyskúšate či je meno dostupné
ping nginxservice
# Vyskúšate požiadavku HTTP GET na porte 80
curl nginxservice:8800
# Pozrite si definované premenné prostredia
env
```

V prípade, že sa Vám pri spojení zobrazí chybová správa:

```
Unable to use a TTY - input is not a terminal or the right kind of file
```

pridajte pred `kubectl exec` `winpty kubectl exec`.

Viac o tom ako sa vytvára konfigurácia služby nájdete v [oficiálnej dokumentácii](https://kubernetes.io/docs/concepts/services-networking/service/).

## Zverejnenie služby

Takto definovaná služba je dostupná iba v rámci klastra.
Na to aby bola dostupná aj z vonkajšieho prostredia na porte ľubovoľného uzla klastra,  treba nastaviť jej typ na `NodePort`.

Modifikujte konfiguračný súbor so službou:

```yaml
apiVersion: v1
kind: Service
metadata:
  name: nginxservice
spec:
  # Vyznačenie, ktoré pody budú patriť službe
  selector:
    # Vyberie pody, ktoré majú štítok app=nginx
    app: nginx
  # Typ služby sa mení z ClusterIP na NodePort
  type: NodePort
  ports:
    - protocol: TCP
      # Port služby v rámci Kubernetes
      port: 8800
      # Port na kontajneri
      targetPort: 80
      # Verejný port na každom uzle
      nodePort: 30880
```

Na každom uzle klastra bude otvorený port 30880 (ak to dovoľujú pravidlá firewallu).
Podľa dohody sa porty ktoré otvára systém Kubernetes musia nachádzať v rozsahu 30000-32767.

Zadajte požiadavku na IP adresu stroja minikube a číslo portu 30880. Profíci namiesto prehliadača používajú:

```
curl <IP>:30880
```

Viac o orientácii vo virtuálnych sieťach Kubernetes nájdete v tutoriáli na [Digital Ocean](https://www.digitalocean.com/community/tutorials/how-to-inspect-kubernetes-networking).


## Riešenie problémov pri vytváraní objektov

Ak niečo nefunguje podľa očakávania je najprv potrebné
identifikovať problém.

Najprv overte stav klastra skontrolujte, či sa vytvorili
všetky objekty.

```
kubectl get all
```

Ak je objekt vytvorený, ale nie správne tak overte jeho stav:

```
kubectl describe typ_objektu/meno_objektu
```

Zobrazí sa Vám stav objektu.

Vo výpise sa sústreďte na časti "Conditions" a "Events".
Tam nájdete mená vytvorených podradených objektov, napr. `ReplicaSet`.

Ak nie je v poriadku, pátrajte ďalej. Problém môže byť v podradenom objekte, napr. `Deployment` závisí na `ReplicaSet`
a ten závisí na `Pod`. Zoznam podradených objektov zistíte z výpisu `kubectl describe`.

V niektorých prípadoch má zmysel overovať logy:

```
kubectl logs <typ_objektu>/<meno_objektu>
```

Tak môžete zistiť, že máte preklep v konfiguračnom súbore alebo že sa nepodarilo nadviazať spojenie s databázou.

Ak stále neviete identifikovať problém, pripojte sa do bežiaceho podu príkazom:

```
kubectl exec -it <meno_podu> -- sh
```

a z príkazového riadka skúste vykonať príkaz ktorý Vám nefunguje. Ak má pod viac kontajnerov, kontajner na pripojenie určíme pomocou prepínača `-c <meno_kontajneru>`

Zoznam premenných prostredia v kontajneri zistíte príkazom:

```
kubectl exec <meno podu> env
```

Je možné, že v kontajneri nie sú dostupné základné diagnostické nástroje, ako napr. `ping` alebo `curl`.

V tom prípade je potrebné ich doinštalovať pomocou nástrojov operačného systému v kontajneri, napr.

```
apt-get update
apt-get install <meno balíčka z príkazom>
```

## Zrušenie menného priestoru

Menné priestory nám umpžňujú ľahké "poupratovanie" vytvorených objektov. 
Takto zmažeme celý menný priestor `cv6` vrátane všetkých objektov ktoré sa v ňom nachádzajú. Pred tým je dobré sa pozrieť čo vlastne mažeme.

    kubectl get all -n cv6
    kubectl delete namespace cv6

## Ďalšie materiály

- [Kubernetes kurz](https://kube.academy/courses/kubernetes-101)
- [Play With Kubernetes](https://labs.play-with-k8s.com)
- [Ťahák kubectl](https://kubernetes.io/docs/reference/kubectl/cheatsheet/)
- [Deployment Tutorial](https://devopscube.com/kubernetes-deployment-tutorial/)
- [Deployment Reference](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)
- [Expose tutorial](https://kubernetes.io/docs/tutorials/kubernetes-basics/expose/expose-intro/)
