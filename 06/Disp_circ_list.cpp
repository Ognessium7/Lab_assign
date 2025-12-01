#include <iostream>
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

struct circularLL{
    Node* head;
    circularLL(Node* n):head(n){}
    circularLL():head(nullptr){}
};


circularLL* createCLL(vector<int> a){
    if(a.empty()) return new circularLL();
    circularLL* c = new circularLL(new Node(a[0]));
    Node* temp = c->head;
    for(int i = 1;i<a.size();i++){
        Node* n = new Node(a[i]);
        n->prev = temp;
        temp->next = n;
        temp = n;
    }
    temp->next = c->head;
    c->head->prev = temp;
    return c;
}

void displayCll(circularLL* c){
    if(!c->head) { cout<<"List is empty"<<endl; return; }
    Node* temp = c->head;
    do {
        cout<<temp->val<<"<->";
        temp = temp->next;
    } while(temp != c->head);
    cout<<"(head)"<<endl;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    circularLL* head = createCLL(arr);
    cout << "Circular Linked List: ";
    displayCll(head);
    return 0;
}