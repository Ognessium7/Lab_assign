#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) 
        root->left = insert(root->left, val);
    else if (val > root->data) 
        root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    
    if (key < root->data) 
        root->left = deleteNode(root->left, key);
    else if (key > root->data) 
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* node) {
    if (!node) return 0;
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    return max(lDepth, rDepth) + 1;
}

int minDepth(Node* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    if (!node->left) return minDepth(node->right) + 1;
    if (!node->right) return minDepth(node->left) + 1;
    return min(minDepth(node->left), minDepth(node->right)) + 1;
}

int main() {
    Node* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};
    
    for (int x : keys) {
        root = insert(root, x);
    }

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 20); 
    cout << "Max Depth after delete: " << maxDepth(root) << endl;

    return 0;
}