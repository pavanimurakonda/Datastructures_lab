#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
    stack[++top] = value;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char postfix[]) {
    int i;
    int operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }
        else {
            operand2 = pop();
            operand1 = pop();
            switch (postfix[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default:
                    printf("Invalid Operator\n");
                    return -1;
            }
            push(result);
        }
    }
    return pop();
}
int main() {
    char postfix[MAX];
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
