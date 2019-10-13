class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res(nums.size(),1);
        int product;
        
        for(int i=0, product=1; i<(int)nums.size()-1;i++){
            product *= nums[i];
            res[i+1] *= product;
        }
        for(int i=(int)nums.size()-1, product=1; i>0;i--){
            product *= nums[i];
            res[i-1] *= product;
        }
        return res;
    }
};