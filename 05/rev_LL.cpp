#include<iostream>
#include<vector>
using namespace std;

//Write a program to reverse a linked list. 


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


void reverseLL(List* l){
    if(l->head->next == nullptr){
        return;
    }
    Node* temp, *prev, *a;
    temp = prev = l->head;
    while(temp!=nullptr){
        if(temp == l->head){
            temp = temp->next;
            prev->next = nullptr;
        }
        else{
            Node* t = prev;
            a = prev = temp;
            temp = temp->next;
            prev->next = t;
        }
    }
    l->head = a;
}


int main(){
    vector<int> a = {1,2,3,4,5};
    List* l = createLL(a);
    reverseLL(l);
    displayLL(l);
    return 0;
}