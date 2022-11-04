#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int* queue;
    int *front,*rear,capacity;
}Queue;

void insertcq(Queue* q,int ele,int i){
    if(q->front[i-1] == -1){
        (q->front[i-1])++;
    }
    if(q->front[i-1] == (q->capacity/2)-1){
        (q->front[i-1])++;
    }
    q->rear[i-1] = (q->rear[i-1]+1)%(i*q->capacity/2);
    q->queue[q->rear[i-1]] = ele;
}

int deletecq(Queue* q,int i){
    if(q->front[i-1] == q->rear[i-1]){
        return -1;
    }
    
    int ele = q->queue[q->front[i-1]];
    q->front[i-1] = (q->front[i-1]+1)%q->capacity;
    return ele;
}

void displaycq(Queue* q,int i){
    printf("Displaying Queue %d: ",i);
    for(int j=q->front[i-1];j<q->rear[i-1]+1;j++){
        printf("%d ",q->queue[j]);
    }
    printf("\n");
}


int main(){
    Queue *q,que;
    q = &que; 
    int num;
    int size;
    printf("Enter the number of queues: ");
    scanf("%d",&num);
    printf("Enter the capacity of each queue: ");
    scanf("%d",&size);
    q->capacity = num*size;   
    q->queue = (int*)malloc((num*q->capacity)*sizeof(int));
    q->front = (int*)malloc(num*sizeof(int));
    q->rear = (int*)malloc(num*sizeof(int));

    for(int i=0;i<num;i++){
        q->front[i] = q->rear[i] = (i*size)-1;
    }
    insertcq(q,1,1);
    insertcq(q,2,1);
    displaycq(q,1);
    deletecq(q,1);
    displaycq(q,1);

    insertcq(q,3,2);
    insertcq(q,4,2);
    displaycq(q,2);
}