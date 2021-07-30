# Slovár slovenský

Naučíte sa:

  - Identifikovať a využiť časti reťazca;

  - Naprogramovať počítadlo slov.

V rámci prestížnej celovýchodoslovenskej vedeckej grantovej schémy "H2o"
naša katedra získala dotáciu na výskum v oblasti spracovania
prirodzeného jazyka. Cieľom je sledovať pravdepodobnosti výskytu slov v
existujúcich bakalárskych a diplomových prácach a na ich základe
vytvoriť ultimátny generátor nových vedeckých prác.

Ak uspejeme tak už nikdy nebude potrebné ručne písať žiadny text, lebo
automat vygeneruje ľubovoľné množstvo textu na ľubovoľnú tému. Všetci
zamestnanci katedry sú ale zavalení výukou a tak úloha ako vždy pristála
na našom stole.

Výsledkom bude "Ultimátna záverečná práca", ktorá raz a navždy vyrieši
problém nezmyselného písania a kopírovania.

Základom všetkých metód pre automatické generovanie textu je odhad
pravdepodobnosti výskytu slova v trénovacom texte. Pravdepodobnosť
výskytu slova je priamo úmerná jeho početnosti.

V úlohe si vytvoríme "Slovár slovenský", čo je slovník slov zotriedený
podľa abecedy. Ku každému slovu je priradená jeho početnosť. Keď budete
vedieť početnosť každého slova bude jednoduché vyberať slová tak, aby
tie početnejšie mali väčšiu pravdepodobnosť výberu.

# Analýza úlohy

Najprv je potrebné po riadkoch načítavať text zo štandardného vstupu.

<div class="warning">

Vždy si overte výsledok načítania. Ak si výsledok načítania neoveríte,
budete pracovať s neplatnými hodnotami a program sa bude správať
nepredvídateľne.

</div>

Z riadku identifikujte slová. Slová postupne vkladajte do databázy, ale
tak aby ste zabránili ich viacnásobnému výskytu. Ak slovo v databáze
nájdete, zvýšte jeho početnosť o jedna. Inak ho pridajte do databázy s
početnosťou jedna. Na konci zotrieďte databázu lexikograficky (abecedne)
podľa slova a zobrazte slová aj s početnosťami.

## Tokenizácia

Jeden riadok sa skladá z viacerých slov oddelených bielym znakom. V
riadku je potrebné identifikovať slová a postupne ich vkladať do
osobitného reťazca.

<div class="note">

reťazec v jazyku C vždy musí byť ukončený nulou.

</div>

Na tokenizáciu je najjednoduchšie použiť funkciu
[strtok()](http://www.cplusplus.com/reference/cstring/strtok/) zo
štandardnej knižnice.

<div class="warning">

Funkcia `strtok` zmení pôvodný reťazec. Funkcia strtok má skrytý
vnútorný stav.

</div>

Pri prvom volaní zavoláte funkciu `strtok`, prvý argument je reťazec čo
sa má tokenizovať, druhý argument je reťazec znakov ktoré oddeľujú
slová. Funkcia si "zapamätá" reťazec, ktorý rozdeľujeme (adresu si
uloží do globálnej premennej). Pri ďalšom volaní dáme ako prvý
argument `NULL`.

Návratová hodnota je nulová ak nie sú žiadne ďalšie slová alebo adresa
reťazca s ďalším slovom.

Jednoduchý program na výpis všetkých slov zo štandardného vstupu môže
vyzerať napríklad takto:

``` c
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1000

int main(){
    // Buffer na načítanie
    char line[BUFSIZE];
    while(1){
        // Načítanie riadka zo štandardného vstupu, max. 999 znakov vrátane konca riadka.
        char* r = fgets(line,BUFSIZE,stdin);
        // Ak je r NULL, načítanie končí.
        if (r == NULL){
            break;
        }
        char separators[] = "\n\t ";
        // Identifikujem prvé slovo.
        char* word = strtok(line,separators);
        // Ak je slovo NULL, končím spracovnaie riadka
        while (word != NULL){
            // Máme slovo ako samostatný reťazec
            printf("--%s--\n",word);
            // Identifikujem ďalšie slovo
            word = strtok(NULL,separators);
        }
    }
    return 0;
}
```

V premennej `word` sa postupne objavujú slová z riadka ako samostatné
reťazce. Funkcia `strtok` vkladá namiesto oddeľovačov (`separators`) do
pôvodného reťazca (v poli `line`) nuly a podľa potreby posúva smerník
`word` tak aby postupne ukazoval na začiatok každého slova.

# Počítadlo

Aby ste vytvoril počítadlo budete musieť evidovať hodnotu (slovo) a jeho
početnosť. Na to je dobré použiť štruktúru:

    struct item {
      char word[20];
      int count;
    };

Položky slovníka môžte uložiť viacerými spôsobmi, vyberte si tú ktorú si
chcete precvičiť najviac.

  - pole štruktúr alebo pole smerníkov na štruktúry.

  - binárny strom.

Každý spôsob má svoje výhody aj nevýhody. Pri binárnom strome nemusíte
položky triediť, sú zotriedené stále. Pole štruktúr je jednoduché, ale
najmenej efektívne na procesor aj pamäť.

Algoritmus počítadla môže vyzerať takto:

1.  Zober slovo a vyhľadaj ho v databáze.

2.  Ak nenájdeš také slovo, vytvor novú položku s daným slovom a nastav
    početnosť na jednotku.

3.  Ak nájdeš položku s daným slovom, zvýš početnosť o jedna.

Ak je to potrebné, pre lexikografické triedenie využite funkciu
[strcmp()](http://www.cplusplus.com/reference/cstring/strcmp/), ktorá
porovnáva dva reťazce a funkciu
[qsort()](http://www.cplusplus.com/reference/cstdlib/qsort/).

# Odovzdanie

Úlohu odovzdajte do repozitára s názvom `pvjc19cv10`, súbor `program.c`.
Bude hodnotená automaticky ako zadanie (10 bodov). Heslo na odovzdanie
je `slovar`.

Vytvorenie kompletného automatického generátora vedeckých prác na
základe slovníka početností vypočítaného zo vstupného textu bude
ohodnotené ako aktivita (5b).
