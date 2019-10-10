#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using namespace std;

class RandomizedCollection {
public:
    // Duplicates allowed
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // if (m.find(val) != m.end())
        // {
        //     nums.push_back(val);
        //     m[val].push_back(nums.size()-1);
        //     return false;
        // }
        // m[val];
        // nums.push_back(val);
        // return true;
        m[val].insert(nums.size());
        nums.push_back(val);
        return (m[val].size() == 1);
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m[val].empty())
        {
            return false;
        }
        int index = *m[val].begin();
        m[val].erase(index);
        // 不是nums最后一个，通过最后一个元素和之前的元素交换位置来实现删除最后一个
        if (index != nums.size() - 1)
        {
            int tmp = nums.back();
            nums[index] = tmp;
            m[tmp].erase(nums.size() - 1);
            m[tmp].insert(index);
        } 
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * 
 */

int main()
{
    RandomizedCollection* obj = new RandomizedCollection();
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
}