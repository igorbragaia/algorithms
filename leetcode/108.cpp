/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode*solve(vector<int>&nums,int i, int j){
        if(i>j)
            return nullptr;
        
        int m = (i+j)/2;
        TreeNode*node = new TreeNode(nums[m]);
        node->left = solve(nums, i, m-1);
        node->right = solve(nums, m+1, j);
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        
        return solve(nums, 0, (int)nums.size()-1);
    }
};