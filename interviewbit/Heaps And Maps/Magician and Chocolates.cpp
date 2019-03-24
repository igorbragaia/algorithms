int Solution::nchoc(int A, vector<int> &B) {
  priority_queue<int>pq;
  for(int b:B) pq.push(b);
  int top;
  long long int sum=0;
  while(A--){
    top = pq.top();
    pq.pop();
    sum=(sum+top)%(int(1e9+7));
    pq.push(int(floor(top/2)));
  }
  return int(sum);
}
