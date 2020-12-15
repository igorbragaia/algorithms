class Solution {
private:
    int searchStart(vector<int>&nums,int target, int f){
        int s=0,m;
        while(s<=f){
            m=(s+f)/2;
            if(nums[m] == target){
                if(m == 0 or nums[m-1] != target)
                    return m;
                else
                    f=m-1;
            } else if(nums[m] < target)
                s=m+1;
            else
                f=m-1;                
        }
        return -1;
    }
    
    int searchEnd(vector<int>&nums, int target, int s){
        int f=(int)nums.size()-1,m;
        while(s<=f){
            m=(s+f)/2;
            if(nums[m] == target){
                if(m == (int)nums.size()-1 or nums[m+1] != target)
                    return m;
                else
                    s = m+1;
            } else if(nums[m] < target)
                s = m+1;
            else
                f = m-1;                
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        
        int s=0, f=(int)nums.size()-1, m;
        while(s<=f){
            m=(s+f)/2;
            if(nums[m]==target)
                break;
            else if(nums[m]<target)
                s=m+1;
            else
                f=m-1;
        }
        
        int start = searchStart(nums,target,m), end = searchEnd(nums,target,m);
        return {start, end};
    }
};