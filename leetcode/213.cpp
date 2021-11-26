// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size()==1)
//             return nums[0];
        
//         DP = vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1));
//         int ans = 0;
//         for(int j=0;j<nums.size();j++)
//             ans=max(ans,solve(j,j,nums));
//         return ans;
//     }
// private:
//     int solve(int i, int j,vector<int>&nums) {
//         auto size = nums.size();
//         if(!(i<size) or !(j<size))
//             return 0;

//         if(DP[i][j]!=-1)
//             return DP[i][j];
//         if(i==(j+1)%size or i==(j-1+size)%size)
//             return DP[i][j]=0;
//         return DP[i][j]=max(nums[i]+solve(i+2,j,nums),solve(i+1,j,nums));
//     }
    
//     vector<vector<int>>DP;
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int size=(int)nums.size();
        
        if(size==1)
            return nums[0];
        
        vector<int> curr(size,0),next(size,0),nextnext(size,0);
        int ans=0;
        for(int i=size-1;i>=0;i--) {
            for(int j=0;j<size;j++){
                if(j==(i+1)%size or j==(i-1+size)%size)
                    curr[j]=0;
                else
                    curr[j]=max(nums[i]+nextnext[j],next[j]);
                if(i==j)
                    ans = max(ans,curr[j]);
            }
            nextnext=next;
            next=curr;
        }
        return ans;
    }
};