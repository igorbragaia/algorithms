//++ -std=c++11 linear-systems-solver.cpp -o linear-systems-solver.exe && ./linear-systems-solver.exe > log.txt
#include<stdio.h>
#include<vector>
using namespace std;

void printEqs(vector<vector<float>>eqs){
  int i,j;
  for(i=0;i<(int)eqs.size();i++){
    for(j=0;j<(int)eqs[i].size();j++)
      if(eqs[i][j]>=0)  printf("%-3.2f ", eqs[i][j]); else   printf("%-3.1f ", eqs[i][j]);
    printf("\n");
  }
}

vector<vector<float>> gaussianElimination(vector<vector<float>> eqs){
  printf("\nGaussian Elimination:\n");
  printf("log:\n");
  printEqs(eqs);
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
  printf("log:\n");
  printEqs(eqs);
  return eqs;
}

vector<vector<float>> LUdecomposition(vector<vector<float>> eqs){
  vector<vector<float>>Ieqs;
  vector<float>aux;
  for(int i=0;i<(int)eqs.size();i++){
    aux = vector<float>();
    for(int elm:eqs[i]) aux.push_back(elm);
    for(int j=0;j<(int)eqs.size();j++)
      if(i!=j) aux.push_back(0); else aux.push_back(1);
    Ieqs.push_back(aux);
  }
  printf("[A I] matrix that will become [U L]\n");
  printEqs(Ieqs);
  printf("decomposing...\n");
  int i,j,k,m;
  for(i=0;i<(int)Ieqs.size()-1;i++){
    printf("log:\n");
    printEqs(Ieqs);
    for(j=i+1;j<(int)Ieqs.size();j++){
      m = Ieqs[j][i]/Ieqs[i][i];

      for(k=0;k<(int)Ieqs.size();k++)
        Ieqs[j][k] -= Ieqs[i][k]*m;
      Ieqs[j][i+(int)Ieqs.size()] += m;
    }
  }
  printf("log:\n");
  printEqs(Ieqs);
  return Ieqs;
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

vector<float> inverseSubstitution(vector<vector<float>> eqs){
  vector<float>response((int)eqs.size());
  int i,j,sum;
  for(i=0;i<(int)eqs.size();i++){
    sum = eqs[i][(int)eqs[i].size()-1];
    for(j=i-1;j>=0;j--)
      sum -= eqs[i][j]*response[j];
    response[i] = sum/eqs[i][i];
  }
  return response;
}

int main(){
  vector< vector<float> >eqs, gaussian, LU;
  vector<float> eqs_result{-3,3,-1,-16};
  eqs.push_back(vector<float>{2,4,2,3});
  eqs.push_back(vector<float>{-2,-5,-3,-2});
  eqs.push_back(vector<float>{4,7,6,8});
  eqs.push_back(vector<float>{6,10,1,12});

  printf("GAUSSIAN ELIMINATTION\n");
  gaussian=eqs;
  for(int i=0;i<(int)eqs_result.size();i++) gaussian[i].push_back(eqs_result[i]);
  printf("Ax=b\n");
  printEqs(gaussian);
  gaussian = gaussianElimination(gaussian);
  vector<float>response = directSubstitution(gaussian);
  printf("\nPrinting direct substitution response\n");
  for(float i:response)
    printf("%.2f\n", i);

  printf("\nLU DECOMPOSITION\n");
  vector< vector<float> >auxiliar_eqs;
  vector<float>aux;

  LU = LUdecomposition(eqs);
  vector<vector<float>>L, U, Ly, Ux;
  for(int i=0;i<LU.size();i++){
    aux = vector<float>();
    for(int j=0;j<LU.size();j++)
      aux.push_back(LU[i][j]);
    U.push_back(aux);
    aux=vector<float>();
    for(int j=0;j<LU.size();j++)
      aux.push_back(LU[i][j+LU.size()]);
    L.push_back(aux);
  }

  printf("\nL matrix:\n");
  printEqs(L);
  printf("\nU matrix:\n");
  printEqs(U);

  Ly=L;
  for(int i=0;i<(int)eqs_result.size();i++) Ly[i].push_back(eqs_result[i]);
  printf("\nLy=b matrix:\n");
  printEqs(Ly);
  vector<float>y = inverseSubstitution(Ly);
  printf("\nPrinting response = y\n");
  for(float i:y)
    printf("%.2f\n", i);

  Ux=U;
  for(int i=0;i<(int)eqs_result.size();i++) Ux[i].push_back(y[i]);
  printf("\nUx=y matrix:\n");
  printEqs(Ux);
  response = directSubstitution(Ux);
  printf("\nPrinting response = x\n");
  for(float i:response)
    printf("%.2f\n", i);
  return 0;
}
