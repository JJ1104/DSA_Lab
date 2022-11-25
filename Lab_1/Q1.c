#include<stdio.h>

double Add(double arr[],int n)
{
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        sum += arr[i];
    }
    return sum;
}


int main()
{
    int n,i;
    double sum;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    double arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%lf",&arr[i]);
    }
    sum = Add(arr,n);
    printf("The sum of the elements of the array are: %lf",sum);
    return 0;
}