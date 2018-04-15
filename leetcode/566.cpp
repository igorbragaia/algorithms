class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r * c != nums.size() * nums[0].size())
            return nums;
        
        int a = 0, b = 0;
        vector<vector<int>>response;
        vector<int> row;
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < nums[0].size(); j++){
                row.push_back(nums[i][j]);
                if(row.size() == c){
                    response.push_back(row);
                    row.clear();
                }
            }
        return response;
    }
};