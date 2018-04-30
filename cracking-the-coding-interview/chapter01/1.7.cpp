#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

int main(){
  int matrix[10][10];
  for(int i = 0; i < 10; i++){
    for(int j =0; j < 10; j++){
      matrix[i][j] = 12;
    }
  }

  matrix[4][3] = 0;
  matrix[2][7] = 0;

  set<int> rows, columns;

  for(int i = 0; i < 10; i++){
    for(int j =0; j < 10; j++){
      if(matrix[i][j] == 0){
        rows.insert(i);
        columns.insert(j);
      }
    }
  }

  for(int i = 0; i < 10; i++){
    for(int j =0; j < 10; j++){
      if(rows.find(i) != rows.end() or columns.find(j) != columns.end()){
        matrix[i][j] = 0;
      }
    }
  }

  for(int i = 0; i < 10; i++){
    for(int j =0; j < 10; j++){
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
