#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  void mergeArrays(vector<int>&a, vector<int>&b){
    int i = a.size() - b.size() - 1, k = a.size() - 1, j = b.size() - 1;
    while(k >= 0){
      if(i >= 0 && j >= 0){
        if(a[i] > b[j])
          a[k] = a[i--];
        else
          a[k] = b[j--];
      } else if(i >= 0)
        a[k] = a[i--];
      else
        a[k] = b[j--];
      k--;
    }
  }
};

int main(){
  Solution solution;
  vector<int> a = {1,3,5,7}, b = {-1,4,8}, merged;
  a.resize(a.size() + b.size());
  solution.mergeArrays(a,b);
  for(auto el:a){
    printf("%d ",el);
  }
  printf("\n");


  a = {1,3,5,7}, b = {-1,-2,-3}, merged;
  a.resize(a.size() + b.size());
  solution.mergeArrays(a,b);
  for(auto el:a){
    printf("%d ",el);
  }
  printf("\n");

  a = {1,3,5,7}, b = {-1,8,9}, merged;
  a.resize(a.size() + b.size());
  solution.mergeArrays(a,b);
  for(auto el:a){
    printf("%d ",el);
  }
  printf("\n");

  a = {1,3,5,7}, b = {8,9, 10}, merged;
  a.resize(a.size() + b.size());
  solution.mergeArrays(a,b);
  for(auto el:a){
    printf("%d ",el);
  }
  printf("\n");
  return 0;
}
