
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    int mid = length / 2;
    temp = head;
    for (int i = 0; i < mid; i++)
        temp = temp->next;

    cout << "Middle element: " << temp->data << endl;
}

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    findMiddle(head);
    return 0;
}
