// g++ -std=c++11 linear-systems-solver.cpp -o linear-systems-solver.exe && ./linear-systems-solver.exe
#include<stdio.h>
#include<vector>
using namespace std;

void printEqs(vector<vector<float>>eqs){
  int i,j;
  for(i=0;i<(int)eqs.size();i++){
    for(j=0;j<(int)eqs[i].size();j++)
      if(eqs[i][j]>=0)  printf("%3.2f ", eqs[i][j]); else   printf("%3.1f ", eqs[i][j]);
    printf("\n");
  }
}

vector<vector<float>> gaussian_elimination(vector<vector<float>> eqs){
  printf("\nGaussian Elimination:\n");
  int i,j,k,m;
  for(i=0;i<(int)eqs.size()-1;i++){
    printf("log:\n");
    printEqs(eqs);
    for(j=i+1;j<(int)eqs.size();j++){
      m = eqs[j][i]/eqs[i][i];
      for(k=0;k<(int)eqs[i].size();k++)
      eqs[j][k] -= eqs[i][k]*m;
    }
  }
  return eqs;
}

vector<float> directSubstitution(vector<vector<float>> eqs){
  vector<float>response((int)eqs.size());
  int i,j,sum;
  for(i=(int)eqs.size()-1;i>=0;i--){
    sum = eqs[i][(int)eqs[i].size()-1];
    for(j=i+1;j<(int)eqs.size();j++)
      sum -= eqs[i][j]*response[j];
    response[i] = sum/eqs[i][i];
  }
  return response;
}

int main(){
  vector< vector<float> >eqs;
  eqs.push_back(vector<float>{2,4,2,3,-3});
  eqs.push_back(vector<float>{-2,-5,-3,-2,3});
  eqs.push_back(vector<float>{4,7,6,8,-1});
  eqs.push_back(vector<float>{6,10,1,12,-16});

  printf("Initial equations system\n");
  printEqs(eqs);
  eqs = gaussian_elimination(eqs);
  vector<float>response = directSubstitution(eqs);
  printf("\nPrinting response\n");
  for(float i:response)
    printf("%.2f\n", i);
  return 0;
}
