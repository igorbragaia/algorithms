/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define LEFT 0
#define RIGHT 1
#define ROOT 2

TreeNode * current;
stack<pair<TreeNode*,int>>pilha;

BSTIterator::BSTIterator(TreeNode *root) {
    if(root != NULL){
        pilha.push(make_pair(root, ROOT));
        while(pilha.top().first->left!=NULL)
            pilha.push(make_pair(pilha.top().first->left,LEFT));   
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !pilha.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    int val = pilha.top().first->val;
    if(pilha.top().first->right!=NULL){
        pair<TreeNode*,int> top = pilha.top();
        pilha.pop();
        pilha.push(make_pair(top.first->right, RIGHT));
        while(pilha.top().first->left!=NULL)
            pilha.push(make_pair(pilha.top().first->left,LEFT));
    }
    else {
        pilha.pop();            
    }
    return val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
