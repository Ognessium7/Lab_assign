#include<iostream>
using namespace std;
int main(){
    int rows,columns;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter the number of columns:"<<endl;
    cin>>columns;
    int arr[rows*rows];
    cout<<"Enter the elements of the diagonal matrix:"<<endl;
    for(int i=0;i<rows;i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<"The matrix is :"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(i==j){
                cout<<arr[i]<<" ";
        }
        else{
            cout<<0<<" ";
        }
    }
    cout<<endl;
}
}
