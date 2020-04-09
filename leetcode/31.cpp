class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            T: O(n) and M: O(1) solution
        */
        /*
            1) go right->left idx and find by what idx it is ascending
        */
        int idx=-1;
        for(int i=(int)nums.size()-1;i>0 and idx==-1;i--)
            if(nums[i-1]<nums[i])
                idx=i;
        if(idx==-1){
            for(int i=0;i<(int)nums.size()/2;i++)
                swap(nums[i], nums[(int)nums.size()-i-1]);
            return;
        }
        /*
            2) get what is the smallest number highest than nums[idx] for num on the right side of idx
            it could be a binary search but this solution is already O(n)
        */
        int wantedIdx=-1;
        for(int i=(int)nums.size()-1;i>=idx;i--)
            if((wantedIdx == -1 or nums[i]<nums[wantedIdx]) and nums[i]>nums[idx-1])
                wantedIdx=i;
        /*
            3) swap(nums[idx], num)
        */
        swap(nums[idx-1], nums[wantedIdx]);
        /*
            4) for numbers on the ascending range from 1), in O(n) make it ascending again
        */
        for(int i=idx; i<(int)nums.size()-1;i++)
            if(nums[i] < nums[i+1])
                swap(nums[i], nums[i+1]);
        /*
            5) revert the ascending range to make it decreasing
        */
        int i = idx, shift = 1;
        int qty = ((int)nums.size() - idx)/2;
        while(qty--){
            swap(nums[i], nums[(int)nums.size()-shift]);
            i++;
            shift++;
        }
    }
};
