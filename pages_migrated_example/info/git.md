# Práca s GITom

Všetky domáce úlohy budete odovzdávať na automatické hodnotenie pomocou [systému na správu verzií GIT](https://git.kemt.fei.tuke.sk).

Tento systém môžte využiť aj na synchronizáciu práce na cvičení a doma. Nestane sa Vám, že na cvičení budete sedieť zbytočne, lebo domácu úlohu máte rozpracovanú na inom počítači. Pomocou príkazu `git pull` si natiahnete zmeny zo vzdialeného repozitára. 

## Prihlásenie sa na pracovný server

Prihláste sa na stroj na ktorom budete pracovať. Máte aktivovaný prístup na školský server `omega.tuke.sk`.
Na pripojenie sa zo stroja s OS Windows použite klienta [PUTTY](https://www.putty.org/). Prihlasovacie meno a heslo 
je rovnaké ako do IS MAIS.

Po prihlásení si overte aké súbory máte k dispozícii:

    ls

Na to aby ste mohli posielať podania z lokálneho stroja, musíte odoslať
Váš verejný SSH kľúč. Kľúč nájdete v súbore `~/.ssh/id_rsa.pub` a
zobrazíte ho príkazom `cat`.

    cat ~/.ssh/id_rsa.pub

Ak sa tam taký súbor nenachádza, vytvorte ho príkazom:

    ssh-keygen

Po zadaní príkazu iba stláčajte ENTER. Nastavené cesty súborov neprepisujte\!

## Aktivácia vzdialeného repozitára

Prihláste sa na [KEMT Git](https://git.kemt.fei.tuke.sk/). Použite svoj
študentský login a heslo (ktorým sa prihlasujete do MAISu).

Vytvorte repozitár do ktorého budete posielať Vaše zadania (+ New Repository) a jeho
viditeľnosť nastavte na "Private", aby ste zabránili neželanej zhode s
iným zadaním. Zaškrtnite políčko 'Visibility' (Make repository private).

V menu vpravo hore (=) vyhľadajte položku  "/Profile Settings/Settings/SSH ang GPG Keys/Add Key".

Do okienka pomocou schránky vložíte obsah súboru \`~/.ssh/id\_rsa.pub`.

Prihláste sa na pracovný server `omega.tuke.sk`.

Metóda kopírovania textu pomocou schránky sa líši od použitého SSH klienta. V prípade PUTTY zobrazíte súbor, označíte obsah
a skopírujte ho do schránky pomocou stlačenia ľavého a pravého tlačítka myši naraz.

    cat ~/.ssh/id_rsa.pub

## Vytvorenie lokálneho repozitára

Ak ste vložili SSH kľúč, môžte vytvoriť lokálny repozitár, ktorý bude
spojený so vzdialeným repozitárom. Lokálnu kópiu vzdialeného repozitára
vytvoríme príkazom `git clone`, kde ako argument pridáte URL vzdialeného
repozitára, napr.:

    git clone git@git.kemt.fei.tuke.sk:ab123cd/KODPREDMETU.git

Vytvorí sa priečinok ktorý sa volá rovnako ako vzdialený repozitár.

Všetky zadania budete odovzdávať pomocou tohto repozitára. 
Pre každé zadanie si vytvoríte nový adresár a dáte do neho súbory, ktoré sú súčasťou zadania:

    cd pvjc20
    mkdir du1
    vim program.c

Vypracované zadanie odovzdáte tak, že ho odošlete na vzdialený repozitár
a požiadate o automatické hodnotenie.

## Odoslanie súborov

Zmeny je najprv potrebné potvrdiť. Pre potvrdenie musíme súbor najprv
pridať:

    git add program.c

a až potom vykonať potvrdenie, ktoré sa uloží do lokálneho repozitára.
Súčasťou potvrdenie je správa, ktorá opisuje zmenu:

    git commit -m "funguje"

Pokiaľ je zmena jednoduchá a týka sa súborov, ktoré už boli v minulosti
potvrdené, vieme si `git commit` a `git add` spojiť do jedného príkazu:

    git commit -am "funguje"

Potvrdené zmeny odošlete pomocou príkazu:

    git push origin master

argumenty `origin` a `remote` už neskôr nie je potrebné zadávať, takže pre
odoslanie stačí:

    git push

## Niektoré užitočné príkazy Git

Získanie zmien zo vzdialeného repozitára:

    git pull

Zistenie stavu zmien:

    git status

Vrátenie sa k predošlým zmenám:

    git checkout

Zobrazenie histórie potvrdených zmien:

    git log

Zobrazenie manuálovej stránky:

    git help

Pridanie nových zmien ktoré odstraňujú už potvrdené zmeny:

    git revert

Vymazanie z histórie potvrdených zmien alebo zrušenie oblasti zmien:

    git reset

## Ďalšie informácie

- [Kniha GIT](https://git-scm.com/book/cs/v2) po česky

