#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "SStringoperations.c"

void reverse(char str[]){
    char temp;
    int n =strlen(str);
    for(int i=0;i<n/2;i++){
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

int main(){
    STACK *ps,s;
    ps = &s;
    char prefix[30];
    char *e,x;
    printf("Enter the prefix expression: ");
    scanf("%s",prefix);
    ps->capacity = 10;
    ps->stack = (char**)malloc(ps->capacity*sizeof(char*));
    for(int i=0;i<10;i++){
        ps->stack[i] = (char*)malloc(10*sizeof(char));
    }
    ps->top = -1;
    reverse(prefix);
    e = prefix;
    char exp[10];
    while(*e != '\0'){
        if(isalnum(*e)){
            exp[0]=*e;
            exp[1]='\0';
            push(ps,exp);
        }
        else{
            char* op1 = pop(ps);
            char* op2 = pop(ps);
            strcat(op1,op2);
            exp[0] =*e;
            exp[1] ='\0';
            strcat(op1,exp);
            push(ps,op1);
            }
        e++;
        }

    printf("%s",pop(ps));
}
