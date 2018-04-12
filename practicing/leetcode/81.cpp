class Solution {
public:
    bool search(vector<int>& nums, int target) {
          int m = 0, i = 0, f = nums.size() - 1;
          while(f > 0 && nums[0] == nums[f])
              f--;
          while(i <= f){
            m = (i + f) / 2;
            if(nums[m] == target)
              return true;
            if(nums[i] <= nums[m]){
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
          return false;
    }
};
