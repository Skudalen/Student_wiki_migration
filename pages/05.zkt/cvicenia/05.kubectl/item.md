---
title:  Prvé kroky so systémom Kubernetes
published: true
---

! Naučíte sa:
!
! - Komunikovať s klastrom.
! - Vytvoriť a zrušiť jednoduchú aplikáciu.
! - Zistiť stav klastra a stav aplikácie.
! - Zverejniť port aplikácie pomocou služby.

## Vytvorte si pracovné prostredie

Ak máte Docker Desktop, [inštalácia je jednoduchá](/zkt/cvicenia/install_k8sdesktop).
Ak máte VirtualBox použite radšej [Minikube](/zkt/cvicenia/install_minikube).

!!! Kubernetes bežiaci na pozadí môže spomaľovať Váš počítač

S klastrom budete komunikovať pomocou príkazu `kubectl`.
Kubectl používa sieťový protokol pre komunikáciu s aplikačným rozhraním zvoleného Kubernetes klastra, preto musí mať prihlasovacie údaje pre ovládanie klastra.

Najprv vyskúšajte, či klient funguje v poriadku a či má spojenie s klastrom. S ktorým klastrom komunikujem?

```
kubectl cluster-info
```


## Nasadenie aplikácie pomocu objektu Deployment

Na začiatok si skúsime nasadenie jednoduchej aplikácie, ktorá bude vedieť opakovať prijaté požiadavky.
Aplikácia bude vo svojom kontajneri bežať na určitom porte a odpovedať na požiadavky protokolom HTTP.

O úlohy súvisiace s behom aplikácie sa bude starať Kubernetes klaster. Aplikácia sa bude vedieť podľa potreby škálovať a reštartovať na ľubovoľnom uzle.

O beh aplikácie sa starajú špeciálne Kuberntes objekty. Vyjadrujú požadovaný a aktuálny stav aplikácie. Objekty vytvárame priamo pomocou klienta `kubectl` alebo pomocou konfiguračných súborov vo formáte YAML. 

Počas nasadenia prvej aplikácie vznikne Kubernetes objekt typu [Deployment](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/) ktorý sa stará o beh aplikácie. Objekt typu `Deployment` sa bude volať `hello-kube`.

