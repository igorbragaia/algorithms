#include<bits/stdc++.h>
#include<tuple>
using namespace std;

vector<vector<long double> > multiplyMatrices(vector<vector<long double> >A,vector<vector<long double> >B){
  vector<vector<long double> >response;
  assert(A[0].size() == B.size());

  long double sum;
  vector<long double>tmp;
  for(int rowA=0;rowA<(int)A.size();rowA++){
    tmp=vector<long double>();
    for(int colB=0; colB<(int)B[0].size();colB++){
      sum=0;
      for(int k=0;k<(int)A[0].size();k++)
        sum += A[rowA][k]*B[k][colB];
      tmp.push_back(sum);
    }
    response.push_back(tmp);
  }
  return response;
}

vector<vector<long double> > reorderMatrix(vector<vector<long double> >A, vector<int>idxs){
  vector<vector<long double> >AA;
  for(int i=0;i<(int)A.size();i++)
    AA.push_back(A[idxs[i]]);
  return AA;
}

void printMatrix(vector<vector<long double> >eqs){
  cout << "Printing matrix..." << endl;
  long double i,j;
  for(i=0;i<(int)eqs.size();i++){
    for(j=0;j<(int)eqs[i].size();j++)
      if(eqs[i][j]>=0)  printf("%-3.4Lf ", eqs[i][j]); else   printf("%-3.3Lf ", eqs[i][j]);
    printf("\n");
  }
  cout << endl;
}

tuple< vector<vector<long double>>, vector<vector<long double>>, vector<vector<long double>>, vector<int> > LRU_decomposition_with_partial_pivoting(vector<vector<long double> >originalA){
  vector<vector<long double> > A=originalA;
  vector<vector<long double> > L(A.size(),vector<long double>(A.size(),0)),
                               U(A.size(),vector<long double>(A.size(),0)),
                               basis(A.size(),vector<long double>(A.size(),0));
  vector<int>idxs(A.size(),0);

  for(int i=0;i<(int)A.size();i++)
    for(int j=0;j<(int)A.size();j++){
      if(i!=j){
        L[i][j]=0; U[i][j]=0;
      } else {
        L[i][j]=1; U[i][j]=1;
      }
    }

  vector<bool>gotcha(A.size(),false);
  long double pivot,m;
  int iteration=0,idx,idxU;
  while(iteration < (int)A.size()){
    pivot=-1;
    for(int i=0;i<(int)A.size();i++)
      if(!gotcha[i] and abs(A[i][iteration])>pivot){
        pivot=abs(A[i][iteration]);
        idx=i;
      }
    gotcha[idx]=true;
    idxs[idx]=iteration;
    basis[iteration][idx]=1.0;

    for(int i=0;i<(int)A.size();i++)
      U[iteration][i]=A[idx][i];

    idxU=(int)A.size()-1;
    for(int i=(int)A.size()-1;i>=0;i--){
      if(!gotcha[i]){
        m=A[i][iteration]/A[idx][iteration];
        L[idxU][iteration]=m;
        for(int j=0;j<(int)A.size();j++)
          A[i][j]-=m*A[idx][j];
        idxU--;
      }
    }
    iteration++;
  }
  // printf("L\n");
  // printMatrix(L);
  // printf("U\n");
  // printMatrix(U);
  // printf("L*U, reodered\n");
  // printMatrix(multiplyMatrices(basis, multiplyMatrices(L,U)));
  // printf("A\n");
  // printMatrix(originalA);
  // printMatrix(reorderMatrix(multiplyMatrices(L,U), idxs));
  // assert(originalA == reorderMatrix(multiplyMatrices(L,U), idxs));
  return make_tuple(L,U,basis,idxs);
}

