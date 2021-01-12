#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int value;
    node *next;
} *head, *tail;

node *createNode (int score){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->value = score;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int score) {
    node *temp = createNode(score);

    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushTail (int score) {
    node *temp = createNode(score);
    if(!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    }
}

void popHead() {
    if (!head) {
        return;
    }else if  (head == tail) {
        free(head);
        head = tail = NULL;
    }else {
        node *temp = head->next;
        head->next = NULL;
        free(head);
        head = NULL;
    }
}

void popTail() {
    if (!head)return;
    else if (head == tail) {
        free(head);
        head = tail = NULL;
    }else {
        node *temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
}
int minimum(){
    node *now = head;
    int minimum = 10000;
    while(now){
        if(minimum > now->value){
            minimum = now->value;
        }
        now = now->next;
    }
    return minimum;
}

int maximum(){
    node *now = head;
    int maximum = 0;
    while(now){
        if(maximum < now->value){
            maximum = now->value;
        }
        now = now->next;
    }
    return maximum;
}

int main(){
    pushHead(40);
    pushTail(60);
    pushTail(58);
    pushTail(102);
    pushTail(205);
   int max,min,jarak;
   max = maximum();
   min = minimum();
   jarak = maximum()-minimum();

    printf("maximum  = %d\n", max);
    printf("minimum = %d\n",min);
    printf("range = %d\n", jarak);

    return 0;
}
