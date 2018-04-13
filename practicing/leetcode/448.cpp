class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++)
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                answer.push_back(i + 1);
            else
                nums[i] *= -1;
        return answer;
    }
};