#include <stdio.h>

// Function to print factorial recursion as a tree
int factorial(int n, int level) {
    // Print indentation based on recursion level
    for (int i = 0; i < level; i++)
        printf("    ");  

    printf("factorial(%d)\n", n);

    if (n == 0) {
        for (int i = 0; i < level; i++)
            printf("    ");
        printf("Return 1\n");
        return 1;
    }

    int result = n * factorial(n - 1, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");
    printf("Return %d\n", result);

    return result;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int fact = factorial(num, 0);
    printf("\nFactorial of %d = %d\n", num, fact);

    return 0;
}

