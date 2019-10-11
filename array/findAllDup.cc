#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            for (int j : nums)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> nums{4,3,2,7,8,2,3,1}, res;

    res = s.findDuplicates(nums);
    for (int i : res)
    {
        cout << i << " ";
    }
}