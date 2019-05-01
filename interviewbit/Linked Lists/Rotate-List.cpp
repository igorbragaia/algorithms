/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL or A->next==NULL)
        return A;

    int qty=0;
    ListNode*p=A,*q,*response;
    while(p!=NULL){
        qty++;
        p=p->next;
    }

    int move=qty-(B%qty)-1;
    if(move==0)
        return A;
    p=A;
    while(move--)
        p=p->next;
    q=p->next;
    p->next=NULL;
    response=q;
    while(q->next!=NULL)
        q=q->next;
    q->next=A;
    return response;
}
