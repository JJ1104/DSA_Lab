#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
		int day;
		char *month;
		int year;
	}DOB;

typedef struct{
		int reg_no;
		char *name;
		char address[30];
	}STU_INFO;

typedef struct{
	char *college_name;
	char university_name[30];
}COLLEGE;

typedef struct{
	DOB *pdob;
	STU_INFO stuinfo;
	COLLEGE college;
}Student;


int main(){
	int i,n;
	Student *pstu;
	printf("Enter the number of students\n");
	scanf("%d",&n);
	pstu = (Student *) malloc(n*sizeof(Student));
	char temp[20];

	//Initialising
	DOB d1;
	pstu->pdob = &d1;
	// STU_INFO si1;
	// pstu->pstuinfo = &si1;
	// COLLEGE c1;
	// pstu->pcollege = &c1;
	for(i=0;i<n;i++){
		printf("Enter the DOB of Student %d: ",i+1);
		scanf("%d %s %d",&((pstu+i)->pdob->day),temp,&((pstu+i)->pdob->year));
		(pstu+i)->pdob->month = (char *) calloc(strlen(temp)+1,sizeof(char));
		strcpy((pstu+i)->pdob->month,temp);
		// printf("Enter the Student Info of Student %d (Reg_no,Name,Address): ",i+1);
		// scanf("%d %s %s",&(pstu->pstuinfo+i)->reg_no,dn,(pstu->pstuinfo+i)->address);
		// (pstu->pstuinfo+i)->name = (char *) calloc(strlen(dn)+1,sizeof(char));
		// strcpy((pstu->pstuinfo+i)->name,dn);
		// printf("Enter the College Info of Student %d (College Name, University Name): ",i+1);
		// scanf("%s %s",dc,(pstu->pcollege+i)->university_name);
		// (pstu->pcollege+i)->college_name = (char *) calloc(strlen(dc)+1,sizeof(char));
		// strcpy((pstu->pcollege+i)->college_name,dc);
		// printf("\n");
	}

	for(i=0;i<n;i++){
		printf("The DOB of Student %d is: %d/%s/%d\n",i+1,(pstu+i)->pdob->day,(pstu+i)->pdob->month,(pstu+i)->pdob->year);
		// printf("The info of Student %d is: %d : %s : %s\n",i+1,(pstu->pstuinfo+i)->reg_no,(pstu->pstuinfo+i)->name,(pstu->pstuinfo+i)->address);
		// printf("The college of Student %d is: %s, %s\n",i+1,(pstu->pcollege+i)->college_name,(pstu->pcollege+i)->university_name);	
		}

}
		
	// }
// 	printf("Enter the DOB of Student %d: ",1);
// 	scanf("%d",&(pstu->pdob)->day);
// 	printf("%d",pstu->pdob->day);
// }