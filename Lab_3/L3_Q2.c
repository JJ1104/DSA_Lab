#include<stdio.h>

typedef struct Student
{
	char name[20];
	int rollno;
	float cgpa;
}Student;

void sortrollno(Student Sarr[],int n){
	int i,j;
	Student temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(Sarr[j].rollno>Sarr[j+1].rollno){
				temp = Sarr[j+1];
				Sarr[j+1] = Sarr[j];
				Sarr[j] = temp;
			}
		}
	}
}


int main(){
	
	int n,i;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	Student Sarr[n];
	for(i=0;i<n;i++){
		printf("Enter the name of Student %d: ",i+1);
		scanf("%s",Sarr[i].name);
		printf("Enter the Rollno of Student %d: ",i+1);
		scanf("%d",&Sarr[i].rollno);
		printf("Enter the CGPA of Student %d: ",i+1);
		scanf("%f",&Sarr[i].cgpa);
		printf("\n");
	}
	//Displaying one student object
	printf("Name of Student 1 is %s\n",Sarr[0].name);
	printf("Rollno of Student 1 is %d\n",Sarr[0].rollno);
	printf("CGPA of Student 1 is %.1f\n",Sarr[0].cgpa);

	sortrollno(Sarr,n);
	printf("\nAfter Sorting:\n");
	for(i=0;i<n;i++){
		printf("Name of Student %d is %s\n",i+1,Sarr[i].name);
		printf("Rollno of Student %d is %d\n",i+1,Sarr[i].rollno);
		printf("CGPA of Student %d is %.1f\n",i+1,Sarr[i].cgpa);
		printf("\n");
	}
	return 0;

}