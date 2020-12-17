class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--)
                if(i==n-1 and j==m-1)
                    dp[n-1][m-1]=1;
                else                    
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
        return dp[0][0];        
    }
};