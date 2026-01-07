#include <stdio.h>
int stringLength(char* str);

int main() {
    char myString[] = "Hello";
    int length = stringLength(myString);

    printf("The string is: \"%s\"\n", myString);
    printf("The length of the string is: %d\n", length);

    return 0;
}
int stringLength(char* str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}
