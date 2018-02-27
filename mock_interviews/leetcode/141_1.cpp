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
          bool has_cycle = false;
          while(!has_cycle && head != NULL){
              if(head->val == -100000){
                has_cycle = true;
              }
              head->val = -100000;
              head = head->next;
          }
          return has_cycle;
    }
};
