#include<iostream>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !(head->next))
        {
            return NULL;
        }
        ListNode *sp = head, *fp = head;
        while (fp && fp->next)
        {
            if (fp == sp)
            {
                break;
            }
            sp = sp->next;
            fp = fp->next->next;
        }
        if (!fp || !(fp->next))
        {
            return NULL;
        }
        
        sp = head;
        while (sp != fp)
        {
            sp = sp->next;
            fp = fp->next;
        }
        return fp;
    }
};
int main()
{
    Solution sol = Solution();

    
}