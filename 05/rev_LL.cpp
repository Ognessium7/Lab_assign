#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseLL(Node* head) {
    if (head == nullptr)
        return nullptr;

    stack<Node*> s;
    Node* temp = head;

    while (temp != nullptr) {
        s.push(temp);
        temp = temp->next;
    }

    head = s.top();
    s.pop();
    temp = head;

    while (!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = nullptr;
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    cout << "Original List:\n";
    display(head);

    head = reverseUsingStack(head);

    cout << "Reversed List (using stack):\n";
    display(head);

    return 0;
}