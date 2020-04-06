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
    int closestValue(TreeNode* root, double target) {
        int ans=root->val;
        queue<TreeNode*>q;
        q.push(root);
        TreeNode*front;
        while(!q.empty()){
            front = q.front();
            q.pop();
            
            if(abs((double)front->val-target) < abs((double)ans-target))
               ans=front->val;
               
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
        return ans;
    }
};