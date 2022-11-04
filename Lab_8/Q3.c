#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char* queue;
    int front,rear,capacity;
}Queue;

void enqueueF(Queue* pq,char ch){
    if(pq->front == -1){
        pq->rear = pq->front = 0;
        pq->queue[pq->front] = ch;
    }
    else{
        pq->front = (pq->front-1+pq->capacity)%pq->capacity;
        pq->queue[pq->front] = ch;
    }
}

void enqueueR(Queue* pq,char ch){
    if(pq->front == -1){
        pq->front = 0;
    }
    pq->rear = (pq->rear+1)%pq->capacity;
    pq->queue[pq->rear] = ch;
}

char dequeueF(Queue* pq){
    char ch;
    ch = pq->queue[pq->front];
    if(pq->front == pq->rear){
        pq->front = pq->rear = -1;
    }
    else{
        pq->front = (pq->front+1)%pq->capacity;    
    }
    return ch;
}

char dequeueR(Queue* pq){
    char ch;
    ch = pq->queue[pq->rear];
    if(pq->rear == pq->front)
        pq->rear = pq->front = -1;
    else
        pq->rear=(pq->rear-1+pq->capacity)%pq->capacity;
    return ch;
}

void display(Queue* pq){
    int i = pq->front;
    while(i!=pq->rear){
        printf("%c ",pq->queue[i]);
        i = (i+1)%pq->capacity;
    }
    printf("%c ",pq->queue[pq->rear]);
}

int checkPalin(Queue* pq){
    if(pq->front==-1)
        return 1;
    if(dequeueF(pq) == dequeueR(pq))
        checkPalin(pq);
    else
        return 0;
    return 1;
}

int main(){
    Queue *pq,q;
    pq = &q;
    char temp[20];
    printf("Enter the string: ");
    scanf("%s",temp);
    pq->capacity = strlen(temp);
    pq->front = pq->rear = -1;
    pq->queue = (char*)malloc(pq->capacity*sizeof(char));
    for(int i = 0; temp[i]!='\0';i++){
        enqueueR(pq,temp[i]);
    }
    if(checkPalin(pq))
        printf("It is a Palindrome");
    else
        printf("It is not a Palindrome");
}

