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
/** non-iterative
    void flatten(TreeNode* root) {    
        TreeNode *cur = root;
        
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *p = cur->left;
                while (p->right)
                {
                    p = p->right;
                }
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
**/
    void flatten(TreeNode* root) { 
        if (!root)
        {
            return;
        }   
        stack<TreeNode*> st{{root}};

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->left)
            {
                TreeNode *p = cur->left;
                while (p->right)
                {
                    p = p->right;
                }
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            if (cur->right)
            {
                st.push(cur->right);
            }
        }
    }
};

int main()
{
    Solution sol = Solution();

    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    node1->left = node2; node1->right = node5;
    node2->left = node3; node2->right - node4;
    node5->right = node6;

    sol.flatten(node1);

    while (node1)
    {
        cout << node1->val << " ";
        node1 = node1->right;
    }
    return 0;
}