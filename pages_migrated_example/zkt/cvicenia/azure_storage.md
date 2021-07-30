---
title: Azure úložisko
published: true
---

! Naučíte sa:
! - Vytvoriť a použiť statický trvalý zväzok v AKS
! - Vytvoriť a použiť dynamický trvalý zväzok v AKS

## Statické pridelenie úložného priestoru pomocou Azure File

Vytvorené podľa tutoriálu na [Azure Docs](https://docs.microsoft.com/en-us/azure/aks/azure-files-volume).

Trvalý zväzok typu Azure File je adresár ku ktorému prisupujeme pomocou sieťového súborového systému SMB. Pomocou rovnakého protokolu z dielne Microsoftu viete zdieľať zložky cez sieť z Vášho Windows počítača alebo NAS zariadenia. 

Pre uľahčenie použijeme premenné prostredia. 
Do premenných si uložíme:

- Názov skupiny zdrojov (ResorceGroup)
- Miesto dátového centra (Location)
- Názov zdieľanej zložky (ShareName)
- Názov prihlasovacieho účtu k úložisku (StorageAccount)

!! Príkaz export vytvorí premennú, dostupnú v ďalších príkazoch. 
!! premenná `$RANDOM` vráti vždy nové náhodné číslo.

```bash
# Change these four parameters as needed for your own environment
export STORAGE_ACCOUNT_NAME=mystorageaccount$RANDOM
export RESOURCE_GROUP=myAKSShare
export LOCATION=eastus
export SHARE_NAME=aksshare
```

Vytvorte skupinu zdrojov (ResourceGroup) a do skupiny zdrojov vytvorte 
prihlasovací účet k úložisku:


```yaml
# Create a resource group
az group create --name $RESOURCE_GROUP --location $LOCATION
# Create a storage account
az storage account create -n $STORAGE_ACCOUNT_NAME -g $RESOURCE_GROUP -l $LOCATION --sku Standard_LRS
```

Podľa prihlasovacieho účtu vytvorte trvalý zväzok typu Azure File.
Trvalý zväzok sa vytvorí podľa zadaného reťazca na prihlásenie (ConnectionString).
Reťazec na prihlásenie obsahuje meno zložky, meno a heslo na prihlásenie.


```
# Export the connection string as an environment variable, this is used when creating the Azure file share
export AZURE_STORAGE_CONNECTION_STRING=$(az storage account show-connection-string -n $STORAGE_ACCOUNT_NAME -g $RESOURCE_GROUP -o tsv)

# Create the file share
az storage share create -n $SHARE_NAME --connection-string $AZURE_STORAGE_CONNECTION_STRING
```

Vložte údaje o pripojení na trvalý zväzok do Kuberntes.
Údaje uložíte do objektu typu Secret:

```
# Get storage account key
STORAGE_KEY=$(az storage account keys list --resource-group $RESOURCE_GROUP --account-name $STORAGE_ACCOUNT_NAME --query "[0].value" -o tsv)
# Echo storage account name and key
echo Storage account name: $STORAGE_ACCOUNT_NAME
echo Storage account key: $STORAGE_KEY

# Create kuberntes secret
kubectl create secret generic azure-secret --from-literal=azurestorageaccountname=$STORAGE_ACCOUNT_NAME --from-literal=azurestorageaccountkey=$STORAGE_KEY
# Existenciu objektu typu Secret si overte
kubectl get secrets
```

Vytvorte trvalý zväzok.
V trvalom zväzku použijete prihlasovacie údaje uložené do Secret:

```yaml
apiVersion: v1
kind: PersistentVolume
metadata:
  name: azurefile
spec:
  capacity:
    storage: 5Gi
  accessModes:
    - ReadWriteMany
  azureFile:
    # Tu vytvoríte väzbu na prihlasovacie údaje do zväzku
    # prihlasovacie údaje sú v objekte typy Secret
    secretName: azure-secret
    secretNamespace: default
    shareName: aksshare
    readOnly: false
  mountOptions:
  - dir_mode=0755
  - file_mode=0755
  - uid=1000
  - gid=1000
  - mfsymlinks
  - nobrl
```

Vytvorte nárok na trvalý zväzok. 

```yaml
apiVersion: v1
kind: PersistentVolumeClaim
metadata:
  name: azurefile
spec:
  accessModes:
    - ReadWriteMany
  storageClassName: ""
  resources:
    requests:
      storage: 5Gi
```

Teraz môžete vytvoriť objekt kotrý bude využívať trvalý zväzok. Pre jednoduchosť vytvorte priamo objekt typu `Pod`. Objekt Pod obaľuje inštanciu kontajnera, ale bez ďalších vlastností ako je automatický reštart alebo škálovanie ako pri type Deployment. Ale ak chcete, môžete ho rovnakým spôsobom využiť v objekte Deployment alebo StatefulSet.


```yaml
apiVersion: v1
kind: Pod
metadata:
  name: mypod
spec:
  containers:
  - image: mcr.microsoft.com/oss/nginx/nginx:1.15.5-alpine
    name: mypod
    resources:
      requests:
        cpu: 100m
        memory: 128Mi
      limits:
        cpu: 250m
        memory: 256Mi
    volumeMounts:
      - name: azure
        mountPath: /mnt/azure
  volumes:
  - name: azure
    persistentVolumeClaim:
      claimName: azurefile 
```


## Dynamické pridelenie úložného priestoru Azure

https://docs.microsoft.com/en-us/azure/aks/azure-files-dynamic-pv


Vytvorte Storage Class.

```yaml
kind: StorageClass
apiVersion: storage.k8s.io/v1
metadata:
  name: my-azurefile
provisioner: kubernetes.io/azure-file
mountOptions:
  - dir_mode=0777
  - file_mode=0777
  - uid=0
  - gid=0
  - mfsymlinks
  - cache=strict
  - actimeo=30
parameters:
  skuName: Standard_LRS
```

Vytvorte nárok na trvalý zväzok.
Pomocou nároku požiadate o dynamické pridelenie trvalého zväzku zo zvolenej triedy.

```yaml
apiVersion: v1
kind: PersistentVolumeClaim
metadata:
  name: my-azurefile
spec:
  accessModes:
    - ReadWriteMany
  storageClassName: my-azurefile
  resources:
    requests:
      storage: 5Gi
```

Tento trvalý zväzok viete využiť vo svojom nasadení (napr. StatefulSet).


```yaml
apiVersion: v1
kind: Pod
metadata:
  name: mypod2
spec:
  containers:
  - image: mcr.microsoft.com/oss/nginx/nginx:1.15.5-alpine
    name: mypod2
    resources:
      requests:
        cpu: 100m
        memory: 128Mi
      limits:
        cpu: 250m
        memory: 256Mi
    volumeMounts:
      - name: azure
        mountPath: /mnt/azure
  volumes:
  - name: azure
    persistentVolumeClaim:
      claimName: my-azurefile 
```

## Na záver

Nezabudnite zrušiť všetky zdroje čo ste vytvorili.


## Na prečítanie

- [Aký je rozdiel medzi StetefulSet a Deployment](https://medium.com/devops-mojo/kubernetes-difference-between-deployment-and-statefulset-in-k8s-deployments-vs-statefulsets-855f9e897091)
