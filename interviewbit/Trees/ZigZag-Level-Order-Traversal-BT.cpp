/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<int,vector<int>>levels;

void dfs(TreeNode*node, int level){
  if(node != NULL){
    if(node->left!=NULL)
      dfs(node->left,level+1);

    if(levels.find(level) == levels.end())
      levels[level]=vector<int>();
    levels[level].push_back(node->val);

    if(node->right!=NULL)
      dfs(node->right,level+1);
  }
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
  vector<vector<int>>response;
  vector<int>tmp;
  levels=map<int,vector<int>>();
  dfs(A,1);
  for(map<int,vector<int>>::iterator it=levels.begin();it!=levels.end();it++){
    tmp=it->second;
    if(it->first%2==0)
      for(int i=0;i<(int)tmp.size()/2;i++)
        swap(tmp[i],tmp[(int)tmp.size()-i-1]);
    response.push_back(tmp);
  }
  return response;
}
