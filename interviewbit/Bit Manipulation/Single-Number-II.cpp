int Solution::singleNumber(const vector<int> &A) {
  vector<int>bits(33,0);
  for(int elm:A)
    for(int i=0;i<32;i++)
      bits[i] += (elm>>i)&1;
  int ans=0;
  for(int i=0;i<32;i++)
    if(bits[i]%3 != 0)
      ans |= (1<<i);
  return ans;
}
