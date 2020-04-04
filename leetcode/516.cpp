class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = (int)s.size();
        DP = vector<vector<int>>(n, vector<int>(n, -1));
        return dp(s, 0, n-1);
    }
private:
    vector<vector<int>>DP;

    int dp(string & s, int i, int j){
      if(DP[i][j] != -1)
          return DP[i][j];

      int response;
      if(i>j)
        response = 0;
      else if(i==j)
        response = 1;
      else if(s[i] == s[j])
        response = 2 + dp(s, i+1, j-1);
      else
        response = max(dp(s, i+1, j), dp(s, i, j-1));

      DP[i][j] = response;
      return response;
    }
};