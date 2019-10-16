/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*,int>pp;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root == NULL)
        	return res;

        queue<pp>q;
        q.push({root, 1});
        pp front;
        int depth=0;
        while(!q.empty()){
        	front=q.front();
        	q.pop();
        	if(front.second>depth){
        		res.push_back(front.first->val);
        		depth=front.second;
        	}
        	if(front.first->right!=NULL)
        		q.push({front.first->right, front.second+1});
        	if(front.first->left!=NULL)
        		q.push({front.first->left, front.second+1});
        }
        return res;
    }
};