#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "SCHARoperations.c"

void reverse_brackets(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == '(')
            str[i] = ')';
        else if(str[i] == ')')
            str[i] = '(';
    }
}

void reverse(char str[]){
    char temp;
    int n =strlen(str);
    for(int i=0;i<n/2;i++){
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

int priority(char x){
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x =='/')
        return 2;
    return 0;
}

int main(){
    STACK *ps,s,*pprefix,prefix;
    ps = &s;
    pprefix = &prefix;
    char infix[30];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    ps->capacity = strlen(infix);
    ps->stack = (char*)malloc(ps->capacity*sizeof(char));
    ps->top = -1;
    pprefix->capacity = strlen(infix);
    pprefix->stack = (char*)malloc(pprefix->capacity*sizeof(char));
    pprefix->top = -1;
    reverse(infix);
    reverse_brackets(infix);
    char *e,x;
    e = infix;
    while(*e != '\0'){
        if(isalnum(*e))
            push(pprefix,*e);
        else if(*e == '(')
            push(ps,*e);
        else if(*e == ')'){
            while((x=pop(ps)) != '('){
                push(pprefix,x);
            }
        }
        else{
            while(priority(ps->stack[ps->top]) >= priority(*e)){
                push(pprefix,pop(ps));
            }
            push(ps,*e);
        }
        e++;
    }

    while(ps->top != -1){
        push(pprefix,pop(ps));
    }

    while(pprefix->top != -1){
        printf("%c",pop(pprefix));
    }
    return 0;
}