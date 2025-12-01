#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v, Node* l, Node* r){
        val = v;
        left = l;
        right = r;
    }
    Node(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
    Node(){
        val = 0;
        left = nullptr;
        right = nullptr;
    }
};


void insertIntoBST(Node*& n, int v){
    if(n == nullptr){
        n = new Node(v);
        return;
    }
    if(v<n->val){
        insertIntoBST(n->left, v);
    }
    else if(v>n->val){
        insertIntoBST(n->right, v);
    }
}


//makes a BST from a vector
Node* makeBST(vector<int> arr){
    Node* root = new Node(arr[0]);
    for(int i = 1;i<arr.size();i++){
        insertIntoBST(root, arr[i]);
    }
    return root;
}


//func to search an element in BST
Node* searchlBST(Node* root, int n){
    Node* temp = root;
    while(temp!=nullptr && temp->val!=n){
        if(n<temp->val){
            temp = temp->left;
        }
        else if(n>temp->val){
            temp = temp->right;
        }
        else{
            return temp;
        }
    }
    return nullptr;
}
//recursive search
Node* searchrBST(Node* root, int n){
    if(root->val == n){
        return root;
    }
    if(n>root->val){
        return searchrBST(root->right, n);
    }
    else if(n<root->val){
        return searchrBST(root->left, n);
    }
    return nullptr;
}

int maxElement(Node* root){
    while(root->right!=nullptr){
        root = root->right;
    }
    return root->val;
}

int minElement(Node* root){
    while(root->left!=nullptr){
        root = root->left;
    }
    return root->val;
}

// Returns the Node with the smallest value greater than val
Node* getSuccessor(Node* root, int val) {
    Node* successor = nullptr;
    Node* curr = root;

    while (curr != nullptr) {
        if (val < curr->val) {
            successor = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return successor;
}

// Returns the Node with the largest value smaller than val
Node* getPredecessor(Node* root, int val) {
    Node* predecessor = nullptr;
    Node* curr = root;

    while (curr != nullptr) {
        if (val > curr->val) {
            predecessor = curr;
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return predecessor;
}





int main(){
    vector<int> v = {1,3,6,2,8,90,4,22,46};
    Node* root = makeBST(v);

    return 0;
}