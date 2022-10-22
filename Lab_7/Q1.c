#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue{
    char** queue;
    int front,rear,capacity;
}Queue;

void insertcq(Queue* q,char str[]){
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear+1)%q->capacity;
    strcpy(q->queue[q->rear],str);
}

char* deletecq(Queue* q){
    if(q->front == -1){
        return "Empty";
    }
    
    char* str = (char*)malloc((strlen(q->queue[q->front])+1)*sizeof(char));
    strcpy(str,q->queue[q->front]);
    q->front = (q->front+1)%q->capacity;
    return str;
}

void displaycq(Queue* q){
    for(int i=q->front;i<q->rear+1;i++){
        printf("%s ",q->queue[i]);
    }
}

int main(){
    Queue *q,que;
    q = &que; 
    printf("Enter the capacity of queue: ");
    scanf("%d",&q->capacity);   
    q->queue = (char**)malloc(q->capacity*sizeof(char*));
    for(int i =0 ;i<q->capacity;i++){
        q->queue[i] = (char*)malloc(20*sizeof(char));
    }
    q->front=q->rear=-1;
    insertcq(q,"hello");
    insertcq(q,"my");
    insertcq(q,"name");
    insertcq(q,"is");
    displaycq(q);
    printf("%s",deletecq(q));
}