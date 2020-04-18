class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>costs(grid.size(), vector<int>(grid[0].size()));
        for(int i=0;i<(int)grid.size();i++)
            for(int j=0;j<(int)grid[0].size();j++)
                if(i==0 and j==0)
                    costs[i][j] = grid[i][j];
                else if(i==0)
                    costs[i][j] = grid[i][j] + costs[i][j-1];
                else if(j==0)
                    costs[i][j] = grid[i][j] + costs[i-1][j];
                else
                    costs[i][j] = grid[i][j] + min(costs[i][j-1], costs[i-1][j]);
        int lastI = (int)grid.size()-1, lastJ = (int)grid[0].size()-1;
        return costs[lastI][lastJ];
    }
};