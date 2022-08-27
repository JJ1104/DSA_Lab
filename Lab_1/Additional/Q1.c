#include<stdio.h>

int main(){
	int m,n,i,j,choice;
	printf("Enter the number of candidates:\n");
	scanf("%d",&m);
	printf("Enter the number of voters:\n");
	scanf("%d",&n);
	int candidates[m][1];
	for(i=0;i<m;i++){
		candidates[i][1] = 0;
	}
	char names[m][100];
	for(i=0;i<m;i++){
		printf("Enter the name of Candidate %d: ",i+1);
		scanf("%s",names[i]);
	}
	printf("Starting voting:\n");
	printf("Total number of voters:%d\n",n);
	for(i=0;i<n;i++){
		printf("Enter your choice:\n");
		for(j=0;j<m;j++){
			printf("%d.%s ",j+1,names[j]);
		}
		scanf("%d",&choice);
		candidates[choice-1][1]++; 
	}
	printf("Thanks for voting\n");
	printf("Results:\n");
	for(i=0;i<m;i++){
		printf("%s, Votes Secured:%d\n",names[i],candidates[i][1]);
	}
	return 0;
}