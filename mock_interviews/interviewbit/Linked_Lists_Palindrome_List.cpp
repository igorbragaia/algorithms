/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reversedList(ListNode* root)
{
    ListNode *p = root, *next, *reversed = NULL;
    while (p != NULL) {
        next = p->next;

        p->next = reversed;
        reversed = p;

        p = next;
    }

    return reversed;
}

int Solution::lPalin(ListNode* A)
{
    ListNode *p = A, *q;
    int len = 0;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    p = A;
    q = A;
    int tmp = len / 2;
    while (tmp--) {
        q = q->next;
    }

    if (len % 2 == 1) {
        q = q->next;
    }

    q = reversedList(q);

    while (p != NULL && q != NULL) {
        if (p->val != q->val) {
            return 0;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
    return 1;
}
