#include<stdio.h>


void print_arr(int* arr, int n){
    printf("{");
    for(int i = 0;i<n;i++){
        printf("%d, ", arr[i]);
    }
    printf("\b\b}\n");
}


int main(){

    int arr[5][5] = {{1,1,1,1,1}, {2,2,2,2,2}, {3,3,3,3,3}, {4,4,4,4,4}, {5,5,5,5,5}};
    int sum_row[5];
    int sum_col[5];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            sum_row[i] +=arr[i][j];
            sum_col[i] += arr[j][i];
        }
    }
    print_arr(sum_row, 5);
    print_arr(sum_col, 5);
    printf("done");
    return 0;
}