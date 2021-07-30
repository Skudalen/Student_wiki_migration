#include <stdio.h>

int linear_search(int* pole,int size,int value){
    for (int i = 0; i < size; i++){
        if (pole[i] == value){
            return i;
        }
    }
    return -1;
}

int main(){
    int pole[5] = {4,3,6,7,8};
    int value = 7;
    int pole2[3] = {1,2,3};
    for (int i = 0; i < 3; i++){
        int res = linear_search(pole,5,pole2[i]);
    }


    return 0;
}
