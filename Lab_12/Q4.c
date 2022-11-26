#include<stdio.h>
#include<stdlib.h>
#include "BT.c"

void create_BinaryTree(Node* root,char preorder[],char postorder[]){

}

int main(){
    Node Tree = NULL;
    char preorder[20],postorder[20];
    printf("Enter preorder: ");
    scanf("%s",preorder);
    printf("Enter postorder: ");
    scanf("%s",postorder);
    create_BinaryTree(&Tree,preorder,postorder);
}

/* preorder: 1 2 5 6 3
    postorder: 5 6 2 3 1

    1
  /    \
2        3
/ \
5   6

*/