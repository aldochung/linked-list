#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int value;
    Node *next;
} *head, *tail;

int count = 0;

Node *createNode (int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = score;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int score) {
    Node *temp = createNode(score);

    if (!head) {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
    count++;
}

void pushTail (int score) {
    Node *temp = createNode(score);
    if(!head) {
        head = tail = temp;
    }else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}

void popHead() {
    if (!head) {
        return;
    }else if  (head == tail) {
        free(head);
        head = tail = NULL;
    }else {
        Node *temp = head->next;
        head->next = NULL;
        free(head);
        head = NULL;
    }
    count--;
}

void popTail() {
    if (!head)return;
    else if (head == tail) {
        free(head);
        head = tail = NULL;
    }else {
        Node *temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
    count--;
}

int mid() {
    int x = count/2;
    int choice;
    Node *now = head;
    while(x > 0) {
        choice = now->value;
        now = now->next;
        x--;
    }
    return choice;
}

int main() {

    pushHead(50);
    pushTail(90);
    pushTail(60);
    pushHead(30);
    pushTail(62);
    pushTail(103);
    int middle;
    middle = mid();
    printf("%d",middle);
    return 0;
}