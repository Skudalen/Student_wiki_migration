// Cezarovo sifrovanie, priklad z prednasky c. 7 o retazcoch
// Daniel Hladek (c) 2019
#include <stdio.h>
#include <stdlib.h>
#define SIZE 127

char cesar(char c,int kod){
	if (c >= 'a' && c <= 'z'){
		int tajny = c - 'a';
		tajny += kod;
		tajny = tajny % ('z' - 'a');
		tajny += 'a';
		return tajny;
	}
	if (c >= 'A' && c <= 'Z'){
		int tajny = c - 'A';
		tajny += kod;
		tajny = tajny % ('Z' - 'A');
		tajny += 'A';
		return tajny;
	}
	return c;
}

void koduj(char* retazec,int kod){
	    for (int i = 0; retazec[i] != 0; i++){
		    retazec[i] = cesar(retazec[i],kod);
	    }
}

int main(int argc, char** argv){
	//printf("Pocet argumentov je %d\n",argc);
	//printf("Prvy argument je %s\n",argv[0]);
	if (argc < 2){
		printf("Malo argumentov, prosim zadaj heslo ako argument");
		return 0;
	}
	//printf("Druhy argument je %s\n",argv[1]);
	int kluc = 0;
	kluc = strtol(argv[1],NULL,10);
	if (kluc == 0){
		printf("Kluc nie je spravne cislo\n");
		return 0;
	}
	char buffer[SIZE];
	while (1){
		char* r = fgets(buffer,SIZE,stdin);
		if (r != NULL){
			koduj(buffer,3);
			printf("%s",buffer);
		}
		else {
			printf("koniec\n");
			break;
	        }	
	}
	return 0;
}

