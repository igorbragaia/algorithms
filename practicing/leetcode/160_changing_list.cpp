#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

void printAll(ListNode * root){
  ListNode * p = root;
  while(p != NULL){
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

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
      printAll(headA);
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
      printAll(headA);

      return *response;
    }
};

int main(){
  ListNode * root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(3);
  root->next->next->next = new ListNode(4);

  ListNode * root2 = new ListNode(1);
  root2->next = new ListNode(2);
  root2->next->next = new ListNode(3);
  root2->next->next->next = new ListNode(4);

  printf("response %d\n", Solution().getIntersectionNode(root, root2)->val);

  return 0;
}
