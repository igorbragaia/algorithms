class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if(arr.size()==0)
            return 0;

        int n = (int)arr.size(), k = (int)arr[0].size();

        vector<int>DP = arr[0], minArrayExcludingSelf;

        for(int i=1;i<n;i++){
            minArrayExcludingSelf = getMinArrayExcludingSelf(DP);
            for(int j=0;j<k;j++)
                DP[j] = arr[i][j] + minArrayExcludingSelf[j];
        }

        int ans = DP[0];
        for(int j=0;j<k;j++)
            ans = min(ans, DP[j]);
        return ans;
    }
private:
    vector<int> getMinArrayExcludingSelf(vector<int>DP){
        vector<int> left(DP.size(), INT_MAX), right(DP.size(), INT_MAX), ans(DP.size());
        for(int i=1; i<(int)DP.size();i++)
            left[i] = min(left[i], min(left[i-1], DP[i-1]));

        for(int i=(int)DP.size()-2;i>=0;i--)
            right[i] = min(right[i], min(right[i+1], DP[i+1]));

        for(int i=0;i<(int)DP.size();i++)
            ans[i]=min(left[i],right[i]);

        return ans;
    }
};