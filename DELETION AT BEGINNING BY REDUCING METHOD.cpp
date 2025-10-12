#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;  
    
    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    n = n - 1;  
    
    printf("\nArray after deleting first element: ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", arr[i]); 
    }

    return 0;
}
