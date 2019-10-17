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
    bool isValidBST(TreeNode* root) {
        if(root==NULL or (root->left==NULL and root->right==NULL))
            return true;
        bool res=true;
        TreeNode*p=root->left, *q=root;
        while(p!=NULL){
            if(p->val>=q->val)
                res &= false;

            if(p->right!=NULL)
                validate(p->right, p->val, root->val, &res);
            q=p;
            p=p->left;
        }

        p=root->right, q=root;
        while(p!=NULL){
            if(p->val<=q->val)
                res &= false;
            if(p->left!=NULL)
                validate(p->left, root->val, p->val, &res);
            q=p;
            p=p->right;
        }
        return res;
    }
private:
    void validate(TreeNode*root, int rangeMin, int rangeMax, bool *res){
        if(*res){            
            if(root->val<=rangeMin or root->val>=rangeMax)
                *res &= false;
            if(root->left!=NULL)
                validate(root->left, rangeMin, min(root->val, rangeMax), res);
            if(root->right!=NULL)            
                validate(root->right, max(rangeMin, root->val), rangeMax, res);
        }        
    }
};