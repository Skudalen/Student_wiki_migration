# Spustenie kotajnera

Naučíte sa:

- Čo je to obraz, čo je to kontajner a aký je medzi nimi rozdiel.
- Vyhľadanie obrazov na [Docker Hub](https://hub.docker.com/).
- Spustenie kontajnera pomocou `docker run`.

Zistíte, že s pomocou Docker je možné spúšťať rôzne druhy aplikácií bez toho aby sme ich museli zložito inštalovať.
Vedieť spúšťať Docker kontajnery sa Vám (okrem iného) zíde pri vypracovaní prvého zadania.

##  Začnite prácu

Spustte si príkazový riadok (napr. GIT bash)

Zistite v akom adresári sa nachádzate:

    pwd
    ls -l

Overte si, že máte prístupný klient systému Docker:

    docker

## Vyhľadajte obraz busybox

Verejný register aplikácií si môžte pozrieť cez web rozhranie [Docker Hub](https://hub.docker.com/).
Hotové obrazy si môžte vyhľadať aj cez príkazový riadok. 

Aký je [rozdiel](https://stackoverflow.com/questions/23735149/what-is-the-difference-between-a-docker-image-and-a-container)
medzi kontajnerom a obrazom?

V registri [Docker Hub](https://hub.docker.com/) sa nachádza veľa rôznych iných aplikácií - pozrite si [zoznam najpopulárnejších aplikácií](https://hub.docker.com/search?q=&type=image).

Busybox je sada základných príkazov systému Linux v jednom balení - príkazový riadok aj obľúbený textový editor v jednom.

Vyhľadajte obraz tohoto programu:

    docker search busybox

## Získajte obraz busybox

Na Vašom stroji sa nachádza lokálny register obrazov, ktoré sú k dispozícii. Lokálny register si pozriete príkazom:

    docker image ls

Ak sa v lokálnom registri požadovaný obraz nenachádza, získajte ho z centrálneho registra.

    docker pull busybox

Tým si aplikáciu "naninštalujete".

Pozor - inštalujte iba obrazy, ktorým dôverujete. Hoci sú procesy Docker
oddelené od zvyšku systému, predsa len nechcete spúšťať neoverený softvér.


## Spustte obraz

Ak je obraz aplikácie k dispozícii, okamžite sa spustí. Ak obraz nie je k dispozícii v lokálnom registri, systém sa pokúsi ho získať z centrálneho registra.

    docker run -it busybox

V prípade, že sa Vám zobrazí [chybové hlásenie](https://stackoverflow.com/questions/48623005/docker-error-the-input-device-is-not-a-tty-if-you-are-using-mintty-try-prefi):

    the input device is not a TTY.  
    If you are using mintty, try prefixing the command with 'winpty'

pred príkaz `docker` pridajte `winpty`.

    winpty docker run -it busybox

Ocitnete sa vo vnútri bežiaceho kontajnera. 

Trochu sa rozhliadnite dookola:

    ls / # Aké sú tu súbory
    pwd # V akom adresári sa nachádzam
    whoami # Ako sa volá moje prihlasovacie meno?

Vytvorte v kontajneri textový súbor a napíšte do neho nejakú správu:

    echo "Ahoj Svet" > sprava.txt # Zapíšeme správu
    ls -l # Overíme že súbor existuje
    cat ./sprava.txt # Overíme si obsah súboru

Bežiaci kontajner opustíte tak, že skončíte práve bežiaci proces (`bash`):

    exit

alebo `CTRL+C`.

Pozrite si zoznam všetkých kontajnerov:

    docker container ls -a

Prepínač `-a` spôsobuje výpis všetkých kontajnerov, aj tých skončených.

Skúste znovu spustiť taký istý kontajner a overte si, či sa tam súbor nachádza:

    docker run -it busybox
    cat ./sprava.txt
    ls -l

Opustte bežiaci kontajner (`CTRL+D`) a zase si pozrite zoznam kontajnerov:

    docker container ls -a

Čo ste zistili? 

- Po každom spustení zostal záznam v databáze kontajnerov.
- Každý spustený kontajner má svoj identifikačný reťazec.
- Z jedného obrazu je možné spustiť viacero kontajnerov.

Ak si zistíme identifikačný reťazec kontajnera, môžme si pozrieť chybové hlásenia v čase keď kontajner skončil:

    docker logs <ID>

Môžme si dokonca skopírovať súbor, ktorý sme vytvorili:

    docker cp <ID>:sprava.txt ./

Ak nás stav kontajnera po skončení nezaujíma, pri spustení zadáme prepínač `--rm`.

    docker run --rm -it busybox

Čo sa stane ak vynecháme prepínač `-it` ?

## Spustenie na pozadí

Ako sa vrátime k už spustenému kontajneru?

Spustte si na pozadí nový kontajner a pozrite si zoznam všetkých aktívnych  kontajnerov:

<!-- Poznámka -d má iné správanie na Docker for Windows.. (kontajner hneď skončí). Asi to súvisí so čtandardným vstupom -->

    docker run -d busybox
    docker container ls

Môžte si zobraziť aj zoznam všetkých Docker procesov:

    docker ps

Zistite identifikačné meno bežiaceho kontajnera a pripojte sa naňho:

    docker exec -it <ID Kontajnera>

Automatický reštart kontajnera zabezpečíte prepínačom `--run-unless-stopped`. Ak Vaša Docker aplikácia havaruje, systém ju automaticky reštartuje:

    docker run -d busybox --run-unlesss-stoppped

Kontajner bežiaci na pozadí zastavíte príkazom, argument je číslo bežiaceho kontajnera.

    docker stop <ID Kontajnera>

## Čistenie vyrovnávacej pamäte

Získanie obrazu alebo spustenie kontajnera si vyžaduje miesto na pevnom disku. 
Každý získaný obraz alebo spustený kontajner zaberie nejaké miesto.

    docker image ls
    docker ps -a --size

Po čase sa môže stať, že sa miesto na disku vyčerpá.
Záznamy o ukončených kontajneroch sa dajú vymazať pomocou príkazu:

    docker container rm <ID kontajnera>

Nepoužívaný obraz odstránime pomocou:

    docker image rm <názov obrazu>

Docker obsahuje aj "inteligentné čistenie" vyrovnávacej pamäte:

    docker system prune

Pozor, pri čistení si môžme odstrániť aj užitočné informácie.


## Domáca úloha

- Vyhľadajte a spustte obraz "python".
- Zistite, aké ďalšie operácie sa dajú vykonávať pomocou príkazu `docker`.

## Ďalšie materiály

- Ivan Bernát: [Docker a jeho použitie pri kontajnerizácii](https://magazin.kpi.fei.tuke.sk/2019/02/docker-a-jeho-pouzitie-pri-kontajnerizacii/)
- Interaktívny tutoriál [Deploy first Container](https://www.katacoda.com/courses/docker/deploying-first-container) na systéme [Katacoda](https://www.katacoda.com)

