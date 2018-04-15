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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> response;
        stack<TreeNode*> stack;
        TreeNode * top, *left, *right;
        if(root != NULL){
          response.push_back(root->val);
          stack.push(root);
        }
        while(!stack.empty()){
          top = stack.top();
          stack.pop();

          if(top->left != NULL){
            left = top->left;
            top->left = NULL;
            response.push_back(left->val);
            stack.push(top);
            stack.push(left);
          } else if (top->right != NULL){
            right = top->right;
            response.push_back(right->val);
            stack.push(right);
          }
        }
        return response;
    }
};
