/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TreeNode * makeTree(vector<int>&array, int i, int j){
	if(i > j){
		return NULL;
	} else {
		TreeNode * node = new TreeNode(array[(i + j) / 2]);
		node->left = makeTree(array, i, (i + j) / 2 - 1);
		node->right = makeTree(array, (i + j) / 2 + 1, j);
		return node;
	}
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> array;
    while(A != NULL){
    	array.push_back(A->val);
    	A = A->next;
    }
    return makeTree(array, 0, (int)array.size() - 1);
}
