#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if (n == 7){
        abort();
    }
  // Ukocovacia podmienka
  if (n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  // Rekurzivne volanie
  return fibonacci(n-1) +  fibonacci(n-2);
}

int main(){
 int res = fibonacci(40);
 printf("%d\n",res);
  return 0;
}
