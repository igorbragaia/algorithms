#include<stdio.h>
using namespace std;

int main(){
  int matrix[10][10];

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      matrix[i][j] = i;
    }
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
