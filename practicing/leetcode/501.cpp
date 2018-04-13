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
    vector<int> findMode(TreeNode* root) {
        vector<int> answer;
        if(root == NULL)
        	return answer;

        vector<pair<int,int>> ordered_hashmap;
        preorder(root);
        for(unordered_map<int,int>::iterator it = hashmap.begin(); it != hashmap.end(); it++)
        	ordered_hashmap.push_back(make_pair(it->second,it->first));
        sort(ordered_hashmap.begin(), ordered_hashmap.end(), compare);
        for(int i = 0; i < ordered_hashmap.size(); i++)
            if(ordered_hashmap[i].first == ordered_hashmap[0].first)
            	answer.push_back(ordered_hashmap[i].second);
        return answer;
    }
private:
    unordered_map<int,int> hashmap;
    static bool compare(pair<int,int>&a, pair<int,int>&b){
        return a.first > b.first;
    }
    void preorder(TreeNode* root){
    	if(root != NULL){
    		if(hashmap.find(root->val) == hashmap.end())
    			hashmap[root->val] = 1;
    		else
    			hashmap[root->val]++;
    		preorder(root->left);
    		preorder(root->right);
    	}
    }
};
