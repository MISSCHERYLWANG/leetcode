#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int n = nums.size(), degree = 0, res = INT32_MAX;
        unordered_map<int, int> deg_m, left, right;

        for (int i = 0; i < n; ++i)
        {
            if (deg_m.find(nums[i]) != deg_m.end())
            {
                ++deg_m[nums[i]];
                right[nums[i]] = i;
            }
            else
            {
                deg_m[nums[i]] = 1;
                left[nums[i]] = i;
                right[nums[i]] = i;
            }

            degree = max(degree, deg_m[nums[i]]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (deg_m[nums[i]] == degree)
            {
                res = min(res, right[nums[i]] - left[nums[i]] + 1);
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{1, 2, 2, 3, 1, 4, 2};

    cout << s.findShortestSubArray(nums);
}