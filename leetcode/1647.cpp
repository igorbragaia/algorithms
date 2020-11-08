class Solution {
public:
    int minDeletions(string s) {
        map<int,int>hash;
        for(char c:s){
            if(hash.find(c) == hash.end())
                hash[c]=0;
            hash[c]++;
        }
        vector<int>nums;
        for(auto &kv:hash)
            nums.push_back(kv.second);
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int j=(int)nums.size()-2;j>=0;j--){
            if(nums[j] >= nums[j+1]){
                int gap = nums[j]-nums[j+1];
                if(nums[j+1]!=0) gap++;
                ans += gap;
                nums[j] -= gap;
            }
        }
        
        return ans;
    }
};
