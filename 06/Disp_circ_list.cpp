#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayCircularList(Node* head) {
    if (!head) {
        cout << "Circular linked list is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl;
}

int main() {
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};

    head->next = second;
    second->next = third;
    third->next = head;

    cout << "Circular Linked List: ";
    displayCircularList(head);

    return 0;
}