#include<stdio.h>
#include<string.h>

int isPalindrome(char str[],int index){
    int n = strlen(str);
    if(index == n/2){
        return 1;
    }
    if(str[index] == str[n-index-1]){
        return isPalindrome(str,index+1);
    }
    return -1;
}


int main(){
    char str[20];
    printf("Enter a string: ");
    gets(str);
    if(isPalindrome(str,0)==-1){
        printf("It is not a palindrome");
    }
    else{
        printf("It is a palindrome");
    }
    return 0;
}