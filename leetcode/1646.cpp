class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int maxAns = 1;
        vector<int>ans = {0,1};
        for(int i=2;i<=n;i++)
            ans.push_back(0);
        for(int i=2;i<=n;i++){
            if(i%2==0)
                ans[i]=ans[i/2];
            else
                ans[i]=ans[(i-1)/2]+ans[(i+1)/2];
            maxAns=max(maxAns,ans[i]);
        }
        return maxAns;            
    }
};