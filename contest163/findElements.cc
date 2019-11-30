#include<iostream>
#include<queue>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * 迭代层次遍历来恢复二叉树
 * 使用一个set来记录二叉树中的节点，便于寻找
**/

class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;

        q.push(root);
        st.insert(root->val);
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->left != NULL)
            {
                t->left->val = t->val * 2 + 1;
                q.push(t->left);
                st.insert(t->left->val);
            }
            if (t->right != NULL)
            {
                t->right->val = t->val * 2 +2;
                q.push(t->right);
                st.insert(t->right->val);
            }
        }
    }
    
    bool find(int target) {
        if (st.find(target) != st.end())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main()
{
    TreeNode *root = new TreeNode(-1);
    FindElements fe = FindElements(root);
}