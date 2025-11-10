#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getSize(Node* head) {
    if (!head) return 0;
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};
    Node* fourth = new Node{40, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    cout << "Size of Circular Linked List: " << getSize(head) << endl;

    return 0;
}