/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return true;
        ListNode*h1=head,*h2=HalfSplit(head);
        h2=invertList(h2);
        bool res=true;
        while(h1!=NULL and h2!=NULL and res){
            if(h1->val == h2->val){
                h1=h1->next;
                h2=h2->next;
            } else 
                res=false;
        }
        return res;
    }
private:
    ListNode*HalfSplit(ListNode*head) {
        ListNode *p=head, *q=head, *res;
        while(q->next!=NULL and q->next->next!=NULL){
            p=p->next;
            q=q->next->next;
        }
        res=p->next;
        p->next=NULL;
        return res;
    }

    ListNode*invertList(ListNode*head) {
        ListNode*prev=NULL, *current=head, *next;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
};