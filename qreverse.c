#include <stdio.h>
#define MAX 100
int main() {
    int capacity;
    int queue[MAX];
    int stack[MAX];
    int front = 0, rear = -1;
    int i;
    scanf("%d", &capacity);
    for(i = 0; i < capacity; i++) {
        scanf("%d", &queue[++rear]);
    }
    printf("Original queue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
    int top = -1;
    for(i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }
    for(i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }
    printf("Reversed queue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}