---
title: Robot Karel
published: true
---

# Manuály

- [Programátorská príručka](https://kurzy.kpi.fei.tuke.sk/zap/tutorials/karel-api.html)
- [Zdrojové kódy](https://git.kpi.fei.tuke.sk/kpi/karel-the-robot) 
- [Programátorská príručka](https://kurzy.kpi.fei.tuke.sk/zap/tutorials/karel-api.html)
- [Podrobný opis formátu Karlovho sveta](https://kurzy.kpi.fei.tuke.sk/zap/tutorials/karel-api.html)
- [Program na generovanie Karlovho sveta](createworld.c). 
- Pôvodné stránky robota [Karel](https://www.cs.mtsu.edu/~untch/karel/)

# Formát Karlovho sveta



Súbor sveta potom upravíte pomocou textového editora.

Každý riadok opisuje jeden objekt. Položky na riadku sú oddelené medzerami.

Počiatočný smer Karla alebo smer prekážky sa udáva v svetových stranách:

- N (hore) 
- S (dole) 
- W (na ľavo) 
- E (na pravo).


##  Prvý riadok 
obsahuje rozmer sveta, počiatočnú Karlovu pozíciu, Karlov smer a počet značiek v batohu vo formáte:

```
	rozmer_x rozmer_y karol_x karol_y karol_smer počet_žetónov_v_batohu
```

## Riadky začínajúce sa W 
opisujú pozíciu prekážky vo formáte:

```
	W pozícia_x pozícia_y smer_prekážky
```

## Riadky začínajúce sa B 
opisujú pozíciu žetónu vo formáte:

```
	B pozícia_x pozícia_y počet_žetónov
```



Pre zložitejšie rozostavenie stien môžete použiť [program na generovanie Karlovho sveta](createworld.c). 
Program upravte, preložte a spustite:

```
vim createworld.c
gcc createworld.c --std=c11 -o createworld
./createworld > myworld.kw
```


