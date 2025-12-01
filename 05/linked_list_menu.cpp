#include<iostream>
#include<vector>
using namespace std;


struct Node{
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr){}
    Node():val(0), next(nullptr){}
};

struct List{
    Node* head;
    List():head(nullptr){}
    List(Node* m):head(m){}
};



List* createLL(vector<int> arr){
    if(arr.size() == 0){
        cout<<"Empty list!"<<endl;
        return nullptr;
    }
    List* l = new List(new Node(arr[0]));
    Node* temp = l->head;
    for(int i = 1;i<arr.size();i++){
        Node* n = new Node(arr[i]);
        temp->next = n;
        temp = temp->next;
    }
    return l;
}

void displayLL(List* l){
    Node* temp = l->head;
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"nullptr"<<endl;
}


void loop(List* l){
    int c = 0;
    cout<<"============ Singly linked lists ============="<<endl;
    while(c == 0){
        char a;
        cout<<"a) Insert at beginning    b)Insert at end    c)Insert after some value\nd)Delete from begining    e)Delete from end   f)Delete a specific node\ng)Search for a node   h)Display all   i)Terminate"<<endl;
        cin>>a;
        if(l->head == nullptr){
            cout<<"list empty!"<<endl;
            break;
        }
        switch(a){
            case 'a':
            {
                int q;
                cout<<"Enter the value to insert in the beginning: ";
                cin>>q;
                Node* nodeToInsert = new Node(q);
                nodeToInsert->next = l->head;
                l->head = nodeToInsert;
                cout<<q<<" inserted at the beginning of the list."<<endl;
                break;
            }
            case 'b' :
            {
                int q;
                cout<<"Enter the value to insert at the end: ";
                cin>>q;
                Node* nodeToInsert = new Node(q);
                Node* temp = l->head;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                temp->next = nodeToInsert;
                cout<<q<<" inserted at the end of the list."<<endl;
                break;
            }
            case 'c' :
            {
                int q, r;
                cout<<"Enter the value to be inserted: ";
                cin>>q;
                cout<<"Now enter the value after which "<<q<<" must be inserted: ";
                cin>>r;
                Node* nodeToBeInserted = new Node(q);
                Node* temp = l->head;
                while(temp!=nullptr && temp->val!=r){
                    temp = temp->next;
                }
                if(temp==nullptr){
                    cout<<"Value not found inside the list, try again!"<<endl;
                    break;
                }
                else{
                    if(temp->next == nullptr){
                        temp->next = nodeToBeInserted;
                        cout<<"value inserted successfully!"<<endl;
                        break;
                    }
                    else{
                        Node* t = temp->next;
                        temp->next = nodeToBeInserted;
                        nodeToBeInserted->next = t;
                        cout<<"value inserted successfully!"<<endl;
                        break;
                    }
                }
            }
            case 'd' :
            {
                Node* temp = l->head;
                l->head = temp->next;
                delete temp;
                cout<<"Node deleted from the beginning"<<endl;
                break;
            }
            case 'e' :
            {
                Node* temp = l->head;
                Node* rev = temp;
                while(temp->next!=nullptr){
                    rev = temp;
                    temp = temp->next;
                }
                rev->next = nullptr;
                delete temp;
                cout<<"Node deleted from the end"<<endl;
                break;
            }
            case 'f':
            {
                int q;
                cout<<"Enter the node value to be deleted: ";
                cin>>q;
                Node* temp = l->head;
                while(temp->next!=nullptr && temp->next->val!=q){
                    temp = temp->next;
                }
                if(temp->next == nullptr){
                    cout<<"node not found!"<<endl;
                    break;
                }
                else{
                    Node* t = temp->next;
                    if(temp->next->next == nullptr){
                        temp->next = nullptr;
                        cout<<"Node deleted successfully!"<<endl;
                        delete t;
                        break;
                    }
                    else{
                        temp->next = temp->next->next;
                        cout<<"Node deleted successfully!"<<endl;
                        delete t;
                        break;
                    }
                }
            }
            case 'g':
            {
                int q;
                int itr = 1;
                cout<<"Enter the node value to find: ";
                cin>>q;
                Node* temp = l->head;
                while(temp->next!=nullptr && temp->next->val!=q){
                    itr++;
                    temp = temp->next;
                }
                if(temp->next == nullptr){
                    cout<<"Value not found!"<<endl;
                    break;
                }
                else{
                    cout<<"Value found at position: "<<itr+1<<endl;
                    break;
                }

            }
            case 'h':
            {
                Node* temp = l->head;
                while(temp!=nullptr){
                    cout<<temp->val<<"->";
                    temp = temp->next;
                }
                cout<<"null"<<endl;
                break;
            }
            case 'i':
            {
                c = 1;
                cout<<"Program terminating ... "<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid input, try again!"<<endl;
            }
        }
    }
}






int main(){
    vector<int> a = {1};
    List* l = createLL(a);
    loop(l);
    return 0;
}