#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertBefore(int target, int value);
void insertAfter(int target, int value);
void deleteFromBeginning();
void deleteFromEnd();
void deleteSpecific(int value);
void searchNode(int value);
void displayList();

int main() {
    int choice, value, target;

    do {
        cout << "\n---- Singly Linked List Menu ----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert before " << target << ": ";
                cin >> value;
                insertBefore(target, value);
                break;
            case 4:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter value to insert after " << target << ": ";
                cin >> value;
                insertAfter(target, value);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteSpecific(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    cout << "Inserted " << value << " at beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at end.\n";
}

void insertBefore(int target, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == target) {
        insertAtBeginning(value);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != target)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Target node " << target << " not found.\n";
    } else {
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << "Inserted " << value << " before " << target << ".\n";
    }
}

void insertAfter(int target, int value) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Target node " << target << " not found.\n";
    } else {
        Node* newNode = new Node{value, temp->next};
        temp->next = newNode;
        cout << "Inserted " << value << " after " << target << ".\n";
    }
}

void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;
}

void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}

void deleteSpecific(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node " << value << " not found.\n";
    } else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "Deleted node " << value << ".\n";
        delete toDelete;
    }
}

void searchNode(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << value << " not found.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}