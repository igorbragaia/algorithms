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
    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return;
        
        pair<ListNode*,ListNode*> pp = middleSplit(head);
        pp.second = invert(pp.second);
        merge(pp.first, pp.second);
    }
private:
    pair<ListNode*,ListNode*> middleSplit(ListNode*head){
        ListNode*i=head,*j=head->next;
        
        while(j!=NULL and j->next!=NULL and j->next->next!=NULL){
            i=i->next;
            j=j->next->next;
        }
        if(j->next!=NULL and j->next->next==NULL)
            i=i->next;
        ListNode*secondHalf=i->next;
        i->next=NULL;
        return {head, secondHalf};
    }
    
    ListNode* invert(ListNode*head) {
        ListNode*prev=NULL, *curr=head, *next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    void merge(ListNode*list1, ListNode*list2){
        ListNode*i=list1,*j=list2,*next;
        while(i!=NULL and j!=NULL){
            next=i->next;
            i->next=j;
            j=j->next;
            i->next->next=next;
            i=next;
        }
    }
};