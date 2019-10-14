typedef long long int lli;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool res=false;
        map<int,int>hash;
        int sum=0;
        hash[0]=-1;
        for(int i=0;i<(int)nums.size() and !res;i++){
            sum = mod((lli)sum, (lli)nums[i], (lli)k);
            if(hash.find(sum) == hash.end())
                hash[sum]=i;
            if(i-hash[sum]>1)
                res=true;
        }
        return res;        
    }
private:
    lli mod(lli sum, lli num, lli k){
        if(k == 0)
            return sum+num;
        else
            return (k+sum+(num%k))%k;
    }
};