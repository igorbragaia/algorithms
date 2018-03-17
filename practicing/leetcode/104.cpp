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
    int maxDepth(TreeNode* root) {
      return dfs(root, 0);
    }
private:
  int dfs(TreeNode * root, int count){
    if(root == NULL)
      return count;
    return max(dfs(root->left, count + 1), dfs(root->right, count + 1));
  }
};
