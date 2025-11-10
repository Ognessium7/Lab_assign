#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr){
    const int n = arr.size();
    for(int i = 0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[min]>arr[j])
            min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return;
}

void print_vec(vector<int> arr){
    cout<<"{";
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<", ";
    }
    cout<<"\b\b}"<<endl;
}



int main(){
    vector<int> ae = {1,5,4,3,2,8,7,2};
    selectionSort(ae);
    print_vec(ae);
    return 0;
}