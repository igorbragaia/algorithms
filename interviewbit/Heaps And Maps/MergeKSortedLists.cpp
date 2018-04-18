/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int,int> pp;


class comparator{
public:
	bool operator()(const pp&a, const pp&b){
		return a.first > b.first;
	}
};


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* ans = NULL, *p;

    priority_queue<pp, vector<pp>, comparator> minheap;
    for(int i = 0; i < (int)A.size(); i++){
    	minheap.push(make_pair(A[i]->val, i));
    }

    while(!minheap.empty()){
    	pp top = minheap.top();
    	minheap.pop();

    	if(ans == NULL){
    		ans = new ListNode(A[top.second]->val);
    		p = ans;
    	} else {
	  		ans->next = new ListNode(A[top.second]->val);
	  		ans = ans->next;
    	}
    	
		A[top.second] = A[top.second]->next;
		if(A[top.second] != NULL)
			minheap.push(make_pair(A[top.second]->val, top.second));
    }
    return p;
}
