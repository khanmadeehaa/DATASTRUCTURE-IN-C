#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create doubly linked list with user input
struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int value, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode; // First node
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }

    return head;
}

// Function to display doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    displayList(head);

    return 0;
}