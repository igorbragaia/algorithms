class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int response = 0;
        for(int i = 0; i < nums.size(); i++){
            response ^= nums[i];
            response ^= i;
        }
        response ^= nums.size();
        return response;
    }
};
