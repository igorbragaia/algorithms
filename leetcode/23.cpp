/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int,int> pp;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<pp>pq;      
		vector<ListNode*>iters=lists;
		for(unsigned int i=0;i<iters.size();i++)
			pq.push({-iters[i]->val, i});

		ListNode*res=NULL, *iter;
		pp top;
		while(!pq.empty()){
			top=pq.top();
			pq.pop();

			if(res == NULL){
				res = iters[top.second];
				iters[top.second]=iters[top.second]->next;
				res->next=NULL;
				iter=res;
			} else {
				iter->next=iters[top.second];
				iters[top.second]=iters[top.second]->next;
				iter=iter->next;
			}

			if(iters[top.second] != NULL)
				pq.push({-iters[top.second]->val, top.second});
		}
		return res;
    }
};
