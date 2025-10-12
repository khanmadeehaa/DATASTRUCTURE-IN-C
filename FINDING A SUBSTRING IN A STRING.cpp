#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub[50];
    char *pos;

    printf("Enter main string: ");
    gets(str);

    printf("Enter substring to find: ");
    gets(sub);

    pos = strstr(str, sub);

    if (pos != NULL)
        printf("Substring found at position: %ld\n", (pos - str) + 1);
    else
        printf("Substring not found.\n");

    return 0;
}

