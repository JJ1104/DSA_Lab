#include<stdio.h>
#include<stdlib.h>

typedef struct LL* Node;

typedef struct LL{
    int data;
    Node next;
}LL;

Node getNode(){
    Node temp = (Node)malloc(sizeof(LL));
    return temp;
}

void InsertRear(Node* List,int ele){
    Node rear = *List;
    Node temp = getNode();
    temp->data = ele;
    temp->next = NULL;
    if(*List == NULL){
        *List = temp;
        return;
    }
    while(rear->next){
        rear = rear->next;
    }
    rear->next = temp;
}

void display(Node List){
    while(List){
        printf("%d ",List->data);
        List = List->next;
    }
}