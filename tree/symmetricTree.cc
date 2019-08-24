#include<iostream>
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *l = q1.front();
            TreeNode *r = q2.front();
            q1.pop(); q2.pop();

            if (!l && !r)
            {
                continue;
            }

            if ((l && !r) || (!l && r) || (l->val != r->val))
            {
                return false;
            }

            q1.push(l->left); q1.push(l->right);
            q2.push(r->right); q2.push(r->left);
        }
        return true;   
    }
};
int main()
{
    Solution sol = Solution();
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(3);
    root->left = node1; root->right = node2;
    node1->left = node3; node1->right = node4;
    node2->left = node5; node2->right = node6;

    cout << sol.isSymmetric(root);

    return 0;
}