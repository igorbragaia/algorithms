/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* makeTree(const vector<int> &A, int i, int j){
	if(i > j) return NULL;
	TreeNode * node = new TreeNode(A[(i+j)/2]);
	node->left = makeTree(A, i, (i+j)/2 - 1);
	node->right = makeTree(A, (i+j)/2 + 1, j);
	return node;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
	return makeTree(A, 0, (int)A.size() - 1);
}