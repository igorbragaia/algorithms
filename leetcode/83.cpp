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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * p = head, * tmp;
        while(p != NULL && p->next != NULL){
            if(p->next-> val == p->val){
              tmp = p->next;
              p->next = p->next->next;
              delete tmp;
            } else {
              p = p->next;
            }
        }
        return head;
    }
};
