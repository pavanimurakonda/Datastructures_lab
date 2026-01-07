#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int main() {
    int num1, num2, result;
    printf("Enter two non-negative integers: ");
    if (scanf("%d %d", &num1, &num2) != 2 || num1 < 0 || num2 < 0) {
        printf("Invalid input. Please enter two non-negative integers.\n");
        return 1;
    }
    result = gcd(num1, num2);
    printf("The GCD of %d and %d is %d\n", num1, num2, result);
    return 0;
}
