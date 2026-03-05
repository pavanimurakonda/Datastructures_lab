#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void create(int n) {
    struct Node *temp, *newNode, *last;
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    last->next = head;
}
void deleteLast() {
    if(head == NULL)
        return;
    struct Node *temp = head;
    struct Node *prev = NULL;
    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}
void display() {
    if(head == NULL)
        return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
}
int main() {
    int n;
    scanf("%d", &n);
    create(n);
    deleteLast();
    display();
    return 0;
}