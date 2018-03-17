/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode * p = A, * q;
    while(p != NULL){
        if(p -> next != NULL && p -> next -> val == p -> val){
            q = p->next;
            p->next = p->next->next;
            delete q;
        } else {
            p = p->next;
        }
    }
    return A;
}
