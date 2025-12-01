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


Node* makeTreeW(vector<int> arr, int &index){
    index++;
    if(arr[index] == -1){
        return nullptr;
    }
    Node* root = new Node(arr[index]);
    root->left = makeTreeW(arr, index);
    root->right = makeTreeW(arr, index);
    return root;
}

Node* makeTree(vector<int> arr){
    int index = -1;
    return makeTreeW(arr, index);
}



void inOrderTraversalW(Node* n, vector<int>& arr){
    if(n == nullptr){
        return;
    }
    inOrderTraversalW(n->left,arr);
    arr.push_back(n->val);
    inOrderTraversalW(n->right, arr);
    return;
}

//wrapper func.
vector<int> inOrderTraversal(Node* n){
    vector<int> arr = {};
    inOrderTraversalW(n, arr);
    return arr;
}

void preOrderTraversalW(Node* n, vector<int>& arr){
    if(n == nullptr){
        return;
    }
    arr.push_back(n->val);
    preOrderTraversalW(n->left, arr);
    preOrderTraversalW(n->right, arr);
    return;
}

//wrapper func.
vector<int> preOrderTraversalW(Node* n){
    vector<int> arr = {};
    preOrderTraversalW(n, arr);
    return arr;
}


void postOrderTraversalW(Node* n, vector<int>& arr){
    if(n == nullptr){
        return;
    }
    postOrderTraversalW(n->left, arr);
    postOrderTraversalW(n->right, arr);
    arr.push_back(n->val);
    return;
}

//wrapper func.
vector<int> postOrderTraversal(Node* n){
    vector<int> arr = {};
    postOrderTraversalW(n, arr);
    return arr;
}


void printVec(vector<int> arr){
    cout<<"{";
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<", ";
    }
    cout<<"\b\b}"<<endl;
}

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


vector<int> levelOrderTraversal(Node* root){
    vector<int> arr;
    queue<Node*> q1;
    q1.push(root);
    while(!q1.empty()){
        queue<Node*> q2;
        while(!q1.empty()){
            if(q1.front()->left != nullptr)
            q2.push(q1.front()->left);
            if(q1.front()->right != nullptr)
            q2.push(q1.front()->right);
            arr.push_back(q1.front()->val);
            q1.pop();
        }
        q1 = q2;
    }
    return arr;
}




int main(){
    vector<int> arr = {1,6,2,8,9,0,3};
    Node* root = makeBST(arr);
    printVec(levelOrderTraversal(root));
    return 0;
}