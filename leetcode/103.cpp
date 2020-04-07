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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if(root == NULL)
        return {};

      vector<vector<int>> allLevelsArray;
      vector<int> currentLevelArray;
      pair<TreeNode*, int> front;

      queue<pair<TreeNode*,int>>q;
      q.push({root, 0});
      while(!q.empty()){
        front = q.front();
        q.pop();

        if(front.second != (int)allLevelsArray.size()){
          allLevelsArray.push_back(move(currentLevelArray));
          currentLevelArray = vector<int>{};
        }
        currentLevelArray.push_back(front.first->val);

        if(front.first->left)
          q.push({front.first->left, front.second+1});
        if(front.first->right)
          q.push({front.first->right, front.second+1});
      }
      allLevelsArray.push_back(move(currentLevelArray));

      for(unsigned int i=0;i<allLevelsArray.size();i++)
        if(i%2==1)
          for(unsigned int j=0; j<allLevelsArray[i].size()/2;j++)
            swap(allLevelsArray[i][j], allLevelsArray[i][allLevelsArray[i].size()-j-1]);

      return allLevelsArray;
    }
};