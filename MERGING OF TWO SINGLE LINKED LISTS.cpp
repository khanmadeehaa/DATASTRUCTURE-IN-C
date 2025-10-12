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
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
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

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* mergedHead = NULL;
    int n1, n2;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);
    head1 = createList(n1);

    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &n2);
    head2 = createList(n2);

    printf("\nFirst Linked List: ");
    displayList(head1);

    printf("Second Linked List: ");
    displayList(head2);

    mergedHead = mergeLists(head1, head2);

    printf("\nMerged Linked List: ");
    displayList(mergedHead);

    return 0;
}

