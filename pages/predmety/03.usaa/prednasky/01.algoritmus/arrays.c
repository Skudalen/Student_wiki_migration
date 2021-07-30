#include <stdio.h>

int linear_search(int* array,int size,int value){
    for (int i = 0; i < size; i ++){
        if (array[i] == value){
            return i;
        }
    }
    return -1;
}

int binary_search(int* array,int left,int right,int value){
    int mid = (right - left)/ 2;
    if (array[mid] == value){
        return mid;
    }
    else if (left == right){
        return -1;
    }
    else if (array[mid] < value){
        return binary_search(array,left,mid,value);
    }
    return binary_search(array,mid,right,value);
}

int main(int argc, char** argv){
    int size = -1;
    sscanf(argv[1],"%d",&size);

//    int size = 1000;
    int array[size];
    for (int i = 0; i < size; i++){
        array[i] = i;
    }
    //int res = 
    for (int i = 0; i < 10000; i++){
        binary_search(array,0,size,size/2);
        //linear_search(array,size,size/2);
    }
    //printf("%d\n",res);
    return 0;
}
