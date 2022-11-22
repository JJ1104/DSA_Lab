#include<stdio.h>
#include<stdlib.h>
#include "LLC.c"

Node addpoly(Node PolyA, Node PolyB){
    Node result = NULL;
    Node A = PolyA;
    Node B = PolyB;
    do{
        if(PolyA->exp == PolyB->exp){
            InsertLast(&result,PolyA->val+PolyB->val,PolyA->exp); 
            PolyA = PolyA->next;
            PolyB = PolyB->next;
        }
        else if(PolyA->exp > PolyB->exp){
            InsertLast(&result,PolyA->val,PolyA->exp);
            PolyA = PolyA->next;
        }
        else if(PolyA->exp < PolyB->exp){
            InsertLast(&result,PolyB->val,PolyB->exp);
            PolyB = PolyB->next;
        }
    }while(PolyB != B || PolyA != A);
    return result;
}

Node subpoly(Node PolyA, Node PolyB){
    Node result = NULL;
    Node A = PolyA;
    Node B = PolyB;
    do{
        if(PolyA->exp == PolyB->exp){
            InsertLast(&result,PolyA->val-PolyB->val,PolyA->exp); 
            PolyA = PolyA->next;
            PolyB = PolyB->next;
        }
        else if(PolyA->exp > PolyB->exp){
            InsertLast(&result,PolyA->val,PolyA->exp);
            PolyA = PolyA->next;
        }
        else if(PolyA->exp < PolyB->exp){
            InsertLast(&result,PolyB->val,PolyB->exp);
            PolyB = PolyB->next;
        }
    }while(PolyB != B || PolyA != A);
    return result;
}

Node mulpoly(Node PolyA, Node PolyB){
    Node result = NULL;
    Node A = PolyA;
    Node B = PolyB;
    do{
        if(PolyA->exp == PolyB->exp){
            InsertLast(&result,PolyA->val*PolyB->val,PolyA->exp); 
            PolyA = PolyA->next;
            PolyB = PolyB->next;
        }
        else if(PolyA->exp > PolyB->exp){
            InsertLast(&result,PolyA->val,PolyA->exp);
            PolyA = PolyA->next;
        }
        else if(PolyA->exp < PolyB->exp){
            InsertLast(&result,PolyB->val,PolyB->exp);
            PolyB = PolyB->next;
        }
    }while(PolyB != B || PolyA != A);
    return result;
}

void createPoly(Node* PolyA){
    int val,exp;
    printf("Enter 1 to exit\n");
    while(1){
        printf("Enter the value,exponent: ");
        scanf("%d %d",&val,&exp);
        if(val == 1)
            break;
        InsertLast(PolyA,val,exp);
    }
}

int main(){
    Node PolyA = NULL;
    Node PolyB = NULL;
    Node res;
    int choice = 0;
    while(choice != 6){
        printf("1.Create PolyA\n2.Create PolyB\n3.Add\n4.Subtract\n5.Multiply\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice == 1){
            createPoly(&PolyA);
        }
        else if(choice == 2){
            createPoly(&PolyB);
        }
        else if(choice == 3){
            res = addpoly(PolyA,PolyB);
            printf("\nAfter addition:\n");
            display(res);
        }
        else if(choice == 4){
            res = subpoly(PolyA,PolyB);
            printf("\nAfter subtraction:\n");
            display(res);
        }
        else if(choice == 5){
            res = mulpoly(PolyA,PolyB);
            printf("\nAfter multiplication:\n");
            display(res);
        }
        else{
            choice = 6;
        }
    }
}