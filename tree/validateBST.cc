#include<iostream>
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
    bool isValidBST(TreeNode* root) {
        // inorder 
/**     stack<TreeNode*> st;
        TreeNode *cur = root;
        long long pre = INT64_MIN;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }
            else //cur==NULL && st不为空
            {
                TreeNode *t = st.top();
                st.pop();
                if (pre >= t->val)
                {
                    return false;
                }
                pre = t->val;
                cur = t->right;
            }
        }
        return true;
**/
        // recursive
        return isValidate(root, INT64_MIN, INT64_MAX);
    }
    bool isValidate(TreeNode* root, long long mn, long long mx) {
        if (root == NULL)
        {
            return true;
        }
        if (root->val >= mx || root->val <= mn)
        {
            return false;
        }
        return isValidate(root->left, mn, root->val) && isValidate(root->right, root->val, mx);
    }
};
int main()
{
    Solution sol = Solution();
    TreeNode *root = new TreeNode(5);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(6);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(7);

    root->left = node1; root->right = node2;
    node2->left = node3; node2->right = node4;
    cout << sol.isValidBST(root);
    return 0;
}