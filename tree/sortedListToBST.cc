#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
        {
            return NULL;
        }

        int n = 0;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            ++n;
        }
        n = n / 2;
        p = head; 
        while (n > 1)
        {
            p = p->next;
            --n;
        }
        ListNode *l = NULL, *r = NULL;
        TreeNode *cur;
        if (p->next)
        {
            cur = new TreeNode(p->next->val);
            l = head;
            r = p->next->next;
            p->next = NULL;
        }
        else 
        {
            cur = new TreeNode(p->val);
        }
        cur->left = sortedListToBST(l);
        cur->right = sortedListToBST(r);

        return cur;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {  
            vector<int> curLevel;  
            for (int i = q.size(); i > 0; --i)   //计数
            {
                TreeNode *p = q.front();
                q.pop();
                curLevel.push_back(p->val);
                
                if (p->left) 
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    ListNode *node1 = new ListNode(-10);
    ListNode *node2 = new ListNode(-3);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(5);
    ListNode *node5 = new ListNode(9);
    node1->next = node2; node2->next = node3;
    node3->next = node4; node4->next = node5;

    TreeNode *root = sol.sortedListToBST(node1);
    vector<vector<int>> ans = sol.levelOrder(root);

    for (auto v: ans)
    {
        for (int num: v)
        {
            cout << num << " ";
        }
        cout << endl;
    }

}