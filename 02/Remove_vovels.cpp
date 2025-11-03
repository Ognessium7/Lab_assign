#include <iostream>
using namespace std;

int main() {
    char c[200], c1[200];
    int i, j = 0;

    cout << "Enter the string: ";
    cin.getline(c, 200);

    for (i = 0; c[i] != '\0'; i++) {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u') {
            continue;
        } else {
            c1[j++] = c[i];
        }
    }

    c1[j] = '\0'; 

    cout <<"String after removal of vowels: "<<c1<< endl;

    return 0;
}
