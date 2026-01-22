#include <stdio.h>
typedef struct {
    float real;
    float imag;
} Complex;
Complex add(Complex n1, Complex n2) {
    Complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return temp;
}
Complex multiply(Complex n1, Complex n2) {
    Complex temp;
    temp.real = (n1.real * n2.real) - (n1.imag * n2.imag);
    temp.imag = (n1.real * n2.imag) + (n1.imag * n2.real);
    return temp;
}
int main() {
    Complex num1, num2, sum, product;
    printf("Enter real and imaginary parts for first number: ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("Enter real and imaginary parts for second number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    sum = add(num1, num2);
    product = multiply(num1, num2);

    printf("\nSum = %.2f + %.2fi", sum.real, sum.imag);
    printf("\nProduct = %.2f + %.2fi\n", product.real, product.imag);
    return 0;
}
