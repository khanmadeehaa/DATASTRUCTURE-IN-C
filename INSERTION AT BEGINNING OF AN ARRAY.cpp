#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity of array
    int n, i, value;   //n->size

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

    // Step 4: Input value to insert at beginning
    printf("\nEnter value to insert at the beginning: ");
    scanf("%d", &value);

    // Step 5: Shift all elements one position to the right
    for(i = n - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    // Step 6: Insert value at first position
    arr[0] = value;
    n++;  // Increase size

    // Step 7: Display updated array
    printf("\nArray after insertion at beginning:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

