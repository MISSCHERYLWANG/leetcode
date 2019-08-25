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

    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1; node1->left = node2;
    node2->left = node3; node3->left = node4;

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