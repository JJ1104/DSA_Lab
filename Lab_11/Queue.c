#include<stdio.h>

typedef struct BST* Node;

typedef struct Queue{
    int front,rear;
    Node nodestack[30]; 
}Queue;

int isQEmpty(Queue* q){
    if(q->front == q->rear+1 || q->front == -1)
        return 1;
    return 0;
}

void enqueue(Queue* q,Node x){
    if(q->front == -1){
        q->front = 0;
    }
    q->nodestack[++q->rear] = x;
}

Node dequeue(Queue* q){
    if(q->front == q->rear+1){
        q->front = -1;
    }
    return q->nodestack[q->front++];
}

Node Atfront(Queue* q){
    return q->nodestack[q->front];
}