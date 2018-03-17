#include<stdlib.h>
#include<stdio.h>


// note that any rotation in a layer doens't affect another layer rotation
void rotate (int ** matrix, int n){
  int top;
  for(int i = 0; i < n / 2; i++){
    for(int j = i; j < n - i - 1; j++){
      top = matrix[i][j];

      matrix[i][j] = matrix[n - 1 - j][i];
      matrix[n - 1  - j][i] = matrix[n - 1  - i][n - 1  - j];
      matrix[n - 1  - i][n - 1  - j] = matrix[j][n - 1  - i];
      matrix[j][n - 1  - i] = top;
    }
  }
}


int main(){
  int n = 10;
  int ** matrix = (int **) malloc (n * sizeof(int *));
  for(int i = 0; i < n; i++){
    matrix[i] = (int *) malloc (n * sizeof(int));
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matrix[i][j] = i;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\nrotating:\n\n");

  rotate(matrix, n);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }

  for(int i = 0; i < n; i++){
    int * line = matrix[i];
    free(line);
  }
  free(matrix);

  return 0;
}
