#include<stdio.h>

int find_second_largest(int arr[],int n){
    int largest = arr[0], s_largest = arr[0], i;
 
    for(i=0;i<n;i++){
        if(arr[i]>largest){
            s_largest = largest;
            largest = arr[i];
        }
        else{
            if (arr[i] > s_largest && arr[i] != largest) {
                s_largest = arr[i];
            }
        }
    }
    return s_largest;
} 


int main()
{
    int n,i;
    int s_largest;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    s_largest = find_second_largest(arr,n);
    printf("The second largest element is %d",s_largest);
    return 0;
}