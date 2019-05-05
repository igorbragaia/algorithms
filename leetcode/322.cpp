#define INF 1<<30

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int ans;
      vector<int>dp(amount+1,INF);
      dp[0]=0;
      for(int i=1;i<=amount;i++){
        ans = INF;
        for(int coin:coins)
          if(i-coin>=0 and dp[i-coin]!=INF)
            ans=min(ans,1+dp[i-coin]);
        dp[i]=ans;
      }

      if(dp[amount]==INF)
          return -1;
      else
          return dp[amount];
    }
};

// // top-down dp
//
// recursion:
//     rec(amount):
//         if(amount <= 0)
//             return 0
//         else
//             ans=inf
//             for(coin in coins):
//                 ans=min(ans,amount-coin)
//             return ans
//
// // bottom-up dp
//
// for(i in range(amount+1)):
//     ans=inf
//     for(coin in coins):
//         if i-coin:
//             ans=min(ans,dp[i-coin])
//     dp[i]=ans
