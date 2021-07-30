# 11. Paralelizmus v Jave

---
(I/O)

Regulárne výrazy

Perzistencia objektov - serializácia
- Súbory
- Reťazce
- Network

JDBC

kľúčové slovíčko transient


Paralelné návrhové vzory

# =Udov do paralelen0ho prgramovania v Jave

Viete sa venovať viacerým úlohám naraz?
- niekto viac a niekto menej.

# čo znamená parapelné programovanie:

vykonávanie viac úloh naraz

zdieľanie jedného prostriedku viacerými úlohami
- disk
- sieťová karta
- pamäť
- grafická karta

(vlastne všetky komponenty okrem disketovej alebo páskovej mechaniky )


Využívanie prostriedky, ktorý už používa niekto iný

# Prečo je dôležité paralelné programovanie


lepšie využitie existujpcich prostriedkov
- už na mobile často máte aj osem jadier
riešenie úloh, ktoré trvajú príliš dlho
- mám k dispozícii viacero výpočtových servrov alebo cloud, ako ich využijem
riešenie úloh, ktoré je možné riešiť iba paralelene (big data)
- potrebujem spracovať enormné mnoťstvo dát a neviem ako
práca s grafikým používateľským rozhraním:
- robím na nejakej úlohe a popri tom je potrebné riešiť zobrazovanie ovládacích prvkov
- naraz využívam myš aj klávesnicu aj grafickú kartu
- popri vykonávaní úlohy viem nariadiť jej prerušenie alebo zmenu

# Pre4čo je paralelné programovanie ťažké

- Momentálne je hardware viac paralalný ako software
- Software často nevie využívať možnosti hardware

- Paralelné programovanie je ťažšie na abstrakciu
- menej sa učí na školách
- Programátorov schopných pracovať s paralelným kódom je málo.

- Vývoj je veľmi rýchly
- Existuje veľký tlak na paralelné riešenie úloh
    - cloud
    - big data
    - internet of things
    - data mining

Pozor - nesprávne zdieľanie pamäte spôsobuje nepredvídané stavy.
Je 

# Vlákna a procesy

Vlákno  je iba jeden z možných spôsobov paralelného programovania! 
Nie vždy je vhodné používať vlákna a zámky. (Väčšonou to nie je vhodné)

Kedy je vhodné používať vlákna:
- Programovanie na nižšeu úrovni
- Programovanie databázových systémov
- Aplikácie komunikuúce cez sieť
- GUI
- keď je potrebné zdieľať veľa pamäti na zápis.

Kedy nie je vhodné používať vlákna:

- Keď sa to dá urobiť inak, napr. pomocou procesuov

Operácie:

- blokujpce
    - usiluje sa sprlniť príkaz aj za cenu nekonečného čakanie
    - čaká, kým sa operácia nedá splniť
- neblokujúce
    - ak sa operácia nedá splniť pokračuje aj bez toho


Vlákno je proces v procese
Vlákno je spôsob ako vykonávať operácie paralelne, aj keď je k dispozícii iba jedno výpočtové jadro.
Vlákna vedia medzi sebou zdieľať pamäť

Vlákna medzi sebou vedia komunikovať pomocu zdieľanej pamäte.


Vlákno predstavuje jedu úlohu


Rozhranie Runnable


kľúčové slovo synchronized
kľúčové slovo volatile


# Zámky

Race condition:

Keď v strede vykonávania úlohy sú podmeinky zmenené íným vláknom alebo procesom.

Čítanie a zápis do pamňte by malo byť atomické

Pri parlelnom zápise a čítaní je možné, že prečítame iba časť hodnoty, druhú časť zmení iný proces.
tým nastane neočakávaný stav (prečítanie neexistujpcej hodnoty)

Zánky majú za úlohu zabezpečiť kompaktnosť pamäťového miesta.

Treba byť pozorní pri návrhu zámkov

Zánkom sa treba vyhnúť ak sa to dá:
- Na dáta používať databázu
- Používať asynchrónne programovanie
- Používať systém správ medzi procesmi
- Minimalizovať počet zdieľaných miest


# Asynchrónne programovanie
 