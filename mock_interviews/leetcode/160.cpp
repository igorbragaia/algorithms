/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode * reversedList(ListNode * root){
  ListNode * p = root, * prev = NULL, * next;
  while(p != NULL){
    next = p->next;
    p->next = prev;
    prev = p;
    p = next;
  }
  return prev;
}


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA == NULL || headB == NULL){
        return NULL;
      }
      headA = reversedList(headA);
      headB = reversedList(headB);
      ListNode * response = NULL;
      while(headA != NULL && headB != NULL && headA == headB){
        headA = headA->next;
        headB = headB->next;
        response = headA;
      }
      headA = reversedList(headA);
      headB = reversedList(headB);
      return response;
    }
};
