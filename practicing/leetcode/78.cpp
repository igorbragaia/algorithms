class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> bitmask, aux, current;
        vector<vector<int>> response;
        bitmask.push_back(0);
        for(int i = 0; i < nums.size(); i++){
          aux = bitmask;
          for(int j = 0; j < aux.size(); j++)
            bitmask.push_back(aux[j] | 1<<i);
        }
        for(int i = 0; i < bitmask.size(); i++){
          current.clear();
          for(int j = 0; j < nums.size(); j++)
            if(1 << j & bitmask[i])
              current.push_back(nums[j]);
          response.push_back(current);
        }
        return response;
    }
};
