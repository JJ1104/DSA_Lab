#include<stdio.h>

typedef struct {
    int re;
    int img; 
}Complex;

Complex add(Complex *x, Complex *y){
    Complex temp;
    temp.re = x->re + y->re;
    temp.img = x->img + y->img;
    return temp;
}

Complex multiply(Complex *x, Complex *y){
    Complex temp;
    temp.re = x->re*y->re -(x->img*y->img);
    temp.img = x->img*y->re + (x->re*y->img);
    return temp;
}

Complex subtract(Complex *x, Complex *y){
    Complex temp;
    temp.re = x->re - y->re;
    temp.img = x->img - y->img;
    return temp;
}

int main(){
    Complex result,C1,C2;
    Complex *presult = &result,*pC1 = &C1,*pC2 = &C2;
    printf("Enter values of x and y\n");
    printf("Enter the first complex number(x+iy):\n");
    scanf("%d %d",&pC1->re,&pC1->img);
    printf("Enter the second complex number(x+iy):\n");
    scanf("%d %d",&pC2->re,&pC2->img);
    result = add(pC1,pC2);
    printf("After addition: Real Part:%d Imaginary Part:%di\n",presult->re,presult->img);
    result = multiply(pC1,pC2);
    printf("After multiplication: Real Part:%d Imaginary Part:%di\n",presult->re,presult->img);
    result = subtract(pC1,pC2);
    printf("After subtraction: Real Part:%d Imaginary Part:%di\n",presult->re,presult->img);
    return 0;
}