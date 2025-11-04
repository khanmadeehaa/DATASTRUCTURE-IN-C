#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create linked list with user input
struct Node* createList(int n) {
    struct Node* head = NULL, *temp = NULL, *newNode = NULL;
    int value, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

// Function to delete node at any position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    // Delete first node
    if (pos == 1) {
        *head = temp->next;
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
        return;
    }

    // Traverse to the node before the one to delete
    int i;
    struct Node* prev = NULL;
    for (i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position! Node not deleted.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, pos;

    printf("Enter number of nodes in the list: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter position to delete (1 = beginning): ");
    scanf("%d", &pos);

    deleteAtPosition(&head, pos);

    printf("\nAfter Deletion ");
    displayList(head);

    return 0;
}

