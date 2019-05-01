/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseListInPlace(ListNode*root){
  if(root != NULL and root->next != NULL){
    ListNode*previous,*current,*next;
    previous=NULL;
    current=root;
    next=root->next;

    while(current!=NULL){
      next=current->next;
      current->next=previous;
      previous=current;
      current=next;
    }

    return previous;
  } else {
      return root;
  }
}

ListNode* Solution::reorderList(ListNode* A) {
  if(A==NULL or A->next==NULL)
    return A;
  else {
    ListNode*p=A,*q,*aux1,*aux2;

    int count=0;
    while(p!=NULL){
      p=p->next;
      count++;
    }

    count = (count+1)/2-1;
    p=A;
    while(count--)
      p=p->next;
    q=p->next;
    p->next=NULL;
    p=A;

    q=reverseListInPlace(q);
    while(q!=NULL){
      aux1=p->next;
      aux2=q->next;

      p->next=q;
      p->next->next=aux1;

      p=p->next->next;
      q=aux2;
    }

    return A;
  }
}
