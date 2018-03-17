 #include<bits/stdc++.h>
 using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

void printAll(ListNode * root){
  ListNode * p = root;
  while(p!=NULL){
    printf("%d ", p->val);
    p=p->next;
  }
  printf("\n");
}

ListNode * reversedList(ListNode * root){
  ListNode * p = root, * next, * reversed = NULL;
  while(p != NULL){
    next = p->next;

    p->next = reversed;
    reversed = p;

    p = next;
  }

  return reversed;
}

int main(){
  ListNode * root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(3);
  root->next->next->next = new ListNode(4);
  root->next->next->next->next = new ListNode(5);

  printAll(root);
  printAll(reversedList(root));

  return 0;
}
