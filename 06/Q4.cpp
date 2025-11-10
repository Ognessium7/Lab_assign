#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }
    Node* front = head;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (front != tail && front->prev != tail) {
        if (front->data != tail->data) {
            return false;
        }
        front = front->next;
        tail = tail->prev;
    }
    return true;
}