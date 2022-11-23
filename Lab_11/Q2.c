#include<stdio.h>
#include<stdlib.h>
#include "Stack.c"
#include "Queue.c"

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
    Node temp = getnode();
    Node head = *root;
    Node parent = NULL;
    temp->data = val;
    temp->Rchild = temp->Lchild = NULL;

    if(head == NULL){
        head = temp;
        *root = head;
        return ;
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

void iterative_inorder(Node root){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    Node curr = root;
    while(curr != NULL || !(isEmpty(ps))){
        while(curr){
            push(ps,curr);
            curr = curr->Lchild;
        }
        curr = pop(ps);
        printf("%d ",curr->data);
        curr = curr->Rchild;
    }
}

void iterative_preorder(Node root){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    Node curr = root;
    while(curr != NULL || !(isEmpty(ps))){
        while(curr){
            printf("%d ",curr->data);
            push(ps,curr);
            curr = curr->Lchild;
        }
        curr = pop(ps);
        curr = curr->Rchild;
    }
}


// Using Double Stack
// void iterative_postorder(Node root){
//     Stack *ps1,s1,*ps2,s2;
//     ps1 = &s1;
//     ps1->top = -1;
//     ps2 = &s2;
//     ps2->top = -1;
//     Node curr = root;
//     Node temp;
//     push(ps1,curr);
//     while(!(isEmpty(ps1))){
//         curr = pop(ps1);
//         push(ps2,curr);
//         if(curr->Lchild)
//             push(ps1,curr->Lchild);
//         if(curr->Rchild)
//             push(ps1,curr->Rchild);
//     }
//     while(!(isEmpty(ps2))){
//         temp = pop(ps2);
//         printf("%d ",temp->data);
//     }
// }

//Using Single Stack
void iterative_postorder(Node root){
    Stack *ps,s;
    ps = &s;
    ps->top = -1;
    Node curr = root;
    Node prev = NULL;
    while(curr != NULL || !(isEmpty(ps))){
        if(curr){
            push(ps,curr);
            curr = curr->Lchild;
        }
        else{
            curr = top(ps);
            if(curr->Rchild == NULL || curr->Rchild == prev){
                printf("%d ",curr->data);
                pop(ps);
                prev = curr;
                curr = NULL;
            }
            else    
                curr = curr->Rchild;
        }
    }
}

void level_order(Node root){
    Queue *pq,q;
    pq = &q;
    pq->front = pq->rear = -1;
    Node curr = root;
    enqueue(pq,curr);
    while(!(isQEmpty(pq))){
        curr = dequeue(pq);
        printf("%d ",curr->data);

        if(curr->Lchild){
            enqueue(pq,curr->Lchild);
        }
        if(curr->Rchild){
            enqueue(pq,curr->Rchild);
        }
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
    iterative_inorder(Tree);
    printf("\nPreorder : ");
    iterative_preorder(Tree);
    printf("\nPostorder : ");
    iterative_postorder(Tree);
    printf("\nLevel Order : ");
    level_order(Tree);
}
