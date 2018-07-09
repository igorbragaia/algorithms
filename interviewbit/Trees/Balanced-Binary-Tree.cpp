/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int treeLen(TreeNode*A, bool&answer){
    if(A == NULL) 
        return 0;

    int left=1+treeLen(A->left, answer);
    int right=1+treeLen(A->right, answer);
    
    answer &= (abs(left-right)<=1);

    return max(left, right);
}

int Solution::isBalanced(TreeNode* A) {
    bool answer = true;
    treeLen(A, answer);
    return answer;
}
