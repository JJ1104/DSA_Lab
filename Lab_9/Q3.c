#include<stdio.h>
#include<stdlib.h>
#include "LLC.c"

void sort(Node* List){
    Node head = *List;
    Node current = *List;
    Node next = NULL;
    char x;
    while(current->next != head){
        next = current->next;
        while(next != head){
            if(current->data > next->data){
                x = current->data;
                current->data = next->data;
                next->data = x;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void merge(Node* List1,Node List2){
    Node First = *List1;
    Node Second = List2;
    Node rear = First->next;
    Node temp;
    while(rear->next != First){
        rear = rear->next;
    }
    temp = getNode();
    temp->data = List2->data;
    temp->next = First;
    rear->next = temp;
    rear = rear->next;
    List2 = List2->next;
    while(List2 != Second){
        temp = getNode();
        temp->data = List2->data;
        temp->next = First;
        rear->next = temp;
        rear = rear->next;
        List2 = List2->next;
    }
}

int main(){
    Node List1 = NULL, List2 = NULL;
    InsertRear(&List1,'d');
    InsertRear(&List1,'e');
    InsertRear(&List1,'f');
    InsertRear(&List2,'a');
    InsertRear(&List2,'b');
    InsertRear(&List2,'c');
    merge(&List1,List2);
    sort(&List1);
    display(List1);
}