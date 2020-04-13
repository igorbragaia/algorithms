class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        
        map<int,int> counts;
        counts[0] = -1;
        int count=0, ans=0;
        for(int i=0;i<(int)nums.size();i++){
            count += nums[i]==1?1:-1;
            
            if(counts.find(count) != counts.end())
                ans = max(ans, i - counts[count]);
            else
                counts[count] = i;
        }
        return ans;
    }
};