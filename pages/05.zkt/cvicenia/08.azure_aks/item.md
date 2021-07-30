---
title: Azure Kubernetes Service
published: true
---

! Naučíte sa:
!
! - vytvorenie AKS Clustra
! - spojenie kubectl a AKS

!!! Musíte mať nainštalovanú najnovšiu verziu Azure klienta `az` a kubernetes klient `kubectl`. [Takto](https://docs.microsoft.com/en-us/cli/azure/install-azure-cli-linux?pivots=apt#option-1-install-with-one-command) nainštalujete najnovšiu verziu az do prostredia Ubuntu (aj na WSL2) jediným príkazom.



Prihláste sa na Azure a vytvorte ResourceGroup

```bash
az login
az group create --name mrg --location eastus
```

Vytvorte klaster zložený z jedného uzla:

```bash
az aks create --resource-group mrg --name mycluster --node-count 1 --enable-addons monitoring --generate-ssh-keys
```

Vytvorenie bude chvíľu trvať. Vytvorí sa ešte jedna ResourceGroup určená na prostriedky súvisiace s infraštruktúrou klastra.

Prepojte riadkového klienta kubectl s Azure Kubernetes klastrom:

```bash
az aks get-credentials --resource-group mrg --name mycluster
```

Overte si či spojenie funguje:

    kubectl get nodes

## Kontexty kubectl

Príkaz kubectl je schopný riadiť viac klastrov zároveň. Používa na to takzvané kontexty. V prípade, že spojenie nefunguje overte si aktuálny kontext:

    kubectl config get-contexts

Aktuálny kontext môžete zmeniť pomocou

    kubectl config use-context


Vyskúšajte nasadiť túto skúšobnú aplikáciu:

```
apiVersion: apps/v1
kind: Deployment
metadata:
  name: azure-vote-back
spec:
  replicas: 1
  selector:
    matchLabels:
      app: azure-vote-back
  template:
    metadata:
      labels:
        app: azure-vote-back
    spec:
      nodeSelector:
        "beta.kubernetes.io/os": linux
      containers:
      - name: azure-vote-back
        image: mcr.microsoft.com/oss/bitnami/redis:6.0.8
        env:
        - name: ALLOW_EMPTY_PASSWORD
          value: "yes"
        resources:
          requests:
            cpu: 100m
            memory: 128Mi
          limits:
            cpu: 250m
            memory: 256Mi
        ports:
        - containerPort: 6379
          name: redis
---
apiVersion: v1
kind: Service
metadata:
  name: azure-vote-back
spec:
  ports:
  - port: 6379
  selector:
    app: azure-vote-back
---
apiVersion: apps/v1
kind: Deployment
metadata:
  name: azure-vote-front
spec:
  replicas: 1
  selector:
    matchLabels:
      app: azure-vote-front
  template:
    metadata:
      labels:
        app: azure-vote-front
    spec:
      nodeSelector:
        "beta.kubernetes.io/os": linux
      containers:
      - name: azure-vote-front
        image: mcr.microsoft.com/azuredocs/azure-vote-front:v1
        resources:
          requests:
            cpu: 100m
            memory: 128Mi
          limits:
            cpu: 250m
            memory: 256Mi
        ports:
        - containerPort: 80
        env:
        - name: REDIS
          value: "azure-vote-back"
---
apiVersion: v1
kind: Service
metadata:
  name: azure-vote-front
spec:
  type: LoadBalancer
  ports:
  - port: 80
  selector:
    app: azure-vote-front
```

Táto aplikácia nevie udržať svoj stav, alebo nepoužíva trvalé zväzky.


## Bibliografia

- https://docs.microsoft.com/en-us/azure/aks/kubernetes-walkthrough
