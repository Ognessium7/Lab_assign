#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    int i, j, k = 0, size = (3*n)-2;
    int a[size];

    cout << "Enter elements (row major):\n";
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }

    cout << "\nThe matrix is..\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i - j == -1 || i - j == 0 || i - j == 1) {
                cout << a[k] << " ";
                k++;
            } else {
                cout <<0;
            }
        }
        cout << "\n";
    }
    return 0;
}
