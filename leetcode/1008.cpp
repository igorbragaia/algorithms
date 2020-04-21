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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return construct(INT_MIN, INT_MAX, idx, preorder);
    }
private:
    TreeNode* construct(int left, int right, int&idx, vector<int>&preorder){
        if(idx == (int)preorder.size() or preorder[idx] < left or preorder[idx] > right)
            return nullptr;
        
        int val = preorder[idx++];
        TreeNode*node = new TreeNode(val);
        node->left = construct(left, val, idx, preorder);
        node->right = construct(val, right, idx, preorder);
        return node;
    }
};