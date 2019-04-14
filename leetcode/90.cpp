class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> bitmask{0}, aux, current;
        set<vector<int>>response_set;
        vector<vector<int>>response;
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
          sort(current.begin(), current.end());
          response_set.insert(current);
        }
        for(set<vector<int>>::iterator it=response_set.begin(); it!=response_set.end();it++)
            response.push_back(*it);
        return response;
    }
};
