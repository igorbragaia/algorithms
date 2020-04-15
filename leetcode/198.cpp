class Solution {
public:
    int rob(vector<int>& nums) {
        int curr, next=0, nextnext=0, ans=0;
        for(int i=(int)nums.size()-1;i>=0;i--){
            curr = max(nums[i]+nextnext, next);
            ans = max(ans, curr);
            nextnext = next;
            next = curr;
        }
        return ans;
    }
};

/*
    dp[i] = max(nums[i]+dp[i+1], dp[i+2])
*/