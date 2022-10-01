#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char* stack;
	int top;
}STACK;

int isEmpty(STACK* s){
	if(s->top == -1)
		return 1;
	return 0;
}

int isFull(STACK* s,int size){
	if(s->top == size - 1)
		return 1;
	return 0;
}

void push(STACK* s, char ele,int size){
	if(isFull(s,size)){
		printf("\nOVERFLOW ! CANNOT PUSH\n");
		return;
	}
	s->stack[++s->top] = ele;
}

char pop(STACK* s){
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
		printf("%c",s->stack[i]);
}