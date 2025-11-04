#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  
int queue[SIZE];
int front = -1, rear = -1;
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("\nQueue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
    } else {
        printf("%d deleted from queue.\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}
void peek() {
    if (front == -1)
        printf("\nQueue is empty.\n");
    else
        printf("Front element is: %d\n", queue[front]);
}

void display() {
    if (front == -1)
        printf("\nQueue is empty.\n");
    else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
    int choice, value;
    while (1) {
        printf("\n\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}