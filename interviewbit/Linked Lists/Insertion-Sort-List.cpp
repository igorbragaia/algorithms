/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void sort(ListNode*(*root)){
    if((*root) != NULL and (*root)->next != NULL){
        sort(&(*root)->next);
        int val = (*root)->val;
        ListNode * p = (*root);
        while(p->next != NULL and p->next->val < val){
            p->val = p->next->val;
            p = p->next;
        }
        p->val = val;
    }
}

ListNode* Solution::insertionSortList(ListNode* A) {
     sort(&A);  
     return A;
}
