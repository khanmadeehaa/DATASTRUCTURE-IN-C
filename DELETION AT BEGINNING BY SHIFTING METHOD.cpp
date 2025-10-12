#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity
    int n, i, deleted;

    // Step 1: Input current size
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    // Step 2: Underflow check
    if(n == 0) {
        printf("\nUnderflow! No elements to delete.\n");
        return 0;
    }
    
    // Step 3: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 4: Store deleted element
    deleted = arr[0];
    printf("\nDeleted element is: %d\n", deleted);

    // Step 5: Shift elements to the left
    for(i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;  // Reduce size

    // Step 6: Display updated array
    printf("\nArray after deletion at beginning:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

