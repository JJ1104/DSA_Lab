#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int* stack;
	int top;
	int capacity;
}STACK;

int isEmpty(STACK* s){
	if(s->top == -1)
		return 1;
	return 0;
}

int isFull(STACK* s){
	if(s->top == s->capacity - 1)
		return 1;
	return 0;
}

void push(STACK* s, int ele){
	if(isFull(s)){
		printf("\nOVERFLOW ! CANNOT PUSH\n");
		return;
	}
	s->stack[++s->top] = ele;
}

int pop(STACK* s){
	if(isEmpty(s)){
		printf("\nUNDERFLOW ! CANNOT POP\n");
		return -1;
	}
	return s->stack[s->top--];	
}

void display(STACK* s){
	if(isEmpty(s)){
		printf("\nStack is empty !\n");
		return;
	}
	for(int i = 0; i < s->top + 1; i++)
		printf("%d",s->stack[i]);
}