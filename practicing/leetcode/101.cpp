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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return inorder(root->left, root->right);
    }
private:
    bool inorder(TreeNode * root1, TreeNode * root2){
        if(root1 == NULL and root2 == NULL)
            return true;
        if(root1 == NULL or root2 == NULL or root1->val != root2->val)
            return false;
        return inorder(root1->left, root2->right) and inorder(root1->right, root2->left);
    }
};