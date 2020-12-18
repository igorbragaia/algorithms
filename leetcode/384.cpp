class Solution {
public:
    Solution(vector<int>& nums) {
        for(int num:nums)
            start.push_back(num);
        curr = start;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return start;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        /// generates the next permutation
        int i = (int)curr.size()-1;
        while(i>0 and curr[i-1] >= curr[i])
            i--;
        i--;

        if(i < 0){
            reverse(0);
        } else {
            int j=(int)curr.size()-1;
            while(curr[j] <= curr[i])
                j--;
            swap(curr[i], curr[j]);
            reverse(i+1);
        }
        
        return curr;
    }
private:
    vector<int>start, curr;
    
    void reverse(int fromIdx){
        int range = (int)curr.size()-fromIdx;
        for(int i=0;i<range/2;i++)
            swap(curr[fromIdx+i], curr[(int)curr.size()-1-i]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */