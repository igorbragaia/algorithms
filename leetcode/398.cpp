class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<(int)nums.size();i++){
            if(nums_map.find(nums[i]) == nums_map.end()){
                nums_map[nums[i]] = {};
                idx_map[nums[i]] = 0;                
            }
            nums_map[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int response = nums_map[target][idx_map[target]];
        idx_map[target] = (idx_map[target]+1)%((int)nums_map[target].size());
        return response;
    }
private:
    map<int,vector<int>>nums_map;
    map<int,int>idx_map;   
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */