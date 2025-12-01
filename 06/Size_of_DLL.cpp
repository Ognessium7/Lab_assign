#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int v,Node* n,Node* p):val(v), next(n), prev(p){}
    Node(int v):val(v), next(nullptr), prev(nullptr){}
    Node():val(0), next(nullptr), prev(nullptr){}
};

struct doubleLL{
    Node* head;
    doubleLL(Node* n):head(n){}
    doubleLL():head(nullptr){}
};


doubleLL* createDLL(vector<int> a){
    if(a.empty()) return new doubleLL();
    doubleLL* l = new doubleLL(new Node(a[0]));
    Node* temp = l->head;
    for(int i = 1;i<a.size();i++){
        Node* n = new Node(a[i]);
        n->prev = temp;
        temp->next = n;
        temp = n;
    }
    return l;
}

void displayDll(doubleLL* l){
    if(!l->head) { cout<<"List is empty"<<endl; return; }
    Node* temp = l->head;
    cout<<"null<-";
    while(temp!=nullptr){
        cout<<temp->val<<"<->";
        temp = temp->next;
    }
    cout<<"\b\b\b->null"<<endl;
}


int size_Dll(doubleLL* d){
    int count = 0;
    Node* temp = d->head;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}



int main(){
    doubleLL* d = createDLL({1,2,3,4,5});
    displayDll(d);
    cout<<size_Dll(d)<<endl;
    return 0;
}