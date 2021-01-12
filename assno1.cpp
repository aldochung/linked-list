#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node { 
    int data; 
    struct Node* next; 
}; 

void movenode(struct Node** destRef, struct Node** sourceRef); 

struct Node* sortedmerge(struct Node* a, struct Node* b)  { 
    struct Node x; 
    struct Node* tail = &x; 
    x.next = NULL; 
    while (1) { 
        if (a == NULL) { 
            tail->next = b; 
            break; 
        } 
        else if (b == NULL) 
        { 
            tail->next = a; 
            break; 
        } 
        if (a->data <= b->data) 
            movenode(&(tail->next), &a); 
        else
            movenode(&(tail->next), &b); 
  
        tail = tail->next; 
    } 
    return(x.next); 
} 
  
void movenode(struct Node** destRef, struct Node** sourceRef) { 
    struct Node* newNode = *sourceRef; 
    *sourceRef = newNode->next; 
    newNode->next = *destRef; 
    *destRef = newNode; 
} 
void push(struct Node** head_ref, int new_data) { 
    struct Node* new_node = 
    (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  

void printList(struct Node *node) { 
    while (node!=NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  

int main() { 
    struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL; 
  

    push(&a, 30); 
    push(&a, 20); 
    push(&a, 10); 
  
    push(&b, 20); 
    push(&b, 3); 
    push(&b, 2); 
    res = sortedmerge(a, b); 
    printf("Merged Linked List is: \n"); 
    printList(res); 
    return 0; 
} 