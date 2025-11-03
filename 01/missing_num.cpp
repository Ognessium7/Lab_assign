#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no of elements in the array:"<<endl;
    cin>>n;
    int arr[n];
    int total = (n+1)*(n+2) / 2;
    int sum =0;
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<"The missing number is"<< (total-sum) <<endl;
}
