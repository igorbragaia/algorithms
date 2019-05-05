int Solution::lis(const vector<int> &A) {
  int size=(int)A.size();
  vector<int>sorted=A;
  sort(sorted.begin(),sorted.end());
  vector<int>current(size+1,0),below(size+1,0);
  for(int i=size-1;i>=0;i--){
    for(int j=size-1;j>=0;j--){
      if((j==0 or sorted[j]!=sorted[j-1]) and A[i]==sorted[j])
        current[j]=1+below[j+1];
      else
        current[j]=max(current[j+1],below[j]);
    }
    below=current;
    current=vector<int>(size+1,0);
  }
  return below[0];
}
