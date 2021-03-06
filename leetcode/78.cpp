class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> bitmask{0}, aux, current;
        vector<vector<int>> response;
        for(int i = 0; i < (int)nums.size(); i++){
          aux = bitmask;
          for(int j = 0; j < (int)aux.size(); j++)
            bitmask.push_back(aux[j] | 1<<i);
        }
        for(int i = 0; i < (int)bitmask.size(); i++){
          current = vector<int>();
          for(int j = 0; j < (int)nums.size(); j++)
            if(1 << j & bitmask[i])
              current.push_back(nums[j]);
          response.push_back(current);
        }
        return response;
    }
};
