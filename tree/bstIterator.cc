#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
class BSTIterator
{
public:
    stack<TreeNode *> st;
    vector<TreeNode *> tmp;
    int index;
    // memory o(n)
    void midorder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode *p = root;
        while (!st.empty() || p != nullptr)
        {
            if (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                TreeNode *t = st.top();
                st.pop();
                tmp.push_back(t);
                p = t->right;
            }
        }
    }
    BSTIterator(TreeNode *root)
    {
        midorder(root);
        index = -1;
    }

    // @return the next smallest number 
    int next()
    {
        ++index;
        return tmp[index]->val;
    }

    // @return whether we have a next smallest number 
    bool hasNext()
    {
        if (index + 1 >= tmp.size())
        {
            return false;
        }
        return true;
    }

};
**/

class BSTIterator
{
private:
    /* data */
    // memory: o(h)
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *t = st.top(), *p = t->right;
        st.pop();
        while (p)
        {
            st.push(p);
            p = p->left;
        }
        return t->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main()
{
    TreeNode *root = new TreeNode(2);
    BSTIterator *obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
}