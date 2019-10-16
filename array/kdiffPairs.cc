#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return 0;
        }
        unordered_map<int, set<int>> m;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (abs(nums[i] - nums[j]) == k)
                {
                    if (m.find(nums[j]) != m.end())
                    {
                        continue;
                    }
                    m[nums[i]].insert(nums[j]);
                }
            }
        }
        int res = 0;
        for (auto it : m)
        {
            res += it.second.size();
        }
        return res;
    }
};

int main()
{
    Solution s = Solution();
    // [1,1,1,1,1], k = 0
    // [1,1,1,2,1]
    // 1
    vector<int> nums{1,1,1,1,1};
    int k = 0;
    cout << s.findPairs(nums, k);
}