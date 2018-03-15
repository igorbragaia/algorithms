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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 0){
          return NULL;
        }
        int x = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(x);
        int pos;
        for (pos = 0; pos < inorder.size() && inorder[pos] != x; pos++) {
        }
        if (pos != 0) {
            vector<int> in, po;
            for (int i = 0; i < pos; i++) {
                in.push_back(inorder[i]);
                po.push_back(postorder[i]);
            }
            root->left = buildTree(in, po);
        }
        if (pos != inorder.size() - 1) {
            vector<int> in, po;
            for (int i = pos + 1; i < inorder.size(); i++) {
                in.push_back(inorder[i]);
                po.push_back(postorder[i - 1]);
            }
            root->right = buildTree(in, po);
        }
        return root;
        // inorder: left root right
        // postord: left right root
    }
};
