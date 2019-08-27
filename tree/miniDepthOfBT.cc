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
    int minDepth(TreeNode* root) {
        //recursion
/**     if (!root)
        {
            return 0;
        }
        if (!(root->left) && !(root->right))
        {
            return 1;
        }
        if (!(root->left))
        {
            return 1 + minDepth(root->right);
        }
        if (!(root->right))
        {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
**/
        if (!root)
        {
            return 0;
        }
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            ++res;
            for (int i = q.size(); i > 0; --i)
            {
                TreeNode *p = q.front();
                q.pop();
                if (!(p->left) && !(p->right))
                {
                    return res;
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
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    // TreeNode *node2 = new TreeNode(20);
    // TreeNode *node3 = new TreeNode(15);
    // TreeNode *node4 = new TreeNode(7);
    root->left = node1; 
    // root->right = node2;
    // node2->left = node3; node2->right = node4;

    cout << sol.minDepth(root);

    return 0;
}