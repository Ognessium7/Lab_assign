#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


void insertEnd(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}


int deleteKey(struct Node** head, int key) {
    struct Node* curr = *head;
    struct Node* prev = NULL;
    int count = 0;

    while (curr != NULL) {
        if (curr->data == key) {
            count++;
            if (prev == NULL) {
                *head = curr->next;
                free(curr);
                curr = *head;
            } else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return count;
}


void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL)
            printf("->");
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 1;


    for (int i = 0; i < n; i++)
        insertEnd(&head, arr[i]);

    printf("Original List: ");
    printList(head);

    int count = deleteKey(&head, key);

    printf("Count: %d\n", count);
    printf("Updated List: ");
    printList(head);

    return 0;
}
