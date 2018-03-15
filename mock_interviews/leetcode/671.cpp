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
    int findSecondMinimumValue(TreeNode* root) {
        this->rootval = root->val;
        this->min = 1000000;
        dfs(root);
        return this->min==1000000?-1:this->min;
    }
private:
  int min, rootval;
  void dfs(TreeNode * root){
    if(root == NULL){
      return;
    }

    if(root->val != rootval && root->val < min){
      min = root->val;
    } else {
      dfs(root->left);
      dfs(root->right);
    }
  }
};
