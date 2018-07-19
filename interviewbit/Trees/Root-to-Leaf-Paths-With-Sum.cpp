/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool hasPath(TreeNode*root, vector<int>current, vector<vector<int>>&answer){
    if(root!=NULL){
        current.push_back(root->val);

        if(root->left==NULL and root->right==NULL)
            answer.push_back(current);

        hasPath(root->left,current, answer);
        hasPath(root->right,current, answer);
    }
}

int Solution::sumNumbers(TreeNode* A) {
    int pot[10000];
    pot[0]=1;
    for(int i=1;i<10000;i++)
        pot[i]=(pot[i-1]*10)%1003;

    vector<vector<int>>answer;
    vector<int>current;
    hasPath(A,current,answer);
    
    int response=0;
    for(vector<int> num:answer){
        for(int i=0;i<(int)num.size(); i++){
            response=(response+num[i]*pot[(int)num.size()-1-i])%1003;
        }
    }

    return response;
}