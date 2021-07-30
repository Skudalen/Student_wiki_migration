# Prvé kroky so systémom Kubernetes

Naučíte sa:

- Vytvoriť jednoduchý Kubernetes klaster z jedného uzla.
- Komunikovať s klastrom.
- Spustiť a zastaviť jednoduchú aplikáciu.
- Zistiť stav klastra a stav aplikácie.

## Vytvorte si pracovné prostredie

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
Následne si všimnete, že Vaše internetové pripojenie bude fungovať veľmi zle. Medzi sieťovými adaptermi sa Vám zjaví "Network Bridge". Keď si toto rozkliknete, vo vlastnostiach nájdete "Internet Protocol Version 4 (TCP/IPv4)" (v spodnom okne). Tento si zakliknite a internet by mal fungovať správne.

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

## Vyskúšajte prvé kroky s kubectl

Na začiatok si skúsime nasadenie jednoduchej aplikácie, ktorá bude vedieť opakovať prijaté požiadavky.
Aplikácia bude vo svojom kontajneri bežať na určitom porte na
stroji `minkube` a odpovedať na požiadavky protokolom HTTP.

Rozdiel bude ten, že o úlohy súvisiace s behom aplikácie sa bude starať Kubernetes klaster. Aplikácia sa bude vedieť podľa potreby škálovať a reštartovať na ľubovoľnom uzle.

Prvú Kubernetes aplikáciu si vytvoríme príkazom:
```
kubectl create deployment hello-minikube --image=k8s.gcr.io/echoserver:1.10
```

Vznikne objekt typu [Deployment](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/) ktorý sa stará o beh aplikácie. Objekt typu `Deployment` sa bude volať `hello-minikube`.

Viac o objekte `Deployment` v [tutoriáli](https://devopscube.com/kubernetes-deployment-tutorial/).

Overte si nový stav klastra a pozrite si objekty ktoré vznikli:

```
kubectl get all
```

Uvidíte, že okrem `hello-minikube` vznikne aj niekoľko ďalších objektov. Každý objekt má svoje meno a svoj druh.


Základnou jednotkou je objekt typu [Pod](https://kubernetes.io/docs/concepts/workloads/pods/pod/). Jeden Pod je tvorený viacerými kontajnermi a zväzkami. Je zaručené, že jeden Pod bude bežať na maximálne jednom uzle. Vďaka tomu môžu jeho kontajnery navzájom ľahko komunikovať pomocou lokálnych portov a zdieľaných zväzkov.

Pozriem si konkrétny druh objektov v klastri:

```
kubectl get pods
```

Podľa mena sa môžme o pode niečo dozvedieť:

```
kubectl describe pods/<pod_name>
```

nám zobrazí aktuálny stav podu v klastri.

Chybové hlásenia podu si zobrazíme pomocou:

```
kubectl logs pods/<pod_name>
```

Príkazy `describe` a `logs` vieme použiť na všetky objekty  pri hľadaní a riešení problémov v prípade že klaster nie je v želanom stave.

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

Ak zmažeme POD, Replica Set sa postará o spustenie ďalšieho
Ak zmažeme ReplicaSet, Deployment sa postarrá o znovuspustenie
Pri rušení objektov by sme mali postupovať v opačnom poradí.
Ak zmažeme Deployment, Kubernetes sa postará o zrušenie Replica Set a Podov. 

## Služby

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

- ClusterIP: dostupná v rámci klastra.
- NodePort: dostupná z vonku na každom uzle.
- LoadBalancer: dostupná pomocou nástrojov poskytovateľa.

Službu s menom `hello-minikube` typu `NodePort` vytvoríme príkazom:

```
kubectl expose deployment hello-minikube --type=NodePort --port=8080
```

Tým na virtuálnom stroji `minikube` otvoríme port 8080 ktorý môžme skontrolovať pomocou webového prehliadača.

Overte si nový stav Vášho klastra pomocou príkazového riadka

```
kubectl get all
```

alebo si pozrite Dashboard v prehliadači.

IP adresu virtuálneho stroja zistíme pomocou príkazu:

```
minikube ip
```

Zoznam podov a iné užitočné informácie sa nachádzajú v opise deploymentu:


```
kubectl describe deployment/hello-minikube
```

Nakoniec skúste pomocou `kubectl delete` zrušiť všetky objekty.


## Dodatočné zdroje

Pri ďalšom štúdiu využijete tieto materiály:

- Čo je to [Kubernetes](https://kubernetes.io/docs/concepts/overview/what-is-kubernetes/)?
- Kubernetes [tutoriál pre začiatočníkov](https://devopscube.com/kubernetes-tutorials-beginners/).
- Interaktívny kurz  [Kubernetes](https://www.katacoda.com/courses/kubernetes) na platforme Katacoda.
- Začiatky s [Minikube](https://kubernetes.io/docs/setup/learning-environment/minikube/).
- Začiatky s [kubectl](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#-strong-getting-started-strong-)
- [Kubectl run](https://medium.com/@mhausenblas/the-kubectl-run-command-27c68de5cb76)
- [Kubernetes na Azure](https://docs.microsoft.com/en-us/azure/aks/tutorial-kubernetes-prepare-app)
