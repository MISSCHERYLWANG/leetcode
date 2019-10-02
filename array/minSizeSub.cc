#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, sum = 0, res = INT_MAX;

        while (r < nums.size())
        {
            sum += nums[r];
            ++r;
            while (sum >= s)
            {
                res = min(res, r-l);
                sum -= nums[l];
                ++l;
            }
        }
        return (res == INT_MAX ? 0 : res);
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;

    cout << sol.minSubArrayLen(s, nums);

    return 0;

}