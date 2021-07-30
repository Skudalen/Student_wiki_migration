#include <stdio.h>

void recursive_bubble(int *array,int size){
    if (size == 1){
        return;
    }
    for (int i = 1; i < size; i++){
        if (array[i] < array[i-1]){
            int c = array[i-1];
            array[i-1] = array[i];
            array[i] = c;
        }
    }
    recursive_bubble(array,size -1);
}

int main(){
    return 0;
} 
