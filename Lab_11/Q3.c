#include<stdio.h>
#include<stdlib.h>
#include "Stack.c"

typedef struct BST* Node;

typedef struct BST{
    char data;
    Node Rchild, Lchild;
}BST;

Node getnode(){
    Node temp = (Node)malloc(sizeof(BST));
    return temp;
}

void create_exp_tree(Node* root,char postfix[]){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    char *e = postfix;
    Node temp;
    while(*e != '\0'){
        if(*e >= '0' && *e <= '9'){
            temp = getnode();
            temp->data = *e;
            temp->Rchild = temp->Lchild = NULL;
            push(ps,temp);
        }
        else{
            temp = getnode();
            temp->data = *e;
            Node a = pop(ps);
            Node b = pop(ps);
            temp->Rchild = a;
            temp->Lchild = b;
            push(ps,temp);  
        }
        e++;
    }
    *root = pop(ps);
}

int evaluate(Node root){

    if(root->Lchild == NULL && root->Rchild == NULL){
        int val = root->data-'0';
        return val;
    }

    int l_val = evaluate(root->Lchild);
    int r_val = evaluate(root->Rchild);

    if(root->data == '+')
        return l_val+r_val;
    if(root->data == '-')
        return l_val-r_val;
    if(root->data == '*')
        return l_val*r_val;
    if(root->data == '/')
        return l_val/r_val;

}

int main(){
    Node Tree = NULL;
    char postfix[7] = "234*+5+";
    create_exp_tree(&Tree,postfix);
    int ans = evaluate(Tree);
    printf("Value of expression: %d ",ans);
}
