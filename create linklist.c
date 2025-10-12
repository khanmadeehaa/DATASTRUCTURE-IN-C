#include <stdio.h>
#include <stdlib.h>

// structure of node
struct Node {
    int data;
    struct Node* next;
};

// function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &data);
        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// function to display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// main function
int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);
    displayList(head);

    return 0;
}