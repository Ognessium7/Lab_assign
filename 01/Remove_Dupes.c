#include<stdio.h>


void remove_dupes(int* arr, int* n){
    for(int i = 0;i<(*n)-1;i++){
        for(int j = i+1;j<*n;j++){
            if(arr[j] == arr[i]){
                int k = j;
                while(k<(*n)-1){
                    arr[k] = arr[k+1];
                    k++;
                }
                (*n)--;
                if(arr[j] == arr[i]){
                    j--;
                }
            }
        }
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
    int arr[] = {1,2,2,1,5,5,5,5,5,5};
    int n = 6;
    remove_dupes(arr, &n);
    print_arr(arr, n);
}
