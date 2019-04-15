/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void solve(TreeNode*A){
  if(A!=NULL){
    if(A->left!=NULL){
      solve(A->left);
      TreeNode*right=A->right,*left=A->left;
      A->left=NULL;
      A->right=left;
      while(A->right!=NULL)
        A=A->right;
      A->right=right;
    }
    solve(A->right);
  }
}

TreeNode* Solution::flatten(TreeNode* A) {
  solve(A);
  return A;
}
