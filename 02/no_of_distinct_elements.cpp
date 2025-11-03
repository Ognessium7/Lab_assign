#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int count=1;
    int n;
    cout<<"Enter the no. elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    
    
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            count++;
        }
    }
    
    cout<<count<<endl;
}
