class Solution {
public:
    int nextGreaterElement(int n) {
        string ans = "";
        while(n){
          ans += '0' + (n%10);
          n /= 10;
        }
        int i = 1;
        while(i < (int)ans.size() and ans[i] > ans[i - 1])
          i++;
        if(i == (int)ans.size())
          return -1;

        char bound = ans[i];
        
        sort(ans.begin(), ans.begin() + i + 1);
        
        for(j = 0; j <= i; j++)
          if(ans[j] == bound)
            break;
    }
};