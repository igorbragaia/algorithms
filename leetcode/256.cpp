class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0)
            return 0;
        if(costs.size()==1)
            return min(costs[0][0], min(costs[0][1], costs[0][2]));
        
        int n = (int)costs.size();
        vector<vector<int>>DP(n, vector<int>(3, 0));
        DP[0][0] = costs[0][0];
        DP[0][1] = costs[0][1];
        DP[0][2] = costs[0][2];
        for(int i=1;i<n;i++)
            for(int j=0;j<3;j++)
                DP[i][j] = costs[i][j] + min(DP[i-1][(j+1)%3], DP[i-1][(j+2)%3]);
        
        return min(DP[n-1][0], min(DP[n-1][1], DP[n-1][2]));
    }
};