#include <iostream>
#include <string>
#include <stack> 
using namespace std;

int main(){
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);

    stack<char>charStack;

    for (int i=0;i<str.length();i++) {
        charStack.push(str[i]);
    }

    string reversedStr = "";

    while (!charStack.empty()) {
        reversedStr += charStack.top();
        charStack.pop();
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
