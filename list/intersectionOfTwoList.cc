#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
        {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;

        while (pA || pB)
        {    
            if (pA == nullptr)
            {
                pA = headB;
            }
            if (pB == nullptr)
            {
                pB = headA;
            }
            if (pA == pB)
            {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution s = Solution();
    ListNode *headA = new ListNode(4);
    ListNode *headB = new ListNode(5);
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(8);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);
    ListNode *q1 = new ListNode(0);
    ListNode *q2 = new ListNode(1);

    headA->next = p1; p1->next = p2; p2->next = p3; p3->next = p4;
    headB->next = q1; q1->next = q2; q2->next = p2; 
    ListNode *ans = s.getIntersectionNode(headA, headB);
    cout << ans->val;
}