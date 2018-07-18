/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool hasPath(TreeNode*root, int B, int sum, vector<int>current, vector<vector<int>>&answer){
    if(root!=NULL){

        sum+=root->val;
        current.push_back(root->val);

        if(root->left==NULL and root->right==NULL and sum==B)
            answer.push_back(current);

        hasPath(root->left,B,sum, current, answer);
        hasPath(root->right,B,sum,current, answer);
    }
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>answer;
    vector<int>current;
    hasPath(A,B,0,current,answer);
    return answer;
}