#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), total = 0, mx = INT32_MIN;
        vector<int> sums(n + 1, 0), leftPos(n, 0), rightPos(n, n - k), res(3, 0);
        //
        for (int i = 0; i < n; ++i)
        {
            sums[i + 1] = nums[i] + sums[i];
        }
        // from left to right
        total = sums[k] - sums[0];
        for (int i = k; i < n; ++i)
        {
            if (sums[i + 1] - sums[i + 1 - k] > total)
            {
                leftPos[i] = i + 1 - k;
                total = sums[i + 1] - sums[i + 1 - k];
            }
            else
            {
                leftPos[i] = leftPos[i - 1];
            }
        }
        // from right to left to refresh rightPos
        total = sums[n] - sums[n - k];
        for (int i = n - k - 1; i >= 0; --i)
        {
            if (sums[i + k] - sums[i] >= total)
            {
                rightPos[i] = i;
                total = sums[i + k] - sums[i];
            }
            else
            {
                rightPos[i] = rightPos[i + 1];
            }
        }
        // the result
        for (int i = k; i <= n - 2 * k; ++i)
        {
            int lp = leftPos[i - 1], rp = rightPos[i + k];
            total = sums[lp + k] - sums[lp] + sums[i + k] - sums[i] + sums[rp + k] - sums[rp];
            if (mx < total)
            {
                mx = total;
                res = {lp, i, rp};
            }
        }
        return res;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> nums{1, 2, 1, 2, 6, 7, 5, 1}, res;
    int k = 2;

    res = s.maxSumOfThreeSubarrays(nums, k);

    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}