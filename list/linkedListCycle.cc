#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !(head->next))
        {
            return false;
        }
        ListNode *slow = head, *fast = head->next;
        while (fast != slow)
        {
            if (!slow || !(slow->next))
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
int main()
{
    Solution sol = Solution();

    ListNode *head = new ListNode();
}