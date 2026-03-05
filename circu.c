#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;
    return head;
}
struct Node* insertAtPosition(struct Node *head, int value, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(pos == 1) {
        struct Node *temp = head;
        while(temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
void display(struct Node *head, int n) {
    struct Node *temp = head;
    for(int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int n, value, pos;
    scanf("%d", &n);
    struct Node *head = createList(n);
    scanf("%d", &value);
    scanf("%d", &pos);
    head = insertAtPosition(head, value, pos);
    display(head, n + 1);
    return 0;
}