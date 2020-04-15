class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>DP(cost.size());
        DP[(int)cost.size()-1] = cost[(int)cost.size()-1];
        DP[(int)cost.size()-2] = cost[(int)cost.size()-2];
        for(int i=(int)cost.size()-3;i>=0;i--)
            DP[i] = cost[i] + min(DP[i+1], DP[i+2]);
        
        return min(DP[0], DP[1]);
    }
};