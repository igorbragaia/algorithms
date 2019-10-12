class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0, sum=0;
        map<int,int>hash;
        hash[0]=1;

        for(int i=0;i<(int)nums.size();i++){
            sum += nums[i];
            
            if(hash.find(sum-k)!=hash.end())
                res += hash[sum-k];            

            if(hash.find(sum) == hash.end())
                hash[sum]=1;
            else
                hash[sum]++;
        }
        return res;
    }
};