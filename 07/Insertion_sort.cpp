#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr){
    const int n = arr.size();
    for(int i = 1;i<n-1;i++){
        int target = i+1;
        while(target>=1 && arr[target]<arr[target-1]){
            int temp = arr[target-1];
            arr[target-1] = arr[target];
            arr[target] = temp;
            target = target - 1;
        }
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
    insertionSort(ae);
    print_vec(ae);
    return 0;
}