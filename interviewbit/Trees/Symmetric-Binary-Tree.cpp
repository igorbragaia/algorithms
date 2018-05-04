/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isSameTree(TreeNode* A, TreeNode* B) {
	if(A == NULL and B == NULL)
		return true;
	if((A == NULL and B != NULL) or (A != NULL and B == NULL) or A->val != B->val)
		return false;
	return isSameTree(A->left, B->right) and isSameTree(A->right,B->left);
}

int Solution::isSymmetric(TreeNode* A) {
	if(A == NULL)
		return false;
	return isSameTree(A->left, A->right);
}
