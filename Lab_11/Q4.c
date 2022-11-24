#include<stdio.h>
#include<stdlib.h>
#include "Tree.c"

Node copy(Node root){
    if(root==NULL)
        return NULL;
    Node ctree = getnode();
    ctree->data = root->data;
    ctree->Lchild = ctree->Rchild = NULL;
    ctree->Lchild = copy(root->Lchild);
    ctree->Rchild = copy(root->Rchild);

    return ctree;
}

int equals(Node Tree1,Node Tree2){
    if (Tree1 == NULL && Tree2 == NULL) {
        return 1;
    }
    return (Tree1 && Tree2) && (Tree1->data == Tree2->data) &&
            equals(Tree1->Lchild, Tree2->Lchild) &&
            equals(Tree1->Rchild, Tree2->Rchild);
}

int main(){
    Node tree1 = NULL;
    Node tree2 = NULL;
    create_BT(&tree1);
    tree2 = copy(tree1);
    if(equals(tree1,tree2))
        printf("\nThey are equal");
    else
        printf("\nThey are not equal");
}