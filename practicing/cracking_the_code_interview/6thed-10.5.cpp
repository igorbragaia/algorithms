#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<string> strs, string str) {
      int i = 0, f = strs.size() - 1, m, left, right;
      while(i <= f){
        m = (i + f)/2;
        if(strs[m] == ""){
          left = m - 1;
          right = m + 1;
          while(left >= i or right <= f){
            if(left >= i and strs[left] != ""){
              m = left;
              break;
            }
            if(right <= f and strs[right] != ""){
              m = right;
              break;
            }
            left--;
            right++;
          }
        }
        if(strs[m] == str)
          return m;
        if(strs[m] < str)
          i = m + 1;
        else
          f = m - 1;
      }
      return -1;
    }
};

int main(){
  vector<string> strs = {"at", "", "", "", "ball", "", "", "cat", "", "", "dad", ""};
  cout << Solution().search(strs, "x") << endl;
  return 0;
}
