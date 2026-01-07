#include <stdio.h>
#include <stdlib.h>
void add();
void subtract();
void multiply();
void divide();

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void add() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 + num2;
    printf("Result: %.2lf\n", result);
}
void subtract() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 - num2;
    printf("Result: %.2lf\n", result);
}
void multiply() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf("Result: %.2lf\n", result);
}
void divide() {
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    if (num2 == 0.0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        result = num1 / num2;
        printf("Result: %.2lf\n", result);
    }
}
