class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxn=nums[0];
        bool has_positive=false;
        for(int n:nums){
            maxn=max(maxn,n);
            if(n>0)
                has_positive=true;            
        }
        if(!has_positive)
            return maxn;
        
        // case i: one part
        int sum=0, minsum=0,maxsubarr=0;
        for(int i=0;i<(int)nums.size();i++){
            sum+=nums[i];
            maxsubarr=max(maxsubarr,sum-minsum);
            minsum=min(minsum,sum);
        }
        int casei=maxsubarr;
        
        // case ii: two parts
        sum=0;
        int maxsum=0, minsubarr=0;
        for(int i=0;i<(int)nums.size();i++){
            sum+=nums[i];
            minsubarr=min(minsubarr,sum-maxsum);
            maxsum=max(maxsum,sum);
        }
        int caseii=sum-minsubarr;
        
        return max(casei,caseii);
    }
};