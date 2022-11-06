#include<stdio.h>
#include<stdlib.h>

typedef struct DLL* Node;

typedef struct DLL{
    int data;
    Node RLink,Llink;
}DLL;

Node getNode(){
    Node temp = (Node)malloc(sizeof(DLL));
    return temp;
}

void InsertLast(Node* List,int ele){
    Node temp = getNode();
    Node rear = *List;
    temp->data = ele;
    if(*List == NULL){
        temp->Llink = NULL;
        temp->RLink = NULL;
        *List = temp;
        return;
    }
    while(rear->RLink){
        rear = rear->RLink;
    }
    temp->Llink = rear;
    temp->RLink = NULL;
    rear->RLink = temp;
}

void InsertFront(Node* List,int ele){
    Node temp = getNode();
    Node front = *List;
    temp->data = ele;
    if(*List == NULL){
        temp->Llink = NULL;
        temp->RLink = NULL;
        *List = temp;
        return;
    }
    temp->Llink = NULL;
    temp->RLink = front;
    front->Llink= temp;
    *List = front->Llink;
}

int DeleteLast(Node* List){
    Node temp = *List;
    Node prev;
    while(temp->RLink){
        temp = temp->RLink;
    }
    prev = temp->Llink;
    prev->RLink = NULL;
    int ele = temp->data;
    free(temp);
    return ele;
}

int DeleteFront(Node* List){
    Node temp = *List;
    *List = (*List)->RLink;
    (*List)->Llink = NULL;
    int ele = temp->data;
    free(temp);
    return ele;
}

void display(Node List){
    Node temp = List;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->RLink;
    }
}

void rev_display(Node List){
    Node rear = List;
    while(rear->RLink){
        rear = rear->RLink;
    }
    Node temp = rear;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->Llink;
    }
}

int main(){
    Node DList = NULL;
    InsertFront(&DList,1);
    InsertFront(&DList,2);
    InsertFront(&DList,3);
    InsertLast(&DList,4);
    InsertLast(&DList,5);
    InsertLast(&DList,6);
    printf("%d\n",DeleteFront(&DList));
    printf("%d\n",DeleteLast(&DList));
    display(DList);
    return 0;
}