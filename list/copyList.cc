#include<iostream>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
/** no hashmap
    Node* copyRandomList(Node* head) {
        if (!head)
        {
            return NULL;
        }

        Node *p = head;
        while (p)
        {
            Node *newp =new Node(p->val, nullptr, nullptr);
            newp->next = p->next;
            p->next = newp;

            p = newp->next;
        }

        p = head;
        while (p)
        {
            if (p->random)
            {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        Node *res = head->next;
        p = head;
        while (p)
        {
            Node *t = p->next;
            p->next = t->next;
            if (t->next)
            {
                t->next = t->next->next;
            }
            p = p->next;
        }
        return res;
    }
**/
// hashmap
    Node* copyRandomList(Node* head) {
        if (!head)
        {
            return NULL;
        }

        unordered_map<Node*, Node*> m;
        Node *p = head->next;
        Node *copy = new Node(head->val, nullptr, nullptr), *cp = copy;
        m[head] = copy;

        while (p)
        {
            Node *t = new Node(p->val, nullptr, nullptr);
            cp->next = t;
            cp = cp->next;
            m[p] = t;
            p = p->next;
        }
        p = head, cp = copy;
        while (p)
        {
            cp->random = m[p->random];
            p = p->next;
            cp = cp->next;
        }
        return copy;
    }
};

int main()
{
    Solution sol = Solution();

    Node *head = new 
}