#include <stdio.h>

int main() {
    int arr[100];   // Maximum capacity of array
    int n, pos, value, i;

    // Step 1: Input current size
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);
    
	if(n == 100) 
	
	{
        printf("\nOverflow! Cannot insert more elements — array is full.\n");
        return 0;   // Exit the program safely
    }
    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 4: Input position and value
    printf("\nEnter position (1 to %d) where you want to insert: ", n + 1);
    scanf("%d", &pos);

    // Check valid position
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position! Please enter position between 1 and %d.\n", n + 1);
        return 0;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Step 5: Shift elements to the right
    for(i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    // Step 6: Insert new element
    arr[pos - 1] = value;
    n++;  // Increase size

    // Step 7: Display updated array
    printf("\nArray after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

