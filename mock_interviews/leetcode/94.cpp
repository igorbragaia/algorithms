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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> answer;

      if(root == NULL){
        return answer;
      }

      stack<TreeNode*> node_stack;
      node_stack.push(root);
      while(!node_stack.empty()){
        TreeNode * top = node_stack.top();
        node_stack.pop();

        if(top->left != NULL){
          TreeNode * left = top->left;
          top->left = NULL;
          node_stack.push(top);
          node_stack.push(left);
        } else {
          answer.push_back(top->val);
          if(top->right != NULL){
            TreeNode * right = top->right;
            node_stack.push(right);
          }
        }
      }
      return answer;
    }
};
