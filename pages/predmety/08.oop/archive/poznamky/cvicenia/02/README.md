# Cvičenie 2

## Otvorenie projektu

Stiahnuť projekt

Otvoriť projekt v IntelliJ

## Vytvorte triedu Reactor

Vytvorenie triedy Reaktor
- teplota jadra
- poškodenie rekatora
- animácia reaktora

Trieda Reactor je potomkom triedy AbstractActor.

AbstractActor patrí do rámca AlienLib,triedu stačí importovať.

Kliknúť na balíček a pravým tlačítkom New Class

Stačí dopísať extends AbstractActor, import sa doplní sám.

Dopísať členské premenné:
- temperature (int)
- damage (int)
- animation (sk.tuke.oop.framework.Animation)


Čo je to sprite?
http://en.wikipedia.org/wiki/Sprite_(computer_graphics)

Zobrazením viacerých sprite za sebou na tom istom mieste vznikne animácia.

Členským premenným treba nastaviť viditeľnosť na private.

## Pozrite si rozhranie triedy Animation

http://it4kt.cnl.sk/c/oop/resources/javadoc/training.project/index.html


## Vytvorte konštruktor pre triedu reaktor

V konštruktore animácii priraďte obrázok. Číselné hodnoty nastavte na nulu.

```java
// create animation object
normalAnimation = new Animation("images/reactor_on.png", 80, 80, 100);
// play animation repeatedly
normalAnimation.setPingPong(true);
// set actor's animation to just created Animation object
setAnimation(normalAnimation);

```
animation sa dedí od AbstractActor


## Vytvorte prístupové metódy

pre damage a temerature pre čítanie.

Ich viditeľnosť nastavte na public.

## Vytvorte metódu pre zvýšenie teploty reaktora

Reaktor sa začn kaziť pri dvetisíc stupňoch a 
úplne sa pokazí pri 6000 stupňoch.

Ak teplota klesne, poškodenie zostane rovnaké.

Pri výpočte poškodenia zaokrúhľujte nadol (Math.Ceil).

Ak teplota presiahne 4000, zmeňte animáciu.

atď. zložité pravidlá

```java
public void increaseTemperature(int increase){
	if (damage >= 33 && damage <= 66){
    	temperature = temperature + increase * 1.5;
    }
    else if (damage > 66){
    	temperature = temperature + increase * 2;
    }
    else{
  		temperature = temperature + increase;
    }
  int damage = 0;
  if (temperature > 2000 && temperature < 6000){
  	damage = Math.floor((float)(temperature - 2000)/4000) ;
  }

}
```

## Vytvorte metódu pre zníženie teploty reaktora

```java
public void decreaseTemperature(int decrease){
	if (damage <= 50){
    	temperature = temperature - decrease / 2.0;
    }
    else {
    	temperature = temperature - decrease;
    }
}
```

## Vytvorte metódu pre aktualizáciu animácie reaktora 

Nastaví animáciu na základe teploty.

Viditeľnosť má byť súkromný


```java
private void updateAnimation(){
	if (temperature < 4000){
    	setAnimation("reactor_on.png",80,80,100);
	}
    else if (temperature > 6000){
    	setAnimation("reactor_broken.png",80,80,100);
    }
    else{
    	setAnimation("reactor_hot.png",80,80,100);
    }
}

```



## Dokumentácia

http://it4kt.cnl.sk/c/oop/resources/javadoc/training.project/index.html



