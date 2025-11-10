#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int getSize(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = new Node{10, nullptr, nullptr};
    Node* second = new Node{20, nullptr, head};
    Node* third = new Node{30, nullptr, second};

    head->next = second;
    second->next = third;

    cout << "Size of Doubly Linked List: " << getSize(head) << endl;

    return 0;
}