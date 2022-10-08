#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SINToperations.c"

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
    ps->capacity = strlen(prefix);
    ps->stack = (int*)malloc(ps->capacity*sizeof(int));
    ps->top = -1;
    reverse(prefix);
    e = prefix;
    while(*e != '\0'){
        if(*e>='0' && *e<='9')
            push(ps,*e-'0');
        else{
            int val1 = pop(ps);
            int val2 = pop(ps);
            switch(*e){
                case '+': push(ps,val1+val2); break;
                case '-': push(ps,val1-val2); break;
                case '*': push(ps,val1*val2); break;
                case '/': push(ps,val1/val2); break;
                case '%': push(ps,val1%val2); break;
            } 
        }
        e++;
    }
    printf("The result is %d",pop(ps));   
    return 0;
}