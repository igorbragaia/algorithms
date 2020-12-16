class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if((int)nums.size() < 3)
            return false;
        
        int low = INT_MAX, mid = INT_MAX;
        for(int num:nums){
            if(num > mid)
                return true;
            
            if(num < low)
                low = num;
            else if (num > low and num < mid)
                mid = num;                
        }
        
        return false;        
    }
};