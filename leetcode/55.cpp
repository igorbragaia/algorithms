class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = (int)nums.size()-1;
        for(int i=curr;i>=0;i--){
            if(i+nums[i]>=curr) curr=i;
        }
        return curr==0;
    }
};