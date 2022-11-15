#include<stdio.h>
#include<stdlib.h>
#include "LLO.c"

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

