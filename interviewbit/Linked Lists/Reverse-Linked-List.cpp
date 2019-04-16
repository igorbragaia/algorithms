/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(A==NULL or A->next==NULL)
        return A;
    ListNode*previous,*node,*next;
    previous=NULL;
    node=A;
    next=A->next;
    while(node!=NULL){
        next=node->next;
        node->next=previous;
        previous=node;
        node=next;
    }
    return previous;
}
