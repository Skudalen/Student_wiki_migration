---
title: Dockerfile
published: true
--- 

# Vytváranie vlastných obrazov

Naučíte sa:

- Vytvoriť vlastný obraz pomocou `docker build`
- Určiť príkaz na vykonanie
- Určiť systém na konfigurovanie


Vytvorte jednoduchú webovú aplikáciu pomocou skriptovacieho jazyka Python a frameworku [Flask](https://flask.palletsprojects.com/en/1.1.x/). V aplikácii definujeme niekoľko funkcií ktoré vedia spracovať HTTP požiadavky a vrátiť odpoveď vo forme HTML. 

V našom prípade si vytvoríme aplikáciu, ktorá vie pozdraviť a vie povedať aktuálny čas:

Zdrojový text aplikácie: `app.py`

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

Ak by sme takúto aplikáciu chceli spustiť klasickým spôsobom, potrebujeme:

- mať nainštalovaný interpret jazyka Python3
- [nainštalovať framework Flask](https://flask.palletsprojects.com/en/1.1.x/installation/#install-flask)
- spustiť aplikáciu z príkazového riadka tak aby počúvala na určenom porte.
- pomocou webového prehliadača vykonať požiadavku a zobraziť výsledok.

To si vyžaduje vykonanie viacerých príkazov aby sa aplikácia dostala do požadovaného stavu.
Napr. ak máme k dispozícii OS Linux typu Debian alebo Ubuntu:

```
pip install flask
export FLASK_APP=app.py
flask run --host=0.0.0.0
```
## Príprava Docker obrazu

Ak chceme takúto aplikáciu distribuovať, musíme sa pripraviť na rôzne situácie a zabezpečiť aby boli splnené všetky závislosti -
nainštalovaný Python a nainštalované potrebné knižnice. Postup na splnenie závislostí sa odlišuje podľa toho aké prostredie používame - bude iný na prostredí Windows, iný na rôznych prostrediach Linux.

Aby sme si to uľahčili, pripravíme si Docker obraz s aplikáciou aj všetkými závislosťami.

Docker obraz sa skladá z viacerých vrstiev. Na najnižšej úrovni sa nachádzajú súbory operačného systému a nad tým sú aplikácie. Nová vrstva vždy prekryje starú. Vrstvenie obrazov nám umožní ľahko modifikovať už existujúce obrazy bez toho aby sme museli robiť všetko nanovo.

Nový Docker obraz vytvoríme pomocou príkazov `docker`. Podľa inštrukcií v špeciálnom súbore `Dockerfile` zoberieme existujúci obraz, modifikujeme ho, zostavíme a uložíme v lokálnom registri.

## Dockerfile

Najprv sa presvedčte o tom, že máte dostupný stroj Docker Machine a zistite jeho IP adresu. Budete ju potrebovať pri testovaní aplikácie:

```
docker-machine ls
```

Výsledný obraz s aplikáciou je opísaný v súbore `Dockerfile`. Skladá sa zo sady inštrukcií pre zostavenie obrazu. Inštrukcie v `Dockerfile` nám umožňujú ľahko opakovať a modifikovať proces zostavenia aplikácie.

- [Dokumentácia inštrukcií v Dockerfile](https://docs.docker.com/engine/reference/builder/)
- [Odporúčania pri vytváraní Dockerfile](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)

Výhodnou je, že pri vytváraní nových obrazov môžme využiť už existujúce obrazy.
Obraz bude obsahovať operačný systém, potrebné knižnice a iné závislosti.
Nemusíme začať úplne od začiatku, ale využijeme 
[existujúci obraz s nainštalovaným interpreterom Python](https://hub.docker.com/_/python/).

Do `Dockerfile` zapíšeme tieto inštrukcie:

```Dockerfile
# Základný obraz z Docker Hub
# Fungujúca inštalácia Alpine Linux s nainštalovaným interpreterom Python
# Výhodou je malá veľkosť
FROM python:3.8-alpine

# Nastavenie pracovného adresára kontajnera
WORKDIR /app

# Inštalácia  závislostí aplikácie
RUN pip install flask

# Kopírovanie aplikácie súborov do obrazu
COPY ./app.py /app

# Nastavenie premennej prostredia
ENV FLASK_APP app.py

# Program na spustenie
ENTRYPOINT [ "flask" ]
# Argumenty 
CMD ["run", "--host", "0.0.0.0"]
```

Príkaz `ENTRYPOINT` je meno príkazu ktorý sa má vykonať. `CMD` je zoznam východiskových argumentov pre príkaz.


## Zostavenie obrazu

V aktuálnom adresári by sa mali nachádzať dva súbory:

- `app.py`
- `Dockerfile`

Keď máme hotové inštrukcie `Dockerfile`, pokúsme sa zostaviť obraz:

```
docker build -t flaskapp:latest .
```

Argument `-t` (tag) určuje meno obrazu v registri.  Časť pred dvojbodkou je názov obrazu. Časť za dvojbodkou je verzia obrazu.

Overme si, že nový obraz je v zozname lokálne dostupných obrazov:
```
docker images ls
```

## Spustenie vlastného kontajnera

Ak je obraz pripravený v zozname dostupných obrazov, môžeme vytvoriť nový kontajner:

```
docker run -it --rm flaskapp
```

Docker zoberie obraz a podľa inštrukcií v `ENTRYPOINT` a `CMD` spustí aplikáciu.

Podmienky spustenia (názov program, argumenty, premenné prostredia a iné) definované v obraze je možné meniť počas spustenia
`docker run ` zadaním ďalších argumentov.



```
                       ENV                       ENTRYPOINT     CMD
                        |                          |            |
                        v                          v            v
docker run -it --rm -e PREMENNA=ahoj --entrypoint echo flaskapp ahoj svet
```


Poznámka: 

v niektorých obrazoch je ako `ENTRYPOINT` uvedený takýto shell skript:

```
#!/bin/bash
set -e
# Ak je prvý argument meno aplikácie
if [ "$1" = 'postgres' ]; then
    # Urobím nejakú konfiguráciu
    exec gosu postgres "$@"
fi
# Inak vykonám argumenty ako shell príkaz
exec "$@"
```

V tom prípade pri spustení pomocou `docker run` nemusíme meniť parameter`--entrypoint`, lebo celý príkaz na spustenie sa načíta z argumentov `CMD`.

Viac o tom [aký je rozdiel](https://goinbigdata.com/docker-run-vs-cmd-vs-entrypoint/) medzi `CMD`, `ENTRYPOINT` a `RUN`.

## Konfigurácia aplikácie pomocou premenných prostredia

Upravte zdrojový text aplikácie tak, aby bral do úvahy Vami definovanú premennú prostredia.
Ak je definovaná premenná `MY_NAME`, tak aplikácia pekne pozdraví podľa nakonfigurovaného mena.
Inak pozdraví nášho kamaráta Ferka.

Zdrojový text aplikácie: `app.py`

```python
import os
from flask import Flask
from datetime import date

app = Flask(__name__)

@app.route("/")
def hello():
    name = "Ferko"
    if "MY_NAME" in os.environ:
        name = os.environ["MY_NAME"]
    return "<h1 style='color:blue'>Hello There {}!</h1>".format(name)

@app.route("/date")
def date():
    today = date.today()
    return "<p>{}</p>".format(today.strftime("%d.%m.%Y"))

if __name__ == "__main__":
    app.run()
```

Vytvorte nový obraz s vylepšenou aplikáciou.

Premennú prostredia je možné nastaviť tesne pred spustením kontajnera:


```
docker run -it --rm -e MY_NAME=Daniel  flaskapp
```

Beh aplikácie pripravenej v obraze je možné modifikovať aj argumentmi príkazového riadka.

Ak chceme získať pomoc v klasickom príkazovom riadku, napíšeme:

```
flask --help
```

V našom obraze to bude:

```
docker run -it --rm -e MY_NAME=Daniel  flaskapp --help
```

Argumenty na poslednom mieste nahradia argumenty zadané pomocou `CMD`.


Na to aby sme namiesto aplikácie `flask` spustili príkazový riadok, použite parameter `--entrypoint`, 
ktorým prekryjete inštrukcie v `Dockerfile`.

```
docker run -it --rm --entrypoint /bin/sh flaskapp
```

## Domáca úloha

Vymyslite aplikáciu ktorá bude obsahovať počítadlo prístupov.

Podarí sa Vám zistiť a zaznamenať aj typ prehliadača?


## Dodatočné informácie

- [Tutoriál Docker a Flask](https://www.digitalocean.com/community/tutorials/how-to-serve-flask-applications-with-gunicorn-and-nginx-on-ubuntu-18-04)
- [Iný tutoriál Docker a Flask](https://runnable.com/docker/python/dockerize-your-flask-application)



