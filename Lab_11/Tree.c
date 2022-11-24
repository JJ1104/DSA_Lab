#include<stdio.h>
#include<stdlib.h>

typedef struct BT* Node;

typedef struct BT{
    int data;
    Node Rchild, Lchild;
}BT;

Node getnode(){
    Node temp = (Node)malloc(sizeof(BT));
    return temp;
}

void create_BT(Node* root){
    int x,option;
    Node temp;
    Node prev = NULL;
    if(!(*root)){
        temp = getnode();
        printf("Enter the value of root: ");
        scanf("%d",&x);
        temp->data = x;
        temp->Rchild = temp->Lchild = NULL;
        *root = temp;
        prev = *root;
    }
    Node curr = *root;
    printf("1.Go Left\n2.Go Right\n3.Go back\n4.Go to root\n5.Exit\nEnter option: ");
    scanf("%d",&option);
    while(option != 5){
        if(option == 1){
            prev = curr;
            temp = getnode();
            printf("Enter the value of left child:");
            scanf("%d",&x);
            temp->data = x;
            temp->Rchild = temp->Lchild = NULL;
            curr->Lchild = temp;
            curr = curr->Lchild;
        }
        else if(option == 2){
            prev = curr;
            temp = getnode();
            printf("Enter the value of right child:");
            scanf("%d",&x);
            temp->data = x;
            temp->Rchild = temp->Lchild = NULL;
            curr->Rchild = temp;
            curr = curr->Rchild;
        }
        else if(option == 3){
            curr = prev;
        }
        else if(option == 4){
            curr = *root;
        }
        else{
            return;
        }
        printf("Enter option: ");
        scanf("%d",&option);
    }
}