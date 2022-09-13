#include<stdio.h>

void tower_hanoi(int disk,char source,char temp,char dest){
    if(disk==1){
        printf("Move the disk from %c to %c\n",source,dest);
    }
    else{
        tower_hanoi(disk-1,source,dest,temp);
        printf("Move disk from %c to %c\n",source,dest);
        tower_hanoi(disk-1,temp,source,dest);
    }
}




int main(){
    int n;
    char source,dest,aux;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("Enter the source,auxiliary and destination tower: ");
    scanf(" %c %c %c",&source,&aux,&dest);
    tower_hanoi(n,source,aux,dest);
    return 0;
}