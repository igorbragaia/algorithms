/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// higher element on interval (i,j) query O(n). It might be optimized using segment tree, which allows O(logn) queries.
TreeNode* makeTree(const vector<int> &A, int i, int j){
	if(i > j) return NULL;
	int maximum = -1, index;
	for(int k = i; k <= j; k++)
		if(A[k] > maximum){
			maximum = A[k];
			index = k;
		}

	TreeNode * node = new TreeNode(A[index]);
	node->left = makeTree(A, i, index - 1);
	node->right = makeTree(A, index + 1, j);
	return node;
}

TreeNode* Solution::buildTree(vector<int> &A) {
	return makeTree(A, 0, (int)A.size() - 1);
}
