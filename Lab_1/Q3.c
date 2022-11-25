#include<stdio.h>

void read(int matrix[][10], int row, int column) {

   int i, j;
   for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
}

void multiplyMatrices(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2) {

   int i, j; 
   for (i = 0; i < r1; i++) {
      for (j = 0; j < c2; j++) {
            result[i][j] = 0;
      }
   }

   for (i = 0; i < r1; ++i) {
      for (j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

void display(int matrix[][10],int row,int column){
   int i, j;
   for (i = 0; i < row; i++) {
      for (j = 0; j < column; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
}

int main() {
   
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2, i, j;
   printf("Enter rows and columns for the first matrix:\n");
   scanf("%d %d", &r1, &c1);
   printf("Enter rows and columns for the second matrix:\n");
   scanf("%d %d", &r2, &c2);

   while (c1 != r2) {
      printf("Error! Enter rows and columns again.\n");
      printf("Enter rows and columns for the first matrix:\n");
      scanf("%d %d", &r1, &c1);
      printf("Enter rows and columns for the second matrix:\n");
      scanf("%d %d", &r2, &c2);
   }

   printf("Enter the first matrix elements:\n"); 
   read(first, r1, c1);
   
   printf("Enter the second matrix elements:\n"); 
   read(second, r2, c2);
   
   multiplyMatrices(first, second, result, r1, c1, r2, c2);

   printf("First Matrix:\n");
   display(first,r1,c1);
   printf("\n");
   printf("Second Matrix:\n");
   display(second,r2,c2);
   printf("\n");
   
   printf("After multiplying the matrices, the resulting product matrix is:\n");
   display(result,r1,c2);

   return 0;
}