/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*,int> pp;


vector<vector<int> > Solution::levelOrder(TreeNode* A) {
	vector<vector<int>> answer;
	if(A == NULL)
		return answer;

	queue<pp>queue;
	queue.push(make_pair(A, 0));
	while(!queue.empty()){
		pp front = queue.front();
		queue.pop();

		if((int)answer.size() <=  front.second)
			answer.push_back({});
		answer[front.second].push_back(front.first->val);

		if(front.first->left != NULL)
			queue.push(make_pair(front.first->left, front.second + 1));

		if(front.first->right != NULL)
			queue.push(make_pair(front.first->right, front.second + 1));
	}

	return answer;
}
