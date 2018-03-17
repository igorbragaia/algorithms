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
    int sumOfLeftLeaves(TreeNode* root) {
      if(root == NULL)
        return 0;
      return dfs(root, false);
    }
private:
  int dfs(TreeNode * root, bool left){
    if(root->left == NULL && root->right == NULL){
      if(left)
        return root->val;
      else
        return 0;
    }
    int response = 0;
    if(root->left != NULL){
      response += dfs(root->left, true);
    }
    if(root->right != NULL){
      response += dfs(root->right, false);
    }
    return response;
  }
};
