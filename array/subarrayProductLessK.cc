#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    // sliding window
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
        {
            return 0;
        }
        int n = nums.size(), l = 0, r = 0;
        int product = 1, res = 0;
        while (r < n)
        {
            product *= nums[r];
            while (l < n && product >= k)
            {
                product /= nums[l];
                ++l;
            }
            res += (r - l + 1);
            ++r;
        }
        return res;
    }
};
int main()
{
    Solution s = Solution();

    vector<int> nums{10, 5, 2, 6};
    int k = 100;

    cout << s.numSubarrayProductLessThanK(nums, k);
}