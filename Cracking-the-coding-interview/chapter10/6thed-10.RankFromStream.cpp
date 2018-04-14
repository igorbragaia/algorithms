#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
	int val;
	int leftTreeSize;
	int counter;
	TreeNode * left, * right;
	TreeNode(int x): val(x), leftTreeSize(0), counter(1), left(NULL), right(NULL) {};
};


class Solution{
public:
	Solution(): root(NULL){};
	void track(int x){
		if(root == NULL){
			root = new TreeNode(x);
		} else {
			TreeNode * p = root;
			while(p != NULL){
				if(x < p->val){
					p->leftTreeSize++;
					if(p->left != NULL){
						p = p->left;
					} else {
						p->left = new TreeNode(x);
						p = NULL;
					}
				} else if(x > p->val){
					if(p->right != NULL){
						p = p->right;
					} else {
						p->right = new TreeNode(x);
						p = NULL;
					}
				} else {
					p->counter++;
					p = NULL;
				}
			}
		}
	}
	int getRankOfNumber(int x){
		TreeNode * p = root;
		int rank = 0;
		while(p != NULL){
			if(x < p->val){
				p = p->left;
			} else if(x > p->val){
				rank += p->leftTreeSize;
				rank += p->counter;
				p = p->right;
			} else {
				rank += p->leftTreeSize;
				rank += p->counter;
				return rank;
			}
		}
		return -1;
	}
private:
	TreeNode * root;
};


int main(){
	Solution solution;
	solution.track(5);
	solution.track(1);
	solution.track(4);
	solution.track(4);
	solution.track(5);
	solution.track(9);
	solution.track(7);
	solution.track(13);
	solution.track(3);
	cout << solution.getRankOfNumber(1000) << endl;
	cout << solution.getRankOfNumber(1) << endl;
	cout << solution.getRankOfNumber(3) << endl;
	cout << solution.getRankOfNumber(4) << endl;
	cout << solution.getRankOfNumber(5) << endl;
	cout << solution.getRankOfNumber(7) << endl;
	cout << solution.getRankOfNumber(9) << endl;
	cout << solution.getRankOfNumber(13) << endl;
	return 0;
}