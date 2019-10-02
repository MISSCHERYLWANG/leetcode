#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
        {
            return false;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(nums[i]) != m.end())
            {
                return true;
            }
            ++m[nums[i]];
        }
/* 
        unordered_map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it)
        {
            if (it->second >= 2)
            {
                return true;
            }
        }
*/
        return false;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{1,2,3,1};

    cout << sol.containsDuplicate(nums);

    return 0;
}