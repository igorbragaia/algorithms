class Solution {
private:
    int S;
    map<pair<int,int>, int>dp;
    
    int solve(int sum, int i, vector<int>& nums,int&S){
        if(i == (int)nums.size()){
            if(sum==S)
                return 1;
            else
                return 0;
        }
        
        if(dp.find({sum,i}) == dp.end())
            dp[{sum,i}] = solve(sum+nums[i],i+1,nums,S)+solve(sum-nums[i],i+1,nums,S);
        
        return dp[{sum,i}];        
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if((int)nums.size()==0)
            return 0;

        solve(0,0,nums,S);
        
        return dp[{0,0}];
    }
};