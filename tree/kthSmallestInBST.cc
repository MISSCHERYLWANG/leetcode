#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int num = 0;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (!st.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = st.top();
                st.pop();
                ++num;
                if (num == k)
                {
                    return t->val;
                }
                p = t->right;
            }
        }
        return 0;
    }
};
int main()
{
    Solution s = Solution();
    TreeNode *root = new TreeNode(3);
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(4);
    root->left = p1; p1->right = p2; root->right = p3;
    cout << s.kthSmallest(root, 1);
    return 0;
}