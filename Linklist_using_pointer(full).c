#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node before a given element
struct Node* insertBefore(struct Node* head, int data, int element) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    if (head->data == element) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != element) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node from the beginning of the list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node after a given node
struct Node* deleteAfter(struct Node* head, int element) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Element not found or it's the last element in the list. Nothing to delete.\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to search for a node with a given value
int searchNode(struct Node* head, int data) {
    int position = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

// Function to replace the value of a node with a new value
void replaceValue(struct Node* head, int oldData, int newData) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }
    printf("Element not found in the list.\n");
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory of the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data, element, position;

    while (1) {
        printf("\nOperations:\n");
        printf("1. Insert in the beginning\n");
        printf("2. Insert in the end\n");
        printf("3. Insert before a given element\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete after a given node\n");
        printf("7. Search for a node\n");
        printf("8. Replace value of a node with new value\n");
        printf("9. Display list\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                head = insertBefore(head, data, element);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter the element after which to delete: ");
                scanf("%d", &element);
                head = deleteAfter(head, element);
                break;
            case 7:
                printf("Enter the data to search for: ");
                scanf("%d", &data);
                position = searchNode(head, data);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 8:
                printf("Enter the old data to replace: ");
                scanf("%d", &data);
                printf("Enter the new data: ");
                scanf("%d", &element);
                replaceValue(head, data, element);
                break;
            case 9:
                displayList(head);
                break;
            case 10:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}