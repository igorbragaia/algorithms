int pd(vector<int>&num, int idx, int missing, vector<int>&A, bool skipZero){
  if(missing == 0)
    return 0;

  bool exists=false;
  int count = 0;
  for(int elm:A)
    if(elm < num[idx] and !(elm == 0 and skipZero))
      count++;
    else if(elm == num[idx])
      exists = true;

  int response = count*pow((int)A.size(),missing-1);
  if(exists)
    response += pd(num, idx+1, missing-1, A, false);
  return response;
}

int Solution::solve(vector<int> &A, int B, int C) {
  string numStr=to_string(C);
  vector<int>num;
  for(int i=0;i<(int)numStr.size();i++)
    num.push_back(numStr[i]-'0');

  if((int)A.size() == 0 or B > (int)num.size())
    return 0;
  else if(B < (int)num.size()){
    int hasZero=0;
    for(int elm:A) if(elm==0) hasZero=1;
    return ((int)A.size()-hasZero)*pow((int)A.size(), B-1);
  }
  else return pd(num, 0, B, A, B > 1);
}
