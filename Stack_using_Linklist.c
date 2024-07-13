#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
struct Book {
    char title[50];
    int pages;
    float price;
};

// Structure for a node in the linked list
struct Node {
    struct Book data;
    struct Node* next;
};

struct Node* top = NULL; // Initialize the top of the stack to NULL

// Function to push a book onto the stack
void push(struct Book book) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to push.\n");
        return;
    }
    newNode->data = book;
    newNode->next = top;
    top = newNode;
    printf("Book pushed onto the stack.\n");
}

// Function to pop a book from the stack
void pop() {
    if (top == NULL) {
        printf("Stack is empty. Unable to pop.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("Popped book details:\n");
    printf("Title: %s\n", temp->data.title);
    printf("Number of pages: %d\n", temp->data.pages);
    printf("Price: %.2f\n", temp->data.price);
    free(temp);
}

// Function to peek at the top book without popping
void peek() {
    if (top == NULL) {
        printf("Stack is empty. Nothing to peek.\n");
        return;
    }
    printf("Top book details:\n");
    printf("Title: %s\n", top->data.title);
    printf("Number of pages: %d\n", top->data.pages);
    printf("Price: %.2f\n", top->data.price);
}

// Function to display all books in the stack
void display() {
    struct Node* current = top;
    if (current == NULL) {
        printf("Stack is empty. Nothing to display.\n");
        return;
    }
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("Title: %s\n", current->data.title);
        printf("Number of pages: %d\n", current->data.pages);
        printf("Price: %.2f\n", current->data.price);
        printf("----\n");
        current = current->next;
    }
}

int main() {
    int option;
    printf("\n*** Stack of Books Menu ***");
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
            {
                struct Book newBook;
                printf("\nEnter book details:\n");
                printf("Title: ");
                scanf(" %[^\n]", newBook.title);
                printf("Number of pages: ");
                scanf("%d", &newBook.pages);
                printf("Price: ");
                scanf("%f", &newBook.price);
                push(newBook);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}
