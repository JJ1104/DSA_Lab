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

void inorder(Node root){
    if(root){
        inorder(root->Lchild);
        printf("%d ",root->data);
        inorder(root->Rchild);
    }
}

void preorder(Node root){
    if(root){
        printf("%d ",root->data);
        preorder(root->Lchild);
        preorder(root->Rchild);
    }
}

void postorder(Node root){
    if(root){
        postorder(root->Lchild);
        postorder(root->Rchild);
        printf("%d ",root->data);
    }
}

int main(){
    Node Tree = NULL;
    insert(&Tree,3);
    insert(&Tree,1);
    insert(&Tree,2);
    insert(&Tree,4);
    insert(&Tree,5);
    printf("Inorder : ");
    inorder(Tree);
    printf("\nPreorder : ");
    preorder(Tree);
    printf("\nPostorder : ");
    postorder(Tree);
}

/*
                3
             /    \
            1       4  
             \        \ 
                2       5

inorder: 1 2 3 4 5
preorder: 3 1 2 4 5
postorder: 2 1 5 4 3

*/



