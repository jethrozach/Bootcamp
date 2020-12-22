#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    Node *next;
};

void pushHead(struct Node** ref, int number) { 
    Node* new_node = (Node*) malloc(sizeof(Node)); 
    new_node->num  = number; 
    new_node->next = (*ref); 
    (*ref) = new_node; 
} 

Node* SortedMerge(Node* a, Node* b){ 
    Node* answer = NULL; 
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    if (a->num < b->num){ 
        answer = a; 
        answer->next = SortedMerge(a->next, b); 
    } 
    else { 
        answer = b; 
        answer->next = SortedMerge(a, b->next); 
    } 
    return(answer); 
}

void printlist (Node *node){
    while (node != NULL){
        printf ("%d ",node -> num);
        node = node -> next;
    }
}

int main (){
    Node *a = NULL;
    Node *b = NULL;
    Node *ans = NULL;
    pushHead (&a, 15);
    pushHead (&a, 10);
    pushHead (&a, 5);
    pushHead (&b, 20);
    pushHead (&b, 3);
    pushHead (&b, 2);

    ans = SortedMerge(a, b);
    printf ("Merged Linked list: ");
    printlist(ans);
}