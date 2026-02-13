#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
int stack[MAX];
int top = -1;
int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}
int main() {
    push(16);
    push(23);
    push(42);
    printf("Top element is: %d\n", peek());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Top element after pop: %d\n", peek());
    return 0;
}
