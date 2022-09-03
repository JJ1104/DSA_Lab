#include<stdio.h>
#include<string.h>

int isPalin(char strarr[]){
	int i,flag=1,n=strlen(strarr);
	char* p = strarr;
	for(i=0;i<n/2;i++){
		if(*(p+i) == *(p+(n-i-1)))
			flag = 1;
		else{
			flag=0;
			break;
		}
	}
	return flag;
}

int main(){
	char strarr[20];
	printf("Enter your string:\n");
	scanf("%s",strarr);
	if(isPalin(strarr)){
		printf("It is a Palindrome\n");
	}
	else
		printf("It is not a Palindrome");
	printf("\n");
}