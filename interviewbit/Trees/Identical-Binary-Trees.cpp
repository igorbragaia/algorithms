/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
	if(A == NULL and B == NULL)
		return true;
	if((A == NULL and B != NULL) or (A != NULL and B == NULL) or A->val != B->val)
		return false;
	return isSameTree(A->left, B->left) and isSameTree(A->right,B->right);
}
