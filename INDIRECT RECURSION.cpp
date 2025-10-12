#include <stdio.h>

void functionA(int n);
void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        printf("A: %d\n", n);
        functionB(n - 1); // calls functionB
    }
}

void functionB(int n) {
    if (n > 0) {
        printf("B: %d\n", n);
        functionA(n / 2); // calls functionA
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    functionA(num); 
    return 0;
}

