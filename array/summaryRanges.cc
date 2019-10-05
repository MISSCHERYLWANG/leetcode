#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
        {
            return {};
        }
        vector<string> res;
        int l = 0, r = 0;
        while (r < nums.size() - 1)
        {
            if (nums[r] != nums[r+1] - 1)
            {
                string cur = (l == r ? to_string(nums[l]) : to_string(nums[l]) + "->" + to_string(nums[r]));
                res.push_back(cur);
                l = r + 1;
            }
            ++r;
        }
        string cur = (l == r ? to_string(nums[l]) : to_string(nums[l]) + "->" + to_string(nums[r]));
        res.push_back(cur);

        return res;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums{0,2,3,4,6,8,9};

    vector<string> res = sol.summaryRanges(nums);

    for (string s: res)
    {
        cout << s << " ";
    }
    cout << endl;
}