vector<vector<long double>> directSubstitution(vector<vector<long double>> A,vector<vector<long double>>b){
  assert(A.size()==b.size());
  vector<vector<long double>>eqs=A;
  for(int i=0;i<(int)b.size();i++){
    eqs[i].push_back(b[i][0]);
  }

  vector<long double>response((int)eqs.size());
  int i,j;
  long double sum;
  for(i=(int)eqs.size()-1;i>=0;i--){
    sum = eqs[i][(int)eqs[i].size()-1];
    for(j=i+1;j<(int)eqs.size();j++)
      sum -= eqs[i][j]*response[j];
    response[i] = sum/eqs[i][i];
  }

  vector<vector<long double>>x;
  for(int i=0;i<(int)response.size();i++)
    x.push_back(vector<long double>{response[i]});
  return x;
}

vector<vector<long double>> inverseSubstitution(vector<vector<long double>> A,vector<vector<long double>>b){
  assert(A.size()==b.size());
  vector<vector<long double>>eqs=A;
  for(int i=0;i<(int)b.size();i++){
    eqs[i].push_back(b[i][0]);
  }

  vector<long double>response((int)eqs.size());
  int i,j;
  long double sum;
  for(i=0;i<(int)eqs.size();i++){
    sum = eqs[i][(int)eqs[i].size()-1];
    for(j=i-1;j>=0;j--)
      sum -= eqs[i][j]*response[j];
    response[i] = sum/eqs[i][i];
  }

  vector<vector<long double>>x;
  for(int i=0;i<(int)response.size();i++)
    x.push_back(vector<long double>{response[i]});
  return x;
}

vector<vector<long double>> solveLULinearSystem(vector<vector<long double>>L, vector<vector<long double>>U, vector<vector<long double>>basis,vector<vector<long double>>b){
  vector<vector<long double>>x,y,Pb=multiplyMatrices(basis,b);
  y=inverseSubstitution(L,Pb);
  printf("y\n");
  printMatrix(y);
  x=directSubstitution(U,y);
  printf("x\n");
  printMatrix(x);
  return x;
}

vector<vector<long double>>solveLinearSystem(vector<vector<long double> >A,vector<vector<long double> >b){
  vector<vector<long double> >L,U,basis;
  vector<int>idxs;
  auto tmp=LRU_decomposition_with_partial_pivoting(A);
  L=get<0>(tmp);
  U=get<1>(tmp);
  basis=get<2>(tmp);
  idxs=get<3>(tmp);

  printf("A\n");
  printMatrix(A);
  printf("L\n");
  printMatrix(L);
  printf("U\n");
  printMatrix(U);
  printf("L*U\n");
  printMatrix(multiplyMatrices(L,U));
  printf("A=L*U, reordered\n");
  printMatrix(reorderMatrix(multiplyMatrices(L,U), idxs));
  vector<vector<long double> > x=solveLULinearSystem(L,U,basis,b);
  // assert(multiplyMatrices(A,x) == b);
  return x;
}

tuple<vector<vector<long double> >,vector<vector<long double> >>createInput(int n){
  vector<vector<long double> >A,b;
  vector<long double>tmp;
  for(int i=1;i<=n;i++){
    b.push_back(vector<long double>{(long double)1.0});
    tmp=vector<long double>();
    for(int j=1;j<=n;j++)
      tmp.push_back((long double)(1.0/(i+j-1)));
    A.push_back(tmp);
  }
  return make_tuple(A,b);
}

int main(){
  vector<int>ns{5/*10,20,30*/};
  for(int n:ns){
    printf("/*****************************/\n");
    printf("N=%d\n",n);
    auto input=createInput(n);
    vector<vector<long double> >A=get<0>(input),b=get<1>(input);
    vector<vector<long double>>x=solveLinearSystem(A,b);
    printf("PRINTING RESULTS: Ax=b\n");
    printf("A\n");
    printMatrix(A);
    printf("x\n");
    printMatrix(x);
    printf("A*x\n");
    printMatrix(multiplyMatrices(A,x));
    printf("b\n");
    printMatrix(b);
    printf("/*****************************/\n");
  }

  // vector<vector<long double> >A{vector<long double>{3,-4,1},vector<long double>{1,2,2},vector<long double>{4,0,-3}}, b{vector<long double>{9},vector<long double>{3},vector<long double>{-2}};
  // vector<vector<long double>>x=solveLinearSystem(A,b);
  return 0;
}
