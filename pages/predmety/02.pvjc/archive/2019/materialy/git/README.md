# Práca s GITom

Prihláste sa na [KEMT Git](https://git.kemt.fei.tuke.sk/). Použite svoj
študentský login a heslo (ktorým sa prihlasujete do MAISu).

Vyberte vhodné meno projektu podľa inštrukcií k zadaniu, napr.
'pvjc19cv1'. Vytvorte prázdny repozitár (+ New Repository) a jeho
viditeľnosť nastavte na "Private", aby ste zabránili neželanej zhode s
iným zadaním. Zaškrtnite políčko 'Visibility' (Make repository private).

Na to aby ste mohli posielať podania z lokálneho stroja, musíte odoslať
Váš verejný SSH kľúč. Kľúč nájdete v súbore `~/.ssh/id_rsa.pub` a
zobrazíte ho príkazom `cat`.

    cat ~/.ssh/id_rsa.pub

Ak sa tam taký súbor nenachádza, vytvorte ho príkazom:

    ssh-keygen

Nastavené cesty súborov neprepisujte\!

Obsah súboru \~/.ssh/id\_rsa.pub vložíme do Gitu:

Menu vpravo hore = / Profile Settings / Settings / SSH ang GPG Keys /
Add Key

Ak ste vložili SSH kľúč, môžte vytvoriť lokálny repozitár, ktorý bude
spojený so vzdialeným repozitárom. Lokálnu kópiu vzdialeného repozitára
vytvoríme príkazom `git clone`, kde ako argument pridáte URL vzdialeného
repozitára, napr.:

    git clone git@git.kemt.fei.tuke.sk:ab123cd/pvjc19cv1.git

Vytvorí sa priečinok ktorý sa volá rovnako ako vzdialený repozitár.
Dajte do neho súbory, ktoré sú súčasťou zadania:

    cd pvjc19cv1
    vim program.c

Vypracované zadanie odovzdáte tak, že ho odošlete na vzdialený repozitár
a požiadate o automatické hodnotenie.

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

argumenty origin a remote už neskôr nie je potrebné zadávať, takže pre
odoslanie stačí:

    git push

# Niektoré užitočné príkazy Git

Získanie zmien zo vzdialeného repozitára

    git pull

Zistenie stavu zmien

    git status

Vrátenie sa k predošlým zmenám

    git checkout

Zobrazenie histórie potvrdených zmien

    git log

Zobrazenie manuálovej stránky

    git help

Pridanie nových zmien ktoré odstraňujú už potvrdené zmeny

    git revert

Vymazanie z histórie potvrdených zmien alebo zrušenie oblasti zmien

    git reset
