/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        DP = map<TreeNode*,int>();
        ans = root->val;
        dp(root);
        return ans;
    }
private:
    map<TreeNode*,int>DP;
    int ans;
    
    int dp(TreeNode*node){
        if(DP.find(node) != DP.end())
            return DP[node];
        
        int left = node->left != NULL ? dp(node->left) : 0;
        int right = node->right != NULL ? dp(node->right) : 0;
        
        ans = max(ans, node->val + max(left, 0) + max(right, 0));
        
        return DP[node] = max(node->val, node->val +  max(left, right));
    }
};
