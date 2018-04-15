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
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        ListNode * slow = head, * fast = head->next;
        bool has_cycle = false;
        while(!has_cycle && slow != NULL && slow->next != NULL && fast != NULL && fast->next != NULL && fast->next->next != NULL){
            if(slow == fast){
              has_cycle = true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return has_cycle;
    }
};
