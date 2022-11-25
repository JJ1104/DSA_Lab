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

void delete(Node* root,int key){
    Node temp = *root;
    Node prev = NULL;
    while(key != temp->data){
        prev = temp;
        if(key > temp->data)
            temp = temp->Rchild;
        else
            temp = temp->Lchild;
    }
    if(temp->Rchild!=NULL && temp->Lchild!=NULL){
        Node temp2 = temp->Rchild;
        Node prev2 = temp;
        int smallest = temp2->data;
        while(temp2->Lchild != NULL){
            prev2 = temp2;
            temp2 = temp2->Lchild;
            smallest = temp2->data;
        }
        if(temp2->Rchild){
            temp->data = smallest;
            temp2->data = temp2->Rchild->data;
            prev2 = temp2;
            temp2 = temp2->Rchild;
            free(temp2);
            prev2->Rchild = NULL; 
        }
        else{
            if(prev2->Rchild->data == smallest)
                prev2->Rchild = NULL;
            else
                prev2->Lchild = NULL;
            temp->data = smallest;
            free(temp2);
        }
    }
    else if(temp->Rchild!=NULL || temp->Lchild!=NULL){
        if(temp->Rchild){
            Node child = temp->Rchild;
            temp->data = child->data;
            temp->Rchild = NULL;
            free(child);
        }
        else{
            Node child = temp->Lchild;
            temp->data = child->data;
            temp->Lchild =NULL;
            free(child);
        }
    }
    else{
        free(temp);
        if(key > prev->data)
            prev->Rchild = NULL;
        else
            prev->Lchild = NULL;
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
    create_BST(&Tree);
    inorder(Tree);
    delete(&Tree,4);
    printf("\n");
    inorder(Tree);
}
