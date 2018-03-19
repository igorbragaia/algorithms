class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int response = 0;
        for(int i = 0; i < nums.size(); i++)
            response ^= nums[i];
        return response;
    }
};
