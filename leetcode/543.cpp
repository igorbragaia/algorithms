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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        maxDiameter = 0;
        maxLength(root);
        return maxDiameter-1;
    }
private:
    int maxDiameter;
    
    int maxLength(TreeNode*node){
        int leftLength = node->left != NULL ? maxLength(node->left) : 0;
        int rightLength = node->right != NULL ? maxLength(node->right) : 0;
        maxDiameter = max(maxDiameter, 1+leftLength+rightLength);
        return 1+max(leftLength,rightLength);
    }
};