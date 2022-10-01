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

int main(){
	STACK *ps,s;
	ps = &s;
	char ele;
	int n,choice;
	printf("Enter the size of stack: ");
	scanf("%d",&n);
	ps->stack = (char*)malloc(n*sizeof(char));
	ps->top = -1;
	while(1){
		printf("\n1.PUSH\n");
		printf("2.POP\n");
		printf("3.DISPLAY\n");
		printf("4.EXIT\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		if(choice == 1){
			printf("Enter the element you want to push:");
			scanf(" %c",&ele);
			push(ps,ele,n);
		}
		else if(choice == 2){
			char x;
			if((x=pop(ps)) == -1){} 
			else{
				printf("Popped element is %c",x);
			}
		}
		else if(choice == 3){
			display(ps);
		}
		else{
			break;
		}
	}
	return 0;
}