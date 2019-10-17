/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if(root != NULL){
        	s.push(root);
        	p=root;
        	while(p->left != NULL) {
        		p=p->left;
        		s.push(p);
        	}
        }
    }
    
    /** @return the next smallest number */
    int next() {
        p=s.top();
        s.pop();
        int nextValue=p->val;

        if(p->right != NULL) {
        	p=p->right;
        	s.push(p);
	        while(p->left != NULL) {
	        	p=p->left;
	        	s.push(p);
	        }
        }

        return nextValue;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
private:
	stack<TreeNode*>s;
	TreeNode*p;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */