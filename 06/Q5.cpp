#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return true;
    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
    return temp == head;
}

int main() {
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};

    head->next = second;
    second->next = third;
    third->next = head; // Comment this line to test non-circular

    if (isCircular(head))
        cout << "The linked list is circular.\n";
    else
        cout << "The linked list is not circular.\n";

    return 0;
}