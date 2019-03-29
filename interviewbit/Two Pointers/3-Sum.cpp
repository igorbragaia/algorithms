#define INF 1e10

int Solution::threeSumClosest(vector<int> &A, int B) {
  sort(A.begin(), A.end());
  int i,j, size=(int)A.size();
  long long int minDiff=INF, newDiff, response;
  for(int k=0;k<size;k++){
    i=0; j=size-1;
    while(i<j){

        if(i==k) i++;
        if(j==k) j--;
        newDiff = (long long int)abs(B-(A[i]+A[j]+A[k]));
        if( newDiff < minDiff ){
          minDiff = newDiff;
          response = A[i]+A[j]+A[k];
        }

        if(A[i]+A[j]+A[k] == B) break;
        else if(A[i]+A[j]+A[k] < B) i++;
        else j--;
    }
  }
  return (int)response;
}
