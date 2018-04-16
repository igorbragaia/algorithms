class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if((int)nums.size() != 0){
            int total = 0, current = 0;
            for(int i = 0; i < (int) nums.size(); i++)
                total += nums[i];
            for(int i = 0; i < (int) nums.size(); i++){
                if(current == total - nums[i] - current)
                    return i;
                current += nums[i]; 
            }
        }  
        return -1;
    }
};