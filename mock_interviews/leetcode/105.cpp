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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(inorder.size() == 0){
        return NULL;
      }
      int x = preorder[0];
      TreeNode* root = new TreeNode(x);
      int pos;
      for (pos = 0; pos < inorder.size() && inorder[pos] != x; pos++) {
      }
      if (pos != 0) {
          vector<int> in, pre;
          for (int i = 0; i < pos; i++) {
              in.push_back(inorder[i]);
              pre.push_back(preorder[i + 1]);
          }
          root->left = buildTree(pre, in);
      }
      if (pos != inorder.size() - 1) {
          vector<int> in, pre;
          for (int i = pos + 1; i < inorder.size(); i++) {
              in.push_back(inorder[i]);
              pre.push_back(preorder[i]);
          }
          root->right = buildTree(pre, in);
      }
      return root;
      //  inorder: left root right
      //  preorder: root left right
    }
};
