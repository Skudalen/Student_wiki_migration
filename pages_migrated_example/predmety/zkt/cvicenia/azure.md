
# Azure Kubernetes Service

- Prihlásenie sa do Azure
- vytvorenie AKS Clustra
- Riadkový klient Azure (az)
- spojenie kubectl a AKS

https://portworx.com/ha-postgresql-azure-aks/

Minikube Ingress https://minikube.sigs.k8s.io/docs/tutorials/nginx_tcp_udp_ingress/

### Škálovanie StatefulSet

https://kubernetes.io/docs/tasks/run-application/scale-stateful-set/

Úprava počtu podov ktoré bežia naraz.

Keďže máme k dispozícii "klaster", môžeme využiť jeho výkon. 

### Rolling update

Zmena verzie kontajnera.

Distribúcia novej verzie na klaster.

Ako to urobiť tak, aby služba bežala bez prerušenia.

V prípade, že sa upgrade nepodarí (nová verzia sa nespustí)
tak sa objekt Deployment postará o to aby stále bežala stará verzia a nedošlo k výpadku.

 Ako kopírovať z Kubernetes kontajnera
 https://medium.com/@nnilesh7756/copy-directories-and-files-to-and-from-kubernetes-container-pod-19612fa74660

## Ako použijem vlastný docker Obraz v minikube

- Zverejním svoj obraz na Docker Hube
- Použijem privátny register obrazov
- spojím docker klienta s docker démonom v minikube

```
eval $(minikube docker-env)

Note: Later, when you no longer wish to use the Minikube host, you can undo this change by running:

eval $(minikube docker-env -u).
```

```
docker build . -t myimage
```

