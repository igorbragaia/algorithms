/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL) return A;

    ListNode *secondList=NULL, *head=new ListNode(0);
    head->next=A;
    ListNode *itr_p=head, *itr_q, *tmp;

    while(itr_p->next!=NULL){
        if(itr_p->next->val >= B){
            tmp=itr_p->next;
            itr_p->next=itr_p->next->next;

            if(secondList==NULL){
                secondList = tmp;
                secondList->next = NULL;
                itr_q = secondList;
            } else {
                itr_q->next=tmp;
                itr_q->next->next=NULL;
                itr_q=itr_q->next;
            }
        } else if(itr_p->next != NULL)
            itr_p = itr_p->next;
    }
    itr_p->next=secondList;

    return head->next;
}
