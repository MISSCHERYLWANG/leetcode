#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
        {
            return NULL;
        }
        int n = nums.size();
        TreeNode *root = new TreeNode(nums[n/2]);
        vector<int> nums_l(nums.begin(), nums.begin()+n/2), nums_r(nums.begin()+n/2+1, nums.end());
        
        root->left = sortedArrayToBST(nums_l);
        root->right = sortedArrayToBST(nums_r);
        return root;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {  
            vector<int> curLevel;  
            for (int i = q.size(); i > 0; --i)   //计数
            {
                TreeNode *p = q.front();
                q.pop();
                curLevel.push_back(p->val);
                
                if (p->left) 
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{-10, -3, 0, 5, 9};
    TreeNode *root = sol.sortedArrayToBST(nums);
    vector<vector<int>> ans = sol.levelOrder(root);

    for (auto v: ans)
    {
        for (int num: v)
        {
            cout << num << " ";
        }
        cout << endl;
    }

}