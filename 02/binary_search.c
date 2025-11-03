#include<stdio.h>

int binary_search(int *arr,int num, int n){
    int low = 0, high = n-1;
    int mid = (low+high)/2;
    while(low<=high){
        if(arr[mid] == num){
            return mid;
        }
        else if(arr[mid]>num){
            high = mid-1;
            mid = (low+high)/2;
        }
        else if(arr[mid]<num){
            low = mid+1;
            mid = (low+high)/2;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    printf("element found at %d",binary_search(arr, 8, 9));
    return 0;
}