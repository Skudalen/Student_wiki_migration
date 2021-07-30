---
title: Azure Container Instances
published: true
---

! Naučíte sa:
!
! - Použiť vlastný kontajner a register obrazov na nasadenie aplikácie do verejného klaudu.
! - Nasadiť aplikáciu pomocou Azure Container Instances.

# Zostavenie obrazu kontajnera

Zoberme si jednoduchú aplikáciu z minulého cvičenia:

```python
from datetime import date
from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "<h1 style='color:blue'>Hello There!</h1><a href='/date'>Dátum a čas</a>"

@app.route("/date")
def today():
    today = date.today()
    return "<p>{}</p>".format(today.strftime("%d.%m.%Y"))

if __name__ == "__main__":
    app.run()
```
Pre aplikáciu ktorá má zložitejšie závislosti je výhodné vytvoriť obraz kontajnera. Do súboru `Dockerfile` zapíšeme postup pre inštaláciu a konfiguráciu všetkého potrebného na jej beh. To nám uľahčí jej spustenie v prostredí verejného alebo súkromného klaudu.


```Dockerfile
FROM python:3.8-alpine
WORKDIR /app
RUN pip install Flask
COPY ./app.py /app
ENV FLASK_APP app.py
ENTRYPOINT [ "flask" ]
CMD ["run", "--host", "0.0.0.0", "--port", "80"]
```

Zostavte obraz kontajnera a prideľte mu nejaké meno.

    docker build . -r pozdravma:dev

## Register obrazov

Ak chcete vo verejnom klaude použiť vlastný obraz kontajnera tak ho musíte najprv umiestniť do dostupného registra obrazov. 
Register obrazov je miesto, z ktorého je možné získať na požiadanie obraz z ľubovoľného pracovného uzla v klaude. 

Bude to vyzerať asi takto:

                                 Verejný Cloud

    +---------------+           +----------+             +-----------+
    | lokálny stroj |  docker   | register |    docker   | container |
    | docker build  |  push --->| obrazov  |    pull --->| instance  |
    +---------------+           +----------+             +-----------+

Register obrazov musí byť zabezpečený pred neoprávneným prístupom.
Obraz kontajnera môže obsahovať aj citlivé dáta alebo zdrojové kódy ktoré nechceme zdieľať s hocikým. Register musíme nastaviť tak aby sme z lokálneho stroja mali právo na zápis a aby pracovný uzol na klaude mal právo na čítanie.


## Vytvorenie registra obrazov

Na to aby sme mohli použiť vlastný obraz v Azure tak ho musíme uložiť do vlastného registra obrazov. 
Do registra si viete uložiť ľubovoľný lokálny obraz kontajnera.

Najprv si vytvoríme skupinu zdrojov (`resourcegroup`).
Do skupiny zdrojov vytvoríme register. Registru vymyslite nejaké pekné meno.
Meno registra musí byť originálne aby nevznikla kolízia s nejakým iným projektom.

```bash
az group create --name mrg --location eastus   
az acr create --resource-group mrg --name registerkvietocek --sku Basic
```

## Zápis do registra obrazov

Najprv musíme povoliť zápis do nového registra. 
Spojte lokálny klient docker a Registry

    # Funguje to?
    az acr login --name registerkvietocek

Ak tento spôsob prihlásenia nefunguje, musíte spojiť docker klienta a register obrazov pomocou prihlasovacieho mena a hesla. 
Prihláste sa  cez webový prehliadač na Azure portál, nájdite si register. V časti "Settings-Access Keys"
zaškrtnite "Admin User". Zobrazí sa Vám prihlasovacie meno a heslo.

    # Ak to nefunguje
    docker login registerkvietocek.azurecr.io

DNS meno registra obrazov musí byť zakódované do názvu obrazu ktorý sme vytvorili.  Meno registra je zakódované  do mena obrazu kontajnera pred lomítko `/`.

    menoregistra/menoobrazu:tag

    docker tag pozdravma:dev registerkvietocek.azurecr.io/pozdravma:dev
    docker push registerkvietocek.azurecr.io/pozdravma:dev

Príkazom `docker push` odošlete obraz.
Nájdite URL aplikácie a vyskúšajte či funguje.

## Vytvorenie kontajnera pomocou ACI

Na vytvorenie kontajnera použijeme službu "Azure Container Instances".
Všimnite si, že príkaz na vytvorenie kontajnera  je podobný príkazu `docker run`. Do argumentov uvedieme meno obrazu, meno kontajnera a zoznam portov ktoré inštancia používa. 

    az container create --resource-group mrg --name mycontainer --image registerkvietocek.azurecr.io/pozdrav:dev --dns-name-label kvietocek-demo --ports 80

!! ACI nepodporuje mapovanie portov - port ktorý uvediete musí byť zhodný s portom ktorý je otvorený na kontajneri. Tento port bude zverejnený.

Podrobná dokumentácia [az container create](https://docs.microsoft.com/en-us/cli/azure/container?view=azure-cli-latest#az_container_create).

Prístupové práva ku registru obrazov viete nastaviť pomocou argumentov: 
    
    [--registry-login-server]
    [--registry-password]
    [--registry-username]

Trvalé zväzky viete namapovať pomocou:

    [--azure-file-volume-account-key]
    [--azure-file-volume-account-name]
    [--azure-file-volume-mount-path]
    [--azure-file-volume-share-name]

Premenné prostredia viete nastaviť pomocou `[--environment-variables]`.

Zistite dns meno pod ktorým je kontajner prístupný. Meno kontajnera sa dá zistiť pomocou `az` a z web rozhrania. 

    az container show --resource-group mrg --name mycontainer --query "{FQDN:ipAddress.fqdn,ProvisioningState:provisioningState}" --out table

Pozrite si aplikáciu. Aplikácia bude bežať na porte ktorý ste jej pridelili.
Skúste zmeniť port aplikácie. 

Pozrite si logy aplikácie:

    az container logs --resource-group mrg --name mycontainer

## Vyčistite po sebe prostredie

Vymažete celú skupinu prostriedkov. Takto vymažete aj register obrazov s jeho obsahom. 

    az group delete --name mrg

## Bibliografia

- Skúste aj toto Azure Conteiner Instances: https://azure.microsoft.com/en-us/services/container-instances/
- https://docs.microsoft.com/en-us/azure/app-service/tutorial-custom-container?pivots=container-linux/
- https://docs.microsoft.com/en-us/learn/modules/deploy-run-container-app-service/
- https://docs.microsoft.com/en-us/azure/app-service/quickstart-custom-container
- https://docs.microsoft.com/en-us/azure/aks/tutorial-kubernetes-prepare-acr
