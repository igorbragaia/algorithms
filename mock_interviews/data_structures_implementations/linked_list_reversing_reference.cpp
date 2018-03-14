#include<bits/stdc++.h>
using namespace std;


struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode * reversedList(ListNode ** root){
  ListNode * p = * root, * prev = NULL, * next;
  while(p != NULL){
    next = p->next;
    p->next = prev;
    prev = p;
    p = next;
  }
  (*root) = prev;
}

void printAll(ListNode * root){
  ListNode * p = root;
  while(p != NULL){
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main(){
  ListNode * root = new ListNode(10);
  root->next = new ListNode(5);
  root->next->next = new ListNode(3);
  root->next->next->next = new ListNode(16);
  printAll(root);
  reversedList(&root);
  printAll(root);
  return 0;
}
