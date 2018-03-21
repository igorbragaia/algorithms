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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int Cin = 0;
        ListNode *p = l1, *q = l2, *response;

        int len1 = 0, len2 = 0;
        while (p != NULL) {
            p = p->next;
            len1++;
        }
        while (q != NULL) {
            q = q->next;
            len2++;
        }

        if (len1 > len2) {
            response = l1;
            p = l1;
            q = l2;
        }
        else {
            response = l2;
            p = l2;
            q = l1;
        }

        while (p != NULL || q != NULL) {
            if (p != NULL && q != NULL) {
                p->val += q->val;
                p->val += Cin;
                Cin = (p->val) > 9;
                p->val %= 10;
                if (p->next == NULL && q->next == NULL && Cin) {
                    p->next = new ListNode(0);
                }
                p = p->next;
                q = q->next;
            }
            else if (p != NULL && q == NULL) {
                p->val += Cin;
                Cin = (p->val) > 9;
                p->val %= 10;
                if (p->next == NULL && Cin) {
                    p->next = new ListNode(0);
                }
                p = p->next;
            }
        }
        return response;
    }
};
