#include<stdio.h>
#include "SINToperations.c"

int main(){
	int n,bindig;
	printf("Enter a decimal number: ");
	scanf("%d",&n);
	STACK *ps,s;
	ps = &s;
	ps->stack = (int*)malloc(50*sizeof(int));
	ps->top = -1;
	while(n!=0){
		bindig = n%2;
		push(ps,bindig,50);
		n /= 2;
	}
	printf("Binary equivalent is: ");
	while(ps->top != -1){
		printf("%d",pop(ps));
	}
	printf("\n");
	return 0;
}