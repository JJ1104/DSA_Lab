#include<stdio.h>
int* address(int*);


int* address(int* a){
    return a;  
}


int main(){
    int x=5;
    int* xp = &x;
    int* ptr;
    int** xpp = &xp;

    printf("Value of x is %d\n",x);
    printf("Address of x is %p and value is %d\n",xp,*xp);
    printf("Address of xp is %p and value of x is %d\n",xpp,**xpp);
    ptr = address(xp);
    printf("Address of xp which is returned from the function is %p and value of x is %d\n",ptr,*ptr);
    return 0;
}