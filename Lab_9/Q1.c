#include<stdio.h>
#include<stdlib.h>
#include "LLO.c"

void InsertRear(Node* Queue,int ele){
    Node rear = *Queue;
    Node temp = getNode();
    temp->data = ele;
    temp->next = NULL;
    if(*Queue == NULL){
        *Queue = temp;
        return;
    }
    while(rear->next){
        rear = rear->next;
    }
    rear->next = temp;
}

int DeleteFront(Node* Queue){
    if(*Queue == NULL){
        printf("Queue is empty");
        return -1;
    }
    Node temp = *Queue;
    *Queue = (*Queue)->next;
    int ele = temp->data;
    free(temp);
    return ele;
}

void display(Node Queue){
    while(Queue){
        printf("%d ",Queue->data);
        Queue = Queue->next;
    }
}

int main(){
    Node Queue = NULL;
    InsertRear(&Queue,1);
    InsertRear(&Queue,2);
    InsertRear(&Queue,3);
    InsertRear(&Queue,4);
    InsertRear(&Queue,5);
    DeleteFront(&Queue);
    display(Queue);
}

