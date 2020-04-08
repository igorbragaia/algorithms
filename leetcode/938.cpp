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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans=0;
        rec(root,L,R,ans);
        return ans;
    }
private:
    void rec(TreeNode*root, int L, int R, int&ans){
        if(root == NULL)
            return;
        
        if(root->val >= L and root->val <= R)
            ans += root->val;
        rec(root->left, L,R,ans);
        rec(root->right, L,R,ans);
    }
};