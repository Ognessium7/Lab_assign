#include <iostream>
using namespace std;

int main() {
    char s1[100], s2[50];
    int len= 0, j;

    cout << "Enter First string: ";
    cin >> s1;

    cout << "Enter Second string: ";
    cin >> s2;

    while (s1[len] != '\0') {
        len++;
    }

    for (j = 0; s2[j] != '\0'; j++, len++) {
        s1[len] = s2[j];
    }

    s1[len] = '\0';

    cout << "After concatenation: " << s1 << endl;

    return 0;
}
