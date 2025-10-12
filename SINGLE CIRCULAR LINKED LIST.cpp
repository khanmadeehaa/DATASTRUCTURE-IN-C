#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function prototypes
void create(int n);
void display();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int pos);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int pos);

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n--- Singly Circular Linked List Operations ---\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            create(n);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 5:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insertAtPosition(data, pos);
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Create Circular Linked List
void create(int n) {
    int i, data;
    struct Node *newNode, *temp;

    if (n <= 0) return;

    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }
    printf("Circular Linked List created successfully!\n");
}

// Display Circular Linked List
void display() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at Beginning
void insertAtBeginning(int data) {
    struct Node *newNode, *temp = head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at End
void insertAtEnd(int data) {
    struct Node *newNode, *temp = head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Insert at any Position
void insertAtPosition(int data, int pos) {
    struct Node *newNode, *temp = head;
    int i;

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && i < pos - 1) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at Beginning
void deleteAtBeginning() {
    struct Node *temp = head, *last;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    last = head;
    while (last->next != head)
        last = last->next;

    last->next = head->next;
    head = head->next;
    free(temp);
}

// Delete at End
void deleteAtEnd() {
    struct Node *temp = head, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// Delete at any Position
void deleteAtPosition(int pos) {
    struct Node *temp = head, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

