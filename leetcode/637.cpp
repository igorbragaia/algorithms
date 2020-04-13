/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<double>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        int currLevel=0;
        double sum=0,qty=0;
        pair<TreeNode*, double>f;;
        while(!q.empty()){
            f = q.front();
            q.pop();
            
            if(f.second != currLevel){
                ans.push_back(sum/qty);
                sum = 0;
                qty = 0;
                currLevel++;
            }
            sum += (double)f.first->val;
            qty++;
            
            if(f.first->left != NULL)
                q.push({f.first->left, f.second+1});
            if(f.first->right != NULL)
                q.push({f.first->right, f.second+1});
        }
        ans.push_back(sum/qty);
        
        return ans;
    }
};