/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *p, *q, *tmp;
        if (l1->val > l2->val) {
            tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        p = l1;
        q = l2;
        while (p != NULL) {
            while (q != NULL && (p->next == NULL || p->next->val > q->val)) {
                tmp = p->next;
                p->next = q;
                q = q->next;
                p->next->next = tmp;
                p = p->next;
            }
            p = p->next;
        }
        return l1;
    }
};
