/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Print{
    bool left, right;
    TreeNode*node;
    Print(TreeNode*node): left(false), right(false), node(node) {};
};

vector<int> Solution::postorderTraversal(TreeNode* A) {
    //left,root,right
    vector<int>response;
    stack<Print>stack;
    if(A != NULL){
            Print start(A);
            stack.push(start);
        }
    while(!stack.empty()){
        Print top = stack.top();
        stack.pop();
        
        if(!top.left){
            top.left = true;
            stack.push(top);

            if(top.node->left != NULL){
                Print newprint(top.node->left);
                stack.push(newprint);
            }
        } else if(!top.right){
            top.right = true;
            stack.push(top);

            if(top.node->right != NULL){
                Print newprint(top.node->right);
                stack.push(newprint);
            }
        } else {
        	response.push_back(top.node->val);
        }
    }
    return response;
}
