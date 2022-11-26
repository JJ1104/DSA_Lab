#include<stdio.h>
#include<stdlib.h>
#include "BST.c"

void inorder_suc(Node root,int key){

    static int flag = 0;
    if(root){
        inorder_suc(root->Lchild,key);
        if(flag == 1){
            printf("Inorder successor of %d is %d\n",key,root->data);
            flag = 0;
        }
        if(root->data == key){
            flag = 1;
        }
        inorder_suc(root->Rchild,key);
    }
}

int main(){
    Node Tree = NULL;
    create_BST(&Tree);
    inorder_suc(Tree,8);
    inorder_suc(Tree,10);
    inorder_suc(Tree,14);
}