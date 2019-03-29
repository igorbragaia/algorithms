/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
  if(A == NULL and B == NULL) return NULL;
  if(A == NULL and B != NULL) return B;
  if(A != NULL and B == NULL) return A;

  ListNode*list1, *list2, *response, *tmp;
  if(A->val < B->val) {
    list1 = A;
    list2 = B;
  } else {
    list1 = B;
    list2 = A;
  }
  response = list1;
  while(list1 != NULL){
    if(list2 != NULL and (list1->next == NULL or (list2->val >= list1->val and list2->val <= list1->next->val))){
      tmp = list2->next;
      list2->next = list1->next;
      list1->next = list2;
      list2 = tmp;
    }
    list1 = list1->next;
  }
  return response;
}