Viac o objekte `Deployment` v [tutoriáli](https://devopscube.com/kubernetes-deployment-tutorial/).

Prvú Kubernetes aplikáciu si vytvoríme príkazom:

```
kubectl create deployment hello-kube --image=k8s.gcr.io/echoserver:1.10
```

## Zisťovanie stavu klastra

Stav objektov v klastri sa v čase mení. Systém priradí vhodný uzol, pokúsi za získať obraz kontajnera a vytvoriť nový proces podľa našich požiadaviek.

O priebehu nasadenia sa viac dozvieme pomocou príkazu `describe`:


```
kubectl describe deployment/hello-kube
```

Ak bolo nasadenie úspešné, vieme si pozrieť výpisy zo štartu kontajnera pomocou príkazu `logs`:


```
kubectl logs deployment/hello-kube
```

Overte si nový stav klastra a pozrite si objekty ktoré vznikli:

```
kubectl get all
```

Malo by sa zobraziť niečo takéto:

```
NAME                              READY   STATUS    RESTARTS   AGE
pod/hello-kube-5d764c75f7-ffv6l   1/1     Running   0          11m

NAME                 TYPE        CLUSTER-IP   EXTERNAL-IP   PORT(S)   AGE
service/kubernetes   ClusterIP   10.96.0.1    <none>        443/TCP   3d16h

NAME                         READY   UP-TO-DATE   AVAILABLE   AGE
deployment.apps/hello-kube   1/1     1            1           11m

NAME                                    DESIRED   CURRENT   READY   AGE
replicaset.apps/hello-kube-5d764c75f7   1         1         1       11m
```

Uvidíte, že okrem `hello-kube` vznikne aj niekoľko ďalších objektov. Každý objekt má svoje meno a svoj druh.

## POD

Základnou jednotkou klaudovej aplikácie v systéme Kubernetes je objekt typu [Pod](https://kubernetes.io/docs/concepts/workloads/pods/pod/). Jeden Pod je tvorený viacerými kontajnermi a zväzkami. Je zaručené, že jeden Pod bude bežať na maximálne jednom uzle. Vďaka tomu môžu jeho kontajnery navzájom ľahko komunikovať pomocou lokálnych portov a zdieľaných zväzkov.

Pozriem si konkrétny druh objektov v klastri:

```
kubectl get pods
```


Podľa mena sa môžme o pode niečo dozvedieť:

```
kubectl describe pods/<pod_name>
```

nám zobrazí aktuálny stav podu v klastri.

## Riešenie problémov

Príkazy `describe` a `logs` vieme použiť na všetky objekty  pri hľadaní a riešení problémov v prípade že klaster nie je v želanom stave.

Chybové hlásenia podu si zobrazíme pomocou:

```
kubectl logs pods/<pod_name>
```

Do bežiaceho podu sa pripojíte pomocou [tohto návodu](https://kubernetes.io/docs/tasks/debug-application-cluster/get-shell-running-container/).

Okrem podu sa vytvorí [ReplicaSet](https://kubernetes.io/docs/concepts/workloads/controllers/replicaset/), ktorá dáva pozor na jeden alebo viacero podov.  Pomocou objektu typu ReplicaSet vieme aplikáciu škálovať - za behu pridávať alebo odoberať záťaž vo forme podov.

V našom príklade sa o vytvorenie `ReplicaSet`-u a `Pod`-u postaral objekt typu [Deployment](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/).

`Deployment` dáva pozor na pody a `ReplicaSet`-y. Jeho úlohou je zabezpečiť, aby hladko fungovali zmeny verzií podov bez toho aby nastalo prerušenie behu aplikácie.

Ak nová verzia podov nebude fungovať, odmietne update a beh bude pokračovať so starou verziou.

## Zrušenie Kubernetes objektov

Ak objekt už nepotrebujeme, je potrebné ho odstrániť aby zbytočne nezaberal systémové zdroje.

Obstránenie objektu sa vykonáva pomocou príkazu:

```
kubectl delete <druh objektu>/<meno objektu>
```

Vyskúšajte zmazať vyvorený Pod a overte si nový stav klastra:


```
kubectl delete pod/<meno podu>
kubectl get all
```

Podobne vyskúšajte zmazať vytvorený ReplicaSet.

- Ak zmažeme POD, ReplicaSet sa postará o spustenie ďalšieho
- Ak zmažeme ReplicaSet, Deployment sa postarrá o znovuspustenie
- Pri rušení objektov by sme mali postupovať v opačnom poradí.
- Ak zmažeme Deployment, Kubernetes sa postará o zrušenie ReplicaSet a Podov. 


## Služby - objekt Service

Na to aby bola aplikácia použiteľná musíme určiť spôsob prístupu k nej. Kontajnery v rámci jedného podu spolu vedia ľahko komunikovať pomocou lokálnych portov, ale inak sú uzavreté pred vonkajším prístupom.

Proces vytvorenia služby je podobný zaregistrovaniu DNS mena
pre Váš server.  Vznikne DNS záznam platný v rámci klastra 
ktorý môžeme využiť na vytvorenie spojenia medzi viacerými PODmi. 

O vykonanie funkcionality služby sa stará skupina Podov ktoré môžu bežať na ktoromkoľvek uzle klastra. Kubernetes sa postará o to, aby na požiadavku odpovedal jeden z nich.

Ak je podov viac, pody musíme navrhnúť tak, aby boli ľubovoľne zameniteľné - je jedno ktorý pod na požiadavku odpovedá. To je dosiahneme tak, že oddelíme dáta od aplikácie. Ak máme dáta na jednom mieste, napr. v databáze, potom je jedno na ktorom mieste sa vykoná spracovanie.

Musíme povedať akým spôsobom a pod akým menom budeme pristupovať k službe, ktorú pod poskytuje.
Na to slúži objekt typu [Service](https://kubernetes.io/docs/concepts/services-networking/service/). 

Vytvorenie objektu `Service` zverejnení službu pre iné pody alebo pre verejnosť mimo klastra.

```
       +----------+
       | Service  |
       | DNS name |
       +----------+
       ^      ^   ^
      /       |    \
     /        |     \
    |         |      |
+-------+ +-------+ +-------+
| Pod 1 | | Pod 2 | | Pod 3 |
+-------+ +-------+ +-------+

```

Vytvorí sa symbolické DNS meno pod ktorým je prístupná služba. 

Dôležité druhy služieb:

- `ClusterIP`: dostupná v rámci klastra.
- `NodePort`: dostupná z vonku na každom uzle.
- `LoadBalancer`: dostupná pomocou nástrojov poskytovateľa.

Službu s menom `hello-kube` typu `NodePort` vytvoríme príkazom:

```
kubectl expose deployment hello-kube --type=NodePort --port=8080
```


Overte si nový stav Vášho klastra pomocou príkazového riadka:

```
kubectl get all
```

Môžeme sa aj pozrieť bližšie len na služby:

```
kubectl get services
```

Zobrazí sa nám zoznam služieb. Vieme z neho vyčítať, na ktorom porte bude služba zverenená. 

Dostaneme niečo takéto:

```
hello-kube   NodePort    10.111.243.205   <none>        8080:32453/TCP   5s
kubernetes   ClusterIP   10.96.0.1        <none>        443/TCP          4d22h
```

Číslo verejného portu je za dvojbodkou. `NodePort` znamená, že služba beží na každom pracovnom uzle nášho klastra. V tomto prípade je číslo verejného portu automaticky vygenerované a vo Vašom prípade môže byť iné. Verejný port sa dá nastaviť aj podľa našich požiadaviek. 

Vieme si ho vyskúšať pomocou webového prehliadača alebo pomocou príkazu curl:

```
curl -X GET http://localhost:32453
```

Na obrazovke by sa mala zobraziť odpoveď echoservra na našu požiadavku.


## Textovo-grafické rozhranie

Ak na klastri beží viac aplikácií, oceníte konzolový nástroj pre zisťovanie stavu klastra s názvom `k9s`:

Nainštalujete si ho jednoducho:

    wget https://github.com/derailed/k9s/releases/download/v0.24.2/k9s_Linux_x86_64.tar.gz 
    tar zxf k9s_Linux_x86_64.tar.gz
    sudo mv k9s /usr/local/bin

