/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
  ListNode * p = A, * tmp;
  bool update_head = false;
  while(p != NULL){
    if(p->next != NULL && p->next->val == p->val){
      if(p == A){
        update_head = true;
      }
      int val = p->val;
      while(p != NULL && p->val == val){
        tmp = p;
        p = p->next;
        delete tmp;
      }
      if(update_head){
        A = p;
      }
    } else {
      p = p->next;
    }
  }
  return A;
}
