# 1. Štruktúrované údajové typy
:icons: font
:source-highlighter: highlightjs
Daniel Hládek

Programovanie v Jazyku C

## Programovanie

Ing. Daniel Hládek PhD.

daniel.hladek@tuke.sk

BN32 L610


## Cieľ predmetu

Aby ste sa *sami* naučili programovať v jazyku C.

[NOTE.speaker]
====
Koniec testom v Moodli
====

## Hodnotenie

* 20 bodov zápočet
* 80 bodov skúška
* Z každého zadania alebo zápočtovky min polovicu bodov. (s možnosťou dodatočnej opravy)
* Aktívna účasť na cvičeniach (povinnosť vypracovať všetky úlohy na cvičeniach)

## Organizačné pokyny

- Zápočtovka z "Programátorského minima" v 3 týždni.
- Zaobstarajte si "Arduino Sadu" včas (z Číny).

## Ćo je programovanie

- algoritmizácia problému
- znalosť syntaxe programovacieho jazyka
- znalosť prostriedkov, ktoré máme k dispozícii

## Ja nemusím byť programátor ???

- Väčšina najlepších voľných miest je na pozícii programátor
- Aj systémový administrátor musí vedieť programovať (aspoň trochu)
- Kladenie kabeláže je dôležité, ale môžu to robiť Vaši kolegovia z odbornej školy.

## Ako súvisí programovanie a počítačové siete?

Ako fungujú prvky v sieťovej infraštruktúre?

- sú programovateľné

Ako vyzerá správa servrov?

- Programujem skripty pre správu

## Ako súvisí programovanie a počítačové siete?

Pri návrhu a správe siete je potrebné:

- algoritmické myslenie
- znalosť prostriedkov, ktoré máme k dispozícii
- znalosť zápisu konfiguračných súborov

## Programovanie je modelovanie reálneho sveta

- Porozumieť problému znamená byť schopný to vysvetliť aj mojej babke
- Porozumieť problému znamená byť schopný ho naprogramovať

## Príklad: Vlastnosti auta

[.stretch]
image::oldbeetle.jpg[old beetle]

## Ako naprogramujeme pojem auto?

Auto si môžeme  vyjadriť pomocou jeho atribútov. Každý atribút má svoj typ.


- počet kolies
- objem motora
- špz
- dátum platnosti stk
- meno majiteľa


## Ako by vyzeralo auto v jazyku C 

- podľa toho čo vieme doteraz

```c
int pocet_kolies=4;
int objem_motora=1000;
char spz[8]="BA123AB";
```

Dátum platnosti stk? Challenge@Home

## Funkcia na spracovanie auta

[.stretch]
```c
void predaj_auto(
    int pocet_kolies,
    int objem_motora,
    char spz[8])
{
     printf("Skvele auto %s 
      ktore ma %d kolies a %d cm3 motor\n",
      spz,pocet_kolies,objem_motora);
}
```

## Ako by sme reprezentovali viac áut v jazyku C

Poznáme polia!

```c
int pocet_kolies[2] = {4,12};
int objem_motora[2] = {1000,8000};
char spz[8][2] = {"BA123BA","KE456EK"};
```

Vyzerá to ale skôr ako šrotovisko - kolesá sú blízko seba, motory sú blízko seba na jednej kope,
na ďalšej kope sú ešpézetky.

## Ako by sme odovzdali viac áut ako argument funkcie?

```c
void predaj_auta(int pocet_aut,
    int* pocet_kolies,
    int* objemy_motorov,
    char* spz[8])
{
    for (int i = 0; i < pocet_aut; i++){
    	printf("Skvele auto %s ktore ma %d kolies 
          a %d cm3 motor\n",
          spz[i],pocet_kolies[i],
          objem_motora[i]);
    }
}
```
### Challenge@home

Ako by sme zotriedili skupinu áut podľa objemu motora? 


## Naprogramujme auto - Vytvorenie štruktúry

```c
struct auto {
    int pocet_kolies;
    int objem_motora;
    char spz[8];
}
```

Veď píšeme viac! Čo je výhoda?

### Zápis bez štruktúry

```c
int pocet_kolies;
int objem_motora;
char spz[8];
```

## Statická inicializácia štruktúry

Celú štruktúru inicializujeme naraz.

```c
struct auto favorit = {
    .pocet_kolies = 4,
    .objem_motora = 1289,
    .spz = "KE123GO"
};
```

## Inicializácia štruktúry po častiach

```c
// Vyhradenie pamäte
struct auto favorit;
// Priradenie počiatočnej hodnoty každému členu

favorit.pocet_kolies = 4;
favorit.objem_motora = 1289;
favorit.spz = "KE123GO";
```

## Ako odovzdáme štruktúru auto ako argument funkcie?

```c
void predaj_auto(struct auto dakeauto){
  printf("Skvele auto %s ktore 
    ma %d kolies a %d cm3 motor\n",
    dakeauto.spz,
    dakeauto.pocet_kolies,
    dakeauto.objem_motora[i]);
}
```
Operátor `.` slúži na prístup k členu štruktúry.

Dochádza ku kopírovaniu.

## Ako odovzdáme štruktúru auto ako argument funkcie?

Odovzdávame hodnotou *adresy*.

```c
void predaj_auto2(struct auto* dakeauto){
  printf("Skvele auto %s ktore ma %d kolies 
  	a %d cm3 motor\n",
  	*(dakeauto).spz,
  	*(dakeauto).pocet_kolies,
  	*(dakeauto).objem_motora[i]);
}
```
Operátor '*' slúži na získanie hodnoty z adresy

WARNING: Toto nebude fungovať

## Operátor ->

Skrátený zapis použitia operátorov `*` a `.` je operátor `->`

```c
void predaj_auto3(struct auto* dakeauto){
  printf("Skvele auto %s ktore ma %d kolies 
  	a %d cm3 motor\n",
    dakeauto->spz,
    dakeauto->pocet_kolies,
    dakeauto->objem_motora);
}
```

## Pole štruktúr

Ako si reprezentujeme viac áut?

```c
struct auto viacaut[2];
```
## Inicializácia poľa štruktúr


```c
viacaut = { {
	.pocet_kolies = 4,
    .objem_motora = 1289,
    .spz = "KE123GO"
    },
    {
	.pocet_kolies = 8,
    .objem_motora = 2048,
    .spz = "BA456AG"
	}
};
```

## Inicializácia poľa štruktúr po častiach

1. Vyhradíme si pamäť
1. Každú bunku poľa prechádzame v cykle
1. Inicializujeme každý člen

## Ako odovzdáme viac štruktúr auto ako argument funkcie?

```c
void predaj_auta(int pocet_aut,struct auto* prve_auto){
	for (int i = 0; i < pocet_aut; i++){
      printf("Skvele auto %s 
      	ktore ma %d kolies a %d cm3 motor\n",
        dakeauto[i].spz,
        dakeauto[i].pocet_kolies,
        dakeauto[i].objem_motora[i]);
    }
    return -1;
}
```
Kopíruje sa iba adresa prvého auta, nie celé pole.


## Typedef

https://www.kernel.org/doc/html/latest/process/coding-style.html#typedefs

https://stackoverflow.com/questions/612328/difference-between-struct-and-typedef-struct-in-c


## Algoritmus Lineárneho vyhľadávania v poli štruktúr

```c
int hladaj_stvorkolku(int pocet_aut,struct auto* auta){
    for (int i = 0; i < pocet_aut; i++){
    	if (auta[i].pocet_kolies == 4)
        	return i;
    }
    return -1;
}
```

## Koniec


