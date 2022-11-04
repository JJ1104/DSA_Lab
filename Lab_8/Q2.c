#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char** queue;
    int front,rear,capacity;
}Queue;

void enqueueF(Queue* pq,char str[]){
    if(pq->front == -1){
        pq->rear = pq->front = 0;
        strcpy(pq->queue[pq->front],str);
    }
    else{
        pq->front = (pq->front-1+pq->capacity)%pq->capacity;
        strcpy(pq->queue[pq->front],str);
    }
}

void enqueueR(Queue* pq,char str[]){
    if(pq->front == -1){
        pq->front = 0;
    }
    pq->rear = (pq->rear+1)%pq->capacity;
    strcpy(pq->queue[pq->rear],str);
}

char* dequeueF(Queue* pq){
    if((pq->front == pq->rear) && (pq->rear == pq->capacity-1)){
        return "EMPTY";
    }
    char* str = (char*)malloc((strlen(pq->queue[pq->front])+1)*sizeof(char));
    strcpy(str,pq->queue[pq->front]);
    pq->front = (pq->front+1)%pq->capacity;
    return str;
}

void display(Queue* pq){
    int i = pq->front;
    while(i!=pq->rear){
        printf("%s ",pq->queue[i]);
        i = (i+1)%pq->capacity;
    }
    printf("%s ",pq->queue[pq->rear]);
}

int main(){
    Queue *pq,q;
    pq = &q;
    printf("Enter the capacity: ");
    scanf("%d",&pq->capacity);
    pq->front = pq->rear = -1;
    pq->queue = (char**)malloc(pq->capacity*sizeof(char*));
    for(int i = 0; i< pq->capacity; i++){
        pq->queue[i] = (char*)malloc(20*sizeof(char));
    }
    enqueueF(pq,"Morning");
    enqueueF(pq,"Good");
    enqueueR(pq,"My");
    enqueueR(pq,"Name");
    dequeueF(pq);
    display(pq);
}
