#include<iostream>
using namespace std;

int* createArray(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<"th element: ";
        cin>>arr[i];
    }
    return arr;
}

void displayArray(int* arr, int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<*arr<<", ";
        arr++;
    }
    cout<<"\b\b]\n";
}

void removeElement(int* arr, int pos, int n){
    int* new_arr = new int[n-1];
    for(int i=pos+1;i<n;i++){
        arr[i-1] = arr[i];
    }
    for(int i=0;i<n-1;i++){
        new_arr[i] = arr[i];
    }
    arr = new_arr;
}



void removeDuplicates(int* arr, int n){
    for(int i=0;i<n;i++){
        int c = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == arr[i]){
                c++;
            }
            if(c>=2){
                removeElement(arr, j, n);
            }
        }
    }



}




int main(){
    int* one = createArray();
    displayArray(one, 5);
    removeDuplicates(one,5);
    displayArray(one,4);
    return 0;
}
