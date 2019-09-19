#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;
class LRUCache {
// double linkedlist and hashmap
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end())
        {
            return -1;
        }
        // splice: put it->second to l's head
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end())
        {
            l.erase(it->second);
        }
        // push_front: insert the element in the first
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap)
        {
            // rbegin: pointing to the last element
            int k = l.rbegin()->first;
            // erase: true remove: false
            m.erase(k);
            l.pop_back();
        }
    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache* obj = new LRUCache(2);
    int param_1 = obj->get(key);
    obj->put(key,value);

    return 0;
}