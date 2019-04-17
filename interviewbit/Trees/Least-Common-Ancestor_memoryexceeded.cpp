/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode*findNode(TreeNode*node,int num){
  if(node==NULL)
    return NULL;
  if(node->val==num)
    return node;
  TreeNode*left=findNode(node->left,num),*right=findNode(node->right,num);
  if(left!=NULL)
    return left;
  else
    return right;
}

map<TreeNode*,pair<TreeNode*,int>>hashmap;
void makeHashmap(TreeNode*node,TreeNode*parent,int depth){
  if(node!=NULL){
      hashmap[node]=make_pair(parent,depth);
      makeHashmap(node->left,node,depth+1);
      makeHashmap(node->right,node,depth+1);
  }
}

int Solution::lca(TreeNode* A, int B, int C) {
  TreeNode*nodeB=findNode(A,B),*nodeC=findNode(A,C);
  if(nodeB==NULL or nodeC==NULL)
    return -1;
  makeHashmap(A,NULL,0);
  while(nodeB!=nodeC){
    if(hashmap[nodeB].second > hashmap[nodeC].second)
      nodeB=hashmap[nodeB].first;
    else
      nodeC=hashmap[nodeC].first;
  }
  return nodeB->val;
}
