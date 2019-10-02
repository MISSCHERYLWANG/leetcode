#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() == 1)
        {
            return false;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
            {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{1,1}; 
    int k = 2;

    cout << sol.containsNearbyDuplicate(nums, k);

    return 0;
}
