# Zadanie 2 - Kubernetes

Pre študentov odboru Počítačové siete.

Vytvorte a prezentujte nasadenie webovej aplikácie do systému Kubernetes. 
Webová aplikácia by mala byť funkčná. Môžete použiť a upraviť zadanie č. 1.
Zadanie prejde kontrolou originality.

Riešenie by malo obsahovať: 

     - aspoň jeden funkčný objekt typu `Deployment`.
     - aspoň jeden funkčný objekt typu `StatefulSet`.
     - aspoň jeden funkčný objekt typu `Service`.

Zadanie musí obsahovať aspoň tieto súbory:

- `deployment.yaml`: konfiguračný súbor pre objekt typu `Deployment`.
- `statefulset.yaml`: konfiguračný súbor pre objekt typu `StatefulSet`
- `service.yaml`: konfiguračný súbor pre objekt typu `Service`
- `start-app.sh`: skript pre spustenie aplikácie 
- `end-app.sh`: skript pre zastavenie aplikácie
- `README.md`: súbor s dokumentáciou kde predstavíte Vašu aplikáciu a návod na jej spustenie
- `prepare-app.sh`: skript na prípravu aplikácie, zostavenie obrazov a vytvorenie trvalých zväzkov.
- iné potrebné súbory, napr. `Dockerfile`,  sql skripty a pod.

Zadanie odovzdávajte podľa [inštrukcií](../odovzdanie).
