#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
// 先求depth，然后dfs从depth-1开始
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderDFS(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    void levelOrderDFS(TreeNode *root, vector<vector<int>>& res, int level) {
        if (!root)
        {
            return;
        }
        if (level >= res.size())
        {
            res.push_back({});
        }
        res[level].push_back(root->val);

        levelOrderDFS(root->left, res, level+1);
        levelOrderDFS(root->right, res, level+1);
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
    root->left = node1; root->right = node2;
    node2->left = node3; node2->right = node4;

    vector<vector<int>> ans = sol.levelOrderBottom(root);

    for (auto v: ans)
    {
        for (int num: v)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}