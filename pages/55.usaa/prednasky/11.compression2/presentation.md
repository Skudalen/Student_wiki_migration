---
title: Kompresia Lempel Ziv
---
# Kompresia Lempel Ziv 77 a 78

---
## Kompresia

Vstup:: Sekvencia symbolov
Výstup:: Kratšia sekvencia symbolov, ktorá vyjadruje pôvodnú sekvenciu

---
## Kompresia ASCII Art

- Obsahuje veľa medzier za sebou

---
## Aardvark

[https://www.asciiart.eu/animals/aardvarks](Art by Horroroso)

                        _,,......_
                     ,-'          `'--.
                  ,-'  _              '-.
         (`.    ,'   ,  `-.              `.
          \ \  -    / )    \               \
           `\`-^^^, )/      |     /         :
             )^ ^ ^V/            /          '.
             |      )            |           `.
             9   9 /,--,\    |._:`         .._`.
             |    /   /  `.  \    `.      (   `.`.
             |   / \  \    \  \     `--\   )    `.`.___
    -hrr-   .;;./  '   )   '   )       ///'       `-"'
            `--'   7//\    ///\


---
## Run Length Encoding

- kompresia ikon a jednoduchých bitmapovýćh obrázkov.
- kompresia ASCII artu :-)

---
## Run Length Encoding

- Reťazec kóduje ako počet opakovaní symbolu v minulosti.
- Kódové slovo je dvojica: symbol, počet opakovaní

---
## Run Length Encoding

- Zober symbol
- Spočítaj počet jeho výskytov za sebou
- Zapíš počet výskytov
- Zapíš symbol

---
## Run Length Encoding Príklad

    WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW


    12W1B12W3B24W1B14W

---
## Kompresia pomocou slovníka

- V dátach identifikujeme často opakujúce sa časti
- Zakódujeme ich a zostavíme slovník
- Slovník sa vytvára počas behu algoritmu, nie je známy dopredu.


---
## Lempel Ziv 77

Podľa [wiki](https://en.wikipedia.org/wiki/LZ77_and_LZ78):

- Kódové slovo je trojica: posunutie, dĺžka, ďalší znak.
- Kóduje sa výskyt reťazca v minulosti.

---
## Lempel Ziv 77

Prebieha v plávajúcom okne, ktoré je rozdelené na minulosť a budúcnosť.

- Hľadaj v budúcnosti čo najdlhší reťazec čo sa nachádza v minulosti
- Nahraď ho trojicou: dĺžka, posunutie, ďalší znak.

---
## Dekódovanie Lempel Ziv 77

Prebieha v plávajúcom okne.

- Zober kódové slovo.
- Nahraď ho za reťazec podľa minulosti.

---
## Deflate

Kombinácia LZ 77 a Huffman Encoding.

- GIF
- pkzip
- gzip
- zip

---
## Lempel-Ziv-78

Jeho upravená verzia sa nazýva [Lempel-Ziv-Welch](https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch)

[quote,Wikipedia]
> At each stage in compression, input bytes are gathered into a sequence until the next
> character would make a sequence for which there is no code yet in the dictionary.
> The code for the sequence (without that character) is added to the output,
> and a new code (for the sequence with that character) is added to the dictionary.

---
## Kódové slovo LZ78

číslo záznamu v slovníku + symbol

---
## Slovník Lempel-Ziv-Welch

- Asociatívne pole:
	- reťazec -> kód
- Na začiatku je určený počiatočný slovník, ktorý obsahuje napr. všetky reťazce dĺžky jedna.
- Slovník nie je potrebné zapisovať, vytvára sa za behu kódovania aj dekódovania.

---
## Kódovanie Lempel-Ziv-78

1. Inicializuj slovník
1. Zober znak
1. Ak sa buffer a znak nenachádza v slovníku, zapíš kód buffra. Pridaj buffer a znak do slovníka.
1. Inak pridaj znak do buffra a pokračuj ďalším znakom.

---
## Dekódovanie Lempel-Ziv-Welch

Podľa [blogu](http://www.stringology.org/DataCompression/lz78/index_en.html):

1. Inicializuj slovník.
1. Načítaj kódové slovo.
1. Pridaj reaťazec a znak do slovníka.
1. vypíš reťazec a znak


---
## Príklad LZW

- [Na Wiki](https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch)
- [Na geeksforgeeks](https://www.geeksforgeeks.org/lzw-lempel-ziv-welch-compression-technique/)

---
## Aplikácia LZW

- Compress
- GIF
- TIFF
- PDF

---
## Zhrnutie

- Algoritmy LZ sú široko používané.
- Pracujú na princípe identifikácie opakujúcich sa častí.

