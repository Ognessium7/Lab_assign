#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void create() {
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size. Please enter a size between 1 and %d.\n", MAX_SIZE);
        size = 0;
        return;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

void display() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    int element, position;

    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert (0 to %d): ", size);
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    printf("Element inserted successfully.\n");
}

void delete_element() {
    int position;

    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully.\n");
}

int linear_search() {
    int element, i;

    if (size == 0) {
        printf("Array is empty. Cannot search.\n");
        return -1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    int choice;

    do {
        printf("\n——MENU——\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete_element();
                break;
            case 5: {
                int result = linear_search();
                if (result != -1) {
                    printf("Element found at position: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
