#include <iostream>
#include <queue>
using namespace std;
class Stack{
    queue<int> q1,q2;
public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    void pop(){
        if(q1.empty()) cout<<"Empty\n";
        else q1.pop();
    }
    void top(){
        if(q1.empty()) cout<<"Empty\n";
        else cout<<q1.front()<<endl;
    }
    void display(){
        queue<int> t=q1;
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
