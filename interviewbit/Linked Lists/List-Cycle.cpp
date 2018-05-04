/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ListNode* Solution::detectCycle(ListNode* A) {
//     unordered_set<ListNode*>hashset;
//     ListNode* p = A;
//     while(p != NULL){
//     	if(hashset.find(p) != hashset.end())
//     		return p;
//     	hashset.insert(p);
//     	p = p->next;
//     }
//     return NULL;
// }

ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* p = A,* q = A->next;
    while(p != NULL and q != NULL and q->next != NULL and p != q){
    	p = p->next;
    	q = q->next->next;
    }
    if(p != q)
    	return NULL;

    int count = 1;
    p = p->next;
    q = q->next->next;
    while(p != q){
    	p = p->next;
    	q = q->next->next;
    	count++;
    }

    p = A, q = A;
    for(int i = 0; i < count; i++)
    	q = q->next;

    while(p != q){
    	p = p->next;
    	q = q->next;
    }

    return p;
}
