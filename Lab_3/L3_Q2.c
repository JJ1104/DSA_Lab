#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	char name[20];
	int rollno;
	float cgpa;
}Student;

void sortrollno(Student *ptr,int n){
	int i,j;
    Student t;
    for (i = 0; i < n; i++) {
 
        for (j = i + 1; j < n; j++) {
 
            if ((ptr + j)->rollno < (ptr + i)->rollno) {
 
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}


int main(){
	
	int n,i;
    Student *ptr;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	Student Sarr[n];
    // Memory allocation 
  ptr = (Student *)malloc(n * sizeof(Student));
  for (int i = 0; i < n; ++i) {
    printf("Enter name,roll no. and cgpa:\n");
    scanf("%s %d %f", (ptr+i)->name, &(ptr + i)->rollno ,&(ptr+i)->cgpa);
  }
  printf("Displaying Information:\n");
  for (int i = 0; i < n; ++i) {
    printf("%s\t%d\t%f", (ptr + i)->name, (ptr + i)->rollno,(ptr+i)->cgpa);
    printf("\n");
  }

	printf("Name of Student 1 is %s\n",ptr->name);
	printf("Rollno of Student 1 is %d\n",ptr->rollno);
	printf("CGPA of Student 1 is %.1f\n",ptr->cgpa);

	sortrollno(ptr,n);
	printf("\nAfter Sorting:\n");
	for(i=0;i<n;i++){
		printf("Name of Student %d is %s\n",i+1,(ptr+i)->name);
		printf("Rollno of Student %d is %d\n",i+1,(ptr+i)->rollno);
		printf("CGPA of Student %d is %.1f\n",i+1,(ptr+i)->cgpa);
		printf("\n");
	}
	return 0;

}