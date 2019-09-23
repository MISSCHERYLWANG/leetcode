#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // T: o(nlogn)   S: o(1)
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *pre = head, *sp = head, *fp = head;
        while (fp && fp->next)
        {
            pre = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        pre->next = nullptr;

        return merge(sortList(head), sortList(sp));
    }
    ListNode* merge(ListNode* ln1, ListNode* ln2) {
        ListNode *dummy = new ListNode(0), *p = dummy;

        while (ln1 && ln2)
        {
            if (ln1->val < ln2->val)
            {
                p->next = ln1;
                ln1 = ln1->next;
            }
            else
            {
                p->next = ln2;
                ln2 = ln2->next;
            }
            p = p->next;
        }
        if (ln1)
        {
            p->next = ln1;
        }
        if (ln2)
        {
            p->next = ln2;
        }
        return dummy->next;
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

    ListNode *res = sol.sortList(h), *p = res;

    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
}
