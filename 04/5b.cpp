#include <iostream>
#include <queue>
using namespace std;
class Stack{
    queue<int> q;
public:
    void push(int x){
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        if(q.empty()) cout<<"Empty\n";
        else q.pop();
    }
    void top(){
        if(q.empty()) cout<<"Empty\n";
        else cout<<q.front()<<endl;
    }
    void display(){
        queue<int> t=q;
        while(!t.empty()){
            cout<<t.front()<<" ";
            t.pop();
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    int ch,x;
    while(1){
        cout<<"1-Push 2-Pop 3-Top 4-Disp 5-Exit\n";
        cin>>ch;
        if(ch==1){cin>>x; s.push(x);}
        else if(ch==2) s.pop();
        else if(ch==3) s.top();
        else if(ch==4) s.display();
        else break;
    }
}
