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
    int sumNumbers(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int sum = 0, num = 0;
        sumDFS(root, sum, num);
        return sum;
    }
    void sumDFS(TreeNode* root, int& sum, int num) {
        if (!root)
        {
            return;
        }
        num = num * 10 + root->val;
        if (!root->left && !root->right)
        {
            sum += num;
            num = 0;
            return;
        }
        sumDFS(root->left, sum, num);
        sumDFS(root->right, sum, num);
    }
};
int main()
{
    Solution sol = Solution();
    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(0);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(1);

    node1->left = node2; node1->right = node3;
    node2->left = node4; node2->right = node5;

    cout << sol.sumNumbers(node1);

    return 0;
}