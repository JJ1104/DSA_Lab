#include<stdio.h>

void Reverse(int* arr_P,int n){
    int i,temp;
    for(i=0;i<n/2;i++){
        temp = *(arr_P + i);
        *(arr_P + i) = *(arr_P + (n-i-1));
        *(arr_P + (n-i-1)) = temp;
    }
}

int main(){
    int n,i;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    int* arr_P;
    int arr[n];
    arr_P = arr;
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++){
        scanf("%d",(arr_P + i));
    }
    Reverse(arr_P,n);
    printf("After Reversing:\n");
    for(i=0;i<n;i++){
        printf("%d ", *(arr_P + i));
    }
    return 0;
}