/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int depth(TreeNode* A, int current_depth){
    current_depth++;

    if(A->left != NULL and A->right == NULL)
        return depth(A->left, current_depth);
    if(A->left == NULL and A->right != NULL)
        return depth(A->right, current_depth);
    if(A->left != NULL and A->right != NULL)
        return max(depth(A->left, current_depth), depth(A->right, current_depth));
    return current_depth;
}

int Solution::maxDepth(TreeNode* A) {
    if(A == NULL)	
        return 0;
    return depth(A, 0);
}
