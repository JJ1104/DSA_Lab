#include<stdio.h>
#include<stdlib.h>

typedef struct SLL* Node;

typedef struct SLL{
    int val;
    int exp;
    Node next;
}SLL;

Node getnode(){
    Node temp = (Node)malloc(sizeof(SLL));
    return temp;
}

void InsertLast(Node* List,int val,int exp){
    Node temp = getnode();
    Node rear = *List;
    temp->val = val;
    temp->exp = exp;
    if(*List == NULL){
        temp->next = temp;
        *List = temp;
        return;
    }
    while(rear->next != *List){
        rear =rear->next;
    }
    temp->next = *List;
    rear->next= temp;
    return;
}

void display(Node List){
    Node temp = List;
    do{
        printf("%dx^%d ",temp->val,temp->exp);
        temp = temp->next;
    }while(temp != List);
}
