# Pulse width modulation

Digitálny výstup často nestačí:

  - nastavenie rýchlosti motora

  - jas LED diódy

  - poloha serva

# Implementácia PWM

Arduino nepodporuje DA prevodnk.

Namiesto toho posiela pulzy napätia v určitom intervale.

Čím je pulzov viac, tým väčší výkon sa posiela.

Výkon = integrál prúdu v čase

<https://learn.sparkfun.com/tutorials/pulse-width-modulation>

# Implementáca PWM

Vyberiem pin, ktorý podporuje PWM

Funkcia `analogWrite()`

# Pamäť Aduino UNO

<https://www.arduino.cc/en/Tutorial/Memory>

|        |      |                 |
| ------ | ---- | --------------- |
| Flash  | 32kB | Program         |
| SRAM   | 2kB  | Premenné        |
| EEPROM | 1kB  | Dáta po vypnutí |

# Pamäť Arduino UNO

Arduino nemá harddisk, namiesto neho slúži EEPROM a Flash

<https://www.arduino.cc/en/Tutorial/EEPROMWrite>

# Zbernica I2C

Keď nestačí počet voľných pinov.

  - Zbernica pre sériový prenos.

  - Možnosť zapojiť viac zariadení.

  - Single Master, Multiple Slave.

# Práca s I2C

O zbernicu sa stará obvod
[UART](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver-transmitter)
a knižnica [Wire](https://www.arduino.cc/en/Reference/Wire).

<https://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/>

# Zapojenie

  - Vyhľadať a zapojiť piny SDC (Serial Data Clock) a SDA (Serial Data)
    
      - na Arduino UNO analógové piny A4 a A5

  - Budeme potrebovať aj GND a 5V.

  - Zistiť adresu zariadenia
    
      - Pomocou I2C scannera alebo datasheetu

  - Komunikovať so zariadeném pomocou knižnice Wire alebo
    LiquidCrystal\_I2C

[Zapojenie LED displeja cez
I2C](https://www.sunfounder.com/learn/Sensor-Kit-v2-0-for-Arduino/lesson-1-display-by-i2c-lcd1602-sensor-kit-v2-0-for-arduino.html)

# Koniec
