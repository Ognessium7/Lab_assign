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

struct circularLL{
    Node* head;
    circularLL(Node* n):head(n){}
    circularLL():head(nullptr){}
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

void displayCll(circularLL* c){
    if(!c->head) { cout<<"List is empty"<<endl; return; }
    Node* temp = c->head;
    do {
        cout<<temp->val<<"<->";
        temp = temp->next;
    } while(temp != c->head);
    cout<<"(head)"<<endl;
}

void dloop(doubleLL* l){
    int c = 0;
    while(c == 0){
        char a;
        cout<<"============= Double linked list ================"<<endl;
        cout<<"a) Insert at beginning    b)Insert at end    c)Insert after some value\nd)Delete from begining    e)Delete from end   f)Delete a specific node\ng)Search for a node   h)Display all   i)Terminate"<<endl;
        cin>>a;
        switch(a){
            case 'a':
            {
                int q;
                cout<<"Enter the value to insert: ";
                cin>>q;
                Node* n = new Node(q);
                if(l->head == nullptr){
                    l->head = n;
                } else {
                    n->next = l->head;
                    l->head->prev = n;
                    l->head = n;
                }
                cout<<"Value inserted at the beginning."<<endl;
                break;
            }
            case 'b': 
            {
                int q;
                cout<<"Enter the value to be inserted: ";
                cin>>q;
                Node* n = new Node(q);
                if(l->head == nullptr){
                    l->head = n;
                } else {
                    Node* temp = l->head;
                    while(temp->next!=nullptr) temp = temp->next;
                    temp->next = n;
                    n->prev = temp;
                }
                cout<<"Value inserted at the end."<<endl;
                break;
            }
            case 'c':
            {
                int q, r;
                cout<<"Enter the value to be inserted: ";
                cin>>q;
                cout<<"Enter the value after which you want to insert "<<q<<": ";
                cin>>r;
                Node* temp = l->head;
                while(temp!=nullptr && temp->val!=r) temp = temp->next;
                if(temp == nullptr){
                    cout<<"Specified value not found!"<<endl;
                } else {
                    Node* n = new Node(q);
                    Node* nextNode = temp->next;
                    temp->next = n;
                    n->prev = temp;
                    n->next = nextNode;
                    if(nextNode != nullptr) nextNode->prev = n;
                    cout<<"Value inserted."<<endl;
                }
                break;
            }
            case 'd':
            {
                if(l->head == nullptr) { cout<<"List is empty"<<endl; break; }
                Node* temp = l->head;
                l->head = l->head->next;
                if(l->head != nullptr) l->head->prev = nullptr;
                delete temp;
                cout<<"Node deleted successfully."<<endl;
                break;
            }
            case 'e':
            {
                if(l->head == nullptr) { cout<<"List is empty"<<endl; break; }
                Node* temp = l->head;
                while(temp->next != nullptr) temp = temp->next;
                if(temp->prev != nullptr) temp->prev->next = nullptr;
                else l->head = nullptr;
                delete temp;
                cout<<"Node deleted successfully."<<endl;
                break;
            }
            case 'f':
            {
                int q;
                cout<<"Enter the value to delete: ";
                cin>>q;
                Node* temp = l->head;
                while(temp!=nullptr && temp->val!=q) temp = temp->next;
                if(temp == nullptr){
                    cout<<"Value not found."<<endl;
                } else {
                    if(temp->prev != nullptr) temp->prev->next = temp->next;
                    else l->head = temp->next;
                    
                    if(temp->next != nullptr) temp->next->prev = temp->prev;
                    
                    delete temp;
                    cout<<"Node deleted successfully."<<endl;
                }
                break;
            }
            case 'g':
            {
                int q;
                cout<<"Enter the value to search: ";
                cin>>q;
                int itr = 1;
                Node* temp = l->head;
                while(temp!=nullptr && temp->val!=q){
                    itr++;
                    temp=temp->next;
                }
                if(temp == nullptr) cout<<"Value not found."<<endl;
                else cout<<"Value found at pos "<<itr<<endl;
                break;
            }
            case 'h':
            {
                displayDll(l);
                break;
            }
            case 'i':
            {
                cout<<"Terminating loop... "<<endl;
                c = 1;
                break;
            }
            default:
                cout<<"Select a valid option"<<endl;
        }
    }
}

void cloop(circularLL* l){
    int c = 0;
    while(c == 0){
        char a;
        cout<<"============= Circular linked list ================"<<endl;
        cout<<"a) Insert at beginning    b)Insert at end    c)Insert after some value\nd)Delete from begining    e)Delete from end   f)Delete a specific node\ng)Search for a node   h)Display all   i)Terminate"<<endl;
        cin>>a;
        switch(a){
            case 'a':
            {
                int q;
                cout<<"Enter the value to insert: ";
                cin>>q;
                Node* n = new Node(q);
                if(l->head == nullptr){
                    l->head = n;
                    n->next = n;
                    n->prev = n;
                } else {
                    Node* tail = l->head->prev;
                    n->next = l->head;
                    n->prev = tail;
                    tail->next = n;
                    l->head->prev = n;
                    l->head = n;
                }
                cout<<"Value inserted at beginning."<<endl;
                break;
            }
            case 'b': 
            {
                int q;
                cout<<"Enter the value to insert: ";
                cin>>q;
                Node* n = new Node(q);
                if(l->head == nullptr){
                    l->head = n;
                    n->next = n;
                    n->prev = n;
                } else {
                    Node* tail = l->head->prev;
                    n->next = l->head;
                    n->prev = tail;
                    tail->next = n;
                    l->head->prev = n;
                }
                cout<<"Value inserted at end."<<endl;
                break;
            }
            case 'c':
            {
                int q, r;
                cout<<"Enter val to insert: "; cin>>q;
                cout<<"Insert after: "; cin>>r;
                if(l->head == nullptr){ cout<<"List empty"<<endl; break; }
                Node* temp = l->head;
                bool found = false;
                do {
                    if(temp->val == r) { found = true; break; }
                    temp = temp->next;
                } while(temp != l->head);

                if(!found) cout<<"Value not found"<<endl;
                else {
                    Node* n = new Node(q);
                    Node* nextNode = temp->next;
                    temp->next = n;
                    n->prev = temp;
                    n->next = nextNode;
                    nextNode->prev = n;
                    cout<<"Inserted."<<endl;
                }
                break;
            }
            case 'd':
            {
                if(l->head == nullptr) { cout<<"Empty"<<endl; break; }
                Node* temp = l->head;
                if(temp->next == temp) { // Only one node
                    l->head = nullptr;
                } else {
                    Node* tail = temp->prev;
                    l->head = temp->next;
                    tail->next = l->head;
                    l->head->prev = tail;
                }
                delete temp;
                cout<<"Deleted from beginning."<<endl;
                break;
            }
            case 'e':
            {
                if(l->head == nullptr) { cout<<"Empty"<<endl; break; }
                Node* tail = l->head->prev;
                if(tail == l->head) { // Only one node
                    l->head = nullptr;
                    delete tail;
                } else {
                    Node* newTail = tail->prev;
                    newTail->next = l->head;
                    l->head->prev = newTail;
                    delete tail;
                }
                cout<<"Deleted from end."<<endl;
                break;
            }
            case 'f':
            {
                int q;
                cout<<"Enter value to delete: "; cin>>q;
                if(l->head == nullptr) { cout<<"Empty"<<endl; break; }
                Node* temp = l->head;
                bool found = false;
                do {
                    if(temp->val == q) { found = true; break; }
                    temp = temp->next;
                } while(temp != l->head);

                if(!found) { cout<<"Value not found"<<endl; break; }
                
                if(temp == l->head && temp->next == l->head) { // Only one node
                    l->head = nullptr;
                } else {
                    if(temp == l->head) l->head = temp->next;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout<<"Deleted."<<endl;
                break;
            }
            case 'g':
            {
                int q;
                cout<<"Search value: "; cin>>q;
                if(l->head == nullptr) { cout<<"Empty"<<endl; break; }
                Node* temp = l->head;
                int pos = 1;
                bool found = false;
                do {
                    if(temp->val == q) { found = true; break; }
                    temp = temp->next;
                    pos++;
                } while(temp != l->head);
                
                if(found) cout<<"Found at pos "<<pos<<endl;
                else cout<<"Not found"<<endl;
                break;
            }
            case 'h':
            {
                displayCll(l);
                break;
            }
            case 'i':
            {
                c = 1;
                break;
            }
            default: cout<<"Invalid"<<endl;
        }
    }
}

int main(){
    int choice;
    cout << "1. Doubly Linked List\n2. Circular Linked List\nEnter choice: ";
    cin >> choice;

    vector<int> arr = {1, 2, 3};

    if(choice == 1) {
        doubleLL* dl = createDLL(arr);
        dloop(dl);
    } else if(choice == 2) {
        circularLL* cl = createCLL(arr);
        cloop(cl);
    }
    
    return 0;
}