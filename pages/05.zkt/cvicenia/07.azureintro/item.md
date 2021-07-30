---
title: Azure Intro
published: true
---

! Naučíte sa:
!
! - Prihlásenie sa
! - Práca s Azure Portal
! - Práca s Azure CLI
! - Nasadenie Python Flask aplikácie bez kontajnera

## Vytvorte si prístup k "Azure Dev Tools for Teaching"

Pre vytvorenie účtu musíte použiť [školskú stránku](https://uvt.tuke.sk/wps/portal/uv/software/microsoft-softver-msdn) pre program [MDSN pre školy](https://azureforeducation.microsoft.com/devtools).

Ťuknite na "Prístup k softvéru".

Potom na "Sign In"

!! Ak nepoužijete školskú stánku na prihlásenie tak nezískate prístup k niektorým službám

Po výzve Sign In - prihlásite sa podobne ako do MAISU, pred Váš login uveďte 
`ad.tuke.sk`:

    ad.tuke.sk\ab123cd
    HESLO

Systém od Vás bude vyžadovať zadanie telefónneho čísla pre poslanie overovacej SMS.

Po čase sa a overení Vášho telefónneho čísla sa prihlásite na "Azure Education Hub". Z Azure Education Hub viete získať viacero plných softvérov od Microsoftu pre účely výuky. V časti "Learning" sa nachádza viacero tutoriálov.

Ak ťuknete na "Home", zobrazí sa Vám Azure portál - východiskové miesto pre správu a využívanie služieb verejného klaudu Azure. 


## Pripravte si súbory

Vytvorte si adresár s webovou aplikáciou a umiestnite tam súbor `app.py` z [cvičenia č. 4](/zk4/cvicenia/build):

    mkdir cv7
    cp cv4/app.py ./cv7
    echo Flask > requirements.txt

Súbor `requirements.txt` obsahuje zoznam Python balíčkov ktoré si aplikácia vyžaduje. Podľa toho sa nainštaluje všetko potrebné.

## Vytvorenie spojenia s klaudom

Spustite si príkazový riadok WSL2 Ubuntu. Nainštalujte si najnovšiu verziu  [Azure CLI](https://docs.microsoft.com/en-us/cli/azure/install-azure-cli-linux) (závislosť na Python 3).


Vytvorte spojenie s Vašim účom na Azure klaude. Prihlásenie a autentifikácia prebehne pomocou Web prehliadača:

    az login

Spojíte az s Azure klaudom.


## Vytvorenie App Service webapp

    az webapp up --sku B1 --name cv6webapp --location westeurope

Nasadenie aplikácie bude chvíľu trvať.

## Pozrite si aplikáciu

Otvorte prehliadač a zistite či funguje

## Pozrite si aplikáciu na Azure Klaude

Pozrite si Azure Portal a nájdite Vašu aplikáciu

## Zrušte aplikáciu

Aby nemíňala kredit.

    az group delete --no-wait

## Materiály

[Základy práce s Azure CLI](https://docs.microsoft.com/en-us/cli/azure/)

[Pôvodný App Service Python tutoriál](https://docs.microsoft.com/en-us/azure/app-service/quickstart-python)

