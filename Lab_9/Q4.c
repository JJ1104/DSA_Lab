#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList* Node;

typedef struct LinkedList{
    int data;
    Node next;
}LinkedList;

Node getnode(){
    Node temp = (Node)malloc(sizeof(LinkedList));
    return temp;
}

Node InsertFront(Node head,int item){
    Node temp = getnode();
    temp->data = item;
    temp->next = head;
    return temp;
}

Node InsertLast(Node head,int item){
    Node rear,temp;
    temp = getnode();
    temp->data = item;
    temp->next = NULL;
    rear = head;
    if(head == NULL){
        head = temp;
        return head; 
    }
    else{
        while(rear->next)
        {
            rear = rear->next;
        }
        rear->next = temp;
        return head;
    }
}

void RemDuplicates(Node *head){
    Node current = *head;
    Node next,prev;   
    if(head == NULL){
        printf("List is Empty,cannot delete\n");
    }
    else{
        while(current != NULL){
            next = current->next;
            prev = current;
            while(next!=NULL){
                if(current->data == next->data){
                    prev->next = next->next;
                    free(next);
                    next = prev;
                }
                next = next->next;
                prev = prev->next;
            }
            current = current->next;
        }
    }
}
void display(Node head){
    Node temp;
    temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    Node List = NULL;
    List = InsertFront(List,10);
    List = InsertFront(List,5);
    List = InsertFront(List,5);
    List = InsertLast(List,20);
    List = InsertLast(List,30);
    List = InsertLast(List,30);
    display(List);
    printf("\nAfter removing duplicates:\n");
    RemDuplicates(&List);
    display(List);
    return 0;
}