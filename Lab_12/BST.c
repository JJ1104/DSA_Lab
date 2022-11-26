#include<stdio.h>
#include<stdlib.h>

typedef struct BST* Node;

typedef struct BST{
    int data;
    Node Rchild, Lchild;
}BST;

Node getnode(){
    Node temp = (Node)malloc(sizeof(BST));
    return temp;
}

void insert(Node* root,int val){
    Node head = *root;
    Node temp = getnode();
    Node parent = NULL;

    temp->data = val;
    temp->Rchild = temp->Lchild = NULL;
    if(head == NULL){
        head = temp;
        *root = head;
        return;
    }
    while(head != NULL){
        parent = head;
        if(val > head->data){
            head = head->Rchild;
        }
        else{
            head = head->Lchild;
        }
    }
    if(val > parent->data){
        parent->Rchild = temp;
    }
    else{
        parent->Lchild = temp;
    }
    return;
}

void create_BST(Node* root){
    int val;
    while(1){
        printf("Enter the value you want to insert(-1 to exit) : ");
        scanf("%d",&val);
        if(val == -1){break;}
        insert(root,val);
    }
}