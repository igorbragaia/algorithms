class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        DP = vector<int>(arr.size(),-2);
        return dp(arr, start);
    }
private:
    vector<int>DP;
    
    int dp(vector<int>&arr, int i){
      if(i<0 or i>=(int)arr.size())
        return 0;

      if(DP[i] == -1)
        return 0;

      if(DP[i] != -1 and DP[i] != -2)
        return DP[i];

      DP[i] = -1;

      return DP[i] = (arr[i] == 0) ? 1 : max(dp(arr, i-arr[i]), dp(arr, i+arr[i]));
    }
};