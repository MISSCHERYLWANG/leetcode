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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root, *last = nullptr;
        while (cur || !st.empty())
        {
        /** reverse of preorder
            if (cur)
            {
                res.insert(res.begin(), cur->val);
                st.push(cur);
                cur = cur->right;
            }
            else
            {
                TreeNode *t = st.top();
                st.pop();
                cur = t->left;
            }**/ 
            // iterative
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *t = st.top();
                if (t->right && t->right != last)
                {
                    cur = t->right;
                }
                else
                {
                    res.push_back(t->val);
                    last = t;
                    st.pop();
                }
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

    vector<int> ans = sol.postorderTraversal(root);
    for (int a: ans)
    {
        cout << a << " ";
    }
}
