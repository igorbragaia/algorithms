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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == NULL && q == NULL) {
            return true;
        }
        else if (p == NULL || q == NULL || p->val != q->val) {
            return false;
        }

        stack<TreeNode *> stack1, stack2;
        TreeNode *top1, *top2;
        stack1.push(p);
        stack2.push(q);
        bool response = true;
        while (response && !stack1.empty() && !stack2.empty()) {
            top1 = stack1.top();
            top2 = stack2.top();
            stack1.pop();
            stack2.pop();

            if ((top1->left == NULL && top2->left != NULL) || (top1->left != NULL && top2->left == NULL) || (top1->left != NULL && top2->left != NULL && top1->left->val != top2->left->val)) {
                response = false;
            }
            else if (top1->left != NULL && top2->left != NULL && top1->left->val == top2->left->val) {
                stack1.push(top1->left);
                stack2.push(top2->left);
            }

            if ((top1->right == NULL && top2->right != NULL) || (top1->right != NULL && top2->right == NULL) || (top1->right != NULL && top2->right != NULL && top1->right->val != top2->right->val)) {
                response = false;
            }
            else if (top1->right != NULL && top2->right != NULL && top1->right->val == top2->right->val) {
                stack1.push(top1->right);
                stack2.push(top2->right);
            }
        }

        if (!stack1.empty() || !stack2.empty()) {
            response = false;
        }

        return response;
    }
};
