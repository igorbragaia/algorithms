/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool hasPath(TreeNode*root, int B, int sum, bool&found){
    if(root!=NULL){
        sum+=root->val;
        if(root->left==NULL and root->right==NULL and sum==B)
            found=true;
        hasPath(root->left,B,sum,found);
        hasPath(root->right,B,sum,found);
    }
}

int Solution::hasPathSum(TreeNode* A, int B) {
    bool found=false;
    hasPath(A,B,0,found);
    return (int)found;
}

