#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[20];
    struct date{
        int day;
        int month;
        int year;
    }d1;
    struct address{
        int houseno;
        int zip;
        char state[20];
    }addr;
}Employee;


int main(){
    int i,n;
    printf("Enter the number of employees:\n");
    scanf("%d",&n);
    Employee *ptremp;
    Employee *Emparr = (Employee*) malloc(n*sizeof(Employee));
    ptremp = Emparr;
    // Reading
    for(i=0;i<n;i++){
        printf("Enter the name of the employee:\n");
        scanf("%s",(ptremp+i)->name);
        printf("Enter the date of birth(DD/MM/YY):\n");
        scanf("%d %d %d",&(ptremp+i)->d1.day,&(ptremp+i)->d1.month,&(ptremp+i)->d1.year);
        printf("Enter address of the employee(House No,Zip code,State):\n");
        scanf("%d %d %s",&(ptremp+i)->addr.houseno,&(ptremp+i)->addr.zip,(ptremp+i)->addr.state);
        printf("\n");
    }
    // Displaying 
    for(i=0;i<n;i++){
        printf("The name of the employee: %s\n",(ptremp+i)->name);
        printf("The date of birth of the employee: %d/%d/%d\n",(ptremp+i)->d1.day,(ptremp+i)->d1.month,(ptremp+i)->d1.year);
        printf("The address of the employee: %d,%d,%s\n",(ptremp+i)->addr.houseno,(ptremp+i)->addr.zip,(ptremp+i)->addr.state);
        printf("\n");
    }
    return 0;
}