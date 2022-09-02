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
    printf("Address of x is %u and value is %d\n",xp,*xp);
    printf("Address of xp is %u and value of x is %d\n",xpp,**xpp);
    ptr = address(xp);
    printf("Address of x which is returned from the function is %u and value of x is %d\n",ptr,*ptr);
    return 0;
}