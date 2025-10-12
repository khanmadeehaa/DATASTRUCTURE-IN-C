#include <stdio.h>

int main() {
    char str1[100], str2[100], merged[200];
    int i = 0, j = 0, k = 0;

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    while (str1[i] != '\0') {
        merged[k] = str1[i];
        i++;
        k++;
    }

    while (str2[j] != '\0') {
        merged[k] = str2[j];
        j++;
        k++;
    }

    merged[k] = '\0'; 
    printf("Merged string: %s\n", merged);

    return 0;
}

