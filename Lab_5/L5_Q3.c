#include<stdio.h>
#include "SCHARoperations.c"
#include<string.h>

int checkpalin(STACK* s,char str[],int size){
	int flag;
	for(int i = 0; str[i]!='\0'; i++){
		push(s,str[i],size);
	}
	for(int i = 0; i<= strlen(str)/2;i++){
		if(pop(s) == str[i])
			flag = 1;
		else{
			flag =0;
			break;
		}
	}
	return flag;
}


int main(){
	STACK *ps,s;
	ps = &s;
	char str[30];
	printf("Enter the string: ");
	scanf("%s",str);
	int size = 30;
	ps->stack = (char*)malloc(size*sizeof(char));
	ps->top = -1;
	if(checkpalin(ps,str,size)){
		printf("It is a palindrome\n");
	}
	else
		printf("It is not a palindrome\n");
	return 0;
}