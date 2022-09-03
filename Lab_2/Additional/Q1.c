#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	int* arr = (int*) malloc(n* sizeof(int));
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	printf("Printing array in forward direction:\n");
	for(i=0;i<n;i++){
		printf("%d ",*(arr+i));
	}
	printf("\nPrinting array in reverse direction:\n");
	for(i=n-1;i>-1;i--){
		printf("%d ", *(arr+i));
	}
	printf("\n");
	return 0;
}