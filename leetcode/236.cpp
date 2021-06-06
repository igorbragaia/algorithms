/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<bool,bool>bb;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isLCA(root,p,q);
        return answer;
    }
private:
    TreeNode* answer;
    bb isLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr)
            return {false, false};
        
        bb left = isLCA(root->left,p,q), right = isLCA(root->right,p,q);
        bool is_p = root == p || left.first || right.first;
        bool is_q = root == q || left.second || right.second;
        if (!answer and (is_p && is_q))
            answer = root;
        return {is_p, is_q};
    }
};