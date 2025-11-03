#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string:"<<endl;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]>=65 && s[i]<=90){
            s[i]+=32;
        }
    }
    cout<<"Upper case to lower case string is as follows:"<<s<<endl;
    return 0;
}
