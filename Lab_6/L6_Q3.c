#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int* dstack;
    int* top;
    int* capacity;
}DSTACK;

void push(DSTACK* s,int ele,int i){
    if(s->top[i-1] == s->capacity[i-1]){
        printf("OVERFLOW!\n");
        return;
    }
    s->dstack[(s->top[i-1])++] = ele;
}

int pop(DSTACK* s,int i,int size){
    if(s->top[i-1] == s->capacity[i-1]- size){
        printf("UNDERFLOW!\n");
        return -1;
    }
    return s->dstack[--(s->top[i-1])];
}

void display(DSTACK* s, int i,int size){
    for(int j=s->capacity[i-1]-size;j<s->top[i-1];j++)
        printf("%d ",s->dstack[j]);
    printf("\n");
}   

int main(){
    DSTACK *ps,s;
    ps = &s;
    int size;
    printf("Enter the size of stack: ");
    scanf("%d",&size);
    int MAX = size*2;
    ps->dstack = (int*)malloc(MAX*sizeof(int));
    ps->capacity = (int*)malloc(size*sizeof(int));
    ps->top = (int*)malloc(size*sizeof(int));

    for(int i=1;i<=2;i++){
        ps->capacity[i-1] = size*i;
    }
    for(int i=0;i<2;i++){
        ps->top[i] = size*i;
    } 

    push(ps,2,1);
    push(ps,6,1);
    display(ps,1,size);
    push(ps,5,2);
    push(ps,3,2);
    display(ps,2,size);
    pop(ps,1,size);
    pop(ps,2,size);
    printf("After popping:\n");
    display(ps,1,size);
    display(ps,2,size);
}