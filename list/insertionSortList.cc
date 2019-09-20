#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *pse = new ListNode(INT32_MIN);
        pse->next = head;
        ListNode *cur = head->next;
        head->next = NULL;
        while (cur)
        {
            ListNode *p = pse, *n = cur->next;
            while (p->next && p->next->val <= cur->val)
            {
                p = p->next;
            }
            cur->next = p->next;
            p->next = cur;
            cur = n;
        }
        return pse->next;
    }
};

int main()
{
    Solution sol = Solution();

    ListNode *h = new ListNode(4);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(1);
    ListNode *n3 = new ListNode(3);
    h->next = n1; n1->next = n2; n2->next = n3;

    ListNode *new_head = sol.insertionSortList(h);

    ListNode *p = new_head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }

}