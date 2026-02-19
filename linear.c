#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;
void enqueue(int value);
void dequeue();
void display();
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Successfully inserted %d\n", value);
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
