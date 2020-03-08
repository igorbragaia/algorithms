class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0)
            return;
        sums = vector<int>(nums.size());
        sums[0] = nums[0];
        for(unsigned int i=1;i<nums.size(); i++)
            sums[i] = sums[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return sums[j];
        return sums[j] - sums[i-1];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */