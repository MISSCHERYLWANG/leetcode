#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
/**
    void reorderList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next))
        {
            return;
        }
        ListNode *fp = head, *sp = head;
        while (fp && fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
        }
        ListNode *sec = sp->next, *pre = NULL;
        sp->next = NULL;
        while (sec)
        {
            ListNode *next = sec->next;
            sec->next = pre;
            pre = sec;
            sec = next;
        }
        while (head && pre)
        {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
**/
    void reorderList(ListNode* head) {
        if (!head || !(head->next) || !(head->next->next))
        {
            return;
        }
        stack<ListNode*> st;
        ListNode *p = head;
        // 入栈
        while (p)
        {
            st.push(p);
            p = p->next;
        }
        // 后半段出栈并插入链表
        int num = (st.size() - 1) / 2;
        ListNode *h = head;
        while (num)
        {
            ListNode *t = st.top();
            st.pop();
            --num;
            t->next = h->next;
            h->next = t;
            h = t->next;
        }
        st.top()->next = NULL;
    }
};
int main()
{
    Solution sol = Solution();

    ListNode *head = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(4);
    ListNode *n4 = new ListNode(5);

    head->next = n1; n1->next = n2;
    n2->next = n3; n3->next = n4;

    sol.reorderList(head);
    ListNode *p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}