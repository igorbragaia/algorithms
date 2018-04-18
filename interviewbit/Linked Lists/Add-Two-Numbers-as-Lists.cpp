/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* p1 = A,*p2 = B,*ans;
    while(p1 != NULL and p2 != NULL){
        p1 = p1->next;
        p2 = p2->next;
    }
    if(p1 != NULL and p2 == NULL){
        p1 = A;
        p2 = B;
    } else {
        p1 = B;
        p2 = A;
    }
    
    ans = p1;
    int carry = 0;    
    while(p1 != NULL){
        p1->val = carry + p1->val + (p2 != NULL ? p2->val:0);
        carry = p1->val / 10;
        p1->val %= 10;
        if(p1->next == NULL and carry){
            p1->next = new ListNode(1);
            p1 = p1->next;
        }
        p1 = p1->next;
        if(p2 != NULL)
            p2 = p2->next;
    }
    return ans;
}
