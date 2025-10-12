#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity of array
    int n, pos, i,deleted;

    // Step 1: Input current size
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    // Step 2: Check underflow
    if(n == 0) {
        printf("\nUnderflow! No elements to delete.\n");
        return 0;
    }
    
    // Step 3: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 4: Input position to delete
    printf("\nEnter position (1 to %d) to delete: ", n);
    scanf("%d", &pos);

    // Check valid position
    if(pos < 1 || pos > n) {
        printf("Invalid position! Please enter between 1 and %d.\n", n);
        return 0;
    }
    
    //  Store deleted element
    deleted = arr[pos - 1];
    printf("\nDeleted element is: %d\n", deleted);
    
    // Step 5: Shift elements to the left
    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;  // Decrease size

    // Step 6: Display updated array
    printf("\nArray after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

