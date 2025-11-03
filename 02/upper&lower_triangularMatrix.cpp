#include <iostream>
using namespace std;

int main() {
    int n;
    int i, j;
    int k = 0;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    int size = (n* (n + 1)) / 2;
    int a[size];
    cout << "Enter elements (row major):\n";
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }
    cout << "\nThe upper triangular matrix is.\n";
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j) {
                cout << a[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    cout << "\nThe lower triangular matrix is..\n";
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i >= j) {
                cout << a[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    return 0;
}
