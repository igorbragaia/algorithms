/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        ListNode*p=head, *tmp, *q=NULL,*secondHead;
        while(p != NULL and p->next != NULL){
            tmp = p->next;            
            p->next = p->next->next;
            if(p->next != NULL)
                p = p->next;
            
            tmp->next=NULL;
            if(q==NULL){
                q=tmp;
                secondHead=q;
            }
            else {
                q->next=tmp;
                q=q->next;
            }
        }
        p->next = secondHead;
        return head;
    }
};