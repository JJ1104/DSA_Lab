#include<stdio.h>
#include<stdlib.h>
#include "BT.c"
#include "Stack.c"

void printAncestors(Node root,int key){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    while(1){
        while(root && root->data != key){
            push(ps,root);
            root = root->Lchild;
        }
        if(root && root->data == key){break;}
        if(top(ps)->Rchild == NULL){
            root = pop(ps);
            while(!(isEmpty(ps)) && top(ps)->Rchild == root){
                root = pop(ps);
            }  
        }
        if(isEmpty(ps))
            root = NULL;
        else
            root = top(ps)->Rchild;
    }

    while(!(isEmpty(ps))){
        printf("%d ",pop(ps)->data);
    }
}

void inorder(Node root){
    if(root){
        inorder(root->Lchild);
        printf("%d ",root->data);
        inorder(root->Rchild);
    }
}

int main(){
    Node Tree = NULL;
    create_BT(&Tree);
    printf("Ancestors of 6 are: ");
    printAncestors(Tree,6);
}