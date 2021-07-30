# Ladenie pomocou debuggera



1. Preložte Váš program s parametrom -g
    
        gcc linear.c -g -o linear

1. Spustite debugger
    
        gdb linear

1. Zobrazte pomoc pre príkaz list a zistite ako sa zobrazuje zdrojový kód
    
        help list

1. Zobrazte pomoc pre príkaz break na nastavenie breakpointu
    
        help break
        
1. V prostredí debuggera funguje magické dopĺňanie pomocou TAB a šípok.

1. Nastavte breakpoint na funkciu main alebo na číslo riadku
    
        b main

1. Spustite program
    
        run

1. Program zastane na breakpointe. Príkazom backtrack (bt) zobrazíte aktuálne spustené funkcie. Príkaz info locals vám vypíše lokálne premenné. Príkaz print (p) vypíše obsah premennej.
    
        bt
        p it
        info locals

1. Príkazom display môžete sledovať konkrétnu premennú.
    
        display it

1. Krokujte program príkazom step (s). Príkaz continue (c) pokračuje až po ďaľší breakpoint alebo po koniec.
    
        s
        c

1. Ladený program prerušíte Ctrl+C. Debugger skončíte Ctrl+D alebo quit
    
        quit
        
# Postup pri ladení pomocou Valgrind

1. Preložte Váš program s parametrom -g
    
        gcc linear.c -g -o linear

1. Spustite program pomocou valgrindu
    
        valgrind linear
        
3. Sledujte chybové hlásenia

# Použitie s editorom ViM

V editore ViM môžete hneď nájsť tretí riadok pomocu príkazu :3 .


# Tutoriály

- [GDB Tutoriál 1](http://www.unknownroad.com/rtfm/gdbtut/)
- [GDB Tutoriál 2](https://www.tutorialspoint.com/gnu_debugger/index.htm)




