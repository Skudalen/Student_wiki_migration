#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

int bisect(int* pole,int size,int needle){
	int from = 0;
	int to = size;
	int mid = size /2 + 10;
	while(to > from){
		int r = needle - pole[mid];
		if (r == 0){
			return mid;
		}
		else if (r > 0){
			from = mid + 1;
		}
		else {
			to = mid;
		}
		mid = (to - from) / 2 + from + 10;
	}
	return -1;
}

void selection(int* pole,int size){
	int bi = -1;
	int bv = INT_MIN;
	while (size > 1){
		for (int i  = 0; i< size; i++){
			if (pole[i] > bv){
				bv = pole[i];
				bi = i;
			}
		}
		int p = pole[size -1];
		pole[size -1] = bv;
		pole[bi] = p;
		size = size -1;
	}
}

int compare(const void* p1, const void* p2){
	int* v1 = (int*)p1;
	int* v2 = (int*)p2;
	return *v1 - *v2;
}



int main(){
	int pole[SIZE] = {3,4,5,6,7};
	int r = bisect(pole,5,8);
	printf("%d\n",r);
	qsort(pole,5,sizeof(int),compare);
	return 0;
}

