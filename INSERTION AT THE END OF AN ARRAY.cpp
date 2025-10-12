#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity of array
    int n, i, value;

    // Step 1: Input current size
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    // Step 2: Check for overflow
    if(n == 100) {
        printf("\nOverflow! Cannot insert more elements — array is full.\n");
        return 0;
    }
    // Step 3: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Step 4: Input value to insert at end
    printf("\nEnter value to insert at the end: ");
    scanf("%d", &value);

    // Step 5: Insert new value at end
    arr[n] = value;  // Place at next empty index
    n++;             // Increase size

    // Step 6: Display updated array
    printf("\nArray after insertion at end:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

