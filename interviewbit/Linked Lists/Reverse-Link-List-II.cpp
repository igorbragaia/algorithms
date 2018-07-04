/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode*response=A;

    if(A!= NULL and A->next != NULL){
        int count = 1;
        ListNode*antes,*start,*p,*q,*pantes;
    
        p=A;
        if(B!=1){
            while(count != B-1){
                p=p->next;
                count++;
            }
            antes=p;
            start=p->next;
            p=p->next;
            count++;
        } else {
            antes = NULL;
            start=p;
        }
        
        pantes=NULL;
        while(count != C+1){
            q=p->next;
            p->next=pantes;
            pantes=p;
            p=q;
            count++;
        }
        
        if(antes!=NULL)
            antes->next=pantes;
        else
            response = pantes;
        start->next=p;
    }
    return response;
}
