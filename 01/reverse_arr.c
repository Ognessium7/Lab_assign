#include<stdio.h>

void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void rev_arr(int* arr, int n){
    for(int i = 0;i<=(n/2)-1;i++){
        swap(&arr[i], &arr[n-1-i]);
    }
}


void print_arr(int* arr, int n){
    printf("{");
    for(int i = 0;i<n;i++){
        printf("%d, ", arr[i]);
    }
    printf("\b\b}\n");
}


int main(){
    int arr[] = {1,2,3,4,5};
    rev_arr(arr, 5);
    print_arr(arr, 5);
    return 0;
}