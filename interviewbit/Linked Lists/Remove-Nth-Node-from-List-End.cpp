/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int size=0;
    ListNode*p=A,*q;
    while(p!=NULL){
        p=p->next;
        size++;
    }
    if(B>=size)
        return A->next;

    p=A;
    int goUntil = size-B-1;
    while(goUntil--)
        p=p->next;
    p->next=p->next->next;
    return A;
}
