#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int* queue;
    int front,rear,capacity;
}Queue;

void insertcq(Queue* q,int ele){
    if((q->rear+1) == q->capacity){
        printf("Queue is Full!\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear+1)%q->capacity;
    q->queue[q->rear] = ele;
}

int deletecq(Queue* q){
    if(q->front == -1){
        return -1;
    }
    
    int ele = q->queue[q->front];
    q->front = (q->front+1)%q->capacity;
    return ele;
}

void displaycq(Queue* q){
    for(int i=q->front;i<q->rear+1;i++){
        printf("%d ",q->queue[i]);
    }
}

int find_ele(Queue* q,int ele){
    for(int i =q->front;i<q->rear+1;i++){
        if(q->queue[i] == ele){
            return 1;
        }
    }
    return 0;
}

int main(){
    Queue *q,que;
    q = &que; 
    printf("Enter the capacity of queue: ");
    scanf("%d",&q->capacity);   
    q->queue = (int*)malloc(q->capacity*sizeof(int));
    q->front=q->rear=-1;
    insertcq(q,1);
    insertcq(q,2);
    insertcq(q,3);
    insertcq(q,4);
    if(find_ele(q,3)){
        printf("Element Found\n");
    }
    else{
        printf("Element not found\n");
    }
    displaycq(q);
    printf("\nDeleted element: %d",deletecq(q));
}