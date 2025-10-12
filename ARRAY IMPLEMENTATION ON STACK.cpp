#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // maximum size of the stack

int stack[MAX];
int top = -1;  

void push(int value);
void pop();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Implementation Using Array ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Push function (checks overflow)
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Pop function (checks underflow)
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Display the stack
void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

