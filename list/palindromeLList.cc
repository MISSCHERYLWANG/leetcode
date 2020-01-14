#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> temp;
        ListNode *p = head;
        while (p != nullptr) {
            temp.push_back(p->val);
            p = p->next;
        }
        int n = temp.size();
        for (int i = 0; i < n/2; ++i) {
            if (temp[i] != temp[n-1-i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s = Solution();

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(1);
    n1->next = n2; n2->next = n3; n3->next = n4;

    std::cout << s.isPalindrome(n1);
}