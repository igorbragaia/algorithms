class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<vector<int>> v;
        for(unsigned int i=0;i<nums.size();i++)
            v.push_back(vector<int>{nums[i],i});
        sort(v.begin(), v.end());
        for(unsigned int i=1;i<nums.size();i++){
            if(v[i][0] == v[i-1][0] and (v[i][1]-v[i-1][1]) <= k)
                return true;            
        }
        return false;
        // Time: O(nlogn), Memory: O(n)
    }
};