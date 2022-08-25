#include <stdio.h>
 
int Lsearch(int arr[], int n, int ele)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == ele)
            return i;
    return -1;
}
 

int main()
{
    int n,ele,i,result;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search for:\n");
    scanf("%d",&ele);
    result = Lsearch(arr, n, ele);
    (result == -1)? printf("Element is not present in array\n"):printf("Element is present at index %d\n", result);
    return 0;
}
 
    