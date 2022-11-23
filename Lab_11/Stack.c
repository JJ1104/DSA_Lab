#include<stdio.h>

typedef struct BST* Node;

typedef struct Stack{
    int top;
    Node nodestack[30]; 
}Stack;

int isEmpty(Stack* s){
    if(s->top == -1)
        return 1;
    return 0;
}

void push(Stack* s,Node x){
    s->nodestack[++s->top] = x;
}

Node pop(Stack* s){
    return s->nodestack[s->top--];
}

Node top(Stack* s){
    return s->nodestack[s->top];
}