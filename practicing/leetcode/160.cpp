/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverseList(ListNode ** root){
   ListNode * p = * root, * prev = NULL, * next;
   while(p != NULL){
     next = p->next;
     p->next = prev;
     prev = p;
     p = next;
   }
   (*root) = prev;
 }


 class Solution {
 public:
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(headA == NULL || headB == NULL){
         return NULL;
       }
       reverseList(&headA);
       reverseList(&headB);

       if(headA->val != headB->val){
         reverseList(&headA);
         reverseList(&headB);
         return NULL;
       }

       ListNode * p = headA, * q = headB;
       ListNode ** response = &p;
       while(p != NULL && q != NULL && p->next != NULL && q->next != NULL && p->next->val == q->next->val){
           p = p->next;
           q = q->next;
       }

       reverseList(&headA);
       reverseList(&headB);

       return *response;
     }
 };
