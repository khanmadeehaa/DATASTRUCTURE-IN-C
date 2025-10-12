#include <stdio.h>

int main() {
    int arr[100];
    int n, deleted, i;

    // Step 1: Input current size
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    // Step 3: Underflow check
    if(n == 0) {
        printf("\nUnderflow! No elements to delete.\n");
        return 0;
    }

    // Step 3: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 4: Store deleted element (last one)
    deleted = arr[n - 1];
    printf("\nDeleted element is: %d\n", deleted);

    // Step 5: Reduce size (logical deletion)
    n--;  // The last element is now ignored

    // Step 6: Display updated array
    printf("\nArray after deletion at end:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

