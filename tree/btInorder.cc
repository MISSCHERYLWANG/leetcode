#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *r = st.top();
                st.pop();
                res.push_back(r->val);
                cur = r->right;
            }
        }
        // traversalDFS(root, res);
        return res;
    }
    // recursive
/*  void traversalDFS(TreeNode* root, vector<int>& res) {
        if (root != NULL)
        {
            traversalDFS(root->left, res);
            res.push_back(root->val);
            traversalDFS(root->right, res);
        }
    }
*/
};
int main()
{
    Solution sol = Solution();
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->right = node1; node1->left = node2;
    vector<int> ans = sol.inorderTraversal(root);
    for (int a: ans)
    {
        cout << a << " ";
    }
    return 0;
}