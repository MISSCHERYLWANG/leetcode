#include<iostream>
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
/** recursive
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> res;
        vector<int> cur;
        sumDFS(root, sum, res, cur);
        return res;
    }
    void sumDFS(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& cur) {
        if (!root)
        {
            return;
        }
        cur.push_back(root->val);
        if (sum == root->val && !root->left && !root->right)
        {
            res.push_back(cur);
        }

        sumDFS(root->left, sum - root->val, res, cur);
        sumDFS(root->right, sum - root->val, res, cur);
        cur.pop_back();
    }
**/
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> st;
        TreeNode *cur = root, *pre = NULL;
        int val = 0;

        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push_back(cur);
                val += cur->val;
                cur = cur->left;
            }
            cur = st.back();
            if (val == sum && !cur->left && !cur->right)
            {
                vector<int> v;
                for (TreeNode *p: st)
                {
                    v.push_back(p->val);
                }
                res.push_back(v);
            }

            if (cur->right && cur->right != pre)
            {
                cur = cur->right;
            }
            else
            {
                pre = cur;
                val -= cur->val;
                st.pop_back();
                cur = NULL;
            }
            
        }

        return res;
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
    TreeNode *node0 = new TreeNode(5);
    TreeNode *node9 = new TreeNode(1);
    node1->left = node2; node1->right = node3;
    node2->left = node4; 
    node3->left = node5; node3->right = node6;
    node4->left = node7; node4->right = node8;
    node6->right = node9; node6->left = node0;
    int sum;
    cin >> sum;

    vector<vector<int>> ans = sol.pathSum(node1, sum);

    for (auto vec: ans)
    {
        for (int n: vec)
        {
            cout << n << " ";
        }
        cout << endl;
    }
}