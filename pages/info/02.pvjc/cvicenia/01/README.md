# 1. IP Validation

## Cvičenie 1: Úloha

Vypracujte http://it4kt.cnl.sk/c/pvjc/2018/labs.01.html[tutoriál č. 1]

Prihláste sa na https://www.codewars.com/

Skontrolujte, či je zadaný reťazec platná IPV4 adresa:

- reťazce v jazyku C sú ukončené nulou
- práve 4 čísla menšie ako 256 a väčšie ako 0
- číslo sa nesmie začínať na nulu
- číslo sa končí bodkou alebo 0 (na konci)
- všetky znaky sú číslice alebo bodky

## Postup

Budete potrebovať funkciu pre konverziu reťazca na číslo

* http://www.cplusplus.com/reference/cstdio/sscanf/[sscanf]
* http://www.cplusplus.com/reference/cstdlib/atoi/[atoi]
* http://www.cplusplus.com/reference/cstdlib/strtol/[strtol]


1. Preštudujte si dokumentáciu k funkcii na konverziu reťazcov.
2. Pripravte si funkciu na konverziu a skontrolovanie čísla.
	
    int is_number_correct(const char* str){
        return 0;
    }
    
3. Pripravte si pomocné pole, do ktorého budete postupne ukladať reťazec ,ktorý budete kontrolovať:

	char buffer[5];
    
4. Kopírujte znaky do pomocného reťazca, pokiaľ nenarazíte na bodku.

	for (int i = 0; str[i] != 0 ; i++){
    	buffer[j] = str[i];
    }
    
5. Ukončite pomocný reťazec a skontrolujte ho.

	buffer[j] = 0;
    if (!is_number_correct(buffer)){
    	return 0;
    }
    
6. Zistite, či ste identifikovali práve 4 správne časti.

	if (correct_parts == 4){
    	return 1;
    }


## Opakovanie:

- Polia v jazyku C
- Reťazce v jazyku C
