#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
        printf("\n--- Doubly Circular Linked List Operations ---\n");
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

// Function to create a doubly circular linked list
void create(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0)
        return;

    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = head;
    head->prev = head;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;

        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
        temp = newNode;
    }

    printf("Doubly Circular Linked List created successfully!\n");
}

// Display the list
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node *newNode, *last;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node *newNode, *last;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// Insert at any position
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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning() {
    struct Node *last, *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    last = head->prev;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    struct Node *last;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    last = head->prev;
    last->prev->next = head;
    head->prev = last->prev;
    free(last);
}

// Delete at any position
void deleteAtPosition(int pos) {
    struct Node *temp = head;
    int i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    for (i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (temp == head) {
        printf("Position out of range!\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

