#define INF 1e10

vector<vector<int> > Solution::threeSum(vector<int> &A) {
  vector<vector<int>>response;
  if((int)A.size()==0)return response;
  set<vector<int>>setresponse;
  vector<int>tmp;

  sort(A.begin(), A.end());
  int i,j, size=(int)A.size();
  long long int sum;
  for(int k=0;k<size;k++){
    i=k+1; j=size-1;
    while(i<j){
        if(i==k) i++;
        else if(j==k) j--;
        else {
          sum = (long long int)A[i]+A[j]+A[k];

          tmp = vector<int>{A[i],A[j],A[k]};
          sort(tmp.begin(), tmp.end());
          if(sum == 0) setresponse.insert(tmp);

          if(A[i]+A[j]+A[k] < 0) i++;
          else j--;
        }
    }
  }
  for(set<vector<int>>::iterator it=setresponse.begin();it!=setresponse.end();it++)
    response.push_back(*it);

  return response;
}
