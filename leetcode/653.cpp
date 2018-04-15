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
    bool findTarget(TreeNode* root, int k) {
        return bfs(root, k);
    }
private:
  bool bfs(TreeNode* root, int k){
    TreeNode* front;
    queue<TreeNode*>queue;

    queue.push(root);
    while(!queue.empty()){
        front = queue.front();
        queue.pop();

        bool found = search(root, front, k - front->val);
        if(found)
          return true;
        if(front->left != NULL)
          queue.push(front->left);
        if(front->right != NULL)
          queue.push(front->right);
    }
    return false;
  }

  bool search(TreeNode* node, TreeNode* reference, int value){
    while(node != NULL){
      if(node->val == value && node != reference)
        return true;

      if(value < node->val)
        node = node->left;
      else
        node = node->right;
    }
    return false;
  }
};
