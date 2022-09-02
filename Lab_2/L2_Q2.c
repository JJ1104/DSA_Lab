#include<stdio.h>
#include<stdlib.h>

int Smallest(int* arr_P,int n){
    int i, smallest = *(arr_P);
    for(i=0;i<n;i++){
        if(*(arr_P + i) < smallest){
            smallest = *(arr_P + i);
        }
    }
    return smallest;
}


int main()
{
    int i,n,small;
    printf("Enter the number of elements in an array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    int* arr = (int*) calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    small = Smallest(arr,n);
    printf("The smallest element is %d",small);
    return 0;
}