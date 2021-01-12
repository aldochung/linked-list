#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int value;
    node* next;
}*head, *tail;

node* createnode(int value)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->value = value;
    newnode->next=NULL;
    return newnode;
}


void pushTail(int value)
{
 
    node *temp = createnode(value);
    if(!head)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;//node menunjuk head yang lama
        tail = temp;//node menunjuk head yg baru
    }
}


void searchList(int x)
{
    x = x+1;
    int a=1;
    node* now = head;
    while(now)
    {
        if(a==x)
        printf("%d",now->value);

        now = now->next;
        a++;
    }
}

int main()
{
    int a[10]={1,3,5,7,9,11,13,15,17,19},n=5;
    printf("Node ke berapa dr belakang?\n");
    //scanf("%d",&n);
    for(int i=0; i<10; i++)
    {
        pushTail(a[i]);
    }
    printf("Node ke %d dari blkg:\n",n);
    searchList(10-n);
    return 0;

}