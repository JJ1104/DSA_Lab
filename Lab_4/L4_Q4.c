#include<stdio.h>

int tower_hanoi(int disk,char source,char temp,char dest){
    static int count = 0;
    count++;
    if(disk==1){
        printf("Move the disk from %c to %c\n",source,dest);
    }
    else{
        tower_hanoi(disk-1,source,dest,temp);
        printf("Move disk from %c to %c\n",source,dest);
        tower_hanoi(disk-1,temp,source,dest);
    }
    return count;
}




int main(){
    int n,count;
    char source,dest,aux;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("Enter the source,auxiliary and destination tower: ");
    scanf(" %c %c %c",&source,&aux,&dest);
    count = tower_hanoi(n,source,aux,dest);
    printf("Number of moves is %d\n",count);
    return 0;
}
