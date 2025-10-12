#include <stdio.h>

int main() {
    int arr[100];   // Maximum array size
    int n, i;

    // Taking size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Taking elements from user
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Traversing (displaying) the array
    printf("\nYou entered:\n");
    for(i = 0; i < n; i++) {
        printf("Element at index %d = %d\n", i, arr[i]);
    }

    return 0;
}

