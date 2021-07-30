# Testovanie

Ing. Daniel Hládek PhD.

Základy softvérového inžinierstva

# Testovanie

Proces hľadania rozdielov medzi očakávaným a skutočným správaním
systému.

# Chyba

Ak systém nerobí to čo má alebo robí to čo nemá.

# Prečo testovať?

  - Testovanie poskytuje spätnú väzbu.

  - Testovanie garantuje kvalitu.

  - Testovanie zabráni sklamaniu zo systému.

# Automatické testovanie

Testy by mali byť ľahko opakovateľné.

  - Testovanie regresie  
    Zabrániť tomu, aby sa chyba zopakovala.

# Plánovanie testovania

  - Ćo sa bude testovať?

  - Ako sa bude testovať?

  - Kedy sa bude testovať?

  - Koľko to bude stáť (niekedy až 40 percent nákladov)?

# Plánovanie testovania

  - Pokrytie kódu  
    koľko percent kódu sa vykoná počas testovania.

navrhnúť testy s minimálnym úsilím a maximálnou pravdepodobnosťou
odhalenia chyby.

# Plánovanie testovania

  - Test vie dokázať existenciu určitej chyby.

  - Testovanie nevie dokázať, že systém je bez chýb.

# Je nemožné kompletne a jednoducho otestovať zložitý systém

Lebo kompletný test musí byť ešte zložitejší.

# Čierna skrinka

  - Čo je vo vnútri?

  - Na testovanie nám stačí poznať dokumentáciu rozhrania.

# Úrovne testovania

  - Jednotkové testovanie.

  - Testovanie integrácie.

  - Testovanie systému.

  - Testovanie akceptácie.

# Jednotkové testovanie

  - Jednotky  
    významové časti zdrojového kódu (funkcie, metódy, triedy).
    
      - Sú jednotky správne?
    
      - Zvyčajne vyžaduje znalosť kódu

# Testovanie integrácie

  - Rozhranie  
    spôsob prístupu k viacerým jednotkám
    
      - Fungujú jednotky spolu?
    
      - Testovanie rozhrania systému.

# Testovanie systému

  - Funguje systém ako celok?

# Testovanie akceptácie

  - Spĺňa systém svoj účel na mieste nasadenia?

  - Zaplatí objednávateľ za systém?

  - Vačšinou sa vykonáva osobne.

# Nástroje pre uľahčenie tímovej spolupráce

  - Continous integration  
    automatické vykonanie jednotkových a integračných testov.

  - Continous delivery  
    udržiavanie kódu v podobe vhodnej pre okamžité nasadenie.

# Nástroje pre uľahčenie tímovej spolupráce

  - Continous deployment  
    automatické vytváranie inštalačných balíkov s pomocou testov
    akceptácie.

# Jednotkové testovanie v jazyku C

Funkcia `assert`

Je potrebný "modulárny" návrh a dokumentácia rozhrania.

Zodpovedá implementácia dokumentácii?

# Jednotkové testovanie v jazyku C

  - vstupné podmienky  
    čo je predpokladom fungovania?

  - hraničné prípady  
    ako sa funkcia správa pri "extrémnych" vstupoch?

  - správanie funkcie  
    či sa funkcia správa podľa dokumentácie?

  - výstupné podmnienky  
    vyhovuje výstup predpokladom?

# Jednotkové testovanie v jazyku C

  - Vytvorte testovacie funkcie (test function)

# Jednotkové testovanie v jazyku C

Rozhranie `sorter.h`

``` c
// Sorts the given array descending. Does nothing on empty array.
// @param non-empty array of integers
// @param number of elements in array
void sorter(int* array,int size);
```

# Testovacie funkcie

``` c
void test_sorter_empty(){
    sorter(NULL,0);
}

void test_sorter_one(){
    int a = 1;
    sorter(&a,1);
    assert(a == 1);
}
```

# Testovacie funkcie

``` c
void test_sorter_two(){
    int array = {2,3};
    sorter(array,2);
    assert(array[0] == 3);
    assert(array[1] == 2);
}
```

# Spustenie testu

  - Testovacie funkcie spojte do "testovacieho prípadu" (test case).

  - Testovacie prípady spojte do testovacej sady (test suite).

# Spustenie testu

``` c
#include <greatest.h>
SUITE(the_suite) {
    RUN_TEST(test_sorter_empty);
    RUN_TEST(test_sorter_one);
}
int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(the_suite);
    GREATEST_MAIN_END();
}
```

# Zostavenie testu

Je potrebné preložiť a zostaviť:

  - knižnica pre testovanie

  - kód testu

  - testovaný kód

  - spušťač testu (funkcia main).

# Knižnice pre testovanie jazyka C

  - greatest

  - libcheck

  - Unity

# Nástroje pre uľahčenie tímovej spolupráce

  - Jenkinks CI

  - GitLab CI

# Mocking

Nahradenie jednotiek "falošnou" testovaciou verziou.

  - CMocka

# Assert

<http://pgbovine.net/programming-with-asserts.htm>

# Bibliografia

Prednáška Z. Havlice: "Testovacia fáza v životnom cykle programového
systému"

<http://softwaretestingfundamentals.com/>

<https://codeship.com/continuous-integration-essentials>

<https://www.cs.dartmouth.edu/~campbell/cs50/artoftesting.html>

<https://xebia.com/blog/5-reasons-why-you-should-test-your-code/>
