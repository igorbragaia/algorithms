//      20
//      /\
//    8   22
//   / \
// 4    12
//     /\
//   10 14
#include<stdio.h>
#include<queue>
using namespace std;


struct TreeNode {
  int val;
  TreeNode * left, *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


void bfs(TreeNode root){
  queue<TreeNode> queue;
  queue.push(root);
  while(!queue.empty()){
    TreeNode element = queue.front();
    queue.pop();
    printf("%d ", element.val);
    if(element.left != NULL){
      queue.push(*element.left);
    }
    if(element.right != NULL){
      queue.push(*element.right);
    }
  }
}


int main(){
  TreeNode * root = new TreeNode(20);

  root->left = new TreeNode(8);
  root->right = new TreeNode(22);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(12);

  root->left->right->left = new TreeNode(10);
  root->left->right->right = new TreeNode(14);

  bfs(*root);

  return 0;
}
