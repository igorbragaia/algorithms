/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive Solution
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL)
//             return true;
//         return inorder(root->left, root->right);
//     }
// private:
//     bool inorder(TreeNode * root1, TreeNode * root2){
//         if(root1 == NULL and root2 == NULL)
//             return true;
//         if(root1 == NULL or root2 == NULL or root1->val != root2->val)
//             return false;
//         return inorder(root1->left, root2->right) and inorder(root1->right, root2->left);
//     }
// };

struct Print{
    TreeNode * node;
    bool left, right;
    Print(TreeNode * x): node(x), left(false), right(false) {};
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;

        queue<Print> queueL, queueR;
        Print printL(root->left);
        Print printR(root->right);
        queueL.push(printL);
        queueR.push(printR);
        while(!queueL.empty() and !queueR.empty()){
            printL = queueL.front();
            printR = queueR.front();
            queueL.pop();
            queueR.pop();

            if((printL.node == NULL and printR.node != NULL) or (printL.node != NULL and printR.node == NULL) or (printL.node != NULL and printR.node != NULL and printL.node->val != printR.node->val))
                return false;

            if(printL.node != NULL and !printL.left and !printL.right){
                printL.right = true;
                Print printLR(printL.node->right);
                queueL.push(printL);
                queueL.push(printLR);
            } else if(printL.node != NULL and !printL.left and printL.right){
                printL.left = true;
                Print printLL(printL.node->left);
                queueL.push(printL);
                queueL.push(printLL);                
            }

            if(printR.node != NULL and !printR.left and !printR.right){
                printR.left = true;
                Print printRL(printR.node->left);
                queueR.push(printR);
                queueR.push(printRL);
            } else if(printR.node != NULL and printR.left and !printR.right){
                printR.right = true;
                Print printRR(printR.node->right);
                queueR.push(printR);
                queueR.push(printRR);                
            }
        }
        if(!queueL.empty() or !queueR.empty())
            return false;
        return true;
    }
};