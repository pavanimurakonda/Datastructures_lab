#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char item) {
    stack[++top] = item;
}
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}
int isEmpty() {
    return (top == -1);
}
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
int infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;
    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (isEmpty()) {
                return 0;
            }
            pop();
        }
        else {
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }
    while (!isEmpty()) {
        if (stack[top] == '(') {
            return 0;
        }
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return 1;
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    if (infixToPostfix(infix, postfix)) {
        printf("Postfix Expression: %s\n", postfix);
    } else {
        printf("Error: Mismatched Parentheses!\n");
    }
    return 0;
}
