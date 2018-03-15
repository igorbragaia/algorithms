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
    int kthSmallest(TreeNode* root, int k)
    {
        int answer = -1, i = 0;
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty() && answer == -1) {
            TreeNode* top = node_stack.top();
            node_stack.pop();

            if (top->left != NULL) {
                TreeNode* left = top->left;
                top->left = NULL;
                node_stack.push(top);
                node_stack.push(left);
            }
            else {
                i++;
                if (i == k) {
                    answer = top->val;
                }
                if (top->right != NULL) {
                    TreeNode* right = top->right;
                    node_stack.push(right);
                }
            }
        }
        return answer;
    }
};
