#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
/**
 * iteration
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return NULL;
        }
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        Node *nnode = new Node(node->val);
        m[node] = nnode;
        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            for (Node *ns: n->neighbors)
            {
                if (!m.count(ns))
                {
                    m[ns] = new Node(ns->val);
                    q.push(ns);
                }
                m[n]->neighbors.push_back(m[ns]);
            }
        }
        return nnode;
    }
**/
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return dfs(m, node);
    }
    Node* dfs(unordered_map<Node*, Node*>& m, Node* node) {
        if (!node)
        {
            return NULL;
        }
        if (m.count(node))
        {
            return m[node];
        }
        Node *clone = new Node(node->val);
        m[node] = clone;
        for (Node *nei: node->neighbors)
        {
            clone->neighbors.push_back(dfs(m, nei));
        }
        return clone;
    }
};
int main()
{
    Solution sol = Solution();

    return 0;
}