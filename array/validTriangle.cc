#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        if (nums.empty() || nums.size() < 3)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = n - 1; i >= 2; --i)
        {
            int l = 0, r = i - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] > nums[i])
                {
                    res += (r - l);
                    --r;
                }
                else
                {
                    ++l;
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();
    vector<int> nums{2, 2, 3, 4};

    cout << s.triangleNumber(nums);
}