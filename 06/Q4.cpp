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


bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }
    Node* front = head;
    Node* tail = head;
    while (tail->next!=nullptr) {
        tail = tail->next;
    }
    while (front != tail && front->prev != tail) {
        if (front->val != tail->val) {
            return false;
        }
        front = front->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    vector<int> v1 = {1,2,3,2,1};
    doubleLL* d1 = createDLL(v1);
    displayDll(d1);
    if(isPalindrome(d1->head)) cout<<"It is a Palindrome"<<endl;
    else cout<<"Not a Palindrome"<<endl;

    vector<int> v2 = {1,2,3,4,5};
    doubleLL* d2 = createDLL(v2);
    displayDll(d2);
    if(isPalindrome(d2->head)) cout<<"It is a Palindrome"<<endl;
    else cout<<"Not a Palindrome"<<endl;

    return 0;
}