#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int main(){
    string s;
    cin>>s;
    queue<char> q;
    unordered_map<char,int> m;
    for(char c:s){
        m[c]++;
        q.push(c);
        while(!q.empty() && m[q.front()]>1) q.pop();
        if(q.empty()) cout<<"-1 ";
        else cout<<q.front()<<" ";
    }
}
