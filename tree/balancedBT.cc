#include<iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
/** 递归深度
 *      if (!root)
        {
            return true;
        }

        int l = maxDepth(root->left), r = maxDepth(root->right);
        
        if (l - r > 1 || r - l > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
**/
        if (checkDepth(root) == -1)
        {
            return false;
        }
        return true;
    }
/** int maxDepth(TreeNode* root) {
        return (root == NULL) ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
**/
    int checkDepth(TreeNode *root) {
        if (!root)
        {
            return 0;
        }
        int l = checkDepth(root->left);
        if (l == -1)
        {
            return -1;
        }
        int r = checkDepth(root->right);
        if (r == -1)
        {
            return -1;
        }
        if (abs(l-r) > 1)
        {
            return -1;
        }
        return 1 + max(l, r);
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
    root->left = node1; root->right = node2;;
    node1->left = node3; node3->left = node4;

    cout << sol.isBalanced(root);

    return 0;
}