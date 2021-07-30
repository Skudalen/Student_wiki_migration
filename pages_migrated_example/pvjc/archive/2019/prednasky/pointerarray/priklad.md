# /prednasky/06.pointerarray/priklad

\#include\<stdio.h\> \#include\<stdlib.h\> \#include\<string.h\>

int compare(const void\* p1,const void\* p2){ char\* s1 =
**((char**)p1); char** s2 = \*((char**)p2); return strcmp(s1,s2);

}

int main() { printf("Hello World"); char\* pole\[100\]; char
buffer\[100\]; int counter = 0; while(1){ char\* r =
fgets(buffer,100,stdin); if (r \!= NULL){ int l = strlen(buffer);
pole\[counter\] = malloc(l + 1); memcpy(pole\[counter\],buffer,l+1);
counter = 1; } else { break; } }
qsort(pole,sizeof(char\*),counter,compare); for (int i =0; i \< counter;
i+){ printf(pole\[i\]); free(pole\[i\]); }

``` 
    return 0;
}
```
