vector<int> Solution::maxset(vector<int> &A) {
  long long int tmpsum = 0, anssum=-1;
  vector<int> tmp, ans;
  for(int el:A){
    if(el < 0){
      if(tmp.size() > 0){
        if(tmpsum > anssum){
          anssum = tmpsum;
          ans = tmp;
        }
        tmpsum = 0;
        tmp.clear();
      }
    } else {
      tmp.push_back(el);
      tmpsum += (long long int) el;
    }
  }
  if(tmpsum > anssum){
    anssum = tmpsum;
    ans = tmp;
  }
  return ans;
}
