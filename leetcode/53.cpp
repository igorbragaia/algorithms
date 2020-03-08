class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], prev = nums[0];
        for(unsigned int i=1; i<nums.size(); i++){
            prev = max(nums[i], nums[i] + prev);
            ans = max(ans, prev);
        }
        return ans;
    }
};