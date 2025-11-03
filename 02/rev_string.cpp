#include <iostream>
#include<cstring>
using namespace std;

int main() {
    char str[50];
    char temp;

    cout << "Enter a string to reverse: ";
    cin >> str;

    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    cout << "The reverse of the original string is: " << str << endl;
    return 0;
}
