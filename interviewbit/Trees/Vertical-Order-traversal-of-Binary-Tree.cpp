/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(A == NULL)
    	return {};

    vector<pair<int,int>>array;

    queue<pair<TreeNode*,int>>queue;
    queue.push(make_pair(A,0));
    while(!queue.empty()){
    	pair<TreeNode*,int> front=queue.front();
    	queue.pop();

    	array.push_back(make_pair(front.first->val, front.second));

    	if(front.first->left!=NULL)
    		queue.push(make_pair(front.first->left, front.second-1));
    	if(front.first->right!=NULL)
    		queue.push(make_pair(front.first->right,front.second+1));
    }



    int minPos=0, maxPos=0;
    for(pair<int,int> el:array){
        minPos=min(minPos, el.second);
        maxPos=max(maxPos, el.second);    
    }
    maxPos+=abs(minPos);
    for(int i=0;i<(int)array.size();i++)
        array[i].second += abs(minPos);
    vector<int>empty;
    vector<vector<int>>answer(maxPos+1,empty);
    for(int i=0;i<(int)array.size();i++)
        answer[array[i].second].push_back(array[i].first);
    return answer;
}
