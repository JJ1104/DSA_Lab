#include<stdio.h>
#include<stdlib.h>

typedef struct LL* Node;

typedef struct LL{
    char data;
    Node next;
}LL;

Node getNode(){
    Node temp = (Node)malloc(sizeof(LL));
    return temp;
}

void InsertRear(Node* List,int ele){
    Node head = *List;
    Node rear;
    Node temp = getNode();
    temp->data = ele;
    temp->next = head;
    if(*List == NULL){
        *List = temp;
        head = *List;
        (*List)->next = head; 
        return;
    }
    rear = head->next;
    while(rear->next != head){
        rear = rear->next;
    }
    rear->next = temp;
}

void display(Node List){
    Node head = List;
    printf("%c ",head->data);
    Node temp = head->next;
    while(temp != head){
        printf("%c ",temp->data);
        temp = temp->next;
    }
}