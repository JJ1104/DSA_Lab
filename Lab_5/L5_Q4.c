#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int* stack;
	int* top;
}STACK;

void push(STACK* s, int ele,int index){
	s->stack[s->top[index]] = ele;
}

int main(){
	int n,ele,k;
	STACK *ps,s;
	ps = &s;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int size_of_top = n+1;
	ps->stack = (int*)malloc(n*sizeof(int));
	ps->top = (int*)malloc(size_of_top*sizeof(int));
	ps->top[0] = -1;
	for(int i = 1; i < size_of_top; i++){
		ps->top[i] = i-1;
	}
	printf("Enter the elements of the array: ");
	for(int i = 0; i < n; i++){
		scanf("%d",&ele);
		push(ps,ele,i+1);
	}
	printf("Enter the number of elements to remove: ");
	scanf("%d",&k);
	while(k!=0){
		for(int j = 1; j < size_of_top; j++){
			if(ps->stack[ps->top[j]] < ps->stack[ps->top[j+1]]){
				for(int i = j; i < size_of_top;i++){
					ps->top[i] = ps->top[i+1];
				}
				size_of_top--;
				break;
			}
		}
		k--;
	}

	for(int i =1; i<size_of_top;i++){
		printf("%d ",ps->stack[ps->top[i]]);
	}
	return 0;
}