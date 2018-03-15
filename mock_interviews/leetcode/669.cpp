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
    TreeNode* trimBST(TreeNode* root, int L, int R)
    {
        if (root == NULL || root->val < L || root->val > R) {
            return NULL;
        }
        this->L = L;
        this->R = R;
        dfs(&root);
        return root;
    }
private:
    int L, R;
    void dfs(TreeNode** root)
    {
        if ((*root)->left != NULL && (*root)->right == NULL && (*root)->left->val < this->L) {
            TreeNode* tmp = (*root)->left;
            (*root)->left = (*root)->left->left;
            delete tmp;
        }
        else {
            TreeNode *tmp = (*root)->left, *p = (*root)->left;
            while (p->right->right != NULL)
                p = p->right;
            TreeNode* insert = p->right;
            p->right = NULL;
            insert->left = (*root)->left->left;
            insert->right = (*root)->left->right;
            (*root)->left = insert;
            delete tmp;
        }

        if ((*root)->right != NULL && (*root)->right->val > this->R) {
            TreeNode* tmp = (*root)->right;
            (*root)->right = (*root)->right->left;
            delete tmp;
        }
        else {
            TreeNode *tmp = (*root)->right, *p = (*root)->right;
            while (p->right->right != NULL)
                p = p->right;
            TreeNode* insert = p->right;
            p->right = NULL;
            insert->left = (*root)->right->left;
            insert->right = (*root)->right->right;
            (*root)->right = insert;
            delete tmp;
        }

        if ((*root)->left != NULL)
            dfs(&(*root)->left);
        if ((*root)->right != NULL)
            dfs(&(*root)->right);
    }
};
