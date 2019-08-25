#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool left = true;

        while (!q.empty())
        {
            int s = q.size();
            vector<int> curLevel(s, 0);
            for (int i = s; i > 0; --i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (left)
                {
                    curLevel[s-i] = p->val;
                }
                else 
                {
                    curLevel[i-1] = p->val;
                }
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            left = !left;
            res.push_back(curLevel);
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1; root->right = node2;
    node2->left = node3; node2->right = node4;

    vector<vector<int>> ans = sol.zigzagLevelOrder(root);

    for (auto v: ans)
    {
        for (int num: v)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}