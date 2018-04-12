class Solution {
public:
    int search(vector<int>& nums, int target) {
          int m = 0, i = 0, f = nums.size() - 1;
          while(i <= f){
            m = (i + f) / 2;
            if(nums[m] == target)
              return m;
            if(nums[i] < nums[m]){
              if(nums[i] <= target && target <= nums[m])
                f = m - 1;
              else
                i = m + 1;
            } else {
              if(nums[m + 1] <= target && target <= nums[f])
                i = m + 1;
              else
                f = m - 1;
            }
          }
          return -1;
    }
};
