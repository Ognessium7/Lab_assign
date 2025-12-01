#include<iostream>
#include<vector>
using namespace std;


/*Write a program to count the number of occurrences of a given key in a singly linked list and
then delete all the occurrences. */ 



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


int count_delete_key(List* l, int key){
    Node* temp = l->head;
    int itr = 0;
    Node* prev = temp;
    while(temp!=nullptr){
        if(temp->val == key){
            itr++;
            if(temp == l->head){
                l->head = temp->next;
                prev = temp->next;
                Node* n = temp;
                temp = temp->next;
                delete n;
            }
            else{
                prev->next = temp->next;
                Node* n = temp;
                temp = temp->next;
                delete n;
            }
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return itr;
}





int main(){
    vector<int> a = {1,1,1,1,1,5,4,6,7,4,3,1,1};
    List* l = createLL(a);
    cout<<count_delete_key(l, 1)<<endl;
    displayLL(l);
    return 0;
}