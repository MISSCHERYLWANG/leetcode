#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            // cur == NULL || st is empty
            else
            {
                TreeNode *t = st.top();
                st.pop();
                cur = t->right;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    root->right = n1; n1->left = n2;

    vector<int> ans = sol.preorderTraversal(root);    
    for (int a: ans)
    {
        cout << a << " ";
    }
}