#include <stdio.h>

void printDiamond(int n) {
    int i, j, space;
    int total_rows = n;

    for (i = 1; i <= (total_rows + 1) / 2; i++) {
        for (space = 1; space <= ((total_rows + 1) / 2) - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = (total_rows - 1) / 2; i >= 1; i--) {
        for (space = 1; space <= ((total_rows + 1) / 2) - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}
int main() {
    int rows;
    printf("Enter the number of rows for the diamond (must be an odd number): ");
    scanf("%d", &rows);
    if (rows % 2 == 0) {
        printf("Error: Please enter an odd number of rows.\n");
        return 1;
    }
    printDiamond(2*rows - 1);
    return 0;
}
