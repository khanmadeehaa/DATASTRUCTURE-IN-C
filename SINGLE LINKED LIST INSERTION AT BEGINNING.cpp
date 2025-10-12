#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

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

void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;  
    *head = newNode;       
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes in the original list: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nOriginal ");
    displayList(head);

    printf("\nEnter value to insert at beginning: ");
    scanf("%d", &value);

    insertAtBeginning(&head, value);

    printf("\nAfter Insertion at Beginning ");
    displayList(head);

    return 0;
}

