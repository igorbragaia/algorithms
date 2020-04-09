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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return false;
        
        set<int>nums;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*f;
        while(!q.empty()){
            f = q.front();
            q.pop();
            
            if(nums.find(k-f->val) != nums.end())
                return true;
            else
                nums.insert(f->val);
            
            if(f->left!=NULL) q.push(f->left);
            if(f->right!=NULL) q.push(f->right);
        }
        
        return false;
    }
};