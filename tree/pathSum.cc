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
/** recursive
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        if (!root->left && !root->right && root->val == sum)
        {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
**/
// iteration
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (!cur->left && !cur->right)
            {
                if (cur->val == sum)
                {
                    return true;
                }
            }
            if (cur->left)
            {
                cur->left->val += cur->val;
                st.push(cur->left);
            }
            if (cur->right)
            {
                cur->right->val += cur->val;
                st.push(cur->right);
            }
        }
        return false;
    }
};
int main()
{
    Solution sol = Solution();

    TreeNode *node1 = new TreeNode(5);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(8);
    TreeNode *node4 = new TreeNode(11);
    TreeNode *node5 = new TreeNode(13);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(2);
    TreeNode *node9 = new TreeNode(1);
    node1->left = node2; node1->right = node3;
    node2->left = node4; 
    node3->left = node5; node3->right = node6;
    node4->left = node7; node4->right = node8;
    node6->right = node9;
    int sum;
    cin >> sum;
    cout << sol.hasPathSum(node1, sum);

    return 0;

}