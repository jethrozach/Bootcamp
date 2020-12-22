#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    Node *next; 
} *head, *tail, *current, *list, *slow_p, *fast_p;

Node *createNode(int num) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int num) {
    Node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        temp->next = head;
        head = temp;
    } 
}

void pushTail(int num) {
    Node *temp = createNode(num);
    if (!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    } 
}
 
int detectLoop(Node *list) {
    slow_p = list; 
    fast_p = list;
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

void printList() {
    Node *current = head;
    while (current) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

int main() {
    pushHead(20);
    pushHead(25);
    pushTail(40);
    pushTail(45);
    printList();
    head->next->next->next->next = head;
    if (detectLoop(head)) {
        printf("Found cycle\n");
    }else {
        printf("Not found cycle\n");
    }
    return 0;
}